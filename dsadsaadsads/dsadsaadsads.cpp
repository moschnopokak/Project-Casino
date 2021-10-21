#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <cstdio>

int yarik_debilishe_tuporiloe()
{
    int a, b;
    float c;
    printf("\nКоэффициент обмена: 100 рублей к 65 гривни. Введите сумму(в рублях) которую вы хотите обменять: ");
    scanf_s("%d", &a);
    c = (65 * a / 100) % 1;
    if (c != 0) {
        printf("\n Ваша сдача: %d руб.", c);
    }
    b = 65 * a / 100;
    printf("\n Вы получаете %d грн.", b);
    return b;
}
int rus_roulette() {
    printf("\nРусская рулетка:\n");
    int c, b, bullet, game, surv_count;
    int a[6];
    c = 1;
    surv_count = 0;
    while (c != 0) {
        printf("\nНажмите 1, если хотите выстрелить.");
        printf("\nНажмите 2, если хотите прокрутить барабан.");
        printf("\nНажмите 3, если хотите выйти.");
        a[0] = 0;
        a[1] = 0;
        a[2] = 0;
        a[3] = 0;
        a[4] = 0;
        a[5] = 0;
        bullet = rand() % 6;
        printf("%d", bullet);
        a[bullet] = 1;
        scanf_s("%d", &game);
        switch (game) {
        case 1:
            if (a[0] == 1) {
                printf("\n ТЫ УМЕР!");
                return 0;
                c = 0;
            }
            else {
                printf("\n ТЫ КРУТ!");
                surv_count += 1;
            }
        case 2:
            printf("\nБарабан прокручен");
        case 3:
            printf("\nДо новых встреч");
            break;

        }
    }
}
int std_game(int points) {
    int a, b, c, d, min_a, max_a, chc_in, try_count, bet, max_try, gain, input_flag;
    char ans_in;
    a = points;
    b = 1;
    if (a == 0) {
        printf("\n Если вы хотите играть вам нужно обменять рубли на гривны. На данный моменту у вас 0 гривней.");
        return 0;
    }
    else {
        while ((b == 1) && (a != 0))
        {
            printf("\nУ вас на балансе %d гривней. Вы хотите играть? [1 - это да/0 - это ярик дурак]", a);
            scanf_s("%d", &chc_in);
            if (chc_in == 1) {

                printf("\nВведите вашу ставку: ");
                scanf_s("%d", &bet);
                printf("\nВведите два числа определяющих диапозон загадываемых чисел: ");
                scanf_s("%d", &ans_in);
                min_a = int(ans_in);
                scanf_s("%d", &max_a);
                if (max_a < min_a) {
                    min_a = max_a;
                    max_a = int(ans_in);
                }
                c = min_a + rand() % (max_a - min_a + 1);
                printf("\nВведите число попыток за которое вы планируете отгадать число: ");
                scanf_s("%d", &max_try);
                try_count = 0;
                d = 0;
                while ((d != c) && (max_try >= try_count))
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
                        printf("\n Вы угадали число за %d попыток", try_count);
                    }

                }
                if (try_count > max_try) {
                    printf("\nК сожалению вы не смогли угадать число за %d попыток. Вы полностью теряете вашу ставку.", max_try);
                    gain = 0;
                }
                else {
                    gain = 5 * bet / (max_try * try_count);
                    printf("\nВаш выигрыш равен %d грн.", gain);
                }
                return(gain - bet);
            }
        }
    }
    return(gain - bet);
}


int main()
{
    setlocale(LC_ALL, "Rus");
    int flag, bipki, x;
    bipki = 0;
    flag = 1;
    printf("\nПриветствуем вас в Казино!С чего желаете начать?\n");
    while (flag == 1) {

        printf("\nНа вашем счету %d грн.", bipki);
        printf("\nНажмите 1, если хотите узнать правила игры.");
        printf("\nНажмите 2, если хотите обменять денгбе.");
        printf("\nНажмите 3, если желаете покинуть Казино.");
        printf("\nНажмите 4, если хотите начать игру");
        printf("\nНажмите 5, если хотите анекдот");
        printf("\nНажмите 6, если хотите сыграть в русскую рулетку")
        int input;
        scanf_s("%d", &input);
        switch (input) {
        case 1:
            printf("\nПравила игры таковы: вы выбираете диапазон чисел, после чего вам будет предложено угадать число, выбранное программой из вашего диапазона. Чем меньше попыток вам понадобиться, тем больше будет полученный профит. Размер выигрыша так же зависит и от размера выбранного диапазона. Чтобы начать играть, вам нужно перевести ваши рубли в гривны.");
            break;
        case 2:
            bipki += yarik_debilishe_tuporiloe();
            break;
        case 3:
            printf("До свидания, возвращайтесь к нам поскорее :(\n");
            flag = 0;
            break;
        case 4:
            bipki += std_game(bipki);
            break;
        case 5:
            printf("\n- Слушай, Изя, я знаю гениальный способ, как в ресторане бесплатно поесть. - А ну, Абрам, рассказывай. - Идёшь в хорошее заведение незадолго до закрытия.Заказываешь закусочку, лучшие блюда, десерт, коньяк.Когда все официанты разойдутся, последний подойдёт к тебе, а ты говоришь : А я уже заплатил вашему товарищу, который ушёл. На следующий день пошли в ресторан. Заказывают всё по полной программе и сидят.Наконец подходит последний официант : -Извините, но пора закрывать, прошу оплатить заказ. Абрам : -Но мы уже вашему коллеге деньги дали. Изя :-Кстати, нам ещё долго ждать сдачу ?");
            break;
        case 6:
            x = rus_roulette();
            if (x > 0) {
                bipki = bipki ^ x;
            }
            else {
                bipki = 0;
            }
            break;
        default:
            printf("\nВвод данных неверен, попробуйте ещё раз.");
            break;
        }
    }
}


