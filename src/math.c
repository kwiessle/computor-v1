/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:39:32 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/23 23:48:19 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double  get_discriminent(double a, double b, double c) {
  return (b * b - 4 * (a * c ));
}

char  *natural_sqrt_root_1(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "%lf", ((-b + sqrt(delta)) / (2 * a)));
  return (root);
}

char  *natural_sqrt_root_2(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "%lf", ((-b - sqrt(delta)) / (2 * a)));
  return (root);
}

char  *natural_sqrt_root_3(double a, double b) {
  char  *root;
  asprintf(&root, "%lf", -b / (2 * a));
  return (root);
}

char *complex_sqrt_root_1(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "-%lf + %lfi", b / (2 * a), sqrt(-delta) / (2 * a));
  return (root);
}

char *complex_sqrt_root_2(double a, double b, double delta) {
  char  *root;
  asprintf(&root, "-%lf - %lfi", b / (2 * a), sqrt(-delta) / (2 * a));
  return (root);
}
