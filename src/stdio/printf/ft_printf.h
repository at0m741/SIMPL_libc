/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: babonnet <babonnet@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:06:35 by bbonnet           #+#    #+#             */
/*   Updated: 2024/09/26 19:08:50 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdint.h>

int ft_printf(const char *format, ...);

void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putnbr_base(unsigned long n, char *base, unsigned long base_size,
                    int *count);
void ft_putnbr_count(int n, int *count);
size_t ft_strlen(const char *str);
int manage_char(va_list var, const char type);
int print_pointer(unsigned long pointer);
int display_wrong_flag(char c);
void	ft_putsizet(size_t n);

#endif
