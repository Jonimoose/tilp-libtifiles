/*  libtifiles - TI File Format library
 *  Copyright (C) 2002  Romain Lievin
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __TIFILES_MACROS__
#define __TIFILES_MACROS__

#ifndef TIFILES_MACROS
#define TIFILES_MACROS

#include <stdint.h>

/* Macros, part 1 */
// extract a word from a longword
# define LSW(l) (uint16_t) ((l) & 0x0000FFFF)
# define MSW(l) (uint16_t)(((l) & 0xFFFF0000) >> 16)
// extract a byte from a word
# define LSB(w) (uint8_t) ((w) & 0x00FF)
# define MSB(w) (uint8_t)(((w) & 0xFF00) >> 8)
// extract a nibble from a byte
# define LSN(b)  ((b) & 0x0F)
# define MSN(b) (((b) & 0xF0) >> 4)
// convert 2 nibbles into a BCD byte
# define BCD(b) (10*MSN(b)+LSN(b))
#endif

/* Macros, part 2 */
// these macro are in little endian format (Intel ?, LSB first)
#define NIBBLE2BYTE(l, u)           ((l) + ((u) << 4))
#define NIBBLE2WORD(ll, lu, ul, uu) ((ll) + ((lu) << 4) + ((ul) << 8) + ((uu) << 12))

#define BYTE2WORD(l, u)               ((l) + ((u) << 8))
#define BYTE2LONGWORD(ll, lu, ul, uu) ((ll) + ((lu) << 8) + ((ul) << 16) + ((uu) << 24))
#define WORD2LONGWORD(l, u)           ((l) + ((u) << 16))

#define L_NIBBLE2BYTE   NIBBLE2BYTE
#define L_NIBBLE2WORD   NIBBLE2WORD
#define L_BYTE2WORD     BYTE2WORD
#define L_BYTE2LONGWORD BYTE2LONGWORD
#define L_WORD2LONGWORD WORD2LONGWORD

// these macros are in big endian format (Motorola ?, MSB first)
#define B_NIBBLE2BYTE(u, l)           ((l) + ((u) << 4))
#define B_NIBBLE2WORD(uu, ul, lu, ll) ((ll) + ((lu) << 4) + ((ul) << 8) + ((uu) << 12))

#define B_BYTE2WORD(u, l)               ((l) + ((u) << 8))
#define B_BYTE2LONGWORD(uu, ul, lu, ll) ((ll) + ((lu) << 8) + ((ul) << 16) + ((uu) << 24))
#define B_WORD2LONGWORD(u, l)           ((l) + ((u) << 16))

/* 
   A very very useful macro ! 
   Used to propagate an error code when a function returns.
*/
#ifndef TRY
# define TRY(x) { int aaaa_; if((aaaa_ = (x))) return aaaa_; }   //new !
#endif
#define TRYC(x) { int aaa_; if((aaa_ = (x))) return aaa_; } 
#define TRY_ TRYC

/*
  The directory separator depending on the platform
*/
#if defined(__WIN32__)
#  define DIR_SEPARATOR "\\"
#  define DIR_SEPARATOR_S "\\"
#  define DIR_SEPARATOR_C '\\'
#elif defined(__LINUX__)
#  define DIR_SEPARATOR "/"
#  define DIR_SEPARATOR_S "/"
#  define DIR_SEPARATOR_C '/'
#endif

#endif




