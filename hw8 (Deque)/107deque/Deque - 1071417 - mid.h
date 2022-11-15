#ifndef DEQUE_H
#define DEQUE_H

// CLASS TEMPLATE DequeConstIterator
template< class MyDeque >
class DequeConstIterator // iterator for nonmutable deque
{
private:
	using size_type = typename MyDeque::size_type;

public:
	using value_type      = typename MyDeque::value_type;
	using difference_type = typename MyDeque::difference_type;
	using pointer         = typename MyDeque::const_pointer;
	using reference       = const value_type &;

	// construct with null pointer
	DequeConstIterator()
		: myOff(0),
		myCont(nullptr)
	{
	}

	// construct with offset off in *pDeque
	DequeConstIterator(size_type off, const MyDeque* pDeque)
		: myOff(off),
		myCont(pDeque)
	{
	}

	DequeConstIterator(const DequeConstIterator& right) // copy constructor
		: myOff(right.myOff),
		myCont(right.myCont)
	{
	}

	~DequeConstIterator() // destructor
	{
	}

	// const return avoids: ( a1 = a2 ) = a3
	const DequeConstIterator& operator=(const DequeConstIterator& right)
	{
		if (right != *this) // avoid self-assignment
		{
			myCont = right.myCont;
			myOff = right.myOff;
		}
		return *this; // enables x = y = z, for example
	}

	reference operator*() const
	{
		size_type block = myCont->getBlock(myOff);
		size_type off = myOff % 4;
		return myCont->map[block][off];
	}

	pointer operator->() const
	{
		return &(this->operator*());
	}

	DequeConstIterator& operator++() // preincrement
	{
		++myOff;
		return *this;
	}

	DequeConstIterator operator++(int) // postincrement
	{
		DequeConstIterator tmp = *this;
		++* this;
		return tmp;
	}

	DequeConstIterator& operator--() // predecrement
	{
		--myOff;
		return *this;
	}

	DequeConstIterator operator--(int) // postdecrement
	{
		DequeConstIterator tmp = *this;
		--* this;
		return tmp;
	}

	// increment by integer
	DequeConstIterator& operator+=(const difference_type off)
	{
		myOff += off;
		return *this;
	}

	// return this + integer
	DequeConstIterator operator+(const difference_type off) const
	{
		DequeConstIterator tmp = *this;
		return tmp += off;
	}

	// decrement by integer
	DequeConstIterator& operator-=(const difference_type off)
	{
		return *this += -off;
	}

	// return this - integer
	DequeConstIterator operator-(const difference_type off) const
	{
		DequeConstIterator tmp = *this;
		return tmp -= off;
	}

	// return difference of iterators
	difference_type operator-(const DequeConstIterator& right) const
	{
		return (static_cast<difference_type>(this->myOff - right.myOff));
	}

	reference operator[](const difference_type off) const // subscript
	{
		return *(*this + off);
	}

	// test for iterator equality
	bool operator==(const DequeConstIterator& right) const
	{
		return this->myOff == right.myOff;
	}

	// test for iterator inequality
	bool operator!=(const DequeConstIterator& right) const
	{
		return !(*this == right);
	}

	// test if this < right
	bool operator<(const DequeConstIterator& right) const
	{
		return this->myOff < right.myOff;
	}

	// test if this > right
	bool operator>(const DequeConstIterator& right) const
	{
		return right < *this;
	}

	// test if this <= right
	bool operator<=(const DequeConstIterator& right) const
	{
		return !(right < *this);
	}

	// test if this >= right
	bool operator>=(const DequeConstIterator& right) const
	{
		return !(*this < right);
	}

	const MyDeque* myCont; // keep a pointer to deque
	size_type myOff;       // offset of element in deque
};


// CLASS TEMPLATE DequeIterator
template< class MyDeque >
class DequeIterator : public DequeConstIterator< MyDeque >
{ // iterator for mutable deque
private:
	using size_type = typename MyDeque::size_type;
	using MyBase = DequeConstIterator< MyDeque >;

public:
	using value_type      = typename MyDeque::value_type;
	using difference_type = typename MyDeque::difference_type;
	using pointer         = typename MyDeque::pointer;
	using reference       = value_type &;

	DequeIterator() // construct with null deque pointer
	{
	}

	DequeIterator(size_type off, const MyDeque* pDeque)
		: MyBase(off, pDeque) // construct with offset off in *pDeque
	{
	}

	reference operator*() const // return designated object
	{
		return const_cast<reference>(MyBase::operator*());
	}

	pointer operator->() const // return pointer to class object
	{
		return &(this->operator*());
	}

	DequeIterator& operator++() // preincrement
	{
		MyBase::operator++();
		return *this;
	}

