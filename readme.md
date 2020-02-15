## Д.З. Класс Односвязный Список

Компилируется с использованием фич С++11

    make
    rm -f list
    g++ -g --std=c++11 *.cpp -o list
    ./list 
    It's first
    1
    2
    5
    7
    It's second 
    1
    2
    5
    10
    It's copy: 
    1
    2
    5
    7
    operator &: 
    1
    2
    5
    operator |: 
    1
    2
    5
    7
    10
    It's merge:
    1
    2
    5
    7
    10
    It's fifth:
    1
    2
    5
    7
    10


    g++ -std=c++11 -g *.cpp
    
## 'Старым' компилятором не компилится

    g++ -std=c++98 *.cpp
    In file included from homework-05022020.cpp:2:0:
    List.h:21:11: error: expected ‘,’ or ‘...’ before ‘&&’ token
      List(List&& ob);
               ^
    List.h:21:16: error: invalid constructor; you probably meant ‘List (const List&)’
      List(List&& ob);
                    ^
    List.h: In constructor ‘List::Node::Node()’:
    List.h:11:11: error: ‘nullptr’ was not declared in this scope
        next = nullptr;
               ^
