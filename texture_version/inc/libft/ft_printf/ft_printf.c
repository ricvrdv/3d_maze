/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:35:26 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/19 14:13:47 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_specifier(char s, va_list *args, int *len, int *i);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] != '\0')
				check_specifier(format[i++], &args, &len, &i);
			else
				break ;
		}
		else
		{
			ft_print_char((char)format[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}

static void	check_specifier(char sp, va_list *args, int *len, int *i)
{
	if (sp == 'c')
		ft_print_char(va_arg(*args, int), len);
	else if (sp == 's')
		ft_print_str(va_arg(*args, char *), len);
	else if (sp == 'p')
		ft_print_pointer(va_arg(*args, void *), len);
	else if (sp == 'd' || sp == 'i')
		ft_print_int(va_arg(*args, int), len);
	else if (sp == 'u')
		ft_print_unsigned_int(va_arg(*args, unsigned int), len);
	else if (sp == 'x')
		ft_print_hex(va_arg(*args, unsigned int), len, sp);
	else if (sp == 'X')
		ft_print_hex(va_arg(*args, unsigned int), len, sp);
	else if (sp == '%')
		ft_print_char('%', len);
	else
		(*i)--;
}

/*
# include <stdio.h>
# include <limits.h>

int	main(void)
{
	char	c1 = 'r', c2 = ' ', c3 = 0, c4 = 'R';
	int	n1 = 42, n2 = -42, n3 = INT_MIN, n4 = INT_MAX;
	char	*s1 = "Print me!", *s2 = "", *s3 = NULL;

	ft_printf("specifier c:\n");
	int r1 = ft_printf("ft_printf: '%c' '%c' '%c' '%c' %%\n", c1, c2, c3, c4);
	ft_printf("(return = %d)\n", r1);
	int r2 = printf("printf   : '%c' '%c' '%c' '%c' %%\n", c1, c2, c3, c4);
	ft_printf("(return = %d)\n\n", r2);

	ft_printf("specifier d:\n");
	int r3 = ft_printf("ft_printf: %d %d %d %d\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n", r3);
	int r4 = printf("printf   : %d %d %d %d\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n\n", r4);

	ft_printf("specifier i:\n");
	int r5 = ft_printf("ft_printf: %i %i %i %i\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n", r5);
	int r6 = printf("printf   : %i %i %i %i\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n\n", r6);

	ft_printf("specifier s:\n");
	int r7 = ft_printf("ft_printf: \"%s\" \"%s\" \"%s\"\n", s1, s2, s3);
	ft_printf("(return = %d)\n", r7);
	int r8 = printf("printf   : \"%s\" \"%s\" \"%s\"\n", s1, s2, s3);
	ft_printf("(return = %d)\n\n", r8);

	ft_printf("specifier p:\n");
	int r9 = ft_printf("ft_printf: %p %p %p\n", s1, s2, s3);
	ft_printf("(return = %d)\n", r9);
	int r10 = printf("printf   : %p %p %p\n", s1, s2, s3);
	ft_printf("(return = %d)\n\n", r10);

	ft_printf("specifier x:\n");
	int r11 = ft_printf("ft_printf: %x %x %x %x\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n", r11);
	int r12 = printf("printf   : %x %x %x %x\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n\n", r12);

	ft_printf("specifier X:\n");
	int r13 = ft_printf("ft_printf: %X %X %X %X\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n", r13);
	int r14 = printf("printf   : %X %X %X %X\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n\n", r14);

	ft_printf("specifier u:\n");
	int r15 = ft_printf("ft_printf: %u %u %u %u\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n", r15);
	int r16 = printf("printf   : %u %u %u %u\n", n1, n2, n3, n4);
	ft_printf("(return = %d)\n", r16);

	return (0);
}*/
