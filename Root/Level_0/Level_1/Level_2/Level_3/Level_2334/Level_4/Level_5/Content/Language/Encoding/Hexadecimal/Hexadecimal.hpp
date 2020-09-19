#ifndef  HEXADECIMAL_H
#define  HEXADECIMAL_H


#include <new>  //  Class std::bad_alloc


#include "../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef SignedInteger8bits, Typedef UnsignedInteger16bits
#include "../../BasicUtilities/cpp_BasicUtilities.hpp"  //  Function ThrowExceptionIfExpressionIsTrue, Function LittleOrBigEndian
#include "../../Memory/BitsAndBytes/BitsAndBytes.hpp"  //  Class BitsAndBytes
#include "../../Encoding/Ascii/AsciiString/AsciiString.hpp"  //  Static member function Length, Static member function SetLettersOfToUppercase


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#include <iostream>  //  Class std::cout, Class std::endl
#endif


// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part

 

namespace Universe
{

    namespace Encoding
    {


        // This is used when only declaring the object in this source file will be enough to
        // pass compilation. The implementation is given to the compiler through the cpp source
        // file that the object is nested within
        //
        // Forward declarations :
        //
        //  NONE
        //


        // Give proper treatment, by dealing with big and little endian encoding systems
        // where it is required. The big or little endian encoding appear when dealing
        // with byte order in memory


        // To support move semantics every class must provide a default state. This state
        // will be used to notify that the current instance resources was taken by a move
        // operation :
        //
        //  m_hexadecimal the shared pointer object is set to default state
        //  m_trueForDecimalValueCanBeUsedAndFalseOtherwise = false
        //
        // When this state is indicated the object should not be used as it is ( the object is empty )


        // Constructor of derived object, when called, all the base class constructors are executed first, according to
        // the order they appear in the class declaration, and only then the user code is executed

        // Destructor of derived object, when it is called, the user code existing in the destructor itself is executed first and then all the destructors
        // of the base objects, in an opposite way from which they were constructed


        // Hexadecimal - In mathematics and computing, hexadecimal ( also base 16, or hex ) is a positional numeral system with a radix, or base, of 16. It 
        // uses sixteen distinct symbols, most often the symbols 0 – 9 to represent values zero to nine, and A, B, C, D, E, F ( or alternatively a, b, c, d, e, f ) 
        // to represent values ten to fifteen. Hexadecimal numerals are widely used by computer system designers and programmers. As each hexadecimal digit represents
        // four binary digits ( bits ), it allows a more human-friendly representation of binary-coded values. One hexadecimal digit represents a nibble ( 4 bits ), 
        // which is half of an octet or byte ( 8 bits )


        // Template class Information :
        //
        //  Purpose :
        //
        //      Convert between hexadecimal values and hexadecimal representation as a string
        //
        //  Description :
        //
        //      There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
        //      can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
        //      no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
        //      not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
        //      program to end
        //
        //  Possible errors :
        //
        //
        //
        template< typename TYPE >
        class Hexadecimal 
        { 
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy
            // and move the object. This methods if not declared the compiler generates a basic behavior
            // for them :


            // Method Information :
            //
            //  Description :
            //
            //      Default Constructor, used to support move semantics
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            explicit inline Hexadecimal();


            // Method Information :
            //
            //  Description :
            //
            //      Constructor,
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          decimalValue - the decimal value that should be represented as hexadecimal
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Hexadecimal( TYPE decimalValue );


            // Method Information :
            //
            //  Description :
            //
            //      Constructor,
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. hexadecimal - the hexadecimal representation 
            //          2. trueForLittleEndianAndFalseForBigEndian - the encoding on which the hexadecimal representation was created        
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            Hexadecimal( const AsciiString& hexadecimal, bool trueForLittleEndianAndFalseForBigEndian );


            // Method Information :
            //
            //  Description :
            //
            //      Copy constructor, will operate correctly even if the other object is in default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the object that should be copied
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to the new copy is returned
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Hexadecimal( const Hexadecimal< TYPE >& other );


