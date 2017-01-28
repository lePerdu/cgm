/**
 * transform.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 * Function prototypes for creating transformation matrices.
 */

#ifndef TRANSFORM_H_
#define TRANSFORM_H_

#include "vector/vec3.h"
#include "matrix/mat4.h"

/**
 * Sets a matrix to an orthographic projection matrix
 * @param m - Matrix to set.
 * @param left - Left coordinate of the clipping pane.
 * @param right - Right coordinate of the clipping pane.
 * @param bottom - Bottom coordinate of the clipping pane.
 * @param top - Top coordinate of the clipping pane.
 * @param near - Near coordinate of the depth clipping pane.
 * @param far - Far coordinate of the depth clipping pane.
 */
void cgm_set_ortho(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far);

/**
 * Multiplies a matrix by an orthographic (2D) projection matrix.
 * @param m - Matrix to multiply.
 * @param left - Left coordinate of the clipping pane.
 * @param right - Right coordinate of the clipping pane.
 * @param bottom - Bottom coordinate of the clipping pane.
 * @param top - Top coordinate of the clipping pane.
 * @param near - Near coordinate of the depth clipping pane.
 * @param far - Far coordinate of the depth clipping pane.
 */
void cgm_ortho(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far);

/**
 * Sets a matrix to a frustum projection matrix
 * @param m - Matrix to set.
 * @param left - Left coordinate of the clipping pane.
 * @param right - Right coordinate of the clipping pane.
 * @param bottom - Bottom coordinate of the clipping pane.
 * @param top - Top coordinate of the clipping pane.
 * @param near - Near coordinate of the depth clipping pane.
 * @param far - Far coordinate of the depth clipping pane.
 */
void cgm_set_frustum(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far);

/**
 * Multiplies a matrix by a frustum projection matrix.
 * @param m - Matrix to multiply.
 * @param left - Left coordinate of the clipping pane.
 * @param right - Right coordinate of the clipping pane.
 * @param bottom - Bottom coordinate of the clipping pane.
 * @param top - Top coordinate of the clipping pane.
 * @param near - Near coordinate of the depth clipping pane.
 * @param far - Far coordinate of the depth clipping pane.
 */
void cgm_frustum(
        cgm_mat4* m,
        float left, float right,
        float bottom, float top,
        float near, float far);

/**
 * Sets a matrix to a perspective projection matrix.
 * @param m - Matrix to multiply.
 * @param fov_y - The Field of View in the y (vertical) direction.
 *                Measured in radians
 * @param aspect_ratio - The aspect ratio of the clipping pane.
 * @param near - Near coordinate of the depth clipping pane.
 * @param far - Far coordinate of the depth clipping pane.
 */
void cgm_set_perspective(
        cgm_mat4* m,
        float fov_y, float aspect_ratio,
        float near, float far);

/**
 * Multiplies a matrix by a perspective projection matrix.
 * @param m - Matrix to multiply.
 * @param fov_y - The Field of View in the y (vertical) direction.
 *                Measured in radians
 * @param aspect_ratio - The aspect ratio of the clipping pane.
 * @param near - Near coordinate of the depth clipping pane.
 * @param far - Far coordinate of the depth clipping pane.
 */
void cgm_perspective(
        cgm_mat4* m,
        float fov_y, float aspect_ratio,
        float near, float far);

/**
 * Sets a matrix to a look at view matrix.
 * @param m - Matrix to set.
 * @param eye - Position of the eye.
 * @param center - Position of the reference point.
 * @param up - Upward direction.
 */
void cgm_set_lookat(
        cgm_mat4* m,
        const cgm_vec3* eye,
        const cgm_vec3* center,
        const cgm_vec3* up);

/**
 * Multiplies a matrix by a look at view matrix.
 * @param m - Matrix to multiply.
 * @param eye - Position of the eye.
 * @param center - Position of the reference point.
 * @param up - Upward direction.
 */
void cgm_lookat(
        cgm_mat4* m,
        const cgm_vec3* eye,
        const cgm_vec3* center,
        const cgm_vec3* up);

/**
 * Sets a matrix to a translation matrix.
 * @param m - Matrix to set.
 * @param x - Translation in x.
 * @param y - Tranlation in y.
 * @param z - Trasnlation in z.
 */
void cgm_set_translate(cgm_mat4* m, float x, float y, float z);

/**
 * Multiplies a matrix by a translation matrix.
 * @param m - Matrix to translate.
 * @param x - Translation in x.
 * @param y - Tranlation in y.
 * @param z - Trasnlation in z.
 */
void cgm_translate(cgm_mat4* m, float x, float y, float z);

/**
 * Sets a matrix to a scaling matrix.
 * @param m - Matrix to set.
 * @param x - Scale in x.
 * @param y - Scale in y.
 * @param z - Scale in z.
 */
void cgm_set_scale(cgm_mat4* m, float x, float y, float z);

/**
 * Multiplies a matrix by a scaling matrix.
 * @param m - Matrix to scale.
 * @param x - Scale in x.
 * @param y - Scale in y.
 * @param z - Scale in z.
 */
void cgm_scale(cgm_mat4* m, float x, float y, float z);

/**
 * Sets a matrix to a rotation matrix around the x-axis.
 * @param m - Matrix to set.
 * @param angle - Angle to rotate in radians.
 */
void cgm_set_rotate_x(cgm_mat4* m, float angle);

/**
 * Multiplies a matrix by a rotation matrix around the x-axis
 * @param m - Matrix to rotate.
 * @param angle - angle to rotate in radians.
 */
void cgm_rotate_x(cgm_mat4* m, float angle);

/**
 * Sets a matrix to a rotation matrix around the y-axis.
 * @param m - Matrix to set.
 * @param angle - Angle to rotate in radians.
 */
void cgm_set_rotate_y(cgm_mat4* m, float theat);

/**
 * Multiplies a matrix by a rotation matrix around the y-axis
 * @param m - Matrix to rotate.
 * @param angle - angle to rotate in radians.
 */
void cgm_rotate_y(cgm_mat4* m, float angle);

/**
 * Sets a matrix to a rotation matrix around the z-axis.
 * @param m - Matrix to set.
 * @param angle - Angle to rotate in radians.
 */
void cgm_set_rotate_z(cgm_mat4* m, float angle);

/**
 * Multiplies a matrix by a rotation matrix around the z-axis
 * @param m - Matrix to rotate.
 * @param angle - angle to rotate in radians.
 */
void cgm_rotate_z(cgm_mat4* m, float angle);

/**
 * Sets a matrix to a rotation matrix
 * @param m - Matrix to set.
 * @param axis - Axis to rotate around.
 * @param angle - Angle to rotate (counter-clockwise) in radians.
 */
void cgm_set_rotate(cgm_mat4* m, const cgm_vec3* axis, float angle);

/**
 * Multiplies a matrix by a rotation matrix.
 * @param m - Matrix to multiply.
 * @param axis - Axis to rotate around.
 * @param angle - Angle to rotate (counter-clockwise) in radians.
 */
void cgm_rotate(cgm_mat4* m, const cgm_vec3* axis, float angle);

#endif /* TRANSFORM_H_ */

/* vim: set ft=c: */
