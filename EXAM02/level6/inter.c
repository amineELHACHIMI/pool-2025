#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	i;
	int	j;
	int	l;
	int	tab[256] = {0};

	l = 0;
	if (argc > 1)
	{
		j = 1;
		while (argv[j])
		{
			i = 0;
			while (argv[j][i])
			{
				l=0;
				while (tab[l] && tab[l] != argv[j][i])
					l++;
				if (tab[l] == 0)
				{
					tab[l] = argv[j][i];
					write(1, &argv[j][i], 1);
				}
				i++;
			}
			j++;
		}
	}
	write(1,"\n",1);
	return (0);
}
