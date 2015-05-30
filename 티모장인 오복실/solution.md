## Idea. Closet array

> A: [1 4 7 9 12]

> B: [3 8 11]

A로부터 B와 가장 유사하게(가깝게) 표현한 배열의 상태를 출력하라.

위 예시에서 답은 아래와 같다.

[4 7 12]

- B의 각 원소에 대해 A에서 **이진탐색**으로 해결 *O(BlogA)*

```
#include <stdio.h>
#include <math.h> //abs

int s[1000001];

int main(){
    int i, n, k;
    scanf("%d %d", &n, &k);
    for(i=0; i<n; ++i) scanf("%d", &s[i]);
    int l=0, r=n-1, p;
    for(i=0; i<k; ++i){
        scanf("%d", &p);
        // 이진탐색으로 정답을 추려냄
        l=0, r=n-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(s[mid] > p) r=mid-1;
            else l=mid+1;
        }
        // 마지막으로 추려진 두 수 중에서 차이가 더 작은쪽을 선택
        if(abs(p-s[l]) >= abs(p-s[r])) printf("%c%d ", p > s[r] ? '-' : '+', (int)abs(p-s[r]));
        else printf("%c%d ", p > s[l] ? '-' : '+', (int)abs(p-s[l]));
    }
    return 0;
}
```

- B의 각 원소에 대해 A에서 **스위핑**으로 탐색하여 해결할 수 있지만 *O(A+B)* A가 매우 큰 크기의 배열이라면 이진탐색으로만 해결할 수 있게 분별력을 줄 수 있음.

```
/***
 * 추가예정
 *
 ***/
```

- B의 각 원소에 대해 A로부터 하나씩 검사하며 찾을 수 있습니다. 가장 떠올리기 쉽고, 구현하기도 쉽지만 이 경우에는 *O(AB)*의 시간복잡도를 가집니다.

```
#include <iostream>
#include <cmath>  // abs
using namespace std;

int a[1000001];

int main(){
    int i, n, k, p;
    cin >> n >> k;
    for(i=0; i<n; ++i) cin >> a[i];
    for(i=0; i<k; ++i){
        cin >> p;
        // 비교를 위해 d를 적당히 큰 값으로 잡는다.
        int d=987654321, answer=0;
        // 정답에 가까워질수록 차이는 줄어든다.
        // 차이가 다시 커질때까지 반복한다면 정답에서 반복을 멈춘다.
        for(int j=0;abs(a[j]-p)<=d; ++j){
            d = abs(a[j]-p);
            answer = a[j];
        }
        cout<<(p<answer?'-':'+')<<abs(p-answer)<<' ';
    }
    return 0;
}
```
