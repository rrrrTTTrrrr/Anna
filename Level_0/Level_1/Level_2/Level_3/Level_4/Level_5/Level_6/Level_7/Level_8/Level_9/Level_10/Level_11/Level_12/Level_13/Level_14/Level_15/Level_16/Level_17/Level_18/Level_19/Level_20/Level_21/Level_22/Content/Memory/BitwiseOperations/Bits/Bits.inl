//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::Integer IntegerType >
inline IntegerType Bits::GetIntegerWithAllMostSignificantBitsOnFromIndexAndAbove( const UnsignedInteger64bits bitIndex )
{        
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( bitIndex, ( sizeof( IntegerType ) * 8UL ) );

    // A lookup table for unsigned integers with size of 1 byte, all the bits will be set on above and including index
    static constexpr UnsignedInteger8bits oneByte_bitsOnAboveAndIncludingIndex[8] = {255U,254U,252U,248U,240U,224U,192U,128U};

    // A lookup table for unsigned integers with size of 2 bytes all the bits will be set on above and including index
    static constexpr UnsignedInteger16bits twoBytes_bitsOnAboveAndIncludingIndex[16] = {65535U,65534U,65532U,65528U,65520U,65504U,65472U,65408U,65280U,65024U,64512U,63488U,61440U,57344U,49152U,32768U};

    // A lookup table for unsigned integers with size of 4 bytes, all the bits will be set on above and including index
    static constexpr UnsignedInteger32bits fourBytes_bitsOnAboveAndIncludingIndex[32] = {4294967295U,4294967294U,4294967292U,4294967288U,4294967280U,4294967264U,4294967232U,4294967168U,4294967040U,4294966784U,4294966272U,4294965248U,4294963200U,4294959104U,4294950912U,4294934528U,4294901760U,4294836224U,4294705152U,4294443008U,4293918720U,4292870144U,4290772992U,4286578688U,4278190080U,4261412864U,4227858432U,4160749568U,4026531840U,3758096384U,3221225472U,2147483648U};

    // A lookup table for unsigned integers with size of 8 bytes, all the bits will be set on above and including index
    static constexpr UnsignedInteger64bits eightBytes_bitsOnAboveAndIncludingIndex[64] = {18446744073709551615UL,18446744073709551614UL,18446744073709551612UL,18446744073709551608UL,18446744073709551600UL,18446744073709551584UL,18446744073709551552UL,18446744073709551488UL,18446744073709551360UL,18446744073709551104UL,18446744073709550592UL,18446744073709549568UL,18446744073709547520UL,18446744073709543424UL,18446744073709535232UL,18446744073709518848UL,18446744073709486080UL,18446744073709420544UL,18446744073709289472UL,18446744073709027328UL,18446744073708503040UL,18446744073707454464UL,18446744073705357312UL,18446744073701163008UL,18446744073692774400UL,18446744073675997184UL,18446744073642442752UL,18446744073575333888UL,18446744073441116160UL,18446744073172680704UL,18446744072635809792UL,18446744071562067968UL,18446744069414584320UL,18446744065119617024UL,18446744056529682432UL,18446744039349813248UL,18446744004990074880UL,18446743936270598144UL,18446743798831644672UL,18446743523953737728UL,18446742974197923840UL,18446741874686296064UL,18446739675663040512UL,18446735277616529408UL,18446726481523507200UL,18446708889337462784UL,18446673704965373952UL,18446603336221196288UL,18446462598732840960UL,18446181123756130304UL,18445618173802708992UL,18444492273895866368UL,18442240474082181120UL,18437736874454810624UL,18428729675200069632UL,18410715276690587648UL,18374686479671623680UL,18302628885633695744UL,18158513697557839872UL,17870283321406128128UL,17293822569102704640UL,16140901064495857664UL,13835058055282163712UL,9223372036854775808UL};

    // As can be seen the lookup tables are only for unsigned integers. The reason this is valid is because most systems use two's complement
    // form, which gurantees that the bit pattern will not change when casting between unsigned integer and signed integer

    // Pick the operation to perform according to the integer type size in bytes, return the value inside the required entry in the lookup table
    if constexpr ( sizeof( IntegerType ) == 1 )
    {
        return ( oneByte_bitsOnAboveAndIncludingIndex[ bitIndex ] );        
    }
    else if constexpr ( sizeof( IntegerType ) == 2 )
    {
        return ( twoBytes_bitsOnAboveAndIncludingIndex[ bitIndex ] );
    }
    else if constexpr ( sizeof( IntegerType ) == 4 )
    {
        return ( fourBytes_bitsOnAboveAndIncludingIndex[ bitIndex ] );
    }
    else
    {
        return ( eightBytes_bitsOnAboveAndIncludingIndex[ bitIndex ] );
    }
}


