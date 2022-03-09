//
// Created by Ростислав on 09.03.2022.
//

#include <iostream>
#include <vector>

typedef std::vector<std::pair<int, int>> graphic;

graphic assignSet() {
    using namespace std;
    // 1.1.1. Пользователь задаёт мощность графика.
    cout << "Введите мощность графика: ";
    int c1; cin >> c1;
    // 1.1.2. Пользователь вводит пары графика.
    cout << "Введите пары графика: " << endl;
    graphic A;
    for (int i = 0; i < c1; i++) {
        int pair_1, pair_2;
        cin >> pair_1 >> pair_2;
        A.emplace_back(pair_1, pair_2);
    }
    return A;
}

graphic unite(graphic A, const graphic& B) {
    using namespace std;
    // Создаём пустой график D.
    graphic D;
    pair<int, int> curB, curD;
    int countB, countD;
    // Каждый элемент графика А переносим в D.
    D = graphic(A);

    // Возьмём первую пару графика B.
    countB = 0; curB = B[countB];
    p3_4:
    // Возьмём первую пару графика D.
    countD = 0; curD = D[countD];

    p3_5:
    // Проверим, неравны ли пары
    // Если первый элемент взятой пары графика В не равен первому элементу
    // взятой пары графика D, переходим к пункту 3.7.
    if (curB.first != curD.first)   goto p3_7;
    // Если второй элемент взятой пары графика В не равен второму элементу
    // взятой пары графика D, переходим к пункту 3.7.
    if (curB.second != curD.second) goto p3_7;

    // Переходим к пункту 3.11
    goto p3_11; // 3.11

    // Если взятая пара графика D - последняя, переходим к пункту 3.10.
    p3_7:
    if (D.size() - 1 == countD) goto p3_10;

    // Если звятая пара графика D - не последняя, то возьмём следующую
    // пару графика D.
    curD = D[++countD];
    goto p3_5;

    // Добавим взятую пару графика B в график D.
    p3_10:
    D.emplace_back(curB);

    // Если взятая пара графика В - последняя, то переходим к пункту 14.
    p3_11:
    if (countB == B.size() - 1)
        return D;

    // Если взятая пара графика В - не последняя, то возьмём следущую
    // пару графика В.
    curB = B[++countB];
    goto p3_4;

}

graphic intersect(graphic A, graphic B) {
    using namespace std;

    // Создадим новый пустой график D.
    graphic D;
    pair<int, int> curA, curB;
    int countA, countB;

    // Возьмём первую пару графика A.
    countA = 0; curA = A[countA];
    p4_3:
    // Возьмём первую пару графика B.
    countB = 0; curB = B[countB];

    p4_4:
    // Проверим неравны ли пары
    // Если первый элемент взятой пары графика А неравен
    // первому элементу взятой пары графика В, то переходим к п. 4.6
    if (curA.first != curB.first) goto p4_6;
    // Если второй элемент взятой пары графика А неравен
    // второму элементу взятой пары графика В, то переходим к п. 4.6
    if (curA.second != curB.second) goto p4_6;

    // Добавляем взятую пару графика А во множество D и переходим к
    // пункту 4.9.
    D.emplace_back(curA);
    goto p4_9;

    // Если взятая пара графика В - последняя, то переходим к пункту
    // 4.9
    p4_6:
    if (countB == B.size() - 1) goto p4_9;

    // Если взятая пара графика В - не последняя, то возьмём следующий
    // элемент графика В.
    curB = B[++countB];

    // Перейдём к пункту 4.4.
    goto p4_4;

    // Если взятая пара графика А - последняя, то переходим к пункту 14.
    p4_9:
    if (countA == A.size() - 1)
        return D;

    // Если взятая пара графика А - не последняя, то возьмём следующую
    // пару графика А.
    curA = A[++countA];

    // Перейдём к пункту 4.3.
    goto p4_3;

}

