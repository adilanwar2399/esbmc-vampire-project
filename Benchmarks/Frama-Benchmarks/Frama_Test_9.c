#include "__fc_builtin.h"
#include "limits.h"

int Frama_C_nondet(int a, int b);

/*@ requires \true;
  @ terminates \false;
  @ assigns Frama_C_entropy_source \from Frama_C_entropy_source;
  @ ensures \result == 0;
  @*/

int main() {
    // variable declarations
    int n = Frama_C_interval(0, INT_MAX);
    int x;

    // pre-conditions
    (x = n);

    /*@ loop invariant 0 <= x <= n;
      @ loop invariant n < 1 || x >=1;    
      @ loop assigns x;
      @ loop variant x - 1;
      @*/

      for (; x > 1; ) {
          x = x - 1;
          // loop body
      }
     
      if ( x!=1) {
        /*@ assert n<1;
         @*/
        return 0;
      } 

}

/*
[wp] [Timeout] typed_main_loop_invariant_established (Qed 2ms) (Z3)
[wp] [Timeout] typed_main_assert (Qed 6ms) (Z3)
*/