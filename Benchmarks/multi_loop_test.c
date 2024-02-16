 extern void abort(void);
 extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
 void reach_error() { __assert_fail("0", "vnew2.c", 3, "reach_error"); }
 extern void abort(void);
 void assume_abort_if_not(int cond) {
   if(!cond) {abort();}
 }
 void __VERIFIER_assert(int cond) {
   if (!(cond)) {
     ERROR: {reach_error();abort();}
   }
   return;
 }

 #define FORALL(Var, Type, Cond)       \
   Type Var;                           \
   __invariant(__forall(Var, Cond));   \

 #define EXISTS(Var, Type, Cond)       \
   Type Var;                           \
   __invariant(__exists(Var, Cond));   \

 int __VERIFIER_nondet_int();


int main()
{   
    int x = 0;
    int y = __VERIFIER_nondet_int();
    __VERIFIER_assume(y>=0);

    __invariant(y >= 0);
    __invariant(x <= y);
    while(x < y) {
       x += 1;
    }

    // Now we should know that not(x < y) && (x <= y) which implies x = y
    __invariant(x == y);
    __invariant(y >= 0);
    while(y > 0) {
       x -= 1;
       y -= 1;
    }    
    // Now we should know that not(y > 0) and y>=0 which implies y = 0
    // Now we should know that y = 0 and x= y which implies x = 0
    __VERIFIER_assert (x == 0);
}