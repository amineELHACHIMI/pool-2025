#include <stdio.h>
#include <stdlib.h>

int	*ft_range(int start, int end)
{
	int		i;
	int		l;
	int	*res;

	i = 0;
	int j = start;
	while (j <= end)
	{
		i++;
		j++;
	}
	printf("first i = %d", i);
	l = 0;
	res = malloc((i + 1) * 4);
	if (res == NULL)
		return (NULL);
	res[i+1]= '\0';
	printf("start= %d\nend= %d\nl= %d\n, i = %d\n", start, end, l, i);
	while (start <= end)
	{
		printf("start is ===>> %d", start);

		res[l] = start;
		l++;
		start++;
	}
	return (res);
}
int	main(void)
{
	int *res = ft_range(-2, 1);
	int i = 0;
	int l = 0;
/*	while (res[i] != '\0')
	{
		printf("%d, ", res[i]);
		i++;
	}*/
	printf("%d, ", res[0]);
	printf("%d, ", res[1]);
	printf("%d, ", res[2]);
	printf("%d", res[3]);


	return (0);
}
