## Idea. Closet array

> A: [1 4 7 9 12]

> B: [3 8 11]

A로부터 B와 가장 유사하게(가깝게) 표현한 배열의 상태를 출력하라.

위 예시에서 답은 아래와 같다.

[4 7 12]

- B의 각 원소에 대해 A에서 **이진탐색**으로 해결 *O(BlogA)*

- B의 각 원소에 대해 A에서 **스위핑**으로 탐색하여 해결할 수 있지만 *O(A+B)* A가 매우 큰 크기의 배열이라면 이진탐색으로만 해결할 수 있게 분별력을 줄 수 있음.
