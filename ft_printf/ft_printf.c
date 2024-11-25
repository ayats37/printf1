/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:19:52 by taya              #+#    #+#             */
/*   Updated: 2024/11/25 04:16:19 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_input(const char input, va_list *args)
{
	int	i;

	i = 0;
	if (input == 'c')
		i += ft_print_char(va_arg(*args, int));
	else if (input == 'd' || input == 'i')
		i += ft_print_int(va_arg(*args, int));
	else if (input == 'u')
		i += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (input == 's')
		i += ft_print_string(va_arg(*args, char *));
	else if (input == 'p')
		i += ft_print_pointer(va_arg(*args, void *));
	else if (input == 'x')
		i += ft_print_hex(va_arg(*args, unsigned int), 0);
	else if (input == 'X')
		i += ft_print_hex(va_arg(*args, unsigned int), 1);
	else if (input == '%')
		i += ft_print_percent();
	return (i);
}

int	ft_process_of_ft_printf(const char *str_input, int *i, va_list *args,
		int *count)
{
	int	res;

	if (str_input[*i] == '%')
	{
		if (str_input[*i + 1])
		{
			res = ft_check_input(str_input[*i + 1], args);
			if (res == -1)
				return (-1);
			*count += res;
			(*i)++;
		}
	}
	else
	{
		if (ft_print_char(str_input[*i]) == -1)
			return (-1);
		(*count)++;
	}
	return (0);
}

int	ft_printf(const char *str_input, ...)
{
	int		i;
	int		count;
	va_list	args;

	i = 0;
	count = 0;
	va_start(args, str_input);
	while (str_input[i])
	{
		if (ft_process_of_ft_printf(str_input, &i, &args, &count) == -1)
			return (va_end(args), -1);
		i++;
	}
	return (va_end(args), count);
}
