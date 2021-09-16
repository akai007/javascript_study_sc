#include <iostream>

using namespace std;

int main()
{
    char str1[4] = {'J', 'A', 'V', 'A'};
    char str2[6] = {'P', 'Y', 'T', 'H', 'O', 'N'};
    char str3[20]; // define string array
    char strNum1[4] = {'1','2','3','4',};
    char strNum2[4] = {'3','.','1','4',};
    cout << "please enter str:" << endl;
    gets(str3); // 让字符串获取字符流

    cout << "str1:" << str1 << endl;
    cout << "str2:" << str2 << endl;
    cout << "str3:";
    puts(str3); // 让字符串输出
    cout << endl;

    strncpy(str1, str2, 2);
    cout << "复制2个字符串: " << str1;
    cout << endl;
    strcpy(str1, str2);
    cout << "复制字符串: " << str1;
    cout << endl;
    strcat(str1, str2);
    cout << "合并字符串: " << str1;
    cout << endl;

    cout << "字符串长度: " << strlen(str1) << endl;

    int numInt = atoi(strNum1);
    float numFloat = atof(strNum2);
    cout << "num int: " << numInt << endl;
    cout << "num float: " << numFloat << endl;


    cout << endl;
    return 0;
}
