/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:06:36 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 14:58:59 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

/*
#include <stdio.h>
#include <ctype.h>

int   main(void)
{
        char    ch = 'G';

        printf("Character is '%c'\n", ch);
        printf("'%c' (using ft_tolower())\n", ft_tolower(ch));
        printf("'%c' (using tolower())\n", tolower(ch));
}*/