template< Concepts::Integer IntegerType >
inline IntegerType Bits::GetIntegerWithAllMostSignificantBitsOnAboveIndex( const UnsignedInteger64bits bitIndex )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( bitIndex, ( sizeof( IntegerType ) * 8UL ) );
    
    // A lookup table for unsigned integers with size of 1 byte, all the bits will be set on above index
    static constexpr UnsignedInteger8bits oneByte_bitsOnAboveIndex[8] = {254U,252U,228U,240U,224U,192U,128U,0U};

    // A lookup table for unsigned integers with size of 2 bytes, all the bits will be set on above index
    static constexpr UnsignedInteger16bits twoBytes_bitsOnAboveIndex[16] = {65534U,65532U,65528U,65520U,65504U,65472U,65408U,65280U,65024U,64512U,63488U,61440U,57344U,49152U,32768U,0U};

    // A lookup table for unsigned integers with size of 4 bytes, all the bits will be set on above index
    static constexpr UnsignedInteger32bits fourBytes_bitsOnAboveIndex[32] = {4294967294U,4294967292U,4294967288U,4294967280U,4294967264U,4294967232U,4294967168U,4294967040U,4294966784U,4294966272U,4294965248U,4294963200U,4294959104U,4294950912U,4294934528U,4294901760U,4294836224U,4294705152U,4294443008U,4293918720U,4292870144U,4290772992U,4286578688U,4278190080U,4261412864U,4227858432U,4160749568U,4026531840U,3758096384U,3221225472U,2147483648U,0U};

    // A lookup table for unsigned integers with size of 8 bytes, all the bits will be set on above index
    static constexpr UnsignedInteger64bits eightBytes_bitsOnAboveIndex[64] = {18446744073709551614UL,18446744073709551612UL,18446744073709551608UL,18446744073709551600UL,18446744073709551584UL,18446744073709551552UL,18446744073709551488UL,18446744073709551360UL,18446744073709551104UL,18446744073709550592UL,18446744073709549568UL,18446744073709547520UL,18446744073709543424UL,18446744073709535232UL,18446744073709518848UL,18446744073709486080UL,18446744073709420544UL,18446744073709289472UL,18446744073709027328UL,18446744073708503040UL,18446744073707454464UL,18446744073705357312UL,18446744073701163008UL,18446744073692774400UL,18446744073675997184UL,18446744073642442752UL,18446744073575333888UL,18446744073441116160UL,18446744073172680704UL,18446744072635809792UL,18446744071562067968UL,18446744069414584320UL,18446744065119617024UL,18446744056529682432UL,18446744039349813248UL,18446744004990074880UL,18446743936270598144UL,18446743798831644672UL,18446743523953737728UL,18446742974197923840UL,18446741874686296064UL,18446739675663040512UL,18446735277616529408UL,18446726481523507200UL,18446708889337462784UL,18446673704965373952UL,18446603336221196288UL,18446462598732840960UL,18446181123756130304UL,18445618173802708992UL,18444492273895866368UL,18442240474082181120UL,18437736874454810624UL,18428729675200069632UL,18410715276690587648UL,18374686479671623680UL,18302628885633695744UL,18158513697557839872UL,17870283321406128128UL,17293822569102704640UL,16140901064495857664UL,13835058055282163712UL,9223372036854775808UL,0UL};

    // As can be seen the lookup tables are only for unsigned integers. The reason this is valid is because most systems use two's complement
    // form, which gurantees that the bit pattern will not change when casting between unsigned integer and signed integer

    // Pick the operation to perform according to the integer type size in bytes, return the value inside the required entry in the lookup table
    if constexpr ( sizeof( IntegerType ) == 1 )
    {
        return ( oneByte_bitsOnAboveIndex[ bitIndex ] );
    }
    else if constexpr ( sizeof( IntegerType ) == 2 )
    {
        return ( twoBytes_bitsOnAboveIndex[ bitIndex ] );
    }
    else if constexpr ( sizeof( IntegerType ) == 4 )
    {
        return ( fourBytes_bitsOnAboveIndex[ bitIndex ] );
    }
    else
    {
        return ( eightBytes_bitsOnAboveIndex[ bitIndex ] );
    }
}


