/*
 * Complex signal processing vectors
 *
 * Copyright (C) 2012 Thomas Tsou <tom@tsou.cc>
 *
 * All Rights Reserved
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "sigvec.h"

void mul_cx_neon4(float *a, float *b, float *out, int len);

/*! \brief Complex multiply the contents of two complex vectors
 *  \param[in] a Input complex vector 'A'
 *  \param[in] b Input complex vector 'B'
 *  \param[out] out Output complex vector
 */
int cxvec_mul4(struct cxvec *a, struct cxvec *b, struct cxvec *out)
{
	int len;

	if ((a->len != b->len) || (b->len != out->len)) {
		fprintf(stderr, "cxvec_mul4: invalid input\n");
		return -1;
	}

	len = a->len >> 2;

	mul_cx_neon4((float *) a->data,
		     (float *) b->data,
		     (float *) out->data, len);

	return a->len;
}
