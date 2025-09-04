
#include <unistd.h>

int	main(void)
{
	int	i;
	int c;
	i = 0;
	while (i <= 9)
	{
		c=i+'0';
			write(1, &c, 1);
		i=i+2;
	}
	write(1, "10", 2);
	write(1, "\n", 1);
	return (0);
}
