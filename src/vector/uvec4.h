/**
 * uvec4.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef UVEC4_H_
#define UVEC4_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include "uvec2.h"
#include "uvec3.h"

/**
 * A 4-dimensional vector with unsigned integer components.
 * (Do you think there might be too many unions here? Nah...)
 */
typedef union cgm_uvec4 {
    /**
     * Unsigned integer component representation of the vector.
     */
    struct {
        union {
            struct {
                union {
                    /**
                     * x and y components.
                     */
                    struct {
                        uint32_t x, y;
                    };

                    /**
                     * x and y components as a cgm_uvec2.
                     */
                    cgm_uvec2 xy;
                };

                /**
                 * z component.
                 */
                uint32_t z;
            };

            /**
             * x, y, and z components as a cgm_uvec3.
             */
            cgm_uvec3 xyz;
        };

        /**
         * w component.
         */
        uint32_t w;
    };

    /**
     * RGBA color representation of the vector.
     */
    struct {
        union {
            /**
             * r, g, and b components.
             */
            struct {
                uint32_t r, g, b;
            };

            /**
             * r, g, and b components as a cgm_uvec3.
             */
            cgm_uvec3 rgb;
        };

        /**
         * a (alpha) component.
         */
        uint32_t a;
    };

    /**
     * Unsigned integer texture coordinate representation of the vector.
     */
    struct {
        union {
            struct {
                union {
                    /**
                     * s and t coordinates.
                     */
                    uint32_t s, t;

                    /**
                     * s and t coordinates as a cgm_uvec2.
                     */
                    cgm_uvec2 st;
                };

                /**
                 * p coordinate.
                 */
                uint32_t p;
            };

            /**
             * s, t, and p coordinates as a cgm_uvec3.
             */
            cgm_uvec3 stp;
        };

        /**
         * q coordinate.
         */
        uint32_t q;
    };

    /**
     * Unsigned integer array representation of the vector.
     */
    uint32_t v[4];
} cgm_uvec4;

/**
 * Returns a pointer to a compound literal cgm_uvec4.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_uvec4, cgm_uvec4_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @param W - w coordinate.
 * @return Pointer to the vector.
 */
#define CGM_UVEC4(X, Y, Z, W)  ((const cgm_uvec4*) &((cgm_uvec4) {{(X), (Y), (Z), (W)}}))

/**
 * Sets the components of a cgm_uvec4.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_uvec4_set(cgm_uvec4* v, uint32_t x, uint32_t y, uint32_t z, uint32_t w);

/**
 * Sets the components of a cgm_uvec4 from a cgm_uvec2 and z and w coordinates
 * @param v - Vector to set.
 * @param xy - Vector with x and y coordinates.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_uvec4_set_v2(cgm_uvec4* v, const cgm_uvec2* xy, uint32_t z, uint32_t w);

/**
 * Sets the components of a cgm_uvec4 from a cgm_uvec3 and a w coordinate
 * @param v - Vector to set.
 * @param xyz - Vector with x, y, and z coordinates.
 * @param w - w coordinate.
 */
void cgm_uvec4_set_v3(cgm_uvec4* v, const cgm_uvec3* xyz, uint32_t w);

/**
 * Fills all components of a cgm_uvec4 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_uvec4_fill(cgm_uvec4* v, uint32_t val);

/**
 * Copies a vector into another.
 * @parm dest - Destinatoin vector.
 * @parm src - Source vector.
 * @return dest.
 */
cgm_uvec4* cgm_uvec4_cpy(cgm_uvec4* dest, const cgm_uvec4* src);

/**
 * Tests if two cgm_uvec4's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_uvec4_equals(const cgm_uvec4* u, const cgm_uvec4* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_uvec4_nadd(cgm_uvec4* v, uint32_t n);

/**
 * Adds two cgm_uvec4's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_uvec4_add(cgm_uvec4* u, const cgm_uvec4* v);

/**
 * Subtracts two cgm_uvec4's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_uvec4_sub(cgm_uvec4* u, const cgm_uvec4* v);

/**
 * Calculates the dot product of two cgm_uvec4's.
 * @param u - Frist vector.
 * @param v - Second vector.
 * @return Dot product u . v.
 */
uint32_t cgm_uvec4_dot(const cgm_uvec4* u, const cgm_uvec4* v);

/**
 * Multiplies a cgm_uvec4 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_uvec4_scal(cgm_uvec4* v, uint32_t val);

/**
 * Prints a cgm_uvec4 to a stream.
 * The vector is printed as "(x, y, z, w)\n" to the stream in "%d" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_uvec4_fprintf(FILE* stream, const cgm_uvec4* v);

/**
 * Prints a cgm_uvec4 to stdout.
 * The vector is printed in the format of cgm_uvec4_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_uvec4_printf(const cgm_uvec4* v);

#endif /* UVEC4_H_ */

/* vim: set ft=c: */
