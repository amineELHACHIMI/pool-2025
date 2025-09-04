/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtahri <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 00:28:54 by mtahri            #+#    #+#             */
/*   Updated: 2025/09/03 00:28:56 by mtahri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*append_buf(char *content, char *buf, int total, int bytes)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = malloc(total + bytes + 1);
	if (!tmp)
	{
		free(content);
		return (NULL);
	}
	i = 0;
	while (i < total)
	{
		tmp[i] = content[i];
		i++;
	}
	j = 0;
	while (j < bytes)
	{
		tmp[total + j] = buf[j];
		j++;
	}
	tmp[total + bytes] = '\0';
	free(content);
	return (tmp);
}

static char	*init_content(int fd, int is_file)
{
	char	*content;

	content = malloc(1);
	if (!content)
	{
		if (is_file)
			close(fd);
		return (NULL);
	}
	content[0] = '\0';
	return (content);
}

static char	*read_loop(int fd, char *content, int is_file)
{
	char	buf[4096];
	int		bytes;
	int		total;

	total = 0;
	bytes = read(fd, buf, 4096);
	while (bytes > 0)
	{
		content = append_buf(content, buf, total, bytes);
		if (!content)
		{
			if (is_file)
				close(fd);
			return (NULL);
		}
		total += bytes;
		bytes = read(fd, buf, 4096);
	}
	return (content);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*content;

	fd = 0;
	if (filename)
	{
		fd = open(filename, O_RDONLY);
		if (fd < 0)
			return (NULL);
	}
	content = init_content(fd, filename != NULL);
	if (!content)
		return (NULL);
	content = read_loop(fd, content, filename != NULL);
	if (filename)
		close(fd);
	return (content);
}
