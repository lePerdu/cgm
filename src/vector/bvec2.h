/**
 * bvec2.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef BVEC2_H_
#define BVEC2_H_

#include <stdbool.h>
#include <stdio.h>

/**
 * A 2-dimensional vector with boolean components.
 */
typedef union cgm_bvec2 {
    /**
     * Float component representation of the vector.
     */
    struct {
        bool x, y;
    };

    /**
     * Float texture coordinate representaion of the vector.
     */
    struct {
        bool s, t;
    };

    /**
     * Float array representation of the vector.
     */
    bool v[2];
} cgm_bvec2;

/**
 * Returns a pointer to a compound literal cgm_bvec2.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_bvec2, cgm_bvec2_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @return Constant pointer to cgm_bvec2.
 */
#define CGM_BVEC2(X, Y)  ((const cgm_bvec2*) &((cgm_bvec2) {{(X), (Y)}}))

/**
 * Sets the components of a cgm_bvec2.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 */
void cgm_bvec2_set(cgm_bvec2* v, bool x, bool y);

/**
 * Fills both components of a cgm_bvec2 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_bvec2_fill(cgm_bvec2* v, bool val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Source vector.
 * @return dest.
 */
cgm_bvec2* cgm_bvec2_cpy(cgm_bvec2* dest, const cgm_bvec2* src);

/**
 * Tests if two cgm_bvec2's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true(1) if u = v, false(0) otherwise.
 */
bool cgm_bvec2_equals(const cgm_bvec2* u, const cgm_bvec2* v);

/**
 * Tests if any of the cgm_bvec2's components are true.
 * @param v - The vector to test.
 * @return true(1) if at least 1 of the components is true; false(0)
 * otherwise.
 */
bool cgm_bvec2_any(const cgm_bvec2* v);

/**
 * Tests if all of the cgm_vec2's components are true.
 * @param v - The vector to test.
 * @return true(1) if all of the components are true; false(0)
 * otherwise.
 */
bool cgm_bvec2_all(const cgm_bvec2* v);

/**
 * Logically negates all of the components of a cgm_bvec2.
 * @param v - The vector to negate.
 */
void cgm_bvec2_not(cgm_bvec2* v);

/**
 * Prints a cgm_bvec2 to a stream.
 * The vector is printed as "(x, y)\n" to the stream in "%g" format.
 * @param stream - Filesteam to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_bvec2_fprintf(FILE* stream, const cgm_bvec2* v);

/**
 * Prints a cmg_bvec2 to stdout.
 * The vector is printed as "(x, y)\n" to the stream in "%g" format.
 * @param m - Matrix to print.
 * @return The number of characters printed.
 */
int cgm_bvec2_printf(const cgm_bvec2* v);

#endif /* BVEC2_H_ */

/* vim: set ft=c: */
