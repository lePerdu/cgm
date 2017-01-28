/**
 * project.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 *
 * Function prototypes for converting to and from model and screen
 * coordinates.
 */

#ifndef PROJECT_H_
#define PROJECT_H_

#include "vector/vec3.h"
#include "matrix/mat4.h"

/**
 * Projects a vertex in model space to the vertex in window/screen coordinates.
 * @param vertex - Vertex in model space.
 * @param model - Model-View matrix.
 * @param projection - Projection matrix.
 * @param window - Vector to store the window coordinates.
 */
void cgm_project(
        const cgm_vec3* vertex,
        const cgm_mat4* model,
        const cgm_mat4* projection,
        const int* view,
        cgm_vec3* window);

/**
 * Projects a vertex in window/screen coordinates to model space coordinates.
 * @param vertex - Vector to store model coordinates.
 * @param model - Model-View matrix.
 * @param projection - Projection matrix.
 * @param window - Vertex in window coordinates.
 */
void cgm_unproject(
        cgm_vec3* vertex,
        const cgm_mat4* model,
        const cgm_mat4* projection,
        const int* view,
        const cgm_vec3* window);

#endif /* PROJECT_H_ */

/* vim: set ft=c: */
