#import <iostream>
using namespace std;

template<typename T>
void g(T x)
{
        cout<<x<<" ";
}

void f() { } // do nothing

template<typename T, typename... Tail>
void f(T head, Tail... tail)
{
        g(head); // do something to head
        f(tail...); // try again with tail
}


int main()
{
        cout<<"first :";
        f(1, 2.2, "hello");
        cout<<endl;

        cout<<"second :";
        f(0.2,'c', "hello", 100);
        cout<<endl;
        return 0;
}
