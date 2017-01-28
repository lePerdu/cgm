/**
 * mat4.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#ifndef MAT4_H_
#define MAT4_H_

#include <stdio.h>

#include "mat3.h"
#include "../vector/vec3.h"
#include "../vector/vec4.h"
#include "../quaternion/quaternion.h"

/**
 * A 4x4 matrix with float elements.
 */
typedef union cgm_mat4 {
    /**
     * Row-major 4x4 2D float array representation of the matrix.
     */
    float m[4][4];

    /**
     * Row-major 1D float array representation of the matrix.
     */
    float arr[16];

    /**
     * 1D Array of row cgm_vec4's of the matrix.
     */
    cgm_vec4 vec[4];
} cgm_mat4;

/**
 * Fills all elements of a cgm_mat4 with a value.
 * @param m - Matrix to fill.
 * @param val - Value to fill with.
 */
void cgm_mat4_fill(cgm_mat4* m, float val);

/**
 * Sets the upper left of a cgm_mat4 with a cgm_mat3 and the rest of it
 * as in an identity matrix.
 * @param m - Matrix to set.
 * @param m3 - Matrix from which to set.
 */
void cgm_mat4_set_m3(cgm_mat4* m, const cgm_mat3* m3);

/**
 * Sets a cgm_mat4 to represent the same rotation as a cgm_quat.
 * @param m - Matrix to set.
 * @param q - Quaternion from which to set.
 */
void cgm_mat4_set_quat(cgm_mat4* m, const cgm_quat* q);

/**
 * Sets a cgm_mat4 to an identity matrix.
 * @param m - Matrix to set.
 */
void cgm_mat4_set_identity(cgm_mat4* m);

/**
 * Copies a matrix into another.
 * @param dest - Destination matrix.
 * @param src - Source matrix.
 * @return dest.
 */
cgm_mat4* cgm_mat4_cpy(cgm_mat4* dest, const cgm_mat4* src);

/**
 * Tests if two cgm_mat4's are equal.
 * Two matrices are equal if all of their corresponding elements are equal.
 * @param a - First matrix.
 * @param b - Second matrix.
 * @return true (1) if a = b; false (0) otherwise.
 */
bool cgm_mat4_equals(const cgm_mat4* a, const cgm_mat4* b);

/**
 * Adds two cgm_mat4's element-wise.
 * @param a - Matrix to add to.
 * @param b - Matrix to add.
 */
void cgm_mat4_add(cgm_mat4* a, const cgm_mat4* b);

/**
 * Subtracts two cgm_mat4's element-wise.
 * @param a - Matrix to subtract from.
 * @param b - Matrix to subtract.
 */
void cgm_mat4_sub(cgm_mat4* a, const cgm_mat4* b);

/**
 * Scales each element of a matrix.
 * @param m - Matrix to scale.
 * @param val - Value to scale each element.
 */
void cgm_mat4_scal(cgm_mat4* m, float val);

/**
 * Multiples two cgm_mat4's.
 * @param out - Matrix to store the result.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply on the right.
 */
void cgm_mat4_mul(cgm_mat4* out, const cgm_mat4* a, const cgm_mat4* b);

/**
 * Multiplies two cgm_mat4's.
 * @param a - Matrix to multiply on the left and store the result.
 * @param b - Matrix to multiply on the right.
 */
void cgm_mat4_mul_l(cgm_mat4* a, const cgm_mat4* b);

/**
 * Multiplies two cgm_mat4's.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply on the right and store the result.
 */
void cgm_mat4_mul_r(const cgm_mat4* a, cgm_mat4* b);

/**
 * Multiples a cgm_vec3 by a cgm_mat4 by assigning a w component of 1.
 * @param m - Matrix to multiply by (on the left).
 * @param v - Vector to multiply (on the right).
 */
void cgm_mat4_mul_v3(const cgm_mat4* m, cgm_vec3* v);

/**
 * Multiplies a cgm_vec4 by a cgm_mat4.
 * @param m - Matrix to multiply by (on the left).
 * @param v - Vector to multiply (on the right).
 */
void cgm_mat4_mul_v4(const cgm_mat4* m, cgm_vec4* v);

/**
 * Applies the rotation from a cgm_quat to a cgm_mat4.
 * @param m - Matrix to rotate.
 * @param q - Quaternion by which to rotate by.
 */
void cgm_mat4_mul_quat(cgm_mat4* m, const cgm_quat* q);

/**
 * Calculates the determinant of a cgm_mat4.
 * @param m - Matrix to take the determinant of.
 * @return Determinant |m|.
 */
float cgm_mat4_det(const cgm_mat4* m);

/**
 * Transposes a cgm_mat4.
 * @param m - Matrix to transpose.
 */
void cgm_mat4_transpose(cgm_mat4* m);

/**
 * Inverts a cgm_mat4.
 * The (multiplicative) inverse of a matrix m is m' such that
 * m * m' = m' * m = I (identity matrix).
 * @param m - Matrix to invert.
 * @return true (1) if the matrix could be inverted; false (0) otherwise.
 */
int cgm_mat4_invert(cgm_mat4* m);

/**
 * Prints a cgm_mat4 to a stream.
 * The matrix is printed as:
 *      m00 m01 m02 m03
 *      m10 m11 m12 m13
 *      m20 m21 m22 m23
 *      m30 m31 m32 m33
 * with each element printed with %g and separated by tabs and line breaks.
 * @param stream - Filestream to print to.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_mat4_fprintf(FILE* stream, const cgm_mat4* m);

/**
 * Prints a cmg_mat4 to stdout.
 * the matrix is printed as in cgm_mat4_fprintf().
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_mat4_printf(const cgm_mat4* m);

#endif /* MAT4_H_ */

/* vim: set ft=c: */
