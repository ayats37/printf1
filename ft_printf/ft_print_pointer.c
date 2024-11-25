/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 02:59:43 by taya              #+#    #+#             */
/*   Updated: 2024/11/25 04:33:28 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_strrev(char *str)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = ft_strlen(str) - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

static char	*ft_cnv_dth_ptr(unsigned long long n)
{
	char				*str;
	unsigned int		i;
	unsigned long long	r;

	i = 0;
	str = calloc(19, sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	while (n > 0)
	{
		r = n % 16;
		if (r < 10)
			str[i++] = r + '0';
		else
			str[i++] = r + 'a' - 10;
		n = n / 16;
	}
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}

static int	ft_print_hex_ptr(unsigned long long n)
{
	char	*hex_str;
	int		i;

	i = 0;
	hex_str = ft_cnv_dth_ptr(n);
	while (hex_str[i])
	{
		ft_putchar(hex_str[i]);
		i++;
	}
	free(hex_str);
	return (i);
}

int	ft_print_pointer(void *pointer)
{
	int	count;
	int	res;

	count = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	count += 2;
	if (!pointer)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		count++;
	}
	else
	{
		res = ft_print_hex_ptr((unsigned long long)pointer);
		if (res == -1)
			return (-1);
		count += res;
	}
	return (count);
}
