#include<thread>
#include<iostream>
#include<string>

// std::thread thread_object(callable)

void foo(std::string str){
    std::cout << str << std::endl;
    
}


int main(int argc, const char** argv) {
    std::thread thread_object(foo, "Hello");
    return 0;
}