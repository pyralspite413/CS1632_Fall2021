#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _Node {
  struct _Node *next;
  unsigned char data[8];
} Node;

unsigned char *first_data = "Hello..";
unsigned char *second_data = "World..";
unsigned char *third_data = ".......";

void send_data(unsigned char *data, int len) {
  printf("[Sent data]\n");
  for (int i=0; i < len; i++) {
    printf("%2x ", data[i]);
  }
  printf("\n");
}

int main() {
  Node first, second, third;

  first.next = &second;
  memcpy(first.data, first_data, 8);
  second.next = &third;
  memcpy(second.data, second_data, 8);
  third.next = NULL;
  memcpy(third.data, third_data, 8);

  printf("[Stack]\n");
  printf("third.data = %s\n", third.data);
  printf("third.next = %p\n", third.next);
  printf("second.data = %s\n", second.data);
  printf("second.next = %p <--- Sent!\n", second.next);
  printf("first.data = %s <--- Sent!\n", first.data);
  printf("first.next = %p\n", first.next);

  send_data(first.data, 16);

  return 0;
}
