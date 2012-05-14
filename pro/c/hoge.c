#include <stdio.h>

int f(int x);
int main()
{
  printf ("hoge\n");
  f(10);
  return 0;
}

int f(int x){
  printf ("f's address is %x\n", f);
}
