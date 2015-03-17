#include<iostream>
#include<iterator>
#include<vector>
using namespace std;
int main ()
{
    
    vector<int> vec(4);
    /*
     *std::cout << vec.size() << std::endl;
     */
    
    for(int j = 0; j < 4; j++)
    vec.push_back(j);
    /*
     *std::cout << vec[6] << std::endl;
     */
    
    vector<int>::iterator it;
    for(it = vec.begin(); it != vec.end(); it++)
        cout << *it++ << endl;
    return 0;
}
