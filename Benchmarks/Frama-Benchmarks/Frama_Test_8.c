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
    int m = 0;
    // int n = Frama_C_interval(INT_MIN ,  INT_MAX);
    // int size = Frama_C_interval(INT_MIN ,  INT_MAX);

    int n = Frama_C_interval(0 ,  INT_MAX);
    int size = Frama_C_interval(INT_MIN ,  INT_MAX);

    //--------ASK ABOUT 0 and INT_MAX-------------------------------------

     // loop body

     // Here the Loop Variant conditions will be clearly defined in the ACSL Spec manner.
     // Then the assigning will be done and any logic of them will also be defined.

     /* [wp] [Timeout] typed_main_loop_invariant_3_established (Qed 3ms) (Z3) - with below code.
       loop invariant 0 <= x <= n;
       loop invariant n < 0 ==> x <= n;
       loop invariant m == 0 ==> m < x;      
       loop assigns x, m;
       loop variant n - x;
      */

    /*@ loop invariant 0 <= x <= n;
      @ loop invariant n < 0 || x <= n;
      @ loop invariant m == 0 || m < x;      
      @ loop assigns x, m;
      @ loop variant n - x;
      @*/


     for (; x<n; x=x+1) {
         if(size){
            m=x;
         }
     }
     
     if ( n>0) {
        /*@ assert m<n;
         @*/
        return 0;
      } 

}