//Important Note: This file has been used from the sample codes that has been provided to us in CPSC 2150 class
//by the instructor Dr. Bita Shadgar

//A function has been added by the name of removeRoom();

//SLL.h file
//Description: This class implements a linked list 
//Creation Date: May 13, 2021


#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <stdexcept>
// class prototype
template <typename T>
class SLL;

template <typename T>
class Iterator;

// Class Node
template <typename T>
class Node {
public:
	Node() {
	    next = nullptr;
	}
	Node(T data, Node<T> * link = nullptr){
	    info = data; 
        next = link;
	}
	/* Class SLL and Iterator can access all private data members and functions of Node*/
	friend class SLL<T>;
	friend class Iterator<T>; 
private:	
	T info;
	Node <T> *next;
};

// class Iterator
template<typename T>
class Iterator {
public:
  Iterator(Node<T>* p){
     current = p;
  }
  Iterator next() {
     current = current->next;
     return *this;
  }
  T content() {
    return current->info;
  }
  bool isEqual(const Iterator<T>& itr) const {
    return current == itr.current;
  }

  bool operator==(const Iterator<T>& itr) const {
  	  return isEqual(itr);
  }

  bool operator!=(const Iterator<T>& itr) const {
  	  return !isEqual(itr);
  }

  Iterator operator++() {
    return next();
  }

  T& operator*() {
    return current->info;
  }
  /* Class SLL can access all private and protected items of Iterator */
  friend class SLL<T>;
private:
  Node<T>* current;
};

// classs SLL
template<typename T>
class SLL {
public: 
	SLL(){
		head = tail = nullptr;
		size = 0;
	}
	~SLL() {
       for (Node<T> *tmp; head != nullptr;  ) {
    		tmp = head;
    		head = head->next;
    		delete tmp; 
    		tmp = nullptr; 
    	}	
    }
	void addFirst(T data); 
	void addLast(T data);
	void add(Iterator<T> p, T data); 

	void removeRoom(Iterator<T> p);

	T removeFirst();
	T removeLast();
	bool remove(T target);
	//void remove(Iterator p);
	//bool contains(T target) const; 
	Node<T> getObject(int i) const;
	T getInfo(int i) const; 
	Iterator<T> begin()const;
   Iterator<T> end()const;  
	
    friend class Iterator<T>; 
private:
	Node<T> *head;
	Node<T> *tail;
	long size;   
};

template<typename T>
void SLL<T>::addFirst(T data){
	Node<T>* temp;
	if (head == nullptr){ //special case
	   temp = new Node<T>(data, nullptr);
	   head = tail = temp;
	   size++; 
	}
	else{
	   temp = new Node<T>(data, head); 
	   head = temp;  
	   size++;  
	}
}

template<typename T>
void SLL<T>::addLast(T data){
	Node<T>* temp = new Node<T>(data, nullptr); 
	if (head==nullptr){ //special case
	  head = tail = temp;
	  size++; 
	}
	else {
	  tail-> next = temp;  
	  tail = temp; 
	  size++; 	
	}
}

template<typename T>
void SLL<T>::add(Iterator<T> p, T data){
	Node<T> * next =  (p.current)->next;
	Node<T> * node = new Node<T>(data, next);
	(p.current)->next = node;
} 



template<typename T>
void SLL<T>::removeRoom(Iterator<T> p){

	Node<T> *t = head;

	if((p.current) == head){

		delete head;
		(p.current) = nullptr;
		return;

	}

	while(t->next != (p.current)){
		t = t->next;
	}

	Node<T> *temp = (p.current);

	p.current = t;

	(p.current)->next = temp->next;

	delete temp;

}




template<typename T>
T SLL<T>::removeFirst(){
	if (head == nullptr)
		throw std::runtime_error("ERROR: Empty List!"); 
	Node<T>* temp = head; 
	head = head -> next; 
	if (head == nullptr) //Special Case
	   tail = nullptr;
	T data = temp -> info;
	delete temp;
	temp = nullptr; 
	size--;  
	return data;
}

template<typename T>
T SLL<T>::removeLast(){
	if (head == nullptr)
		throw std::runtime_error("ERROR: Empty List!"); 
	Node<T>* tmp = head; 
	for (int i = 0; i < size - 2; i++)
        tmp = tmp->next; 
	Node<T>* last = tail; 
	tail = tmp;        
	tail -> next = nullptr;  
	T data = last -> info;
	delete last; 
	last = nullptr;     
	size--;        
	return data;
}

//removes the first occurance of target and returns true
//if target doesn't exist, it returns false
template<typename T>
bool SLL<T>::remove(T target){
	if (head == nullptr) // list is empty
		throw std::runtime_error("ERROR: Empty List!"); 	
	Node<T>* prev = nullptr;
	Node<T>* tmp = head;
	if (head->info  == target){
		head = head->next;
		--size;
		delete tmp;
		if (head == nullptr) //only one node in list 
	 		tail = nullptr; 
	 	return true;
	}
	// there is more than one node in the list
	prev = head;
	tmp = head->next;
	while (tmp != nullptr){
		if (tmp->info == target){
			prev->next = tmp->next;
			if (tmp == tail)
				tail = prev;
			delete tmp;
			tmp = nullptr;
			--size;
			return true; 
		}
		prev = tmp; 
		tmp = tmp->next;
	}		
	return false;
}



template<typename T> 
Node<T> SLL<T>::getObject(int index) const { 
	if (index < 0 || index > size - 1) 
	  throw std::runtime_error("Index out of range"); 
	Node<T>* current = head; 
	for (int i = 0; i < index; i++) 
	     current = current->next; 
	return *current; 
} 

template<typename T> 
T SLL<T>::getInfo(int index) const { 
	if (index < 0 || index > size - 1) 
	  throw std::runtime_error("Index out of range"); 
	Node<T>* current = head; 
	for (int i = 0; i < index; i++) 
	     current = current->next; 
	return current->info; 
} 

template<typename T>
Iterator<T> SLL<T>::begin() const {
    return Iterator<T>(head);
}

template<typename T>
Iterator<T> SLL<T>::end()const {
    return Iterator<T>(tail->next);
}

#endif