	DequeIterator operator++(int) // postincrement
	{
		DequeIterator tmp = *this;
		MyBase::operator++();
		return tmp;
	}

	DequeIterator& operator--() // predecrement
	{
		MyBase::operator--();
		return *this;
	}

	DequeIterator operator--(int) // postdecrement
	{
		DequeIterator tmp = *this;
		MyBase::operator--();
		return tmp;
	}

	// increment by integer
	DequeIterator& operator+=(const difference_type off)
	{
		MyBase::operator+=(off);
		return *this;
	}

	// return this + integer
	DequeIterator operator+(const difference_type off) const
	{
		DequeIterator tmp = *this;
		return tmp += off;
	}

	// decrement by integer
	DequeIterator& operator-=(const difference_type off)
	{
		MyBase::operator-=(off);
		return *this;
	}

	using MyBase::operator-; // return difference of iterators

	// return this - integer
	DequeIterator operator-(const difference_type off) const
	{
		DequeIterator tmp = *this;
		return tmp -= off;
	}

	reference operator[](const difference_type off) const // subscript
	{
		return const_cast<reference>(MyBase::operator[](off));
	}
};


template < class Ty >
struct DequeSimpleTypes // wraps types needed by iterators
{
	using value_type      = Ty;
	using size_type       = size_t;
	using difference_type = ptrdiff_t;
	using pointer         = value_type *;
	using const_pointer   = const value_type*;
	using MapPtr          = Ty * *;
};

// CLASS TEMPLATE DequeVal
template < class ValTypes >
class DequeVal // base class for deque to hold data
{
public:
	using value_type      = typename ValTypes::value_type;
	using size_type       = typename ValTypes::size_type;
	using difference_type = typename ValTypes::difference_type;
	using pointer         = typename ValTypes::pointer;
	using const_pointer   = typename ValTypes::const_pointer;
	using reference       = value_type &;
	using const_reference = const value_type &;
	using MapPtr          = typename ValTypes::MapPtr;

	DequeVal() // initialize values
		: map(),
		mapSize(0),
		myOff(0),
		mySize(0)
	{
	}

	// determine block from offset
	size_type getBlock(size_type off) const
	{
		return off % (4 * mapSize) / 4;
		//      return ( off / 4 ) & ( mapSize - 1 );
	}

	MapPtr map;        // pointer to array of pointers to blocks
	size_type mapSize; // size of map array, zero or 2^N
	size_type myOff;   // offset of initial element
	size_type mySize;  // current length of sequence
};


// CLASS TEMPLATE deque
template< class Ty >
class deque // circular queue of pointers to blocks
{
private:
	using MapPtr = Ty * *;
	using ScaryVal = DequeVal< DequeSimpleTypes< Ty > >;

public:
	using value_type      = Ty;
	using size_type       = size_t;
	using difference_type = ptrdiff_t;
	using pointer         = value_type *;
	using const_pointer   = const value_type*;
	using reference       = value_type &;
	using const_reference = const value_type &;

	using iterator               = DequeIterator< ScaryVal >;
	using const_iterator         = DequeConstIterator< ScaryVal >;

	// construct empty deque
	deque()
		: myData()
	{
	}

	//fill constructor
	// construct from count * val
	deque(size_type count, const Ty& val)
		: myData()
	{
		if (count == 0)
		{			
			myData.map = nullptr;  
			myData.mapSize = 0;
		}
		else
		{
			myData.mapSize = 8;
			while (count > 4 * (myData.mapSize - 1))  
				myData.mapSize *= 2;

			myData.map = new Ty * [myData.mapSize]();

			for (size_type i = 0; i <= (count - 1) / 4; i++)
				myData.map[i] = new Ty[4];
			/*for (size_type i = 0; i < count / 4; i++)
				myData.map[i] = new Ty[4]();
			if (count % 4 != 0)
				myData.map[count / 4] = new Ty[4]();*/

			for (size_type i = 0; i < count; i++)
				myData.map[i / 4][i % 4] = val;
		}
		myData.mySize = count;
	}

	// destroy the deque
	~deque()
	{
		clear();
	}

	// return iterator for beginning of mutable sequence
	iterator begin()
	{
		return iterator(myData.myOff, &myData);
	}

	// return iterator for end of mutable sequence
	iterator end()
	{
		return iterator(myData.myOff + myData.mySize, &myData);
	}

	// return length of sequence
	size_type size() const
	{
		return myData.mySize;
	}

