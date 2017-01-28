/**
 * bvec4.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef BVEC4_H_
#define BVEC4_H_

#include <stdbool.h>
#include <stdio.h>

#include "bvec2.h"
#include "bvec3.h"

/**
 * A 4-dimensional bvector with bool components.
 * (Do you think there might be too many unions here? Nah...)
 */
typedef union cgm_bvec4 {
    /**
     * Float component representation of the bvector.
     */
    struct {
        union {
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
             * x, y, and z components as a cgm_bvec3.
             */
            cgm_bvec3 xyz;
        };

        /**
         * w component.
         */
        bool w;
    };

    /**
     * RGBA color representation of the bvector.
     */
    struct {
        union {
            /**
             * r, g, and b components.
             */
            struct {
                bool r, g, b;
            };

            /**
             * r, g, and b components as a cgm_bvec3.
             */
            cgm_bvec3 rgb;
        };

        /**
         * a (alpha) component.
         */
        bool a;
    };

    /**
     * Float texture coordinate representation of the bvector.
     */
    struct {
        union {
            struct {
                union {
                    /**
                     * s and t coordinates.
                     */
                    bool s, t;

                    /**
                     * s and t coordinates as a cgm_bvec2.
                     */
                    cgm_bvec2 st;
                };

                /**
                 * p coordinate.
                 */
                bool p;
            };

            /**
             * s, t, and p coordinates as a cgm_bvec3.
             */
            cgm_bvec3 stp;
        };

        /**
         * q coordinate.
         */
        bool q;
    };

    /**
     * Float array representation of the bvector.
     */
    bool v[4];
} cgm_bvec4;

/**
 * Returns a pointer to a compound literal cgm_bvec4.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_bvec4, cgm_bvec4_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @param W - w coordinate.
 * @return Pointer to the bvector.
 */
#define CGM_BVEC4(X, Y, Z, W)  ((const cgm_bvec4*) &((cgm_bvec4) {{(X), (Y), (Z), (W)}}))

/**
 * Sets the components of a cgm_bvec4.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_bvec4_set(cgm_bvec4* v, bool x, bool y, bool z, bool w);

/**
 * Sets the components of a cgm_bvec4 from a cgm_bvec2 and z and w coordinates
 * @param v - Vector to set.
 * @param xy - Vector with x and y coordinates.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_bvec4_set_v2(cgm_bvec4* v, const cgm_bvec2* xy, bool z, bool w);

/**
 * Sets the components of a cgm_bvec4 from a cgm_bvec3 and a w coordinate
 * @param v - Vector to set.
 * @param xyz - Vector with x, y, and z coordinates.
 * @param w - w coordinate.
 */
void cgm_bvec4_set_v3(cgm_bvec4* v, const cgm_bvec3* xyz, bool w);

/**
 * Fills all components of a cgm_bvec4 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_bvec4_fill(cgm_bvec4* v, bool val);

/**
 * Copies a bvector into another.
 * @parm dest - Destinatoin bvector.
 * @parm src - Source bvector.
 * @return dest.
 */
cgm_bvec4* cgm_bvec4_cpy(cgm_bvec4* dest, const cgm_bvec4* src);

/**
 * Tests if two cgm_bvec4's are equal.
 * Two bvectors are equal if all of their corresponding components
 * are equal.
 * @param u - First bvector.
 * @param v - Second bvector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_bvec4_equals(const cgm_bvec4* u, const cgm_bvec4* v);

/**
 * Tests if any of the cgm_bvec4's components are true.
 * @param v - The vector to test.
 * @return true(1) if at least 1 of the components is true; false(0)
 * otherwise.
 */
bool cgm_bvec4_any(const cgm_bvec4* v);

/**
 * Tests if all of the cgm_vec4's components are true.
 * @param v - The vector to test.
 * @return true(1) if all of the components are true; false(0)
 * otherwise.
 */
bool cgm_bvec4_all(const cgm_bvec4* v);

/**
 * Logically negates all of the components of a cgm_bvec4.
 * @param v - The vector to negate.
 */
void cgm_bvec4_not(cgm_bvec4* v);

/**
 * Prints a cgm_bvec4 to a stream.
 * The bvector is printed as "(x, y, z, w)\n" to the stream in "%g" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_bvec4_fprintf(FILE* stream, const cgm_bvec4* v);

/**
 * Prints a cgm_bvec4 to stdout.
 * The bvector is printed in the format of cgm_bvec4_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_bvec4_printf(const cgm_bvec4* v);

#endif /* BVEC4_H_ */

/* vim: set ft=c: */
