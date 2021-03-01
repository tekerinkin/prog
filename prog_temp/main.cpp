#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include "TypeList.h"

using namespace std;

typedef TypeList<int,char,int,double, float, int> Tl1;
typedef TypeList<char, double, int> TL10;

int main()
{
    cout << Tl1() <<' '<< TL10() <<endl;
    cout << Append<Tl1, TL10>::type() << endl;
    return 0;
}