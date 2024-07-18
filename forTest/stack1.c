#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int top, S[1000];

void push(int x){
  S[top+1] = x;
}

int pop(){
  top--;
  return S[top+1];
}

int main()
{
  int a, b;
  top = 0;
  char s[100];
  while (scanf("%s", s) != EOF)
  {
    if (s[0] == "+" )
    {
      a = S[top -1];
      b = S[top];
      push(a+b);
    }
    if (s[0] == "-")
    {
      a = S[top-1];
      b = S[top];
      push(a-b);
    }
    if (s[0] == "*" )
    {
      a = S[top -1];
      b = S[top];
      push(a*b);
    }
    if (s[0] == "/")
    {
      a = S[top-1];
      b = S[top];
      push(a/b);
    }
    
    
  }
  

  return 0;
}
