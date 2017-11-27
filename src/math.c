/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:39:32 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/25 18:40:52 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"


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

double  get_discriminent(double a, double b, double c) {
  return (b * b - 4 * (a * c ));
}

char  *natural_sqrt_root_1(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "%lf", ((-b + ft_sqrt(delta)) / (2 * a)));
  return (root);
}

char  *natural_sqrt_root_2(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "%lf", ((-b - ft_sqrt(delta)) / (2 * a)));
  return (root);
}

char  *natural_sqrt_root_3(double a, double b) {
  char  *root;
  asprintf(&root, "%lf", -b / (2 * a));
  return (root);
}

char *complex_sqrt_root_1(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "-%lf + %lfi", b / (2 * a), ft_sqrt(-delta) / (2 * a));
  return (root);
}

char *complex_sqrt_root_2(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "-%lf - %lfi", b / (2 * a), ft_sqrt(-delta) / (2 * a));
  return (root);
}
