/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 21:39:32 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/19 11:22:05 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double pgcd(int nb1, int nb2)
{
  if (nb2 == 0)
  {
    return nb1;
  }
  return pgcd(nb2, nb1 % nb2);
}

double	ft_sqrt(double x)
{
	double	root;
	int		i;

	i = -1;
	root = x / 2;
	while (++i < 10)
	{
		root = (((x / root) + root) / 2);
	}
	return (root);
}

double ft_double_abs(double n)
{
    return n < 0 ? -n : n;
}

double  get_discriminent(double a, double b, double c) {
  print_discriminent(a, b, c);
  return (b * b - 4 * (a * c ));
}

char  *natural_sqrt_root(double a, double b, double delta, char sign) {
  if (a < 0 ) {
    a *= -1;
    b *= -1;
  }
  char  *root;
  double dividend = sign == '+' ? -b + ft_sqrt(delta) : -b - ft_sqrt(delta);
  double divisor = 2 * a;
  double _pgcd = ft_double_abs(pgcd((int)(dividend), (int)(divisor)));
  if ( a != (int)a || dividend != (int)dividend ||
  dividend / divisor == (int)(dividend / divisor)) {
    asprintf(&root, "%g", (dividend) / divisor);
  }
  else {
    asprintf(&root, "%g/%g", dividend / _pgcd, divisor / _pgcd);
  }
  print_natural_sqrt(a, b, delta, sign);
  return (root);
}

char  *natural_sqrt_root_3(double a, double b) {
  char  *root;
  double _pgcd = ft_double_abs(pgcd((int)(-b), (int)(2 * a)));
  if ( a != (int)(a) || -b != (int)(-b) || -b / (2 * a) == (int)(-b / (2 * a))) {
    asprintf(&root, "%g", -b / (2 * a));
  }
  else {
    asprintf(&root, "%g/%g", -b / _pgcd, (2 * a) / _pgcd);
  }
  print_one_sqrt(a, b);
  return root;
}

static char *complex_sqrt_R(double a, double b) {
  char *real;
  double _pgcd = pgcd((int)b, (int)(2 * a));
  if ( a != (int)a || -b != (int)-b ||  -b / (2 * a) == (int)(-b / (2 * a)) ) {
    asprintf(&real, "%g", -b / (2 * a));
  }
  else {
    asprintf(&real, "%g/%g", (2 * a) / _pgcd  <0 ? -(-b / _pgcd) : -b / _pgcd, ft_double_abs((2 * a) / _pgcd));
  }
  return real;
}

static char *complex_sqrt_I(double a, double sqrt_delta, char sign) {
  char *ireal;
  double divide = sqrt_delta / (2 * a);
  double _pgcd = ft_double_abs(pgcd((int)sqrt_delta, (int)(2 * a)));
  if (a != (int)a || sqrt_delta != (int)sqrt_delta || divide == (int)divide) {
    asprintf(&ireal, "%c %g", divide < 0 ? sign == '+' ? '-' : '+' : sign == '+' ? '+' : '-',
     ft_double_abs(divide));
  }
  else {
    asprintf(&ireal, "%c %g/%g", divide < 0 ? sign == '+' ? '-' : '+' : sign == '+' ? '+' : '-',
      ft_double_abs(sqrt_delta / _pgcd), ft_double_abs((2 * a) / _pgcd));
  }
  return ireal;
}

char *complex_sqrt_root(double a, double b, double delta, char sign) {
  char  *root;
  double sqrt_delta = ft_sqrt(-delta);
  if ( a < 0 ){
    a *= -1;
    b *= -1;
    sqrt_delta *= -1;
  }
  char  *real = complex_sqrt_R(a, b);
  char  *ireal = complex_sqrt_I(a,sqrt_delta, sign);
  asprintf(&root, "%s %si", real, ireal);
  free(real);
  free(ireal);
  print_complex_sqrt(a, b, delta, sign);
  return (root);
}
