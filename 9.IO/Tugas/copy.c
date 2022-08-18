#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

extern int errno;

int main(int argc, char *argv[])
{

  // Make sure that there are arguments
  if (argc < 3)
  {
    printf("missing file argument");
    return -1;
  }

  // targeted file to be copied
  int targetedFile = open(argv[1], O_RDONLY | O_EXCL);

  // targeted file not exist or error opening targeted file
  if (targetedFile < 0)
  {
    perror(argv[1]);
    return -1;
  }

  // get file size of targeted file
  struct stat st;
  stat(argv[1], &st);

  // result file
  // if file does not have in directory then file is created.
  int createdFile = open(argv[2], O_EXCL);

  // Check is createdFile exist. If exist, prevent copy process.
  if (createdFile < 0)
  {
    createdFile = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (createdFile < 0)
    {
      close(targetedFile);

      // print which type of error have in a code
      printf("Error Number %d\n", errno);
      // print program detail "Success or failure"
      perror("Program");

      return -1;
    }
  }
  else
  {
    printf("%s is exist. Please change the filename\n", argv[2]);

    return -1;
  }

  // initiate String for storing entire file content
  char contents[st.st_size];

  // read file and store to c
  read(targetedFile, &contents, st.st_size);

  // write contents to createdfile
  int sz = write(createdFile, contents, strlen(contents));

  // close opened file
  close(targetedFile);
  close(createdFile);

  // if write process error, print the error message
  if (sz < 0)
  {
    perror("");
    return -1;
  }

  return 0;
}