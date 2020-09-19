            // Method Information :
            //
            //  Description :
            //
            //      Use this method to copy content in memory to another location. The method takes into account if the source memory address is lower 
            //      or higher then the destination memory address. If the source address is lower then the copy will begin from the end of the source
            //      memory area to copy, and if it is higher the copy will start from the beginning of the memory area. This is needed to avoid writing
            //      into locations that needs to be read afterwards for the copy, in other words, when the source and destination memory areas overlaps. 
            //      Visually :
            //
            //                                         Pointer = 0x07
            //                                                |
            //                  Source            ->          4 5 6 7 8 9
            //
            //                                               Pointer = 0x09
            //                                                      |
            //                  destination       ->          4 5 6 7 8 9
            //
            //      As can be seen if the copying will start from the beginning of the source memory address, the first writing to the destination memory
            //      address will erase the data, then after it the situation will look :
            //                  
            //                                         Pointer = 0x07
            //                                                |
            //                  Source            ->          4 5 6 7 8 9
            //
            //                                               Pointer = 0x09
            //                                                      |
            //                  destination       ->          4 5 6 4 8 9
            //
            //      Which is of course unwanted. Then the check is dont to avoid it. Now if the source and destination memory addresses are equal then 
            //      there is nothing to do, this situation will be asserted! 
            //
            //      This method is one of three methods that perform the copying of memory areas. This method is enabled only for primitive types, the 
            //      second is for objects and the last for 'Bit' type object. The difference is that primitive types can be just byte copied to the new 
            //      location, while objects require constructors to be called to copy them. The last type 'Bit' is enabled to allow copy that can start
            //      and end not on byte boundaries, to allow 'bit' precision copying. This is possible due to subtitution failure is not an error, which 
            //      is implemented in code through the 'ProvideTypeOnlyIfAssertionIsTrue' object. It will be operated on the return value of the method, 
            //      and to construct it the expression given to the 'ProvideTypeOnlyIfAssertionIsTrue' constructor will be the question if the type is 
            //      primitve. Then only when the type is primitve the 'ProvideTypeOnlyIfAssertionIsTrue' will create a type definiton inside it of the 
            //      type 'void', because the method return nothing. Lastly for the 'Bit' object type a template specialization will be created
            //
            //  Required arguments :
            //            
            //      User information needed :
            //
            //          1. source - a pointer contains the memory address to copy from
            //          2. sourceSize - the number of entries to copy, in terms of bits
            //          3. destination - a pointer contains the memory address to copy to
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Exceptions :
            //
            //      1. The source pointer should not be NULL
            //      2. The destination pointer should not be NULL
            //      3. The source pointer and destination pointer must poiint different memory addresses 
            //      4. The destination pointer contains an address with enough memory space allocate to copy the source ( there is no way at this level to
            //         verify that enough memory space was allocated in the address the destination points too )
            //      5. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            template<>
            static void Copy< Bit >( const Bit source, UnsignedInteger64bits sourceSize, Bit destination );




        // Method Information :
        //
        //  Description :
        //
        //      Use this method to copy content in memory to another location. The method takes into account if the source memory address is lower 
        //      or higher then the destination memory address. If the source address is lower then the copy will begin from the end of the source
        //      memory area to copy, and if it is higher the copy will start from the beginning of the memory area. This is needed to avoid writing
        //      into locations that needs to be read afterwards for the copy, in other words, when the source and destination memory areas overlaps. 
        //      Visually :
        //
        //                                         Pointer = 0x07
        //                                                |
        //                  Source            ->          4 5 6 7 8 9
        //
        //                                               Pointer = 0x09
        //                                                      |
        //                  destination       ->          4 5 6 7 8 9
        //
        //      As can be seen if the copying will start from the beginning of the source memory address, the first writing to the destination memory
        //      address will erase the data, then after it the situation will look :
        //                  
        //                                         Pointer = 0x07
        //                                                |
        //                  Source            ->          4 5 6 7 8 9
        //
        //                                               Pointer = 0x09
        //                                                      |
        //                  destination       ->          4 5 6 4 8 9
        //
        //      Which is of course unwanted. Then the check is dont to avoid it. Now if the source and destination memory addresses are equal then 
        //      there is nothing to do, this situation will be asserted! 
        //
        //      This method is one of three methods that perform the copying of memory areas. This method is enabled only for primitive types, the 
        //      second is for objects and the last for 'Bit' type object. The difference is that primitive types can be just byte copied to the new 
        //      location, while objects require constructors to be called to copy them. The last type 'Bit' is enabled to allow copy that can start
        //      and end not on byte boundaries, to allow 'bit' precision copying. This is possible due to subtitution failure is not an error, which 
        //      is implemented in code through the 'ProvideTypeOnlyIfAssertionIsTrue' object. It will be operated on the return value of the method, 
        //      and to construct it the expression given to the 'ProvideTypeOnlyIfAssertionIsTrue' constructor will be the question if the type is 
        //      primitve. Then only when the type is primitve the 'ProvideTypeOnlyIfAssertionIsTrue' will create a type definiton inside it of the 
        //      type 'void', because the method return nothing. Lastly for the 'Bit' object type a template specialization will be created
        //
        //  Required arguments :
        //            
        //      User information needed :
        //
        //          1. source - a pointer contains the memory address to copy from
        //          2. sourceSize - the number of entries to copy, in terms of bits
        //          3. destination - a pointer contains the memory address to copy to
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Exceptions :
        //
        //      1. The source bit instance should be ready
        //      2. The destination pointer should not be NULL
        //      3. The source pointer and destination pointer must point to different memory addresses 
        //      4. The source size must be larger then 0
        //      5. The destination pointer contains an address with enough memory space allocate to copy the source ( there is no way at this level to
        //         verify that enough memory space was allocated in the address the destination points too )
        //      6. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template<>
        static void Operations::Copy< Bit >( const Bit& source, UnsignedInteger64bits sourceSize, Bit& destination )
        {

            // Check if the contigous segment of bits needs to be copied to higher or lower address values, in other words up or down
            if ( source > destination )
            {
                // The bits needs to be copied to lower addresses
                CopyToLowerAddress_CompareTheIndexOfTheFirstBitInSourceAndDestinationAndChooseTheOperationToCopy_Private( source, sourceSize, destination );
            }
            else if ( source < destination )
            {
                // The bits needs to be copied to higher addresses
                CopyToHigherAddress_CompareTheIndexOfTheFirstBitInSourceAndDestinationAndChooseTheOperationToCopy_Private( source, sourceSize, destination );
            }
            else
            {
                // The bits needs to be copied to the same address
                CopyToTheSameAddress_CompareTheIndexOfTheFirstBitInSourceAndDestinationAndChooseTheOperationToCopy_Private( source, sourceSize, destination );
            }

        }





        // This part is for copying the bits to higher address :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to higher address. The difference is made by the indexes of the first bit, in the 
        //      source and destination
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
	    //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToHigherAddress_CompareTheIndexOfTheFirstBitInSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {

            // Check if the index of the first bit in source is larger then the index of the first bit in destination
            if ( source.FirstUsedBitIndexInTheByte() > destination.FirstUsedBitIndexInTheByte() )
            {
                // The index of the first bit in source is larger then in destination

                // Check the size of source and destination and choose the operation to copy the bits accordingly
                CopyToHigherAddress_SourceFirstBitIndexIsLarger_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( source, destination );
            }
            // Check if the index of the first bit in source is smaller then the index of the first bit in destination
            else if ( source.FirstUsedBitIndexInTheByte() < destination.FirstUsedBitIndexInTheByte() )
            {
                // The index of the first bit in source is smaller then in destination

                // Check the size of source and destination and choose the operation to copy the bits accordingly
                CopyToHigherAddress_SourceFirstBitIndexIsSmaller_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( source, destination );
            }
            else
            {
                // The index of the first bit in source and destination is equal

                // Set the bits that needs to be used in the last byte of destination  to 0
                destination.BytesPointer()[ destination.LastUsedByteIndex() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );

                // Set the bits of the last byte in source to the last byte of destination
                destination.BytesPointer()[ destination.LastUsedByteIndex() ] = ( source.BytesPointer()[ source.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveIndex( source.LastUsedBitIndexInTheByte() ) );

                // Copy the rest of the bytes
                Basic< UnsignedInteger8bits >( DataTypes::Pointer< UnsignedInteger8bits >( ( source + 1 ), ( source.BytesPointer().Size() - 2 ) ), DataTypes::Pointer< UnsignedInteger8bits >( ( destination + 1 ), ( destination.BytesPointer().Size() - 2 ) ) );

                // Set the bits that needs to be used in the first byte of destination  to 0
                destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

                // Set the bits of the first byte in source to the first byte of destination
                destination.BytesPointer()[0] = ( source.BytesPointer()[0] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveAndIncludingIndex( source.FirstUsedBitIndexInTheByte() ) );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to higher address, and the index of the first bit in source is larger then in destination. 
        //      This method picks between 2 situations, and call the required method to handle the situation. The first is when there will be no bits left in the last byte, 
        //      because of the additional bits to the first byte, which will cause the destination to be smaller in 1 byte. The second situation is when the last byte will 
        //      still have used bits and then the size of source and destination will be the same
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToHigherAddress_SourceFirstBitIndexIsLarger_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold more bits then the old first byte

            // Check if the size of source and destination is different
            if ( source.LastUsedByteIndex() > destination.LastUsedByteIndex() )
            {
                // The last byte will have no bits used

                // Do the actual copying already
                CopyToHigherAddress_SourceFirstBitIndexIsLarger_NoBitsShouldBeInTheLastByte__Private( source, destination );
            }
            else
            {
                // The last byte will have bits used

                // Will you just copy??
                CopyToHigherAddress_SourceFirstBitIndexIsLarger_BitsShouldBeInTheLastByte__Private( source, destination );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the index of the first bit that needs to be copied in the old byte is smaller then the index in the new byte, and the last byte bits are 
        //      not required anymore. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToHigherAddress_SourceFirstBitIndexIsLarger_NoBitsShouldBeInTheLastByte__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new last byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( source.FirstUsedBitIndexInTheByte() - destination.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination
            // from 8, which is the number of shifts that should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set to 0 all the bits that needs to be used in the last byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );

            // Store the bits of the last byte
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( ( source.BytesPointer()[ source.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveIndex( source.LastUsedByteIndex() ) ) << numberOfTimesToShift );

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = destination.LastUsedByteIndex();

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = ( source.LastUsedByteIndex() - 1 ) ; sourceByteIndex > 1 ; --sourceByteIndex )
            {
                // Right shift the byte, to exclude the low order bits, and set the result into the current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Left shift the byte, to exclude the high order bits, and set the result into the current byte of destination
                destination.BytesPointer()[ destinationByteIndex - 1 ] = ( source.BytesPointer()[ sourceByteIndex ] << numberOfTimesToShift );

                // Decrease the current byte index on the destination by 1
                destinationByteIndex -= 1;
            }

            // The loop is stopping at 1 instead of 0 because, when assigning in the loop all to previous byte in the destination, all the old bits are deleted, and in the 
            // first byte of destination there are bits that should not be changed, the method only changes the bits in the required range

            // Right shift the second byte of the source, to exclude the low order bits, and set the result into the second byte of destination
            destination.BytesPointer()[1] |= ( source.BytesPointer()[1] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set to 0 all the bits that needs to be used in the first byte of destination
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );  

            // Left shift the byte, to exclude the high order bits, and set the result into the first byte of destination
            destination.BytesPointer()[0] |= ( source.BytesPointer()[1] << numberOfTimesToShift );

            // Set the bits from the first byte of source to the first byte of destination
            destination.BytesPointer()[0] |= ( source.BytesPointer()[0] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the index of the first bit that needs to be copied in the old byte is smaller then the index in the new byte, and the last byte bits still 
        //      needs to be used. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToHigherAddress_SourceFirstBitIndexIsLarger_BitsShouldBeInTheLastByte__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( source.FirstUsedBitIndexInTheByte() - destination.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set the bits in the new last byte that will be set by the required bits to 0
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );

            // Set the last bits that can fit into to the new last byte
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() ] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set the remaining bits from the last byte to the byte before the last new byte
            destination.BytesPointer()[ destination.LastUsedByteIndex() - 1 ] = ( source.BytesPointer()[ source.LastUsedByteIndex() ] << numberOfTimesToShift );

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = ( destination.LastUsedByteIndex() - 1 );

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = ( source.LastUsedByteIndex() - 1 ) ; sourceByteIndex > 1 ; --sourceByteIndex )
            {
                // Right shift the byte, to exclude the low order bits that should be set to previous byte, and set it to the new location
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Left shift the byte, to exclude the high order bits that were already stored, and set it to the byte before the current one
                destination.BytesPointer()[ destinationByteIndex - 1 ] = ( source.BytesPointer()[ sourceByteIndex ] << numberOfTimesToShift );

                // Decrease the current byte index on the destination by 1
                destinationByteIndex -= 1;
            }

            // The loop is stopping at 1 instead of 0 because, when assigning in the loop all to previous byte in the destination, all the old bits are deleted, and in the 
            // first byte of destination there are bits that should not be changed, the method only changes the bits in the required range

            // Right shift the byte, to exclude the low order bits that should be set to previous byte, and set it to the new location
            destination.BytesPointer()[1] |= ( source.BytesPointer()[1] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set off the bits that should be set in the first byte of destination
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

            // Left shift the byte, to exclude the high order bits that were already stored, and set it to the byte before the current one
            destination.BytesPointer()[0] |= ( source.BytesPointer()[1] << numberOfTimesToShift );

            // Right shift the first byte in the source, and set the result in the first byte of destination
            destination.BytesPointer()[0] |= ( source.BytesPointer()[0] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to higher address, and the index of the first bit in source is smaller then in destination. 
        //      This method picks between 2 situations, and call the required method to handle the situation. The first is when bits are pushed from the last byte to the next 
        //      one, because of the bits that can not longer be in the first byte. The second situation is when the bits of the last byte only shifted to make room for more bits
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToHigherAddress_SourceFirstBitIndexIsSmaller_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold more bits then the old first byte

            // Check if because the additional bits of the first byte, there will be bits pushed to the next byte. The only reason for the 2 indexes of the last bytes in the 
            // source and destination to be different is when there are bits pushed from the last byte to the next one, and therefore the destination index will be larger
            if ( source.LastUsedByteIndex() < destination.LastUsedByteIndex() )
            {
                // The last byte can still store all the required bits

                // Do the actual copying already
                CopyToHigherAddress_SourceFirstBitIndexIsSmaller_BitsArePushedFromTheLastByteToTheNextOne__Private( source, destination );
            }
            else
            {
                // Bits from the last byte will be pushed to the next byte

                // Will you just copy??
                CopyToHigherAddress_SourceFirstBitIndexIsSmaller_TheLastByteCanStoreTheAdditionalBits__Private( source, destination );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the bits needs to be copied to higher address values ( up ), and the index of the first bit that needs to be copied in the old byte is 
        //      larger then the index in the new byte, and bits are pushed from the last byte to the next one. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToHigherAddress_SourceFirstBitIndexIsSmaller_BitsArePushedFromTheLastByteToTheNextOne__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( destination.FirstUsedBitIndexInTheByte() - source.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set the bits in the new last byte that will be set by the required bits to 0
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] = ( destination.BytesPointer()[ destination.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() ) );

            // Get the number of bits that will be pushed to the next byte in the copy, then right shift the amount of bits in the last byte of source subtracted by the number 
            // of bits pushed to the next byte, and set the result to the last byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( ( source.BytesPointer()[ source.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveIndex( source.LastUsedBitIndexInTheByte() ) ) >> ( source.LastUsedBitIndexInTheByte() - destination.LastUsedBitIndexInTheByte() ) );

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = ( destination.LastUsedByteIndex() - 1 );

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = source.LastUsedByteIndex() ; sourceByteIndex > 0 ; --sourceByteIndex )
            {
                // Left shift the byte source byte to exclude the high order bits that were already assigned to previous byte, and set the result in the current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] = ( source.BytesPointer()[ sourceByteIndex ] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Right shift the the previous byte of source, to exclude the low order bits, and set the result to the current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex - 1 ] >> numberOfTimesToShift );

                // Decrease the current byte index on the destination by 1
                destinationByteIndex -= 1;
            }

            // Set the bits that needs to be used in the first byte of destination to 0
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

            // Set the bits left from the first byte of the source left shifted, to the first byte of the destination
            destination.BytesPointer()[0] |= ( source.BytesPointer()[0] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the bits needs to be copied to higher address values ( up ), and the index of the first bit that needs to be copied in the old byte is 
        //      larger then the index in the new byte, and the last byte can still store all the required bits. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToHigherAddress_SourceFirstBitIndexIsSmaller_TheLastByteCanStoreTheAdditionalBits__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( destination.FirstUsedBitIndexInTheByte() - source.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set the bits in the new last byte that will be set by the required bits to 0
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] = ( destination.BytesPointer()[ destination.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() ) );

            // Set the bits in the last byte of source left shifted, to the destination last byte
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() ] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = destination.LastUsedByteIndex();

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = ( source.LastUsedByteIndex() - 1 ) ; sourceByteIndex > 0 ; --sourceByteIndex )
            {
                // Right shift the byte, to exclude the low order bits that should be set to previous byte, and set it to the new location
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] >> numberOfTimesToShift );

                // Left shift the byte, to exclude the high order bits that were already stored, and set it to the byte before the current one
                destination.BytesPointer()[ destinationByteIndex - 1 ] = ( source.BytesPointer()[ sourceByteIndex ] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Decrease the current byte index on the destination by 1
                destinationByteIndex -= 1;
            }

            // Set the high order bits from the second byte of the source right shifted
            destination.BytesPointer()[1] |= ( source.BytesPointer()[0] >> numberOfTimesToShift );

            // Set the bits that needs to be used in the first byte of destination to 0
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

            // Set the bits left from the first byte of the source left shifted, to the first byte of the destination
            destination.BytesPointer()[0] |= ( source.BytesPointer()[0] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );
        }


        // This part is for copying the bits to lower address :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to higher address. The difference is made by the indexes of the first bit, in the 
        //      source and destination
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToLowerAddress_CompareTheIndexOfTheFirstBitInSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {

            // Check if the index of the first bit in source is larger then the index of the first bit in destination
            if ( source.FirstUsedBitIndexInTheByte() > destination.FirstUsedBitIndexInTheByte() )
            {
                // The index of the first bit in source is larger then in destination

                // Check the size of source and destination and choose the operation to copy the bits accordingly
                CopyToLowerAddress_SourceFirstBitIndexIsLarger_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( source, destination );
            }
            // Check if the index of the first bit in source is smaller then the index of the first bit in destination
            else if ( source.FirstUsedBitIndexInTheByte() < destination.FirstUsedBitIndexInTheByte() )
            {
                // The index of the first bit in source is smaller then in destination

                // Check the size of source and destination and choose the operation to copy the bits accordingly
                CopyToLowerAddress_SourceFirstBitIndexIsSmaller_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( source, destination );
            }
            else
            {
                // The index of the first bit in source and destination is equal

                // Set the bits that needs to be used in the first byte of destination  to 0
                destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

                // Set the bits of the first byte in source to the first byte of destination
                destination.BytesPointer()[0] = ( source.BytesPointer()[0] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveAndIncludingIndex( source.FirstUsedBitIndexInTheByte() ) );

                // Copy the rest of the bytes
                Basic< UnsignedInteger8bits >( DataTypes::Pointer< UnsignedInteger8bits >( ( source + 1 ), ( source.BytesPointer().Size() - 2 ) ), DataTypes::Pointer< UnsignedInteger8bits >( ( destination + 1 ), ( destination.BytesPointer().Size() - 2 ) ) );

                // Set the bits that needs to be used in the last byte of destination  to 0
                destination.BytesPointer()[ destination.LastUsedByteIndex() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );

                // Set the bits of the last byte in source to the last byte of destination
                destination.BytesPointer()[ destination.LastUsedByteIndex() ] = ( source.BytesPointer()[ source.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveIndex( source.LastUsedBitIndexInTheByte() ) );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to higher address, and the index of the first bit in source is larger then in destination. 
        //      This method picks between 2 situations, and call the required method to handle the situation. The first is when there will be no bits left in the last byte, 
        //      because of the additional bits to the first byte, which will cause the destination to be smaller in 1 byte. The second situation is when the last byte will 
        //      still have used bits and then the size of source and destination will be the same
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToLowerAddress_SourceFirstBitIndexIsLarger_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold more bits then the old first byte

            // Check if the size of source and destination is different
            if ( source.LastUsedByteIndex() > destination.LastUsedByteIndex() )
            {
                // The last byte will have no bits used

                // Do the actual copying already
                CopyToLowerAddress_SourceFirstBitIndexIsLarger_NoBitsShouldBeInTheLastByte__Private( source, destination );
            }
            else
            {
                // The last byte will have bits used

                // Will you just copy??
                CopyToLowerAddress_SourceFirstBitIndexIsLarger_BitsShouldBeInTheLastByte__Private( source, destination );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the index of the first bit that needs to be copied in the old byte is smaller then the index in the new byte, and the last byte bits are 
        //      not required anymore. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToLowerAddress_SourceFirstBitIndexIsLarger_NoBitsShouldBeInTheLastByte__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte in destination will hold more bits then the first byte in source

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( source.FirstUsedBitIndexInTheByte() - destination.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set to 0 all the bits that needs to be used in the first byte of destination
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

            // Set all the bits of the last byte in source that are not required, and then left shift the result and set it to the first byte of destination
            destination.BytesPointer()[0] |= ( ( ( source.BytesPointer()[0] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveAndIncludingIndex( source.FirstUsedBitIndexInTheByte() ) ) >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit ) );            

            // Left shift the current byte in source, to exclude the high order bits that should be stored in the next byte of destination, and store the result into the current 
            // byte of destination
            destination.BytesPointer()[0] |= ( source.BytesPointer()[1] << numberOfTimesToShift );

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = 1;

            // Create an object to store the value the loop should stop on
            UnsignedInteger64bits indexOfLastUsedByte = ( source.LastUsedByteIndex() - 1 );

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = 1 ; sourceByteIndex < indexOfLastUsedByte ; ++sourceByteIndex )
            {
                // Left shift the current byte in source, to exclude the high order bits that should be stored in the next byte of destination, and store the result into 
                // the current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] = ( source.BytesPointer()[ sourceByteIndex ] << numberOfTimesToShift );

                // Right shift the next byte in source, to exclude the low order bits that were just stored to the previous byte of destination, and assign the next byte of 
                // destination to them
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex + 1 ] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Increase the current byte index on the destination by 1
                destinationByteIndex += 1;
            }

            // The loop ends before, to prevent an assignment to the last byte of destination, which will erase the high order bits which should not be changed

            // Set the bits that should be used in the last byte of destination to 0
            destination.BytesPointer()[ destination.LastUsedBitIndexInTheByte() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );

            // Right shift the byte before tha last one in source, to exclude the low order bits that were just stored to the previous byte of destination, and store them in 
            // the last byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() - 1 ] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Now all there is to do it to set the bits in the last byte of source to the last byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() ] << ( destination.LastUsedBitIndexInTheByte() - source.LastUsedBitIndexInTheByte() ) );
        }
        

        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the index of the first bit that needs to be copied in the old byte is smaller then the index in the new byte, and the last byte bits are 
        //      not required anymore. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToLowerAddress_SourceFirstBitIndexIsLarger_BitsShouldBeInTheLastByte__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte in destination will hold more bits then the first byte in source

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( source.FirstUsedBitIndexInTheByte() - destination.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set to 0 all the bits that needs to be used in the first byte of destination
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

            // Store the bits of the last byte
            destination.BytesPointer()[0] |= ( ( source.BytesPointer()[0] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveAndIncludingIndex( source.FirstUsedBitIndexInTheByte() ) ) >>  differenceBetweenTwoIndexesInTheByteOfTheFirstBit );            

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = 0;

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = 1 ; sourceByteIndex < source.LastUsedByteIndex() ; ++sourceByteIndex )
            {
                // Left shift the byte, to exclude the high order bits, and set the result into the current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] << numberOfTimesToShift );

                // Right shift the byte, to exclude the low order bits, and set the result into the next byte of destination
                destination.BytesPointer()[ destinationByteIndex + 1 ] = ( source.BytesPointer()[ sourceByteIndex ] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Increase the current byte index on the destination by 1
                destinationByteIndex += 1;
            }

            // Left shift the byte, to exclude the high order bits, and set the result into the one before the last byte of destination
            destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() ] << numberOfTimesToShift );

            // Set to 0 all the bits that needs to be used in the first byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );  

            // Right shift the byte, to exclude the low order bits, and set the result into the last byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() ] >> differenceBetweenTwoIndexesInTheByteOfTheFirstBit );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to higher address, and the index of the first bit in source is smaller then in destination. 
        //      This method picks between 2 situations, and  call the required method to handle the situation. The first is when bits are pushed from the last byte to the next 
        //      one, because of the bits that can not longer be in the first byte. The second situation is when the bits of the last byte only shifted to make room for more bits
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToLowerAddress_SourceFirstBitIndexIsSmaller_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold more bits then the old first byte

            // Check if because the additional bits of the first byte, there will be bits pushed to the next byte. The only reason for the 2 indexes of the last bytes in the 
            // source and destination to be different is when there are bits pushed from the last byte to the next one, and therefore the destination index will be larger
            if ( source.LastUsedByteIndex() < destination.LastUsedByteIndex() )
            {
                // The last byte can still store all the required bits

                // Do the actual copying already
                CopyToLowerAddress_SourceFirstBitIndexIsSmaller_BitsArePushedFromTheLastByteToTheNextOne__Private( source, destination );
            }
            else
            {
                // Bits from the last byte will be pushed to the next byte

                // Will you just copy??
                CopyToLowerAddress_SourceFirstBitIndexIsSmaller_TheLastByteCanStoreTheAdditionalBits__Private( source, destination );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the bits needs to be copied to higher address values ( up ), and the index of the first bit that needs to be copied in the old byte is 
        //      larger then the index in the new byte, and bits are pushed from the last byte to the next one. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToLowerAddress_SourceFirstBitIndexIsSmaller_BitsArePushedFromTheLastByteToTheNextOne__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( destination.FirstUsedBitIndexInTheByte() - source.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set the bits that needs to be used in the first byte of destination to 0
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

            // Set to first byte of destination the result of left shifting the first byte of source
            destination.BytesPointer()[0] |= ( source.BytesPointer()[0] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = 1;

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = 0 ; sourceByteIndex < source.LastUsedByteIndex() ; ++sourceByteIndex )
            {
                // Right shift the byte, to exclude the low order bits that were set to previous byte, and set it to the new location
                destination.BytesPointer()[ destinationByteIndex ] = ( source.BytesPointer()[ sourceByteIndex ] >> numberOfTimesToShift );

                // Left shift the byte, to exclude the high order bits that needs to be set to the next byte, and set it to the new location
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex + 1 ] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Increase the current byte index on the destination by 1
                destinationByteIndex += 1;
            }

            // Set the bits that needs to be used in the last byte of destination to 0
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );
            
            // The high order bits in the last byte of source, that no longer fit into the last byte, needs to be store at the last byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() ] >> ( source.LastUsedBitIndexInTheByte() - destination.LastUsedBitIndexInTheByte() ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the bits needs to be copied to higher address values ( up ), and the index of the first bit that needs to be copied in the old byte is 
        //      larger then the index in the new byte, and the last byte can still store all the required bits. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToLowerAddress_SourceFirstBitIndexIsSmaller_TheLastByteCanStoreTheAdditionalBits__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( destination.FirstUsedBitIndexInTheByte() - source.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Set the bits in the new first byte that will be set by the required bits to 0
            destination.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( destination.FirstUsedBitIndexInTheByte() );

            destination.BytesPointer()[0] |= ( ( source.BytesPointer()[0] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveAndIncludingIndex( source.FirstUsedBitIndexInTheByte() ) ) << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = 1;

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = 0 ; sourceByteIndex < source.LastUsedByteIndex() ; ++sourceByteIndex )
            {
                // Right shift the byte, to exclude the low order bits, that were already set to destination
                destination.BytesPointer()[ destinationByteIndex ] = ( source.BytesPointer()[ sourceByteIndex ] >> numberOfTimesToShift );

                // Left shift the byte, to exclude the high order bits that should be set to the next byte of destination, and set it to the next byte of source
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex + 1 ] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

                // Increase the current byte index on the destination by 1
                destinationByteIndex += 1;
            }

            // Set the bits that needs to be used in the last byte of destination to 0
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( destination.LastUsedBitIndexInTheByte() );

            // Set to the last byte of destination the result of right shift the byte before the last byte of source, to exclude the low order bits that were already set to 
            // destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() - 1 ] >> numberOfTimesToShift );

            // Set the bits of the last byte of source left shifted, to the last byte of destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( source.BytesPointer()[ source.LastUsedByteIndex() ] << differenceBetweenTwoIndexesInTheByteOfTheFirstBit );
        }


        // This part is for copying the bits to the same address :


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to the same address. The difference is made by the indexes of the first bit, in the 
        //      source and destination
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToTheSameAddress_CompareTheIndexOfTheFirstBitInSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {

            // Check if the index of the first bit in source is larger then the index of the first bit in destination
            if ( source.FirstUsedBitIndexInTheByte() > destination.FirstUsedBitIndexInTheByte() )
            {
                // The index of the first bit in source is larger then in destination

                // Check the size of source and destination and choose the operation to copy the bits accordingly
                CopyToTheSameAddress_SourceFirstBitIndexIsLarger_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( source, destination );
            }
            // Check if the index of the first bit in source is smaller then the index of the first bit in destination
            else if ( source.FirstUsedBitIndexInTheByte() < destination.FirstUsedBitIndexInTheByte() )
            {
                // The index of the first bit in source is smaller then in destination

                // Check the size of source and destination and choose the operation to copy the bits accordingly
                CopyToTheSameAddress_SourceFirstBitIndexIsSmaller_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( source, destination );
            }

            // If the first bit index in source and destination is equal then notihng needs to be done
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to the same address, and the index of the first bit in source is larger then in destination. 
        //      This method picks between 2 situations, and call the required method to handle the situation. The first is when there will be no bits left in the last byte, 
        //      because of the additional bits to the first byte, which will cause the destination to be smaller in 1 byte. The second situation is when the last byte will still 
        //      have used bits and then the size of source and destination will be the same
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToTheSameAddress_SourceFirstBitIndexIsLarger_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold more bits then the old first byte

            // Check if the size of source and destination is different
            if ( source.LastUsedByteIndex() > destination.LastUsedByteIndex() )
            {
                // The last byte will have no bits used

                // Do the actual copying already
                CopyToTheSameAddress_SourceFirstBitIndexIsLarger_NoBitsShouldBeInTheLastByte__Private( source, destination );
            }
            else
            {
                // The last byte will have bits used

                // Will you just copy??
                CopyToTheSameAddress_SourceFirstBitIndexIsLarger_BitsShouldBeInTheLastByte__Private( source, destination );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the index of the first bit that needs to be copied in the old byte is smaller then the index in the new byte, and the last byte bits are 
        //      not required anymore. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToTheSameAddress_SourceFirstBitIndexIsLarger_NoBitsShouldBeInTheLastByte__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte in destination will hold more bits then the first byte in source

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( source.FirstUsedBitIndexInTheByte() - destination.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // The addresses are equal which means that the first byte of source is the same byte of destination, therefore in the operations only destination can be used if 
            // wanted

            // Shift the first byte of destination to the required new first index
            destination.BytesPointer()[0] >>= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;            

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = 0;

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = 1 ; sourceByteIndex < source.LastUsedByteIndex() ; ++sourceByteIndex )
            {
                // Left shift the current byte in source, to exclude the high order bits that should be stored in the next byte of destination, and store the result into the 
                //  current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] << numberOfTimesToShift );

                // Right shift the next byte in source, to exclude the low order bits that were just stored to the previous byte of destination, and assign the next byte of 
                // destination to them
                destination.BytesPointer()[ destinationByteIndex + 1 ] >>= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;

                // Increase the current byte index on the destination by 1
                destinationByteIndex += 1;
            }

            // Set the bits in the last byte of source left shifted the difference between the index of the last bit in source and destination
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] |= ( ( ( source.BytesPointer()[ source.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveIndex( source.LastUsedBitIndexInTheByte() ) ) << ( destination.LastUsedBitIndexInTheByte() - source.LastUsedBitIndexInTheByte() ) ) );
        }
        

        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the index of the first bit that needs to be copied in the old byte is smaller then the index in the new byte, and the last byte bits are 
        //      not required anymore. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToTheSameAddress_SourceFirstBitIndexIsLarger_BitsShouldBeInTheLastByte__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte in destination will hold more bits then the first byte in source

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( source.FirstUsedBitIndexInTheByte() - destination.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination
            // from 8, which is the number of shifts that should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // The addresses are equal which means that the first byte of source is the same byte of destination, therefore in the operations only destination can be used if 
            // wanted

            // Shift the first byte of destination to the required new first index
            destination.BytesPointer()[0] >>= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;            

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = 0;

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = 1 ; sourceByteIndex <= source.LastUsedByteIndex() ; ++sourceByteIndex )
            {
                // Left shift the current byte in source, to exclude the high order bits that should be stored in the next byte of destination, and store the result into the 
                // current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] << numberOfTimesToShift );

                // Right shift the next byte in source, to exclude the low order bits that were just stored to the previous byte of destination, and assign the next byte of 
                // destination to them
                destination.BytesPointer()[ destinationByteIndex + 1 ] >>= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;

                // Increase the current byte index on the destination by 1
                destinationByteIndex += 1;
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to choose the required operation for copying the bits to higher address, and the index of the first bit in source is smaller then in destination.
        //      This method picks between 2 situations, and call the required method to handle the situation. The first is when bits are pushed from the last byte to the next 
        //      one, because of the bits that can not longer be in the first byte. The second situation is when the bits of the last byte only shifted to make room for more bits
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToTheSameAddress_SourceFirstBitIndexIsSmaller_CompareTheSizesOfSourceAndDestinationAndChooseTheOperationToCopy__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold more bits then the old first byte

            // Check if because the additional bits of the first byte, there will be bits pushed to the next byte. The only reason for the 2 indexes of the last bytes in 
            // the source and destination to be different is when there are bits pushed from the last byte to the next one, and therefore the destination index will be larger
            if ( source.LastUsedByteIndex() < destination.LastUsedByteIndex() )
            {
                // The last byte can still store all the required bits

                // Do the actual copying already
                CopyToTheSameAddress_SourceFirstBitIndexIsSmaller_BitsArePushedFromTheLastByteToTheNextOne__Private( source, destination );
            }
            else
            {
                // Bits from the last byte will be pushed to the next byte

                // Will you just copy??
                CopyToTheSameAddress_SourceFirstBitIndexIsSmaller_TheLastByteCanStoreTheAdditionalBits__Private( source, destination );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the bits needs to be copied to higher address values ( up ), and the index of the first bit that needs to be copied in the old byte is 
        //      larger then the index in the new byte, and bits are pushed from the last byte to the next one. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToTheSameAddress_SourceFirstBitIndexIsSmaller_BitsArePushedFromTheLastByteToTheNextOne__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( destination.FirstUsedBitIndexInTheByte() - source.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts that 
            // should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // The addresses are equal which means that the first byte of source is the same byte of destination, therefore in the operations only destination can be used if 
            // wanted

            // Shift the first byte of destination to the required new first index
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] = ( ( ( source.BytesPointer()[ source.LastUsedByteIndex() ] & DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveIndex( source.LastUsedBitIndexInTheByte() ) ) >> ( source.LastUsedBitIndexInTheByte() - destination.LastUsedBitIndexInTheByte() ) ) );            

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = ( destination.LastUsedByteIndex() - 1 );

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = ( source.LastUsedByteIndex() - 1 ) ; sourceByteIndex > 0 ; --sourceByteIndex )
            {
                // Left shift the current byte of destination, to exclude the higher order bits that were already stored in the next byte of destination
                destination.BytesPointer()[ destinationByteIndex ] <<= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;
                
                // Right shift the current byte of source to, exclude the low order bytes that should stay in the current byte, and store it in the current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] >> numberOfTimesToShift );

                // Descrease the current byte index on the destination by 1
                destinationByteIndex -= 1;
            }

            // Left shift the second byte of destination, to exclude the higher order bits that were already stored in the next byte of destination
            destination.BytesPointer()[1] <<= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;

            // Set the high order bits of the first byte in source, that should be stored in the the first byte of destination
            destination.BytesPointer()[1] |= ( source.BytesPointer()[0] >> numberOfTimesToShift );

            // Left shift the second byte of destination, to exclude the higher order bits that were already stored in the next byte of destination
            destination.BytesPointer()[0] <<= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method when the bits needs to be copied to higher address values ( up ), and the index of the first bit that needs to be copied in the old byte is 
        //      larger then the index in the new byte, and the last byte can still store all the required bits. In this method the actual copy is done
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
        //  Exceptions :
        //
        //		NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        void Operations::CopyToTheSameAddress_SourceFirstBitIndexIsSmaller_TheLastByteCanStoreTheAdditionalBits__Private( const Bit source, UnsignedInteger64bits sourceSize, Bit destination )
        {
            // The new first byte will hold less bits then the old first byte

            // This object will store the difference between the first bit index in source and destination
            UnsignedInteger8bits differenceBetweenTwoIndexesInTheByteOfTheFirstBit = ( destination.FirstUsedBitIndexInTheByte() - source.FirstUsedBitIndexInTheByte() );

            // This object will store the result of subtracting the difference between the first bit index in source and destination from 8, which is the number of shifts 
            // that should be done to other way
            UnsignedInteger8bits numberOfTimesToShift = ( 8 - differenceBetweenTwoIndexesInTheByteOfTheFirstBit );

            // The addresses are equal which means that the first byte of source is the same byte of destination, therefore in the operations only destination can be used if 
            // wanted

            // Shift the first byte of destination to the required new first index
            destination.BytesPointer()[ destination.LastUsedByteIndex() ] <<= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;            

            // Create an index for the destination bytes
            UnsignedInteger64bits destinationByteIndex = destination.LastUsedByteIndex();

            // Loop on all the rest of the source bytes
            for ( UnsignedInteger64bits sourceByteIndex = ( source.LastUsedByteIndex() - 1 ) ; sourceByteIndex > 0 ; --sourceByteIndex )
            {
                // Right shift the current byte of source, to exclude the low order bits that should stay in the same byte and store it the the current byte of destination
                destination.BytesPointer()[ destinationByteIndex ] |= ( source.BytesPointer()[ sourceByteIndex ] >> numberOfTimesToShift );

                // Left shift the next byte in source, to exclude the low order bits that were just stored to the previous byte of destination, and assign the next byte of 
                // destination to them
                destination.BytesPointer()[ destinationByteIndex - 1 ] <<= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;

                // Descrease the current byte index on the destination by 1
                destinationByteIndex -= 1;
            }

            // Set the high order bits from the first byte of source that should be stored in the second byte of destination
            destination.BytesPointer()[1] |= ( source.BytesPointer()[0] >> numberOfTimesToShift );

            // Left shift the first byte of destination
            destination.BytesPointer()[0] <<= differenceBetweenTwoIndexesInTheByteOfTheFirstBit;
        }






&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&






        // Method Information :
        //
        //  Description :
        //
        //      Use this method to set a contigous memory segment, that the data is bits, to the given state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. memorySegment - a bits pointer object containts information on the memory segment to set
        //          3. state - this will be used to determine if the bits needs to be set on ( true ) or off ( false )
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
        void Set::Bits( DataTypes::BitsPointer memorySegment, bool state )
        {

            // Check if the memory segment conatins only 1 byte
            if ( memorySegment.BytesPointer().Size() == 1 )
            {
                // The memory segment conatins only 1 byte

                if ( state == true )
                {
                    // The bits needs to be set on

                    // Set on the bits in the first byte
                    memorySegment.BytesPointer()[0] |= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveAndIncludingIndex( memorySegment.FirstUsedBitIndexInTheByte() );
                }
                else
                {
                    // The bits needs to be set off

                    // Set off the bits in the first byte
                    memorySegment.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( memorySegment.FirstUsedBitIndexInTheByte() );
                }

                // Nothing else needs to be done
                return;
            }

            // The setting is divided into three :
            //
            //  1. The bits in the first byte
            //  2. The middle part where the bits fill all the bytes
            //  3. The bits in the last byte

            // Check if the bits needs to be on or off
            if ( state == true )
            {
                // The bits needs to be set on

                // Set on the bits in the first byte
                memorySegment.BytesPointer()[0] |= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveAndIncludingIndex( memorySegment.FirstUsedBitIndexInTheByte() );

                // Set the bits in the middle part, which can be handled as full bytes
                Basic< UnsignedInteger8bits >( ( memorySegment.BytesPointer().Part( 1, ( memorySegment.BytesPointer().Size() - 2 ) ) ), ~0 );

                // Set the bits in the last byte on
                memorySegment.BytesPointer()[ memorySegment.BytesPointer().Size() - 1 ] |= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveIndex( memorySegment.LastUsedBitIndexInTheByte() );
            }
            else
            {
                // The bits needs to be set off

                // Set off the bits in the first byte
                memorySegment.BytesPointer()[0] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OffAboveAndIncludingIndex( memorySegment.FirstUsedBitIndexInTheByte() );

                // Set the bits in the middle part, which can be handled as full bytes
                Basic< UnsignedInteger8bits >( ( memorySegment.BytesPointer().Part( 1, ( memorySegment.BytesPointer().Size() - 2 ) ) ), 0 );

                // Set the bits in the last byte off
                memorySegment.BytesPointer()[ memorySegment.BytesPointer().Size() - 1 ] &= DataTypes::OneSideBitsOnOneSideBitsOff< UnsignedInteger8bits >::OnAboveIndex( memorySegment.LastUsedBitIndexInTheByte() ); 
            }

        }








&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&










            // Method Information :
            //
            //  Description :
            //
            //      Use this method to compare a contigous memory segment, that the data is basic types, to another destination
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. firstMemorySegment - a pointer object containing information on the first memory segment to compare
            //          2. secondMemorySegment - a pointer object containing information on the second memory segment to compare
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the 2 memory segments match
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      1. One of the pointer instances is in default state
            //      2. 
            //
            bool Compare::Bits( const DataTypes::BitsPointer firstMemorySegment, const DataTypes::BitsPointer secondMemorySegment )
            {
                // Check that the size of the 2 memory segments match, and if they mismatch returne false
                IF_EXPRESSION_IS_TRUE_RETURN_VALUE( ( firstMemorySegment.Size() != secondMemorySegment.Size() ), false )

                // Check if the size is smaller then 16, this is needed to ensure that if all the bits lay in 1 byte it will take care of it
                if ( firstMemorySegment.Size() <= 16 )
                {
                    // The size of the memory segments is less then 16 bits, then all the bits of a memory segments can be located on 1 byte

                    // Loop on all the bits
                    for ( UnsignedInteger64bits bitIndex = 0 ; bitIndex < firstMemorySegment.Size() ; ++bitIndex )
                    {
                        // Compare the current bit, and if they mismatch, return false
                        IF_EXPRESSION_IS_TRUE_RETURN_VALUE( ( firstMemorySegment[ bitIndex ] != secondMemorySegment[ bitIndex ] ), false )
                    }

                    // If control reached here the memory segments match
                    return ( true );
                }
                // Check if the index of the first used bit in the first byte is equal in both bits pointers
                else if ( firstMemorySegment.FirstUsedBitIndexInTheByte() == secondMemorySegment.FirstUsedBitIndexInTheByte() )
                {
                    // The index of the first used bit in the first byte is equal in both bits pointers

                    // Return the result of comparing the memory segments
                    return ( CompareBitsMemorySegmentsThatStartFromTheSameIndex_IMP( firstMemorySegment, secondMemorySegment ) );
                }

                // Now the 2 bits memory segments start from a different index in the first byte, therefore one of the bits memory segments needs to be copied to match
                // every bit with the corresponding bit from the other bits memory segment

                // Allocate memory space to contain the copy of the bits
                DataTypes::HeapSharedBitsPointer firstMemorySegmentCopy( firstMemorySegment.Size(), secondMemorySegment.FirstUsedBitIndexInTheByte() );

                // Copy the bits of the first memory segment to the new memory space with the required offset to match the bits in the second memory segment
                Memory::Copy::Bits( firstMemorySegment, firstMemorySegmentCopy );

                // Now we got both memory segments start from the same index in the first byte, and they can be compared

                // Return the result of comparing the memory segments
                return ( CompareBitsMemorySegmentsThatStartFromTheSameIndex_IMP( firstMemorySegmentCopy, secondMemorySegment ) );
            }



            // Method Information :
            //
            //  Description :
            //
            //      Use this method to compare a contigous memory segment, that the data is basic types, to another destination. When dealing with bits memory segments 
            //      each segment can start from another index and then each bit that needs to be compared has a different offset. This method only deals with memory
            //      segments that start from the same index, and then all the bits don't have offsets
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. firstMemorySegment - a pointer object containing information on the first memory segment to compare
            //          2. secondMemorySegment - a pointer object containing information on the second memory segment to compare
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. true - if the 2 memory segments match
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      1. One of the pointer instances is in default state
            //      2. 
            //
            bool Compare::CompareBitsMemorySegmentsThatStartFromTheSameIndex_IMP( const DataTypes::BitsPointer firstMemorySegment, const DataTypes::BitsPointer secondMemorySegment )
            {
                // Both memory segments start from the same bit index in the first byte

                // Compare the first byte in the memory segments when the bits that are unused off, and if they mismatch, return false
                IF_EXPRESSION_IS_TRUE_RETURN_VALUE( ( ( firstMemorySegment.BytesPointer()[0] >> firstMemorySegment.FirstUsedBitIndexInTheByte() ) != ( secondMemorySegment.BytesPointer()[0] >> secondMemorySegment.FirstUsedBitIndexInTheByte() ) ), false )
                
                // Now all the bits in the middle bytes can be checked as bytes because the relative location match

                // This object will point to the first memory segment starting from the second byte until one before the last byte
                DataTypes::Pointer< UnsignedInteger8bits > firstMemorySegmentBytesPointer( ( firstMemorySegment.BytesPointer() + 1 ), ( firstMemorySegment.BytesPointer().Size() - 2 ) );
                
                // This object will point to the second memory segment starting from the second byte until one before the last byte
                DataTypes::Pointer< UnsignedInteger8bits > secondMemorySegmentBytesPointer( ( secondMemorySegment.BytesPointer() + 1 ), ( secondMemorySegment.BytesPointer().Size() - 2 ) );

                // Use the compare method for basic types
                IF_EXPRESSION_IS_FALSE_RETURN_VALUE( Basic< UnsignedInteger8bits >( firstMemorySegmentBytesPointer, secondMemorySegmentBytesPointer ), false );

                // Compare the first byte in the memory segments when the bits that are unused off, and if they mismatch, return false
                IF_EXPRESSION_IS_TRUE_RETURN_VALUE( ( ( firstMemorySegment.BytesPointer()[ firstMemorySegment.BytesPointer().Size() - 1 ] << ( 8 - ( firstMemorySegment.LastUsedBitIndexInTheByte() + 1 ) ) ) != ( secondMemorySegment.BytesPointer()[ secondMemorySegment.BytesPointer().Size() - 1 ] << ( 8 - ( secondMemorySegment.LastUsedBitIndexInTheByte() + 1 ) ) ) ), false )
            
                // If control reached here the memory segments match
                return ( true );
            }