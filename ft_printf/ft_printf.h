/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taya <taya@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 21:19:54 by taya              #+#    #+#             */
/*   Updated: 2024/11/22 03:33:43 by taya             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
int		ft_print_char(char c);
int		ft_print_string(char *str);
int		ft_print_percent(void);
int		ft_print_int(int n);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, int upper_or_lower);
int		ft_print_pointer(void *pointer);
int		ft_printf(const char *str_input, ...);
void	ft_putunbr(unsigned int n);
void	ft_putnbr(int n);
void	ft_strrev(char *str);
int	ft_strlen(const char *str);

#endif
