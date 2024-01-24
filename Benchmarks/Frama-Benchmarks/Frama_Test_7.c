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
     // __ESBMC_assume((x <= 2));
     // __ESBMC_assume((y <= 2));
     // __ESBMC_assume((y >= 0));

     if (x<0){
      return 0; 
     }

     if (x>2){
      return 0;
     }

     if (y>2){
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
      @ loop invariant -2 <= x - y <= 2;
      @ loop assigns x, y;
      @*/


     for (;size;) {
       (x  = (x + 2));
       (y  = (y + 2));
     }
     
     // post-condition
     if ( x == 4 ) {
        /*@ assert x!=0;
         @*/
        return 0;
      } 

}