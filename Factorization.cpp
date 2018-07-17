#include <stdio.h>
#include <stdlib.h>
#include <forward_list>

const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int minusOrEq(int value){
    int size = sizeof(primes)/sizeof(int), index=-1;
    for(int i=0; i<size; ++i){
        if(primes[i]<=value)
            index++;
    }
    return index;
}


int main(int argc, char const *argv[])
{
    if(argc<2)
        exit(1);
    int value = atoi(argv[1]), i, tmp;
    bool done = false;
    std::forward_list<int> list;
    i = minusOrEq(value);
    tmp = value;
    while(!done){
        if(i == -1){
            done = true;
            break;
        }
        if(tmp % primes[i] ==0){
            list.push_front(primes[i]);
            tmp /= primes[i];
            i = minusOrEq(tmp);
        }
        else
            --i;
    }
    for(auto &v: list){
        printf("Factor: %d\n", v);
    }
    return 0;
}