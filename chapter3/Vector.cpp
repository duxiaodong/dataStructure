#include<iostream>
template <typename Object>
class Vector 
{
    public:
        /*
         *三大构造函数;
         */
        explicit Vector(int initSize = 0)
            :theSize(initSize),theCapacity(initSize + SPARE_CAPACITY)
        { objects = new Object[theCapacity];}

        Vector(const Vector &ths):objects(NULL) 
        {operator=(ths);}
            
        const Vector & operator=(const Vector &ths)
        {
            if(this != ths){
                delete [] objects;
                theSize = ths.size();
                theCapacity = ths.theCapacity;
                objects = new Object[theCapacity];
                for(int i = 0; i < size(); i++){
                    objects[i] = ths.objects[i];
                }
            }
            return *this;
        }

        ~Vector()
        {delete [] objects;}

        int size() const 
        {return theSize;}

        int capacity() const
        {return theCapacity;}
        bool empty() const
        {return size() == 0 ;}

        //Vector支持数组方式的索引
        Object operator[]( int index)
        {
            return objects[index];
        }
        const Object operator[](int index) const
        {
            return objects[index];
        }
        //扩容策略,newSize>theCapacity时,扩容
        void resize(int newSize)
        {
            if(newSize > theCapacity)
                reserve(newSize *2 + 1);
            theSize = newSize;
        }

        void reserve(int newCapacity)
        {
            if(newCapacity < theSize) //newCapacity<theSize,不扩容;
                return ;
            Object *oldArray = objects;
            objects = new Object[newCapacity];
            for(int i = 0; i < size(); i++){
                objects[i] = oldArray[i];
            }
            theCapacity = newCapacity;
        }

        void push_back(const Object &x)
        {
            if (theSize == theCapacity)
                reserve(theCapacity * 2 +1);
            objects[theSize++] = x;

        }
        void pop_back()
        {
            theSize--;
        }
        //iterator 是Object对象的指针变量;
        typedef Object * iterator;
        typedef const Object * const_iterator;
        iterator begin()
        {return &objects[0];}
        const_iterator begin() const
        {return &objects[0];}

        iterator end()
        {return &objects[size()];}
        const_iterator end() const
        {return &objects[size()];}


        enum {SPARE_CAPACITY  = 16};
    private:
        int theSize;
        int theCapacity;
        Object *objects;
};
int main()
{
    Vector<int> vec;

    for(int j = 0; j != 5; j++)
    vec.push_back(j);
    vec.pop_back();    

    if(!vec.empty())
        std::cout << "not empty:" << std::endl;
    vec.resize(10);
    std::cout << "vecresize:" << vec.size()
    << "vecCapacity:" << vec.capacity() << std::endl;

    vec.resize(17);
    std::cout << "vecresize:" << vec.size() 
    << "vecCapacity:" << vec.capacity() << std::endl;

    vec.reserve(14);
    std::cout << "vecresize:" << vec.size() 
    << "vecCapacity:" << vec.capacity() << std::endl;

    Vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
        std::cout << *it << std::endl;

    return 0;
}
