#ifndef RANGE_MAP_CONST_ITERATOR_HPP
#define RANGE_MAP_CONST_ITERATOR_HPP

#include "rangemapconstiterator.h"
#include "rangemapiterator.h"
#include "simplerange.h"

namespace SimpleRangeMap {

template< typename T >
RangeMapConstIterator< T >::RangeMapConstIterator( const typename std::map< SimpleRange, T >::const_iterator& i )
  : m_iterator( i )
{
}

template< typename T >
RangeMapConstIterator< T >::RangeMapConstIterator( const RangeMapIterator< T >& i )
  : m_iterator( i.m_iterator )
{
}

template< typename T >
RangeMapConstIterator< T >::RangeMapConstIterator()
{
}

template< typename T >
const T& RangeMapConstIterator< T >::operator *() const
{
  return m_iterator->second;
}

template< typename T >
const T *RangeMapConstIterator< T >::operator->() const
{
  return &( m_iterator->second );
}

template< typename T >
bool RangeMapConstIterator< T >::operator==( const RangeMapConstIterator< T >& n ) const
{
  return m_iterator == n.m_iterator;
}

template< typename T >
bool RangeMapConstIterator< T >::operator==( const RangeMapIterator< T >& n ) const
{
  return m_iterator == n.m_iterator;
}

template< typename T >
bool RangeMapConstIterator< T >::operator!=( const RangeMapConstIterator< T >& n ) const
{
  return m_iterator != n.m_iterator;
}

template< typename T >
bool RangeMapConstIterator< T >::operator!=( const RangeMapIterator< T >& n ) const
{
  return m_iterator != n.m_iterator;
}

template< typename T >
RangeMapConstIterator< T >& RangeMapConstIterator< T >::operator++()
{
  ++m_iterator;
  return *this;
}

template< typename T >
RangeMapConstIterator< T > RangeMapConstIterator< T >::operator++( int )
{
  RangeMapConstIterator toReturn( *this );
  ++( *this );
  return toReturn;
}

template< typename T >
RangeMapConstIterator< T >& RangeMapConstIterator< T >::operator--()
{
  --m_iterator;
  return *this;
}

template< typename T >
RangeMapConstIterator< T > RangeMapConstIterator< T >::operator--( int )
{
  RangeMapConstIterator toReturn( *this );
  --( *this );
  return toReturn;
}

template< typename T >
const unsigned long RangeMapConstIterator< T >::lower() const
{
  return m_iterator->first.m_lowerRange;
}

template< typename T >
const unsigned long RangeMapConstIterator< T >::upper() const
{
  return m_iterator->first.m_upperRange;
}

} // namespace SimpleRangeMap

#endif // RANGE_MAP_CONST_ITERATOR_HPP
