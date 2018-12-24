/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init_free_prm.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: kabouama <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/29 18:07:49 by kabouama     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/29 18:16:50 by kabouama    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_prm(t_param *prm)
{
	prm->i = 0;
	prm->len = 0;
	prm->var_type = 0;
	prm->size = 0;
}

void	init_prm2(t_param *prm)
{
	prm->test = 0;
	prm->temp = 0;
	prm->i = 0;
}

void	free_prm(t_param *prm, t_stock *begin)
{
	free_list(begin);
	free(prm->size);
	free(prm);
}
