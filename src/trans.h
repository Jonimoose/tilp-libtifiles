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

#ifndef __TIFILES_TRANS__
#define __TIFILES_TRANS__

#include "export.h"

char *tixx_translate_varname(const char *varname, char *translate,
                             uint8_t vartype, int calc_type);

char *ti73_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype);
char *ti82_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype);
char *ti83_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype);
char *ti83p_translate_varname(const char *varname, char *translate, 
			      uint8_t vartype);
char *ti85_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype);
char *ti86_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype);
char *ti89_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype);
char *ti92_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype);
char *ti92p_translate_varname(const char *varname, char *translate, 
			      uint8_t vartype);

#endif


