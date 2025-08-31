/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_int.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:29:27 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/18 16:24:35 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned_int(unsigned int u, int *len)
{
	char	digit;

	if (u > 9)
		ft_print_unsigned_int(u / 10, len);
	digit = (u % 10) + '0';
	ft_print_char(digit, len);
}
