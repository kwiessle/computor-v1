/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 18:12:11 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/19 13:49:35 by vquesnel         ###   ########.fr       */
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
	env->delta = 0;
	env->equation = NULL;
	return (env);
}

t_env   *init_env(double a, double b, double c) {
  t_env   *env;

  if (!(env = new_env()))
  		return (NULL);
  env->mlx = mlx_init();
  env->window = mlx_new_window(env->mlx, _X_MAX, _Y_MAX, _PROG_NAME);
  env->a = a;
  env->b = b;
  env->c = c;
  env->delta = (b * b - 4 * (a * c ));
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

float   polynomial(double x, double a, double b, double c) {
  return ((float)(a * (x * x) + (b * x) + c));
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
    draw_roots(env);
  draw_curve(env);

  return;
}


void  draw_roots(t_env *env) {
  int y = -10;

  if (env->a == 0) {
	  double x = -env->c / env->b;
	  while (y <= 10) {
		 mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x * _X_ZOOM), _Y_ORIGIN - y, _C_NEG);
		 y++;
	  }
  }
  else if (env->delta == 0) {
    double x = -(env->b) / (2 * env->a);
    while (y <= 10) {
      mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x * _X_ZOOM), _Y_ORIGIN - y, _C_NEG);
      y++;
    }
  }
  else if (env->delta > 0) {
    double x1 = -(env->b - ft_sqrt(env->delta)) / (2 * env->a);
    double x2 = -(env->b + ft_sqrt(env->delta)) / (2 * env->a);
    while (y <= 10) {
      mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x1 * _X_ZOOM), _Y_ORIGIN - y , _C_NEG);
      mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x2 * _X_ZOOM), _Y_ORIGIN - y , _C_NEG);
      y++;
    }
  }
}

void   draw_curve(t_env *env) {
  float x = -_X_ORIGIN;
  float y = 0;
  while (x <= _X_ORIGIN) {
    y = _Y_ORIGIN - (polynomial(x, env->a, env->b, env->c) * _Y_ZOOM);
    if (y >= 0 && y <= _Y_MAX ) {
      mlx_pixel_put(env->mlx, env->window, _X_ORIGIN + (x * _X_ZOOM), y, _C_POS);
    }
    x += 0.001;
  }
  return;
}
