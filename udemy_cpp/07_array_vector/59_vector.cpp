#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector <double> test_scores {99, 88, 100};

    cout << "\n Test scores using array syntax:" << endl;
    cout << test_scores[0] << endl;
    cout << test_scores[1] << endl;
    cout << test_scores[2] << endl;

    cout << "\n Test scores using vector syntax:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;
    cout << "\n There are now" << test_scores.size() << " scores in the vector" << endl;

    cout << "\n Enter 3 test scores(separate by space): ";
    cin >> test_scores.at(0)
        >> test_scores.at(1)
        >> test_scores.at(2);
    
    cout << "\n The new scores:" << endl;
    cout << test_scores.at(0) << endl;
    cout << test_scores.at(1) << endl;
    cout << test_scores.at(2) << endl;

    cin >> test_scores.at(3); // will throw exception

    return 0;
}
