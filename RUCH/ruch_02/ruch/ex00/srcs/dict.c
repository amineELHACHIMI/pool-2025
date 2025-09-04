#include "dict.h"
#include <stdlib.h>

static int	dict_reserve(t_dict *d, size_t need)
{
	t_entry	*n;
	size_t	newcap;
	size_t	i;

	if (d->cap >= need)
		return (1);
	newcap = d->cap ? d->cap * 2 : 32;
	while (newcap < need)
		newcap *= 2;
	n = malloc(newcap * sizeof(t_entry));
	if (!n)
		return (0);
	i = 0;
	while (i < d->size)
	{
		n[i] = d->arr[i];
		i++;
	}
	free(d->arr);
	d->arr = n;
	d->cap = newcap;
	return (1);
}

int	dict_put(t_dict *d, char *key, char *val)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < d->size)
	{
		if (ft_strlen(d->arr[i].key) == ft_strlen(key))
		{
			j = 0;
			while (d->arr[i].key[j] && key[j] && d->arr[i].key[j] == key[j])
				j++;
			if (!d->arr[i].key[j] && !key[j])
			{
				free(d->arr[i].val);
				d->arr[i].val = val;
				free(key);
				return (1);
			}
		}
		i++;
	}
	if (!dict_reserve(d, d->size + 1))
	{
		free(key);
		free(val);
		return (0);
	}
	d->arr[d->size].key = key;
	d->arr[d->size].val = val;
	d->size++;
	return (1);
}

const char	*dict_get(t_dict *d, const char *key)
{
	size_t	i;
	size_t	ki;

	i = 0;
	while (i < d->size)
	{
		ki = 0;
		while (d->arr[i].key[ki] && key[ki] && d->arr[i].key[ki] == key[ki])
			ki++;
		if (!d->arr[i].key[ki] && !key[ki])
			return (d->arr[i].val);
		i++;
	}
	return (NULL);
}

int	is_numeric_str(const char *s)
{
	size_t	i;

	if (!s || !*s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

static int	parse_dict_line(const char *text, size_t start, size_t end,
		t_dict *d)
{
	size_t	colon;
	char	*left;
	char	*right;

	colon = start;
	while (colon < end)
	{
		if (text[colon] == ':')
			break ;
		colon++;
	}
	if (colon == end)
		return (0);
	left = ft_strndup(text + start, colon - start);
	right = ft_strndup(text + colon + 1, end - colon - 1);
	if (!left || !right)
	{
		free(left);
		free(right);
		return (0);
	}
	trim_inplace(left);
	trim_inplace(right);
	if (!is_numeric_str(left) || right[0] == 0)
	{
		free(left);
		free(right);
		return (0);
	}
	if (!dict_put(d, left, right))
		return (0);
	return (1);
}

int	parse_dict_text(const char *text, t_dict *d)
{
	size_t	i;
	size_t	start;
	size_t	end;

	i = 0;
	while (text[i])
	{
		start = i;
		while (text[i] && text[i] != '\n')
			i++;
		end = i;
		if (text[i] == '\n')
			i++;
		if (!parse_dict_line(text, start, end, d))
			return (0);
	}
	return (1);
}

int	load_dict(const char *path, t_dict *d)
{
	char	*txt;
	int		ok;

	txt = NULL;
	if (!read_all(path, &txt))
		return (0);
	ok = parse_dict_text(txt, d);
	free(txt);
	return (ok);
}

void	free_dict(t_dict *d)
{
	size_t	i;

	if (!d)
		return ;
	i = 0;
	while (i < d->size)
	{
		free(d->arr[i].key);
		free(d->arr[i].val);
		i++;
	}
	free(d->arr);
	d->arr = NULL;
	d->size = 0;
	d->cap = 0;
}
