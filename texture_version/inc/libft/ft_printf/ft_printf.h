/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjesus-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:34:32 by rjesus-d          #+#    #+#             */
/*   Updated: 2024/11/18 18:26:48 by rjesus-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_print_char(char c, int *len);
void	ft_print_str(char *s, int *len);
void	ft_print_int(int number, int *len);
void	ft_print_unsigned_int(unsigned int u, int *len);
void	ft_print_hex(unsigned int number, int *len, char case_type);
void	ft_print_pointer(void *pointer, int *len);

#endif
