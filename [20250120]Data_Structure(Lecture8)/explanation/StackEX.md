# 스택의 활용

## 괄호 검색 알고리즘

### 코드

```c
int parentheses(void)
{
    ArrayStack stack;
    init(&stack, 50);

    char* str = (char*)malloc((51) * sizeof(char));
    if (str == NULL)
        return 1;
    scanf("%s", str);
    size_t len = strlen(str);

    for (int i = 0; i < len; i++)
    {
        switch (str[i])
        {
        case '(':
        case '{':
        case '[':
            push(&stack, str[i]);
            break;
        case ')':
        case '}':
        case ']':
            if (isEmpty(&stack))
            {
                free(str);
                freeStack(&stack);
                return 1;
            }
            else
            {
                element temp = pop(&stack);
                if (((str[i] == ')') && (temp != '(')) || ((str[i] == '}') && (temp != '{')) || ((str[i] == ']') && (temp != '[')))
                {
                    free(str);
                    freeStack(&stack);
                    return 1;
                }
                break;
            }
        }

    }
    if (isEmpty(&stack))
    {
        free(str);
        freeStack(&stack);
        return 0;
    }
    else
    {
        free(str);
        freeStack(&stack);
        return 1;
    }
}

int main(void)
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        if(!parentheses())
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
```

```
6
(())())
NO
(((()())()
NO
(()())((()))
YES
((()()(()))(((())))()
NO
()()()()(()()())()
YES
(()((())()(
NO
```

### 예시 입력

```
3
()
({[()]})
({[()]}
```

### 실행 흐름

1. 첫 번째 문자열 `()`:
    - `'('` 푸시 -> `')'` 팝 (짝이 맞음).
    - 스택 비어 있음 -> YES
2. 두 번째 문자열 `({[()]})`:
    - `'('`, `'{'`, `'['`, `'('` 순서로 푸시.
    - `')'` -> `'('` 팝 (짝이 맞음).
    - `']'` -> `'['` 팝 (짝이 맞음).
    - `'}'` -> `'{'` 팝 (짝이 맞음).
    - `')'` -> `'('` 팝 (짝이 맞음).
    - 스택 비어 있음 -> YES
3. 세 번째 문자열 `({[()]}`:
    - `'('`, `'{'`, `'['`, `'('` 순서로 푸시.
    - `')'` -> `'('` 팝 (짝이 맞음).
    - `']'` -> `'['` 팝 (짝이 맞음).
    - `'}'` -> `'{'` 팝 (짝이 맞음).
    - 문자열 끝났지만 스택에 `'('` 남아 있음.
    - NO

### 출력

```
YES
YES
NO
```

### 백준 문제

[9012 괄호 (실버 4)](https://www.acmicpc.net/problem/9012)

- Stack을 이용하여 해결 가능.
- 그러나 더 효율적인 방법이 있다.