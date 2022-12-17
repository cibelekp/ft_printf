/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 14:16:15 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/17 16:51:28 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int i;

	i = -1;
	if (s == NULL)
		s = "(null)";
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	ft_puthexa(unsigned int nb, char *base)
{
	int len;

	len = 0;
	if (nb >= 16)
		len += ft_puthexa(nb / 16, base);
	len += ft_putchar(base[nb % 16]);
	return (len);
}

int	ft_putu(unsigned int nb)
{
	int len;

	len = 0;
	if (nb >= 10)
		len += ft_putnb(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_putnb(int nb)
{
	int len;

	len = 0;
	if (nb == INT_MIN)
		return (ft_putstr("-2147483648"));
	if (nb < 0)
	{
		len += ft_putchar('-');
		nb *= -1;
	}
	if (nb >= 10)
		len += ft_putnb(nb / 10);
	len += ft_putchar(nb % 10 + '0');
	return (len);
}

int	ft_putptr(unsigned long int ptr, char *base)
{
	int len;

	len = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	if (ptr >= 16)
		len += ft_puthexa(ptr / 16, base);
	len += ft_putchar(base[ptr % 16]);
	return (len);
}