#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc > 1)
	{
		while (argv[i])
		{
			write(1, &argv[i][0], 1);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}
