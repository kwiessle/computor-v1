/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 13:55:13 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/20 15:32:43 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void      print_discriminent(double a, double b, double c) {
  printf("To calculate the discriminent you need to resolve\n\n");
  printf("\e[1;38;5;130mΔ = b^2 - 4 * a * c\e[0m\n\n");
  printf("Where a, b, c are respectively the coefficent of the degree 2, 1, 0 so:\n\n");
  printf("Δ = %g^2 - 4 * %g * %g\n", b, a, c);
  printf("Δ = %g^2 - %g\n", b, 4 * a * c);
  printf("Δ = %g - %g\n", b * b, 4 * a * c);
  printf("\e[1;38;5;82;4mΔ = %g\e[0m\n\n", b * b - 4 * (a * c));
}

void      print_natural_sqrt(double a, double b, double delta, char sign) {
  double dividend = sign == '+' ? -b + ft_sqrt(delta) : -b - ft_sqrt(delta);
  double divisor = 2 * a;

  printf("\e[1;38;5;130mX%c = (-b %c √Δ) / (2 * a)\e[0m\n", sign == '+' ? '1' : '2', sign);
  printf("X%c = (-(%g) %c √%g) / (2 * (%g))\n", sign == '+' ? '1' : '2', b, sign, delta, a);
  printf("X%c = (-(%g) %c %g) / %g\n", sign == '+' ? '1' : '2', b, sign, ft_sqrt(delta), divisor);
  printf("X%c =  %g / %g\n", sign == '+' ? '1' : '2',dividend, divisor);
}

void      print_one_sqrt(double a, double b){
  printf("Δ is equal to zero, the unique solution is:\n\n");
  printf("\e[1;38;5;130mX1 = -b / (2 * a)\e[0m\n");
  printf("X1 = -(%g) / (2 * (%g))\n", b, a);
  printf("X1 = %g / %g\n", -b, 2 * a);
}

void      print_complex_sqrt(double a, double b, double delta, char sign){
  printf("\e[1;38;5;130mX%c = (-b %c i√(-Δ)) / (2 * a)\e[0m\n", sign == '+' ? '1' : '2', sign);
  printf("X%c = (-(%g) %c i√-(%g)) / (2 * (%g))\n", sign == '+' ? '1' : '2', b, sign, delta, a);
  printf("X%c = (-(%g) %c %gi) / %g\n", sign == '+' ? '1' : '2', b, sign, ft_sqrt(-delta), 2 * a);
  printf("X%c =  %g / %g %c %gi/%g\n", sign == '+' ? '1' : '2', -b, 2 * a, sign,  ft_sqrt(-delta), 2 * a);
}

void      print_reduced_form(int max_pow, double *coefs) {
  int tmp_pow = max_pow;
  if( coefs[max_pow] == 0) {
    return;
  }
  printf("The reduced form is:\n\n");
  while ( tmp_pow >= 0 ) {
    if (coefs[tmp_pow] != 0) {
      switch (tmp_pow) {
        case 0:
          printf(
            "\e[1;38;5;82;4m%c %g ",
            coefs[tmp_pow] < 0 ? 45 : 43,
            ft_double_abs(coefs[tmp_pow])
          );
          break;
        case 1:
          printf(
            "\e[1;38;5;82;4m%c %g * X ",
            coefs[tmp_pow] < 0 ? 45 : 43,
            ft_double_abs(coefs[tmp_pow])
          );
          break;
        default:
          printf(
            "\e[1;38;5;82;4m%c %g * X^%d ",
            coefs[tmp_pow] < 0 ? 45 : 43,
            ft_double_abs(coefs[tmp_pow]),
            tmp_pow
          );
      }
    }
    tmp_pow--;
  }
  printf("= 0\e[0m\n\n");
  printf("Polynomial degree: \e[1;38;5;82;4m%d\e[0m\n\n", max_pow);
}

