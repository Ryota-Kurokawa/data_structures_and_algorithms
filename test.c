// 1万回Helloworldを出力するまでの時間を測る

#include <stdio.h>
#include <time.h>

int main()
{
  clock_t start = clock();
  for (int i = 0; i < 1000000; i++)
  {
    printf("Hello, World!");
  }
  clock_t end = clock();
  printf("Time: %f\n", (double)(end - start) / CLOCKS_PER_SEC);
  return 0;
}
