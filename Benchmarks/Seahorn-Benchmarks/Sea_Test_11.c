#include "seahorn/seahorn.h"

extern void abort(void);
// extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
// void reach_error() { __assert_fail("0", "vnew2.c", 3, "reach_error"); }
extern void abort(void);
extern int nd();

void assume_abort_if_not(int cond) {
  if(!cond) {abort();}
}
// void __VERIFIER_assert(int cond) {
//   if (!(cond)) {
//     ERROR: {reach_error();abort();}
//   }
//   return;
// }

#define FORALL(Var, Type, Cond)       \
  Type Var;                           \
  __invariant(__forall(Var, Cond));   \

#define EXISTS(Var, Type, Cond)       \
  Type Var;                           \
  __invariant(__exists(Var, Cond));   \


// int __VERIFIER_nondet_int();

int main() {
    // variable declarations
    int n = nd();
    int v1 = nd();
    int v2 = nd();
    int v3 = nd();
    int x;

    // pre-conditions
    (x = 0);

    // loop body
    // __invariant(x <= n || n < 0);
    
    for (; x < n; x = (x + 1)) {
        // loop body
    }

    // post-condition
    if (n>=0){
        sassert(x==n);
    }
}