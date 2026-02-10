/* few things to revise on arrays and vectors

you cannot declaire the array as below
int *arr --> because declare means to allocate the memory, this will be just a integer pointer
int arr[10] --> this is valid, but not int arr[] again above reason
int arr[] = {1,2,3,4} --> this is valid too
if you really want to declare it as pointer
int *arr = malloc(n * sizeof(int))

However, you can pass it in following ways, in which above things can change...
declare it as any above valid, while passing to the function
foo(arr) ---> this is valid, no *arr, cos array name itself is a pointer to first element

receiving end
int foo(int arr[]) ---> most used valid.
int foo(int *a) --> this is also valid.
-------in both cases, you cant access as size of it, cos its just a pointer to array, sizeof(arr), sizeof(arr[0])
 both are invalid

 Double pointer:
 I have used it before, check in my old c programming dsa solutions, why did i use them?
 i used it for linked list, the problem i was facing was, head.. if someone ask me to delete the head, or change of head
 then in normal case i have to always send back the new head pointer to the callee, i could avoid it by taking double pointer..

 this is a plus if you master it, trap if you are unsure. check it in arrays as well

*/

/*

in stack you better provide the size as well, cos anyway we need a top

*/

#include <iostream>
using namespace std;

const int MAX=10;

int check_empty(int *s)
{
    return (*s == 0);
}

int check_full(int *s)
{
    return (*s == MAX);
}

void push_element(int *a, int *s, int x)
{
    if(check_full(s))
    {
        cout<<"FULL"<<endl;
        return;
    }   

    a[*s] = x;
    (*s)++;
    
}

void pop_element(int *a, int *s)
{
    if(check_empty(s))
    {
        cout<<"EMPTY"<<endl; 
        return;
    }

    (*s)--;
}

void traverse(int *a, int *s)
{
    if(check_empty(s))
    {
        cout<<"EMPTY2"<<endl;
        return;
    }
    
    for(int i=0;i<(*s);i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    int a[MAX];
    int size=0;

    push_element(a, &size, 10);
    push_element(a, &size, 20);
    push_element(a, &size, 30);

    traverse(a, &size);

    pop_element(a, &size);

    traverse(a, &size);
    pop_element(a, &size);
    pop_element(a, &size);
    pop_element(a, &size);
    traverse(a, &size);
}