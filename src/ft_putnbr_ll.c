/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_ll.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 22:11:12 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 18:00:00 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	ft_putnbr_long(long long n)
{
	if (n - 1 == 9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		return (2018);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_long(n / 10);
		ft_putchar((n % 10) + '0');
	}
	return (ft_nbrlen(n));
}

long long	ft_putnbr_ll(long long n)
{
	if (n - 1 == 9223372036854775807)
	{
		ft_putstr("-9223372036854775808");
		return (2018);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n >= 10)
			ft_putnbr_ll(n / 10);
		ft_putchar((n % 10) + '0');
	}
	return (ft_nbrlen(n));
}

long long	ft_putnbr_lf(long double n, t_float *flt)
{
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_lf(n / 10, flt);
	flt->tmp++;
	if (!(((long long)n % 10) >= 0 && ((long long)n % 10) <= 10))
		ft_putnbr(0);
	else
		ft_putchar(((long long)(n) % 10) + '0');
	return (flt->tmp);
}

int			ft_nbrlen_lf(long double n, t_param *prm)
{
	if (n < 0)
		n *= -1;
	if (n >= 10)
	{
		ft_nbrlen_lf(n / 10, prm);
		prm->flt++;
	}
	else
		prm->flt++;
	return (prm->flt);
}
