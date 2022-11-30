/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:11:47 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/30 17:58:47 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/lib_fct.h"
# include <stdarg.h>

// Printf by 42
int		ft_printf(const char *str, ...);

// Convert integer from base 10 to base 16
void	conv_ten_to_hex(int nbr, char dep, int *res);

// Convert integer from base 10 to base 16 and print at adress format
void	print_adress(long long int nbr, char dep, int *res, int mod);
#endif
