/* { dg-do compile } */
/* { dg-options "-march=rv64gcv -mabi=lp64d -O3 -ftree-vectorize -fdump-rtl-expand-details -fno-schedule-insns -fno-schedule-insns2" } */
/* { dg-skip-if "" { *-*-* } { "-flto" } } */
/* { dg-final { check-function-bodies "**" "" } } */

#include "../vec_sat_arith.h"

/*
** vec_sat_u_add_uint8_t_fmt_4:
** ...
** vsetvli\s+[atx][0-9]+,\s*[atx][0-9]+,\s*e8,\s*m1,\s*ta,\s*ma
** vle8\.v\s+v[0-9]+,\s*0\([atx][0-9]+\)
** vle8\.v\s+v[0-9]+,\s*0\([atx][0-9]+\)
** vsaddu\.vv\s+v[0-9]+,\s*v[0-9]+,\s*v[0-9]+
** ...
*/
DEF_VEC_SAT_U_ADD_FMT_4(uint8_t)

/* { dg-final { scan-rtl-dump-times ".SAT_ADD " 4 "expand" } } */
