#include <iostream>

using namespace std;
// Ошибки по стилю кода:
// Правлю первый и последний раз
// 1. Необходимо использовать camelCase либо under_score
// 2. Необходимо использовать const там, где это возможно
// 3. Добавляйте в .gitignore файлы, которые не должны попадать в репозиторий к примеру файлы сборки

// Можем собраться и подумать
// Нужна ли нам эта функция вообще
// Максимальное int число 0x7FFFFFFF -> 10 символов, следовательно максимальная длина строки 12 символов учитывая \0
// Зато сложность нашего алгоритма будет O(n) где n - длина числа
// Мы же проходим по числу дважды, следовательно сложность O(2n), что конечно в глобальном смысле роли не играет
// Но все же

// Программа не собирается
// Отсутствует CMake проект
// Необходимо добавить в .gitignore файлы сборки
// Необходимо написать тесты используя assert()

// хау ту юз ассерт ?
// #include <cassert>
// assert(1 == 2);

int getIntLen(int num) {
    int length = 0;
    while (num > 0) {
        num = num / 16;
        length = length + 1;
    }
    return length;
}

char *intTohex(int num) {
    bool is_negative = (num < 0) ? true : false;
    int total_length;

    if (is_negative) {
        total_length = getIntLen(num) + 3;
    } else {
        total_length = getIntLen(num) + 2;
    }

    char *result = new char[total_length + 1];
    result[total_length + 1] = 0;

    int i;
    if (is_negative) {
        num = num * (-1);
        result[0] = '-';
        result[1] = '0';
        result[2] = 'x';
        i = getIntLen(num) + 2;
    } else {
        result[0] = '0';
        result[1] = 'x';
        i = getIntLen(num) + 1;
    }

    while (num > 0) {
        int ost = num % 16;
        char res;

        if (ost > 9) {
            /// я вообще не помню что такое таблица какой код какой символ
            /// в таблице ASCII 64 = '@'?
            res = char(64 + (ost - 9));
        } else {
            res = char(48 + ost);
        }

        result[i] = res;
        num = num / 16;
        i = i - 1;
    }

    return result;
}

/// тесты!
int main() {
    int n;
    cin >> n;
    cout << intTohex(n) << endl;
}