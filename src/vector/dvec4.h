/**
 * dvec4.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef DVEC4_H_
#define DVEC4_H_

#include <stdio.h>

#include "dvec2.h"
#include "dvec3.h"

/**
 * A 4-dimensional vector with double components.
 * (Do you think there might be too many unions here? Nah...)
 */
typedef union cgm_dvec4 {
    /**
     * Double component representation of the vector.
     */
    struct {
        union {
            struct {
                union {
                    /**
                     * x and y components.
                     */
                    struct {
                        double x, y;
                    };

                    /**
                     * x and y components as a cgm_dvec2.
                     */
                    cgm_dvec2 xy;
                };

                /**
                 * z component.
                 */
                double z;
            };

            /**
             * x, y, and z components as a cgm_dvec3.
             */
            cgm_dvec3 xyz;
        };

        /**
         * w component.
         */
        double w;
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
                double r, g, b;
            };

            /**
             * r, g, and b components as a cgm_dvec3.
             */
            cgm_dvec3 rgb;
        };

        /**
         * a (alpha) component.
         */
        double a;
    };

    /**
     * Double texture coordinate representation of the vector.
     */
    struct {
        union {
            struct {
                union {
                    /**
                     * s and t coordinates.
                     */
                    double s, t;

                    /**
                     * s and t coordinates as a cgm_dvec2.
                     */
                    cgm_dvec2 st;
                };

                /**
                 * p coordinate.
                 */
                double p;
            };

            /**
             * s, t, and p coordinates as a cgm_dvec3.
             */
            cgm_dvec3 stp;
        };

        /**
         * q coordinate.
         */
        double q;
    };

    /**
     * Double array representation of the vector.
     */
    double v[4];
} cgm_dvec4;

/**
 * Returns a pointer to a compound literal cgm_dvec4.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_dvec4, cgm_dvec4_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @param W - w coordinate.
 * @return Pointer to the vector.
 */
#define CGM_DVEC4(X, Y, Z, W)  ((const cgm_dvec4*) &((cgm_dvec4) {{(X), (Y), (Z), (W)}}))

/**
 * Sets the components of a cgm_dvec4.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_dvec4_set(cgm_dvec4* v, double x, double y, double z, double w);

/**
 * Sets the components of a cgm_dvec4 from a cgm_dvec2 and z and w coordinates
 * @param v - Vector to set.
 * @param xy - Vector with x and y coordinates.
 * @param z - z coordinate.
 * @param w - w coordinate.
 */
void cgm_dvec4_set_v2(cgm_dvec4* v, const cgm_dvec2* xy, double z, double w);

/**
 * Sets the components of a cgm_dvec4 from a cgm_dvec3 and a w coordinate
 * @param v - Vector to set.
 * @param xyz - Vector with x, y, and z coordinates.
 * @param w - w coordinate.
 */
void cgm_dvec4_set_v3(cgm_dvec4* v, const cgm_dvec3* xyz, double w);

/**
 * Fills all components of a cgm_dvec4 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_dvec4_fill(cgm_dvec4* v, double val);

/**
 * Copies a vector into another.
 * @parm dest - Destinatoin vector.
 * @parm src - Source vector.
 * @return dest.
 */
cgm_dvec4* cgm_dvec4_cpy(cgm_dvec4* dest, const cgm_dvec4* src);

/**
 * Tests if two cgm_dvec4's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_dvec4_equals(const cgm_dvec4* u, const cgm_dvec4* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_dvec4_nadd(cgm_dvec4* v, double n);

/**
 * Adds two cgm_dvec4's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_dvec4_add(cgm_dvec4* u, const cgm_dvec4* v);

/**
 * Subtracts two cgm_dvec4's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_dvec4_sub(cgm_dvec4* u, const cgm_dvec4* v);

/**
 * Calculates the dot product of two cgm_dvec4's.
 * @param u - Frist vector.
 * @param v - Second vector.
 * @return Dot product u . v.
 */
double cgm_dvec4_dot(const cgm_dvec4* u, const cgm_dvec4* v);

/**
 * Multiplies a cgm_dvec4 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_dvec4_scal(cgm_dvec4* v, double val);

/**
 * Returns the magnitude of a cgm_dvec4.
 * @param v - Vector to take the magnitude of.
 * @return Magnitude ||v||.
 */
double cgm_dvec4_mag(const cgm_dvec4* v);

/**
 * Normalizes a cgm_dvec4.
 * The vector v is scaled such that its magnitude is 1 and it has the same
 * direction as before.
 * @param v - Vector to normalize.
 */
void cgm_dvec4_norm(cgm_dvec4* v);

/**
 * Prints a cgm_dvec4 to a stream.
 * The vector is printed as "(x, y, z, w)\n" to the stream in "%g" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_dvec4_fprintf(FILE* stream, const cgm_dvec4* v);

/**
 * Prints a cgm_dvec4 to stdout.
 * The vector is printed in the format of cgm_dvec4_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_dvec4_printf(const cgm_dvec4* v);

#endif /* DVEC4_H_ */

/* vim: set ft=c: */
