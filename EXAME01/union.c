#include <unistd.h>
int main(int argc, char **argv)
{
	int i = 0;
	int j;
	int k;
	if(argc == 3)
	{
		while(argv[1][i])
		{
			j = 0;
			while(argv[1][i] != argv[2][j] && argv[2][j] != '\0')
				j++;
			if(argv[1][i] == argv[2][j])
			{
				k = 0;
				while(k < i && argv[1][k] != argv[1][i])
					k++;
				if(k == i)
					write(1, &argv[1][i], 1);
			}
			i++;
		}
	}
	write(1, "\n", 1);
}
