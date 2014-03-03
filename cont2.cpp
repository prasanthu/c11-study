#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

template<typename T> 
using Iterator = typename T::iterator;


template<typename C, typename V>
vector<Iterator<C>> find_all(C&c, V v)
{
    vector<Iterator<C>> res;
    for (auto p = c.begin(); p!=c.end(); ++p) {
        if (*p == v) {
            res.push_back(p);
        }
    }
    return res;
}

void test()
{
    string m{"Mary had a little lamb"};
    for (auto p : find_all(m, 'a')) {
        if (*p != 'a') {
            cerr<<"string bug\n";
        }
    }
}

int test_iterators()
{
    string from, to;
    cout << "Enter Input file: ";
    cin >> from;
    cout << "Enter Output file: ";
    cin >> to;

    ifstream is{from};
    istream_iterator<string> ii{is};
    istream_iterator<string> eos{};

    ofstream os{to};
    ostream_iterator<string> oo{os, "\n"};
    
    vector<string> b {ii, eos};
    for (auto p = b.begin(); p != b.end(); ++p) {
        cout << *p << endl; 
    }
    sort(b.begin(), b.end());
    
    unique_copy(b.begin(), b.end(), oo);

    return !is.eof()|| !os;
    
}

int test2_iterators()
{
    string from, to;
    cout << "Enter Input file: ";
    cin >> from;
    cout << "Enter Output file: ";
    cin >> to;

    ifstream is{from};
    istream_iterator<string> ii{is};
    istream_iterator<string> eos{};

    ofstream os{to};
    ostream_iterator<string> oo{os, "\n"};
    
    set<string> b {ii, eos};
    for (auto p = b.begin(); p != b.end(); ++p) {
        cout << *p << endl; 
    }
    
    copy(b.begin(), b.end(), oo);

    return !is.eof()|| !os;
    
}


int main()
{
    return test2_iterators();
}
