#include<iostream>
#include <utility>
#include <thread>

void foo(){
    std::cout << "HEllo World" << std::endl; 
}


int main(int argc, const char** argv) {
    std::pair<int,int> p {1,1};

    std::pair<int, int> *p_ptr = &p;

    *p_ptr = std::pair<int, int> {2,2};

    std::thread t1(&foo);

    t1.detach();


    // t1.join();

    
    std::cout << p_ptr->first << std::endl;
    return 0;
}