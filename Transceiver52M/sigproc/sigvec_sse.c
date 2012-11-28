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

#include <stdio.h>
#include "sigvec.h"

int cxvec_mul4(struct cxvec *a, struct cxvec *b, struct cxvec *out)
{
	fprintf(stderr, "cxvec_mul4: not supported on this architecture\n");
	return -1;
}

int cxvec_mac4(float complex *a, float complex *b, float complex *out, int len)
{
	fprintf(stderr, "cxvec_mac4: not supported on this architecture\n");
	return -1;
}

int cxvec_mac(float complex *a, float complex *b, float complex *out, int len)
{
	fprintf(stderr, "cxvec_mac: not supported on this architecture\n");
	return -1;
}
