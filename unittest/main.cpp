#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../rangemap/rangemap.h"

namespace {

template< typename T, typename I >
void checkValue( T&                  rangeMap,
                 const unsigned long expectedValue,
                 const unsigned long index )
{
  I i = rangeMap.find( index );
  REQUIRE( i != rangeMap.end() );
  REQUIRE ( *i == expectedValue );
}

template< typename T, typename I >
void performTest()
{
  RangeMap<unsigned long> rangeMap;
  rangeMap.insert( 0,  5 ); // 0 -  4
  rangeMap.insert( 1, 10 ); // 5 - 14
  rangeMap.insert( 2,  3 ); // 15 - 17

  REQUIRE( rangeMap.size() == 3 );

  checkValue< T, I >( rangeMap, 0,  0 );
  checkValue< T, I >( rangeMap, 0,  1 );
  checkValue< T, I >( rangeMap, 0,  2 );
  checkValue< T, I >( rangeMap, 0,  3 );
  checkValue< T, I >( rangeMap, 0,  4 );
  checkValue< T, I >( rangeMap, 1,  5 );
  checkValue< T, I >( rangeMap, 1,  6 );
  checkValue< T, I >( rangeMap, 1,  7 );
  checkValue< T, I >( rangeMap, 1,  8 );
  checkValue< T, I >( rangeMap, 1,  9 );
  checkValue< T, I >( rangeMap, 1, 10 );
  checkValue< T, I >( rangeMap, 1, 11 );
  checkValue< T, I >( rangeMap, 1, 12 );
  checkValue< T, I >( rangeMap, 1, 13 );
  checkValue< T, I >( rangeMap, 1, 14 );
  checkValue< T, I >( rangeMap, 2, 15 );
  checkValue< T, I >( rangeMap, 2, 16 );
  checkValue< T, I >( rangeMap, 2, 17 );
  
  // Fail to find value test
  REQUIRE( rangeMap.find( 18 ) == rangeMap.end() );

  // Iterator test
  I i = rangeMap.begin();
  REQUIRE( i != rangeMap.end() );
  REQUIRE( *i == 0 );
  REQUIRE( i.lower() == 0 );
  REQUIRE( i.upper() == 4 );

  ++i;
  REQUIRE( *i == 1 );
  REQUIRE( i.lower() == 5 );
  REQUIRE( i.upper() == 14 );

  ++i;
  REQUIRE( *i == 2 );
  REQUIRE( i.lower() == 15 );
  REQUIRE( i.upper() == 17 );

  ++i;
  REQUIRE( i == rangeMap.end() );
}

} // namespace

TEST_CASE( "RangeMap" )
{
  performTest< RangeMap<unsigned long>, RangeMap<unsigned long>::iterator >();
}

TEST_CASE( "RangeMap with const interators" )
{
  performTest< RangeMap<unsigned long>, RangeMap<unsigned long>::const_iterator >();
}

TEST_CASE( "RangeMap with const iterators and const container" )
{
  performTest< const RangeMap<unsigned long >, RangeMap<unsigned long>::const_iterator >();
}
