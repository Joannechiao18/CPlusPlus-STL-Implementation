#ifndef LIST_H
#define LIST_H

// ListNode class template definition
template< typename T >
struct ListNode
{
	ListNode *next;
	T myVal;
	ListNode *prev;
}; // end class template ListNode


// ListIterator class template definition
template< typename T >
class ListIterator
{
	template< typename T > friend class list;
public:
	ListIterator(ListNode< T > *p = nullptr) // default constructor
		: ptr(p)
	{
	}

	ListIterator(const ListIterator &iteratorToCopy) // copy constructor
		: ptr(iteratorToCopy.ptr)
	{
	}

	~ListIterator() // destructor
	{
	}

	// const return avoids: ( a1 = a2 ) = a3
	const ListIterator& operator=(const ListIterator &right)
	{
		if (&right != this) // avoid self-assignment
			ptr = right.ptr;
		return *this; // enables x = y = z, for example
	}

	bool operator==(const ListIterator &right) const // equal to
	{
		return ptr == right.ptr;
	}

	bool operator!=(const ListIterator &right) const // not equal to
	{
		return ptr != right.ptr;
	}

	T& operator*() const // dereferencing operator
	{
		return ptr->myVal;
	}

	ListIterator& operator++() // prefix increment operator
	{
		ptr = ptr->next;
		return *this;
	}

	ListIterator& operator--() // prefix decrement operator
	{
		ptr = ptr->prev;
		return *this;
	}

private:
	ListNode< T > *ptr = nullptr; // keep a pointer to list
}; // end class template ListIterator


// ReverseListIterator class template definition
template< typename T >
class ReverseListIterator : public ListIterator< T >
{
public:
	ReverseListIterator(ListNode< T > *p = nullptr) // default constructor
		: ListIterator< T >(p)
	{
	}

	ReverseListIterator(const ReverseListIterator &iteratorToCopy) // copy constructor
		: ListIterator< T >(iteratorToCopy)
	{
	}

	~ReverseListIterator() // destructor
	{
	}

	// const return avoids: ( a1 = a2 ) = a3
	const ReverseListIterator& operator=(const ReverseListIterator &right)
	{
		if (&right != this) // avoid self-assignment
			ListIterator< T >::operator=(right);
		return *this; // enables x = y = z, for example
	}

	ReverseListIterator& operator++() // prefix increment operator
	{
		ListIterator< T >::operator--();
		return *this;
	}

	ReverseListIterator& operator--() // prefix decrement operator
	{
		ListIterator< T >::operator++();
		return *this;
	}
}; // end class template ReverseListIterator


// list class template definition
template< typename T >
class list
{
	template< typename T >
	friend bool operator==(const list< T > &lhs, const list< T > &rhs);

	template< typename T >
	friend bool operator!=(const list< T > &lhs, const list< T > &rhs);

public:
	using iterator = ListIterator< T >;
	using reverse_iterator = ReverseListIterator< T >;

	list(unsigned int n = 0); // Constructs an empty list container, with n elements.

	// Constructs a list container with a copy of each of the elements in x,
	// in the same order.
	list(const list &x);

	// Destroys all list elements,
	// and deallocates all the storage allocated by the list container.
	~list();

	// Copies all the elements from "right" into the list container 
	const list& operator=(const list &x);

	iterator begin() const; // Returns a pointer pointing to the first element in the list container.

	iterator end() const; // Returns an pointer referring to the past-the-end element in the list container.

	reverse_iterator rbegin() const; // Returns a pointer pointing to the last element in the list container
									 // (i.e., its reverse beginning).

	reverse_iterator rend() const; // Returns a pointer pointing to the theoretical element preceding
								   // the first element in the list container (which is considered its reverse end).

	// Returns the number of elements in the list container.
	unsigned int size() const;

	// The list container is extended by inserting a new element
	// before the element at the specified position.
	// This effectively increases the list size by one.
	iterator insert(iterator position, const T &val);

	// Removes from the list container the element at the specified position.
	// This effectively reduces the list size by one.
	iterator erase(iterator position);

	// Resizes the list container so that it contains n elements.
	// If n is smaller than the current list container mySize,
	// the content is reduced to its first n elements, removing those beyond.
	// If n is greater than the current list container mySize,
	// the content is expanded by inserting at the end
	// as many elements as needed to reach a mySize of n.
	void resize(unsigned int n);

