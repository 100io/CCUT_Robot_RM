项目结构文件

```bash
ccut_rm_infantry
│  .gitignore
│  .mxproject
│  CCUT_Robot_V1.0.ioc
│  Makefile
│  README.md
│  startup_stm32f407xx.s
│  STM32F407IGHx_FLASH.ld
│  proj_tree.md
│  
├─.vscode
│      c_cpp_properties.json
│      launch.json
│      tasks.json
│      
├─App
│  ├─Inc
│  │      RC_task.h
│  │      
│  └─Src
│          RC_task.c
│          
├─Board
│  ├─Inc
│  │      bsp_usart.h
│  │      
│  └─Src
│          bsp_usart.c
│          
├─Core
│  ├─Inc
│  │      dma.h
│  │      FreeRTOSConfig.h
│  │      gpio.h
│  │      main.h
│  │      stm32f4xx_hal_conf.h
│  │      stm32f4xx_it.h
│  │      tempCodeRunnerFile.h
│  │      usart.h
│  │      
│  └─Src
│          dma.c
│          freertos.c
│          gpio.c
│          main.c
│          stm32f4xx_hal_msp.c
│          stm32f4xx_it.c
│          syscalls.c
│          sysmem.c
│          system_stm32f4xx.c
│          usart.c
│          
├─Drivers
│  ├─CMSIS
│  │  │  LICENSE.txt
│  │  │  
│  │  ├─Device
│  │  │  └─ST
│  │  │      └─STM32F4xx
│  │  │          │  LICENSE.txt
│  │  │          │  
│  │  │          └─Include
│  │  │                  stm32f407xx.h
│  │  │                  stm32f4xx.h
│  │  │                  system_stm32f4xx.h
│  │  │                  
│  │  └─Include
│  │          cachel1_armv7.h
│  │          cmsis_armcc.h
│  │          cmsis_armclang.h
│  │          cmsis_armclang_ltm.h
│  │          cmsis_compiler.h
│  │          cmsis_gcc.h
│  │          cmsis_iccarm.h
│  │          cmsis_version.h
│  │          core_armv81mml.h
│  │          core_armv8mbl.h
│  │          core_armv8mml.h
│  │          core_cm0.h
│  │          core_cm0plus.h
│  │          core_cm1.h
│  │          core_cm23.h
│  │          core_cm3.h
│  │          core_cm33.h
│  │          core_cm35p.h
│  │          core_cm4.h
│  │          core_cm55.h
│  │          core_cm7.h
│  │          core_cm85.h
│  │          core_sc000.h
│  │          core_sc300.h
│  │          core_starmc1.h
│  │          mpu_armv7.h
│  │          mpu_armv8.h
│  │          pac_armv81.h
│  │          pmu_armv8.h
│  │          tz_context.h
│  │          
│  └─STM32F4xx_HAL_Driver
│      │  LICENSE.txt
│      │  
│      ├─Inc
│      │  │  stm32f4xx_hal.h
│      │  │  stm32f4xx_hal_cortex.h
│      │  │  stm32f4xx_hal_def.h
│      │  │  stm32f4xx_hal_dma.h
│      │  │  stm32f4xx_hal_dma_ex.h
│      │  │  stm32f4xx_hal_exti.h
│      │  │  stm32f4xx_hal_flash.h
│      │  │  stm32f4xx_hal_flash_ex.h
│      │  │  stm32f4xx_hal_flash_ramfunc.h
│      │  │  stm32f4xx_hal_gpio.h
│      │  │  stm32f4xx_hal_gpio_ex.h
│      │  │  stm32f4xx_hal_pwr.h
│      │  │  stm32f4xx_hal_pwr_ex.h
│      │  │  stm32f4xx_hal_rcc.h
│      │  │  stm32f4xx_hal_rcc_ex.h
│      │  │  stm32f4xx_hal_tim.h
│      │  │  stm32f4xx_hal_tim_ex.h
│      │  │  stm32f4xx_hal_uart.h
│      │  │  stm32f4xx_ll_bus.h
│      │  │  stm32f4xx_ll_cortex.h
│      │  │  stm32f4xx_ll_dma.h
│      │  │  stm32f4xx_ll_exti.h
│      │  │  stm32f4xx_ll_gpio.h
│      │  │  stm32f4xx_ll_pwr.h
│      │  │  stm32f4xx_ll_rcc.h
│      │  │  stm32f4xx_ll_system.h
│      │  │  stm32f4xx_ll_usart.h
│      │  │  stm32f4xx_ll_utils.h
│      │  │  
│      │  └─Legacy
│      │          stm32_hal_legacy.h
│      │          
│      └─Src
│              stm32f4xx_hal.c
│              stm32f4xx_hal_cortex.c
│              stm32f4xx_hal_dma.c
│              stm32f4xx_hal_dma_ex.c
│              stm32f4xx_hal_exti.c
│              stm32f4xx_hal_flash.c
│              stm32f4xx_hal_flash_ex.c
│              stm32f4xx_hal_flash_ramfunc.c
│              stm32f4xx_hal_gpio.c
│              stm32f4xx_hal_pwr.c
│              stm32f4xx_hal_pwr_ex.c
│              stm32f4xx_hal_rcc.c
│              stm32f4xx_hal_rcc_ex.c
│              stm32f4xx_hal_tim.c
│              stm32f4xx_hal_tim_ex.c
│              stm32f4xx_hal_uart.c
│              
└─Middlewares
    └─Third_Party
        └─FreeRTOS
            └─Source
                │  croutine.c
                │  event_groups.c
                │  LICENSE
                │  list.c
                │  queue.c
                │  stream_buffer.c
                │  tasks.c
                │  timers.c
                │  
                ├─CMSIS_RTOS
                │      cmsis_os.c
                │      cmsis_os.h
                │      
                ├─include
                │      atomic.h
                │      croutine.h
                │      deprecated_definitions.h
                │      event_groups.h
                │      FreeRTOS.h
                │      list.h
                │      message_buffer.h
                │      mpu_prototypes.h
                │      mpu_wrappers.h
                │      portable.h
                │      projdefs.h
                │      queue.h
                │      semphr.h
                │      StackMacros.h
                │      stack_macros.h
                │      stream_buffer.h
                │      task.h
                │      timers.h
                │      
                └─portable
                    ├─GCC
                    │  └─ARM_CM4F
                    │          port.c
                    │          portmacro.h
                    │          
                    └─MemMang
                            heap_4.c
                            
```