/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtortrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:27:40 by mtortrot          #+#    #+#             */
/*   Updated: 2023/11/14 17:27:46 by mtortrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_define_args(char c, va_list ap, int *n)
{
	if (c == 'c')
		return (ft_putchar(va_arg(ap, int), n));
	if (c == 's' )
		return (ft_putstr(va_arg(ap, char *), n));
	if (c == 'p')
		return (ft_putptr(va_arg(ap, unsigned long int), n));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(ap, int), n, 0));
	if (c == 'u')
		return (ft_putnbr(va_arg(ap, unsigned int), n, 1));
	if (c == 'x')
		return (ft_puthexa(va_arg(ap, unsigned int), n, 0));
	if (c == 'X')
		return (ft_puthexa(va_arg(ap, unsigned int), n, 1));
	return ;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		n;
	va_list	ap;

	if (!str)
		return (-1);
	i = 0;
	n = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] != '%')
			ft_putchar(str[i++], &n);
		else
		{
			if (str[i] == '%' && str[i + 1] == '%')
				ft_putchar(str[i], &n);
			else
				ft_define_args(str[i + 1], ap, &n);
			i += 2;
		}
	}
	va_end(ap);
	return (n);
}
