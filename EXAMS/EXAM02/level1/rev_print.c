#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	if (argc == 2)
	{
		while (argv[1][j])
			j++;
		j--;
		while (argv[1][i] && i < j)
		{
			tmp = argv[1][j];
			argv[1][j] = argv[1][i];
			argv[1][i] = tmp;
			i++;
			j--;
		}
		i = 0;
		while (argv[1][i])
		{
			write(1, &argv[1][i], 1);
			i++;
		}
	}
	return (0);
}
