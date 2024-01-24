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
    int i;
    int size = Frama_C_interval(0, INT_MAX);
    int sn;

    // pre-conditions
    (sn = 0);
    (i = 1);

    /*@ loop invariant 0 <= sn <= size+1;
      @ loop invariant sn == (i -1);  
      @ loop invariant sn == 0 || size >= 0;    
      @ loop invariant size < 0 || i <= size +1;  
      @ loop assigns i, sn;
      @ loop variant size - i;
      @*/

      for (; i <= size; i = (i + 1), sn = (sn + 1)) {
      }

      // post-condition
      if (sn != 0){
          /*@ assert sn==size;
            @*/
          return 0;
      }

      return 0;

}
