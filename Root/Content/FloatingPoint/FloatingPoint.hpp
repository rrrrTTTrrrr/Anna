




# 							                                             Floating Point - this file is used to describe the floating point arithmetics











// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\
// *                                                                                                                                                                                                * \\
// *                                                                                          FLOATING POINT                                                                                        * \\
// *                                                                                                                                                                                                * \\
// ************************************************************************************************************************************************************************************************** \\
// ************************************************************************************************************************************************************************************************** \\




// ************************************************************************************************************************************************************************************************** \\
// *                                                                                          ROUNDING ERROR                                                                                        * \\
// ************************************************************************************************************************************************************************************************** \\



  // Squeezing infinitely many real numbers into a finite number of bits requires an approximate representation. Although there are infinitely many integers,
  // in most programs the result of integer computations can be stored in 32 bits. In contrast, given any fixed number of bits, most calculations with real
  // numbers will produce quantities that cannot be exactly represented using that many bits. Therefore, the result of a floating point calculation must often
  // be rounded in order to fit back into its finite representation. The resulting rounding error is the characteristic feature of floating point computation.
  //
  // Since most floating point calculations have rounding error anyway, does it matter if the basic arithmetic operations introduce a bit more rounding error
  // than necessary? this is a main question through the discussion!!



// ************************************************************************************************************************************************************************************************** \\
// *                                                                                      FLOATING POINT FORMATS                                                                                    * \\
// ************************************************************************************************************************************************************************************************** \\



  // Several different representations of real numbers have been proposed, but by far the most widely used is the floating point representation. Floating point
  // representations have a base, which is always assumed to be even, and a precision. If :
  //
  //    Base = 10   AND   Precision = 3
  //
  // The number 0.1 is represented as :
  //
  //    1.00 * 10 ^ -1
  //
  // If :
  //
  //    Base = 2   AND   Precision = 24
  //
  // The decimal number 0.1 cannot be represented exactly but is approximately :
  //
  //    1.10011001100110011001101 * 2 ^ -4
  //
  // In general, a floating point number will be represented as :
  //
  //    +- d.dddd...d * Base ^ Exponent
  //
  // Where the d's part is called the significand and has p digits. More precisely :
  //
  //    +- d'0'.d'1'd'2'...d'Precision-1' * Base ^ Exponent
  //
  // Represents the number :
  //
  //    +- ( d'0' + d'1 * Base ^ -1 + ... + d'Precision-1' * Base ^ -(Precision-1) ) * Base ^ Exponent    FOR 0 < d'i' < Base
  //
  // The term floating point number will be used to mean a real number that can be exactly represented in the format under discussion. Two other parameters
  // associated with floating point representations are the largest and smallest allowable exponents. Since there are the base power the precision possible
  // significands and a limit number of exponents, a floating point number cab be encoded in :
  //
  //    [ log2( Maximum Exponent - Minimum Exponent + 1 ) ] + [ log2( Base ^ Precision ) ] + 1
  //
  // bits, where the final addition of one is for the sign bit.
  //
  //
  // There are two reasons why a real number might not be exactly representable as a floating point number. The most common situation is illustrated by the
  // decimal number 0.1. Although it has a finite decimal representation, in binary it has an infinite repeating representation. Thus, when the base is 2,
  // the number 0.1 lies strictly between two floating point numbers and is exactly representable by neither of them. A less common situation is that a real
  // number is out of range, that is :
  //
  //    Base * Base ^ Maximal Exponent < Number   OR    1.0 * Base ^ Minimal Exponent > Number
  //
  //
  // Floating point representations are not necessarily unique. For example :
  //
  //    0.01 * 10 ^ 1     AND     1.00 * 10 ^ -1     Both represents - 0.1
  //
  // If the leading digit is nonzero, the representation is said to be normalized. The floating point number
  //
  //
