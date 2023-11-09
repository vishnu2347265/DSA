#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char name[50];
  int id;
  int quantity;
  float price;
  int medicine_sold_per_year[9]; // {2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024, 2025}
} Medicine;

void convert_medicine_sold_per_year_to_matrix(Medicine* medicine, int** matrix) {
  // Initialize the matrix.
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = 0;
    }
  }

  // Copy the medicine sold per year data to the matrix.
  int year = 2017;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix[i][j] = medicine->medicine_sold_per_year[year];
      year++;
    }
  }
}

int main() {
  // Create two medicine structures.
  Medicine medicine1 = {
    "Paracetamol",
    1,
    10,
    10.00,
    {100, 200, 300, 400, 500, 600, 700, 800, 900}
  };

  Medicine medicine2 = {
    "Ibuprofen",
    2,
    20,
    20.00,
    {200, 400, 600, 800, 1000, 1200, 1400, 1500, 1600}
  };

  // Create two 3 * 3 matrices to store the converted medicine sold per year data.
  int** matrix1 = malloc(sizeof(int*) * 3);
  for (int i = 0; i < 3; i++) {
    matrix1[i] = malloc(sizeof(int) * 3);
  }

  int** matrix2 = malloc(sizeof(int*) * 3);
  for (int i = 0; i < 3; i++) {
    matrix2[i] = malloc(sizeof(int) * 3);
  }

  // Convert the medicine sold per year data for both medicines to the matrices.
  convert_medicine_sold_per_year_to_matrix(&medicine1, matrix1);
  convert_medicine_sold_per_year_to_matrix(&medicine2, matrix2);

  // Print the matrices.
  printf("Matrix for medicine 1:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("\nMatrix for medicine 2:\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      printf("%d ", matrix2[i][j]);
    }
    printf("\n");
  }

  // Free the memory allocated for the matrices.
  for (int i = 0; i < 3; i++) {
    free(matrix1[i]);
  }
  free(matrix1);

  for (int i = 0; i < 3; i++) {
    free(matrix2[i]);
  }
  free(matrix2);

  return 0;
}

