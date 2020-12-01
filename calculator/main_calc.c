//Пономарев Игорь
//Калькулятор
#include <stdio.h>
int main(int argc, char *argv[]) {
// какая то фигня
    int a, b ;
    char c;
    char r = 'y';
    do {
        printf("Enter operation type: \n");
        printf("'+' - addition..........(X+Y)\n");
        printf("'-' - subtraction.......(X-Y)\n");
        printf("'/' - division..........(X/Y)\n");
        printf("'*' - multiplication....(X*Y)\n");
        printf("'!' - factorial.........(X)\n");
        printf("'^' - power.............(X^Y)\n");
        scanf(" %c", &c);

        if (c == '!') { // Если нужно  найти факториал числа то вводим одну переменную
            printf("Enter 'X': \n");
            scanf("%i", &a); //Ввод переменной
        } else {        //В остальных случаях требуется двепеременных
            printf("Enter 'X': \n");
            scanf("%i", &a); //Ввод переменной 1

            printf("Enter 'Y': \n");
            scanf("%i", &b); //Ввод переменной 2
        }

        switch (c) {
        case '+': //1. Сложение
            printf("Result: %i \n", a + b); //Вывод результата
            break;

        case '-': //2. Вычитание
            printf("Result: %i \n", a - b); //Вывод результата
            break;

        case '*': //3. Умножение
            printf("Result: %i \n", a * b); //Вывод результата
            break;

        case '/': //4. Деление
            if (b == 0) {                        //Проверка деления на 0
                printf("Error!\n");          //Сообщение об ошибке
                break;
            } else {
                printf("Result: %i \n", a / b);
            } //Вывод результата
            break;

        case '!':                           //5. Вычисление факториала числа
            //Factorial
            b = 1;                         //Стартовое значение переменной
            for (int i = 1; i <= a; i++) { //Цикл для вычисления факториала
                b = b * i;                  //счетчик факториала
            }
            printf("Factorial of %i is: %i \n", a, b); //Вывод результата
            break;

        case '^':                           //6. Операция возведения в степень
            if (b < 0)   //Если степень меньше 0, то выводим сообщение об ошибке
                printf("Error! Power can't be a negative. \n");
            if (b == 0) {                   //Если степень числа равна нулю
                a = 1;                      //Присваиваем результату значение 1
                printf("Result: %i \n", a);
            }
            if (b == 1) {                   //Если степень числа равна 1
                printf("Result: %i \n", a); //Вывод результата
            }

            if (b > 1) {
                int buff = a; //Сохраняем в "буферную" переменную исходное число
                for (int i = 2; i <= b; i++) {//Цикл для пошагового вычисления
                    a = a * buff;           //По шагам возводим в степень
                }
                printf("Result: %i \n", a); //Результат Возведения в степень
            }
            break;

        default: //Случай ошибки при вводе операции
            printf("Error. Unknown operation. \n");

        }

        printf("Repeat programm? (y/n)"); //Запрос повторения программы
        scanf(" %c", &r);//Ввод ответа пользователя для повторения программы
    } while (r != 'n');

    return 0;
}