template< Concepts::Integer IntegerType >
inline IntegerType Bits::GetIntegerWithAllMostSignificantBitsOffFromIndexAndAbove( const UnsignedInteger64bits bitIndex )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( bitIndex, ( sizeof( IntegerType ) * 8UL ) );

    // A lookup table for unsigned integers with size of 1 byte, all the bits will be set off above and including index
    static constexpr UnsignedInteger8bits oneByte_bitsOffAboveAndIncludingIndex[8] = {0U,1U,3U,7U,15U,31U,63U,127U};

    // A lookup table for unsigned integers with size of 2 bytes all the bits will be set off above and including index
    static constexpr UnsignedInteger16bits twoBytes_bitsOffAboveAndIncludingIndex[16] = {0U,1U,3U,7U,15U,31U,63U,127U,255U,511U,1023U,2047U,4095U,8191U,16383U,32767U};

    // A lookup table for unsigned integers with size of 4 bytes, all the bits will be set off above and including index
    static constexpr UnsignedInteger32bits fourBytes_bitsOffAboveAndIncludingIndex[32] = {0U,1U,3U,7U,15U,31U,63U,127U,255U,511U,1023U,2047U,4095U,8191U,16383U,32767U,65535U,131071U,262143U,524287U,1048575U,2097151U,4194303U,8388607U,16777215U,33554431U,67108863U,134217727U,268435455U,536870911U,1073741823U,2147483647U};

    // A lookup table for unsigned integers with size of 8 bytes, all the bits will be set off above and including index
    static constexpr UnsignedInteger64bits eightBytes_bitsOffAboveAndIncludingIndex[64] = {0UL,1UL,3UL,7UL,15UL,31UL,63UL,127UL,255UL,511UL,1023UL,2047UL,4095UL,8191UL,16383UL,32767UL,65535UL,131071UL,262143UL,524287UL,1048575UL,2097151UL,4194303UL,8388607UL,16777215UL,33554431UL,67108863UL,134217727UL,268435455UL,536870911UL,1073741823UL,2147483647UL,4294967295UL,8589934591UL,17179869183UL,34359738367UL,68719476735UL,137438953471UL,274877906943UL,549755813887UL,1099511627775UL,2199023255551UL,4398046511103UL,8796093022207UL,17592186044415UL,35184372088831UL,70368744177663UL,140737488355327UL,281474976710655UL,562949953421311UL,1125899906842623UL,2251799813685247UL,4503599627370495UL,9007199254740991UL,18014398509481983UL,36028797018963967UL,72057594037927935UL,144115188075855871UL,288230376151711743UL,576460752303423487UL,1152921504606846975UL,2305843009213693951UL,4611686018427387903UL,9223372036854775807UL};

    // As can be seen the lookup tables are only for unsigned integers. The reason this is valid is because most systems use two's complement
    // form, which gurantees that the bit pattern will not change when casting between unsigned integer and signed integer

    // Pick the operation to perform according to the integer type size in bytes, return the value inside the required entry in the lookup table
    if constexpr ( sizeof( IntegerType ) == 1 )
    {
        return ( oneByte_bitsOffAboveAndIncludingIndex[ bitIndex ] );
    }
    else if constexpr ( sizeof( IntegerType ) == 2 )
    {
        return ( twoBytes_bitsOffAboveAndIncludingIndex[ bitIndex ] );
    }
    else if constexpr ( sizeof( IntegerType ) == 4 )
    {
        return ( fourBytes_bitsOffAboveAndIncludingIndex[ bitIndex ] );
    }
    else
    {
        return ( eightBytes_bitsOffAboveAndIncludingIndex[ bitIndex ] );
    }
}


