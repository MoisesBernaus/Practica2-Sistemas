#include <stdio.h>

int main( void ) {
  int D,d, r, q;


    __CPROVER_assume( (D < 0) &&  (D >= -300) &&
                  (d > 0)); // cambio de d>=0 a d > 0  sino el bucle puede no acabar 
  r = D; 
  q = 0;
  while ( r < 0 ) {
     r = r + d;
     q--;  
  }
   
  __CPROVER_assert(q == (D - r) / d , "q == cociente");
  __CPROVER_assert(r == D - ((q * d) ), "r == resto");

  // Este assert es equivalente a realizar los 2 anteriores
  __CPROVER_assert(D ==((q * d) + r), "Relación D, d, q, r"); 
  printf( " quotient: %d,  reminder: %d\n", q, r );
}

