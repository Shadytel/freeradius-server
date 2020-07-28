#pragma once
/*
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
 */

/** A generic buffer structure for string printing and parsing strings
 *
 * Because doing manual length checks is error prone and a waste of everyones time.
 *
 * @file src/lib/util/sbuff.h
 *
 * @copyright 2020 Arran Cudbard-Bell <a.cudbardb@freeradius.org>
 */
RCSIDH(hex_h, "$Id$")

#  ifdef __cplusplus
extern "C" {
#  endif
#include <sys/types.h>
#include <freeradius-devel/util/sbuff.h>
#include <freeradius-devel/util/dbuff.h>

ssize_t		fr_hex2bin(fr_dbuff_t *out, fr_sbuff_t *in);

ssize_t		fr_bin2hex(fr_sbuff_t *out, fr_dbuff_t *in);

char		*fr_abin2hex(TALLOC_CTX *ctx, uint8_t const *bin, size_t inlen);

#ifdef __cplusplus
}
#endif
