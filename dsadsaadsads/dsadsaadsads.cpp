#include <iostream>
#include <locale.h>
#include <stdlib.h>

int yarik_debilishe_tuporiloe()
{
    int a, b;
    float c;
    printf("Коэффициент обмена: 100 рублей к 65 гривни. Введите сумму(в рублях) которую вы хотите обменять: ");
    scanf_s("%d", &a);
    c = (65 * a / 100) % 1;
    if (c != 0) {
        printf("\n Ваша сдача: ", c , "руб.");
    }
    b = 65 * a / 100;
    printf("\n Вы получаете ", b, "грн.");
    return b;
}
int std_game(int points) {
    int a, b, c, d, min_a, max_a, chc_in, try_count, bet;
    char ans_in;

    a = points;
    b = 1;
    if (a == 0){
        printf("\n Если вы хотите играть вам нужно обменять рубли на гривны. На данный моменту у вас 0 гривней.");
        return 0;
    }
    else {
        while ((b == 1) && (a != 0))
        {
            printf("%s", "\n У вас на балансе %a гривней. Вы хотите играть? [1 - это да/0 - это ярик дурак] \n");
            scanf_s("%d", &chc_in);
            if (chc_in == 1) {
                printf("\nВведите два числа определяющих диапозон загадываемых чисел: ");
                scanf_s("%d", &ans_in);
                min_a = int(ans_in);
                scanf_s("%d", &max_a);
                if (max_a < min_a) {
                    min_a = max_a;
                    max_a = int(ans_in);
                }
                c = min_a + rand()%(max_a - min_a + 1);
                try_count = 0;
                d = 0;
                while (d != c) 
                {
                    printf("\nВведите число: ");
                    scanf_s("%d", &d);
                    try_count += 1;
                    if (d < c) {
                        printf("\n Ваше число меньше чем загаданное.");

                    }
                    else if (d > c) {
                        printf("\n Ваше число больше чем загаданное.");
                    }
                    else if (d == c) {
                        printf("\n Вы угадали число за ", try_count, "попыток");
                        return(bet, try_count);
                    }

                }



               


            }

        }

    }
}


int main()
{
    char* locale = setlocale(LC_ALL, "");
}

 
