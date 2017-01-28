/**
 * dvec2.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef DVEC2_H_
#define DVEC2_H_

#include <stdbool.h>
#include <stdio.h>

/**
 * A 2-dimensional vector with double components.
 */
typedef union cgm_dvec2 {
    /**
     * Double component representation of the vector.
     */
    struct {
        double x, y;
    };

    /**
     * Double texture coordinate representaion of the vector.
     */
    struct {
        double s, t;
    };

    /**
     * Double array representation of the vector.
     */
    double v[2];
} cgm_dvec2;

/**
 * Returns a pointer to a compound literal cgm_dvec2.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_dvec2, cgm_dvec2_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @return Constant pointer to cgm_dvec2.
 */
#define CGM_DVEC2(X, Y)  ((const cgm_dvec2*) &((cgm_dvec2) {{(X), (Y)}}))

/**
 * Sets the components of a cgm_dvec2.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 */
void cgm_dvec2_set(cgm_dvec2* v, double x, double y);

/**
 * Fills both components of a cgm_dvec2 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_dvec2_fill(cgm_dvec2* v, double val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Source vector.
 * @return dest.
 */
cgm_dvec2* cgm_dvec2_cpy(cgm_dvec2* dest, const cgm_dvec2* src);

/**
 * Tests if two cgm_dvec2's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true(1) if u = v, false(0) otherwise.
 */
bool cgm_dvec2_equals(const cgm_dvec2* u, const cgm_dvec2* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_dvec2_nadd(cgm_dvec2* v, double n);

/**
 * Adds two cgm_dvec2's component-wise.
 * The result u + v is stored in u.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_dvec2_add(cgm_dvec2* u, const cgm_dvec2* v);

/**
 * Subtracts two cgm_dvec2's component-wise.
 * The result u - v is stored in u
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_dvec2_sub(cgm_dvec2* u, const cgm_dvec2* v);

/**
 * Returns the dot product of two cgm_dvec2's.
 * If either of the vectors is NULL, then NaN is returned.
 * @param u - First vector.
 * @param v - Secont vector.
 * @return Dot product u . v.
 */
double cgm_dvec2_dot(const cgm_dvec2* u, const cgm_dvec2* v);

/**
 * Multiplies a cgm_dvec2 by a scalar.
 * The result val * v is stored in v.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_dvec2_scal(cgm_dvec2* v, double val);

/**
 * Returns the magnitude of a cgm_dvec2.
 * @param v - Vector to take the magnitude of.
 * @return Magnitude ||v||.
 */
double cgm_dvec2_mag(const cgm_dvec2* v);

/**
 * Normalizes a cgm_dvec2.
 * The vector v is scaled such that its magnitude is 1 and it has the same
 * direction as before.
 * If the vector has a magnitude of 0, no operation is performed.
 * @param v - Vector to normalize.
 */
void cgm_dvec2_norm(cgm_dvec2* v);

/**
 * Prints a cgm_dvec2 to a stream.
 * The vector is printed as "(x, y)\n" to the stream in "%g" format.
 * @param stream - Filesteam to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_dvec2_fprintf(FILE* stream, const cgm_dvec2* v);

/**
 * Prints a cmg_dvec2 to stdout.
 * The vector is printed as "(x, y)\n" to the stream in "%g" format.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_dvec2_printf(const cgm_dvec2* v);

#endif /* DVEC2_H_ */

/* vim: set ft=c: */
