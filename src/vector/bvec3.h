/**
 * bvec3.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef BVEC3_H_
#define BVEC3_H_

#include <stdbool.h>
#include <string.h>

#include "bvec2.h"

/**
 * A 3-dimensional bvector with bool components.
 */
typedef union cgm_bvec3 {
    /**
     * Float component representation of the bvector.
     */
    struct {
        union {
            /**
             * x and y components.
             */
            struct {
                bool x, y;
            };

            /**
             * x and y components as a cgm_bvec2.
             */
            cgm_bvec2 xy;
        };

        /**
         * z component.
         */
        bool z;
    };

    /**
     * RGB color representation of the bvector.
     */
    struct {
        bool r, g, b;
    };

    /**
     * Float texture coordinate representation of the bvector.
     */
    struct {
        bool s, t, p;
    };

    /**
     * Float array representation of the bvector.
     */
    bool v[3];
} cgm_bvec3;

/**
 * Returns a pointer to a compound literal cgm_bvec3.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_bvec3, cgm_bvec3_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @return Pointer to the bvector.
 */
#define CGM_BVEC3(X, Y, Z)  ((const cgm_bvec3*) &((cgm_bvec3) {{(X), (Y), (Z)}}))

/**
 * Sets the components of a cgm_bvec3.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 */
void cgm_bvec3_set(cgm_bvec3* v, bool x, bool y, bool z);

/**
 * Sets the components of a cgm_bvec3 from a cgm_bvec2 and a z-coordinate.
 * @param v - Vector to set.
 * @param xy - cgm_bvec2 with x and y coordinates.
 * @param z - z coordinate.
 */
void cgm_bvec3_set_v2(cgm_bvec3* v, const cgm_bvec2* xy, bool z);

/**
 * Fills all components of a cgm_bvec3 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_bvec3_fill(cgm_bvec3* v, bool val);

/**
 * Copies src into dest.
 * @param dest - Destination bvector.
 * @param src - Srouce bvector.
 * @return dest.
 */
cgm_bvec3* cgm_bvec3_cpy(cgm_bvec3* dest, const cgm_bvec3* src);

/**
 * Tests if two cgm_bvec3's are equal.
 * Two bvectors are equal if all of their corresponding components
 * are equal.
 * @param u - First bvector.
 * @param v - Second bvector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_bvec3_equals(const cgm_bvec3* u, const cgm_bvec3* v);

/**
 * Tests if any of the cgm_bvec3's components are true.
 * @param v - The vector to test.
 * @return true(1) if at least 1 of the components is true; false(0)
 * otherwise.
 */
bool cgm_bvec3_any(const cgm_bvec3* v);

/**
 * Tests if all of the cgm_vec3's components are true.
 * @param v - The vector to test.
 * @return true(1) if all of the components are true; false(0)
 * otherwise.
 */
bool cgm_bvec3_all(const cgm_bvec3* v);

/**
 * Logically negates all of the components of a cgm_bvec3.
 * @param v - The vector to negate.
 */
void cgm_bvec3_not(cgm_bvec3* v);

/**
 * Prints a cgm_bvec3 to a stream.
 * The bvector is printed as "(x, y, z)\n" to the stream in "%g" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_bvec3_fprintf(FILE* stream, const cgm_bvec3* v);

/**
 * Prints a cgm_bvec3 to stdout.
 * The bvector is printed as in cgm_bvec3_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_bvec3_printf(const cgm_bvec3* v);

#endif /* BVEC3_H_ */

/* vim: set ft=c: */
