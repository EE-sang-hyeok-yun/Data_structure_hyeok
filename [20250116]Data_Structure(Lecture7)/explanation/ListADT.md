# 리스트란

## 리스트의 개념

리스트(List)는 데이터를 순서대로 저장하고 관리하는 추상적 데이터 구조(ADT)이다. 리스트 ADT는 배열이나 연결 리스트를 기반으로 구현할 수 있다.

리스트(List)는 데이터를 순서대로 저장하고 관리하며, 주요 연산을 통해 데이터를 삽입, 삭제, 검색, 갱신할 수 있다. 

## 리스트 ADT

### 리스트 객체

- 리스트는 n개의 요소로 구성된 순서 있는 모임이다.
- 각 요소는 리스트 안에서 고유한 위치를 가지며, 이 위치는 0부터 시작한다.

### 리스트 연산

- `addLast(list, item)` ::= 맨 마지막에 `item` 을 추가한다.
- `addFirst(list, item)` ::= 맨 처음에 `item` 을 추가한다.
- `add(list, pos, item)` ::= `pos` 위치에 `item` 을 추가한다.
- `delete(list, pos)` ::= `pos` 위치의 요소를 제거한다.
- `clear(list)` ::= 리스트의 모든 요소를 제거한다.
- `replace(list, pos, item)` ::= `pos` 위치의 요소를 `item` 으로 대체한다.
- `isInList(list, item)` ::= `item` 이 `list` 안에 있는지 검사한다.
- `getEntry(list, pos)` ::= `pos` 위치의 요소를 반환한다.
- `getLength(list)` ::= `list` 의 길이를 구한다.
- `isEmpty(list)` ::= `list` 가 비어있는지 검사한다.
- `isFull(list)` ::= `list` 가 꽉 차있는지 검사한다.
- `display(list)` ::= `list` 의 모든 요소를 표시한다.