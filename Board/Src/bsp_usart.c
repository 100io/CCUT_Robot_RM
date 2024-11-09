#include "bsp_usart.h"
#include "main.h"
#include "stdarg.h"
#include "stdio.h"
/* 作者：LWH 时间：2024年11月 目标：调用HAL库实现串口的发送功能 */
/* .c文件代码规范：
    1.关于头文件的包含：（1）直接包含main.h，就需要声明hal库的外设句柄
                   （2）包含usart.h则无需重新声明句柄，句柄在usart中已经声明完了
                   （3）不在对应的头文件里面包含main.h为了防止重复包含
    2.定义相关的全局变量：定义的相关全局变量只用于这单个文件的全局变量，不作为参数对外进行
    传递，传递参数我们放在头文件里面声明的结构体中，这些都用于参数传递
    3.对于函数的定义与实现：在头文件中进行声明，.c文件中只写对应函数的实现。
    4.必须在.c文件中对句柄进行声明,因为如果在.h中包含main.h并且进行声明会极大出现重复包含
 */

/* 声明hal库的句柄 */
extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_tx;

/*定义相关全局变量*/



/*对函数的定义与实现 */
void usart1_tx_dma_init(void)
{
        //enable the DMA transfer for the receiver request
    //使能DMA串口接收
    SET_BIT(huart1.Instance->CR3, USART_CR3_DMAT);

}
void usart1_tx_dma_enable(uint8_t *data, uint16_t len)
{
    
    //disable DMA
    //失效DMA
    __HAL_DMA_DISABLE(&hdma_usart1_tx);
    while(hdma_usart1_tx.Instance->CR & DMA_SxCR_EN)
    {
        __HAL_DMA_DISABLE(&hdma_usart1_tx);
    }

    //clear flag
    //清除标志位
    __HAL_DMA_CLEAR_FLAG(&hdma_usart1_tx, DMA_HISR_TCIF7);
    __HAL_DMA_CLEAR_FLAG(&hdma_usart1_tx, DMA_HISR_HTIF7);

    //set data address
    //设置数据地址
    hdma_usart1_tx.Instance->M0AR = (uint32_t)(data);
    //set data length
    //设置数据长度
    hdma_usart1_tx.Instance->NDTR = len;

    //enable DMA
    //使能DMA
    __HAL_DMA_ENABLE(&hdma_usart1_tx);
}

/*实现串口发送一个字节的函数*/
void bsp_uart_send_byte(uint8_t Byte){
    HAL_UART_Transmit(&huart1,&Byte,1,HAL_MAX_DELAY);
}
/*实现串口发送数组*/
void bsp_uart_send_array(uint8_t *Array,uint16_t length){
    for(uint16_t i=0;i<length;i++){
        bsp_uart_send_byte(Array[i]);
    }
}
/*实现串口发送一个字符串 */
void bsp_uart_send_string(char *mstring){
    for(uint16_t i=0;mstring[i]!='\0';i++){
        bsp_uart_send_byte(mstring[i]);
    }
}
/*实现串口发送数字 */

//这个函数相当于根据y的值实现对x的幂运算，返回x^y
uint32_t serial_pow(uint32_t x,uint32_t y){
    uint32_t Result=1;
    while(y--){
        Result*=x;
    }
    return Result;
}
void bsp_uart_send_num(uint32_t number,uint8_t length){
    uint8_t i;
    for(i=0;i<length;i++){
        bsp_uart_send_byte(number/serial_pow(10,length-i-1)%10+'0');//对数据的每一位进行提取
    }
}
/*实现c语言printf的重定向*/
void bsp_uart_send_printf(char *format, ...){
    static uint8_t tx_buf[256] = {0};
    static va_list ap;
    static uint16_t len;
    va_start(ap, format);
    //return length of string 
    //返回字符串长度
    len = vsprintf((char *)tx_buf, format, ap);
    va_end(ap);
    usart1_tx_dma_enable(tx_buf, len);
}
