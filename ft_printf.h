/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 08:11:47 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/25 15:23:31 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/lib_fct.h"
# include <stdarg.h>
// Printf by 42
int	ft_printf(const char *str, ...);

// Convert integer from base 10 to base 16
int	conv_ten_to_hex(int nbr, char dep);
#endif
