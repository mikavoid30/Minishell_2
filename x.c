#include <stdlib.h>
#include <unistd.h>

int main()
{
  int	i;

  i = 0;
  while (i < 100)
    {
      char	d;
      char	c;

      d = '\n';
      c = (i % 10) + '0';
      write(1, &c, 1);
      write(1, &d, 1);
      i++;
      sleep(1);
    }
}
