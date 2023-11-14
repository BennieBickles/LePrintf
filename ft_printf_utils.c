/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtortrot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:28:12 by mtortrot          #+#    #+#             */
/*   Updated: 2023/11/14 17:30:08 by mtortrot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *n)
{
	write(1, &c, 1);
	*n += 1;
}

void	ft_putstr(char *str, int *n)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", n);
		return ;
	}
	while (str[i])
		write(1, &str[i++], 1);
	*n = *n + i;
}

void	ft_putnbr(long long int nb, int *n, int is_unsign)
{
	if (!is_unsign && nb < 0)
	{
		ft_putchar('-', n);
		nb *= -1;
	}
	if (nb <= 9)
	{
		ft_putchar(nb + '0', n);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, n, is_unsign);
		ft_putchar(nb % 10 + '0', n);
	}
}

void	ft_puthexa(unsigned long long int nb, int *n, int c)
{
	char	*base;

	if (c == 0)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nb <= 15)
		ft_putchar((base[0 + nb]), n);
	if (nb > 15)
	{
		ft_puthexa(nb / 16, n, c);
		ft_putchar((base[0 + nb % 16]), n);
	}
}

void	ft_putptr(unsigned long int ptr, int *n)
{
	if (ptr == 0)
		return (ft_putstr("(nil)", n));
	ft_putstr("0x", n);
	ft_puthexa(ptr, n, 0);
}
