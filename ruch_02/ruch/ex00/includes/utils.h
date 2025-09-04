/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:33:28 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 18:21:08 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>

typedef struct s_out
{
	int		started;
	int		error;
	t_dict	*dict;
}			t_out;

size_t		ft_strlen(const char *s);
int			ft_is_space(char c);
int			ft_is_digit(char c);
char		*ft_strndup(const char *s, size_t n);
char		*ft_strdup(const char *s);
char		*trim_inplace(char *s);
int			read_all(const char *path, char **out);

void		putstr(const char *s);
void		putendl(const char *s);

#endif