int      print_exceptions(int max_pow, double *coefs) {
  printf("Values of a, b and c are:\n\n");
  if (max_pow >= 3) {
      printf("\e[1;38;5;82;4ma = %g\tb = %g\tc = %g\e[0m\n\n", coefs[2], coefs[1], coefs[0]);
      printf("\e[1;38;5;160;4mThe polynomial degree is stricly greater than 2, I can't solve.\e[0m\n");
      return -5;
  }
  if (max_pow == 0 ) {
      printf("\e[1;38;5;82;4ma = 0\tb = 0\tc = %g\e[0m\n\n",coefs[max_pow]);
      coefs[max_pow] != 0 ?
        printf("b = 0 and c != 0 so:\n\n\e[1;38;5;160;4mThis isnt't a valid equation\e[0m\n") :
        printf("b = 0 and c = 0 so:\n\n\e[1;38;5;82;4mAll numbers are solution\e[0m\n");
      return -4;
  }
  // if (max_pow == 1 && coefs[1] == 0) {
    // printf("\e[1;38;5;82;4ma = 0\tb = %g\tc = %g\e[0m\n\n", coefs[1], coefs[0]);
//
      // return -3;
  // }
  if (coefs[2] == 0 || max_pow == 1) {
    printf("\e[1;38;5;82;4ma = 0\tb = %g\tc = %g\e[0m\n\n", coefs[1], coefs[0]);
    printf("a = 0, The unique solution is:\n\n");
    printf("\e[1;38;5;130mX1 = -c / b\e[0m\n");
    double divide = -coefs[0] / coefs[1];
    double _pgcd = ft_double_abs(pgcd((int)coefs[0], (int)coefs[1]));
    printf("X1 = - (%g) / %g\n", coefs[0], coefs[1]);
    -coefs[0] != (int)-coefs[0] || divide == (int)(divide) ?
      printf("\e[1;38;5;82;4mX1 = %g\e[0m\n", divide) :
      printf("\e[1;38;5;82;4mX1 = %s%g/%g\e[0m\n", divide < 0 ? "- " : "",
        ft_double_abs(-coefs[0] / _pgcd),
        ft_double_abs(coefs[1] / _pgcd));
    return -2;
  }
  printf("\e[1;38;5;82;4ma = %g\tb = %g\tc = %g\e[0m\n\n", coefs[2], coefs[1], coefs[0]);
  return _SUCCESS;
}

void      print_solutions(double *coefs) {
  double delta = get_discriminent(coefs[2], coefs[1], coefs[0]);
  if (delta > 0) {
    printf("Δ is strictly positive, the two solutions are:\n\n");
    char *X1 = natural_sqrt_root(coefs[2], coefs[1], delta, '+');
    printf("\e[1;38;5;82;4mX1 = %s\e[0m\n\n", X1);
    char *X2 = natural_sqrt_root(coefs[2], coefs[1], delta, '-');
    printf("\e[1;38;5;82;4mX2 = %s\e[0m\n\n", X2);
    printf("The equation of the curve is:\n\n\e[1;38;5;82;4mf(x) = %g * (x - (%s)) * (x - (%s))\e[0m\n", coefs[2], X1, X2);
    free(X1);
    free(X2);
  }
  else if (delta == 0) {
    char *X1 = natural_sqrt_root_3(coefs[2],coefs[1]);
    printf("\e[1;38;5;82;4mX1 = %s\e[0m\n\n", X1);
    printf("The equation of the curve is:\n\n\e[1;38;5;82;4mf(x) = %g * (x - (%s))^2\e[0m\n", coefs[2], X1);
    free(X1);
  }
  else {
    printf("Δ is strictly negative, the two solutions are:\n\n");
    char *X1= complex_sqrt_root(coefs[2],coefs[1], delta, '+');
    printf("\e[1;38;5;82;4mX1 = %s\e[0m\n\n", X1);
    char *X2= complex_sqrt_root(coefs[2],coefs[1], delta, '-');
    printf("\e[1;38;5;82;4mX2 = %s\e[0m\n\n", X2);
    printf("The equation of the curve is:\n\n\e[1;38;5;82;4mf(x) = %g * (x - (%s)) * (x - (%s))\e[0m\n", coefs[2], X1, X2);
    free(X1);
    free(X2);
  }
}
