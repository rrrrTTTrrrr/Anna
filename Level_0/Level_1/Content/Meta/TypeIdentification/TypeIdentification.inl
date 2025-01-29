//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename Type >
inline UnsignedInteger64bits TypeIdentification::Get()
{
    // This static object will store the identification number of the type. For each type that will use this object a copy of this method will 
    // be created, with the specific type, now to make sure each type has a different identification number, the counter is used. In each get 
    // method that gets created the static variable will be initialized on first call with the current value of the counter, and will increase 
    // by 1 after
    static UnsignedInteger64bits typeIdentification = member_numberOfTypes++;

    // Return the identification number for the type
    return ( typeIdentification );
}


inline UnsignedInteger64bits TypeIdentification::NumberOfTypes()
{
	// Return the number of types
	return ( member_numberOfTypes );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



}  //  Namespace Universe