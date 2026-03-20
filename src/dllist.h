//List ADT using Doubly Linked List
#pragma once

#include "../include/dlinkedlistnode.h"
#include "../include/list.h"



template <typename T>
class DLList : public List<T>{
    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;
        size_t n = 0;

    public:
        ~DLList(){}
 
/*
	virtual void add(const size_t i, const T& x) = 0;
	virtual T remove(const size_t i) = 0;
	virtual T get(const size_t i) const = 0;
	virtual T set(const size_t i, const T& x) = 0;
	virtual size_t size() const = 0;
*/

};