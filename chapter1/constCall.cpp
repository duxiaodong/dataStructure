/*
 *这个findMax函数只是找出最大值，string类型的可以直接比较，同时使用了 const引用来传递参数以及使用const引用作为返回值
 *Fri Nov 28 11:58:51 CST 2014
 */
#include<iostream>
#include<vector>
using namespace std;
const string &findMax (const vector<string> &arr)
{
    int maxIndex = 0;
    for(int i = 1; i < arr.size();i++){
    if(arr[maxIndex] < arr[i])
        maxIndex = i;
    }
    return arr[maxIndex];
}
int main()
{
    const vector<string> vec={"ab","bc","cd"};
    string x = findMax(vec);
    cout << x << endl;
    
    return 0;
}

