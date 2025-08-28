#include <stdio.h>

int f(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    if (x == 3) return 4;
    return f(x - 1) + f(x - 2) + f(x - 3);
}

int main(){
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", f(n));
  }
  return 0;
}