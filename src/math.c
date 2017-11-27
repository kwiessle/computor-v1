/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:39:32 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/27 17:56:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"
#include <math.h>


double ft_sqrt(double n)
{
  double x = n;
  double y = 1;
  if (n < 0)
    return (_FAILURE);
  while(x - y > 0) {
    x = (x + y) / 2;
    y = n / x;
  }
  return (x);
}

double ft_double_abs(double n)
{
   if ( n < 0 ) {
      return (-n);
   }
   return (n);
}

double  get_discriminent(double a, double b, double c) {
  return (b * b - 4 * (a * c ));
}

double  natural_sqrt_root_1(double a, double b, double delta) {
  return ((-b + ft_sqrt(delta)) / (2 * a));
}

double  natural_sqrt_root_2(double a, double b, double delta) {
   return ((-b - ft_sqrt(delta)) / (2 * a));
}

double natural_sqrt_root_3(double a, double b) {
   return (-b / (2 * a));
}

char *complex_sqrt_root_1(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "-%g + %gi", b / (2 * a), ft_sqrt(-delta) / (2 * a));
  return (root);
}

char *complex_sqrt_root_2(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "-%g - %gi", b / (2 * a), ft_sqrt(-delta) / (2 * a));
  return (root);
}