            // Method Information :
            //
            //  Description :
            //
            //      Assignment operator, handle with self assignment correctly. Will operate correctly even if the other object is in default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the object that should be copied
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //
            Hexadecimal< TYPE >& operator=( const Hexadecimal< TYPE >& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move constructor, takes the resources from the instance given in the rvalue reference, and set it to the default state.
            //      Will operate correctly even if the other object is in default state. Important note - if the current object has a pointer
            //      memebers, they must be set manually to 0 before using the method set to default state, or else the resources will be deleted
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the object that should be moved
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Hexadecimal( Hexadecimal< TYPE >&& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move Assignment operator, handle self assignment correctly. take the resources from the
            //      instance given in the rvalue reference, and set it to the default state.
            //      will operate correctly even if the other object is in default state. Important note - if the current object
            //      has a pointer memebers, they must be set manually to 0 before using the method set to default state, or else
            //      the resources will be deleted
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the object that should be moved
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //
            Hexadecimal< TYPE >& operator=( Hexadecimal< TYPE >&& other );


            // Method Information :
            //
            //  Description :
            //
            //      Destructor,
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ~Hexadecimal() throw();


            // To support Move semantics, the following 3 methods are added to every object. One method to set
            // the object into the default state, another to check if the object is in the default state,
            // and the last method to delete all the object resources :


            // Method Information :
            //
            //  Description :
            //
            //      Use to set the object into his default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline void SetToDefaultState();


            // Method Information :
            //
            //  Description :
            //
            //      Use to check if the object is in default state, it will return true if it does, and false otherwise
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true, if instance is at default state
            //      2. false, if instance is not at default state
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline bool DefaultState() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to delete the object resources and set the object to default state. The resource will only be 
            //      deleted if the reference count is 1, which means only current instance uses the resource. If the 
            //      current instance is at default state the method will do nothing
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. Deleting the object resources failed
            //      2.
            //
            inline void DeleteResourcesAndSetToDefaultState();


            // The following methods are the interface of the object. This methods implement the
            // capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use to set a new decimal value    
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          newDecimalValue - the new decimal value that should be represented as hexadecimal
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The decimal value
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. 
            //
            TYPE SetNewDecimalValue( TYPE newDecimalValue );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the decimal value    
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The decimal value
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. 
            //
            TYPE GetDecimalValue();


            // Method Information :
            //
            //  Description :
            //
            //      Use to set new hexadecimal representation
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. newHexadecimal - the hexadecimal representation 
            //          2. trueForLittleEndianAndFalseForBigEndian - the encoding on which the hexadecimal representation was created        
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline void SetNewHexadecimalRepresentation( const AsciiString& newHexadecimal, bool trueForLittleEndianAndFalseForBigEndian );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the hexadecimal representation 
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The ascii string object of the hexadecimal representation 
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. 
            //
            inline AsciiString GetHexadecimalRepresentation() const;


            // The following methods declare the overloaded operators for the object :


            // All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
            // help locate problems in the code


            DEBUG_TOOL(


                // This part of the class is dedicated for testing :


                // Method Information :
                //
                //  Description :
                //
                //      This method is used to test the object
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          NONE
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      1. true - if the object passed the test
                //      2. false - otherwise
                //
                //  Possible errors :
                //
                //      1. A method does not work correctly - class Exception is thrown
                //      2. There is no more free memory space - class std::bad_alloc is thrown
                //      3. 
                //
                void Test();


                // Method Information :
                //
                //  Description :
                //
                //      Use to display the hexadecimal representation
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          NONE
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2. 
                //
                void DisplayHexadecimalRepresentation() const;


                // Method Information :
                //
                //  Description :
                //
                //      Use to display the hexadecimal representation
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          NONE
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      NONE
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2. 
                //
                inline void DisplayDecimalValue();


            )  //  End of debug tool


        private: 


            // This object will store the hexadecimal representation
            Encoding::AsciiString m_hexadecimal;

            // This object will store the decimal value
            TYPE m_decimalValue;

            // This object will store if the decimal value can be used. It can be used if the method GetDecimalValue was used on the 
            // current hexadecimal representation
            bool m_trueForDecimalValueCanBeUsedAndFalseOtherwise;

            // This object will store the if the current system uses little or big endian
            bool m_trueForLittleEndianAndFalseForBigEndian;


            // Method Information :
            //
            //  Description :
            //
            //      Use to set the beginning of the hexadecimal representation with the encoding of the system,
            //      little or big endian. This way when other users use the hexadecimal representation they can
            //      know the encoding of the system that created the hexadecimal representation
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          trueForLittleEndianAndFalseForBigEndian - this will be used to determine the encoding of the system little or big endian
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            void SetLittleOrBigEndianEncodingIMP( bool trueForLittleEndianAndFalseForBigEndian );


            // Method Information :
            //
            //  Description :
            //
            //      Use to convert the decimal value into the hexadecimal representation
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          decimalValue - the decimal value to convert to hexadecimal representation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            void ConvertToHexadecimalIMP( TYPE decimalValue );


            // Method Information :
            //
            //  Description :
            //
            //      Use to add the hexadecimal convention '0x' and before are the letters 'LE' or 'BE' for notifying the endoing type
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          trueForLittleEndianAndFalseForBigEndian - the encoding on which the hexadecimal representation was created        
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            void AddTheHexadecimalConventionIfNeededAndSetLettersToUppercaseIMP( bool trueForLittleEndianAndFalseForBigEndian );


            // Friend class or friend function can access private and protected members of other class in which it is declared as friend.
            // It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
            // is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
            // use of this functions is not limited to the class's scope. The following declarations are for all the function that should
            // be friends with this class :


        };  //  Class Hexadecimal























//  **************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   *************************************************************





















        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor, used to support move semantics
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline Hexadecimal< TYPE >::Hexadecimal() :
        m_hexadecimal(),
        m_decimalValue( 0 ),
        m_trueForDecimalValueCanBeUsedAndFalseOtherwise( false ),
        m_trueForLittleEndianAndFalseForBigEndian( false )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          decimalValue - the decimal value that should be represented as hexadecimal
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline Hexadecimal< TYPE >::Hexadecimal( TYPE decimalValue ) : 
        m_hexadecimal( ( sizeof( TYPE ) * 2 ) + 4 ),
        m_decimalValue( decimalValue ),
        m_trueForDecimalValueCanBeUsedAndFalseOtherwise( true ),
        m_trueForLittleEndianAndFalseForBigEndian( LittleOrBigEndian() )
        {
            // Set the first byte to notify if the system that creeated the hexadecimal representation
            // uses little or big endian
            SetLittleOrBigEndianEncodingIMP( m_trueForLittleEndianAndFalseForBigEndian );

            // Set the hexadecimal convention '0x'

            // Set the first byte to "0"
            m_hexadecimal[2] = '0';

            // Set the second byte to "x"
            m_hexadecimal[3] = 'x';

            // Convert the given decimal value into hexadecimal representation
            ConvertToHexadecimalIMP( decimalValue );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. hexadecimal - the hexadecimal representation 
        //          2. trueForLittleEndianAndFalseForBigEndian - the encoding on which the hexadecimal representation was created
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        Hexadecimal< TYPE >::Hexadecimal( const AsciiString& hexadecimal, bool trueForLittleEndianAndFalseForBigEndian ) : 
        m_hexadecimal( hexadecimal ),
        m_decimalValue( 0 ),
        m_trueForDecimalValueCanBeUsedAndFalseOtherwise( false ),
        m_trueForLittleEndianAndFalseForBigEndian( LittleOrBigEndian() )
        {
            // Copy the hexadecimal representation
            AddTheHexadecimalConventionIfNeededAndSetLettersToUppercaseIMP( trueForLittleEndianAndFalseForBigEndian );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Copy constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //        They will come
        //
        template< typename TYPE >
        inline Hexadecimal< TYPE >::Hexadecimal( const Hexadecimal< TYPE >& other ) :
        m_hexadecimal( other.m_hexadecimal ),
        m_decimalValue( other.m_decimalValue ),
        m_trueForDecimalValueCanBeUsedAndFalseOtherwise( other.m_trueForDecimalValueCanBeUsedAndFalseOtherwise ),
        m_trueForLittleEndianAndFalseForBigEndian( LittleOrBigEndian() )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, handle self assignment correctly,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        Hexadecimal< TYPE >& Hexadecimal< TYPE >::operator=( const Hexadecimal< TYPE >& other )
        {

            // Check that this is not self assignment
            if ( this != &other )
            {
                // This is not self assignment

                // Check if the other object is in default state
                if ( true == other.DefaultState() )
                {
                    // The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Copy the other object resources

                // Copy the hexadecimal representation from other object to this object
                m_hexadecimal = other.m_hexadecimal;

                // Copy the decimal value
                m_decimalValue = other.m_decimalValue;

                // Copy the information if the decimal value can be used
                m_trueForDecimalValueCanBeUsedAndFalseOtherwise = other.m_trueForDecimalValueCanBeUsedAndFalseOtherwise;

                // Set the encoding of the system little or big endian
                m_trueForLittleEndianAndFalseForBigEndian = LittleOrBigEndian();
            }

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move constructor, take the resources from the instance given in the rvalue reference, and set it to the default state.
        //      Will operate correctly even if the other object is in default state. Important note - if the current object has a pointer
        //      memebers, they must be set manually to 0 before using the method set to default state, or else the resources will be deleted
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline Hexadecimal< TYPE >::Hexadecimal( Hexadecimal< TYPE >&& other ) :
        m_hexadecimal( other.m_hexadecimal ),
        m_decimalValue( other.m_decimalValue ),
        m_trueForDecimalValueCanBeUsedAndFalseOtherwise( other.m_trueForDecimalValueCanBeUsedAndFalseOtherwise ),
        m_trueForLittleEndianAndFalseForBigEndian( LittleOrBigEndian() )
        {
            // Set the other object to default state
            other.SetToDefaultState();
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, handle self assignment correctly. take the resources from the instance given in the rvalue reference,
        //      and set it to the default state. Will operate correctly even if the other object is in default state. Important note - if the
        //      current object has pointer memebers, they must be set manually to 0 before using the method set to default state, or else
        //      the resources will be deleted
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object
        //
        //  Possible errors :
        //
        //  They will come
        //
        template< typename TYPE >
        Hexadecimal< TYPE >& Hexadecimal< TYPE >::operator=( Hexadecimal< TYPE >&& other )
        {

            // Check that this is not self assignment
            if ( this != &other )
            {
                // This is not self assignment

                // Check if the other object is in default state
                if ( true == other.DefaultState() )
                {
                    // The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Take the other object resources

                // Take the hexadecimal representation from other object to this object
                m_hexadecimal = other.m_hexadecimal;

                // Take the decimal value
                m_decimalValue = other.m_decimalValue;

                // Take the information if the decimal value can be used
                m_trueForDecimalValueCanBeUsedAndFalseOtherwise = other.m_trueForDecimalValueCanBeUsedAndFalseOtherwise;

                // Set the encoding of the system little or big endian
                m_trueForLittleEndianAndFalseForBigEndian = LittleOrBigEndian();

                // Set the other object to default state
                other.SetToDefaultState();
            }

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //        Destructor,
        //
        //  Required arguments :
        //
        //        User information needed :
        //
        //            NONE
        //
        //        Information returned to the user :
        //
        //            NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline Hexadecimal< TYPE >::~Hexadecimal() throw()
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the object into his default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline void Hexadecimal< TYPE >::SetToDefaultState()
        {
            // Set the members to their default state

            // Set the ascii string with the hexadecimal representation to default state
            m_hexadecimal.SetToDefaultState();

            // Set that the decimal value can not be used
            m_trueForDecimalValueCanBeUsedAndFalseOtherwise = false;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the object is in default state, it will return true if it does, and false otherwise
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true, if instance is at default state
        //      2. false, if instance is not at default state
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline bool Hexadecimal< TYPE >::DefaultState() const
        {

            // Check if the object is in default state
            if ( true == m_hexadecimal.DefaultState() &&
                 false == m_trueForDecimalValueCanBeUsedAndFalseOtherwise )
            {
                // The object is in default state
                return ( true );
            }

            // The object is not in default state
            return ( false );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to delete the object resources and set the object to default state. The resource will only be 
        //      deleted if the reference count is 1, which means only current instance uses the resource. If the 
        //      current instance is at default state the method will do nothing
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. Deleting the object resources failed
        //      2.
        //
        template< typename TYPE >
        inline void Hexadecimal< TYPE >::DeleteResourcesAndSetToDefaultState()
        {
            // Check if the object is in default state, then nothing needs to be done
            RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

            // Delete the resource inside the ascii string
            m_hexadecimal.DeleteResourcesAndSetToDefaultState();

            // Set that the decimal value can not be used
            m_trueForDecimalValueCanBeUsedAndFalseOtherwise = false;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to set a new decimal value    
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          newDecimalValue - the new decimal value that should be represented as hexadecimal
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The decimal value
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. 
        //
        template< typename TYPE >
        inline TYPE Hexadecimal< TYPE >::SetNewDecimalValue( TYPE newDecimalValue )
        {
            // Set the new decimal value
            m_decimalValue = newDecimalValue;

            // Set that the decimal value can be used
            m_trueForDecimalValueCanBeUsedAndFalseOtherwise = true;

            // Convert the given decimal value into hexadecimal representation
            ConvertToHexadecimalIMP( newDecimalValue );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the decimal value    
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The decimal value
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. 
        //
        template< typename TYPE >
        TYPE Hexadecimal< TYPE >::GetDecimalValue()
        {

            // Check if the decimal value can be used
            if ( true == m_trueForDecimalValueCanBeUsedAndFalseOtherwise )
            {
                // The decimal value can be used, which means either the decimal value was given in construction
                // ot this method was already called on the current hexadecimal representation
                return ( m_decimalValue );
            } 

            // Loop on all the bytes ( starting from the fifth byte right after the "LE0x or BE0x" )
            for ( UnsignedInteger16bits hexadecimalIndex = 4 ; m_hexadecimal[ hexadecimalIndex ] != 0 ; ++hexadecimalIndex )
            {
                // The hexadecmial represnt the state of the bits, therefore the bits of the decimal value must be identical.
                // For that every hexadecimal entry is set into the lowest significant bits, and then the decimal value
                // is left shifted 4 times to move the 4 lowest significant bits to higher significant bits, and to make
                // space for the next hexadecimal entry

                // Check if the current hexadecimal characters is a digit 1 - 9 or a letter A - F
                if ( ( m_hexadecimal[ hexadecimalIndex ] >= '0' ) && ( m_hexadecimal[ hexadecimalIndex ] <= '9' ) )
                {
                    // The current hexadecimal character is a digit, then 48 ( the value of '0' in ascii ) would be needed to 
                    // be subtracted from it in order to get the decimal value

                    // Multiply the current decimal value by 16, which is the same as left shifting 4 times, in order 
                    // to make room for the next lower significant bits, and add the new 4 bits
                    m_decimalValue = ( m_decimalValue * 16 ) + ( m_hexadecimal[ hexadecimalIndex ] - '0' );
                }
                else
                {
                    // The current hexadecimal character is a letter, then 65 ( the value of 'A' in ascii ) would be needed to 
                    // be subtracted from it in order to get the decimal value

                    // Multiply the current decimal value by 16, which is the same as left shifting 4 times, in order 
                    // to make room for the next lower significant bits, and add the new 4 bits
                    m_decimalValue = ( m_decimalValue * 16 ) + ( m_hexadecimal[ hexadecimalIndex ] - 'A' );
                }

            }

            // Now all the bits were entered to the decimal value variable

            // The process is correct if the system used big endian encoding, otherwise the bits of the decimal value must be
            // reversed
            if ( true == m_trueForLittleEndianAndFalseForBigEndian ) 
            {
                // The system uses little endian encoding

                // Reverse the order of the bits
                Memory::BitsAndBytes::ReverseBytesOrder( &m_decimalValue, sizeof( TYPE ) );
            }

            // Set that the decimal value can be used
            m_trueForDecimalValueCanBeUsedAndFalseOtherwise = true;

            // Return the decimal value
            return ( m_decimalValue );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to set new hexadecimal representation
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. newHexadecimal - the hexadecimal representation 
        //          2. trueForLittleEndianAndFalseForBigEndian - the encoding on which the hexadecimal representation was created        
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline void Hexadecimal< TYPE >::SetNewHexadecimalRepresentation( const AsciiString& newHexadecimal, bool trueForLittleEndianAndFalseForBigEndian )
        {
            // Copy the new hexadecimal representation into this object
            m_hexadecimal = newHexadecimal;

            // Copy the hexadecimal representation
            AddTheHexadecimalConventionIfNeededAndSetLettersToUppercaseIMP( trueForLittleEndianAndFalseForBigEndian );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the hexadecimal representation 
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The ascii string object of the hexadecimal representation 
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. 
        //
        template< typename TYPE >
        inline AsciiString Hexadecimal< TYPE >::GetHexadecimalRepresentation() const
        {
            // Return the ascii string object of the hexadecimal representation 
            return ( m_hexadecimal );
        }


























//  ***************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************






























//  **************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************************
























        // Method Information :
        //
        //  Description :
        //
        //      Use to set the beginning of the hexadecimal representation with the encoding of the system,
        //      little or big endian. This way when other users use the hexadecimal representation they can
        //      know the encoding of the system that created the hexadecimal representation
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          trueForLittleEndianAndFalseForBigEndian - this will be used to determine the encoding of the system little or big endian
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        void Hexadecimal< TYPE >::SetLittleOrBigEndianEncodingIMP( bool trueForLittleEndianAndFalseForBigEndian )
        {
            // Set the second byte with the letter "E" to notify that this is the endian mark
            m_hexadecimal.PushHead( 'E' );

            // Check if the system used little or big endian
            if ( true == trueForLittleEndianAndFalseForBigEndian )
            {
                // Little endian encoding

                // Set the first byte to notify the system using little endian
                m_hexadecimal.PushHead( 'L' );
            }
            else
            {
                // Big endian encoding

                // Set the first byte to notify the system using big endian
                m_hexadecimal.PushHead( 'B' );

            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to convert the decimal value into the hexadecimal representation
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          decimalValue - the decimal value to convert to hexadecimal representation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        void Hexadecimal< TYPE >::ConvertToHexadecimalIMP( TYPE decimalValue )
        {
            // This object will store the transformation from the state of the 4 bits to the hexadecimal representation ( 0111 -> 7 )
            static const char m_4bitsStateToHexadecimalRepresentation[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

            // Create an object to store the number of bytes the object is stored on
            UnsignedInteger16bits decimalValueNumberOfBytes = sizeof( TYPE );

            // Create an object to point to the bytes of the decimal value
            UnsignedInteger8bits* decimalValueByte = reinterpret_cast< UnsignedInteger8bits* >( &decimalValue );

            // Create an object to store the current byte to be set in hexadecimal value
            UnsignedInteger16bits hexadecimalIndex = 4;

            // Loop on all the bytes of the given object
            for ( UnsignedInteger16bits decimalValueByteIndex = 0 ; decimalValueByteIndex < decimalValueNumberOfBytes ; ++decimalValueByteIndex )
            {
                // First the 4 lower significant bits are handled. Set all the higher significant 4 bits to 0, and use the result as an index into
                // the lookup array that transform between the 4 bits state and the hexadecimal representation
                m_hexadecimal[ hexadecimalIndex + 1 ] = m_4bitsStateToHexadecimalRepresentation[ ( decimalValueByte[ decimalValueByteIndex ] & 0x0F ) ];

                // Now the 4 higher significant bits. Right shift 4 times the byte, now the required bits are in the required location.
                // Use the result as an index into the lookup array that transoform between the 4 bits state and the hexadecimal representation
                m_hexadecimal[ hexadecimalIndex ] = m_4bitsStateToHexadecimalRepresentation[ ( decimalValueByte[ decimalValueByteIndex ] >> 4 ) ];

                // Increase the hexadecimal index by 1
                hexadecimalIndex += 2;
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to add the hexadecimal convention '0x' and before are the letters 'LE' or 'BE' for notifying the endoing type
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          trueForLittleEndianAndFalseForBigEndian - the encoding on which the hexadecimal representation was created         
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        void Hexadecimal< TYPE >::AddTheHexadecimalConventionIfNeededAndSetLettersToUppercaseIMP( bool trueForLittleEndianAndFalseForBigEndian )
        {

            // Check if the given hexadecimal representation starts with the convention "0x"
            if ( ( m_hexadecimal[0] != '0'  ) && ( m_hexadecimal[1] != 'x' ) )
            {
                // The given hexadecimal representation has the convention "0x"

                // Add the 'x' to the beginning
                m_hexadecimal.PushHead( 'x' );

                // Add the '0' before the 'x'
                m_hexadecimal.PushHead( '0' );
            }

            // Set the first byte to notify if the system that creeated the hexadecimal representation
            // uses little or big endian
            SetLittleOrBigEndianEncodingIMP( trueForLittleEndianAndFalseForBigEndian );

            // Set all the hexadecimal characters to upper case letters 
            AsciiString::SetLettersToUppercase( m_hexadecimal + 4 );

            // Check if the encoding on current system is the same as the encoding in the system the hexadecimal
            // representation was created on. If the encoding is not the same then the hexadecimal characters order
            // should be reversed
            if ( m_trueForLittleEndianAndFalseForBigEndian != trueForLittleEndianAndFalseForBigEndian ) 
            {
                // The endian encoidng is different

                // Reverse the order as groups of 2, because to describe 1 byte 2 hexadecimal characters are needed
                Memory::BitsAndBytes::ReverseGroupBytesInArrayOfBytes( ( m_hexadecimal + 4 ) , 2, ( m_hexadecimal.Size() - 4 ) );
            }
            
        }






















// ***************************************************************   NESTED CLASS IMPLEMENTATION -    ****************************************************************************
























// ******************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ****************************************************************










        // This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
        // within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
        // to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
        // this functions are needed to avoid just that























// ***********************************************************************   TESTING   ***********************************************************************










        // All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
        // help locate problems in the code


        DEBUG_TOOL(



            // Method Information :
            //
            //  Description :
            //
            //      This method is used to test the object
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the object passed the test
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      1. A method does not work correctly - class Exception is thrown
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            template< typename TYPE >
            void Hexadecimal< TYPE >::Test()
            {
                // Get an handle to the assert object
                ErrorHandling::Assert& assert = ErrorHandling::Assert::GetHandle();
                
                // Create an instance using the default constructor
                Hexadecimal< UnsignedInteger64bits > testHexadecimal_1;

                // Check if the instance is in default state
                assert.False( testHexadecimal_1.DefaultState(), "Hexadecimal::Test failed - the default constrcutor does not work correctly" );

                // Create an instance using the constrcutor with the decimal value given
                Hexadecimal< UnsignedInteger8bits > testHexadecimal_2( 1 );

                // Display the hexadecimal representation
                testHexadecimal_2.DisplayHexadecimalRepresentation();

                // Create an instance using the constrcutor with the decimal value given
                Hexadecimal< UnsignedInteger8bits > testHexadecimal_3( 8 );

                // Display the hexadecimal representation
                testHexadecimal_3.DisplayHexadecimalRepresentation();

                // Create an instance using the constrcutor with the decimal value given
                Hexadecimal< UnsignedInteger16bits > testHexadecimal_4( 144 );

                // Display the hexadecimal representation
                testHexadecimal_4.DisplayHexadecimalRepresentation();

                // Create an instance using the constrcutor with the decimal value given
                Hexadecimal< UnsignedInteger16bits > testHexadecimal_5( 257 );

                // Display the hexadecimal representation
                testHexadecimal_5.DisplayHexadecimalRepresentation();

                // Create an instance using the constrcutor with the decimal value given
                Hexadecimal< UnsignedInteger64bits > testHexadecimal_6( 16536 );

                // Display the hexadecimal representation
                testHexadecimal_6.DisplayHexadecimalRepresentation();

                // Create an instance using the constrcutor with the hexadecimal representation given
                Hexadecimal< UnsignedInteger16bits > testHexadecimal_7( "0x0100", true );

                // Display the hexadecimal representation
                testHexadecimal_7.DisplayHexadecimalRepresentation();

                // Display the decimal value
                testHexadecimal_7.DisplayDecimalValue();

                // Create an instance using the constrcutor with the hexadecimal representation given
                Hexadecimal< UnsignedInteger16bits > testHexadecimal_8( "0x1100", true );

                // Display the decimal value
                testHexadecimal_8.DisplayDecimalValue();

                // Create an instance using the constrcutor with the hexadecimal representation given
                Hexadecimal< UnsignedInteger16bits > testHexadecimal_9( "0x0800", true );

                // Display the decimal value
                testHexadecimal_9.DisplayDecimalValue();

                // Create an instance using the constrcutor with the hexadecimal representation given
                Hexadecimal< UnsignedInteger16bits > testHexadecimal_10( "0x1101", true );

                // Display the decimal value
                testHexadecimal_10.DisplayDecimalValue();

                // Create an instance using the constrcutor with the hexadecimal representation given
                Hexadecimal< UnsignedInteger16bits > testHexadecimal_11( "0x8800", true );

                // Display the decimal value
                testHexadecimal_11.DisplayDecimalValue();            
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to display the hexadecimal representation
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. 
            //
            template< typename TYPE >
            void Hexadecimal< TYPE >::DisplayHexadecimalRepresentation() const
            {
                // Display the hexadecimal representation
                //m_hexadecimal.Display();
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to display the hexadecimal representation
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          NONE
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. 
            //
            template< typename TYPE >
            inline void Hexadecimal< TYPE >::DisplayDecimalValue()
            {
                // Display the decimal value
                std::cout << "The decimal value is -  " << GetDecimalValue() << std::endl;
            }


        )  //  End of debug tool















    }  //   Namespace Encoding

}  //   Namespace Universe

#endif  // HEXADECIMAL_H














