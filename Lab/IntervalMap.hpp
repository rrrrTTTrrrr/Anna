#include <map>
#include <limits>

class uu
{
public:
    uu( int ii ) : m(ii) {}

    bool operator< ( uu other ) { return ( m < other.m ); }
    bool operator< ( uu other ) const { return ( m < other.m ); }

    int m;
};

class uuuu
{
public:
    uuuu( int ii ) : m(ii) {}

    bool operator== ( uuuu other ) const { return ( m < other.m ); }

    int m;
};

template< typename K, typename V >
class interval_map {

public:

    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val ) 
    {
        m_map.insert( m_map.end(), std::make_pair( std::numeric_limits< K >::lowest(), val ) );
    }

    // Assign value val to interval [keyBegin, keyEnd).
    // Overwrite previous values in this interval.
    // Conforming to the C++ Standard Library conventions, the interval
    // includes keyBegin, but excludes keyEnd.
    // If !( keyBegin < keyEnd ), this designates an empty interval,
    // and assign must do nothing.
    void assign( K const& keyBegin, K const& keyEnd, V const& val ) 
    {

        // Check that the arguments are valid
        if ( !( keyBegin < keyEnd ) )
        {
            return;
        }

        // This temporary will be used to store a value when it should be moved between entries
        V temporaryValue_1;
        V temporaryValue_2;

        // Check if the key beginning is larger or equal then the highest current key
        if ( ( ( --m_map.end() )->first < keyBegin ) || !( keyBegin < ( ( --m_map.end() )->first ) ) )
        {
            if ( ( --m_map.end() )->second == val )
            {
                return;
            }

            temporaryValue_1 = ( --m_map.end() )->second;

            m_map[ keyBegin ] = val;
            m_map[ keyEnd ] = temporaryValue_1;

            return;
        }

        // Check if the beginning of the range is the lowest possible value or smaller or equal then the smallest key in the map
        if ( !( std::numeric_limits< K >::lowest() < keyBegin ) || ( keyBegin < ( ++m_map.begin() )->first ) || !( ( ( ++m_map.begin() )->first ) < keyBegin ) )
        {
            // Check if the end of the range is larger or equal to the largest key currently in the map
            if ( ( ( ( --m_map.end() )->first ) < keyEnd ) || !( keyEnd < ( ( --m_map.end() )->first ) ) )
            {
                // Store the values at the beginning and end
                temporaryValue_1 = m_map.begin()->second;
                temporaryValue_2 = ( --m_map.end() )->second;

                // Clear the map from all the entries
                m_map.clear();

                m_map[ std::numeric_limits< K >::lowest() ] = temporaryValue_1;

                // Check if all the values are the same, then only one key and value pair needs to be insert
                if ( ( val == temporaryValue_1 ) && ( val == temporaryValue_2 ) )
                {
                    return;
                }

                m_map[ keyBegin ] = val;

                if ( val == temporaryValue_2 )
                {
                    return;
                }

                m_map[ keyEnd ] = temporaryValue_2;

                return;
            }

        }

        // Declare iterators to help pass on the map
        typename std::map< K, V >::iterator it_begin = m_map.end();
        typename std::map< K, V >::iterator it_end = m_map.end();

        typename std::map< K, V >::iterator iterator_aidToPassOnMap_1 = m_map.begin();
        typename std::map< K, V >::iterator iterator_aidToPassOnMap_2 = m_map.begin();

        // Loop to find the entry that contains a key larger then the current begin
        while ( iterator_aidToPassOnMap_2 != m_map.end() ) 
        {
            if ( keyBegin < iterator_aidToPassOnMap_2->first )
            {
                it_begin = iterator_aidToPassOnMap_1;
                break;
            }

            iterator_aidToPassOnMap_1 = iterator_aidToPassOnMap_2;
            ++iterator_aidToPassOnMap_2;
        }

        // Keep looping to find the entry that contains a key larger then the current end
        while ( iterator_aidToPassOnMap_2 != m_map.end() ) 
        {
            if ( ( keyEnd < iterator_aidToPassOnMap_2->first ) || !( iterator_aidToPassOnMap_2->first < keyEnd ) )
            {
                it_end = iterator_aidToPassOnMap_1;
                break;
            }

            iterator_aidToPassOnMap_1 = iterator_aidToPassOnMap_2;
            ++iterator_aidToPassOnMap_2;
        }

        // Check if both iterators point to the same location, which means the entire range needs to be added inside
        // another range
        if ( it_begin == it_end )
        {
            // Check if the value of the current range match the one needs to be added
            if ( it_begin->second == val )
            {
                return;
            }

            // Check if the key end is equal to the key in the next iterator
            if ( keyEnd < ( ++it_end )->first )
            {
                m_map[ keyEnd ] = it_begin->second;                
            }

            m_map[ keyBegin ] = val;

            return;
        }

        // Store the value in case the end iterator point to the end of the map which means it will delete also the last
        // entry, and the value inside it is needed
        if ( it_end != m_map.end() )
        {
            temporaryValue_1 = it_end->second;
        }
        else
        {
            temporaryValue_1 = ( --it_end )->second;            
        }

        iterator_aidToPassOnMap_1 = it_begin;
        iterator_aidToPassOnMap_2 = ++iterator_aidToPassOnMap_1;

        // Delete all the entries between the keys
        while ( iterator_aidToPassOnMap_2 != it_end )
        {
            ++iterator_aidToPassOnMap_1;
            m_map.erase( iterator_aidToPassOnMap_2 );
            iterator_aidToPassOnMap_2 = iterator_aidToPassOnMap_1;
        }
       
        m_map[ keyBegin ] = val;

        // Check if the end iterator points to the end of the map
        if ( ( it_end == m_map.end() )  )
        {
            m_map[ keyEnd ] = temporaryValue_1;

            return;
        }

        // Check if the end key is larger then the key at the end iterator
        if ( it_end->first < keyEnd )
        {
            m_map.erase( it_end );

            if ( !( val == temporaryValue_1 ) )
            {
                m_map[ keyEnd ] = temporaryValue_1;
            }
        }

    }

    // look-up of the value associated with key
    V const& operator[]( K const& key ) const 
    {
        return ( --m_map.upper_bound(key) )->second;
    }


    std::map< K, V > m_map;

};

// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of unsigned int intervals to char.





        // The possibilites are : 
        //
        //  1. The given range falls entirely within another range, then the surrounding range should appear on both sides :
        //
        //                                            a
        //      current state           |--------------------------|
        //  
        //                                           b
        //      range to assign                 |---------|
        //
        //                                  a        b         a
        //      result                  |-------|---------|--------|
        //
        //    
        //                                      a               b
        //      current state           |--------------------|-----|
        //  
        //                                           c
        //      range to assign                 |---------|
        //
        //                                  a        c     a    b
        //      result                  |-------|---------|--|-----|
        //
        //
        //  2. The given range falls entirely within another range, but the temporaryValue_1 is the same, nothing needs to be done
        //
        //  3. The given range falls betwen two other ranges :
        //
        //
        //                                      a               b
        //      current state           |-------------|------------|
        //  
        //                                           c
        //      range to assign                 |---------|
        //
        //                                  a        c         b
        //      result                  |-------|---------|--------|
        //
        //
        //  4. The given range range falls between two other ranges, but the value is the same as the left range :
        //
        //
        //                                      a               b
        //      current state           |-------------|------------|
        //  
        //                                           a
        //      range to assign                 |---------|
        //
        //                                        a            b
        //      result                  |-----------------|--------|
        //
        //
        //  5. The given range range falls between two other ranges, but the value is the same as the right range :
        //
        //
        //                                      a               b
        //      current state           |-------------|------------|
        //  
        //                                           b
        //      range to assign                 |---------|
        //
        //                                  a            b
        //      result                  |-------|------------------|
        //
        //
        //  6. The given range falls between two other ranges, but covers another range entirely :
        //
        //        
        //                                  a         b        c
        //      current state           |-------|----------|-------|
        //  
        //                                           d
        //      range to assign               |--------------|
        //
        //                                 a          d         c 
        //      result                  |-----|--------------|-----|
        //
        //
        //  7. The entire possible range is provided, this means that only the value assigned to the maximum value of the range should
        //     stay all the other range is assigned to the new value