template< Concepts::Integer IntegerType >
inline IntegerType Bits::GetIntegerWithAllMostSignificantBitsOffAboveIndex( const UnsignedInteger64bits bitIndex )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
    AssertValueIsBelowCertainLimit( bitIndex, ( sizeof( IntegerType ) * 8UL ) );

    // A lookup table for unsigned integers with size of 1 byte, all the bits will be set off above index
    static constexpr UnsignedInteger8bits oneByte_bitsOffAboveIndex[8] = {1U,3U,7U,15U,31U,63U,127U,0U};

    // A lookup table for unsigned integers with size of 2 bytes all the bits will be set off above index
    static constexpr UnsignedInteger16bits twoBytes_bitsOffAboveIndex[16] = {1U,3U,7U,15U,31U,63U,127U,255U,511U,1023U,2047U,4095U,8191U,16383U,32767U,65535U};

    // A lookup table for unsigned integers with size of 4 bytes, all the bits will be set off above index
    static constexpr UnsignedInteger32bits fourBytes_bitsOffAboveIndex[32] = {1U,3U,7U,15U,31U,63U,127U,255U,511U,1023U,2047U,4095U,8191U,16383U,32767U,65535U,131071U,262143U,524287U,1048575U,2097151U,4194303U,8388607U,16777215U,33554431U,67108863U,134217727U,268435455U,536870911U,1073741823U,2147483647U,4294967295U};

    // A lookup table for unsigned integers with size of 8 bytes, all the bits will be set off above index
    static constexpr UnsignedInteger64bits eightBytes_bitsOffAboveIndex[64] = {1UL,3UL,7UL,15UL,31UL,63UL,127UL,255UL,511UL,1023UL,2047UL,4095UL,8191UL,16383UL,32767UL,65535UL,131071UL,262143UL,524287UL,1048575UL,2097151UL,4194303UL,8388607UL,16777215UL,33554431UL,67108863UL,134217727UL,268435455UL,536870911UL,1073741823UL,2147483647UL,4294967295UL,8589934591UL,17179869183UL,34359738367UL,68719476735UL,137438953471UL,274877906943UL,549755813887UL,1099511627775UL,2199023255551UL,4398046511103UL,8796093022207UL,17592186044415UL,35184372088831UL,70368744177663UL,140737488355327UL,281474976710655UL,562949953421311UL,1125899906842623UL,2251799813685247UL,4503599627370495UL,9007199254740991UL,18014398509481983UL,36028797018963967UL,72057594037927935UL,144115188075855871UL,288230376151711743UL,576460752303423487UL,1152921504606846975UL,2305843009213693951UL,4611686018427387903UL,9223372036854775807UL,18446744073709551615UL};

    // As can be seen the lookup tables are only for unsigned integers. The reason this is valid is because most systems use two's complement
    // form, which gurantees that the bit pattern will not change when casting between unsigned integer and signed integer

    // Pick the operation to perform according to the integer type size in bytes, return the value inside the required entry in the lookup table
    if constexpr ( sizeof( IntegerType ) == 1 )
    {
        return ( oneByte_bitsOffAboveIndex[ bitIndex ] );
    }
    else if constexpr ( sizeof( IntegerType ) == 2 )
    {
        return ( twoBytes_bitsOffAboveIndex[ bitIndex ] );
    }
    else if constexpr ( sizeof( IntegerType ) == 4 )
    {
        return ( fourBytes_bitsOffAboveIndex[ bitIndex ] );
    }
    else
    {
        return ( eightBytes_bitsOffAboveIndex[ bitIndex ] );
    }
}



}  //  Namespace Memory


}  //  Namespace Universe