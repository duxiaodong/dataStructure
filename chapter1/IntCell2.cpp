#include<iostream>
using namespace std;
class IntCell
{
    public:
        explicit IntCell(int initvalue = 0);
        ~IntCell();
        const IntCell & operator=(const IntCell &ths);
        int read() const
        { return *value; }
        void write(int x)
        { *value = x; }

    private:
        int *value;

};
IntCell::IntCell(int initvalue)
{
    value = new int(initvalue);
}
const IntCell & IntCell::operator=(const IntCell &ths)
{
    if (this != &ths)
        *value = *ths.value;
    return *this;
}
IntCell::~IntCell()
{
    delete value;
}
int main()
{
    IntCell obj(9);
    cout << obj.read() << endl;
    IntCell obj2 ;
    obj2 = obj;
    cout << obj2.read() << endl;


    return 0;
}
