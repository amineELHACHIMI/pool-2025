#include <unistd.h>

int	check(char str[], char res)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == res)
			return (0);
		i++;
	}
	str[i] = res;
	return (1);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	c;
	char	res;
	char	cont;
	char	str[100] = {0};

	c = 0;
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			res = argv[1][i];
			cont = 0;
			j = i;
			if (check(str, res) == 1)
			{
				while (argv[1][j])
				{
					if (argv[1][j] == res)
						cont++;
					j++;
				}
				write(1, &res, 1);
				write(1, "/", 1);
				if (cont > 9)
				{
					c = cont / 10 + '0';
					write(1, &c, 1);
					c = cont % 10 + '0';
					write(1, &c, 1);
					write(1, "\n", 1);
				}
				else
				{
					c = cont + '0';
					write(1, &c, 1);
					write(1, "\n", 1);
				}
			}
			i++;
		}
	}
	return (0);
}
