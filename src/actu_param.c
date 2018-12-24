/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   actu_param.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/14 19:40:44 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/05 22:49:06 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_param		*actu_width(t_param *prm, t_stock *stck)
{
	if (stck->str[prm->i] >= '1' && stck->str[prm->i] <= '9')
		prm->width = char_atoi(stck, prm);
	else
		prm->width = 0;
	return (prm);
}

t_param		*actu_precision(t_param *prm, t_stock *stck)
{
	if (stck->str[prm->i] == '.')
	{
		prm->i++;
		if (stck->str[prm->i] >= '0' && stck->str[prm->i] <= '9')
			prm->preci = char_atoi(stck, prm);
		else
			prm->preci = -5;
	}
	else
		prm->preci = 0;
	return (prm);
}

void		actu_size(t_param *prm, t_stock *stck)
{
	int		i;

	i = 0;
	prm->size = NULL;
	if (stck->str[prm->i] == 'h' && stck->str[prm->i + 1] != 'h')
	{
		prm->size = ft_strdup("h");
		prm->i++;
	}
	if (stck->str[prm->i] == 'h' && stck->str[prm->i + 1] == 'h')
	{
		prm->size = ft_strdup("hh");
		prm->i += 2;
	}
	if (stck->str[prm->i] == 'l' && stck->str[prm->i + 1] != 'l')
	{
		prm->size = ft_strdup("l");
		prm->i++;
	}
	if (stck->str[prm->i] == 'L'
			&& (stck->str[prm->i + 1] == 'f' || stck->str[prm->i + 1] == 'F'))
	{
		prm->size = ft_strdup("L");
		prm->i++;
	}
}

t_param		*actu_size2(t_param *prm, t_stock *stck)
{
	int		i;

	i = 0;
	prm->size = NULL;
	actu_size(prm, stck);
	if (stck->str[prm->i] == 'l' && stck->str[prm->i + 1] == 'l')
	{
		prm->size = ft_strdup("ll");
		prm->i += 2;
	}
	if (stck->str[prm->i] == 'z')
	{
		prm->size = ft_strdup("z");
		prm->i++;
	}
	if (stck->str[prm->i] == 'j')
	{
		prm->size = ft_strdup("j");
		prm->i++;
	}
	return (prm);
}

t_param		*actu_param(t_param *prm, t_stock *stck)
{
	actu_flags(prm, stck);
	actu_width(prm, stck);
	actu_precision(prm, stck);
	actu_size2(prm, stck);
	prm->type = stck->str[prm->i];
	return (prm);
}
