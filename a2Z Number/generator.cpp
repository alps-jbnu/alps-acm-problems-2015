/***
#include <cstdio>
#include <cstdlib>
#include <ctime>

void f(int k, int len){
    printf("%d ", k);
    for(int i=0; i<len; ++i){
        int p = rand()%k;
        if(i==0) while(p==0) p=rand()%k;
        if(p<10) p = '0'+p;
        else if(p<36) p = 'A'+(p-10)%10;
        else p = 'a'+(p-36)%10;
        printf("%c", p);
    }
    puts("");
}

int main(){
    int i, k, len;
    srand(time(NULL));
    for(i=0; i<50; ++i) f(rand()%60+2, rand()%30+1);
    return 0;
}

// 우선 만들어 보고
***/
/****/
// 데이터 추려내기
#include <cstdio>
#include <cstring>
#include <iostream>
int main(){
    char s[32];
    int i, T, x;
    scanf("%d", &T);
    while(T--){
        long long sum=0, p=1;
        bool can=true;
        std::cin >> x >> s;
        for(i=strlen(s)-1;i>=0;--i,p*=x){
            sum += p * (s[i]-(s[i]<'A'?'0':(s[i]<'a'?55:49)));
        }
        if(sum > 0 && sum <= 2147483648) printf("%d %lld\n", x, sum);
    }
    return 0;
}
/***/
