#include<iostream>
using namespace std;
class IntCell
{
    public:
        explicit IntCell(int initValue = 0)
            :value(initValue){}
        int read() const
        { return value; }
        void write(int x)
        { value = x; }

    private:
        int value;

};
int main()
{
    IntCell obj;
    IntCell obj2(10);
    obj  = obj2;
    cout << "obj operator:" << obj.read() << endl;
    cout << obj2.read() << endl;

    return 0;
}
