/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:07:56 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/18 19:12:36 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(void *pointer, int *len)
{
	unsigned long	address;
	char			digits[20];
	char			*base_character;
	int				i;

	address = (unsigned long)pointer;
	base_character = "0123456789abcdef";
	i = 0;
	if (address == 0)
	{
		ft_print_str("(nil)", len);
		return ;
	}
	ft_print_str("0x", len);
	while (address != 0)
	{
		digits[i] = base_character[address % 16];
		address /= 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_print_char(digits[i], len);
	}
}
