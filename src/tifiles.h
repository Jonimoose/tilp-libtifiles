/* Hey EMACS -*- linux-c -*- */
/* $Id$ */

/*  libTIFILES - Ti File Format library, a part of the TiLP project
 *  Copyright (C) 1999-2005  Romain Lievin
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

#ifndef __TIFILES_H__
#define __TIFILES_H__

#include "export.h"

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

/* Versioning */

#ifdef __WIN32__
# define LIBTIFILES_VERSION "0.0.1"
#else
# define LIBTIFILES_VERSION VERSION
#endif

/* Definitions */

#define VARNAME_MAX		18	// group/name: 8 + 1 + 8 + 1
#define TIFILES_NCALCS	12	// # of supported calcs

typedef enum {
	CALC_NONE = 0,
	CALC_TI73, CALC_TI82, CALC_TI83, CALC_TI83P, CALC_TI84P, CALC_TI85, CALC_TI86,
	CALC_TI89, CALC_TI89T, CALC_TI92, CALC_TI92P, CALC_V200,
} TiCalcType;

typedef enum {
  ATTRB_NONE = 0, ATTRB_LOCKED = 1, ATTRB_PROTECTED, ATTRB_ARCHIVED = 3
} TiFileAttr;

typedef enum {
  TIFILE_SINGLE = 1, TIFILE_GROUP = 2, TIFILE_BACKUP = 4, TIFILE_FLASH = 8,
} TiFileType;

typedef enum {
  ENCODING_ASCII = 1, ENCODING_LATIN1, ENCODING_UNICODE
} TiFileEncoding;

#include "typesxx.h"
#include "filesxx.h"

/* Functions */

