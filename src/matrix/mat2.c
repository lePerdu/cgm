/*
 * mat2.c
 *
 * Copyright (c) Zach Peltzer.
 * Subject to the MIT License.
 *
 * Inline function definitions for mat2.h.
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "../vector/vec2.h"
#include "mat2.h"

void cgm_mat2_fill(cgm_mat2* m, float val) {
    for (int i = 0; i < 4; i++) {
        m->arr[i] = val;
    }
}

void cgm_mat2_set_identity(cgm_mat2* m) {
    for (int i = 0; i < 4; i++) {
        if (i % (2 + 1) == 0) {
            m->arr[i] = 1;
        } else {
            m->arr[i] = 0;
        }
    }
}

cgm_mat2* cgm_mat2_cpy(cgm_mat2* dest, const cgm_mat2* src) {
    return memcpy(dest, src, sizeof(cgm_mat2));
}

bool cgm_mat2_equals(const cgm_mat2* a, const cgm_mat2* b) {
    for (int i = 0; i < 4; i++) {
        if (a->arr[i] != b->arr[i]) {
            return false;
        }
    }

    return true;
}

void cgm_mat2_add(cgm_mat2* a, const cgm_mat2* b) {
    for (int i = 0; i < 4; i++) {
        a->arr[i] += b->arr[i];
    }
}

void cgm_mat2_sub(cgm_mat2* a, const cgm_mat2* b) {
    for (int i = 0; i < 4; i++) {
        a->arr[i] -= b->arr[i];
    }
}

void cgm_mat2_scal(cgm_mat2* m, float val) {
    for (int i = 0; i < 4; i++) {
        m->arr[i] *= val;
    }
}

void cgm_mat2_mul(cgm_mat2* out, const cgm_mat2* a, const cgm_mat2* b) {
    cgm_mat2_fill(out, 0);
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            float tmp = b->m[i][k];
            for (int j = 0; j < 2; j++) {
                out->m[i][j] += tmp * a->m[k][j];
            }
        }
    }
}

void cgm_mat2_mul_l(cgm_mat2* a, const cgm_mat2* b) {
    cgm_mat2 out;
    cgm_mat2_mul(&out, a, b);
    cgm_mat2_cpy(a, &out);
}

void cgm_mat2_mul_r(const cgm_mat2* a, cgm_mat2* b) {
    cgm_mat2 out;
    cgm_mat2_mul(&out, a, b);
    cgm_mat2_cpy(b, &out);
}

void cgm_mat2_mul_v2(const cgm_mat2* m, cgm_vec2* v) {
    float x = v->x, y = v->y;
    v->x = m->m[0][0] * x + m->m[1][0] * y;
    v->y = m->m[0][1] * x + m->m[1][1] * y;
}

float cgm_mat2_det(const cgm_mat2* m) {
    return m->m[0][0] * m->m[1][1] - m->m[1][0] * m->m[0][1];
}

void cgm_mat2_transpose(cgm_mat2* m) {
    float tmp = m->m[0][1];
    m->m[0][1] = m->m[1][0];
    m->m[1][0] = tmp;
}

int cgm_mat2_invert(cgm_mat2* m) {
    float det = cgm_mat2_det(m);
    if (det == 0) {
        return false;
    }
    
    float tmp = m->m[0][0];
    m->m[0][0] = m->m[1][1] / det;
    m->m[1][1] = tmp / det;
    m->m[0][1] *= -1 / det;
    m->m[1][0] *= -1 / det;

    return true;
}

int cgm_mat2_fprintf(FILE* stream, const cgm_mat2* m) {
    return fprintf(stream, "%g\t%g\n%g\t%g\n", m->arr[0], m->arr[1], m->arr[2], m->arr[3]);
}

int cgm_mat2_printf(const cgm_mat2* m) {
    return cgm_mat2_fprintf(stdout, m);
}

/* vim: set ft=c: */
