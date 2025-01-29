namespace Universe
{

    namespace Abilities
    {



// This macro should be used add in objects that deal with numeric types as data members. This will make the object appear as the data
// itself, with all the operators C++ had to offer for each numeric type. This includes the following operations :
//
//      Arithmetic operators :
//
//          1. Addition ->  +
//          2. Subtraction ->  -
//          3. Multiplication ->  *
//          4. Division ->  /
//          5. Modulo ->  %
//          6. Pre increment by 1 ->  ++
//          7. Post increment by 1 ->  ++
//          8. Pre decrement by 1 ->  --
//          9. Post decrement by 1 ->  --
//
//      Arithmetic and Assignment operators :
//
//          10. Assignment ->  =
//          11. Addition and assignment ->  +=
//          12. Subtraction and assignment ->  -=
//          13. Multiplication and assignment ->  *=
//          14. Division and assignment ->  /=
//          15. Modulo and assignment ->  %=
//          16. Bitwise AND and assignment ->  &=
//          17. Bitwise OR and assignment ->  |=
//          18. Bitwise XOR and assignment ->  ^=
//          19. Bitwise left shift and assignment ->  <<=
//          20. Bitwise right shift and assignment ->  >>=
//
//      Relational operators :
//
//          21. Equal to ->  ==
//          22. Not equal to ->  !=
//          23. Greater than ->  >
//          24. Less then ->  <
//          25. Greater than or equal to ->  >=
//          26. Less than or equal to ->  <=
//
//      Logical operators :
//
//          27. Logical AND ->  &&
//          28. Logical OR ->  ||
//          29. Logical NOT ->  !
//
//      Bitwise operators :
//
//          30. Bitwise AND ->  &
//          31. Bitwise OR ->  |
//          32. Bitwise XOR ->  ^
//          33. Bitwise left shift ->  <<
//          34. Bitwise right shift ->  >>
//
// The required arguments are :
//
//      1. MemberName - the member name that the operators should act on
//      2. MemberNumericType - the numeric type of the member
//
#define AddAllOperatorsToObject( MemberName, MemberNumericType, ActionToExecuteInOperatorsThatDoNotChangeTheInstance, ActionToExecuteInOperatorsThatChangeTheInstance )       \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator+( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName + rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator+( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName + rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator-( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName - rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator-( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName - rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator*( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName * rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator*( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName * rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator/( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName / rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator/( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName / rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator%( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName % rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator++()                                                                                                                                                   \
    {                                                                                                                                                                               \
        ++MemberName;                                                                                                                                                               \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    friend inline SelfType operator++( SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        SelfType copyOfRightSideOperand( rightSideOperand );                                                                                                                        \
                                                                                                                                                                                    \
        rightSideOperand.MemberName++;                                                                                                                                              \
                                                                                                                                                                                    \
        return ( copyOfRightSideOperand );                                                                                                                                          \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator--()                                                                                                                                                   \
    {                                                                                                                                                                               \
        --MemberName;                                                                                                                                                               \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    friend inline SelfType operator--( SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        SelfType copyOfRightSideOperand( rightSideOperand );                                                                                                                        \
                                                                                                                                                                                    \
        rightSideOperand.MemberName--;                                                                                                                                              \
                                                                                                                                                                                    \
        return ( copyOfRightSideOperand );                                                                                                                                          \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator%( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName % rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator=( MemberNumericType rightSideOperand )                                                                                                                \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName = rightSideOperand;                                                                                                                                              \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator+=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName += rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator+=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName += rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator-=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName -= rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator-=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName -= rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator*=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName *= rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator*=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName *= rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator/=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName /= rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator/=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName /= rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator%=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName %= rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator%=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName %= rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator<<=( MemberNumericType rightSideOperand )                                                                                                              \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName <<= rightSideOperand;                                                                                                                                            \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator<<=( const SelfType& rightSideOperand )                                                                                                                \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName <<= rightSideOperand.MemberName;                                                                                                                                 \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator>>=( MemberNumericType rightSideOperand )                                                                                                              \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName >>= rightSideOperand;                                                                                                                                            \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator>>=( const SelfType& rightSideOperand )                                                                                                                \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName >>= rightSideOperand.MemberName;                                                                                                                                 \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator&=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName &= rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator&=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName &= rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator|=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName |= rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator|=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName |= rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator^=( MemberNumericType rightSideOperand )                                                                                                               \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName ^= rightSideOperand;                                                                                                                                             \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline SelfType& operator^=( const SelfType& rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatChangeTheInstance                                                                                                                             \
                                                                                                                                                                                    \
        MemberName ^= rightSideOperand.MemberName;                                                                                                                                  \
                                                                                                                                                                                    \
        return ( *this );                                                                                                                                                           \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator==( MemberNumericType rightSideOperand )                                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName == rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator!=( MemberNumericType rightSideOperand ) const                                                                                                           \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName != rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator>( MemberNumericType rightSideOperand ) const                                                                                                            \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName > rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator>( const SelfType& rightSideOperand ) const                                                                                                              \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName > rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator <( MemberNumericType rightSideOperand ) const                                                                                                           \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName < rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator <( const SelfType& rightSideOperand ) const                                                                                                             \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName < rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator>=( MemberNumericType rightSideOperand ) const                                                                                                           \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName >= rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator>=( const SelfType& rightSideOperand ) const                                                                                                             \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName >= rightSideOperand.MemberName );                                                                                                                       \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator<=( MemberNumericType rightSideOperand ) const                                                                                                           \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName <= rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator<=( const SelfType& rightSideOperand ) const                                                                                                             \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName <= rightSideOperand.MemberName );                                                                                                                       \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator&&( MemberNumericType rightSideOperand ) const                                                                                                           \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName && rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator&&( const SelfType& rightSideOperand ) const                                                                                                             \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName && rightSideOperand.MemberName );                                                                                                                       \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator||( MemberNumericType rightSideOperand ) const                                                                                                           \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName || rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline Boolean operator||( const SelfType& rightSideOperand ) const                                                                                                             \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName || rightSideOperand.MemberName );                                                                                                                       \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
    //                                                                                                                                                                                 \
    // friend inline Boolean operator!( const SelfType& rightSideOperand )                                                                                                             \
    // {                                                                                                                                                                               \
    //     ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
    //                                                                                                                                                                                 \
    //     return ( !rightSideOperand.MemberName );                                                                                                                                    \
    // }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator&( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName & rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator&( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName & rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator|( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName | rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator|( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName | rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator^( MemberNumericType rightSideOperand ) const                                                                                                  \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName ^ rightSideOperand );                                                                                                                                   \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator^( const SelfType& rightSideOperand ) const                                                                                                    \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName ^ rightSideOperand.MemberName );                                                                                                                        \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator<<( MemberNumericType rightSideOperand ) const                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName << rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator<<( const SelfType& rightSideOperand ) const                                                                                                   \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName << rightSideOperand.MemberName );                                                                                                                       \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator>>( MemberNumericType rightSideOperand ) const                                                                                                 \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName >> rightSideOperand );                                                                                                                                  \
    }                                                                                                                                                                               \
                                                                                                                                                                                    \
                                                                                                                                                                                    \
    inline MemberNumericType operator>>( const SelfType& rightSideOperand ) const                                                                                                   \
    {                                                                                                                                                                               \
        ActionToExecuteInOperatorsThatDoNotChangeTheInstance                                                                                                                        \
                                                                                                                                                                                    \
        return ( MemberName >> rightSideOperand.MemberName );                                                                                                                       \
    }



    }  //  Namespace Abilities

}  //  Namespace Universe