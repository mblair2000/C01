// On my honor:
//
// - I have not discussed the C language code in my program with
// anyone other than my instructor or the teaching assistants
// assigned to this course.
//
// - I have not used C language code obtained from another student,
// the Internet, or any other unauthorized source, either modified
// or unmodified.
//
// - If any C language code or documentation used in my program
// was obtained from an authorized source, such as a text book or
// course notes, that has been clearly noted with a proper citation
// in the comments of my program.
//
// - I have not designed this program in such a way as to defeat or
// interfere with the normal operation of the Curator System.
//
// Michael Blair
// mblair2000


// bigMesa()
//   locates most massive "mesa" in an array of integer values
//   a "mesa" is a run of equal values
//   the "mass" of a "mesa" is the sum of the values in the mesa
//   a "mesa" can't have length < MIN_MESA_LENGTH
#include "bigMesa.h"

/**
 *  Given an array of nonnegative integers, a mesa is a sequence of at
 *  least MIN_MESA_LENGTH identical values.  The length of a mesa is the
 *  number of values in the sequence, and the mass of a mesa is the sum
 *  of the values in the sequence.
 *
 *  bigMesa() determines the mesa of maximum mass in the array that is
 *  passed into it.  bigMesa() reports its results by setting three extern
 *  variables:  mesaStart, mesaEnd and mesaMass.
 *
 * Pre:  A[0:A_SZ - 1] are nonnegative integers.
 *       The caller has declared the following three variables with
 *       external linkage, so they can be accessed by this function:
 *           uint8_t  mesaStart
 *           uint8_t  mesaEnd
 *           uint32_t mesaMass
 *
 * Post: mesaStart = index of first element of most massive mesa
 *       mesaEnd   = index of last element of most massive mesa
 *       mesaMass  = sum of elements in most massive mesa
 *       All are set to zero if no mesa is found. 
 *
 * Restrictions:
 *    You may not use a second array.
 *    You MUST use array bracket notation whenever you access an array 
 *        element.
 */ 
Mesa bigMesa(const uint16_t A[], uint8_t A_SZ) {

   // Create a dummy Mesa object to hold final answer; this will be
   // modified in the code you write below.
   Mesa possible = {0, 0, 0, 0, false};
   
   
   // You must write the body of the implementation here; use helper
   // functions if you like.
   
   for (int i = 0; i < A_SZ; i++)
   {
	   // Set a couple of variables used to determine characteristics
	   // of the mesa if found
	   int x = i;
	   uint32_t massMesa = A[i];
	   int count = 1;
	   
	   // if mesa height is high enough, move forward with process
	   if (A[i] >= MIN_MESA_HEIGHT)
	   {
		   // determine how long mesa lasts
		   while (A[x] == A[x + 1])
		   {
			   massMesa = massMesa + A[i];
			   count++;
			   x++;
		   }
		   
		   // if the valid messa has more mass, store values in
		   // possible's variables
		   if (count >= MIN_MESA_LENGTH && massMesa > possible.mass)
		   {
			   // change possible mesa's variabels
			   possible.height = A[i];
			   possible.start = i;
			   possible.end = i + count - 1;
			   possible.mass = massMesa;
			   possible.valid = true;
		   }
	   }
   }

   // Return the updated Mesa object to the caller:
   return possible;
}
