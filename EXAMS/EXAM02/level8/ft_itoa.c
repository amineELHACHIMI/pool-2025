#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int nbr)
{
	int		i;
	char	*res;
	long	n;
	long	temp;

	i = 0;
	n = nbr;
	if (nbr < 0)
	{
		n = -n;
		i++;
	}
	temp = n;
	while (temp > 0)
	{
		temp /= 10;
		i++;
	}
	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	if (nbr < 0)
		res[0] = '-';
	i--;
	while (n)
	{
		res[i] = (n % 10) + '0';
		n /= 10;
		i--;
	}
	printf("%d\n", i);
	return (res);
}
int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
	return (0);
}
