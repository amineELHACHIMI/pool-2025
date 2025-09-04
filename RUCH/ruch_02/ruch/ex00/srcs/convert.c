#include "convert.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

static int	*make_pow10_key(size_t zeros)
{
	char	*k;
	size_t	i;
	int		*res;

	k = malloc(zeros + 2);
	if (!k)
		return (0);
	i = 0;
	k[i++] = '1';
	while (zeros--)
		k[i++] = '0';
	k[i] = 0;
	res = int_from_digits(k, i - 1);
	free(k);
	return (res);
}

int	handle_zero(const char *num, t_dict *dict, int len)
{
	const char	*z;

	z = dict_get(dict, "0");
	if (!z)
	{
		putendl("Dict Error");
		return (0);
	}
	putendl(z);
	return (1);
}

static char	*init_group(const char *num, size_t start, size_t len)
{
	char	*res;

	res = ft_strndup(num + start, len - start);
	return (res);
}

char	**init_g(const char *num, size_t groups, size_t len)
{
	char	**g;
	size_t	start;

	g = malloc(groups * sizeof(char *));
	if (!g)
	{
		putendl("Dict Error");
		return (0);
	}
	while (len > 0)
	{
		if (len >= 3)
			start = len - 3;
		else
			start = 0;
		g[--groups] = init_group(num, start, len);
		if (!g[groups])
		{
			putendl("Dict Error");
			return (0);
		}
		len = start;
	}
	return (g);
}

int	convert_number(t_dict *dict, const char *num)
{
	size_t	len;
	size_t	groups;
	t_out	out;

	len = ft_strlen(num);
	if (len == 1 && num[0] == '0')
		handle_zero(num, dict, len);
	groups = (len + 2) / 3;
	print_num(&out, dict, groups, init_g(num, groups, len));
	if (out.error)
	{
		putendl("Dict Error");
		return (0);
	}
	write(1, "\n", 1);
	return (1);
}
