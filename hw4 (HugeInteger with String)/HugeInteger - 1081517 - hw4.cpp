#include "HugeInteger.h" // include definition of class HugeInteger

// default constructor; construct a zero HugeInteger with size 1
HugeInteger::HugeInteger()
   : integer( 1, '0' ) 
{
}

// constructor; construct a zero HugeInteger with size n
HugeInteger::HugeInteger( unsigned int n )
   : integer( ( n > 0 ) ? n : 1, '0' )
{
} // end HugeInteger constructor

// copy constructor
// constructs a HugeInteger with a copy of each of the elements in integerToCopy
HugeInteger::HugeInteger( const HugeInteger &integerToCopy )
   : integer( integerToCopy.integer )
{
} // end HugeInteger copy constructor

// destructor; destroys the HugeInteger
HugeInteger::~HugeInteger()
{
} // end HugeInteger destructor

// overloaded assignment operator;
// const return avoids: ( a1 = a2 ) = a3
const HugeInteger& HugeInteger::operator=( const HugeInteger &right )
{
   if( &right != this ) // avoid self-assignment
      integer = right.integer;  /*calls for function "assign" in String.h*/

   return *this; // enables x = y = z, for example
}

// function that tests if two HugeIntegers are equal
bool HugeInteger::operator==( const HugeInteger &right ) const
{
  // return operator==( integer, right.integer );
   return ( integer == right.integer );  /*calls for "operator==" in String.h*/
} // end function equal

// function that tests if one HugeInteger is less than another
bool HugeInteger::operator<( const HugeInteger &right ) const
{
    if (integer.size() < right.integer.size())
        return true;
    else if (integer.size() > right.integer.size())
        return false;
    for (int i = integer.size() - 1; i >= 0; i--)
    {
        if (integer.begin()[i] > right.integer.begin()[i])
            return false;
        if (integer.begin()[i] < right.integer.begin()[i])
            return true;
    }
    return false; 
} // end function less

// function that tests if one HugeInteger is less than or equal to another
bool HugeInteger::operator<=( const HugeInteger &right ) const
{
   return ( *this == right || *this < right );
} // end function lessEqual

// addition operator; HugeInteger + HugeInteger
HugeInteger HugeInteger::operator+( HugeInteger &op2 )  
/*函數原型:HugeInteger operator+(HugeInteger &op2)或
friend HugeInteger operator+(cosnt HugeInteger & op1, const HugeInteger & op2)*/
{
   unsigned int op1Size = integer.size();
   unsigned int op2Size = op2.integer.size();
   unsigned int sumSize = ( op1Size >= op2Size ) ? op1Size + 1 : op2Size + 1;

   HugeInteger sum( sumSize );

   string::iterator it1 = integer.begin();
   string::iterator it3 = sum.integer.begin();
   for( ; it1 != integer.end(); ++it1, ++it3 )
      *it3 = *it1;

   string::iterator it2 = op2.integer.begin();
   for( it3 = sum.integer.begin(); it2 != op2.integer.end(); ++it2, ++it3 )
      *it3 = ( *it3 - '0' ) + ( *it2 - '0' ) + '0';

   for( it3 = sum.integer.begin(); it3 != sum.integer.end() - 1; ++it3 )
      if( *it3 > '9' )
      {
         ( *it3 ) = ( *it3 - '0' ) - 10 + '0';
         ( *( it3 + 1 ) ) = ( *( it3 + 1 ) - '0' ) + 1 + '0';
      }

   if (*it3 == '0')
      sum.integer.pop_back();

   return sum; 
} // end function add

// subtraction operator; HugeInteger - HugeInteger
HugeInteger HugeInteger::operator-( HugeInteger &op2 )
{
   HugeInteger zero;

   if( *this == op2 )
      return zero;

   HugeInteger difference( *this );

   string::iterator it2 = op2.integer.begin();
   string::iterator it3 = difference.integer.begin();
   for (it3 = difference.integer.begin(); it2 != op2.integer.end(); it2++, it3++)
   {
       int n = (*it3 - '0') - (*it2 - '0');
       if (n < 0)
       {
           *it3 = (*it3 - '0') + 10 + '0';
           *it3 = (*it3 - '0') - (*it2 - '0') + '0';
           int i = 1;
           if (*(it3 + i) == '0' && (it3 + i) != difference.integer.end())
           {
               while (*(it3 + i) == '0' && (it3 + i) != difference.integer.end())
               {
                   (*(it3 + i)) = (*(it3 + i) - '0') + 10 + '0';
                   (*(it3 + i)) = (*(it3 + i) - '0') - 1 + '0';
                   i++;
                   if (*(it3 + i) > '0')
                   {
                       (*(it3 + i)) = (*(it3 + i) - '0') - 1 + '0';
                       break;
                   }
               }
           }
           else
               *(it3 + i) = (*(it3 + i) - '0') - 1 + '0';
       }
       else
           *it3 = n + '0';
   }

   it3 = difference.integer.end() - 1;
   while (*it3 == '0' && difference.integer.size() > 1)
   {
       it3--;
       difference.integer.pop_back();
   }
       
   return difference;
} // end function subtract

