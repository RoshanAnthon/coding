#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> a;
    int num;

    a.push_back(11);
    a.push_back(12);
    a.push_back(13);

    cout << "enter more values if you want to add to the vector, integers only\n to end enter a character\n";
    while (cin >> num) {
        a.push_back(num);
    }

    cout << "printing the vector elements\n";
    for (int i=0; i<a.size(); i++) {
        cout << a[i] <<" ";
    }
    cout << endl;
    return 0;
}