	// The deque container is extended by inserting a new element
	// before the element at the specified position.
	void insert(const_iterator position, const Ty& val)
	{
		if (myData.mySize == 0)
		{
			if (position == begin() && position == end())
			{
				if (myData.mapSize == 0)
				{
					myData.mapSize = 8;
					myData.map = new Ty * [myData.mapSize]();
				}

				myData.myOff = 4 * myData.mapSize - 1; 
				int block = getBlock(myData.myOff);  //用getBlock的前提是myOff要先有指定值
				if (myData.map[block] == nullptr)
					myData.map[block] = new Ty[4]();

				myData.map[block][myData.myOff % 4] = val;
			}
		}
		else
		{
			if (begin() <= position && position <= end())
			{
				// all elements before position move forward
				if (position <= begin() + myData.mySize / 2)
				{
					unsigned int newFront = (myData.myOff - 1) % (4 * myData.mapSize);
					if (newFront % 4 == 3 && myData.mySize >= 4 * (myData.mapSize - 1))
					{
						doubleMapSize();
						newFront = (myData.myOff - 1) % (4 * myData.mapSize);
					}

					//push front
					iterator p1 = begin();
					
					for (; p1 != position; ++p1)
					{
						newFront = newFront % (4 * myData.mapSize);  /***/

						int block = getBlock(newFront);

						if (myData.map[block] == nullptr)
							myData.map[block] = new Ty[4]();
						myData.map[block][newFront % 4] = *p1;  
						newFront++;  /***/
					}

					if (myData.map[getBlock(newFront)] == nullptr) 
						myData.map[getBlock(newFront)] = new Ty[4]();
					myData.map[getBlock(newFront)][newFront % 4] = val;

					myData.myOff = newFront;
				}
				else // all elements after (and at) position move backward
				{
					unsigned int newBack = (myData.myOff + myData.mySize) % (4 * myData.mapSize);
					if (newBack % 4 == 0 && myData.mySize >= 4 * (myData.mapSize - 1))
					{
						doubleMapSize();
						newBack = myData.myOff + myData.mySize;
					}

					iterator p1 = end();
					p1--;

					for (; p1 != (--position)++; --p1)  
					{
						newBack = newBack % (4 * myData.mapSize);

						int block = getBlock(newBack);

						if (myData.map[block] == nullptr)
					 		myData.map[block] = new Ty[4]();

						myData.map[block][newBack % 4] = *p1;
						newBack--;
					}

					if (myData.map[getBlock(newBack)] == nullptr)
						myData.map[getBlock(newBack)] = new Ty[4]();
					myData.map[getBlock(newBack)][newBack % 4] = val;
				}
			}
		}

		++myData.mySize;
	}

	// erase all
	void clear()
	{
		if (myData.mapSize > 0)
		{
			for (size_type i = 0; i < myData.mapSize; i++)
				if (myData.map[i] != nullptr)
					delete[] myData.map[i];
			delete[] myData.map;

			myData.mapSize = 0;
			myData.mySize = 0;
			myData.myOff = 0;
			myData.map = MapPtr();
		}

		////erase
		//if (myData.mySize > 0)
		//{
			//if (begin() <= position && position <= end())
		//{
		//	if (position <= begin() + myData.mySize / 2)
		//	{
		//		size_type pos = (myData.myOff + 1) % 4 * myData.mapSize;
		//		iterator p1 = begin();
		//		for (; p1 != position; p1++)
		//		{
		//			pos = pos % 4 * myData.mapSize;
		//			int block = getBlock(pos);
		//			myData.map[block][pos % 4] = *p1;
		//			pos++;
		//		}				
		//	}
		//	else
		//	{
		//		size_type pos = myData.myOff + (position - begin());
		//		iterator p1 = position;
		//		p1++;
		//		for (; p1 != end(); p1++)
		//		{
		//			pos = pos % 4 * myData.mapSize;
		//			int block = getBlock(pos);
		//			myData.map[block][pos % 4] = *p1;
		//			pos++;
		//		}
		//	}			
		//	myData.mySize--;
		//}
		//}		
	}

private:

	// determine block from offset
	size_type getBlock(size_type off) const
	{
		return myData.getBlock(off);
		//      return ( ( myData.off / 4 ) & ( myData.mapSize - 1 ) );
	}

	void doubleMapSize()
	{
		if (myData.mapSize > 0)
		{
			int newSize = myData.mapSize * 2;
			Ty** buffer = new Ty * [newSize]();

			for (int i = myData.myOff / 4, t = 0; t < myData.mapSize; i++, t++)
				if (myData.map[i % myData.mapSize] != nullptr)
					buffer[i] = myData.map[i % myData.mapSize];

			delete[] myData.map;
			myData.map = buffer;
			myData.mapSize = newSize;
		}
	}

	ScaryVal myData;
};

#endif