#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <cstdio>

int yarik_debilishe_tuporiloe()
{
    int a, b;
    printf("Коэффициент обмена: 100 рублей к 65 гривни. Взнос минимум 100 рублей. Введите сумму(в рублях) которую вы хотите обменять: ");
    scanf_s("%d", &a);
    if (a > 100) {
        b = 65 * a / 100;
        printf("Вы получаете %d грн.", b);
    }
    else {
        printf("Ваш ввод неверен.");
        b = 0;
    }
    return b;
}
int rus_roulette() {
    printf("\nРусская рулетка:\n");
    srand(time(NULL));
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
                printf("\nВы проиграли все ваши деньги.");
                return 0;
                c = 0;
            }
            else {
                printf("\nВы остаетесь в игре.");
                surv_count += 1;
            }
            break;
        case 2:
            printf("\nБарабан прокручен");
            break;
        case 3:
            printf("\nДо новых встреч");
            return (surv_count + 1);
            break;
        default:
            printf("\nВвод данных неверен, попробуйте ещё раз.");
            break;

        }
    }
}
int std_game(int points) {
    int a, b, c, d, min_a, max_a, chc_in, try_count, bet, max_try, gain, input_flag, ans_in, bet_flag, max_flag, win_flag, mmd_flag;
    srand(time(NULL));
    a = points;
    b = 1;
    bet = 0;
    bet_flag = 1;
    max_flag = 1;
    mmd_flag = 1;
    win_flag = 0;
    gain = 0;
    if (a == 0) {
        printf("\nЕсли вы хотите играть вам нужно обменять рубли на гривны. На данный моменту у вас 0 гривней.");
        return 0;
    }
    else {
        while ((b == 1) && (a != 0))
        {
            printf("\nУ вас на балансе %d гривней. Вы хотите играть? [1 - это да/0 - это нет]\n", a);
            scanf_s("%d", &chc_in);
            switch (chc_in) {
            case 1:
                while (bet_flag == 1) {
                    printf("\nВведите вашу ставку: ");
                    scanf_s("%d", &bet);
                    if (bet <= a) {
                        bet_flag = 0;
                    }
                    else {
                        printf("\nУ вас нет столько гривен.");
                    }
                }
                while (mmd_flag == 1) {
                    printf("\nВведите два числа определяющих диапозон загадываемых чисел. Минимальный диапазон(разница максимального и минимального числа) должен быть равен 2.\n");
                    scanf_s("%d", &ans_in);
                    min_a = int(ans_in);
                    scanf_s("%d", &max_a);
                    if (max_a < min_a) {
                        min_a = max_a;
                        max_a = int(ans_in);
                    }
                    if ((max_a - min_a) > 2) {
                        mmd_flag = 0;
                    }
                    else {
                        printf("Вы ввели недопустимый диапазон.");
                    }
                }

                c = min_a + rand() % (max_a - min_a + 1);
                while (max_flag == 1) {
                    printf("\nВведите число попыток за которое вы планируете отгадать число: ");
                    scanf_s("%d", &max_try);
                    if (max_try >= 1) {
                        max_flag = 0;
                    }
                    else {
                        printf("\nВы ввели недопустимое число попыток за которое можно отгадать число.");
                    }
                }

                try_count = 0;
                d = 0;
                while ((d != c) && (max_try > try_count))
                {
                    printf("\nВведите число: ");
                    scanf_s("%d", &d);
                    try_count += 1;
                    if (d < c) {
                        printf("\nВаше число меньше чем загаданное.");

                    }
                    else if (d > c) {
                        printf("\nВаше число больше чем загаданное.");
                    }
                    else if (d == c) {
                        printf("\nВы угадали число за %d попыток", try_count);
                        win_flag = 1;
                    }

                }
                if (win_flag != 1) {
                    printf("\nК сожалению вы не смогли угадать число за %d попыток. Вы полностью теряете вашу ставку.", max_try);
                    gain = 0;
                }
                else {
                    if (1 + (try_count / log2(max_a - min_a)) > 1) {
                        gain = bet * (1 + try_count / log2(max_a - min_a));
                    }
                    else {
                        gain = bet * 0, 95;
                    }
                    printf("\nВаш выигрыш равен %d грн.", gain);
                }
                break;


            case 0:
                printf  ("Хорошо. Мы возвращаем вас в главное меню.");
                return(0);
                break;
            default:
                printf("\nВвод данных неверен, попробуйте ещё раз.");
            }
            break;
        }
        return(gain - bet);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int flag, bipki, x, wn;
    bipki = 0;
    flag = 1;
    printf("\nПриветствуем вас в Казино!С чего желаете начать?\n");
    while (flag == 1) {

        printf("\nНа вашем счету %d грн.", bipki);
        printf("\nНажмите 1, если хотите узнать правила игры.");
        printf("\nНажмите 2, если хотите обменять денгбе.");
        printf("\nНажмите 3, если желаете покинуть Казино.");
        printf("\nНажмите 4, если хотите начать игру.");
        printf("\nНажмите 5, если хотите анекдот.");
        printf("\nНажмите 6, если хотите сыграть в русскую рулетку.\n");
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
            printf("\nДо свидания, возвращайтесь к нам поскорее :(");
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
            wn = bipki * (x - 1);
            if (x > 0) {
                printf("Ваш выигрыш равен %d грн.", wn);
                bipki = bipki * x;
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


