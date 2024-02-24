#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

enum return_messages { OK, INCORRECT_MATRIX, ERR_CALC };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// main
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// support
int s21_is_valid_matrix(matrix_t *A);
int s21_is_ptr(const matrix_t *A);
int s21_is_square_matrix(matrix_t *A);
int s21_is_same_matrix(matrix_t *A, matrix_t *B);
int s21_get_sign(int i, int j);
int s21_sum_or_sub(matrix_t *A, matrix_t *B, matrix_t *result, char sign);
void s21_create_minor_matrix(matrix_t *A, matrix_t *result);
void s21_create_matrix_for_determinant(matrix_t *A, matrix_t *result,
                                       int skip_row, int skip_col);
double s21_get_det(matrix_t *A, int size_A);

#endif  // SRC_S21_MATRIX_H_
