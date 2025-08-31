/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:40:58 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/18 18:45:28 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hex(unsigned int number, int *len, char case_type)
{
	int		i;
	char	digits[20];
	char	*base_character;

	if (case_type == 'x')
		base_character = "0123456789abcdef";
	else
		base_character = "0123456789ABCDEF";
	i = 0;
	if (number == 0)
	{
		ft_print_char('0', len);
		return ;
	}
	while (number != 0)
	{
		digits[i] = base_character[number % 16];
		number = number / 16;
		i++;
	}
	while (i > 0)
	{
		i--;
		ft_print_char(digits[i], len);
	}
}
