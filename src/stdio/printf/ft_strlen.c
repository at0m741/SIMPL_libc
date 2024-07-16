/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonnet <bbonnet@42angouleme.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:33:17 by bbonnet           #+#    #+#             */
/*   Updated: 2024/07/16 18:07:58 by babonnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

size_t	ft_strlen(const char *str)
{
	const char	*start;

	start = str;
	while (*start)
		++start;
	return (start - str);
}
