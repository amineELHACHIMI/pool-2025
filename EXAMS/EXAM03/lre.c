#include <unistd.h>

int main(int ac, char **av)
{
	int i, j, count;
	int printed[256]={0};
	char c;

	if (ac == 2)
	{
		//i = 0;
		//while (i < 256)
			//printed[i++] = 0;
		i = 0;
		while (av[1][i])
		{
			if (printed[av[1][i]] == 0)
			{
				count = 0;
				j = 0;
				while (av[1][j])
				{
					if (av[1][j] == av[1][i])
						count++;
					j++;
				}
				write(1, &av[1][i], 1);
				write(1, ":", 1);
				if (count > 9)
				{
					c = (count / 10) + '0';
					write(1, &c, 1);
				}
				c = (count % 10) + '0';
				write(1, &c, 1);
				write(1, "\n", 1);
				printed[av[1][i]] = 1;
			}
			i++;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

