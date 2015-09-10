/**
******************************************************************************
* @file    MicoDriverAdc.c 
* @author  William Xu
* @version V1.0.0
* @date    05-May-2014
* @brief   This file provide ADC driver functions.
******************************************************************************
*
*  The MIT License
*  Copyright (c) 2014 MXCHIP Inc.
*
*  Permission is hereby granted, free of charge, to any person obtaining a copy 
*  of this software and associated documentation files (the "Software"), to deal
*  in the Software without restriction, including without limitation the rights 
*  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
*  copies of the Software, and to permit persons to whom the Software is furnished
*  to do so, subject to the following conditions:
*
*  The above copyright notice and this permission notice shall be included in
*  all copies or substantial portions of the Software.
*
*  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
*  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
*  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
*  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
*  WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR 
*  IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
******************************************************************************
*/ 

#include "platform.h"
#include "platform_peripheral.h"


/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *               Variables Definitions
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/


/******************************************************
 *               Function Definitions
 ******************************************************/



OSStatus platform_adc_init( const platform_adc_t* adc, uint32_t sample_cycle )
{
  UNUSED_PARAMETER(adc);
  UNUSED_PARAMETER(sample_cycle);
  platform_log("unimplemented");
  return kUnsupportedErr;
}

OSStatus platform_adc_take_sample( const platform_adc_t* adc, uint16_t* output )
{
  UNUSED_PARAMETER(output);
  platform_log("unimplemented");
  return kUnsupportedErr;
}

OSStatus platform_adc_take_sample_stream( const platform_adc_t* adc, void* buffer, uint16_t buffer_length )
{
  UNUSED_PARAMETER(adc);
  UNUSED_PARAMETER(buffer);
  UNUSED_PARAMETER(buffer_length);
  platform_log("unimplemented");
  return kUnsupportedErr;
}

OSStatus platform_adc_deinit( const platform_adc_t* adc )
{
  UNUSED_PARAMETER(adc);
  platform_log("unimplemented");
  return kUnsupportedErr;
}