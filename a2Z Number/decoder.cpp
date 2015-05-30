/***
 * filename: decoder.cpp
 * extension: cpp
 * description: 10진수로 표현된 N이 주어지면, 임의의 X진법으로 출력한다.
 ***/

#include <iostream>
#include <cstdlib>  //srand
#include <ctime>    //time
using namespace std;

int main(){
    int n, x;
    srand(time(NULL));
    while(cin >> n){
        x = rand()%61+2; //2진법~62진법
        cout<< x <<' ';
        int i, len=0;
        char buf[62]={};
        while(n>0){
            int k=n%x, ch=0;
            if(k<10) ch=k+'0';
            else if(k<36) ch=k-10+'A';
            else ch=k-36+'a';
            buf[len++] = ch;
            n/=x;
        }
        for(i=len-1; i>=0; --i) cout<< buf[i];
        cout<<'\n';
    }
    return 0;
}
