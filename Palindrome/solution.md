연산이 2가지가 있네요.

어떤 위치에 문자를 삽입하거나, 어떤 위치의 문자를 삭제하거나.

제가 의사코드를 작성하자면 아래와 같습니다.

```
f(int l, int r):
    if(l>=r) return 0
    if(s[l]==s[r]) return f(l+1, r-1)
    return 1 + min( f(l+1, r), f(l, r-1) )
```

문자열 양쪽 끝을 확인하면서 한쪽 끝 문자를 삭제한다고 생각해도 될 것 같습니다.

Category: ```DP```, ```Recursive``` 
