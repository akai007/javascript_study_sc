#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> vec1, vec2;
    vec1.push_back(10);
    vec1.push_back(20);

    vec2.push_back(100);
    vec2.push_back(200);

    vector<vector<int>> vec2D;
    vec2D.push_back(vec1);
    vec2D.push_back(vec2);

    cout << vec2D.at(1).at(1) << endl
        << vec2D.at(0).at(0) << endl;
    
    /* code */
    return 0;
}
