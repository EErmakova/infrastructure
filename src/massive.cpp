#include <stack>
#include "massive.h"
int* Multipl(int*a, int n) {
   int* res = new int[n];
   int* tmp = new int[n-1];
   tmp[0] = a[1];
   for (int i = 1; i < n - 2; ++i)
       tmp[i] = tmp[i - 1] * a[i];
   int mul = 1;
   for (int i = n; i >0; --i) {
       res[i] = tmp[i]*mul;
       mul *= a[i];

   }
   return res;
   
}
