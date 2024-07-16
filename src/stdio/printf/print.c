/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:39:47 by babonnet          #+#    #+#             */
/*   Updated: 2024/07/16 18:14:23 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

void ft_putnbr_base(unsigned long n, char *base, unsigned long base_size, int *count)
{
	if (n >= base_size)
	{
		ft_putnbr_base(n / base_size, base, base_size, count);
		ft_putnbr_base(n % base_size, base, base_size, count);
	}
	else
    {
        ft_putchar_fd(base[n], 1);
        (*count)++;
    }
}

void	ft_putnbr_count(int n, int *count)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", 1);
		(*count) += 11; 
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		(*count)++;
		n = -n;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + '0', 1);
		(*count)++;
		return ;
	}
	ft_putnbr_count(n / 10, count);
	ft_putnbr_count(n % 10, count);
}

int print_pointer(unsigned long pointer)
{
	int count;

	count = 0;
	if (pointer == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
    count += 2;
	ft_putnbr_base(pointer, "0123456789abcdef", 16, &count);
	return (count);
}

int manage_char(va_list var, const char type)
{
	char *str;

	if (type == 'c')
	{
		ft_putchar_fd((char) va_arg(var, int), 1);
		return (1);
	}
	str = NULL;
	str = va_arg(var, char *);
	if (str == NULL)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int display_wrong_flag(char c)
{
    write(1, "%", 1);
    write(1, &c, 1);
    return (2);
}
