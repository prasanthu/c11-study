#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>

using namespace std;

struct Greater_than {
    int val;
    Greater_than(int v) : val{v} {}
    bool operator()(const pair<string, int> &r) { return r.second > val;}
};

void f(map<string, int> &m, int v)
{
    auto p = m.begin();
    while ((p = find_if(p, m.end(), Greater_than{v})) != m.end()) {
        cout << p->first << " " << p->second<< endl;
        ++p;
    }
}

void f_lambda(map<string, int> &m, int v)
{
    auto p = m.begin();
    while ((p = find_if(p, m.end(), [&v](const pair<string, int> &r) { return r.second > v;})) != m.end()) {
        cout << p->first << " " << p->second<< endl;
        ++p;
    }
}


int main()
{
    map<string, int> empl;
    empl["Prasanth"] = 36;
    empl["Durga"] = 5;
    empl["Lakshmi"] = 1;
    empl["Swapna"] = 33;
    
    f(empl, 1);
    f_lambda(empl, 5);
    return 0;
}
