/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:32:20 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 15:32:24 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_H
# define CONVERT_H

# include "dict.h"

int		convert_number(t_dict *dict, const char *num);
int		validate_number(const char *s);
char	*strip_leading_zeros(const char *s);

#endif