// multiplication operator; HugeInteger * HugeInteger
HugeInteger HugeInteger::operator*( HugeInteger &op2 )
{
   HugeInteger zero;
   if( isZero() || op2.isZero() )
      return zero;

   unsigned int productSize = integer.size() + op2.integer.size();
   HugeInteger product( productSize );

   string::iterator it1 = integer.begin();
   string::iterator it2 = op2.integer.begin();
   string::iterator it3 = product.integer.begin();
   int i;
   for (it3 = product.integer.begin(); it2 != op2.integer.end(); it2++, it3++)
   {
       for (it1 = integer.begin(), i = 0; it1 != integer.end(); it1++, i++)
       {
           int n = (*(it3 + i) - '0') + (*it2 - '0') * (*it1 - '0');
           if (n > 9)
           {
               (*(it3 + i)) = n % 10 + '0';
               (*(it3 + i + 1)) = (*(it3 + i + 1) - '0') + n / 10 + '0';       
           }
           else
               (*(it3 + i)) = n + '0';
       }
   }
       
   it3 = product.integer.end() - 1;
   while (*it3 == '0' && product.integer.size() > 1)
   {
       it3--;
       product.integer.pop_back();
   }

   return product;
} // end function multiply

// division operator; HugeInteger / HugeInteger provided that op2 is not zero
HugeInteger HugeInteger::operator/( HugeInteger &op2 )
{
   HugeInteger remainder(*this); 
   /*HugeInteger remainder(integer.size());
   remainder.operator=(*this);*/

   HugeInteger zero;
   if (*this < op2)
      return zero;

   unsigned int n = integer.size() - op2.integer.size();
   HugeInteger buffer(integer.size());
   string::iterator it1 = buffer.integer.end() - 1;  
   for (int i = op2.integer.size() - 1; i >= 0; i--, it1--)
       *it1 = op2.integer.begin()[i];  //buffer=divisor shift left by n positions

   unsigned int quotientSize = integer.size() - op2.integer.size();

   if (*this < buffer)
       buffer.divideByTen();
   else
       quotientSize++;

   HugeInteger quotient(quotientSize);
   for (int k = quotientSize - 1; k >= 0; k--)
   {
       while (!(remainder < buffer))
       {
           /*HugeInteger temp;
           temp.operator=(remainder.operator-(buffer));
           remainder.operator=(temp);
           quotient.integer.begin()[k]++;*/
           
           remainder = remainder - buffer;  //"="和"-"都會呼叫operator
           quotient.integer.begin()[k]++;
       }
       /*if (k > 0)*/
           buffer.divideByTen();
   }
    
   return quotient;
} // end function divide

// modulus operator; HugeInteger % HugeInteger provided that op2 is not zero
HugeInteger HugeInteger::operator%( HugeInteger &op2 )
{
   HugeInteger quotient = ( *this ) / op2;
   HugeInteger product = quotient * op2;
   HugeInteger remainder = ( *this ) - product;
   return remainder;
}

// convert a string of decimal digits into a HugeInteger
void HugeInteger::convert( string &str )
{
   integer.resize( str.size() );
   string::iterator it1 = integer.end() - 1;
   string::iterator it2 = str.begin();
   for( ; it2 != str.end(); --it1, ++it2 )
      *it1 = *it2;
} // end function convert

// function that tests if a HugeInteger is zero
bool HugeInteger::isZero()
{
   for( string::iterator it = integer.begin(); it != integer.end(); ++it )
      if( *it != '0' )
         return false;  //比第一個就不是'0'就會return false，這個function就結束了

   return true;
}

// function that divides a HugeInteger by 10; shift a HugeInteger one position to the right
void HugeInteger::divideByTen()
{
    string::iterator it = integer.begin() + 1;
    for (; it != integer.end(); it++)
        *(it - 1) = *it;
    integer.pop_back();

   //string::iterator it = integer.begin();
   //string::iterator it2 = it;
   //for( ++it2; it2 != integer.end(); ++it, ++it2 )
   //   *it = *it2;  //integer是本體，所以把*it2放到*it

   //integer.pop_back();  //要pop_back()的數字會是零
}

// overloaded output operator
ostream& operator<<( ostream &output, const HugeInteger &hugeInteger )  
{
   string::const_iterator it = hugeInteger.integer.end() - 1;

   for( ; it != hugeInteger.integer.begin() - 1; --it )
      if( *it <= '9' )
         output << *it;

   return output; // enables cout << x << y; (顯示字串並傳回cout物件，所以cout<<x會顯示字串然後取代成其回傳值)
} // end function output
