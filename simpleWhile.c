#define N 10

int main()
{
  int numbers[N];
  int maxeven;
  int x = 0, i = 0;
  
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
      // So check that  maxeven is the greatest one of them
   }
     else {
        // check that there are NO even numbers in the array
     }
}