graphic diff(graphic A, graphic B) {

    using namespace std;

    // Создадим новый пустой график D.
    graphic D;
    pair<int, int> curA, curB;
    int countA, countB;

    // Возьмём первую пару графика A.
    countA = 0; curA = A[countA];
    p5_3:
    // Возьмём первую пару графика B.
    countB = 0; curB = B[countB];

    p5_4:
    // Проверим, равны ли графики
    // Если первый элемент взятой пары графика А неравен первому
    // элементу взятой пары графика В, перейдём к пункту 5.5
    if (curA.first != curB.first) goto p5_5;
    // Если второй элемент взятой пары графика А равен второму
    // элементу взятой пары графика В, перейдём к пункту 5.9.
    if (curA.second == curB.second) goto p5_9;

    p5_5:
    // Если взятая пара графика В является последней, перейдём к пункту 5.8.
    if (countB == B.size() - 1) goto p5_8;

    // Если взятая пара графика В не является последней,
    // возьмём следущую пару графика В.
    curB = B[++countB];

    // Перейдём к пункту 5.4.
    goto p5_4;

    // Добавляем взятую пару графика А в график D.
    p5_8:
    D.emplace_back(curA);

    p5_9:
    // Если взятая пара графика А является последней, перейдём к пункту 14.
    if (countA == A.size() - 1)
        return D;

    // Если взятая пара графика А не является последней, возьмём следующую
    // пару графика А.
    curA = A[++countA];

    // Перейдём к пункту 5.3.
    goto p5_3;

}

graphic sym_diff(graphic A, graphic B) {

    // Разность графиков A и B
    graphic C = diff(A, B);

    // Разность графиков В и А
    graphic F = diff(B, A);

    // Объединение графиков C и F
    return unite(C, F);

}

graphic universum() {
    using namespace std;
    int x, y;
    pair<int, int> f;
    graphic U;

    // Зададим график U.
    // Присвоими значение х = 1
    x = 1;

    // Присвоим значение y = 1
    y = 1;

    p8_1_2:
    // Если значение y больше или равно 100, перейдём к пункиу 8.1.3.
    if (y >= 100) goto p8_1_3;
    // Перейдём к пункту 8.1.5.
    goto p8_1_5;

    p8_1_3:
    if (x >= 100)
        return U;
    // x = x + 1
    x++;

    // y = 0
    y = 0;

    p8_1_5:
    // y = y + 1
    y++;

    // Создадим пару f, где первая компонента будет равна x,
    // а вторая компонента будет равна y.
    f = make_pair(x, y);

    // Добавим созданную пару в график U.
    U.emplace_back(f);

    // Перейдём к пункту 8.1.2.
    goto p8_1_2;

}

graphic inverse(graphic A) {
    using namespace std;

    // Создадим пустой график D
    graphic D;
    pair<int, int> f, curA;
    int countA;

    // Возьмём первую пару графика А.
    countA = 0; curA = A[countA];

    p10_3:
    // Создадим пару f, где первая компонента будет равна
    // второй компоненте взятой пары графика А, а вторая
    // компонента будет равна первой компоненте взятой пары
    // графика А.
    f = make_pair(curA.second, curA.first);

    // Добавляем пару f в график D.
    D.emplace_back(f);

    // Если взятая пара графика А является  последней, то
    // переходим к пункту 10.8.
    if (countA == A.size() - 1)
        return D;

    // Выбираем следующую пару графика А.
    curA = A[++countA];

    // Переходим к пункту 10.3.
    goto p10_3;

}

