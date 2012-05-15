#ifndef agents_arachnidutils_rangemap_rangemapconstiterator_h
#define agents_arachnidutils_rangemap_rangemapconstiterator_h

#include <map>

namespace SimpleRangeMap {

class SimpleRange;
template< typename N > class RangeMapIterator;

template< typename T >
class RangeMapConstIterator
{
public:
  RangeMapConstIterator( const typename std::map< SimpleRange, T >::const_iterator& );
  RangeMapConstIterator( const RangeMapIterator< T >& );
  RangeMapConstIterator();

  const T&                operator *()                                    const;
  const T                *operator->()                                    const;
  bool                    operator==( const RangeMapIterator< T >& )      const;
  bool                    operator==( const RangeMapConstIterator< T >& ) const;
  bool                    operator!=( const RangeMapIterator< T >& )      const;
  bool                    operator!=( const RangeMapConstIterator< T >& ) const;
  RangeMapConstIterator&  operator++();
  RangeMapConstIterator   operator++( int );
  RangeMapConstIterator&  operator--();
  RangeMapConstIterator   operator--( int );

  const unsigned long lower() const;
  const unsigned long upper() const;

  typename std::map< SimpleRange, T >::const_iterator m_iterator;
};

} // namespace SimpleRangeMap

#include "rangemapconstiterator.hpp"

#endif // agents_arachnidutils_rangemap_rangemapconstiterator_h
