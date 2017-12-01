/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:12:11 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/01 01:21:39 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

t_env   *new_env(void) {
  t_env   *env;
  if (!(env = (t_env *)malloc(sizeof(t_env))))
    return (NULL);
  env->mlx = mlx_init();
  env->window = mlx_new_window(env->mlx, _X_MAX, _Y_MAX, _PROG_NAME);
  env->a = 3.0;
  env->b = 12.0;
  env->c = 4.0;
  env->delta = 0.0;
  env->equation = "y = 3X^2 + 12X +4\0";
  return(env);
}

int   key_events(int keycode, t_env *env) {
    switch (keycode) {
      case _K_SPACE:
        mlx_loop(env->mlx);
        break;
      case _K_ESC:
        exit(0);
        break;
      default:
        break;
    }
    return (0);
}

int   polynomial(int x, double a, double b, double c) {
  return ((int)(a * (x * x) + (b * x) + c));
}


void  init_graph(t_env *env) {
  int i = 0;
  while (i <= _Y_MAX) {
    // if (i % 10 == 0) {
    //     mlx_pixel_put(env->mlx, env->window, _Y_MAX / 2 - 1, i, _C_GRAD);
    //     mlx_pixel_put(env->mlx, env->window, _Y_MAX / 2  - 2, i, _C_GRAD);
    //     mlx_pixel_put(env->mlx, env->window, _Y_MAX / 2  + 1, i, _C_GRAD);
    //     mlx_pixel_put(env->mlx, env->window, _Y_MAX / 2  + 2, i, _C_GRAD);
    //
    // }
    mlx_pixel_put(env->mlx, env->window, (_X_MAX / 2), i, _C_AXIS);
    i++;
  }
  i = 0;
  while (i <= _X_MAX) {
    // if (i % 10 == 0) {
    //     mlx_pixel_put(env->mlx, env->window, i, _X_MAX / 2 - 1, _C_GRAD);
    //     mlx_pixel_put(env->mlx, env->window, i, _X_MAX / 2 - 2, _C_GRAD);
    //     mlx_pixel_put(env->mlx, env->window, i, _X_MAX / 2 + 1, _C_GRAD);
    //     mlx_pixel_put(env->mlx, env->window, i, _X_MAX / 2 + 2, _C_GRAD);
    //
    // }
    mlx_pixel_put(env->mlx, env->window, i, (_Y_MAX / 2), _C_AXIS);
    i++;
  }
  i = 0;
  while (i <= _X_MAX / 2) {
    mlx_pixel_put(env->mlx, env->window, i + _X_MAX / 2, polynomial(i, env->a, env->b, env->c) / _P_ZOOM, _C_NEG);
    i++;
  }
  i = -_X_MAX / 2;
  while (i <= 0) {
    mlx_pixel_put(env->mlx, env->window, i + _X_MAX / 2, polynomial(i, env->a, env->b, env->c) / _P_ZOOM, _C_POS);
    i++;
  }
  mlx_string_put(env->mlx, env->window, 30, _Y_MAX - 30, _C_TXT, env->equation);
  return;
}
