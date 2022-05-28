#define N 10

int main()
{
  int numbers[N];
  int maxeven;
  int x = 0, i = 0;

  
   for(int i=0; i <N; i++)__CPROVER_assume((numbers[i] >= -10) && (numbers[i] <= 10));

   maxeven = 1;
   for (i = 0; i < N ; i++) {
     if (numbers[i] % 2 == 0 ) {
        if (maxeven == 1 || maxeven < numbers[i]) {
            maxeven = numbers[i];
        }
     } 
   }
   if (maxeven != 1) {
      // there are even numbers in the array,
      // So check that maxeven is the greatest one of them
      int max_in_array = 0;
      for(int i=0; i < N; i++) max_in_array = ((numbers[i] % 2 == 0) && (numbers[i] == maxeven)) ? 1: max_in_array;
      __CPROVER_assert(max_in_array == 1, "maxeven es un numero par del array");


      // cuenta el numero de pares
      int even_counter =0;
      for(int i=0; i < N; i++) even_counter = (numbers[i] % 2 == 0) ? even_counter+1: even_counter; 

      // comprueba que maxeven >= a todos los numeros pares del array
      int counter = 0;
      for(int i=0; i < N; i++) counter = (numbers[i] % 2 == 0 && maxeven >= numbers[i]) ? counter +1: counter;
       __CPROVER_assert(counter == even_counter, "forall even number in numbers max >= number");
   }
     else {
        int odd_counter = 0;
        for(int i=0; i < N; i++) odd_counter = (numbers[i] % 2 == 0) ? odd_counter: odd_counter +1;
        __CPROVER_assert(odd_counter == N, "numero de impares == N"); 
     }
     
}
