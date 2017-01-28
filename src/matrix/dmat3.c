/**
 * dmat3.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../vector/dvec3.h"
#include "dmat3.h"

void cgm_dmat3_fill(cgm_dmat3* m, double val) {
    for (int i = 0; i < 9; i++) {
        m->arr[i] = val;
    }
}

void cgm_dmat3_set_identity(cgm_dmat3* m) {
    for (int i = 0; i < 9; i++) {
        if (i % (3 + 1) == 0) {
            m->arr[i] = 1;
        } else {
            m->arr[i] = 0;
        }
    }
}

cgm_dmat3* cgm_dmat3_cpy(cgm_dmat3* dest, const cgm_dmat3* src) {
    return memcpy(dest, src, sizeof(cgm_dmat3));
}

bool cgm_dmat3_equals(const cgm_dmat3* a, const cgm_dmat3* b) {
    for (int i = 0; i < 9; i++) {
        if (a->arr[i] != b->arr[i]) {
            return false;
        }
    }

    return true;
}

void cgm_dmat3_add(cgm_dmat3* a, const cgm_dmat3* b) {
    for (int i = 0; i < 9; i++) {
        a->arr[i] += b->arr[i];
    }
}

void cgm_dmat3_sub(cgm_dmat3* a, const cgm_dmat3* b) {
    for (int i = 0; i < 9; i++) {
        a->arr[i] -= b->arr[i];
    }
}

void cgm_dmat3_scal(cgm_dmat3* m, double val) {
    for (int i = 0; i < 9; i++) {
        m->arr[i] *= val;
    }
}

void cgm_dmat3_mul(cgm_dmat3* out, const cgm_dmat3* a, const cgm_dmat3* b) {
    cgm_dmat3_fill(out, 0);
    for (int i = 0; i < 3; i++) {
        for (int k = 0; k < 3; k++) {
            double tmp = b->m[i][k];
            for (int j = 0; j < 3; j++) {
                out->m[i][j] += tmp * a->m[k][j];
            }
        }
    }
}

void cgm_dmat3_mul_l(cgm_dmat3* a, const cgm_dmat3* b) {
    cgm_dmat3 out;
    cgm_dmat3_mul(&out, a, b);
    cgm_dmat3_cpy(a, &out);
}

void cgm_dmat3_mul_r(const cgm_dmat3* a, cgm_dmat3* b) {
    cgm_dmat3 out;
    cgm_dmat3_mul(&out, a, b);
    cgm_dmat3_cpy(b, &out);
}

void cgm_dmat3_mul_v3(const cgm_dmat3* m, cgm_dvec3* v) {
    double x = v->x, y = v->y, z = v->z;
    v->x = m->m[0][0] * x + m->m[1][0] * y + m->m[2][0] * z;
    v->y = m->m[0][1] * x + m->m[1][1] * y + m->m[2][1] * z;
    v->z = m->m[0][2] * x + m->m[1][2] * y + m->m[2][2] * z;
}

double cgm_dmat3_det(const cgm_dmat3* m) {
    return + m->m[0][0] * (m->m[1][1] * m->m[2][2] - m->m[2][1] * m->m[1][2])
           - m->m[0][1] * (m->m[1][0] * m->m[2][2] - m->m[2][0] * m->m[1][2])
           + m->m[0][2] * (m->m[1][0] * m->m[2][1] - m->m[2][0] * m->m[1][1]);
}

void cgm_dmat3_transpose(cgm_dmat3* m) {
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 3; j++) {
            double tmp = m->m[i][j];
            m->m[i][j] = m->m[j][i];
            m->m[j][i] = tmp;
        }
    }
}

int cgm_dmat3_invert(cgm_dmat3* m) {
    cgm_dmat3 inv;
    inv.m[0][0] = + (m->m[1][1] * m->m[2][2] - m->m[2][1] * m->m[1][2]);
    inv.m[0][1] = - (m->m[0][1] * m->m[2][2] - m->m[2][1] * m->m[0][2]);
    inv.m[0][2] = + (m->m[0][1] * m->m[1][2] - m->m[1][1] * m->m[0][2]);

    double det = inv.m[0][0] + inv.m[0][1] + inv.m[0][2];
    if (det == 0) {
        return false;
    }

    inv.m[1][0] = - (m->m[1][0] * m->m[2][2] - m->m[2][0] * m->m[1][2]);
    inv.m[1][1] = + (m->m[0][0] * m->m[2][2] - m->m[2][0] * m->m[0][2]);
    inv.m[1][2] = - (m->m[0][0] * m->m[1][2] - m->m[1][0] * m->m[0][2]);

    inv.m[2][0] = + (m->m[1][0] * m->m[2][1] - m->m[2][0] * m->m[1][1]);
    inv.m[2][1] = - (m->m[0][0] * m->m[2][1] - m->m[2][0] * m->m[0][1]);
    inv.m[2][2] = + (m->m[0][0] * m->m[1][1] - m->m[1][0] * m->m[0][1]);
    
    cgm_dmat3_scal(&inv, 1 / det);
    cgm_dmat3_cpy(m, &inv);

    return true;
}

int cgm_dmat3_fprintf(FILE* stream, const cgm_dmat3* m) {
    int len = 0;
    for (int i = 0; i < 3; i++) {
        len += fprintf(stream, "%g\t%g\t%g\n", m->m[i][0], m->m[i][1], m->m[i][2]);
    }

    return len;
}

int cgm_dmat3_printf(const cgm_dmat3* m) {
    return cgm_dmat3_fprintf(stdout, m);
}

/* vim: set ft=c: */
