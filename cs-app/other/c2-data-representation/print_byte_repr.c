#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_ptr;

void show_bytes(byte_ptr start, size_t len) {
  int i;
  for (i = 0; i < len; i++) {
    printf(" %.2x", start[i]);
  }

  printf("\n");
}

void show_int(int x) {
  show_bytes((byte_ptr) &x, sizeof(int));
}

void show_ptr(void *x) {
  show_bytes((byte_ptr) &x, sizeof(void *));
}

void show_float(float x) {
  show_bytes((byte_ptr) &x, sizeof(float));
}

void show_str(const char *x) {
  show_bytes((byte_ptr)x, strlen(x));
}

int main() {
  int ival = 0x3039; // 12345 decimal

  printf("int:\n");
  show_int(ival); // in mac/arm64, shows '39 30 00 00' (little endian: first address has less significant value)

  printf("ptr:\n");
  show_ptr(&ival);

  printf("float:\n");
  show_float((float)ival);

  printf("string:\n");
  // In ASCII:
  //   - digit 'd' is 0x3d
  //   - end is: 0x00
  //
  // --> "12345" = 0x 35 34 33 32 31 00
  // strlen skips the end character, as it is the same for all strings
  const char* s = "12345"; 
  show_str(s);
  printf("[0]: %.2x\n", s[0]);

}
