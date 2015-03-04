/* ss_clock.c
 * Clock Display for Adafruit 4x7 segment LED
 * Holtek HT16K33 Ram Mapping 16*8 LED Controller Driver with keyscan
 * Author: Bill Waller <BillWaller@wallerbroadcasting.com>
 * Copyright (c) 2015 Bill Waller
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <mraa.h>
#include "ht16k33.h"

/*---------------------------------------------
 *         1
 *        ---
 *     6 |   | 2
 *        -7-
 *     5 |   | 3
 *        ---  o 8
 *         4
 *
 *  0     1     2     3     4     5     6     7
 *  8     9     A     B     C     D     E     F
 *---------------------------------------------*/
static const uint8_t ss_number_glyph[]={
  0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07,
  0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5E, 0x79, 0x71 };

/*--------------------------------------------------------------
 * ss_str - Ram address, followed by 16 8-bit words
 *          LED Digits:  (1)   7   (2)   8   (:)   9   (3)   A
 *                       (4)   :    5    B    6    C    :    X
 *--------------------------------------------------------------*/
uint8_t ss_str[]={ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                        0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 };

long int time(), now;
struct tm *tmstruct, *localtime();
mraa_i2c_context i2c;
mraa_i2c_context ss_init();
void ss_time(mraa_i2c_context);

int
main(int argc, char **argv)
{
  i2c=ss_init();
 
  while (1)
      ss_time(i2c);
  return(0);
}

mraa_i2c_context ss_init()
{                                      // Initialize i2c bus and ht16k33
  mraa_init();
  i2c=mraa_i2c_init(0);
  mraa_i2c_address(i2c,HT16K33_I2C_ADDR);
  mraa_i2c_write_byte(i2c,HT16K33_OSCILLATOR_OFF);
  mraa_i2c_address(i2c,HT16K33_I2C_ADDR);
  mraa_i2c_write_byte(i2c,HT16K33_OSCILLATOR_ON);
  mraa_i2c_address(i2c,HT16K33_I2C_ADDR);
  mraa_i2c_write_byte(i2c,HT16K33_DISPLAY_ON);
  mraa_i2c_address(i2c,HT16K33_I2C_ADDR);
  mraa_i2c_write_byte(i2c,HT16K33_BRIGHTNESS_CMD|HT16K33_BRIGHTNESS_LOW);
  return(i2c);
}

void ss_time(mraa_i2c_context i2c)
{                    // Write local time to display and sleep 10 seconds
  time(&now);
  tmstruct=localtime(&now);
  ss_str[SS_DGT1]=ss_number_glyph[tmstruct->tm_hour/10];
  ss_str[SS_DGT2]=ss_number_glyph[tmstruct->tm_hour%10];
  ss_str[SS_COLON]=SS_COLON_GLYPH;
  ss_str[SS_DGT3]=ss_number_glyph[tmstruct->tm_min/10];
  ss_str[SS_DGT4]=ss_number_glyph[tmstruct->tm_min%10];
  mraa_i2c_address(i2c,HT16K33_I2C_ADDR);
  mraa_i2c_write(i2c,ss_str,10);
  sleep(10);
};
