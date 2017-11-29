/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwiessle <kwiessle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:04:44 by kwiessle          #+#    #+#             */
/*   Updated: 2017/11/29 13:40:22 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

char  *minimize(char *str) {
  int     i = 0, j = 0, spaces = 0;
  char    *super;
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
    if (minimized[i] == '=' && minimized[i + 2] != '-')
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

static double  get_high_coeff(char **left, char ** right, char *degree) {
  int     i = 0;
  double  coeff = 0.0;
  while (left[i]) {
    if (left[i][0] == 'X' && ft_strlen(left[i]) > 1 && ft_strcmp(left[i], ft_strjoin("X^", degree)) == 0) {
      if (left[i -1][0] == '+') {
        coeff = coeff + 1.0;
      } else if (left[i -1][0] == '-') {
        coeff = coeff - 1.0;
      } else {
        coeff = coeff + (atof(ft_strjoin(left[i -3], left[i -2])));
      }
    }
    i++;
  }
  i = 0;
  while (right[i]) {
    if (right[i][0] == 'X' && ft_strlen(right[i]) > 1 && ft_strcmp(right[i], ft_strjoin("X^", degree)) == 0) {
      if (right[i -1][0] == '+') {
        coeff = coeff - 1.0;
      } else if (right[i -1][0] == '-') {
        coeff = coeff + 1.0;
      } else {
        coeff = coeff + (-1 * atof(ft_strjoin(right[i -3], right[i -2])));
      }
    }
    i++;
  }
  return (coeff);
}
//
static double   get_low_coeff(char **left, char **right) {
  int     i = 0;
  double  coeff = 0.0;
  while (left[i]) {
    if (left[i][0] == 'X') {
      if (ft_strlen(left[i]) == 1) {
        if (left[i -1][0] == '+') {
          coeff = coeff + 1.0;
        } else if (left[i -1][0] == '-') {
          coeff = coeff - 1.0;
        } else {
          coeff = coeff + (atof(ft_strjoin(left[i -3], left[i -2])));
        }
      }
      if (ft_strlen(left[i]) > 1 && ft_strcmp(left[i], "X^1") == 0) {
          if (left[i -1][0] == '+') {
            coeff = coeff + 1.0;
          } else if (left[i -1][0] == '-') {
            coeff = coeff - 1.0;
          } else {
            coeff = coeff + (atof(ft_strjoin(left[i -3], left[i -2])));
          }
      }
    }
    i++;
  }
  i = 0;
  while (right[i]) {
    if (right[i][0] == 'X') {
      if (ft_strlen(right[i]) == 1) {
        if (right[i -1][0] == '+') {
          coeff = coeff - 1.0;
        } else if (right[i -1][0] == '-') {
          coeff = coeff + 1.0;
        } else {
          coeff = coeff + (-1 * atof(ft_strjoin(right[i -3], right[i -2])));
        }
      }
      if (ft_strlen(right[i]) > 1 && ft_strcmp(right[i], "X^1") == 0) {
          if (right[i -1][0] == '+') {
            coeff = coeff - 1.0;
          } else if (right[i -1][0] == '-') {
            coeff = coeff + 1.0;
          } else {
            coeff = coeff + (-1 * atof(ft_strjoin(right[i -3], right[i -2])));
          }
      }
    }
    i++;
  }
  return (coeff);
}



static double get_nat_coeff(char **left, char **right) {
  int     i = 0;
  double  coeff = 0.0;

  while (left[i]) {
    if ((left[i][0] == '+' || left[i][0] == '-') && (left[0 +1][0] != 'X') && (left[i +2][0] == '#' || (left[i +2][0] == '+' || left[i +2][0] == '-'))) {
      coeff = coeff + atof(ft_strjoin(left[i], left[i +1]));
    }
    else if (left[i][0] == 'X' && ft_strcmp("X^0", left[i]) == 0) {
      coeff = coeff + (atof(ft_strjoin(left[i -3], left[i -2])));
    }
    i++;
  }
  i = 0;
  while (right[i]) {
    if ((right[i][0] == '+' || right[i][0] == '-') && (right[0 +1][0] != 'X') && (right[i +2][0] == '#' || (right[i +2][0] == '+' || right[i +2][0] == '-'))) {
      coeff = coeff + (-1 * atof(ft_strjoin(right[i], right[i +1])));
    }
    else if (right[i][0] == 'X' && ft_strcmp("X^0", right[i]) == 0) {
      coeff = coeff + (-1 * atof(ft_strjoin(right[i -3], right[i -2])));
    }
    i++;
  }
  return (coeff);
}

void  print_tab(char *name, char **tab) {
  int   i = 0;
  printf("\n\n%s\n\n", name);
  while (tab[i]) {
    printf("%s\n", tab[i]);
    i++;
  }
}
int   get_max_pow(char *equation_trimed) {
  char *tmp = equation_trimed;
  int i = 0;
  int max_pow = 0;
  char *tmp2;
  while((tmp = ft_strchr(tmp, '^')) != NULL) {
    tmp++;
    tmp2 = ft_strdup(tmp);
    while(tmp2[i] && (tmp2[i] != '-' && tmp2[i] != '+' && tmp2[i] != '=')) {
      i++;
    }
    tmp2[i] = '\0';
    max_pow = max_pow < ft_atoi(tmp2) ? ft_atoi(tmp2) : max_pow;
  }
  return(max_pow);
}

double   get_coeff(char *equation_trimed, int degree) {
  char    **sides;
  char    **left;
  char    **right;
  double  a = 0.0;
  char    *equation;
  char    *str_degree = ft_itoa(degree);

  if (equation_trimed[1] != '-') {
    equation = ft_strjoin("+ ", equation_trimed);
  } else {
    equation = ft_strdup(equation_trimed);
  }
  // printf("Looking for %d degree.\n", degree);
  // printf("equation : %s\n", equation);
  sides = ft_strsplit(equation, '=');
  left = ft_strsplit(sides[0],' ');
  right = ft_strsplit(sides[1], ' ');
  // print_tab("LEFT  ->", left);
  // print_tab("RIGHT  ->", right);
  if (degree >= 2) {
    a = get_high_coeff(left, right, str_degree);
  } else if (degree == 1) {
    a = get_low_coeff(left, right);
  } else if (degree == 0) {
    a = get_nat_coeff(left, right);
  }
  return (a);
}
