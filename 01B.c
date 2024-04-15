#include<stdio.h>

int GCD(int a, int b){
while (b != 0)
{
  int temp = b;
  b = a % b;
  a = temp;
}
return a;
}

int main(void)
{

  int x,y;
  x = 0;
  y = 0;
  scanf("%d", &x);
  scanf("%d", &y);
  int z = GCD(x, y);
  printf("%d\n", z);

  return 0;
}

