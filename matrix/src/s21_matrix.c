#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = OK;
  if (rows > 0 && columns > 0 && s21_is_ptr(result)) {
    result->columns = columns;
    result->rows = rows;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          status = INCORRECT_MATRIX;
          break;
        }
      }
    } else {
      status = INCORRECT_MATRIX;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

void s21_remove_matrix(matrix_t *A) {
  if (A->matrix != NULL) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int result = SUCCESS;
  if (s21_is_valid_matrix(A) && s21_is_valid_matrix(B) &&
      s21_is_same_matrix(A, B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPS) {
          result = FAILURE;
          break;
        }
      }
    }
  } else {
    result = FAILURE;
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_or_sub(A, B, result, '+');
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  return s21_sum_or_sub(A, B, result, '-');
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  if (s21_is_valid_matrix(A) && s21_is_ptr(result)) {
    if (!s21_create_matrix(A->rows, A->columns, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    } else {
      status = INCORRECT_MATRIX;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (s21_is_valid_matrix(A) && s21_is_valid_matrix(B) && s21_is_ptr(result)) {
    if (A->columns == B->rows) {
      if (!s21_create_matrix(A->rows, B->columns, result)) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < A->columns; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      } else {
        status = INCORRECT_MATRIX;
      }
    } else {
      status = ERR_CALC;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (s21_is_valid_matrix(A) && s21_is_ptr(result)) {
    if (!s21_create_matrix(A->columns, A->rows, result)) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    } else {
      status = INCORRECT_MATRIX;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (s21_is_valid_matrix(A) && s21_is_ptr(result)) {
    if (s21_is_square_matrix(A)) {
      if (!s21_create_matrix(A->rows, A->columns, result)) {
        s21_create_minor_matrix(A, result);
      } else {
        status = INCORRECT_MATRIX;
      }
    } else {
      status = ERR_CALC;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_determinant(matrix_t *A, double *result) {
  int status = OK;
  if (s21_is_valid_matrix(A)) {
    if (s21_is_square_matrix(A)) {
      *result = (A->columns > 1) ? s21_get_det(A, A->columns) : A->matrix[0][0];
    } else {
      status = ERR_CALC;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (s21_is_valid_matrix(A) && s21_is_ptr(result)) {
    if (s21_is_square_matrix(A)) {
      double determinant = 0;
      s21_determinant(A, &determinant);
      if (determinant != 0) {
        if (A->columns == 1) {
          if (!s21_create_matrix(A->rows, A->columns, result)) {
            result->matrix[0][0] = 1 / A->matrix[0][0];
          } else {
            status = INCORRECT_MATRIX;
          }
        } else {
          matrix_t complements = {0};
          matrix_t complements_transpose = {0};
          s21_calc_complements(A, &complements);
          s21_transpose(&complements, &complements_transpose);
          s21_mult_number(&complements_transpose, 1 / determinant, result);
          s21_remove_matrix(&complements);
          s21_remove_matrix(&complements_transpose);
        }
      } else {
        status = ERR_CALC;
      }
    } else {
      status = ERR_CALC;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

// *****support functions*****

int s21_is_valid_matrix(matrix_t *A) {
  return s21_is_ptr(A) && A->matrix != NULL && (A->columns > 0 && A->rows > 0);
}

int s21_is_ptr(const matrix_t *A) { return A != NULL; }

int s21_is_square_matrix(matrix_t *A) { return A->rows == A->columns; }

int s21_is_same_matrix(matrix_t *A, matrix_t *B) {
  return A->rows == B->rows && A->columns == B->columns;
}

int s21_get_sign(int i, int j) { return (i + j) % 2 == 0 ? 1 : -1; }

int s21_sum_or_sub(matrix_t *A, matrix_t *B, matrix_t *result, char sign) {
  int status = OK;
  if (s21_is_valid_matrix(A) && s21_is_valid_matrix(B) && s21_is_ptr(result)) {
    if (s21_is_same_matrix(A, B)) {
      if (!s21_create_matrix(A->rows, A->columns, result)) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = (sign == '+')
                                       ? A->matrix[i][j] + B->matrix[i][j]
                                       : A->matrix[i][j] - B->matrix[i][j];
          }
        }
      } else {
        status = INCORRECT_MATRIX;
      }
    } else {
      status = ERR_CALC;
    }
  } else {
    status = INCORRECT_MATRIX;
  }
  return status;
}

void s21_create_minor_matrix(matrix_t *A, matrix_t *result) {
  if (A->columns == 1) {
    result->matrix[0][0] = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    double determinant = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        s21_create_matrix_for_determinant(A, &tmp, i, j);
        s21_determinant(&tmp, &determinant);
        result->matrix[i][j] = determinant * s21_get_sign(i, j);
        s21_remove_matrix(&tmp);
      }
    }
  }
}

void s21_create_matrix_for_determinant(matrix_t *A, matrix_t *result,
                                       int skip_row, int skip_col) {
  if (!s21_create_matrix(A->rows - 1, A->rows - 1, result)) {
    int row = 0;
    for (int i = 0; i < A->rows; i++) {
      if (i == skip_row) {
        continue;
      }
      for (int j = 0, col = 0; j < A->columns; j++) {
        if (j == skip_col) {
          continue;
        }
        result->matrix[row][col++] = A->matrix[i][j];
      }
      row++;
    }
  }
}

double s21_get_det(matrix_t *A, int size_A) {
  double d = 0;
  if (size_A == 2) {
    d += A->matrix[0][0] * A->matrix[1][1] - A->matrix[1][0] * A->matrix[0][1];
  } else {
    int i = 0;
    while (i < size_A) {
      matrix_t tmp = {0};
      s21_create_matrix_for_determinant(A, &tmp, i, 0);
      d += A->matrix[i][0] * s21_get_sign(i, 0) * s21_get_det(&tmp, size_A - 1);
      s21_remove_matrix(&tmp);
      i++;
    }
  }
  return d;
}
