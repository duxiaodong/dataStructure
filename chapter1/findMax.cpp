/*
 *模板函数，findMax使之具有泛型，通用性，11行的比较运算符重载是在string 以及int中定义的，如果使用自己的类，需要重写。
 *Fri Nov 28 11:52:07 CST 2014
 */
#include<iostream>
#include<vector>
using namespace std;
class dateManage
{
    public:
       explicit dateManage(int initvalue = 0);
       dateManage(const dateManage &ths);
        ~dateManage();

        const dateManage & operator=(const dateManage &ths);
        
        bool operator<(const dateManage &ths);//做比较使用
        void pri(ostream &out )const
        {out << *date ;}
        int read() const
        {return *date;}
        void write(int x)
        {  *date = x;}
    private:
        int *date;

};
ostream &operator<< (ostream &out, const dateManage &ths)
{
     ths.pri(out);
     return out;
}
dateManage::dateManage(int initvalue)
{
    date = new int(initvalue);
}
dateManage::dateManage(const dateManage &ths)
{
    date = new int (*ths.date);
}
const dateManage & dateManage::operator=(const dateManage &ths)
{
    if(this != &ths)
        *date = *ths.date;
    return *this;
}

bool dateManage::operator<(const dateManage &ths)
{
    return date < ths.date; 
}
dateManage::~dateManage()
{
    delete date;
}
template <typename Compareable>
const Compareable &findMax (vector<Compareable> &arr)
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
    vector<string> vec={"ab","bc","cd"};
    vector<int> itvalue(10,4);
    vector<dateManage> value(39);
    string x = findMax(vec);
    int y = findMax(itvalue);
    dateManage z = findMax(value);
    
    cout << "string:" << x << " " << "int:" << y << endl;
    cout << "dateManage:" << z << endl;
    return 0;
}


