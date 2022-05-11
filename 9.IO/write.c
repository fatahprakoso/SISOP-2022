#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
  int sz;

  int fd = open("foo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

  if (fd < 0)
  {
    perror("r1");
    exit(1);
  }

  sz = write(fd, "hello geeks\n", strlen("hello geeks\n"));

  printf("called write(% d, \"hello geeks\\n\", %zu)."
         " It returned %d\n",
         fd, strlen("hello geeks\n"), sz);

  int msg = close(fd);

  printf("close message: %d\n", msg);

  return 0;
}