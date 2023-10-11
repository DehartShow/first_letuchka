#include <iostream>

using namespace std;

// Ошибки по стилю кода:
// Правлю первый и последний раз
// 1. Необходимо использовать camelCase либо under_score
// 2. Необходимо использовать const там, где это возможно
// 3. Добавляйте в .gitignore файлы, которые не должны попадать в репозиторий к примеру файлы сборки

// Можем собраться и подумать
// get_int_lengh - название функции не соответствует ее действию -> правильно length
// Нужна ли нам эта функция вообще
// Максимальное int число 2147483647 -> 10 символов, следовательно мы можем выделить 11 + 3 символов
// 10 для числа 1 для знака два для 0x и один для \0
// Зато сложность нашего алгоритма будет O(n) где n - длина числа
// Мы же проходим по числу дважды, следовательно сложность O(2n), что конечно в глобальном смысле роли не играет
// Но все же

// Программа не собирается
// и в ней нет main функции
// Необходимо добавить main функцию
// Необходимо добавить в .gitignore файлы сборки
// Необходимо написать тесты используя assert()

// хау ту юз ассерт ?
// #include <cassert>
// assert(1 == 2);

int get_int_lengh(int num) {
    int result = 0;
    if (num == 0) { // <- стиль
        return 1;
    }
    while (num != 0) {// <- стиль
        result += 1;
        num /= 10;
    }
    return result;
}


// 0d... -0d...
char *dec2str(int num) {// <- стиль
    int two_or_one;
    bool is_negative;
    if (num < 0) {// <- стиль
        two_or_one = 2;
        is_negative = true;
        num = -num;
    } else {// <- стиль
        two_or_one = 1;
        is_negative = false;
    }

    int total_length = 3;
    if (is_negative) {// <- стиль
        total_length += 1;
    }

    total_length += get_int_lengh(num);

    char *result = new char[total_length]; //необходимо для выделения динамической памяти "new"

    for (int index = total_length - 2; index > two_or_one; --index) {// <- стиль
        result[index] = (num % 10) + '0';
        num /= 10;
    }
    if (is_negative) {// <- стиль
        result[0] = '-';
        result[1] = '0';
        result[2] = 'd';

    } else {// <- стиль
        result[0] = '0';
        result[1] = 'd';

    }
    result[total_length - 1] = '\0';
    return result;
}