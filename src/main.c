/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/24 11:47:22 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {
  double a = 9.3;
  double b = 4;
  double c = 4;
  double delta = get_discriminent(a,b,c);
  printf("C1: %s\n", complex_sqrt_root_1(a,b, delta));
  printf("C2: %s\n", complex_sqrt_root_2(a,b, delta));
  // printf("R3: %s\n", natural_sqrt_root_3(a,b));
  printf("DELTA : %lf\n", delta);
  if (ac != 2) {
    display_error(1);
    return (0);
  }
  if (check_argument(av[1]) == _FAILURE) {
      display_error(2);
      return (0);
  } else if (check_format(av[1]) == _FAILURE) {
      display_error(3);
      return (0);
  }

  return (0);
}
