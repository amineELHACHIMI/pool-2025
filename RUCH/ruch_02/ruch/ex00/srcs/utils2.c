/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:22:09 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 18:33:48 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static void	int_to_str(char *buf, int v)
{
	int		i;
	int		j;
	char	tmp[4];

	if (v == 0)
	{
		buf[0] = '0';
		buf[1] = 0;
		return ;
	}
	i = 0;
	while (v > 0)
	{
		tmp[i++] = (v % 10) + '0';
		v /= 10;
	}
	j = 0;
	while (j < i)
	{
		buf[j] = tmp[i - 1 - j];
		j++;
	}
	buf[j] = 0;
}

int	int_from_digits(const char *s, size_t len)
{
	int		v;
	size_t	i;

	v = 0;
	i = 0;
	while (i < len)
	{
		v = v * 10 + (s[i] - '0');
		i++;
	}
	return (v);
}

static int	allocate_buffer(char **buf, size_t *cap, int fd)
{
	*cap = 4096;
	*buf = malloc(*cap + 1);
	if (!*buf)
	{
		close(fd);
		return (0);
	}
	return (1);
}

static int	expand_buffer(char **buf, size_t *cap, size_t len, int fd)
{
	char	*nb;
	size_t	i;

	nb = malloc((*cap) * 2 + 1);
	if (!nb)
		return (free(*buf), close(fd), 0);
	i = 0;
	while (i < len)
	{
		nb[i] = (*buf)[i];
		i++;
	}
	free(*buf);
	*buf = nb;
	*cap *= 2;
	return (1);
}

int	read_all(const char *path, char **out)
{
	int		fd;
	char	*buf;
	ssize_t	r;
	size_t	cap;
	size_t	len;

	fd = open(path, O_RDONLY);
	if (fd < 0 || !allocate_buffer(&buf, &cap, fd))
		return (0);
	len = 0;
	while (1)
	{
		r = read(fd, buf + len, cap - len);
		if (r < 0)
			return (free(buf), close(fd), 0);
		if (r == 0)
			break ;
		len += (size_t)r;
		if (len == cap && !expand_buffer(&buf, &cap, len, fd))
			return (0);
	}
	close(fd);
	buf[len] = 0;
	*out = buf;
	return (1);
}
