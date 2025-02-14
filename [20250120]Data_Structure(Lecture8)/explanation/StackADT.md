# 스택 ADT

## 스택 개념

스택(Stack)은 데이터를 후입선출(LIFO, Last In First Out) 방식으로 저장하고 관리하는 추상적 데이터 구조(ADT)이다. 

스택은 삽입과 삭제가 한쪽 끝(Top)에서만 이루어진다.

## 스택 ADT

### 스택 객체

- 스택은 n개의 요소로 구성된 선형 리스트이다.
- 삽입과 삭제는 스택의 꼭대기(Top)에서만 수행된다.
- 가장 마지막에 삽입된 요소가 가장 먼저 삭제된다.

### 스택 연산

- `create()` ::= 스택을 생성한다. 초기화된 비어 있는 스택을 반환한다.
- `isEmpty(stack)` ::= 스택이 비어 있는지 확인한다. 스택이 비어 있으면 `true`를, 그렇지 않으면 `false`를 반환한다.
- `isFull(stack)` ::= 스택이 가득 찼는지 확인한다. 스택이 가득 찼으면 `true`를, 그렇지 않으면 `false`를 반환한다.
- `push(stack, item)` ::= 스택의 꼭대기에 `item`을 삽입한다. 만약 스택이 가득 차 있으면 삽입에 실패한다.
- `pop(stack)` ::= 스택의 꼭대기에서 요소를 제거하고 반환한다. 만약 스택이 비어 있으면 제거에 실패한다.
- `peek(stack)` ::= 스택의 꼭대기 요소를 제거하지 않고 반환한다. 스택이 비어 있으면 반환에 실패한다.