/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tel-moat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 15:40:47 by tel-moat          #+#    #+#             */
/*   Updated: 2025/09/01 15:42:15 by tel-moat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_H
# define VALIDATE_H

int		validate_number(const char *s);
char	*strip_leading_zeros(const char *s);
char	*validate_inp(const char *num_str, t_dict *d, const char *dict_path);

#endif
