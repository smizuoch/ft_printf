/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smizuoch <smizuoch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:33:14 by smizuoch          #+#    #+#             */
/*   Updated: 2023/06/14 18:52:36 by smizuoch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

void	ft_conversionlist(char str, va_list *ap, int *printf_len)
{
	if (str == 'c')
		ft_printchar(va_arg(*ap, int), printf_len);
	else if (str == 's')
		ft_printstring(va_arg(*ap, char *), printf_len);
	else if (str == 'p')
		ft_printvoid(va_arg(*ap, void *), printf_len);
	else if (str == 'd')
		ft_printnbr(va_arg(*ap, int), printf_len);
	else if (str == 'i')
		ft_printnbr(va_arg(*ap, int), printf_len);
	else if (str == 'u')
		ft_printnbru(va_arg(*ap, unsigned int), printf_len);
	else if (str == 'x')
		printnbr_hex(va_arg(*ap, unsigned int), printf_len);
	else if (str == 'X')
		printnbr_bighex(va_arg(*ap, unsigned int), printf_len);
	else if (str == '%')
		ft_printchar('%', printf_len);
}

int	ft_printf(const char *str, ...)
{
	size_t	n;
	int		printf_len;
	va_list	ap;

	printf_len = 0;
	n = 0;
	if (str == NULL)
		return (-1);
	va_start(ap, str);
	while (str[n] != '\0')
	{
		if (str[n] == '%')
		{
			n ++;
			ft_conversionlist(str[n], &ap, &printf_len);
		}
		else
			ft_printchar(str[n], &printf_len);
		if (printf_len == -1)
			return (-1);
		n ++;
	}
	va_end(ap);
	return (printf_len);
}
