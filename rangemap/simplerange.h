#ifndef agents_arachnidutils_rangemap_simplerange_h
#define agents_arachnidutils_rangemap_simplerange_h

namespace SimpleRangeMap {

class SimpleRange
{
public:
  inline SimpleRange( const unsigned long lowerRange, const unsigned long upperRange );

  unsigned long m_lowerRange;
  unsigned long m_upperRange;
};

inline bool operator< ( const SimpleRangeMap::SimpleRange&, const SimpleRangeMap::SimpleRange& );
inline bool operator> ( const SimpleRangeMap::SimpleRange&, const SimpleRangeMap::SimpleRange& );
inline bool operator==( const SimpleRangeMap::SimpleRange&, const SimpleRangeMap::SimpleRange& );

} // namespace SimpleRangeMap

#include "simplerange.hpp"

#endif // agents_arachnidutils_rangemap_simplerange_h
