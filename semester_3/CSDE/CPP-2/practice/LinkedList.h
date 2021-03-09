#include<iostream>
using namespace std;

#ifndef __LINKEDLIST__
#define __LINKEDLIST__

template <class T>
// Linked List Node
class Node{
public:
    T data;
    Node <T> *link;
    Node(T element){
        data = element;
        link = 0; }
};
// Linked List Class
template <class T>
class LinkedList
{
protected:
    Node <T> *first;
    int current_size;
public:
    LinkedList(){
        first = 0;
        current_size = 0; };
    int GetSize() { return current_size; }; // 노드 개수를 리턴
    void Insert(T element); // 맨 앞에 원소를 삽입
    virtual bool Delete(T &element); // 맨 뒤의 원소를 삭제
    void Print();	// 리스트를 출력
};
template <class T>
void LinkedList <T>::Insert(T element){ // 새 노드를 맨 앞에 붙임
    Node <T> *newnode = new Node <T>(element);
    newnode->link = first;
    first = newnode;
    current_size++;
}
template <class T>
bool LinkedList <T>::Delete(T &element){
    // 마지막 노드의 값을 리턴하면서, 메모리에서 할당 해제
    if(first == 0) return false;
    Node <T> *current = first, *previous = 0;
    while(1){    // 마지막 노드까지 찾아가는 반복문
        if(current->link == 0)    // find end node
        {
            if(previous) previous->link = current->link;
            else first = first->link;
            break;
        }
        previous = current;
        current = current->link;
    }
    element = current->data;
    delete current;
    current_size--;
    return true;
}
template <class T>
void LinkedList <T>::Print() {
	if(first == NULL) return;
	Node <T> *curNode = first;
	int cnt = 0;

	while(true) {
		cnt += 1;
		cout << "[" << cnt;
		cout << "|" << curNode -> data << "]";
		if(curNode -> link == NULL)
			break;
		cout << "->";
		curNode = curNode -> link;
	}
	cout << endl;
}
#endif