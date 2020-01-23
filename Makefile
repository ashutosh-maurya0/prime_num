##
## Makefile for prime
##
## written by Prine Maurya <kumarprince9211420@gmail.com>
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

CC = gcc
CFLAGS = -g2 -O2 -Wall -W -pthread
PROGRAM = prime
INSTALL = /usr/bin/env install
PREFIX  = /usr/local
OS_ARCH = $(shell uname)

ifeq ($(shell uname -o 2>/dev/null), Cygwin)
LDFLAGS = -lioperm
endif

ifeq ($(OS_ARCH), $(filter $(OS_ARCH), NetBSD OpenBSD))
LDFLAGS = -l$(shell uname -p)
endif

all: $(PROGRAM)

$(PROGRAM): output.o helpf.o primef.o primef_struct.o main.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

install: $(PROGRAM)
	$(INSTALL) $(PROGRAM) $(PREFIX)/sbin

clean:
	rm -f *.o $(PROGRAM) junit.xml

distclean: clean

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I. -o $@

.PHONY: all install clean distclean
