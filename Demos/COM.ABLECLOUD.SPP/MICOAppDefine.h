/**
  ******************************************************************************
  * @file    MICOAppDefine.h 
  * @author  William Xu
  * @version V1.0.0
  * @date    05-May-2014
  * @brief   This file create a TCP listener thread, accept every TCP client
  *          connection and create thread for them.
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, MXCHIP Inc. SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2014 MXCHIP Inc.</center></h2>
  ******************************************************************************
  */ 


#ifndef __MICOAPPDEFINE_H
#define __MICOAPPDEFINE_H

#include "MICO.h"
#include "Common.h"

#define APP_INFO  "3088@Ablecloud"

#define FIRMWARE_REVISION   "MICO_SPP_2_4"
#define MANUFACTURER        "MXCHIP Inc."
#define SERIAL_NUMBER       "20140606"
#define PROTOCOL            "com.ablecloud.spp"

/* Wi-Fi configuration mode */
#define MICO_CONFIG_MODE CONFIG_MODE_EASYLINK_WITH_SOFTAP

/* Demo C function call C++ function and C++ function call C function */
//#define MICO_C_CPP_MIXING_DEMO

/*User provided configurations*/
#define CONFIGURATION_VERSION               0x00000000 // if default configuration is changed, update this number
#define MAX_QUEUE_NUM                       6  // 1 remote client, 5 local server
#define MAX_QUEUE_LENGTH                    8  // each queue max 8 msg
#define UART_RECV_TIMEOUT                   500
#define UART_ONE_PACKAGE_LENGTH             1024
#define wlanBufferLen                       1024
#define UART_BUFFER_LENGTH                  2048
#define RECVED_UART_DATA_LOOPBACK_PORT      1003


/* Define thread stack size */
#ifdef DEBUG
  #define STACK_SIZE_UART_RECV_THREAD           0x2A0
  #define STACK_SIZE_LOCAL_TCP_SERVER_THREAD    0x300
  #define STACK_SIZE_LOCAL_TCP_CLIENT_THREAD    0x350
  #define STACK_SIZE_REMOTE_TCP_CLIENT_THREAD   0x500
#else
  #define STACK_SIZE_UART_RECV_THREAD           0x150
  #define STACK_SIZE_LOCAL_TCP_SERVER_THREAD    0x180
  #define STACK_SIZE_LOCAL_TCP_CLIENT_THREAD    0x200
  #define STACK_SIZE_REMOTE_TCP_CLIENT_THREAD   0x260
#endif

/*Running status*/
typedef struct{
  /*Local clients port list*/
  uint32_t          configDataVer;
} application_config_t;
void uartRecv_thread(void *inContext);

#endif

