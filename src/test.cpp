#include<iostream>
#include <utility>
#include <thread>
#include <map>

void foo(){
    std::cout << "HEllo World" << std::endl; 
}


int main(int argc, const char** argv) {
    std::map<int, int> m;
    m[1] = 1;
    m[2] = 2;

    std::map<int,int>* m_ptr  = &m;

    // std::pair<int,int> p {1,1};

    // std::pair<int, int> *p_ptr = &p;

    // *p_ptr = std::pair<int, int> {2,2};

    // std::thread t1(&foo);

    // t1.detach();


    // t1.join();

    
    std::cout << (*m_ptr)[2] << std::endl;
    return 0;
}