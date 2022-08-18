#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
  // Make sure that there are arguments
  if (argc < 2)
  {
    printf("missing file argument");
    return -1;
  }

  // open file by the argument
  int fd = open(argv[1], O_RDONLY);

  if (fd < 0)
  {
    perror(argv[1]);
    return -1;
  }

  // get file size of targeted file
  struct stat st;
  stat(argv[1], &st);

  // initiate String for storing entire file content
  char contents[st.st_size];

  // read file and store to c
  read(fd, &contents, st.st_size);

  // print content
  for (int i = 0; i < sizeof(contents); i++)
  {
    printf("%c", contents[i]);
  }

  // close fd
  close(fd);

  return 0;
}