#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str1 = "JAVA";
    string str2 = "PYTHON";
    string str3("TODO");

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;

    string str4 = str1 + str2;
    cout << "str4: " << str4 << endl;

    cout << "str3长度: " << str3.size() << endl;
    cout << "str4长度: " << str4.length() << endl;

    cout << "从第一个位置开始找 ON 字符串：" << str4.find("ON", 0) << endl; // 从第一个位置开始找 ON 字符串

    str3 = str1.substr(1, 3); // 从第二个字开始截取3个字符；
    cout << "从第二个字开始截取3个字符: " << str3 << endl;

    str4.replace(1, 2, "666888", 3);
    cout << "从第一个位置开始的两个字符 替换成\"666888\" 的前3个字符: " << str4 << endl;

    str2.insert(4, "OOOOOOOOOOOOOOOOO", 0, 5);
    cout << "在第四个位置插入指定字符串从0开始的5个字符" << str2 << endl;

    string strArr[5] = {str1, str2, str3, str4, "所有字符串"};


    return 0;
}
