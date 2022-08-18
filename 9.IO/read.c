#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char c[32];

  int fd1 = open("sample.txt", O_RDONLY);

  read(fd1, &c, 32);

  for (int i = 0; i < sizeof(c); i++)
  {
    printf("%c ", c[i]);
  }
  printf("\n");

  exit(0);
}