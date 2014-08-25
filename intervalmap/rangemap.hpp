#ifndef RANGE_MAP_HPP
#define RANGE_MAP_HPP

#include "rangemap.h"

template< typename T >
RangeMap< T >::RangeMap()
  : m_nextRangeNo( 0 )
{
}

template< typename T >
void RangeMap< T >::clear()
{
  m_map.clear();
}

template< typename T >
SimpleRangeMap::RangeMapIterator<T> RangeMap< T >::begin()
{
  return SimpleRangeMap::RangeMapIterator<T>( m_map.begin() );
}

template< typename T >
SimpleRangeMap::RangeMapConstIterator<T> RangeMap< T >::begin() const
{
  return SimpleRangeMap::RangeMapConstIterator<T>( m_map.begin() );
}

template< typename T >
SimpleRangeMap::RangeMapIterator<T> RangeMap< T >::end()
{
  return SimpleRangeMap::RangeMapIterator<T>( m_map.end() );
}

template< typename T >
SimpleRangeMap::RangeMapConstIterator<T> RangeMap< T >::end() const
{
  return SimpleRangeMap::RangeMapConstIterator<T>( m_map.end() );
}

template< typename T >
size_t RangeMap< T >::size() const
{
  return m_map.size();
}

template< typename T >
unsigned long RangeMap< T >::nextRangeNo() const
{
  return m_nextRangeNo;
}

template< typename T >
bool RangeMap< T >::empty() const
{
  return m_map.empty();
}

template< typename T >
SimpleRangeMap::RangeMapIterator<T> RangeMap< T >::find( const unsigned long indexNo )
{
  return SimpleRangeMap::RangeMapIterator<T>( m_map.find( SimpleRangeMap::SimpleRange( indexNo, indexNo ) ) );
}

template< typename T >
SimpleRangeMap::RangeMapConstIterator<T> RangeMap< T >::find( const unsigned long indexNo ) const
{
  return SimpleRangeMap::RangeMapConstIterator<T>( m_map.find( SimpleRangeMap::SimpleRange( indexNo, indexNo ) ) );
}

template< typename T >
void RangeMap< T >::insert( const T& object, unsigned long sizeOfRange )
{
  if ( sizeOfRange > 0 )
  {
    m_map.insert( std::make_pair( SimpleRangeMap::SimpleRange( m_nextRangeNo, m_nextRangeNo + sizeOfRange - 1 ), object ) );
    m_nextRangeNo += sizeOfRange;
  }
}

#endif // RANGE_MAP_HPP
