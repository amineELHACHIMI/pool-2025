/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:24:32 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 18:24:36 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include <unistd.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f')
		return (1);
	return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*p;
	size_t	i;

	p = malloc(n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n && s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strdup(const char *s)
{
	return (ft_strndup(s, ft_strlen(s)));
}
