/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saatouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:20:25 by saatouam          #+#    #+#             */
/*   Updated: 2025/08/24 20:22:34 by saatouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_space(char *str)
{
	if (!*str || *str == ' ')
		return (0);
	return (1);
}

int	parse_input(char *str, int *clues)
{
	int	i;

	i = 0;
	ft_space(str);
	while (*str)
	{
		if (*str >= '1' && *str <= '4')
		{
			if (i >= 16)
				return (0);
			clues[i++] = *str - '0';
			str++;
			if (*str == ' ')
			{
				str++;
				if (!*str)
					return (0);
			}
			else if (*str != '\0')
				return (0);
		}
		else
			return (0);
	}
	return (i == 16);
}
