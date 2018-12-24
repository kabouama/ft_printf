/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   process_s.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/21 20:18:36 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/27 23:28:17 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*flags_neg(t_param *prm, char *var, char *str, int len)
{
	if (prm->flags == '-' || prm->flags2 == '-')
	{
		if (!prm->preci && var != NULL)
		{
			ft_putstr(var);
			prm->len += len;
		}
		else if (!prm->preci && var == NULL)
		{
			ft_putstr(str);
			prm->len += 6;
			prm->width -= 6;
		}
		if (var != NULL && !prm->preci)
			prm->width -= len;
		while (prm->width > 0 && !prm->preci)
		{
			ft_putchar(' ');
			prm->width--;
			prm->len++;
			prm->j++;
		}
	}
	return (var);
}

char		*no_preci_s(t_param *prm, char *var, int len)
{
	if (var == NULL)
		prm->width -= 6;
	if (var != NULL)
		prm->width -= len;
	while (prm->width > 0)
	{
		ft_putchar(' ');
		prm->width--;
		prm->len++;
		prm->j++;
	}
	return (var);
}

char		*check_width_s(t_param *prm, char *var)
{
	int		len;
	char	*str;

	str = "(null)";
	if (var != NULL)
		len = ft_strlen(var);
	if (prm->width && ((prm->flags != '0' && prm->flags2 != '0') || prm->preci))
	{
		flags_neg(prm, var, str, len);
		if (!prm->preci)
			no_preci_s(prm, var, len);
		else if (prm->preci)
		{
			if (prm->width > prm->preci && prm->preci != -5 && prm->preci < len)
				prm->width -= prm->preci;
			else if (prm->preci != -5)
				prm->width -= len;
			affiche_space(prm);
		}
	}
	return (var);
}

char		*check_preci_s(t_param *prm, char *var)
{
	int		i;
	int		len;
	char	*str;

	str = "(null)";
	i = 0;
	prm->preci2 = prm->preci;
	if (var != NULL)
		len = ft_strlen(var);
	if (prm->preci && prm->preci != -15)
	{
		while (prm->preci > 0 && i < len)
		{
			if (var == NULL)
				ft_putchar(str[i]);
			else
				ft_putchar(var[i]);
			i++;
			prm->len++;
			prm->preci--;
		}
		prm->preci = -15;
	}
	prm->preci = prm->preci2;
	return (var);
}

char		*process_s(t_param *prm, char *var)
{
	if (prm->flags == '-' || prm->flags2 == '-')
		var = check_preci_s(prm, var);
	var = check_width_s(prm, var);
	if (prm->flags != '-' && prm->flags2 != '-')
		var = check_preci_s(prm, var);
	if (!(prm->preci < 0 && var == 0)
			&& prm->flags != '-' && prm->flags2 != '-' && !prm->preci)
	{
		if (var != NULL)
		{
			ft_putstr(var);
			prm->len += ft_strlen(var);
		}
		else
		{
			ft_putstr("(null)");
			prm->len += 6;
		}
	}
	return (var);
}
