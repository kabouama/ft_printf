/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_u.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/16 18:24:01 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 23:27:08 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

unsigned int		ft_putnbr_u(unsigned int n)
{
	if (n >= 10)
		ft_putnbr_u(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_nbrlen(n));
}

unsigned long long	ft_putnbr_uu(unsigned long long n)
{
	if (n >= 10)
		ft_putnbr_uu(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_nbrlen(n));
}

unsigned long		ft_putnbr_lu(unsigned long n)
{
	if (n >= 10)
		ft_putnbr_lu(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_nbrlen(n));
}

int					ft_putnbr_hu(unsigned short n)
{
	if (n >= 10)
		ft_putnbr_hu(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_nbrlen(n));
}

int					ft_putnbr_hhu(unsigned char n)
{
	if (n >= 10)
		ft_putnbr_hhu(n / 10);
	ft_putchar((n % 10) + '0');
	return (ft_nbrlen(n));
}
