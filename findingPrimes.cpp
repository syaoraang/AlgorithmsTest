#include <stdio.h>
#include <list>

#define TOPE 1000

int main(int argc, char const *argv[])
{
    std::list<int> primes;
    int i = 2;
    while(i<=TOPE){
        bool done = false;
        
        for(auto &j: primes){        
            if (i%j == 0){
                done = true;
                break;
            }
        }
        if (!done)
            primes.push_back(i);
        ++i;
    };
    for(auto &v: primes)
        printf("%d, ", v);
    printf("\n");
    return 0;
}