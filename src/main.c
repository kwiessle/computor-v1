/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/25 16:22:18 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {

  if (ac != 2) {
    display_error(1);
    return (0);
  }
  if (check_argument(av[1]) == _FAILURE) {
      display_error(2);
      return (0);
  }
  if (check_format(av[1]) == _FAILURE) {
      display_error(3);
      return (0);
  } else {
    double a = get_coeff(super_trim(av[1]), '2');
    double b = get_coeff(super_trim(av[1]), '1');
    double c = get_coeff(super_trim(av[1]), '0');
    printf("a = %lf\nb = %lf\nc = %lf\n", a, b, c);
    double delta = get_discriminent(a,b,c);
    if (delta > 0) {
      printf("Solution 1: %s\n", natural_sqrt_root_1(a,b, delta));
      printf("Solution 2: %s\n", natural_sqrt_root_2(a,b, delta));
    } else if (delta == 0) {
      printf("Solution 1: %s\n", natural_sqrt_root_3(a,b));
    } else {
      printf("Solution 1: %s\n", complex_sqrt_root_1(a,b, delta));
      printf("Solution 2: %s\n", complex_sqrt_root_2(a,b, delta));
    }

  }

  return (0);
}