	// Removes all elements from the list container (which are destroyed).
	void clear();

private:
	unsigned int mySize = 0; // the number of elements in the list container

	// pointing to the past-the-end element in the list container
	ListNode< T > *myHead = nullptr;
}; // end class template list


// Constructs an empty list container, with no elements.
template< typename T >
list< T >::list(unsigned int n)
	: mySize(n)
{
	myHead=new ListNode<T>;
	myHead->myVal=T();
	myHead->prev=myHead->next=myHead;

	if(n>0)
	{
		for(int i=0;i<n;i++)
			insert(end(),T());
	}
}

// Constructs a list container with a copy of each of the elements in x,
// in the same order.
template< typename T >
list< T >::list(const list< T > &x)
	: mySize( 0 )
{
	myHead=new ListNode<T>;
	myHead->myVal=T();
	myHead->prev=myHead->next=myHead;

	iterator right=x.begin();
	for(;it!=right.end();it++)
		insert(end(),*right);
}

// Destroys all list container elements,
// and deallocates all the storage allocated by the list container.
template< typename T >
list< T >::~list()
{
	clear();
	delete myHead;
}

// Assigns new contents to the container, replacing its current contents,
// and modifying its size accordingly.
template< typename T >
const list< T >& list< T >::operator=(const list< T > &x)
{
	if (&x != this) // avoid self-assignment
	{
		resize(right.size());
		for(int i=0;i<x.size();i++)
			this->begin()[i]=right.begin()[i];		
	}

	return *this; // enables x = y = z, for example
} // end function operator=

template< typename T >
typename list< T >::iterator list< T >::begin() const
{
	return iterator(myHead->next);
}

template< typename T >
typename list< T >::iterator list< T >::end() const
{
	return iterator(myHead);
}

template< typename T >
typename list< T >::reverse_iterator list< T >::rbegin() const
{
	return reverse_iterator(myHead->prev);
}

template< typename T >
typename list< T >::reverse_iterator list< T >::rend() const
{
	return reverse_iterator(myHead);
}

template< typename T >
unsigned int list< T >::size() const
{
	return mySize;
}

// The list container is extended by inserting a new element
// before the element at the specified position.
// This effectively increases the list size by one.
template< typename T >
typename list< T >::iterator list< T >::insert(iterator position, const T &val)
{
	ListNode<T> *new_node=new ListNode<T>;
	new_node->myVal=val;

	new_node->prev=position.ptr->prev;
	position.ptr->prev->next=new_node;
	position.ptr->prev=new_node;
	new_node->next=position.ptr

	mySize++;

	return begin();
}

// Removes from the list container the element at the specified position.
// This effectively reduces the list size by one.
template< typename T >
typename list< T >::iterator list< T >::erase(iterator position)
{
	position.ptr->prev->next=position.ptr->next;
	position.ptr->next->prev=position.ptr->prev;
	delete position.ptr;

	mySize--;	
	return begin();
}

// Resizes the list container so that p contains n elements.
template< typename T >
void list< T >::resize(unsigned int n)
{
	while (mySize != n)
		if (mySize > n)
			erase(--end());
		else
			insert(end(), T());
}

// Removes all elements from the list container (which are destroyed)
template< typename T >
void list< T >::clear()
{
	if (mySize != 0) // the list is not empty
	{
		while (myHead->next != myHead)
		{
			myHead->next = myHead->next->next;
			delete myHead->next->prev;
		}

		myHead->prev = myHead;
		mySize = 0;
	}
}

// determine if two lists are equal and return true, otherwise return false
template< typename T >
bool operator==(const list< T > &lhs, const list< T > &rhs)
{
	if (lhs.mySize != rhs.mySize) // different number of elements
		return false;

	ListNode< T > *p1 = lhs.myHead->next;
	ListNode< T > *p2 = rhs.myHead->next;
	for (; p1 != lhs.myHead && p2 != rhs.myHead; p1 = p1->next, p2 = p2->next)
		if (p1->myVal != p2->myVal)
			return false;

	return true;
}

// inequality operator; returns opposite of == operator
template< typename T >
bool operator!=(const list< T > &lhs, const list< T > &rhs)
{
	return !(lhs == rhs);
}

#endif