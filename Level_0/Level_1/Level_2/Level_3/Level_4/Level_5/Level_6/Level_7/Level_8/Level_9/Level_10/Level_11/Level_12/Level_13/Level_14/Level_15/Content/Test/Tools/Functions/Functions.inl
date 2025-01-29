//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline UnsignedInteger32bits Functions::Function_1( UnsignedInteger32bits rr, UnsignedInteger64bits )
{
	rr += 1;
	return ( 9 );
}


inline UnsignedInteger32bits Functions::Function_2( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits )
{
	return ( 99 );
}


inline void Functions::Function_3()
{}


inline UnsignedInteger32bits Functions::Function_4()
{
	return ( 999 );
}


inline void Functions::Function_5( UnsignedInteger32bits, UnsignedInteger64bits )
{}


inline void Functions::Function_6( UnsignedInteger32bits* pointer_1, UnsignedInteger64bits* pointer_2 )
{
	if ( pointer_1 != nullptr )
	{
		*pointer_1 = 888333;
	}

	if ( pointer_2 != nullptr )
	{
		*pointer_2 = 7777;
	}
}


inline void Functions::Function_7( UnsignedInteger64bits* array, UnsignedInteger64bits arraySize )
{
    
    for ( UnsignedInteger64bits index = 0 ; index < arraySize ; ++ index )
    {
        array[ index ] = index;
    }

}



}  //  Namespace Test


}  //  Namespace Universe