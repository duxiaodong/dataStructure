/*
 *Fri Oct 10 15:12:26 CST 2014
 fibonacci(斐波那契数列); 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144 
 */
#include<iostream>
using namespace std;
int main ()
{
    int f0 = 0, f1 = 1, t, n = 1;
    cout << "数列第一个:" << f0 << endl;
    cout << "数列第二个:" << f1 << endl;
    for(n = 3; n <= 20 ; n++){
        t = f1;
        f1 = f0 + f1;
        f0 = t;
        cout << "数列第" << n << "个:" << f1 << endl;
    }
    cout << endl;
    return 0;
}
