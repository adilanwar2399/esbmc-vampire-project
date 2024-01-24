#include "__fc_builtin.h"
#include "limits.h"

int Frama_C_nondet(int a, int b);

/*@ requires \true;
  @ terminates \false;
  @ assigns Frama_C_entropy_source \from Frama_C_entropy_source;
  @ ensures \result == 0;
  @*/

int main() {
    // int v1, v2, v3;
    int x = 0;
    int y = 0;
    int nd = Frama_C_interval(INT_MIN, INT_MAX);
    // int z = 0;
    
    /*@ loop invariant INT_MIN<= x <= INT_MAX;
      @ loop invariant x==y;    
      @ loop assigns x, y;
      @*/

    for(;nd;){ 
        x++; 
        y++; 
    }

    /*@ assert x==y;
        @*/
    
}