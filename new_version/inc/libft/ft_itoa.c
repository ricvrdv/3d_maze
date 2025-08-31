/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 20:56:23 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/11 15:28:22 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long nbr);
static char	*mem_allocate(int digits);
char		*ft_itoa(int n);

char	*ft_itoa(int n)
{
	char	*string;
	long	nbr;
	int		digits;
	int		i;

	nbr = (long)n;
	digits = count_digits(nbr);
	string = mem_allocate(digits);
	if (!string)
		return (NULL);
	if (nbr < 0)
	{
		string[0] = '-';
		nbr = -nbr;
	}
	i = digits - 1;
	while (nbr > 0)
	{
		string[i--] = ((nbr % 10) + '0');
		nbr /= 10;
	}
	if (n == 0)
		string[0] = '0';
	string[digits] = '\0';
	return (string);
}

static int	count_digits(long nbr)
{
	int	digits;

	digits = 1;
	if (nbr < 0)
	{
		digits++;
		nbr = -nbr;
	}
	while (nbr / 10 > 0)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

static char	*mem_allocate(int digits)
{
	char	*string;

	string = (char *)malloc(sizeof(char) * (digits + 1));
	if (!string)
		return (NULL);
	return (string);
}

/*
#include <stdio.h>

int   main(int argc, char *argv[])
{
        if (argc == 2)
        {
                printf("Number: %s\n", argv[1]);
                printf("String: %s\n", ft_itoa(atoi(argv[1])));
                return (0);
        }
        return (1);
}*/
