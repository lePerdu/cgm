/*
 * dmat2.c
 *
 * Copyright (c) Zach Peltzer.
 * Subject to the MIT License.
 *
 * Inline function definitions for dmat2.h.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../vector/dvec2.h"
#include "dmat2.h"

void cgm_dmat2_fill(cgm_dmat2* m, double val) {
    for (int i = 0; i < 4; i++) {
        m->arr[i] = val;
    }
}

void cgm_dmat2_set_identity(cgm_dmat2* m) {
    for (int i = 0; i < 4; i++) {
        if (i % (2 + 1) == 0) {
            m->arr[i] = 1;
        } else {
            m->arr[i] = 0;
        }
    }
}

cgm_dmat2* cgm_dmat2_cpy(cgm_dmat2* dest, const cgm_dmat2* src) {
    return memcpy(dest, src, sizeof(cgm_dmat2));
}

bool cgm_dmat2_equals(const cgm_dmat2* a, const cgm_dmat2* b) {
    for (int i = 0; i < 4; i++) {
        if (a->arr[i] != b->arr[i]) {
            return false;
        }
    }

    return true;
}

void cgm_dmat2_add(cgm_dmat2* a, const cgm_dmat2* b) {
    for (int i = 0; i < 4; i++) {
        a->arr[i] += b->arr[i];
    }
}

void cgm_dmat2_sub(cgm_dmat2* a, const cgm_dmat2* b) {
    for (int i = 0; i < 4; i++) {
        a->arr[i] -= b->arr[i];
    }
}

void cgm_dmat2_scal(cgm_dmat2* m, double val) {
    for (int i = 0; i < 4; i++) {
        m->arr[i] *= val;
    }
}

void cgm_dmat2_mul(cgm_dmat2* out, const cgm_dmat2* a, const cgm_dmat2* b) {
    cgm_dmat2_fill(out, 0);
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            double tmp = b->m[i][k];
            for (int j = 0; j < 2; j++) {
                out->m[i][j] += tmp * a->m[k][j];
            }
        }
    }
}

void cgm_dmat2_mul_l(cgm_dmat2* a, const cgm_dmat2* b) {
    cgm_dmat2 out;
    cgm_dmat2_mul(&out, a, b);
    cgm_dmat2_cpy(a, &out);
}

void cgm_dmat2_mul_r(const cgm_dmat2* a, cgm_dmat2* b) {
    cgm_dmat2 out;
    cgm_dmat2_mul(&out, a, b);
    cgm_dmat2_cpy(b, &out);
}

void cgm_dmat2_mul_v2(const cgm_dmat2* m, cgm_dvec2* v) {
    double x = v->x, y = v->y;
    v->x = m->m[0][0] * x + m->m[1][0] * y;
    v->y = m->m[0][1] * x + m->m[1][1] * y;
}

double cgm_dmat2_det(const cgm_dmat2* m) {
    return m->m[0][0] * m->m[1][1] - m->m[1][0] * m->m[0][1];
}

void cgm_dmat2_transpose(cgm_dmat2* m) {
    double tmp = m->m[0][1];
    m->m[0][1] = m->m[1][0];
    m->m[1][0] = tmp;
}

int cgm_dmat2_invert(cgm_dmat2* m) {
    double det = cgm_dmat2_det(m);
    if (det == 0) {
        return false;
    }
    
    double tmp = m->m[0][0];
    m->m[0][0] = m->m[1][1] / det;
    m->m[1][1] = tmp / det;
    m->m[0][1] *= -1 / det;
    m->m[1][0] *= -1 / det;

    return true;
}

int cgm_dmat2_fprintf(FILE* stream, const cgm_dmat2* m) {
    return fprintf(stream, "%g\t%g\n%g\t%g\n", m->arr[0], m->arr[1], m->arr[2], m->arr[3]);
}

int cgm_dmat2_printf(const cgm_dmat2* m) {
    return cgm_dmat2_fprintf(stdout, m);
}

/* vim: set ft=c: */
