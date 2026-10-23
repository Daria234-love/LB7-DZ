#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

int task1(void);
int task2(void);
int task3(void);

int task1(void)
{
    char c;
    printf("Введите один символ: ");

    if (scanf(" %c", &c) != 1)
    {
        printf("Ошибка ввода.\n");
        return 1;
    }

    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        printf("Символ '%c' — это цифра.\n", c);
        break;

    default:
        if (isalpha((unsigned char)c))
        {
            printf("Символ '%c' — это буква.\n", c);
        }
        else
        {
            printf("Символ '%c' — это не буква и не цифра.\n", c);
        }
        break;
    }

    return 0;
}

int task2(void)
{
    float x, y;
    char c;

    printf("Введите выражение без пробелов, например 12.5+3.2: ");

 
    if (scanf("%f%c%f", &x, &c, &y) != 3)
    {
        printf("Ошибка ввода выражения.\n");
        return 1;
    }

    switch (c)
    {
    case '+':
        printf("Результат = %f\n", x + y);
        break;

    case '-':
        printf("Результат = %f\n", x - y);
        break;

    case '*':
        printf("Результат = %f\n", x * y);
        break;

    case '/':
        if (y == 0.0f)
        {
            printf("На ноль делить нельзя.\n");
        }
        else
        {
            printf("Результат = %f\n", x / y);
        }
        break;

    case '^':
        printf("Результат = %f\n", pow(x, y));
        break;

    default:
        printf("Неизвестная операция '%c'.\n", c);
        break;
    }

    return 0;
}

const char* ruble_word(int n)
{
    int last_two = n % 100;
    int last = n % 10;

    if (last_two >= 11 && last_two <= 14)
        return "рублей";

    if (last == 1)
        return "рубль";

    if (last >= 2 && last <= 4)
        return "рубля";

    return "рублей";
}

const char* kopeck_word(int n)
{
    int last_two = n % 100;
    int last = n % 10;

    if (last_two >= 11 && last_two <= 14)
        return "копеек";

    if (last == 1)
        return "копейка";

    if (last >= 2 && last <= 4)
        return "копейки";

    return "копеек";
}

int task3(void)
{
    int price_kopecks;
    int rubles;
    int kopecks;

    printf("Введите стоимость в копейках: ");

    if (scanf("%d", &price_kopecks) != 1 || price_kopecks < 0)
    {
        printf("Введите неотрицательное целое число.\n");
        return 1;
    }

    rubles = price_kopecks / 100;
    kopecks = price_kopecks % 100;

    printf("Стоимость: %d %s %d %s\n",
        rubles, ruble_word(rubles),
        kopecks, kopeck_word(kopecks));

    return 0;
}

int main(void)
{
    setlocale(LC_CTYPE, "RUS");

    task1();
    task2();
    task3();

    system("pause");
    return 0;
}