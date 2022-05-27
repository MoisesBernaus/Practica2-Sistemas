#include <stdio.h>

int main( void ) {
  int D,d, r, q;

  __CPROVER_assume( (D < 0) &&  (D >= -300) &&
                   (d >= 0)  );
  r = D; 
  q = 0;
  while ( r < 0 ) {
     r = r + d;
     q--;   
  }
  printf( " quotient: %d,  reminder: %d\n", q, r );
}

