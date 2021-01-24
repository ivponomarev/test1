//Пономарев Игорь
//Калькулятор с записью и чтением в файл
#include <stdio.h>

//структура для вводных данных
typedef struct {
    int x;
    int y;
} variables;

typedef struct {
    char c;
    char r;
} commands;

typedef struct {

    variables a;
    commands com;

} equation;
/////////////////////

equation eq1; //список для читаемых данных из файла
equation outData; //список для записываемых данных в файл

int main(int argc, char *argv[]) {

    int a, b;
    char c;
    char r = 'n';

    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    do {

        //Читаем из файла в список (структуру)
        fscanf(input, "%c", &eq1.com.c);
        fscanf(input, "%c", &eq1.com.r);
        fscanf(input, "%i ", &eq1.a.x);
        fscanf(input, "%i ", &eq1.a.y);

        c = eq1.com.c; //сохраняем данные в переменную
        outData.com.c = c; //данные из переменной зписываем в список

        if (c == '!') { // Если нужно  найти факториал числа то вводим одну переменную
            a = eq1.a.x; //Ввод переменной
        } else {        //В остальных случаях требуется две переменных
            a = eq1.a.x; //Ввод переменной 1
            b = eq1.a.y; //Ввод переменной 2
        }

        switch (c) {
        case '+': //1. Сложение
            printf("Result: %i \n", a + b); //Вывод результата
            outData.a.x = a + b; //Записываем в список
            break;

        case '-': //2. Вычитание
            printf("Result: %i \n", a - b); //Вывод результата
            outData.a.x = a - b; //Записываем в список
            break;

        case '*': //3. Умножение
            printf("Result: %i \n", a * b); //Вывод результата
            outData.a.x = a * b; //Записываем в список
            break;

        case '/': //4. Деление
            if (b == 0) {                        //Проверка деления на 0
                printf("Error!\n");          //Сообщение об ошибке
                outData.a.x = 0;          //Записываем в список
                break;
            } else {

                outData.a.x = a / b;          //Записываем в список
            }
            break;

        case '!':                           //5. Вычисление факториала числа
            //Factorial
            b = 1;                         //Стартовое значение переменной
            for (int i = 1; i <= a; i++) { //Цикл для вычисления факториала
                b = b * i;                  //счетчик факториала
            }
            printf("Factorial of %i is: %i \n", a, b); //Вывод результата
            outData.a.x = a; //Записываем в список
            outData.a.y = b; //Записываем в список
            break;

        case '^': //6. Операция возведения в степень
            if (b < 0)   //Если степень меньше 0, то выводим сообщение об ошибке
                printf("Error! Power can't be a negative. \n");
            outData.a.x = 0;   //Записываем в список
            if (b == 0) {                   //Если степень числа равна нулю
                a = 1;                      //Присваиваем результату значение 1
                printf("Result: %i \n", a);
                outData.a.x = 1;                      //Записываем в список
            }
            if (b == 1) {                   //Если степень числа равна 1
                printf("Result: %i \n", a); //Вывод результата
                outData.a.x = a; //Записываем в список
            }

            if (b > 1) {
                int buff = a; //Сохраняем в "буферную" переменную исходное число
                for (int i = 2; i <= b; i++) { //Цикл для пошагового вычисления
                    a = a * buff;           //По шагам возводим в степень
                }
                printf("Result: %i \n", a); //Результат Возведения в степень
                outData.a.x = a; //Записываем в список
            }
            break;

        default: //Случай ошибки при вводе операции
            printf("Error. Unknown operation. \n");
            outData.a.x = 0; //Записываем в список
            outData.a.y = 0; //Записываем в список

        }

        //printf("Repeat programm? (y/n)"); //Запрос повторения программы
        r = eq1.com.r;
        outData.com.r = r; //Записываем в список

        //Записываем в файл
        fprintf(output, "%c", outData.com.c);
        fprintf(output, "%c", outData.com.r);
        fprintf(output, "%i ", outData.a.x);
        fprintf(output, "%i\n", outData.a.y);

    } while (r != 'n');

    fclose(input);  //закрываем файл
    fclose(output); //закрываем файл

    return 0;
}
