/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:04:44 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/29 18:06:02 by kwiessle         ###   ########.fr       */
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
  if (!(super = malloc(sizeof(char*) * (strlen(str) - spaces))))
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
  return (fix);
}



static double high_loop(char **side, char *degree) {
  int     i = 0;
  double  coeff = 0.0;
  while (side[i]) {
    if (side[i][0] == 'X' && ft_strlen(side[i]) > 1 && ft_strcmp(side[i], ft_strjoin("X^", degree)) == 0) {
      if (side[i -1][0] == '+') {
        coeff = coeff + 1.0;
      } else if (side[i -1][0] == '-') {
        coeff = coeff - 1.0;
      } else {
        coeff = coeff + (atof(ft_strjoin(side[i -3], side[i -2])));
      }
    }
    i++;
  }
  return (coeff);
}

static double low_loop(char **side) {
  int     i = 0;
  double  coeff = 0.0;
  while (side[i]) {
    if (side[i][0] == 'X') {
      if (ft_strlen(side[i]) == 1) {
        if (side[i -1][0] == '+') {
          coeff = coeff + 1.0;
        } else if (side[i -1][0] == '-') {
          coeff = coeff - 1.0;
        } else {
          coeff = coeff + (atof(ft_strjoin(side[i -3], side[i -2])));
        }
      }
      if (ft_strlen(side[i]) > 1 && ft_strcmp(side[i], "X^1") == 0) {
          if (side[i -1][0] == '+') {
            coeff = coeff + 1.0;
          } else if (side[i -1][0] == '-') {
            coeff = coeff - 1.0;
          } else {
            coeff = coeff + (atof(ft_strjoin(side[i -3], side[i -2])));
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
  while (side[i]) {
    if ((side[i][0] == '+' || side[i][0] == '-') && (side[i +1][0] != 'X') && (side[i +2][0] == '#' || (side[i +2][0] == '+' || side[i +2][0] == '-'))) {
      coeff = coeff + atof(ft_strjoin(side[i], side[i +1]));
    }
    else if (side[i][0] == 'X' && ft_strcmp("X^0", side[i]) == 0) {
      coeff = coeff + (atof(ft_strjoin(side[i -3], side[i -2])));
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
    }
    else if (tmp[0] != '^' || tmp[0] == '#') {
      max_pow = max_pow < 1 ? 1 : max_pow;
    }
  }
  return(max_pow);
}

double   get_coeff(char *equation, int degree) {
  char    **sides;
  char    **left;
  char    **right;
  double  a = 0.0;
  char    *str_degree = ft_itoa(degree);

  sides = ft_strsplit(equation, '=');
  left = ft_strsplit(sides[0],' ');
  right = ft_strsplit(sides[1], ' ');
  if (degree >= 2) {
    a = high_loop(left, str_degree) - high_loop(right, str_degree);
  } else if (degree == 1) {
    a = low_loop(left) - low_loop(right);
  } else if (degree == 0) {
    a = nat_loop(left) - nat_loop(right);

  }
  return (a);
}
