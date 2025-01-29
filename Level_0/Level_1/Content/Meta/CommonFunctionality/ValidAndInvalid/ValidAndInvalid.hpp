namespace Universe
{



	// The content of this file is 2 type definitions, with different size. One of the ways to check requirements on types, is by creating a set of overloaded
	// functions, where one will check some requirement on the type, and the other is the fallback in case the requirement is not valid on the current
	// type. In this set of functions to know which verison was choosen, the function that checks the requirement on the type will return the 'Valid'
	// type, and the other will return the 'Invalid' type. This way the type can be compared, or the size of it can be taken, to know which version was
	// choosen, and as a result know if the type is satisfy the requirement or not
	//
	using Valid = UnsignedInteger8bits;
	using Invalid = UnsignedInteger64bits;



}  //  Namespace Universe