graphic compose(graphic A, graphic B) {

    using namespace std;

    // Создадим новый пустой график D.
    graphic D;
    pair<int, int> curA, curB, temp, f;
    int countA, countB, tempCount;

    // Возьмём первую пару графика A.
    countA = 0; curA = A[countA];

    p12_3:
    // Возьмём первую пару графика B.
    countB = 0; curB = B[countB];

    p12_4:
    // Если вторая компонента взятой пары A не равна первой компоненте
    // взятой пары графика В, переходим к пункту 12.7.
    if (curA.second != curB.first) goto p12_7;

    // Создадим пару f, где первая компонента будет равно первой
    // компоненте взятой пары графика А, а вторая компонента
    // будет равна второй компоненте взятой пары графика В.
    f = make_pair(curA.first, curB.second);

    // Добавим пару f в график D.
    p12_6:
    D.emplace_back(f);

    // Если выбранная пара графика В является последней, переходим
    // к пункту 12.10
    p12_7:
    if (B.size() - 1 == countB) goto p12_11;

    // Если выбранная пара графика В не является последней, выбираем
    // следующую пару графика В.
    curB = B[++countB];

    // Переходим к пункту 12.4.
    goto p12_4;

    // Если выбранная пара графика А является последней, переходим к
    // пункту 14.
    p12_11:
    if (A.size() - 1 == countA) return D;

    // Если выбранная пара графика А не является последней, выбираем
    // следующую пару графика А.
    curA = A[++countA];

    // Переходим к пункту 12.4
    goto p12_3;

}

int main() {

    using namespace std;

    setlocale(0, "RUS");

    // 1. Задание множеств
    // 1.1. Пользователь задаёт график А.
    graphic A = assignSet();
    // 1.2. Пользователь задаёт график В:
    graphic B = assignSet();

    // 2. Пользователь задаёт операцию над графиками А и В.
    cout << "Выберите операцию:"
            "\n\t1. Объединение графиков А и В"
            "\n\t2. Пересечение графиков А и В"
            "\n\t3. Разность графиков А и В"
            "\n\t4. Разность графиков В и А"
            "\n\t5. Симметрическая разность графиков А и В"
            "\n\t6. Дополнение графика А"
            "\n\t7. Дополнение графика В"
            "\n\t8. Инверсия графика А"
            "\n\t9. Инверсия графика В"
            "\n\t10. Композиция графиков А и В"
            "\n\t11. Композиция графиков В и А\n"
            "Ваш выбор: ";

    int mode; cin >> mode;

    graphic D;
    switch (mode) {

        // Если пользователь хочет найти объединение графиков А и В, то
        case 1: {
            D = unite(A, B);
            break;
        }

            // Если пользователь хочет найти пересечение графиков А и В, то
        case 2: {
            D = intersect(A, B);
            break;
        }

            // Если пользователь хочет найти разность графиков А и В, то
        case 3: {
            D = diff(A, B);
            break;
        }

            // Если пользоавтель хочет найти разность графиков В и А, то
        case 4: {
            D = diff(B, A);
            break;
        }

            // Если пользователь холет найти симметрическую разность
            // графиков А и В, то
        case 5: {
            D = sym_diff(A, B);
            break;
        }

            // Если пользователь хочет найти дополнение графика А, то
        case 6: {

            // Зададим график U.
            graphic U = universum();
            // Разность графиков U и A.
            D = diff(U, A);
            break;

        }

            // Если пользователь хочет найти дополнение графика В, то
        case 7: {

            // Зададим график U.
            graphic U = universum();
            // Разность графиков U и B.
            D = diff(U, B);
            break;

        }

            // Если пользователь хочет найти инверсию графика А, то
        case 8: {
            D = inverse(A);
            break;
        }

            // Если пользователь хочет найти инверсию графика В, то
        case 9: {
            D = inverse(B);
            break;
        }

            // Если пользотваель хочет найти композицию графиков А и В, то
        case 10: {
            D = compose(A, B);
            break;
        }

            // Если пользователь хочет найти композицию графиков В и А, то
        case 11: {
            D = compose(B, A);
            break;
        }


    }

    cout << "D = { ";
    for (auto pair : D) {
        cout << "<" << pair.first << ", " << pair.second << ">, ";
    }
    cout << "}" << endl;
    return 0;
}
