/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:09:23 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/19 12:50:10 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *s, int *len)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		ft_print_str("(null)", len);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_print_char(s[i], len);
		i++;
	}
}
