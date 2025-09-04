#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	l;
	int	tab[256] = {0};

	i = 0;
	j = 0;
	l = 0;
	if (argc <= 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (argv[j])
	{
		while (argv[j][i])
		{
			l = 0;
			while (argv[j][i])
			{
				if (tab[l] == argv[j][i])
				{
					i++;
					break ;
				}
				l++;
			}
			if (tab[l] == 0)
				tab[l] = argv[j][i];
			l = 0;
		}
		j++;
		while (tab[l])
		{
			write(1, &tab[l], 1);
			l++;
		}
	}
}
