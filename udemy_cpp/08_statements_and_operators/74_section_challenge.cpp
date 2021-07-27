#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int totalCent = 0;
    cout << "Enter an amount in cents: ";
    cin >> totalCent;

    const int DOLLAR_VAL = 100;
    const int QUATER_VAL = 25;
    const int DIME_VAL = 10;
    const int NICKEL_VAL = 5;
    const int PENNIE_VAL = 1;

    int nums = 0;
    int remains = totalCent;

    nums = remains / DOLLAR_VAL;
    remains = remains % DOLLAR_VAL;
    cout << "dolor:\t" << nums << endl;

    nums = remains / QUATER_VAL;
    remains = remains % QUATER_VAL;
    cout << "quater:\t" << nums << endl;

    nums = remains / DIME_VAL;
    remains = remains % DIME_VAL;
    cout << "dime:\t" << nums << endl;

    nums = remains / NICKEL_VAL;
    remains = remains % NICKEL_VAL;
    cout << "nickel:\t" << nums << endl;

    nums = remains / PENNIE_VAL;
    remains = remains % PENNIE_VAL;
    cout << "pennie:\t" << nums << endl;

    return 0;
}
