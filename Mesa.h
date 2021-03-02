#ifndef MESA_H
#define MESA_H
#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

/***  DO NOT MODIFY THIS FILE!!  ***/

/**  Represents a "mesa", defined as a contiguous sequence of array cells,
 *   storing the same value, which must be at least MIN_MESA_HEIGHT, and
 *   including at least MIN_MESA_LENGTH such cells.  The "mass" of such
 *   a sequence is defined as the sum of the values in the sequence.
 * 
 *   A Mesa object is said to be proper if each of the following
 *   conditions holds:
 * 
 *     - height and length satisfy the minimum requirement
 *     - end > begin >= 0
 *     - mass = sum of the values in the sequence
 *     - valid = true
 *
 *   or if each of the following conditions hold:
 * 
 *     - height = begin = end = mass = 0
 *     - valid = false
 */
 
#define MIN_MESA_HEIGHT 200       // minimum height to be a mesa
#define MIN_MESA_LENGTH   9       // minimum length to be a mesa

struct _Mesa {
	uint16_t height;   // the height of the mesa
	uint16_t start;    // the first index included in the mesa
	uint16_t end;      // the last index included in the mesa
	uint32_t mass;     // the product of the mesa's height and length
    bool     valid;    // true iff a valid Mesa was found
};
typedef struct _Mesa Mesa;

void writeMesa(FILE* fp, Mesa m);

#endif
