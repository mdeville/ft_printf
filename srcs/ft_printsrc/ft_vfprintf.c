/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vfprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdeville <mdeville@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:33:17 by mdeville          #+#    #+#             */
/*   Updated: 2017/12/07 17:42:18 by mdeville         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vfprintf(const int fd, const char *format, va_list ap)
{
	size_t	i;
	size_t	cpt;
	va_list	cpy;
	t_token	token;

	va_copy(cpy, ap);
	if (!format)
		return (-1);
	i = 0;
	cpt = 0;
	while (format[i])
	{
		if (format[i] == '%' && (i += 1))
		{
			token = parse_token(format, &i, &cpy);
			cpt += print_token(fd, token, &cpy);
		}
		else
		{
			write(1, format + i++, 1);
			cpt += 1;
		}
	}
	va_end(cpy);
	return (cpt);
}
