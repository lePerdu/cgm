/**
 * dvec3.h
 *
 * Copyright (c) 2016 Zach Peltzer.
 * Subject to the MIT License.
 * 
 */

#ifndef DVEC3_H_
#define DVEC3_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dvec2.h"

/**
 * A 3-dimensional vector with double components.
 */
typedef union cgm_dvec3 {
    /**
     * Double component representation of the vector.
     */
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
     * RGB color representation of the vector.
     */
    struct {
        double r, g, b;
    };

    /**
     * Double texture coordinate representation of the vector.
     */
    struct {
        double s, t, p;
    };

    /**
     * Double array representation of the vector.
     */
    double v[3];
} cgm_dvec3;

/**
 * Returns a pointer to a compound literal cgm_dvec3.
 * This should be primarily used as a function parameter
 * when one wants to avoid creating a new variable.
 * To set the values of a cgm_dvec3, cgm_dvec3_set() should be used instead.
 * @param X - x coordinate.
 * @param Y - y coordinate.
 * @param Z - z coordinate.
 * @return Pointer to the vector.
 */
#define CGM_DVEC3(X, Y, Z)  ((const cgm_dvec3*) &((cgm_dvec3) {{(X), (Y), (Z)}}))

/**
 * Sets the components of a cgm_dvec3.
 * @param v - Vector to set.
 * @param x - x coordinate.
 * @param y - y coordinate.
 * @param z - z coordinate.
 */
void cgm_dvec3_set(cgm_dvec3* v, double x, double y, double z);

/**
 * Sets the components of a cgm_dvec3 from a cgm_dvec2 and a z-coordinate.
 * @param v - Vector to set.
 * @param xy - cgm_dvec2 with x and y coordinates.
 * @param z - z coordinate.
 */
void cgm_dvec3_set_v2(cgm_dvec3* v, const cgm_dvec2* xy, double z);

/**
 * Fills all components of a cgm_dvec3 with a value.
 * @param v - Vector to fill.
 * @param val - Value to fill with.
 */
void cgm_dvec3_fill(cgm_dvec3* v, double val);

/**
 * Copies src into dest.
 * @param dest - Destination vector.
 * @param src - Srouce vector.
 * @return dest.
 */
cgm_dvec3* cgm_dvec3_cpy(cgm_dvec3* dest, const cgm_dvec3* src);

/**
 * Tests if two cgm_dvec3's are equal.
 * Two vectors are equal if all of their corresponding components
 * are equal.
 * @param u - First vector.
 * @param v - Second vector.
 * @return true (1) if u = v; false (0) otherwise.
 */
bool cgm_dvec3_equals(const cgm_dvec3* u, const cgm_dvec3* v);

/**
 * Adds a value to each component of the vector.
 * @param v - Vector to add to.
 * @param n - Value to add.
 */
void cgm_dvec3_nadd(cgm_dvec3* v, double n);

/**
 * Adds two cgm_dvec3's component-wise.
 * @param u - Vector to add to.
 * @param v - Vector to add.
 */
void cgm_dvec3_add(cgm_dvec3* u, const cgm_dvec3* v);

/**
 * Subtracts two cgm_dvec3's component-wise.
 * @param u - Vector to subtract from.
 * @param v - Vector to subtract.
 */
void cgm_dvec3_sub(cgm_dvec3* u, const cgm_dvec3* v);

/**
 * Calculates the dot product of two cgm_dvec3's.
 * @param u - First vector.
 * @param v - Second vector.
 * @return The dot product u . v.
 */
double cgm_dvec3_dot(const cgm_dvec3* u, const cgm_dvec3* v);

/**
 * Multiplies a cgm_dvec3 by a scalar.
 * @param v - Vector to scale.
 * @param val - Scale factor.
 */
void cgm_dvec3_scal(cgm_dvec3* v, double val);

/**
 * Returns the magnitude of a cgm_dvec3.
 * @param v - Vector to take the magnitude of.
 * @return Magnitude ||v||.
 */
double cgm_dvec3_mag(const cgm_dvec3* v);

/**
 * Normalizes a cgm_dvec3.
 * The vector is scaled such that its magnitude is 1 and it has the same
 * direction as before.
 * @param v - The vector to normalize.
 */
void cgm_dvec3_norm(cgm_dvec3* v);

/**
 * Calculates the cross product of two cgm_dvec3's.
 * The cross product of two vectors is a vector which is perpendicular
 * to both of them.
 * @param out - Vector to store u x v.
 * @param u - First vector to cross.
 * @param v - Second vector to cross.
 */
void cgm_dvec3_cross(cgm_dvec3* out, const cgm_dvec3* u, const cgm_dvec3* v);

/**
 * Prints a cgm_dvec3 to a stream.
 * The vector is printed as "(x, y, z)\n" to the stream in "%g" format.
 * @param stream - Filestream to print to.
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_dvec3_fprintf(FILE* stream, const cgm_dvec3* v);

/**
 * Prints a cgm_dvec3 to stdout.
 * The vector is printed as in cgm_dvec3_fprintf().
 * @param v - Vector to print.
 * @return The number of characters printed.
 */
int cgm_dvec3_printf(const cgm_dvec3* v);

#endif /* DVEC3_H_ */

/* vim: set ft=c: */
