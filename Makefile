# Makefile for ss_clock
# Simple Clock for Adafruit 4x7 segment LED
# Holtek HT16K33 Ram Mapping 16*8 LED Controller Driver with keyscan
#
# Author: Bill Waller <BillWaller@wallerbroadcasting.com>
# Copyright (c) 2015 Bill Waller
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

CC=g++
CFLAGS=-g
LIBDIR=/usr/lib/i386-linux-gnu
OBJS=ss_clock

all:	$(OBJS)

clean:
	rm -f *.o $(OBJS)

ss_clock:	ss_clock.c ht16k33.h
	$(CC) $(CFLAGS) ss_clock.c -o ss_clock -L$(LIBDIR) -lmraa
