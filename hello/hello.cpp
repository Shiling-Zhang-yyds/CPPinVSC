#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> arr;
    int i = 0;
    for (; i < 10; i++) {
        arr.push_back(i * 2);
    }
    for (auto c : arr) {
        cout << c << " ";
    }
    return 0;
}