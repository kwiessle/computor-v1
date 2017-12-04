/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/04 11:47:31 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {
  t_env *env;
  (void)ac;
  if (check_format(av[1]) == _FAILURE) {
      display_error(3);
      return (0);
  } else {
    char *equation_trimed = super_trim(av[1]);
    int max_pow = get_max_pow(equation_trimed);
    int tmp_pow = max_pow;
    double *coefs;

    if ( !(coefs = (double *)malloc(max_pow * sizeof(double))) ) {
      return (_FAILURE);
    }
    while ( tmp_pow >= 0 ) {
      coefs[tmp_pow] = get_coeff(equation_trimed, tmp_pow);
      tmp_pow--;
    }
    while (max_pow > 0 && coefs[max_pow] == 0) {
      max_pow--;
    }
    print_reduced_form(max_pow, coefs);
    print_solutions(coefs);
    if (av[2] && av[2] && ft_strcmp(av[2], "--grapher") == 0) {
      env = new_env(coefs[2], coefs[1], coefs[0]);
      init_graph(env);
      mlx_hook(env->window, 2, 3, key_events, env);
      mlx_loop(env->mlx);
    } else {
      display_error(4);
      exit(0);
    }
  }

  return (0);
}
