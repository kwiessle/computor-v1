/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:12:11 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/04 16:46:50 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static t_env	*new_env(void){
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = NULL;
	env->window = NULL;
	env->a = 0;
	env->b = 0;
	env->c = 0;
	env->equation = NULL;
	return (env);
}

t_env   *init_env(double a, double b, double c) {
  t_env   *env;

  if (!(env = new_env()))
  		return (NULL);
  env->mlx = mlx_init();
  env->window = mlx_new_window(env->mlx, _X_MAX, _Y_MAX, _PROG_NAME);
  env->a = a / _P_ITER;
  env->b = b / _P_ITER;
  env->c = c / _P_ITER;
  asprintf(&env->equation, "y = %gx^2 + %gx + %g",a ,b, c);
  return(env);
}

int   key_events(int keycode, t_env *env) {
  (void)env;
    switch (keycode) {
      case _K_ESC:
        exit(0);
        break;
      default:
        break;
    }
    return (0);
}

long long   polynomial(int x, double a, double b, double c) {
  return ((long long)(a * (x * x) + (b * x) + c));
}


void  init_graph(t_env *env) {
  int x = 0, y = 0;
  while (y <= _Y_MAX) {
    mlx_pixel_put(env->mlx, env->window, _Y_ORIGIN, y, _C_AXIS);
    y++;
  }
  while (x <= _X_MAX) {
    mlx_pixel_put(env->mlx, env->window, x, _X_ORIGIN, _C_AXIS);
    x++;
  }
  mlx_string_put(env->mlx, env->window, 30, 30, _C_TXT, env->equation);
  draw_curve(env);
  return;
}

void   draw_curve(t_env *env) {
  int x = -_X_ORIGIN;
  int y = 0;
  while (x <= _X_ORIGIN) {
    y = _Y_ORIGIN - (polynomial(x, env->a, env->b, env->c) * _Y_ZOOM);
    if (y >= 0 && y <= _Y_MAX ) {
      mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x * _X_ZOOM), y, _C_NEG);
      if (y == _Y_ORIGIN) {
        mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x * _X_ZOOM), y, _C_POS);
      }
    }
    x++;
  }
  return;
}