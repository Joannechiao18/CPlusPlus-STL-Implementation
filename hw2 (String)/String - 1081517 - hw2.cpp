#include "String.h" // include definition of class String
#include <iostream>

//default constructor
string::string() 
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
}

//frombuffer constructor
string::string( const char *const ptr, const size_type count )
   : bx(),
     mySize( 0 ),
     myRes( 15 )  
{
    //resize(count);  //resize會幫你判斷要用ptr或buf，mySize和myRes也會設定成新的值
    //for (int i = 0; i < count; i++)
    //    myPtr()[i] = ptr[i];

    int newmyRes = myRes * 1.5;
    if (newmyRes < (count / 16) * 16 + 15)
        newmyRes = (count / 16) * 16 + 15;

    if (count <= myRes)
    {
        for (int i = 0; i < count; i++)
            bx.buf[i] = ptr[i];
    }
    else if (count > myRes)
    {
        bx.ptr = new char[newmyRes + 1]();
        for (int i = 0; i < count; i++)
            bx.ptr[i] = ptr[i];;
        myRes = newmyRes;
    }
    mySize = count;
}

//fill constructor
string::string( const size_type count, const char ch )
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
    resize(count);
    for (int i = 0; i < count; i++)
        myPtr()[i] = ch;
}

//copy constructor
string::string( const string &right )
   : bx(),
     mySize( 0 ),
     myRes( 15 )
{
    resize(right.size());
    for (int i = 0; i < right.mySize; i++)
        myPtr()[i] = right.myPtr()[i];

    /*mySize = right.mySize;
    myRes = (mySize / 16) * 16 + 15;
    不能用myRes=right.myRes，是和STL的string比，這樣配置規則會不同

    if(myRes > 15)
        bx.ptr = new char[myRes + 1]();  
    for (int i = 0; i < right.mySize; i++)
        myPtr()[i] = right.myPtr()[i];*/
}

string::~string() 
{
   if( myRes > 15 )
      delete[] bx.ptr;
}

string::value_type* string::myPtr()
{
   if( myRes < 16 )
      return bx.buf;
   else
      return bx.ptr;
}

const string::value_type* string::myPtr() const
{
   if( myRes < 16 )
      return bx.buf;
   else
      return bx.ptr;
}

string& string::assign( const string &right )
{
   if( this != &right )
   {
       //resize(right.mySize);  //只需要一個參數，在標頭檔裡面有預設好的字元參數
       //for (int i = 0; i < right.mySize; i++)
       //    myPtr()[i] = right.myPtr()[i];

       int rightSize = right.size();
       if (rightSize > capacity())
       {
           if (myRes > 15)
               delete[]bx.ptr;

           int newmyRes = myRes * 1.5;
           if (newmyRes < (rightSize / 16) * 16 + 15)
               newmyRes = (rightSize / 16) * 16 + 15;

           bx.ptr = new char[newmyRes + 1]();
           myRes = newmyRes;
       }

       mySize = rightSize;

       for (int i = 0; i < rightSize; i++)
           myPtr()[i] = right.myPtr()[i];
   }

   return *this;
}

void string::clear() 
{
   mySize = 0;
   myPtr()[ 0 ] = value_type();
}

string::iterator string::begin() 
{
   return iterator( myPtr() );
}

string::const_iterator string::begin() const 
{
   return const_iterator( myPtr() );
}

string::iterator string::end() 
{
   return iterator( myPtr() + static_cast< difference_type >( mySize ) );
}

string::const_iterator string::end() const 
{
   return const_iterator( myPtr() + static_cast< difference_type >( mySize ) );
}

string::reference string::element( const size_type off ) 
{
   return myPtr()[ off ];
}

string::const_reference string::element( const size_type off ) const 
{
   return myPtr()[ off ];
}

void string::push_back( char ch )
{
   resize( mySize + 1 );
   myPtr()[ mySize - 1 ] = ch;
}

void string::pop_back() 
{
   if( mySize > 0 )
      --mySize;
}

string::reference string::front() 
{
   return myPtr()[ 0 ];
}

string::const_reference string::front() const 
{
   return myPtr()[ 0 ];
}

string::reference string::back() 
{
   return myPtr()[ mySize - 1 ];
}

string::const_reference string::back() const 
{
   return myPtr()[ mySize - 1 ];
}

const char* string::c_str() const
{
   return myPtr();
}

string::size_type string::size() const
{
   return mySize;
}

void string::resize( const size_type newSize, const char ch )
{
    //int originalSize = size();
    //if (newSize > originalSize)
    //{
    //    if (newSize > capacity())
    //    {
    //        int newmyRes = myRes * 1.5;
    //        if (newmyRes < (newSize / 16) * 16 + 15)
    //            newmyRes = (newSize / 16) * 16 + 15;

    //        string TOCOPY(*this);

    //        bx.ptr = new char[newmyRes + 1]();
    //        for (int i = 0; i < originalSize; i++)
    //            bx.ptr[i] = TOCOPY.myPtr()[i];

    //        myRes = newmyRes;
    //    }
    //    for (int i = originalSize; i < newSize; i++)
    //        myPtr()[i] = ch;
    //}
    //mySize = newSize;

    if (newSize <= capacity())
    {
        if (newSize > mySize)
        {
            for (int i = mySize; i < newSize; i++)
                myPtr()[i] = ch;
        }
        mySize = newSize;  //如果newSize<mySize就直接指定其mySize為newSize，呼叫size()時會只擷取到mySize的地方
    }
    else
    {
        int newmyRes = myRes * 1.5;
        if (newmyRes < (newSize / 16) * 16 + 15)
            newmyRes = (newSize / 16) * 16 + 15;

        //value_type* temp = myPtr(); //(因為是union，所以原本的值可能會亂掉)
        //bx.ptr = new char[newmyRes + 1]();
        //for (int i = 0; i < mySize; i++)
        //    bx.ptr[i] = temp[i];
        //for (int i = mySize; i < newSize; i++)
        //    bx.ptr[i] = ch;

        string TOCOPY(*this);

        /*
        如果沒有copy constructor:
        string COPY(mySize,'\0');(fill constructor)
        for (int i = 0; i < mySize; i++)
             COPY.myPtr()[i] = myPtr()[i];
        */

        bx.ptr = new char[newmyRes + 1]();
        for (int i = 0; i < mySize; i++)
            bx.ptr[i] = TOCOPY.myPtr()[i];
        for (int i = mySize; i < newSize; i++)  //除了放值以外還要初始化新配值的空格
            bx.ptr[i] = ch;

        mySize = newSize;
        myRes = newmyRes;
    }
}

string::size_type string::capacity() const 
{
   return myRes;
}

bool string::empty() const 
{
   return mySize == 0;
}