#ifndef BSP_USART_H_
#define BSP_USART_H_
#include "stdint.h"
/* 作者：LWH 时间：2024年11月 目标：调用HAL库实现串口的发送功能 */
/* .h文件代码规范：
    1.头文件只负责声明不进行定义和实现。
    2.声明可供外部调用的函数,声明的函数一般对应固定的.c
 */



/*实现串口发送一个字节的函数*/
void bsp_uart_send_byte(uint8_t Byte);
/*实现串口发送数组*/
void bsp_uart_send_array(uint8_t *Array,uint16_t length);
/*实现串口发送一个字符串 */
void bsp_uart_send_string(char *mstring);
/*实现串口发送数字 */
uint32_t serial_pow(uint32_t x,uint32_t y);
void bsp_uart_send_num(uint32_t number,uint8_t length);
/*实现c语言printf的重定向*/
void bsp_uart_send_printf(char *format,...);
/* 串口1dma发送 */
void usart1_tx_dma_enable(uint8_t *data, uint16_t len);
/* 串口1dma发送初始化 */
void usart1_tx_dma_init(void);
#endif // !BSP_UART_H_

