/* this is very very very importent */
#include <iostream>
using namespace std;

int main()
{
    vector<int> p1;
    vector<int> p2(10, 0);  // initialise 10 elements as 0 ... you can expand it later
    vector<string> p3 = {"hi", "Roshan", "take", "care"};
    vector<int> p4;

    p4 = {1,2,3,4,5,6,7,8};

    p1.push_back(1); // push at last
    p1.emplace_back(2); // faster than pushback-- dynamically resize, smart enough to understand pairs etc
    // pushback({1,2}), emplace_back(1,2)
    cout<<"last element"<<p1.back()<<" size="<<p1.size()<<endl;
    cout<<p4[3]<<" "<<p4.at(2)<<endl;
    p4.pop_back();
    cout<<p4[3]<<endl; // still holds the value but back will not point --- unstable

    p4.erase(p4.begin()+2);  // great function -- we can use to delete a random element in that array and it auto shifts
    p4.insert(p4.begin(), 0); // can just give index
    p4.insert(p4.begin(), p1.begin(), p1.end());
    p4.erase(p4.begin()+4, p4.end()-1);
    p4.insert(p4.begin()+4, 3, 5);

    /* iterator 

    normal syntax is vector<int>::iterator it = v.start() or v.end() or rend(), rbegin() 
    to avoid this long syntax, just use auto 
    remember its a pointer to the address
    remember end() is poiting to size() not size()-1*/

    for ( auto i = p4.begin() ; i < p4.end() ; i++ )
    {
        cout<<*(i)<<endl; 
    }
    cout<<" Reverse \n";
    for ( auto i = p4.rbegin() ; i < p4.rend() ; i++ ) // remember its still i++, < rend
    {
        cout<<*(i)<<endl; 
    }

    //for( int i = 0; i< p4.size(); i++)
    for(int x : p4)
    {
        cout<<x;
    }

    p4.swap(p1); // swaps both vectors
    p4.clear(); // erase everything
    cout<<p4.empty()


}