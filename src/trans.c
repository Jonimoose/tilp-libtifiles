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

/*
  This unit is used to translate some varnames into a more readable name.
  Depends on the calculator type and the variable type.
*/

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "typesxx.h"
#include "file_int.h"

/* 
   Some varnames have to be translated in a more useable name.
   See the protocol doc for more informations
*/
char *ti73_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  int i;

  switch(vartype)
    {
    case TI73_WDW:
      strcpy(translate, "Window");
      break;
    case TI73_ZSTO:
      strcpy(translate, "RclWin");
      break;
    case TI73_TAB:
      strcpy(translate, "TblSet");
      break;
    default:
      switch(varname[0] & 0xFF)
	{
	case 0x5D:
	  if(varname[1] > 0x09)
	    {
	      for(i=0; i<7; i++) { (translate)[i]=varname[i+1]; }
	      break;
	    }
	    sprintf(translate, "L%c", varname[1]+'0'); //TI73 != TI83 here
	  break;
	case 0x5C:
	  sprintf(translate, "[%c]", varname[1]+'A');
	  break;
	case 0x5E:
	  switch( (varname[1] & 0xF0) >> 4)
	    {
	    case 1:
	      if(varname[1] != 0x19)
		sprintf(translate, "Y%c", (varname[1] & 0xFF) + '1'-0x10);
	      else 
		strcpy(translate, "Y0");
	      break;
	    case 2:
	      if(varname[1] & 0x01 )
		{
		  sprintf(translate, "X%ct", ( (varname[1]-0x20) >> 1)+'1');
		}
	      else
		{
		  sprintf(translate, "Y%ct", ( (varname[1]-0x20) >> 1)+'1');
		}
	      break;
	    case 4:
	      sprintf(translate, "r%c", (varname[1] & 0xFF) - 0x40+'1');
	      break;
	    case 8:
	      sprintf(translate, "%c", (varname[1] & 0xFF) - 0x80+'u');
	      break;
	    }
	  break;
	case 0xAA:
	  if(varname[1] != 0x09)
	    sprintf(translate, "Str%c", varname[1]+'1');
	  else
	    strcpy(translate, "Str0");
	  break;
	case 0x60:
	  if(varname[1] != 0x09)
	    sprintf(translate, "Pic%c", varname[1]+'1');
	  else
	    strcpy(translate, "Pic0");
	  break;
	case 0x61:
	  if(varname[1] != 0x09)
	    sprintf(translate, "GDB%c", varname[1]+'1');
	  else
	    strcpy(translate, "GDB0");
	  break;
	default:
	  strcpy(translate, varname);
	}
      break;
    }

  return translate;
}

char *ti82_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  int i;

  /*
  printf("-> <%s> ", varname);
  for(i=0; i<8; i++) { printf("%02X ", 0xFF & varname[i]); }
  printf("\n");
  */
  switch(vartype)
    {
    case TI82_WDW:
      strcpy(translate, "Window");
      break;
    case TI82_ZSTO:
      strcpy(translate, "RclWin");
      break;
    case TI82_TAB:
      strcpy(translate, "TblSet");
      break;
    default:
      switch(varname[0] & 0xFF)
	{
	case 0x5D: /* List */
	  if(varname[1] > 0x09)
	    {
	      for(i=0; i<7; i++) { translate[i]=varname[i+1]; }
	      break;
	    }
	  sprintf(translate, "L%c", varname[1]+'1');
	  break;
	case 0x5C: /* Matrix */
	  sprintf(translate, "[%c]", varname[1]+'A');
	  break;
	case 0x5E: /* Equations */
	  switch( (varname[1] & 0xF0) >> 4)
	    {
	    case 1:
	      if(varname[1] != 0x19)
		sprintf(translate, "Y%c", (varname[1] & 0xFF) + '1'-0x10);
	      else
		strcpy(translate, "Y0");
	      break;
	    case 2:
	      if(varname[1] & 0x01)
		{
		  sprintf(translate, "Y%ct", ( (varname[1]-0x20) >> 1)+'1');
		}
	      else
		{
		  sprintf(translate, "X%ct", ( (varname[1]-0x20) >> 1)+'1');
		}
	      break;
	    case 4:
	      sprintf(translate, "r%c", (varname[1] & 0xFF) - 0x40+'1');
	      break;
	    case 8:
	      sprintf(translate, "%c", (varname[1] & 0xFF) - 0x80+'u');
	      break;
	    }
	  break;
	case 0x60: /* Pictures */
	  sprintf(translate, "Pic%c", varname[1]+'1');
	  break;
	case 0x61: /* Gdb */
	  sprintf(translate, "GDB%c", varname[1]+'1');
	  break;
	default:
	  strcpy(translate, varname);
	}
      break;
    }

  return translate;
}

