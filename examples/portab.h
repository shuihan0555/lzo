/* portab.h -- portability layer

   This file is part of the LZO data compression library.

   Copyright (C) 1996-2005 Markus Franz Xaver Johannes Oberhumer
   All Rights Reserved.

   The LZO library is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License as
   published by the Free Software Foundation; either version 2 of
   the License, or (at your option) any later version.

   The LZO library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with the LZO library; see the file COPYING.
   If not, write to the Free Software Foundation, Inc.,
   59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

   Markus F.X.J. Oberhumer
   <markus@oberhumer.com>
   http://www.oberhumer.com/opensource/lzo/
 */


#include "lzo/lzoconf.h"

#if (LZO_CC_MSC && (_MSC_VER >= 1000 && _MSC_VER < 1200))
   /* avoid `-W4' warnings in system header files */
#  pragma warning(disable: 4201 4214 4514)
#endif
#if (LZO_CC_MSC && (_MSC_VER >= 1300))
   /* avoid `-Wall' warnings in system header files */
#  pragma warning(disable: 4163 4255 4820)
   /* avoid warnings about inlining */
#  pragma warning(disable: 4710 4711)
#endif
#if (LZO_CC_MSC && (_MSC_VER >= 1400))
   /* avoid warnings when using "deprecated" POSIX functions */
#  pragma warning(disable: 4996)
#endif
#if (LZO_CC_PELLESC && (__POCC__ >= 290))
#  pragma warn(disable:2002)
#endif


/*************************************************************************
//
**************************************************************************/

#if defined(__LZO_MMODEL_HUGE) || !(defined(LZO_LIBC_ISOC90) || defined(LZO_LIBC_ISOC99))

#include "examples/portab_a.h"

#else

/* INFO:
 *   The "portab_a.h" version above uses the ACC library to add
 *   support for ancient systems (like 16-bit DOS) and to provide
 *   some gimmicks like Windows high-resolution timers.
 *   Still, on any halfway modern machine you can also use the
 *   following pure ANSI-C code instead.
 */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#if defined(CLK_TCK) && !defined(CLOCKS_PER_SEC)
#  define CLOCKS_PER_SEC CLK_TCK
#endif

#if defined(WANT_LZO_MALLOC)
#  define lzo_malloc(a)         (malloc(a))
#  define lzo_free(a)           (free(a))
#endif
#if defined(WANT_LZO_FREAD)
#  define lzo_fread(f,b,s)      (fread(b,1,s,f))
#  define lzo_fwrite(f,b,s)     (fwrite(b,1,s,f))
#endif
#if defined(WANT_LZO_UCLOCK)
#  define lzo_uclock_handle_t   int
#  define lzo_uclock_t          double
#  define lzo_uclock_open(a)    ((void)(a))
#  define lzo_uclock_close(a)   ((void)(a))
#  define lzo_uclock_read(a,b)  *(b) = (clock() / (double)(CLOCKS_PER_SEC))
#  define lzo_uclock_get_elapsed(a,b,c) (*(c) - *(b))
#endif
#if defined(WANT_LZO_WILDARGV)
#  define lzo_wildargv(a,b)     ((void)0)
#endif

#endif


/*************************************************************************
// misc
**************************************************************************/

/* turn on assertions */
#undef NDEBUG
#include <assert.h>

/* just in case */
#undef xmalloc
#undef xfree
#undef xread
#undef xwrite
#undef xputc
#undef xgetc
#undef xread32
#undef xwrite32


/*
vi:ts=4:et
*/

