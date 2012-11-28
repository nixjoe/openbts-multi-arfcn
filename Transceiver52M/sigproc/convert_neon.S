/*
 * Copyright (C) 2012 Thomas Tsou <tom@tsou.cc>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 * See the COPYING file in the main directory for details.
 */

	.syntax unified
	.arch armv7-a
	.fpu neon
	.text
	.align 2
	.global convert_flt32_int16
	.type convert_flt32_int16, %function
convert_flt32_int16:
	push             {r2, lr}
.loop_fltint:
	vld1.64       {d0-d1}, [r1]!
	vcvt.s32.f32       q2, q0
	vqmovn.s32         d0, q2
	vst1.64          {d0}, [r0]!
	subs               r2, #4
	bne          .loop_fltint
	pop              {r2, pc}
	.size convert_flt32_int16, .-convert_flt32_int16
	.text
	.align 2
	.global convert_int16_flt32
	.type convert_int16_flt32, %function
convert_int16_flt32:
	push             {r2, lr}
.loop_intflt:
	vld1.64          {d0}, [r1]!
	vmovl.s16          q1, d0
	vcvt.f32.s32       q0, q1
	vst1.64          {d0}, [r0]!
	vst1.64          {d1}, [r0]!
	subs               r2, #4
	bne          .loop_intflt
	pop             {r2, pc}
	.size convert_int16_flt32, .-convert_int16_flt32
	.section .note.GNU-stack,"",%progbits
