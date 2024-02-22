#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

START_TEST(abs_test_1) {
  ck_assert_double_eq(abs(-7), s21_abs(-7));
  ck_assert_double_eq(abs(-98), s21_abs(-98));
  ck_assert_double_eq(abs(123), s21_abs(123));
  ck_assert_double_eq(abs(10009), s21_abs(10009));
  ck_assert_double_eq(abs(-10009), s21_abs(-10009));
}
END_TEST

START_TEST(abs_test_2) {
  ck_assert_int_eq(s21_abs(-10), abs(-10));
  ck_assert_int_eq(s21_abs(-0), abs(-0));
}
END_TEST

START_TEST(acos_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(acos_test_2) {
  for (float k = -1; k <= 1; k += 0.0305) {
    double a = s21_acos(k);
    double b = acos(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(acos_test_3) {
  ck_assert_ldouble_nan(s21_acos(s21_INF));
  ck_assert_ldouble_nan(s21_acos(s21_NEG_INF));
  ck_assert_ldouble_nan(s21_acos(s21_NAN));
  ck_assert_ldouble_nan(s21_acos(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_acos(0.5), acos(0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_acos(-0.5), acos(-0.5), 1e-8);
  ck_assert_ldouble_eq_tol(s21_acos(-1), acos(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-15);
  ck_assert_ldouble_nan(s21_acos(1.1));
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(-0), acos(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_acos(0.7), acos(0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.00000004564897), acos(0.00000004564897),
                           1e-15);
}
END_TEST

START_TEST(asin_test_1) {
  for (float k = -1; k <= 1; k += 0.1) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
  ck_assert_double_eq_tol(asin(1), s21_asin(1), 1e-7);
}
END_TEST

START_TEST(asin_test_2) {
  for (float k = -1; k <= 1; k += 0.0771) {
    double a = s21_asin(k);
    double b = asin(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(atan_test_1) {
  for (float k = -10; k <= 10; k += 4) {
    double a = s21_atan(k);
    double b = atan(k);
    ck_assert_double_eq_tol(a, b, 1e-7);
  }
}
END_TEST

START_TEST(atan_test_2) {
  double a = 12;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 0.4;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = -0.333;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 30;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = 13.54;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
  a = s21_EXP;
  ck_assert_double_eq_tol(atan(a), s21_atan(a), 1e-7);
}
END_TEST

START_TEST(ceil_test) {
  ck_assert_double_eq(ceil(INFINITY), s21_ceil(s21_INF));
  ck_assert_double_eq(ceil(-INFINITY), s21_ceil(-s21_INF));
  ck_assert_double_nan(ceil(NAN));
  ck_assert_double_nan(s21_ceil(s21_NAN));
  ck_assert_double_eq(ceil(-7.0), s21_ceil(-7.0));
  ck_assert_double_eq(ceil(-98.1), s21_ceil(-98.1));
  ck_assert_double_eq(ceil(123.02), s21_ceil(123.02));
  ck_assert_double_eq(ceil(10009.00123), s21_ceil(10009.00123));
  ck_assert_double_eq(ceil(-10009.555), s21_ceil(-10009.555));
  ck_assert_double_eq(ceil(-0.10009), s21_ceil(-0.10009));
  ck_assert_double_eq(ceil(-1e-23), s21_ceil(-1e-23));
}
END_TEST

START_TEST(cos_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
      ck_assert_double_eq_tol(cos(k + R * s21_PI), s21_cos(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(cos_test_2) {
  for (int R = 5; R >= -15; R -= 2) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 12) {
      ck_assert_double_eq_tol(cos(k + R * s21_PI), s21_cos(k + R * s21_PI),
                              1e-7);
    }
  }
}
END_TEST

START_TEST(cos_test_3) {
  ck_assert_ldouble_nan(s21_cos(s21_INF));
  ck_assert_ldouble_nan(s21_cos(-s21_INF));
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_nan(s21_cos(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_cos(0.5), cos(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0.5), cos(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-1), cos(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1), cos(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1.1), cos(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(1.5), cos(1.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-2.1), cos(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(-0), cos(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(5.123456789123), cos(5.123456789123), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(0.00000004564897), cos(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(s21_PI_2), cos(s21_PI_2), 1e-15);
  ck_assert_ldouble_eq_tol(s21_cos(17000000000.1), cos(17000000000.1), 1e-6);
}
END_TEST

START_TEST(exp_test_1) {
  for (double k = -21; k < 21; k += 1) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_2) {
  for (double k = -15; k < 15; k += 0.123) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_3) {
  for (double k = -5; k < 5; k += 0.00573) {
    double a = s21_exp(k);
    double b = exp(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(exp_test_4) {
  ck_assert_double_nan(s21_exp(s21_NAN));
  ck_assert_double_eq(exp(INFINITY), s21_exp(s21_INF));
  ck_assert_double_eq(exp(-INFINITY), s21_exp(-s21_INF));
  ck_assert_double_eq(exp(0), s21_exp(0));
  ck_assert_ldouble_eq_tol(exp(1), s21_exp(1), 1e-6);
}
END_TEST

START_TEST(exp_test_5) {
  double x = 1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(exp_test_6) {
  double x = -1;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(exp_test_7) {
  double x = 0;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(exp_test_8) {
  double x = 999999999999;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_9) {
  double x = -999999999999;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(exp_test_10) {
  double x = DBL_MAX;
  ck_assert_ldouble_infinite(s21_exp(x));
  ck_assert_ldouble_infinite(exp(x));
}
END_TEST

START_TEST(exp_test_11) {
  double x = -DBL_MAX;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(exp_test_12) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(exp_test_13) {
  double x = -1e-9;
  ck_assert_ldouble_eq_tol(s21_exp(x), exp(x), 1e-6);
}
END_TEST

START_TEST(exp_test_14) {
  ck_assert_ldouble_nan(s21_exp(NAN));
  ck_assert_ldouble_nan(exp(NAN));
}
END_TEST

START_TEST(exp_test_15) {
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
  ck_assert_ldouble_infinite(exp(INFINITY));
}
END_TEST

START_TEST(exp_test_16) {
  ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), 1e-6);
}
END_TEST

START_TEST(fabs_test) {
  ck_assert_double_eq(fabs(INFINITY), s21_fabs(s21_INF));
  ck_assert_double_eq(fabs(-INFINITY), s21_fabs(-s21_INF));
  ck_assert_double_nan(fabs(NAN));
  ck_assert_double_nan(s21_fabs(s21_NAN));
  ck_assert_double_eq(fabs(-7.0), s21_fabs(-7.0));
  ck_assert_double_eq(fabs(-98.1), s21_fabs(-98.1));
  ck_assert_double_eq(fabs(123.02), s21_fabs(123.02));
  ck_assert_double_eq(fabs(10009.0), s21_fabs(10009.0));
  ck_assert_double_eq(fabs(-10009.555), s21_fabs(-10009.555));
  ck_assert_double_eq(fabs(-0.10009), s21_fabs(-0.10009));
  ck_assert_double_eq(fabs(-1e23), s21_fabs(-1e23));
}
END_TEST

START_TEST(floor_test) {
  ck_assert_double_eq(floor(INFINITY), s21_floor(s21_INF));
  ck_assert_double_eq(floor(-INFINITY), s21_floor(-s21_INF));
  ck_assert_double_nan(floor(NAN));
  ck_assert_double_nan(s21_floor(s21_NAN));
  ck_assert_double_eq(floor(-7.0), s21_floor(-7.0));
  ck_assert_double_eq(floor(-98.1), s21_floor(-98.1));
  ck_assert_double_eq(floor(123.02), s21_floor(123.02));
  ck_assert_double_eq(floor(10009.00123), s21_floor(10009.00123));
  ck_assert_double_eq(floor(-10009.555), s21_floor(-10009.555));
  ck_assert_double_eq(floor(-0.10009), s21_floor(-0.10009));
  ck_assert_double_eq(floor(-1e-23), s21_floor(-1e-23));
  ck_assert_double_eq(floor(100091234.5), s21_floor(100091234.5));
}
END_TEST

START_TEST(fmod_test_1) {
  ck_assert_double_nan(fmod(1, 0));
  ck_assert_double_nan(s21_fmod(1, 0));
  ck_assert_double_eq(fmod(0, -1), s21_fmod(0, -1));
  ck_assert_double_eq(fmod(0, 1), s21_fmod(0, 1));
  ck_assert_double_nan(fmod(INFINITY, -1));
  ck_assert_double_nan(s21_fmod(INFINITY, -1));
  ck_assert_double_eq(fmod(-1, -INFINITY), s21_fmod(-1, -s21_INF));
  ck_assert_double_eq(fmod(0, INFINITY), s21_fmod(0, s21_INF));
  ck_assert_double_nan(s21_fmod(0, s21_NAN));
  ck_assert_double_nan(fmod(0, NAN));
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_NAN));
  ck_assert_double_nan(fmod(NAN, NAN));
  ck_assert_double_nan(s21_fmod(s21_NAN, s21_INF));
  ck_assert_double_nan(s21_fmod(s21_INF, s21_NAN));
  ck_assert_double_nan(s21_fmod(s21_NAN, -s21_INF));
  ck_assert_double_nan(s21_fmod(-s21_INF, s21_NAN));
  ck_assert_double_nan(fmod(NAN, INFINITY));
  ck_assert_double_nan(fmod(INFINITY, NAN));
  ck_assert_double_nan(fmod(NAN, -INFINITY));
  ck_assert_double_nan(fmod(-INFINITY, NAN));
}
END_TEST

START_TEST(fmod_test_2) {
  for (double a = -1500; a < 1500; a += 123) {
    for (double b = -12; b < 12; b += 1.25) {
      ck_assert_double_eq(fmod(a, b), s21_fmod(a, b));
      ck_assert_double_eq(fmod(b, a), s21_fmod(b, a));
    }
  }
}
END_TEST

START_TEST(log_test_1) {
  for (double k = 1; k < 100; k += 13.2) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_2) {
  for (double k = 0.1; k < 4; k += 0.24) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_3) {
  for (double k = 0.1; k < 10000; k += 123) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_4) {
  for (double k = 0.000005; k < 1; k *= 5) {
    double a = s21_log(k);
    double b = log(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(log_test_5) {
  ck_assert_double_nan(s21_log(s21_NAN));
  ck_assert_double_eq(log(0), s21_log(0));
  ck_assert_double_nan(s21_log(-3));
  ck_assert_ldouble_eq_tol(log(s21_e), s21_log(s21_e), 1e-6);
  ck_assert_double_eq_tol(log(2), s21_log(2), 1e-6);
}
END_TEST

START_TEST(pow_test_1) {
  ck_assert_ldouble_eq_tol(s21_pow(1, 1), pow(1, 1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.000, 0.000), pow(0.000, 0.000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.000, 1.000), pow(0.000, 1.000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.698, 7), pow(0.698, 7), 1e-6);
  ck_assert_int_eq(s21_pow(-2.6, 3.45) == NAN, pow(-2.6, 3.45) == NAN);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0.), pow(0, 0.), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(10, 1.5), pow(10, 1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1.5, 1.5), pow(1.5, 1.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 1), pow(0, 1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 0), pow(1, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1.000, 0.000), pow(1.000, 0.000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.215, 0.215), pow(0.215, 0.215), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.978464, 5), pow(0.978464, 5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.986, 10), pow(0.986, 10), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(8.654, 0.7), pow(8.654, 0.7), 1e-6);
  ck_assert_double_nan(s21_pow(s21_NAN, s21_NAN));
  ck_assert_double_eq(s21_pow(s21_NEG_INF, 3), pow(s21_NEG_INF, 3));
  ck_assert_double_eq(s21_pow(-s21_INF, -3), pow(-s21_INF, -3));
  ck_assert_double_eq(pow(INFINITY, INFINITY), s21_pow(s21_INF, s21_INF));
  ck_assert_double_eq(pow(INFINITY, -INFINITY), s21_pow(s21_INF, -s21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(8.654, -0.7), pow(8.654, -0.7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.978464, -5), pow(0.978464, -5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.756, -7), pow(0.756, -7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 5), pow(0, 5), 1e-6);
  ck_assert_ldouble_infinite(s21_pow(0, -5));
  ck_assert_ldouble_eq_tol(s21_pow(9.35378, -9.34748), pow(9.35378, -9.34748),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(53.5685, -11.39064), pow(53.5685, -11.39064),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(56.346786, 2.5346), pow(56.346786, 2.5346),
                           1e-6);
}
END_TEST

START_TEST(sin_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 17) {
      ck_assert_double_eq_tol(sin(k + R * s21_PI), s21_sin(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(sin_test_2) {
  for (int R = 5; R >= -15; R -= 2) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 15) {
      ck_assert_double_eq_tol(sin(k + R * s21_PI), s21_sin(k + R * s21_PI),
                              1e-7);
    }
  }
}
END_TEST

START_TEST(sin_test_3) {
  ck_assert_ldouble_nan(s21_sin(s21_INF));
  ck_assert_ldouble_nan(s21_sin(-s21_INF));
  ck_assert_ldouble_nan(s21_sin(s21_NAN));
  ck_assert_ldouble_nan(s21_sin(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-1), sin(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(1), sin(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(1.1), sin(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-2.1), sin(-2.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(0), sin(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(-0), sin(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(5.123456789123), sin(5.123456789123), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(0.00000004564897), sin(0.00000004564897),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-s21_2PI), sin(-s21_2PI), 1e-15);
  ck_assert_ldouble_eq_tol(s21_sin(100000000), sin(100000000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-100000000), sin(-100000000), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(17000000000.1), sin(17000000000.1), 1e-6);
}
END_TEST

START_TEST(sqrt_test_1) {
  for (double k = 0; k < 21; k += 3) {
    double a = s21_sqrt(k);
    double b = sqrt(k);
    ck_assert_double_eq_tol(a, b, 1e-6);
  }
}
END_TEST

START_TEST(sqrt_test_2) {
  ck_assert_double_nan(s21_sqrt(s21_NAN));
  ck_assert_double_nan(sqrt(NAN));
  ck_assert_double_eq(s21_sqrt(s21_INF), sqrt(INFINITY));
  ck_assert_double_nan(s21_sqrt(-s21_INF));
  ck_assert_double_nan(sqrt(-INFINITY));
  ck_assert_double_nan(s21_sqrt(-5));
  ck_assert_double_nan(sqrt(-5));
  ck_assert_double_eq_tol(s21_sqrt(1000), sqrt(1000), 1e-7);
}
END_TEST

START_TEST(tan_test_1) {
  for (int R = 20; R >= -20; R -= 4) {
    for (double k = 2 * s21_PI; k > -2 * s21_PI; k -= s21_PI / 9) {
      ck_assert_double_eq_tol(tan(k + R * s21_PI), s21_tan(k + R * s21_PI),
                              1e-6);
    }
  }
}
END_TEST

START_TEST(tan_test_2) {
  ck_assert_ldouble_nan(s21_cos(s21_INF));
  ck_assert_ldouble_nan(s21_cos(-s21_INF));
  ck_assert_ldouble_nan(s21_cos(s21_NAN));
  ck_assert_ldouble_nan(s21_cos(-s21_NAN));
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-0.5), tan(-0.5), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-1), tan(-1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(1), tan(1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(1.1), tan(1.1), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-2.1), tan(-2.1), 1e-8);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(-0), tan(-0), 1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(0.00000004564897), tan(0.00000004564897),
                           1e-15);
  ck_assert_ldouble_eq_tol(s21_tan(170000000.1), tan(170000000.1), 1e-7);
}
END_TEST

START_TEST(sin_cos_tan_test) {
  ck_assert_double_nan(s21_sin(s21_NAN));
  ck_assert_double_nan(s21_cos(s21_NAN));
  ck_assert_double_nan(s21_tan(s21_NAN));
  ck_assert_double_nan(s21_sin(s21_INF));
  ck_assert_double_nan(s21_cos(s21_INF));
  ck_assert_double_nan(s21_tan(s21_INF));
  ck_assert_double_nan(s21_sin(-s21_INF));
  ck_assert_double_nan(s21_cos(-s21_INF));
  ck_assert_double_nan(s21_tan(-s21_INF));
}
END_TEST

START_TEST(asin_acos_atan_test) {
  ck_assert_double_nan(s21_asin(s21_NAN));
  ck_assert_double_nan(s21_acos(s21_NAN));
  ck_assert_double_nan(s21_atan(s21_NAN));
  ck_assert_double_nan(s21_asin(s21_INF));
  ck_assert_double_nan(s21_acos(s21_INF));
  ck_assert_double_nan(s21_asin(-s21_INF));
  ck_assert_double_nan(s21_acos(-s21_INF));
  ck_assert_double_eq(atan(-INFINITY), atan(-s21_INF));
  ck_assert_double_nan(s21_asin(5));
  ck_assert_double_nan(s21_acos(6));
  ck_assert_double_nan(s21_asin(-8));
}
END_TEST

Suite *s21_math_suite(void) {
  Suite *suite;

  suite = suite_create("s21_math");
  TCase *tcase_core = tcase_create("Core");

  tcase_add_test(tcase_core, abs_test_1);
  tcase_add_test(tcase_core, abs_test_2);
  tcase_add_test(tcase_core, acos_test_1);
  tcase_add_test(tcase_core, acos_test_2);
  tcase_add_test(tcase_core, acos_test_3);
  tcase_add_test(tcase_core, asin_test_1);
  tcase_add_test(tcase_core, asin_test_2);
  tcase_add_test(tcase_core, atan_test_1);
  tcase_add_test(tcase_core, atan_test_2);
  tcase_add_test(tcase_core, ceil_test);
  tcase_add_test(tcase_core, cos_test_1);
  tcase_add_test(tcase_core, cos_test_2);
  tcase_add_test(tcase_core, cos_test_3);
  tcase_add_test(tcase_core, exp_test_1);
  tcase_add_test(tcase_core, exp_test_2);
  tcase_add_test(tcase_core, exp_test_3);
  tcase_add_test(tcase_core, exp_test_4);
  tcase_add_test(tcase_core, exp_test_5);
  tcase_add_test(tcase_core, exp_test_6);
  tcase_add_test(tcase_core, exp_test_7);
  tcase_add_test(tcase_core, exp_test_8);
  tcase_add_test(tcase_core, exp_test_9);
  tcase_add_test(tcase_core, exp_test_10);
  tcase_add_test(tcase_core, exp_test_11);
  tcase_add_test(tcase_core, exp_test_12);
  tcase_add_test(tcase_core, exp_test_13);
  tcase_add_test(tcase_core, exp_test_14);
  tcase_add_test(tcase_core, exp_test_15);
  tcase_add_test(tcase_core, exp_test_16);
  tcase_add_test(tcase_core, fabs_test);
  tcase_add_test(tcase_core, floor_test);
  tcase_add_test(tcase_core, fmod_test_1);
  tcase_add_test(tcase_core, fmod_test_2);
  tcase_add_test(tcase_core, log_test_1);
  tcase_add_test(tcase_core, log_test_2);
  tcase_add_test(tcase_core, log_test_3);
  tcase_add_test(tcase_core, log_test_4);
  tcase_add_test(tcase_core, log_test_5);
  tcase_add_test(tcase_core, pow_test_1);
  tcase_add_test(tcase_core, sin_test_1);
  tcase_add_test(tcase_core, sin_test_2);
  tcase_add_test(tcase_core, sin_test_3);
  tcase_add_test(tcase_core, sqrt_test_1);
  tcase_add_test(tcase_core, sqrt_test_2);
  tcase_add_test(tcase_core, tan_test_1);
  tcase_add_test(tcase_core, tan_test_2);
  tcase_add_test(tcase_core, sin_cos_tan_test);
  tcase_add_test(tcase_core, asin_acos_atan_test);

  suite_add_tcase(suite, tcase_core);

  return suite;
}

int main(void) {
  Suite *suite = s21_math_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);

  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);

  return (failed_count == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}