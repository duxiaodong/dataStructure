/*
 *dateManage这个类是学习了当默认值不可使用的时候，如何重新复制构造函数，operator=以及析构函数
 *等价于当数据成员有指针类型的时候
 *Fri Nov 28 11:54:42 CST 2014
 */
#ifndef dateManage_H

#define dateManage_H

#include<iostream>
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
int main ()
{
    dateManage dateObj = dateManage(10);
    cout << dateObj.read() << endl;
    dateManage B(dateObj);
    cout << "赋值构造函数"<< B.read() << endl;
    B= dateManage(dateObj);//修改默认构造函数
    cout << B.read() << endl;
    
    dateManage dateObj2;//重载= 
    dateObj2 = dateObj;
    cout << dateObj2.read() << endl;

    return 0;
}
#endif
