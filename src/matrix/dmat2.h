/**
 * dmat2.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 */

#ifndef DMAT2_H_
#define DMAT2_H_

#include <stdio.h>

#include "../vector/dvec2.h"

/**
 * A 2x2 matrix with double elements.
 */
typedef union cgm_dmat2 {
    /**
     * Row-major 2x2 2D double array representation of the matrix.
     */
    double m[2][2];

    /**
     * Row-major 1D double array representation of the matrix.
     */
    double arr[4];

    /**
     * 1D Array of row cgm_dvec2's of the matrix.
     */
    cgm_dvec2 vec[2];
} cgm_dmat2;

/**
 * Fills all elements of a cgm_dmat2 with a value.
 * @param m - Matrix to fill.
 * @param val - Value to fill with.
 */
void cgm_dmat2_fill(cgm_dmat2* m, double val);

/**
 * Sets a cgm_dmat2 to an identity matrix.
 * @param m - Matrix to set.
 */
void cgm_dmat2_set_identity(cgm_dmat2* m);

/**
 * Copies a matrix into another.
 * @param dest - Destination matrix.
 * @param src - Source matrix.
 * @return dest.
 */
cgm_dmat2* cgm_dmat2_cpy(cgm_dmat2* dest, const cgm_dmat2* src);

/**
 * Tests if two cgm_dmat2's are equal.
 * Two matrices are equal if all of their corresponding elements are equal.
 * @param a - First matrix.
 * @param b - Second matrix.
 * @return true (1) if a = b; false (0) otherwise.
 */
bool cgm_dmat2_equals(const cgm_dmat2* a, const cgm_dmat2* b);

/**
 * Adds two cgm_dmat2's element-wise.
 * @param a - Matrix to add to.
 * @param b - Matrix to add.
 */
void cgm_dmat2_add(cgm_dmat2* a, const cgm_dmat2* b);

/**
 * Subtracts two cgm_dmat2's element-wise.
 * @param a - Matrix to subtract from.
 * @param b - Matrix to subtract.
 */
void cgm_dmat2_sub(cgm_dmat2* a, const cgm_dmat2* b);

/**
 * Scales each element of a cgm_dmat2.
 * @param m - Matrix to scale.
 * @param val - Value to scale each element.
 */
void cgm_dmat2_scal(cgm_dmat2* m, double val);

/**
 * Multiplies two cgm_dmat2's.
 * @param out - Matrix to store result.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply on the right.
 */
void cgm_dmat2_mul(cgm_dmat2* out, const cgm_dmat2* a, const cgm_dmat2* b);

/**
 * Multiplies two cgm_dmat2's.
 * @param a - Matrix to multiple on the left and store the result.
 * @param b - Matrix to multiply on the right.
 */
void cgm_dmat2_mul_l(cgm_dmat2* a, const cgm_dmat2* b);

/**
 * Multiplies two cgm_dmat2's.
 * @param a - Matrix to multiply on the left.
 * @param b - Matrix to multiply on the right and store ths result.
 */
void cgm_dmat2_mul_r(const cgm_dmat2* a, cgm_dmat2* b);

/**
 * Multiplies a cgm_dvec2 by a cgm_dmat2.
 * @param m - Matrix to multiply by (on the left).
 * @param v - Vector to multiply (on the right).
 */
void cgm_dmat2_mul_v2(const cgm_dmat2* m, cgm_dvec2* v);

/**
 * Calculates the determinant of a cgm_dmat2.
 * @param m - Matrix to take the determinant of.
 * @return Determinant |m|; NaN if m is NULL.
 */
double cgm_dmat2_det(const cgm_dmat2* m);

/**
 * Transposes a cgm_dmat2.
 * @param m - Matrix to transpose.
 */
void cgm_dmat2_transpose(cgm_dmat2* m);

/**
 * Inverts a cgm_dmat2.
 * The (multiplicative) inverse of a matrix m is a matrix m' such that
 * m'*m = m*m' = I (identity matrix).
 * @param m - Matrix to invert.
 * @return true (1) if the matrix could be inverted; false (0) otherwise.
 */
int cgm_dmat2_invert(cgm_dmat2* m);

/**
 * Prints a cgm_dmat2 to a stream.
 * The matrix is printed as:
 *      m00 m01
 *      m10 m11
 * with each element printed with %g and separated by tabs and line breaks.
 * @param stream - Filestream to print to.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_dmat2_fprintf(FILE* stream, const cgm_dmat2* m);

/**
 * Prints a cgm_dmat2 to stdout.
 * The matrix is printed as in cgm_dmat2_fprintf
 * @param m - Matrix to print.
 * @return The number of characted printed.
 */
int cgm_dmat2_printf(const cgm_dmat2* m);

#endif /* DMAT2_H_ */

/* vim: set ft=c: */
