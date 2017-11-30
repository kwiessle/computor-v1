/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:12:11 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/30 18:27:47 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

t_env   *new_env(void) {
  t_env   *env;
  if (!(env = (t_env *)malloc(sizeof(t_env))))
    return (NULL);
  env->mlx = mlx_init();
  env->window = mlx_new_window(env->mlx, _X_MAX, _Y_MAX, _PROG_NAME);
  env->a = 0.0;
  env->b = 0.0;
  env->c = 0.0;
  env->delta = 0.0;
  return(env);
}