#ifdef __cplusplus
extern "C" {
#endif

  /****************/
  /* Entry points */
  /****************/
  
  TIEXPORT int TICALL tifiles_init(void);
  TIEXPORT int TICALL tifiles_exit(void);

  /*********************/
  /* General functions */
  /*********************/

  // intrface.c
  TIEXPORT const char* TICALL tifiles_get_version(void);
  TIEXPORT int         TICALL tifiles_get_error(int number, char **message);

  // trans.c
  TIEXPORT uint8_t TICALL *tixx_detokenize_varname(TiCalcType model, const char *src, char *dst, uint8_t vartype);

  TIEXPORT char* TICALL tifiles_transcode_to_ascii(TiCalcType model, char* dst, const char *src);
  TIEXPORT char* TICALL tifiles_transcode_to_latin1(TiCalcType model, char* dst, const char *src);
  TIEXPORT char* TICALL tifiles_transcode_to_unicode(TiCalcType model, char* dst, const char *src);

  TIEXPORT void TICALL tifiles_translate_set_encoding(TiFileEncoding encoding);
  TIEXPORT TiFileEncoding TICALL tifiles_translate_get_encoding(void);

  TIEXPORT char *TICALL tifiles_translate_varname(TiCalcType model, char *dst, const char *src, uint8_t vartype);
  TIEXPORT char *TICALL tifiles_translate_varname_static(TiCalcType model, const char *src, uint8_t vartype);
  
  // typesXX.c
  TIEXPORT const char* TICALL tifiles_vartype2string(uint8_t data);
  TIEXPORT uint8_t     TICALL tifiles_string2vartype(const char *s);
  TIEXPORT const char* TICALL tifiles_vartype2file(uint8_t data);
  TIEXPORT uint8_t     TICALL tifiles_file2vartype(const char *s);

  TIEXPORT const char* TICALL tifiles_vartype2icon(uint8_t data);
  TIEXPORT const char* TICALL tifiles_vartype2desc(uint8_t data);

  TIEXPORT const char* TICALL tifiles_group_file_ext(void);
  TIEXPORT const char* TICALL tifiles_backup_file_ext(void);
  TIEXPORT const char* TICALL tifiles_flash_app_file_ext(void);
  TIEXPORT const char* TICALL tifiles_flash_os_file_ext(void);

  TIEXPORT int TICALL tifiles_is_a_ti_file(const char *filename);
  TIEXPORT int TICALL tifiles_is_a_single_file(const char *filename);
  TIEXPORT int TICALL tifiles_is_a_group_file(const char *filename);
  TIEXPORT int TICALL tifiles_is_a_regular_file(const char *filename);
  TIEXPORT int TICALL tifiles_is_a_backup_file(const char *filename);
  TIEXPORT int TICALL tifiles_is_a_flash_file(const char *filename);
  TIEXPORT int TICALL tifiles_is_a_tib_file(const char *filename);

  TIEXPORT int TICALL tifiles_which_calc_type(const char *filename);
  TIEXPORT int TICALL tifiles_which_file_type(const char *filename);

  TIEXPORT const char* TICALL tifiles_file_descriptive(const char *filename);
  TIEXPORT const char* TICALL tifiles_file_icon(const char *filename);

  TIEXPORT const char* TICALL tifiles_calctype2signature(TiCalcType calc_type);
  TIEXPORT TiCalcType  TICALL tifiles_signature2calctype(const char *signat);
	
  TIEXPORT const int TICALL tifiles_folder_type(void);
  TIEXPORT const int TICALL tifiles_flash_type(void);
  TIEXPORT const int TICALL tifiles_idlist_type(void);
  
  TIEXPORT int TICALL tifiles_is_ti8x(TiCalcType calc_type);
  TIEXPORT int TICALL tifiles_is_ti9x(TiCalcType calc_type);

  // misc.c
  TIEXPORT char* TICALL tifiles_get_extension(const char *filename);
  TIEXPORT char* TICALL tifiles_dup_extension(const char *filename);

  TIEXPORT uint16_t TICALL tifiles_compute_checksum(uint8_t * buffer,
						    int size);

  TIEXPORT char* TICALL tifiles_get_varname(const char *full_name);
  TIEXPORT char* TICALL tifiles_get_fldname(const char *full_name);
  TIEXPORT int   TICALL tifiles_build_fullname(TiCalcType model,
	                     char *full_name,
					     const char *fldname,
					     const char *varname);

  // filesXX.c: layer built on files8x/9x
  TIEXPORT TiRegular *TICALL tifiles_create_regular_content(void);
  TIEXPORT int TICALL tifiles_free_regular_content(TiRegular * content);
  TIEXPORT int TICALL tifiles_read_regular_file(const char *filename,
						TiRegular * content);
  TIEXPORT int TICALL tifiles_write_regular_file(const char *filename,
						 TiRegular * content,
						 char **filename2);
  TIEXPORT int TICALL tifiles_display_file(const char *filename);

  TIEXPORT int TICALL tifiles_create_table_of_entries(TiRegular *content,
						      int ***tabl,
						      int *nfolders);

  // grp_ops.c
  TIEXPORT int TICALL tifiles_group_contents(TiRegular ** srcs,
					     TiRegular ** dest);
  TIEXPORT int TICALL tifiles_ungroup_content(TiRegular * src,
					      TiRegular *** dest);

  TIEXPORT int TICALL tifiles_group_files(char **filenames,
					  const char *filename);
  TIEXPORT int TICALL tifiles_ungroup_file(const char *filename);

  // type2str.c
  TIEXPORT const char* TICALL tifiles_calctype_to_string(TiCalcType type);
  TIEXPORT TiCalcType  TICALL tifiles_string_to_calctype(const char *str);
  
  TIEXPORT const char* TICALL tifiles_attribute_to_string(TiFileAttr atrb);
  TIEXPORT TiFileAttr  TICALL tifiles_string_to_attribute(const char *str);
  
  TIEXPORT const char* TICALL tifiles_filetype_to_string(TiFileType type);
  TIEXPORT TiFileType  TICALL tifiles_string_to_filetype(const char *str);

  // special for win32 (DLL partition -> memory violation)
#ifdef __WIN32__
  TIEXPORT void* TICALL tifiles_calloc(size_t nmemb, size_t size);
  TIEXPORT void* TICALL tifiles_malloc(size_t size);
  TIEXPORT void  TICALL tifiles_free(void *ptr);
  TIEXPORT void* TICALL tifiles_realloc(void *ptr, size_t size);
#else
# define tifiles_calloc  calloc
# define tifiles_malloc  malloc
# define tifiles_free    free
# define tifiles_realloc realloc
#endif

  // deprecated
  // nothing yet
  TIEXPORT void TICALL tifiles_set_calc(TiCalcType type);
  TIEXPORT TiCalcType TICALL tifiles_get_calc(void);

#ifdef __cplusplus
}
#endif

#endif
