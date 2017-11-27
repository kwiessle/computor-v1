/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:40:23 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/27 17:56:46 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

>>>>>>> submodules
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int  main(int ac, char **av) {

  if (ac != 2) {
    display_error(1);
    return (0);
  }

  // if (check_argument(av[1]) == _FAILURE) {

  //     display_error(2);
  //     return (0);
  // }
  // if (check_format(av[1]) == _FAILURE) {
  //     display_error(3);
  //     return (0);
  // } else {
    double a = get_coeff(super_trim(av[1]), '2');
    double b = get_coeff(super_trim(av[1]), '1');
    double c = get_coeff(super_trim(av[1]), '0');
    double d = get_coeff(super_trim(av[1]), '3');
    if (d != 0 ) {
      printf("Reduced form: %g * X^3 %c %g * X^2 %c %g * X^1 %c %g * X^0 = 0\n",
      c, a < 0 ? 45 : 43, ft_double_abs(a), b < 0 ? 45 : 43, ft_double_abs(b), c < 0 ? 45: 43,  ft_double_abs(c));
      printf("Polynomial degree: %d\n", 3);
      printf("The polynomial degree is stricly greater than 2, I can't solve.");
      return (0);
    }
    printf("Reduced form: %g * X^2 %c %g * X^1 %c %g * X^0 = 0\n",
     a, b < 0 ? 45 : 43,  ft_double_abs(b), c < 0 ? 45: 43,  ft_double_abs(c));
    printf("Polynomial degree: %d\n", a == 0 ? b == 0 ? 0 : 1 : 2);
    if ( a == 0 && c == 0 && b == 0) {
      printf("All numbers are solution\n");
      return (0);
    }
    if ( a == 0 ) {
      printf("The solution is:\n %g\n", -c / b);
      return (0);
   }

    double delta = get_discriminent(a,b,c);
    if (delta > 0) {
      printf("Δ = %g is strictly positive, the two solutions are:\n", delta);
      printf("X1: %g\n", natural_sqrt_root_1(a,b, delta));
      printf("X2: %g\n", natural_sqrt_root_2(a,b, delta));
    } else if (delta == 0) {
      printf("Δ = %g is equal to zero, the unique solution is:\n", delta);
      printf("X1: %g\n", natural_sqrt_root_3(a,b));
    } else {
      printf("Δ = %g is strictly negative, the two solutions are:\n", delta);
      printf("X1: %s\n", complex_sqrt_root_1(a,b, delta));
      printf("X2: %s\n", complex_sqrt_root_2(a,b, delta));
    }
  }
  return (0);
}
