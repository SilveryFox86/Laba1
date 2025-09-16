#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ROWS 10
#define MAX_COLS 10

typedef struct {
    char surname[MAX_NAME_LENGTH];
    char name[MAX_NAME_LENGTH];
    int age;
    float average_grade;
} Student;

void array_range_difference();
void random_array_init();
void custom_size_array();
void matrix_row_column_sum();
void search_student();
void dynamic_square_array(); 

void print_array(int arr[], int size);
int get_int_input(const char* prompt, int min_val, int max_val);
float get_float_input(const char* prompt, float min_val, float max_val);

int main() {
    setlocale(LC_ALL, "");
    int choice;

    srand(time(NULL));

    do {
        printf("\n=== МЕНЮ ПРОГРАММЫ ===\n");
        printf("1. Разница max и min\n");
        printf("2. Массив, случайные числа\n");
        printf("3. Динамичный массив\n");
        printf("4. Сумма значений строки/столбцы\n");
        printf("5. Ввод данных студентов\n");
        printf("6. Двумерный динамический массив\n"); 
        printf("0. Выход\n");
        printf("Выберите пункт меню: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка ввода! Пожалуйста, введите число.\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
        case 1:
            array_range_difference();
            break;
        case 2:
            random_array_init();
            break;
        case 3:
            custom_size_array();
            break;
        case 4:
            matrix_row_column_sum();
            break;
        case 5:
            search_student();
            break;
        case 6:
            dynamic_square_array(); 
            break;
        case 0:
            printf("Выход из программы...\n");
            break;
        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }

        while (getchar() != '\n');

    } while (choice != 0);

    return 0;
}

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

int get_int_input(const char* prompt, int min_val, int max_val) {
    int value;
    int valid_input;

    do {
        printf("%s", prompt);
        valid_input = scanf("%d", &value);

        if (valid_input != 1) {
            printf("Ошибка ввода! Пожалуйста, введите целое число.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (value < min_val || value > max_val) {
            printf("Ошибка! Значение должно быть от %d до %d.\n", min_val, max_val);
            valid_input = 0;
        }

    } while (valid_input != 1 || value < min_val || value > max_val);

    return value;
}


float get_float_input(const char* prompt, float min_val, float max_val) {
    float value;
    int valid_input;

    do {
        printf("%s", prompt);
        valid_input = scanf("%f", &value);

        if (valid_input != 1) {
            printf("Ошибка ввода! Пожалуйста, введите число.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (value < min_val || value > max_val) {
            printf("Ошибка! Значение должно быть от %.1f до %.1f.\n", min_val, max_val);
            valid_input = 0;
        }

    } while (valid_input != 1 || value < min_val || value > max_val);

    return value;
}

void array_range_difference() {
    printf("\n=== Разница между max и min элементами массива ===\n");

    int size = get_int_input("Введите размер массива (1-100): ", 1, 100);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    printf("Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Ошибка ввода! Пожалуйста, введите целое число: ");
            while (getchar() != '\n'); 
        }
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    printf("Массив: ");
    print_array(arr, size);
    printf("Минимальный элемент: %d\n", min);
    printf("Максимальный элемент: %d\n", max);
    printf("Разница: %d - %d = %d\n", max, min, max - min);

    free(arr);
}

void random_array_init() {
    printf("\n=== Инициализация массива случайными числами ===\n");

    int size = get_int_input("Введите размер массива (1-100): ", 1, 100);
    int min_val = get_int_input("Введите минимальное значение: ", -1000, 1000);
    int max_val = get_int_input("Введите максимальное значение: ", min_val, 1000);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % (max_val - min_val + 1) + min_val;
    }

    printf("Сгенерированный массив: ");
    print_array(arr, size);

    free(arr);
}

void custom_size_array() {
    printf("\n=== Создание массива произвольного размерa ===\n");

    int size = get_int_input("Введите размер массива (1-100): ", 1, 100);

    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    printf("Введите %d элементов массива:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Элемент %d: ", i + 1);
        while (scanf("%d", &arr[i]) != 1) {
            printf("Ошибка ввода! Пожалуйста, введите целое число: ");
            while (getchar() != '\n'); 
        }
    }

    printf("Созданный массив: ");
    print_array(arr, size);

    free(arr);
}

void matrix_row_column_sum() {
    printf("\n=== Сумма значений в строках и столбцах матрицы ===\n");


    int rows = get_int_input("Введите количество строк (1-10): ", 1, MAX_ROWS);
    int cols = get_int_input("Введите количество столбцов (1-10): ", 1, MAX_COLS);

    int min_val = get_int_input("Введите минимальное значение для случайных чисел: ", -1000, 1000);
    int max_val;

    do {
        max_val = get_int_input("Введите максимальное значение для случайных чисел: ", min_val, 1000);
        if (max_val < min_val) {
            printf("Максимальное значение не может быть меньше минимального!\n");
        }
    } while (max_val < min_val);

    int matrix[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = rand() % (max_val - min_val + 1) + min_val;
        }
    }

    printf("\nСгенерированная матрица %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nСуммы строк:\n");
    for (int i = 0; i < rows; i++) {
        int row_sum = 0;
        for (int j = 0; j < cols; j++) {
            row_sum += matrix[i][j];
        }
        printf("Строка %d: %d\n", i + 1, row_sum);
    }

    printf("\nСуммы столбцов:\n");
    for (int j = 0; j < cols; j++) {
        int col_sum = 0;
        for (int i = 0; i < rows; i++) {
            col_sum += matrix[i][j];
        }
        printf("Столбец %d: %d\n", j + 1, col_sum);
    }
}

