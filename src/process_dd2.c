/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_dd2.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/26 23:01:26 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/03 18:47:15 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		affiche_plus(t_param *prm, long var)
{
	if ((prm->flags == '+' || prm->flags2 == '+') && var >= 0)
		ft_putchar('+');
}

void		affiche_var(t_param *prm, long var)
{
	if (prm->var_type == 80)
	{
		if (ft_putnbr_long(var) == 2018)
			prm->len += 19;
	}
	else if (prm->var_type == 81)
		ft_putnbr(var);
	else if (prm->var_type == 82)
	{
		if (ft_putnbr_ll(var) == 2018)
			prm->len += 19;
	}
	else if (prm->var_type == 83)
		ft_putnbr(var);
	else
		ft_putnbr(var);
}

void		check_width_d1(t_param *prm, long var, int wid)
{
	if (var < 0)
		wid--;
	if ((prm->flags == ' ' || prm->flags2 == ' ') && var >= 0)
	{
		wid--;
		prm->len++;
		ft_putchar(' ');
	}
	if (prm->type != 'f' && prm->type != 'F')
		wid -= prm->preci;
	while (wid > 0)
	{
		ft_putchar(' ');
		wid--;
		prm->len++;
	}
	if (prm->flags == '0' || prm->flags2 == '0')
		affiche_plus(prm, var);
}

void		check_width_d2(t_param *prm, long var, int wid)
{
	if (prm->flags == '0' || prm->flags2 == '0')
		affiche_plus(prm, var);
	if (prm->type != 'f' || prm->type != 'F')
		wid -= ft_nbrlen(var);
	if (var == 0 && prm->flags != '0' && prm->flags2 != '0' && prm->preci)
		wid++;
	if ((prm->flags == ' ' || prm->flags2 == ' ') && var >= 0)
	{
		ft_putchar(' ');
		wid--;
		prm->len++;
	}
	if ((prm->flags == '0' || prm->flags2 == '0') && !prm->preci && var < 0)
	{
		ft_putchar('-');
		prm->len++;
	}
	while (wid-- > 0)
	{
		if ((prm->flags == '0' || prm->flags2 == '0') && !prm->preci)
			ft_putchar('0');
		else
			ft_putchar(' ');
		prm->len++;
	}
}

void		check_width_d(t_param *prm, long var, float varf)
{
	int		wid;
	int		len_var;

	len_var = ft_nbrlen_lf(varf, prm);
	wid = prm->width;
	if (!prm->preci)
	{
		if (prm->type == 'f' || prm->type == 'F')
			wid -= 7;
	}
	else if ((prm->type == 'f' || prm->type == 'F') && prm->preci > 0)
	{
		wid -= prm->preci + 1;
		if (prm->preci > len_var)
			wid -= len_var;
	}
	if (prm->width)
	{
		if (prm->type == 'f' || prm->type == 'F')
			var = (long)varf;
		if (prm->preci && prm->preci >= ft_nbrlen(var))
			check_width_d1(prm, var, wid);
		else if (prm->width > ft_nbrlen(var))
			check_width_d2(prm, var, wid);
	}
}
