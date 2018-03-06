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
 * @file nrf.c
 * @brief Interface with nRF24L01 chip over SPI
 * 
 * Interface with nRF24L01 chip over SPI
 * 
 * @author Matthew Haney
 * @date 2018-04-08
 */

#include <stdint.h>
#include <stddef.h> /* NULL and size_t */

#include "nrf.h"

uint8_t nrf_read_register(uint8_t reg) {
  /* Use 5 least significant bits of parameter as address */
  reg &= 0x1F;
  nrf_chip_enable();
  SPI_write_byte(reg);
  uint8_t result;
  SPI_read_byte(&result);
  nrf_chip_disable();
  return result;
}

void nrf_write_register(uint8_t reg, uint8_t value) {
  /* Use 5 least significant bits of parameter as address */
  reg &= 0x1F;
  nrf_chip_enable();
  SPI_write_byte(reg);
  SPI_write_byte(value);
  nrf_chip_disable();
}

uint8_t nrf_read_status() {
  return nrf_read_register(NRF_STATUS_REG);
}

void nrf_write_config(uint8_t config) {
  nrf_write_register(NRF_CONFIG_REG, config);
}

uint8_t nrf_read_config() {
  return nrf_read_register(NRF_CONFIG_REG);
}

uint8_t nrf_read_rf_setup() {
  return nrf_read_register(NRF_RF_SETUP_REG);
}

void nrf_write_rf_setup(uint8_t config) {
  nrf_write_register(NRF_RF_SETUP_REG, config);
}

uint8_t nrf_read_rf_ch() {
  return nrf_read_register(NRF_RF_CH_REG);
}

void nrf_write_rf_ch(uint8_t channel) {
  nrf_write_register(NRF_RF_CH_REG, channel);
}

void nrf_read_TX_ADDR(uint8_t * address) {
  
}

void nrf_write_TX_ADDR(uint8_t * tx_addr) {
}

uint8_t nrf_read_fifo_status() {
  return nrf_read_register(NRF_FIFO_STATUS_REG);
}

void nrf_flush_tx_fifo() {
  nrf_chip_enable();
  SPI_write_byte(0xc1);
  nrf_chip_disable();
}

void nrf_flush_rx_fifo() {
  nrf_chip_enable();
  SPI_write_byte(0xc2);
  nrf_chip_disable();
}
