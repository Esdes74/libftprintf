/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:11:47 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/23 21:16:46 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include "libft/lib_fct.h"

// Printf by 42
int	ft_printf(const char *str, ...);

// Convert integer from base 10 to base 16
int	conv_ten_to_hex(int nbr, char dep);
#endif
