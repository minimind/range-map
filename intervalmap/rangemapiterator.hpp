#ifndef RANGE_MAP_ITERATOR_HPP
#define RANGE_MAP_ITERATOR_HPP

#include "rangemapiterator.h"
#include "simplerange.h"

namespace SimpleRangeMap {

template< typename T >
RangeMapIterator< T >::RangeMapIterator( const typename std::map< SimpleRange, T >::iterator& i )
  : m_iterator( i )
{
}

template< typename T >
RangeMapIterator< T >::RangeMapIterator()
{
}

template< typename T >
T& RangeMapIterator< T >::operator *()
{
  return m_iterator->second;
}

template< typename T >
const T& RangeMapIterator< T >::operator *() const
{
  return m_iterator->second;
}

template< typename T >
T *RangeMapIterator< T >::operator->()
{
  return &( m_iterator->second );
}

template< typename T >
const T *RangeMapIterator< T >::operator->() const
{
  return &( m_iterator->second );
}

template< typename T >
bool RangeMapIterator< T >::operator==( const RangeMapIterator& n ) const
{
  return m_iterator == n.m_iterator;
}

template< typename T >
bool RangeMapIterator< T >::operator!=( const RangeMapIterator& n ) const
{
  return m_iterator != n.m_iterator;
}

template< typename T >
RangeMapIterator< T >& RangeMapIterator< T >::operator++()
{
  ++m_iterator;
  return *this;
}

template< typename T >
RangeMapIterator< T > RangeMapIterator< T >::operator++( int )
{
  RangeMapIterator toReturn( *this );
  ++( *this );
  return toReturn;
}

template< typename T >
RangeMapIterator< T >& RangeMapIterator< T >::operator--()
{
  --m_iterator;
  return *this;
}

template< typename T >
RangeMapIterator< T > RangeMapIterator< T >::operator--( int )
{
  RangeMapIterator toReturn( *this );
  --( *this );
  return toReturn;
}

template< typename T >
const unsigned long RangeMapIterator< T >::lower() const
{
  return m_iterator->first.m_lowerRange;
}

template< typename T >
const unsigned long RangeMapIterator< T >::upper() const
{
  return m_iterator->first.m_upperRange;
}

} // namespace SimpleRangeMap

#endif // RANGE_MAP_ITERATOR_HPP
