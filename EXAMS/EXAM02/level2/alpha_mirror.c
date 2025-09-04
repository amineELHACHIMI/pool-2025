#include <unistd.h>

int	main(int argc, char *argv[])
{
	int		i;
	char	c;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] >= 'a' && argv[1][i] <= 'z')
			{
				c = argv[1][i];
				c = 'z' - (c - 'a');
				write(1, &c, 1);
			}
			else if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
			{
				c = argv[1][i];
				c = 'Z' - (c - 'A');
				write(1, &c, 1);
			}
			else
				write(1,&argv[1][i],1);
			i++;
		}
		// i=0;
		// while(argv[1][i]){
		// write(1,&argv[1][i],1);
		// i++;
		//}
	}
	return (0);
}
