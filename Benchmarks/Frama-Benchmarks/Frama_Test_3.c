#include "__fc_builtin.h"
#include "limits.h"

int Frama_C_nondet(int a, int b);

/*@ requires \true;
  @ terminates \false;
  @ assigns Frama_C_entropy_source \from Frama_C_entropy_source;
  @ ensures \result == 0;
  @*/


int main() {
    
    int x = 0;
    int y = Frama_C_interval(INT_MIN ,  INT_MAX);
    int z = Frama_C_interval(INT_MIN ,  INT_MAX);

    int size = Frama_C_interval(0 ,  INT_MAX);;
    
    // int size = 5;

    // Here the Loop Variant conditions will be clearly defined in the ACSL Spec manner.
    // Then the assigning will be done and any logic of them will also be defined.

    // Important Note: If the size = (nondet) is exceedingly large for the variable then the loop will timeout.

    // Proves Termination of the loop. 
    // ESBMC Partial correctness.

    /*loop invariant 0 <= x <= size;
      loop invariant x > 0 ==> z >= y;
      loop assigns x, y;
      loop variant size - x;
      */

    /*@ loop invariant 0 <= x <= size;
      @ loop invariant x == 0 || z >= y;
      @ loop assigns x, y;
      @ loop variant size - x;
      @*/

    for (x = 0; x < size; x++) {
       if (z <= y) {
          y = z;
       }
    }

    if (size > 0) {
       /*@ assert z>=y;
        @*/
        return 0;
    }
    return 0;
}