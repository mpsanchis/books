#include <stdio.h>

int uadd_ok(unsigned x, unsigned y) {
  int s = x + y;
  printf("SUM: %u\n", s);
  if (s < x) {
    printf("SUM smaller than first operand...");
    return 0;
  }
  return 1;
}

int main() {
  unsigned x = 2147483649;
  unsigned y = 2147483648;
  int add_ok = uadd_ok(x,y);
  char add_ok_c = add_ok == 1 ? 'y' : 'n';
  printf("Add OK? %c\n", add_ok_c);
}
