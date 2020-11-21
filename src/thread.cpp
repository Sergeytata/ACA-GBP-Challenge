#include<thread>
#include<iostream>
#include<string>
#include <omp.h>
#include <unistd.h>
#include <algorithm>

#define ARRAY_SIZE 100000000
#define ARRAY_VALUE 1231

#define THREAD_NUM 4

// std::thread thread_object(callable)

void foo(std::string str){
    std::cout << str << std::endl;
}

void checkThreadsRunning(){
    omp_set_dynamic(0);
    omp_set_num_threads(THREAD_NUM); // set number of threads in "parallel" blocks
    #pragma omp parallel
    {
        usleep(5000 * omp_get_thread_num()); // do this to avoid race condition while printing
        std::cout << "Number of available threads: " << omp_get_num_threads() << std::endl;
        // each thread can also get its own number
        std::cout << "Current thread number: " << omp_get_thread_num() << std::endl;
        std::cout << "Hello, World!" << std::endl;
    }
}


void arrayOfIntegers(){
    int *arr = new int[ARRAY_SIZE];
    std::fill_n(arr, ARRAY_SIZE, ARRAY_VALUE);

    auto start = std::chrono::high_resolution_clock::now();

    #pragma omp parallel for
        for(int i = 0; i < ARRAY_SIZE; i++)
        {
            arr[i] = arr[i] / arr[i] + arr[i] / 5 - 14;
        }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << diff.count() << std::endl;
}

int main()
{
    arrayOfIntegers();
    return 0;
}