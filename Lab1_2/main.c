#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
// Математична функція
double f(double x)
{
    return 2 * pow(x - 1000, 3)
         - 3 * pow(x + 500, 2)
         + 4 * x
         - 5;
}

int main()
{
    int variant = 0;
    double x1, x2, delta;
    unsigned int N;

// Цикл валідації номера варіанта введення
    while (variant != 1 && variant != 2)
    {
        printf("Оберіть варіант (1 - за N, 2 - за delta): ");
        scanf("%d", &variant);

        if (variant != 1 && variant != 2)
        {
            printf("Помилка! Введіть 1 або 2.\n");
        }
    }

    printf("Введіть X1: ");
    scanf("%lf", &x1);

    printf("Введіть X2: ");
    scanf("%lf", &x2);

    if (variant == 1)
    {
        printf("Введіть кіл-ть точок N: ");
        scanf("%u", &N);

// Обчислення кроку delta
        delta = (x2 - x1) / (N - 1);
    }
    else
    {
        printf("Введіть дельту: ");
        scanf("%lf", &delta);

// Обчислення кількості точок N
        N = (unsigned int)((x2 - x1) / delta) + 1;
    }

// Виведення введених початкових даних
    printf("\nX1=%.2lf, X2=%.2lf, delta=%.2lf\n\n",
           x1, x2, delta);

// Верх таблиці
    printf("*******************************************************\n");
    printf("*   N  *        X         *          F(X)             *\n");
    printf("*******************************************************\n");

    int line_count = 0;
    int is_first_screen = 1;

    double prev_x = x1;
    double prev_y = f(x1);

    for (unsigned int i = 1; i <= N; i++)
    {
        double x = x1 + (i - 1) * delta;
        double y = f(x);

// Форматоване вивведення рядку
        printf("*%5u * %17.2lf * %25.2lf *\n",
               i, x, y);

        printf("-------------------------------------------------------\n");

// Перевірка зміни знаку функції
        if (i > 1 && prev_y * y <= 0)
        {
            printf(" --> Корінь на інтервалі: [%.2lf; %.2lf]\n",
                   prev_x, x);

            printf("-------------------------------------------------------\n");
        }

        prev_x = x;
        prev_y = y;

        line_count++;

// Пауза після заповнення екрана
        if (line_count == 8 && i < N)
        {
            if (is_first_screen)
            {
                printf("\nPress Any Key to Continue...");
                is_first_screen = 0;
            }

            getch();
            printf("\n");

            line_count = 0;
        }
    }

    return 0;
}
