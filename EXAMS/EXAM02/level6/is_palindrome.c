#include <unistd.h>

int	main(int argc,char *argv[])
{
	int	i;
	int	j;
	int	l;

	i = 0;
	j = 1;
	l = 0;
	if(argc <= 1){
		write(1,"\n",1);
	return 0;
	}
	 while (argv[j][l])
		 l++;
	 l--;
	while (argv[j][i])
	{

			while (argv[j][i] && l >= i)
			{
				if (argv[j][i] == argv[j][l])
				{
					i++;
					l--;
				}
				else
					return (0);
			}
			i = 0;
			j = 1;
			while (argv[j][i]){
				write(1, &argv[j][i], 1);
			i++;
			}
			 }
		
	
	return (0);
}
