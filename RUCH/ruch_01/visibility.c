/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visibility.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saatouam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 20:20:46 by saatouam          #+#    #+#             */
/*   Updated: 2025/08/24 20:20:51 by saatouam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_visible(int *line)
{
	int	i;
	int	max;
	int	visible;

	i = 0;
	max = 0;
	visible = 0;
	while (i < 4)
	{
		if (line[i] > max)
		{
			max = line[i];
			visible++;
		}
		i++;
	}
	return (visible);
}

void	reverse(int *arr)
{
	int	tmp;

	tmp = arr[0];
	arr[0] = arr[3];
	arr[3] = tmp;
	tmp = arr[1];
	arr[1] = arr[2];
	arr[2] = tmp;
}

void	copy_col(int grid[4][4], int col, int *out)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		out[i] = grid[i][col];
		i++;
	}
}
