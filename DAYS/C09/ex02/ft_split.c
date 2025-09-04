/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amelhach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:53:25 by amelhach          #+#    #+#             */
/*   Updated: 2025/09/03 16:59:35 by amelhach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (c == charset[i++])
			return (1);
	return (0);
}

int	count_substrings(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (is_separator(str[i], charset))
			i++;
		else
		{
			count++;
			while (str[i] && !is_separator(str[i], charset))
				i++;
		}
	}
	return (count);
}

int	get_word_len(char *str, char *charset)
{
	int	len;

	len = 0;
	while (str[len] && !is_separator(str[len], charset))
		len++;
	return (len);
}

char	*malloc_word(char *str, int len)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		k;
	int		len;
	int		count;
	char	**result;

	i = 0;
	k = 0;
	count = count_substrings(str, charset);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (is_separator(str[i], charset))
			i++;
		else
		{
			len = get_word_len(&str[i], charset);
			result[k++] = malloc_word(&str[i], len);
			i += len;
		}
	}
	result[k] = NULL;
	return (result);
}
