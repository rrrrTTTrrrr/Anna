#ifndef ROOT_CPP
#define ROOT_CPP


#include "Root.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{



	// Forward declarations :
	//
	//  NONE
	//



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		void Root::Test()
		{
			// This pair will store the result
			Tuple< Boolean COMMA SignedInteger32bits > rootResult;

			// Try some number combination
			rootResult = Calculate< SignedInteger32bits >( 16, 2 );
			Assert_Test( rootResult.template Entry< 0 >() == true );
			Assert_Test( rootResult.template Entry< 1 >() == 4 );

			// Try some number combination
			rootResult = Calculate< SignedInteger32bits >( 15, 2 );
			Assert_Test( rootResult.template Entry< 0 >() == false );

			// Try some number combination
			rootResult = Calculate< SignedInteger32bits >( 165, 3 );
			Assert_Test( rootResult.template Entry< 0 >() == false );

			// Try some number combination
			rootResult = Calculate< SignedInteger32bits >( 512, 3 );
			Assert_Test( rootResult.template Entry< 0 >() == true );
			Assert_Test( rootResult.template Entry< 1 >() == 8 );

			// Try some number combination
			rootResult = Calculate< SignedInteger32bits >( 49, 2 );
			Assert_Test( rootResult.template Entry< 0 >() == true );
			Assert_Test( rootResult.template Entry< 1 >() == 7 );

			// Try some number combination
			Assert_Test( ( Calculate< FloatingPoint >( 2.25, 2, 0.01 ) - 1.5 ) < 0.00001 );
			Assert_Test( ( Calculate< FloatingPoint >( 19.7056, 2, 0.00001 ) - 4.43909 ) < 0.00001 );
		}

	)  //  End of debug tool
	


}  //  Namespace Universe


#endif  //  ROOT_CPP





