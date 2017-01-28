/**
 * mat3.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#ifndef MAT3_H_
#define MAT3_H_

#include <math.h>
#include <stdio.h>

#include "../vector/vec3.h"

/**
 * A 3x3 matrix with float elements.
 */
typedef union cgm_mat3 {
    /**
     * Row-major 3x3 2D float array representation of the matrix.
     */
    float m[3][3];

    /**
     * Row-major 1D float array representation of the matrix.
     */
    float arr[9];

    /**
     * 1D Array of row cgm_vec3's of the matrix.
     */
    cgm_vec3 vec[3];
} cgm_mat3;

/**
 * Fills all elements of a cgm_mat3 with a value.
 * @param m - Matrix to fill.
 * @param val - Value to fill with.
 */
void cgm_mat3_fill(cgm_mat3* m, float val);

/**
 * Sets a cgm_mat3 to an identity matrix.
 * @param m - Matrix to set.
 */
void cgm_mat3_set_identity(cgm_mat3* m);

/**
 * Copies a matrix into another.
 * @param dest - Destination matrix.
 * @param src - Source matrix.
 * @return dest.
 */
cgm_mat3* cgm_mat3_cpy(cgm_mat3* dest, const cgm_mat3* src);

/**
 * Tests if two cgm_mat3's are equal.
 * Two matrices are equal if all of their corresponding elements are equal.
 * @param a - First matrix.
 * @param b - Second matrix.
 * @return true (1) if a = b; false (0) otherwise.
 */
bool cgm_mat3_equals(const cgm_mat3* a, const cgm_mat3* b);

/**
 * Adds two cgm_mat3's element-wise.
 * @param a - Matrix to add to.
 * @param b - Matrix to add.
 */
void cgm_mat3_add(cgm_mat3* a, const cgm_mat3* b);

/**
 * Subtracts two cgm_mat3's element-wise.
 * @param a - Matrix to subtract from.
 * @param b - Matrix to subtract.
 */
void cgm_mat3_sub(cgm_mat3* a, const cgm_mat3* b);

/**
 * Scales each element of a cgm_mat3.
 * @param m - Matrix to scale.
 * @param val - Values to scale each element.
 */
void cgm_mat3_scal(cgm_mat3* m, float val);

/**
 * Multiplies two cgm_mat3's.
 * @param out - Matrix to store the result.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply by on the right.
 */
void cgm_mat3_mul(cgm_mat3* out, const cgm_mat3* a, const cgm_mat3* b);

/**
 * Multiplies two cgm_mat3's.
 * @param a - Matrix to multiply on the left and store the result.
 * @param b - Matrix to multiply on the right.
 */
void cgm_mat3_mul_l(cgm_mat3* a, const cgm_mat3* b);

/**
 * Multiplies two cgm_mat3's.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply on the right and store the result.
 */
void cgm_mat3_mul_r(const cgm_mat3* a, cgm_mat3* b);

/**
 * Multiplies a cgm_vec3 by a cgm_mat3.
 * @param m - Matrix to multiply by (on the left).
 * @param v - Vector to multiply (on the right).
 */
void cgm_mat3_mul_v3(const cgm_mat3* m, cgm_vec3* v);

/**
 * Calculates the determinant of a cgm_mat3.
 * @param m - Matrix to take the determinant of.
 * @return Determinant |m|; NaN if m is NULL.
 */
float cgm_mat3_det(const cgm_mat3* m);

/**
 * Transposes a cgm_mat3.
 * @param m - Matrix to transpose.
 */
void cgm_mat3_transpose(cgm_mat3* m);

/**
 * Inverts a cgm_mat3.
 * The (multiplicative) inverse of a matrix m is another matrix m' such that
 * m * m' = m' * m = I (identity matrix).
 * @param m - Matrix to invert.
 * @return true (1) if the matrix could be inverted; false (0) otherwise.
 */
int cgm_mat3_invert(cgm_mat3* m);

/**
 * Prints a cgm_mat3 to a stream.
 * The matrix is printed as:
 *      m00 m01 m02
 *      m10 m11 m12
 *      m20 m21 m22
 * with each element printed with %g and separated by tabs and line breaks.
 * @param stream - Filestream to print to.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_mat3_fprintf(FILE* stream, const cgm_mat3* m);

/**
 * Prints a cmg_mat3 to stdout.
 * the matrix is printed as in cgm_mat3_fprintf().
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_mat3_printf(const cgm_mat3* m);

#endif /* MAT3_H_ */

/* vim: set ft=c: */
