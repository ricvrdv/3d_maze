/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:04:50 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:58:20 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int   main(void)
{
        char    ch = 'a';

        printf("Character is '%c'\n", ch);
        printf("'%c' (using ft_toupper())\n", ft_toupper(ch));
        printf("'%c' (using toupper())\n", toupper(ch));
}*/
