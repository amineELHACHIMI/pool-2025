#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc == 2)
		while (argv[1][i])
		{
			if (i % 15 == 0)
				write(1, "5", 1);
			else if (i % 3 == 0)
				write(1, "5", 1);
			else if (i % 5 == 0)
				write(1, "3", 1);
			else
				write(1, &argv[1][i], 1);
			i++;
		}
	write(1, "\n", 1);
	return (0);
}
