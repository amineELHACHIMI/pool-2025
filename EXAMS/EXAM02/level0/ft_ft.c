void ft_ft(int *nbr)
{
 *nbr = 42;
}
#include <stdio.h>
int main(){
	int num;
	ft_ft(&num);
printf("%d\n", num);
return 0;
}
