/**
  ******************************************************************************
  * @file    MICOAppEntrance.c 
  * @author  William Xu
  * @version V1.0.0
  * @date    05-May-2014
  * @brief   Mico application entrance, addd user application functons and threads.
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

#include "MICODefine.h"
#include "MICOAppDefine.h"

#include "StringUtils.h"
#include "MicoPlatform.h"
#include "zc_mx_adpter.h"
#include <ac_hal.h>
#define app_log(M, ...) custom_log("APP", M, ##__VA_ARGS__)
#define app_log_trace() custom_log_trace("APP")

volatile ring_buffer_t  rx_buffer;
volatile uint8_t        rx_data[UART_BUFFER_LENGTH];
mico_semaphore_t query_sem;   
/* MICO system callback: Restore default configuration provided by application */
void appRestoreDefault_callback(mico_Context_t *inContext)
{
     inContext->flashContentInRam.appConfig.configDataVer = CONFIGURATION_VERSION;
}

OSStatus MICOStartUart( mico_Context_t * const inContext )
{
    OSStatus err = kNoErr;
    mico_uart_config_t uart_config;
        /*UART receive thread*/
    uart_config.baud_rate    = 115200;
    uart_config.data_width   = DATA_WIDTH_8BIT;
    uart_config.parity       = NO_PARITY;
    uart_config.stop_bits    = STOP_BITS_1;
    uart_config.flow_control = FLOW_CONTROL_DISABLED;

    if(inContext->flashContentInRam.micoSystemConfig.mcuPowerSaveEnable == true)
        uart_config.flags = UART_WAKEUP_ENABLE;
    else
        uart_config.flags = UART_WAKEUP_DISABLE;
    ring_buffer_init  ( (ring_buffer_t *)&rx_buffer, (uint8_t *)rx_data, UART_BUFFER_LENGTH );
    MicoUartInitialize( UART_FOR_APP, &uart_config, (ring_buffer_t *)&rx_buffer );
    return err;
}

/*************************************************
* Function: MICOStartUart
* Description: 
* Author: cxy 
* Returns: 
* Parameter: 
* History:
*************************************************/
void MICORfLed_thread(void * inContext )
{  
    static bool onoff = true;
    while(1){

            mico_rtos_get_semaphore(&query_sem, 1000); 
            onoff = !onoff;            
            MicoRfLed(onoff);                    

    }
}

/*************************************************
* Function: MICOBlinkRfLed
* Description: 
* Author: cxy 
* Returns: 
* Parameter: 
* History:
*************************************************/
OSStatus MICOBlinkRfLed(mico_Context_t * const inContext)
{

  OSStatus err = kUnknownErr;
  mico_rtos_init_semaphore(&query_sem, 1);
    

  err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "query", MICORfLed_thread, 0x500, (void*)inContext );

  return err;
}

OSStatus MICOStartApplication( mico_Context_t * const inContext )
{
    app_log_trace();
    OSStatus err = kNoErr;
    
    require_action(inContext, exit, err = kParamErr);
    
    MX_Init();
    AC_Init();
    
    err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "UART Recv", uartRecv_thread, STACK_SIZE_REMOTE_TCP_CLIENT_THREAD, (void*)inContext );
    require_noerr_action( err, exit, app_log("ERROR: Unable to start the uart recv thread.") );
    
    
	err = mico_rtos_create_thread(NULL, MICO_APPLICATION_PRIORITY, "HF_Cloudfunc", MX_Cloudfunc, STACK_SIZE_REMOTE_TCP_CLIENT_THREAD, (void*)inContext );
	require_noerr_action( err, exit, app_log("ERROR: Unable to start the MX_Cloudfunc thread.") );

    exit:
    return err;
}




