/**
 * project.c
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 *
 * Inline funciton definitions for project.h.
 */

#include "vector/vec3.h"
#include "matrix/mat4.h"
#include "project.h"

void cgm_project(
        const cgm_vec3* vertex,
        const cgm_mat4* model,
        const cgm_mat4* projection,
        const int view[4],
        cgm_vec3* window) {
    cgm_vec4 out;
    cgm_vec4_set_v3(&out, vertex, 1);
    cgm_mat4_mul_v4(model, &out);
    cgm_mat4_mul_v4(projection, &out);

    if (out.w == 0) {
        return;
    }

    cgm_vec3_cpy(window, &out.xyz);
    window->x = ((window->x + 1) / 2 * view[2] + view[0]) / out.w;
    window->y = ((window->y + 1) / 2 * view[3] + view[1]) / out.w;
    window->z = ((window->z + 1) / 2) / out.w;
}

void cgm_unproject(
        cgm_vec3* vertex,
        const cgm_mat4* model,
        const cgm_mat4* projection,
        const int view[4],
        const cgm_vec3* window) {
    cgm_mat4 tmp;
    cgm_mat4_mul(&tmp, projection, model);
    if (!cgm_mat4_invert(&tmp)) {
        return;
    }

    cgm_vec4 out;
    out.x = (window->x - view[0]) / view[2] * 2 - 1;
    out.y = (window->y - view[1]) / view[3] * 2 - 1;
    out.z = window->z * 2 - 1;
    out.w = 1;
    cgm_mat4_mul_v4(&tmp, &out);
    if (out.w == 0) {
        return;
    }

    cgm_vec3_cpy(vertex, &out.xyz);
    cgm_vec3_scal(vertex, 1 / out.w);
}

/* vim: set ft=c: */
