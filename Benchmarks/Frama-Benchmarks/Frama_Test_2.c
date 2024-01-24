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

    // Here the Loop Variant conditions will be clearly defined in the ACSL Spec manner.
    // Then the assigning will be done and any logic of them will also be defined.

    /*loop invariant 0 <= x <= 500;
      loop invariant x > 0 ==> z >= y;
      loop assigns x, y;
      loop variant 500 - x;
      */

    /*@ loop invariant 0 <= x <= 500;
      @ loop invariant x == 0 || z >= y;
      @ loop assigns x, y;
      @ loop variant 500 - x;
      @*/

    for (; x < 500; x++) {
        if (z <= y) {
            y = z;
        }
    }

    /*@ assert z>=y;
     @*/
    return 0;
}