/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:12:11 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/01 18:43:59 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

t_env   *new_env(double a, double b, double c) {
  char    *equation_str;
  t_env   *env;
  if (!(env = (t_env *)malloc(sizeof(t_env))))
    return (NULL);
  env->mlx = mlx_init();
  env->window = mlx_new_window(env->mlx, _X_MAX, _Y_MAX, _PROG_NAME);
  env->a = a;
  env->b = b;
  env->c = c;
  asprintf(&equation_str, "y = %gx^2 + %gx + %g", env->a, env->b, env->c);
  env->equation = equation_str;
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
  int x = 0, y = 0;
  while (y <= _Y_MAX) {
    mlx_pixel_put(env->mlx, env->window, (_Y_MAX / 2), y, _C_AXIS);
    y++;
  }
  while (x <= _X_MAX) {
    mlx_pixel_put(env->mlx, env->window, x, (_X_MAX / 2), _C_AXIS);
    x++;
  }
  mlx_string_put(env->mlx, env->window, 30, 30, _C_TXT, env->equation);
  draw_curve(env);
  return;
}

void   draw_curve(t_env *env) {
  int x = -_X_MAX / 2;
  int y = 0;
  while (x <= _X_MAX / 2) {
    y = _Y_ORIGIN + (polynomial(x, env->a, env->b, env->c) * _Y_ZOOM);
    if (y >= 0 && y <= _Y_MAX ) {
      mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x * _X_ZOOM), y, _C_NEG);
    }
    x++;
  }
  return;
}
