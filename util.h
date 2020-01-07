/* 
 * General helper functions and defines
 *
 * ------------------------------------------------
 *
 * Copyright (C) 2020 Paul Kurucz
 * 
 * License info: See the LICENSE file at the repo top level
 *
 * THIS SOFTWARE IS PROVIDED IN AN "AS IS" CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 */

#include <stdbool.h>
#include <stdint.h>

#ifndef _UTIL_H
#define _UTIL_H

/* ----------------------------------------------------- */

#ifndef MIN
#define MIN(_A, _B) ( ((_A) < (_B)) ? (_A) : (_B) )
#endif

#ifndef MAX
#define MAX(_A, _B) ( ((_A) > (_B)) ? (_A) : (_B) )
#endif

#ifndef NUMEL
#define NUMEL(_X) ( sizeof((_X)) / sizeof((_X)[0]) )
#endif

/* ----------------------------------------------------- */

#endif /* _UTIL_H */

