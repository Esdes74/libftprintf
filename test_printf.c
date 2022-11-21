/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eslamber <eslamber@student.42.ft>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 10:34:59 by eslamber          #+#    #+#             */
/*   Updated: 2022/11/21 09:54:35 by eslamber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int	n;

	n = 65;
	printf("espace : |% 5d|\nminus : |%-5d|\nzeros : |%05d|\n", n, n, n);
	n = 256854;
	printf("point : |%.8d|\nminus : |%-5d|\nzeros : |%05d|\n", n, n, n);
	n = 65;
	printf("espace : |%5d|\nminus : |%-5d|\n'x' : |%0x|\n", n, n, n);
	n = 0x5467;
	printf("espace : |%5d|\nminus : |%-5d|\n'x' : |%0x|\n", n, n, n);
	return 0;
}
