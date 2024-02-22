#include "s21_math.h"

int s21_abs(int x) {
  int res = (x < 0) ? -x : x;
  return res;
}

long double s21_acos(double x) {
  if (x <= 1 && x >= -1) {
    x = s21_PI / 2 - s21_asin(x);
  } else {
    x = s21_NAN;
  }
  return x;
}

long double s21_asin(double x) {
  long double rez = x, y = x;
  long double i = 1;
  while (s21_fabs(rez) > s21_EPS) {
    if (x < -1 || x > 1) {
      y = s21_NAN;
      break;
    }
    if (x == 1 || x == -1) {
      y = s21_PI / 2 * x;
      break;
    }
    rez *= x * x * (2 * i - 1) * (2 * i - 1) / ((2 * i + 1) * 2 * i);
    i += 1;
    y += rez;
  }
  return y;
}

long double s21_atan(double x) {
  long double res = 0.0;
  if (x == s21_INF) {
    res = s21_PI_2;
  } else if (x == s21_NEG_INF) {
    res = -s21_PI_2;
  } else {
    res = s21_asin(x / s21_sqrt(1 + x * x));
  }
  return res;
}

long double s21_ceil(double x) {
  long double res = 0.0;
  if (x != x) {
    res = s21_NAN;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else if (x == s21_NEG_INF) {
    res = s21_NEG_INF;
  } else {
    res = (int)x;
    if (x < 0 && x > -1) {
      res *= -1;
    }
    if (x != (int)x && x > 0) {
      res += 1;
    }
  }
  return res;
}

long double s21_cos(double x) {
  double pow = 0.0;
  long double res = 1.0;
  long double num = 1.0;
  long double y = s21_fmod(x, 2.0 * s21_PI);

  if (x == s21_NAN || s21_fabs(x) == s21_INF) {
    res = s21_NAN;
  } else {
    while (s21_fabs(num / res) > s21_EPS) {
      pow = pow + 2.0;
      num = (-num * y * y) / ((pow - 1.0) * (pow));
      res += num;
    }
  }
  return res;
}

long double s21_exp(double x) {
  long double res = 0.0, a = 1.0;
  int minus = 0;
  if (x != x) {
    res = s21_NAN;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else if (x == s21_NEG_INF) {
    res = 0;
  } else {
    if (x < 0) {
      x *= -1;
      minus = 1;
    }
    int n = 1;
    while (s21_fabs(a) > s21_EPS && res != s21_INF) {
      res += a;
      a *= x / n;
      n++;
    }
  }
  if (minus) {
    res = 1 / res;
  }
  return res;
}

long double s21_fabs(double x) {
  double res = (x >= 0) ? x : -x;
  return res;
}

long double s21_floor(double x) {
  long double res = 0.0;
  if (x != x) {
    res = s21_NAN;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else if (x == s21_NEG_INF) {
    res = s21_NEG_INF;
  } else {
    res = (int)x;
    if (x < 0 && (x != (int)x)) {
      res -= 1;
    }
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0;
  long int n = x / y;
  if (y == 0.0 || x == s21_INF || x == s21_NEG_INF) {
    res = s21_NAN;
  } else if (y == s21_INF || y == s21_NEG_INF) {
    res = x;
  } else {
    res = x - (n * y);
  }
  return res;
}

long double s21_log(double x) {
  long double res = 0.0;
  int exp = 0, del = 0;
  if (x < 0 || x != x) {
    res = s21_NAN;
  } else if (x == s21_INF) {
    res = s21_INF;
  } else if (x == 0) {
    res = s21_NEG_INF;
  } else if (x == s21_e) {
    res = 1;
  } else {
    if (x > 2) {
      while (x > 1) {
        x /= 10;
        exp++;
      }
    } else if (x < 1) {
      while (x * 10 < 1) {
        x *= 10;
        exp--;
      }
    }
    while (x >= 2) {
      x /= 2;
      del++;
    }
    res = exp * s21_LN10 + del * s21_LOG_2;
    double res_lg = 0.0, a = 1.0;
    int b = 1, c = 1;
    while (s21_fabs(a) > s21_EPS) {
      a *= x - 1.0;
      res_lg += c * a / b;
      b++;
      c *= -1;
    }
    res += res_lg;
  }
  return res;
}

long double s21_pow(double base, double exp) {
  unsigned int e = 0;
  long double res = 1.0;

  if (base == 0) {
    if (exp > 0) {
      res = 0;
    } else if (exp == 0) {
      res = 1;
    } else if (exp != exp) {
      res = s21_NAN;
    } else {
      res = s21_INF;
    }
  } else if (base == 1) {
    res = 1;
  } else if (exp == (int)(e = (int)exp)) {
    if ((int)e < 0) {
      e = -e;
      base = 1 / base;
    }
    for (int i = 0; i < (int)e; i++) {
      res *= base;
    }
  } else if (base != base) {
    res = s21_NAN;
  } else if (exp == s21_NEG_INF) {
    if (base == -1) {
      res = 1;
    } else if (base < 1 && base > -1) {
      res = s21_INF;
    } else {
      res = 0;
    }
  } else if (exp == s21_INF) {
    if (base == -1) {
      res = 1;
    } else if (base < 1 && base > -1) {
      res = 0;
    } else {
      res = s21_INF;
    }
  } else {
    res = s21_exp(s21_log(base) * exp);
  }
  return res;
}

long double s21_sin(double x) {
  long double res;
  if (x == s21_INF || x == -s21_INF || x != x) {
    res = s21_NAN;
  }
  x = s21_fmod(x, 2 * s21_PI);
  while (x > s21_PI) {
    x -= 2 * s21_PI;
  }

  while (x < -s21_PI) {
    x += 2 * s21_PI;
  }
  res = x;
  int factorial = 1;
  long double tmp = x;
  while (s21_fabs(tmp) > s21_EPS) {
    tmp = (-tmp * x * x) / ((2 * factorial + 1) * (2 * factorial));
    res += tmp;
    factorial++;
  }
  return res;
}

long double s21_sqrt(double x) {
  long double res = 0.0;
  if (x < 0 || x == s21_NAN) {
    res = s21_NAN;
  } else {
    res = s21_pow(x, 0.5);
  }
  return res;
}

long double s21_tan(double x) {
  long double res = 0;
  if (x == s21_INF || x == s21_NEG_INF) {
    res = s21_NAN;
  } else {
    res = s21_sin(x) / s21_cos(x);
  }
  return res;
}
