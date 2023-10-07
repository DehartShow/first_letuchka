#include <iostream>
using namespace std;

int get_int_lengh(int num){
    int result = 0;
    if(num == 0){
        return 1;
    }
    while (num != 0){
        result += 1;
        num /= 10;
    }
    return result;
}

// 0d... -0d...
char* dec2str(int num){
    int two_or_one;
    bool is_negative;
    if (num < 0){
        two_or_one = 2;
        is_negative = true;
        num = -num;
    } else{
        two_or_one = 1;
        is_negative = false;
    }

    int total_length = 3;
    if (is_negative){
        total_length += 1;
    }

    total_length += get_int_lengh(num);

    char* result = new char[total_length]; //необходимо для выделения динамической памяти "new"

    for (int index = total_length - 2; index > two_or_one; --index)
    {
        result[index] = (num % 10) + '0';
        num /= 10;
    }
    if (is_negative){
        result[0] = '-';
        result[1] = '0';
        result[2] = 'd';

    } else{
        result[0] = '0';
        result[1] = 'd';

    }
    result[total_length - 1] = '\0';
    return result;
}

int main(){
    int n;
    cin >>n;
    cout << dec2str(n)<< endl;
}
