/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckojima- <ckojima-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:44:07 by ckojima-          #+#    #+#             */
/*   Updated: 2022/12/17 16:47:40 by ckojima-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthexa(unsigned int nb, char *base);
int	ft_putnb(int nb);
int	ft_putptr(unsigned long int ptr, char *base);
int	ft_putu(unsigned int nb);

int	ft_printf(const char *str, ...);

#endif