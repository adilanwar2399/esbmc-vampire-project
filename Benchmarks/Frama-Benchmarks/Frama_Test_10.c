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
    int v1 = Frama_C_interval(INT_MIN, INT_MAX);
    int v2 = Frama_C_interval(INT_MIN, INT_MAX);
    int v3 = Frama_C_interval(INT_MIN, INT_MAX);
    int x;

    // pre-conditions
    (x = n);

    /*@ loop invariant 0 <= x <= n;
      @ loop invariant x < n ==> n < 0;    
      @ loop assigns x;
      @ loop variant n - x;
      @*/

      for (; x < n; x=x+1) {
          // loop body
      }
     
      if ( x!=n) {
        /*@ assert n<0;
         @*/
        return 0;
      } 

}

/* No Error when int n = Frama_C_Interval(0, INT_MAX);
<Otherwise:-------[wp] [Timeout] typed_main_loop_invariant_established (Qed 6ms) (Z3)---->
*/