char *ti83_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  int i;

  switch(vartype)
    {
    case TI82_WDW:
      strcpy(translate, "Window");
      break;
    case TI82_ZSTO:
      strcpy(translate, "RclWin");
      break;
    case TI82_TAB:
      strcpy(translate, "TblSet");
      break;
    default:
      switch(varname[0] & 0xFF)
	{
	case 0x5D:
	  if(varname[1] > 0x09)
	    {
	      for(i=0; i<7; i++) { (translate)[i]=varname[i+1]; }
	      break;
	    }
	  if(varname[1] != 0x09)
	    sprintf(translate, "L%c", varname[1]+'1');
	  else 
	    strcpy(translate, "L9");
	  break;
	case 0x5C:
	  sprintf(translate, "[%c]", varname[1]+'A');
	  break;
	case 0x5E:
	  switch( (varname[1] & 0xF0) >> 4)
	    {
	    case 1:
	      if(varname[1] != 0x19)
		sprintf(translate, "Y%c", (varname[1] & 0xFF) + '1'-0x10);
	      else 
		strcpy(translate, "Y0");
	      break;
	    case 2:
	      if(varname[1] & 0x01 )
		{
		  sprintf(translate, "X%ct", ( (varname[1]-0x20) >> 1)+'1');
		}
	      else
		{
		  sprintf(translate, "Y%ct", ( (varname[1]-0x20) >> 1)+'1');
		}
	      break;
	    case 4:
	      sprintf(translate, "r%c", (varname[1] & 0xFF) - 0x40+'1');
	      break;
	    case 8:
	      sprintf(translate, "%c", (varname[1] & 0xFF) - 0x80+'u');
	      break;
	    }
	  break;
	case 0xAA:
	  if(varname[1] != 0x09)
	    sprintf(translate, "Str%c", varname[1]+'1');
	  else
	    strcpy(translate, "Str0");
	  break;
	case 0x60:
	  if(varname[1] != 0x09)
	    sprintf(translate, "Pic%c", varname[1]+'1');
	  else
	    strcpy(translate, "Pic0");
	  break;
	case 0x61:
	  if(varname[1] != 0x09)
	    sprintf(translate, "GDB%c", varname[1]+'1');
	  else
	    strcpy(translate, "GDB0");
	  break;
	default:
	  strcpy(translate, varname);
	}
      break;
    }

  return translate;
}

/* TI83+ is not supported yet */
char *ti83p_translate_varname(const char *varname, char *translate, 
			      uint8_t vartype)
{
  return ti83_translate_varname(varname, translate, vartype);
}

/*
  Other calc do not need varname translation but these functions are provided
  as general functions
*/

char *ti85_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  strcpy(translate, varname);
  
  return translate;
}

char *ti86_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  strcpy(translate, varname);

  return translate;
}

char *ti89_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  strcpy(translate, varname);

  return translate;
}

char *ti92_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  strcpy(translate, varname);

  return translate;
}

char *ti92p_translate_varname(const char *varname, char *translate, 
			      uint8_t vartype)
{
  strcpy(translate, varname);

  return translate;
}

char *v200_translate_varname(const char *varname, char *translate, 
			     uint8_t vartype)
{
  strcpy(translate, varname);
  
  return translate;
}

char *tixx_translate_varname(const char *varname, char *translate,
                             uint8_t vartype, int calc_type)
{
  switch(calc_type)
    {
    case CALC_TI73:
      return ti73_translate_varname(varname, translate, vartype); break;
    case CALC_TI82:
      return ti82_translate_varname(varname, translate, vartype); break;
    case CALC_TI83:
      return ti83_translate_varname(varname, translate, vartype); break;
    case CALC_TI83P:
      return ti83p_translate_varname(varname, translate, vartype); break;
    case CALC_TI85:
      return ti85_translate_varname(varname, translate, vartype); break;
    case CALC_TI86:
      return ti86_translate_varname(varname, translate, vartype); break;
    case CALC_TI89:
      return ti89_translate_varname(varname, translate, vartype); break;
    case CALC_TI92:
      return ti92_translate_varname(varname, translate, vartype); break;
    case CALC_TI92P:
      return ti92p_translate_varname(varname, translate, vartype); break;
    case CALC_V200:
      return v200_translate_varname(varname, translate, vartype); break;
    default:
      return "invalid calc type !";
      break;
    }
}

extern int tifiles_calc_type;

TIEXPORT char* TICALL tifiles_translate_varname(const char *varname, 
						char *translate,
						uint8_t vartype)
{
  return 
    tixx_translate_varname(varname, translate, vartype, tifiles_calc_type);
}

TIEXPORT char* TICALL tifiles_translate_varname2(const char *varname,
						 uint8_t vartype)
{
  static char trans[9];

  return tixx_translate_varname(varname, trans, vartype, tifiles_calc_type);
}
