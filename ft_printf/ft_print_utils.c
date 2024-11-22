/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 14:47:04 by taya              #+#    #+#             */
/*   Updated: 2024/11/22 03:33:34 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n >= 0 && n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void	ft_putunbr(unsigned int n)
{
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putunbr(n / 10);
		ft_putunbr(n % 10);
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return;
	while (str[i])
	{
		i++;
	}
	i--;
	while (j < i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
