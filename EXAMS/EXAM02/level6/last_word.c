#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	l;

	l = 0;
	if(argc==2){
	while (argv[1][l])
		l++;
	l--;
	while (l >= 0 && (argv[1][l] == ' ' || argv[1][l] == '\t'))
		l--;
	while (l >= 0 && (argv[1][l] != ' ' &&  argv[1][l] != '\t'))
		l--;
	l++;
	while (argv[1][l] && (argv[1][l] != ' ' || argv[1][l] != '\t'))
	{
		write(1, &argv[1][l], 1);
		l++;
	}
	l=0;

	}
	write(1,"\n",1);
	return (0);
}
