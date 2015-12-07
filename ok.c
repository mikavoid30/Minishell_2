#include <unistd.h>

int main()
{
  int i = 30;
  int c = '#';
  while (i > 0)
    {
      write(1, &c, 1);
      sleep(1);
    }
  return (0);
}
