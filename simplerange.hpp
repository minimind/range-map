#ifndef SIMPLE_RANGE_HPP
#define SIMPLE_RANGE_HPP

namespace SimpleRangeMap {

inline SimpleRange::SimpleRange( const unsigned long lowerRange, const unsigned long upperRange )
  : m_lowerRange( lowerRange )
  , m_upperRange( upperRange )
{
}

inline bool operator<( const SimpleRangeMap::SimpleRange& a, const SimpleRangeMap::SimpleRange& b )
{
  return a.m_upperRange < b.m_lowerRange;
}

inline bool operator>( const SimpleRangeMap::SimpleRange& a, const SimpleRangeMap::SimpleRange& b )
{
  return a.m_lowerRange < b.m_upperRange;
}

inline bool operator==( const SimpleRangeMap::SimpleRange& a, const SimpleRangeMap::SimpleRange& b )
{
  return a.m_lowerRange >= b.m_lowerRange && a.m_upperRange <= b.m_upperRange;
}

} // namespace SimpleRangeMap

#endif // SIMPLE_RANGE_HPP
