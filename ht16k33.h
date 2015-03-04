/* ht16k33.h
 *
 * Holtek HT16K33 Ram Mapping 16*8 LED Controller Driver with keyscan
 *
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

#define HT16K33_I2C_ADDR           0x70
#define HT16K33_OSCILLATOR_OFF     0x20
#define HT16K33_OSCILLATOR_ON      0x21
#define HT16K33_DISPLAY_OFF        0x80
#define HT16K33_DISPLAY_ON         0x81
#define HT16K33_BLINK_MS_500       0x02
#define HT16K33_BLINK_MS_1000      0x04
#define HT16K33_BLINK_MS_2000      0x06
#define HT16K33_BRIGHTNESS_CMD     0xE0
#define HT16K33_BRIGHTNESS_LOW     0x03
#define HT16K33_BRIGHTNESS_MED     0x07
#define HT16K33_BRIGHTNESS_MAX     0x0F
#define HT16K33_OUT_ROW            0xA0
#define HT16K33_OUT_LOW_INT        0xA1
#define HT16K33_OUT_HIGH_INT       0xA3

#define SS_DGT1                       1
#define SS_DGT2                       3
#define SS_COLON                      5
#define SS_DGT3                       7
#define SS_DGT4                       9
#define SS_COLON_GLYPH             0x02
#define SS_DP                      0x80
