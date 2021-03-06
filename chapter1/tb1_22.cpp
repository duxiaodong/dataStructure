/*
 *Fri Jan  9 19:48:31 CST 2015
 *函数对象传递
 */
#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
template <typename Object,typename Comparator>
const Object & findMax(const vector<Object> &arr, Comparator cmp)
{
    int maxIndex = 0;
    for(int i = 1; i != arr.size(); i++){
        if(cmp.isLessThan(arr[maxIndex] , arr[i])){
            maxIndex = i;
        }
    }
    return arr[maxIndex];
}
class CaseCompare
{
    public:
    bool isLessThan(const string &str1, const string &str2) const
    {
        return strcasecmp(str1.c_str() ,str2.c_str()) < 0;
    }
};
int main()
{
    vector<string> arr(3);
    arr[0] = "abbb"; arr[1] = "dccd";arr[2] = "cdd";
    cout << findMax (arr, CaseCompare()) << endl;
    return 0;
}
