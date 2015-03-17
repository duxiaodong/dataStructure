#include<iostream>
template <typename Object>
class Vector 
{
    public:
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

        /*
         *Vector支持数组方式的索引
         */
        Object operator[]( int index)
        {
            return objects[index];
        }
        const Object operator[](int index) const
        {
            return objects[index];
        }
        /*
         *扩容以及添加新的元素
         */
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
        void reserve(int newCapacity)
        {
            if(newCapacity < theSize)
                return ;
            Object *oldArray = objects;
            objects = new Object[newCapacity];
            for(int i = 0; i < size(); i++){
                objects[i] = oldArray[i];
            }
            theCapacity = newCapacity;
        }
        /*
         *iterator 是Object对象的别名;；
         */
        typedef Object * iterator;
        typedef const Object * const_iterator;
        iterator begin()
        {return &objects[0];}
        iterator end()
        {return &objects[size()];}


        enum {SPARE_CAPACITY  = 16};
    private:
        int theSize;
        int theCapacity;
        Object *objects;
};
int main()
{
    Vector<int> vec(4);
    std::cout << vec.size() << std::endl;
    
    for(int j = 0; j < 4; j++)
    vec.push_back(j);
    /*
     *std::cout << vec[6] << std::endl;
     */
    
    Vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
        std::cout << *it++ << std::endl;

    return 0;
}
