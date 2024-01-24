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
    int a = Frama_C_interval(INT_MIN, INT_MAX);
    int m = Frama_C_interval(INT_MIN, INT_MAX);
    int x = 0;
    int k = 0;

    /*@ loop invariant 0 <= k <= 1;
      @ loop invariant k < 1 || m>=a;    
      @ loop assigns k, m;
      @ loop variant 1 - k;
      @*/

      for (; k < 1; k = k + 1) {
        if (m < a) {
            m = a;
        }
      }

      /*@ assert a<=m;
        @*/

      return 0;

}
