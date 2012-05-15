#ifndef agents_arachnidutils_rangemap_rangemapiterator_h
#define agents_arachnidutils_rangemap_rangemapiterator_h

#include <map>

namespace SimpleRangeMap {

class SimpleRange;

template< typename T >
class RangeMapIterator
{
public:
  RangeMapIterator( const typename std::map< SimpleRange, T >::iterator& );
  RangeMapIterator();

  T&                operator *();
  const T&          operator *()                          const;
  T                *operator->();
  const T          *operator->()                          const;
  bool              operator==( const RangeMapIterator& ) const;
  bool              operator!=( const RangeMapIterator& ) const;
  RangeMapIterator& operator++();
  RangeMapIterator  operator++( int );
  RangeMapIterator& operator--();
  RangeMapIterator  operator--( int );

  const unsigned long lower() const;
  const unsigned long upper() const;

  typename std::map< SimpleRange, T >::iterator m_iterator;
};

} // namespace SimpleRangeMap

#include "rangemapiterator.hpp"

#endif // agents_arachnidutils_rangemap_rangemapiterator_h
