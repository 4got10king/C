#ifndef S21_MATH_H
#define S21_MATH_H

#define s21_EXP 2.71828182845904523543
#define s21_NEG_INF -1.0 / 0.0
#define s21_PI 3.14159265358979323846
#define s21_NAN 0.0 / 0.0
#define s21_INF 1.0 / 0.0
#define s21_2PI 6.2831853071795864768
#define s21_PI_2 1.57079632679489661923
#define s21_EPS 1e-17
#define s21_MAX_DOUBLE 1.79769313486231571e+308
#define s21_LN10 2.30258509299404568402
#define s21_e 2.718281828459045091
#define s21_LOG_2 0.69314718056

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

#endif
