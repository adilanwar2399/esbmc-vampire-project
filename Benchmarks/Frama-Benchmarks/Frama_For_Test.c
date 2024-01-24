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
    // int z = 0;
    
    /*@ loop invariant 0 <= z <= 10;
      @ loop invariant x==y;    
      @ loop assigns x, y, z;
      @ loop variant 10-z;
      @*/

    for(int z = 0; z < 10; z++){ 
        x++; 
        y++; 
    }

    /*@ assert x==y;
        @*/
    
}