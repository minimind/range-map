#ifndef agents_arachnidutils_rangemap_rangemap_h
#define agents_arachnidutils_rangemap_rangemap_h

#include <map>
#include "simplerange.h"
#include "rangemapiterator.h"
#include "rangemapconstiterator.h"

template< typename T >
class RangeMap
{
public:
  typedef SimpleRangeMap::RangeMapIterator<T>      iterator;
  typedef SimpleRangeMap::RangeMapConstIterator<T> const_iterator;

  RangeMap();

  void           clear();
  iterator       begin();
  const_iterator begin()               const;
  iterator       end();
  const_iterator end()                 const;
  size_t         size()                const;
  unsigned long  nextRangeNo()         const;
  bool           empty()               const;
  const_iterator find( unsigned long ) const;
  iterator       find( unsigned long );
  void           insert( const T&, unsigned long );

private:
  std::map< SimpleRangeMap::SimpleRange, T > m_map;
  unsigned long                              m_nextRangeNo;
};

#include "rangemap.hpp"
#include "simplerange.hpp"
#include "rangemapiterator.hpp"
#include "rangemapconstiterator.hpp"

#endif // agents_arachnidutils_rangemap_rangemap_h
