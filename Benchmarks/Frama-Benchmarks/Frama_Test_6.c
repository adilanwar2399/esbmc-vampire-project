#include "__fc_builtin.h"
#include "limits.h"

int Frama_C_nondet(int a, int b);

/*@ requires \true;
  @ terminates \false;
  @ assigns Frama_C_entropy_source \from Frama_C_entropy_source;
  @ ensures \result == 0;
  @*/


int main() {
    
    int x = Frama_C_interval(INT_MIN ,  INT_MAX);
    int y = Frama_C_interval(INT_MIN ,  INT_MAX);
    int size = Frama_C_interval(INT_MIN ,  INT_MAX);

     // pre-conditions
     // __ESBMC_assume((x >= 0));
     // __ESBMC_assume((x <= 10));
     // __ESBMC_assume((y <= 10));
     // __ESBMC_assume((y >= 0));

     if (x<0){
      return 0; 
     }

     if (x>10){
      return 0;
     }

     if (y>10){
      return 0; 
     }

     if (y<0){
      return 0;
     }

     // loop body

     // Here the Loop Variant conditions will be clearly defined in the ACSL Spec manner.
     // Then the assigning will be done and any logic of them will also be defined.

    /*@ loop invariant INT_MIN <= x <= INT_MAX;
      @ loop invariant INT_MIN <= y <= INT_MAX;
      @ loop invariant -10 <= x - y <= 10;
      @ loop assigns x, y;
      @*/


     for (;size;) {
       x  = x + 10;
       y  = y + 10;
     }
     
     // post-condition
     if ( y == 0 ) {
        /*@ assert x!=20;
         @*/
        return 0;
      } 

}