void search_student() {
    printf("\n=== Ввод данных студентов и поиск ===\n");

    Student students[MAX_STUDENTS];
    int count;

    count = get_int_input("Введите количество студентов (1-100): ", 1, MAX_STUDENTS);

    printf("Введите данные %d студентов (используя английские символы):\n", count);
    for (int i = 0; i < count; i++) {
        printf("\nСтудент %d:\n", i + 1);
        printf("Фамилия: ");
        scanf("%s", students[i].surname);
        printf("Имя: ");
        scanf("%s", students[i].name);

        students[i].age = get_int_input("Возраст: ", 1, 100);
        students[i].average_grade = get_float_input("Средний балл: ", 1, 100);
    }

    printf("\nВведенные данные студентов:\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s %s, возраст: %d, средний балл: %.1f\n",
            i + 1, students[i].surname, students[i].name,
            students[i].age, students[i].average_grade);
    }

    int search_choice;
    do {
        printf("\n=== ПОИСК СТУДЕНТОВ ===\n");
        printf("1 - Поиск по фамилии\n");
        printf("2 - Поиск по имени\n");
        printf("3 - Поиск по возрасту\n");
        printf("4 - Поиск по среднему баллу\n");
        printf("0 - Вернуться в главное меню\n");

        search_choice = get_int_input("Выберите тип поиска: ", 0, 4);

        int found = 0;

        switch (search_choice) {
        case 1: {
            char search_surname[MAX_NAME_LENGTH];
            printf("Введите фамилию для поиска: ");
            scanf("%s", search_surname);

            printf("\nРезультаты поиска по фамилии '%s':\n", search_surname);
            for (int i = 0; i < count; i++) {
                // Поиск по неполному совпадению с помощью strstr
                if (strstr(students[i].surname, search_surname) != NULL) {
                    printf("Найден: %s %s, возраст: %d, средний балл: %.1f\n",
                        students[i].surname, students[i].name,
                        students[i].age, students[i].average_grade);
                    found = 1;
                }
            }
            break;
        }
        case 2: {
            char search_name[MAX_NAME_LENGTH];
            printf("Введите имя для поиска: ");
            scanf("%s", search_name);

            printf("\nРезультаты поиска по имени '%s':\n", search_name);
            for (int i = 0; i < count; i++) {
                // Поиск по неполному совпадению с помощью strstr
                if (strstr(students[i].name, search_name) != NULL) {
                    printf("Найден: %s %s, возраст: %d, средний балл: %.1f\n",
                        students[i].surname, students[i].name,
                        students[i].age, students[i].average_grade);
                    found = 1;
                }
            }
            break;
        }
        case 3: {
            int search_age = get_int_input("Введите возраст для поиска: ", 1, 100);

            printf("\nРезультаты поиска по возрасту %d:\n", search_age);
            for (int i = 0; i < count; i++) {
                if (students[i].age == search_age) {
                    printf("Найден: %s %s, возраст: %d, средний балл: %.1f\n",
                        students[i].surname, students[i].name,
                        students[i].age, students[i].average_grade);
                    found = 1;
                }
            }
            break;
        }
        case 4: {
            float search_grade = get_float_input("Введите средний балл для поиска: ", 1, 100);

            printf("\nРезультаты поиска по среднему баллу %.1f:\n", search_grade);
            for (int i = 0; i < count; i++) {
                if (students[i].average_grade == search_grade) {
                    printf("Найден: %s %s, возраст: %d, средний балл: %.1f\n",
                        students[i].surname, students[i].name,
                        students[i].age, students[i].average_grade);
                    found = 1;
                }
            }
            break;
        }
        case 0:
            printf("Возврат в главное меню, нажмите Enter...\n");
            break;
        }

        if (search_choice >= 1 && search_choice <= 4 && !found) {
            printf("Студенты с указанными параметрами не найдены.\n");
        }

        while (getchar() != '\n');

    } while (search_choice != 0);
}
void dynamic_square_array() {
    printf("\n=== Двумерный динамический квадратный массив ===\n");

    int size = get_int_input("Введите размер квадратного массива (1-20): ", 1, 20);

   
    int** array = (int**)malloc(size * sizeof(int*));
    if (array == NULL) {
        printf("Ошибка выделения памяти!\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        array[i] = (int*)malloc(size * sizeof(int));
        if (array[i] == NULL) {
            printf("Ошибка выделения памяти!\n");
      
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return;
        }
    }


    printf("\nСгенерированный массив %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            array[i][j] = rand() % 31 - 10; 
            printf("%4d", array[i][j]);
        }
        printf("\n");
    }

    int zeroCount = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (array[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    printf("\nКоличество нулевых элементов: %d\n", zeroCount);


    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    printf("Память успешно освобождена.\n");
}

