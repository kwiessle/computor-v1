/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:04:44 by kwiessle          #+#    #+#             */
/*   Updated: 2017/12/04 16:19:08 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

char  *minimize(char *str) {
  int     i = 0, j = 0, spaces = 0;
  char    *super;
  char    *fix;
  while (str[i]) {
    if (str[i] ==  ' ')
      spaces++;
    i++;
  }
  if (!(super = malloc(sizeof(char *) * (strlen(str) - spaces))))
    return (NULL);
  i = 0;
  while (str[i]) {
    if (str[i] != ' ') {
      super[j] = str[i];
      j++;
    }
    i++;
  }
  super[j] = '\0';
  if (super[0] != '-' && super[0] != '+') {
    fix = ft_strjoin("+", super);
    free(super);
    return (fix);
  }
  return (super);
}

char  *super_trim(char *str) {
  char  *minimized = minimize(str);
  char  *trimed;
  char  *fix;
  int   verif = 0;
  int   len = strlen(minimized), i = 0, operators = 0, j = 0;

  while (minimized[i]) {
    if (minimized[i] == '+' || minimized[i] == '-' || minimized[i] == '*' || minimized[i] == '=')
      operators++;
    if (minimized[i] == '=' && minimized[i + 1] != '-' && minimized[i + 1] != '+')
      verif++;
    i++;
  }
  i = 0;
  if (!(trimed = malloc(sizeof(char *) * (len + (operators * 2) + 2  + (verif * 3)))))
    return (NULL);
  while (minimized[i]) {
    if (minimized[i] == '+' || minimized[i] == '-' || minimized[i] == '*' ) {
      trimed[j] = ' ';
      trimed[j + 1] = minimized[i];
      trimed[j + 2] = ' ';
      j = j + 2;
    } else if (minimized[i] == '=') {
      trimed[j] = ' ';
      trimed[j + 1] = '#';
      trimed[j + 2] = minimized[i];
      if (verif == 1) {
        j++;
        trimed[j + 2] = ' ';
        trimed[j + 3] = '+';
        trimed[j + 4] = ' ';
        j = j + 4;
      } else {
        j = j + 2;
      }
    } else {
      trimed[j] = minimized[i];
    }
    i++;
    j++;
  }
  trimed[j] = '\0';
  fix = ft_strjoin(trimed, " #");
  free(trimed);
  free(minimized);
  return (fix);
}

static double high_loop(char **side, char *degree) {
  int     i = 0;
  char    *aCoef;
  char    *pow =  ft_strjoin("X^", degree);
  double  coeff = 0.0;
  while (side[i]) {
    if (side[i][0] == 'X' && ft_strlen(side[i]) > 1 && ft_strcmp(side[i], pow) == 0) {
      if (side[i -1][0] == '+') {
        coeff = coeff + 1.0;
      } else if (side[i -1][0] == '-') {
        coeff = coeff - 1.0;
      } else {
        aCoef = ft_strjoin(side[i -3], side[i -2]);
        coeff = coeff + (atof(aCoef));
        free(aCoef);
      }
    }
    i++;
  }
  free(pow);
  return (coeff);
}

static double low_loop(char **side) {
  int     i = 0;
  double  coeff = 0.0;
  char    *aCoef;
  while (side[i]) {
    if (side[i][0] == 'X') {
      if (ft_strlen(side[i]) == 1) {
        if (side[i -1][0] == '+') {
          coeff = coeff + 1.0;
        } else if (side[i -1][0] == '-') {
          coeff = coeff - 1.0;
        } else {
          aCoef = ft_strjoin(side[i - 3], side[i - 2]);
          coeff = coeff + (atof(aCoef));
          free(aCoef);
        }
      }
      if (ft_strlen(side[i]) > 1 && ft_strcmp(side[i], "X^1") == 0) {
          if (side[i -1][0] == '+') {
            coeff = coeff + 1.0;
          } else if (side[i -1][0] == '-') {
            coeff = coeff - 1.0;
          } else {
            aCoef = ft_strjoin(side[i -3], side[i -2]);
            coeff = coeff + (atof(aCoef));
            free(aCoef);
          }
      }
    }
    i++;
  }
  return (coeff);
}

static double nat_loop(char **side) {
  int     i = 0;
  double  coeff = 0.0;
  char  *aCoef;
  while (side[i]) {
    if ((side[i][0] == '+' || side[i][0] == '-') && (side[i +1][0] != 'X') && (side[i +2][0] == '#' || (side[i +2][0] == '+' || side[i +2][0] == '-'))) {
      aCoef = ft_strjoin(side[i], side[i +1]);
      coeff = coeff + atof(aCoef);
      free(aCoef);
    }
    else if (side[i][0] == 'X' && ft_strcmp("X^0", side[i]) == 0) {
      aCoef = ft_strjoin(side[i -3], side[i -2]);
      coeff = coeff + (atof(aCoef));
      free(aCoef);
    }
    i++;
  }
  return (coeff);
}


int   get_max_pow(char *equation_trimed) {
  char *tmp = equation_trimed;
  int i = 0;
  int max_pow = 0;
  char *tmp2;
  while((tmp = ft_strchr(tmp, 'X')) != NULL && tmp++) {
    if (tmp[0] == '^' && tmp++) {
      tmp2 = ft_strdup(tmp);
      while(tmp2[i] && (tmp2[i] != '-' && tmp2[i] != '+' && tmp2[i] != '=' && tmp2[i] != '#')) {
        i++;
      }
      tmp2[i] = '\0';
      max_pow = max_pow < ft_atoi(tmp2) ? ft_atoi(tmp2) : max_pow;
      free(tmp2);
    }
    else if (tmp[0] != '^' || tmp[0] == '#') {
      max_pow = max_pow < 1 ? 1 : max_pow;
    }
  }
  free(tmp);
  return(max_pow);
}

void free_tab(void **tab) {
  int i = 0;
  while(tab[i]) {
    free(tab[i]);
    i++;
  }
  free(tab);
}

double   *get_coeff(char *equation, int degree) {
  char    **sides;
  char    **left;
  char    **right;
  char    *str_degree = ft_itoa(degree);
  double *coefs;

  if ( !(coefs = (double *)malloc(degree * sizeof(double) + 1)) ) {
    return (NULL);
  }
  sides = ft_strsplit(equation, '=');
  left = ft_strsplit(sides[0],' ');
  right = ft_strsplit(sides[1], ' ');
  while (degree >= 0) {
    if (degree >= 2) {
      coefs[degree] = high_loop(left, str_degree) - high_loop(right, str_degree);
    } else if (degree == 1) {
      coefs[degree] = low_loop(left) - low_loop(right);
    } else if (degree == 0) {
      coefs[degree] = nat_loop(left) - nat_loop(right);
    }
    degree--;
  }
  free(str_degree);
  free_tab((void **)left);
  free_tab((void **)right);
  free_tab((void **)sides);
  return (coefs);
}
