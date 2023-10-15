#include <stdio.h>
#include <stdlib.h>

void print_pyramid(int);

int main(void) {
  char buf[512];
  int height;

  do {
    printf("Height: ");
    fgets(buf, sizeof buf, stdin);
    height = atoi(buf);
  } while (height < 1 || height > 16);

  print_pyramid(height);
}

void print_pyramid(int height) {
  int spaces = height - 1;

  for (int i = 0; i < height; i++) {
    // prints spaces before blocks
    for (int j = 0; j < spaces; j++) {
      printf(" ");
    }

    // prints left side of the pyramid
    for (int hashes = height - spaces; hashes > 0; hashes--) {
      printf("#");
    }

    // prints two-blocks wide space between the left and right side of the
    // pyramid
    printf("  ");

    // prints right side of the pyramid
    for (int hashes = height - spaces; hashes > 0; hashes--) {
      printf("#");
    }

    printf("\n");
    spaces -= 1;
  }
}