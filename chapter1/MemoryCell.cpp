/*
 *Fri Nov 28 11:50:37 CST 2014
 *模板类使用，改写了Intcell类实质具有一般性，即泛型
 */
#include<iostream>
#include<vector>
using namespace std;
template <typename Object>
class MemoryCell
{
    public:
        explicit MemoryCell(const Object &initValue = Object()):value(initValue){}
        const Object & read() const
        {return  value;}
        void write(const Object & x)
        {value = x;}
    private:
            Object value;
};
int main()
{
    MemoryCell<int> obj1;
    MemoryCell<string> obj2("hello");
    obj1.write(3);
    obj2.write(obj2.read() + " world");
    cout << "objint:" << obj1.read() <<" " <<  "objstring:" << obj2.read() << endl;

    return 0;
}
