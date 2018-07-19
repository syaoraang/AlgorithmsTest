#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <queue>


int main(int argc, char const *argv[])
{
    const char *s = "abbc";
    const char *b = "cbabadcbbabbcdabaabccbabc";

    std::map<char, int> dic;
    std::queue<char> indexes;

    const int sl = strlen(s), bl = strlen(b);
    for(int i=0; i<sl; ++i){
        if(!dic.count(s[i]))
            dic[s[i]] = 1;
        else
            dic[s[i]]++;
    }

    for(int j = 0; j<bl-3; ++j){
        char i = b[j];
        std::map<char, int> tmp(dic);
        int c = 0;
        bool keep = true;
        while(keep && c<sl){
            i = b[j+c];
            if(tmp.count(i) && tmp[i]>0){
                tmp[i]--;
                keep = true;
                c++;
            }
            else
                keep = false;
        }
        if(c == sl)
            indexes.push(j);
    }
    
    printf("Permutations found at: ");
    while(indexes.size()){
        const int v = indexes.front();
        printf("%d, ", v);
        indexes.pop();
    }
    printf("\n");

    /* code */
    return 0;
}