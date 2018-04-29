/******************************************************************************
 * Copyright (C) 2018
 * Christopher Morroni and Matthew Haney
 * University of Colorado, Boulder
 *
 * Redistribution, modification, or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Christopher Morroni, Matthew Haney, and the University of
 * Colorado are not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file log.c
 * @brief 
 *
 * 
 *
 * @author Christopher Morroni
 * @date 04/27/2018
 */

#include "conversion.h"
#include "log.h"

void log_data(void * data, uint8_t len)
{
#ifdef DEBUG
  PRINT_ITEM(data, len);
#endif
}

void log_string(uint8_t * str)
{
#ifdef DEBUG
  PRINT_STR(str);
#endif
}

void log_int(int32_t i)
{
#ifdef DEBUG
  uint8_t conversion_buf[12], len;
  len = my_itoa(i, conversion_buf, BASE_10);
  PRINT_ITEM(conversion_buf, len);
#endif
}

void log_flush()
{
#ifdef DEBUG
#ifdef PLATFORM_KL25Z
  while(!(UART0_S1 & UART0_S1_TC_MASK));
#else
  fflush(stdout);
#endif /* PLATFORM_KL25Z */
#endif /* DEBUG */
}

void log_item(log_item_t * log)
{
#ifdef DEBUG
  PRINT_ITEM(log, sizeof(log->timestamp) + sizeof(log->id) + sizeof(log->source_id) + sizeof(log->len));
  PRINT_ITEM(log->payload, log->len);
  PRINT_ITEM(&log->crc, sizeof(log->crc);
#endif
}
