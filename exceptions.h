/*!
*    @file    MyHeaderFile.h
*    @brief   Brief header file description
*    @author  MHPC
*    @date    2015.1.~27
*/ 

/**
* This class is the base class for all exception classes. Do not use
* its methods and variables directly since the interface and
* mechanism may be subject to change.
*/

namespace StandardExceptions
{
/**
* Exception denoting a division by zero.
*
* @note Unfortunately, automatic detection of division by zero is very
* hardware dependent and requires severe hacking on some architectures.
* Therefore, this exception is only raised if the test is performed
* explicitly.
*/

DeclException0 (ExcDivideByZero);

/**
* Exception raised if a number is not finite.
*
* This exception should be used to catch infinite or not a number
* results of arithmetic operations that do not result from a division by
* zero (use ExcDivideByZero for those).
*/
DeclException0 (ExcNumberNotFinite);

/**
* Trying to allocate a new object failed due to lack of free memory.
*/
DeclException0 (ExcIO);

/**
* An error occurred opening the named file.
*
* The constructor takes a single argument of type <tt>char*</tt>
* naming the file.
*/
DeclException0 (ExcNotImplemented);

/**
* This exception usually indicates that some condition which the
* programmer thinks must be satisfied at a certain point in an algorithm,
* is not fulfilled. This might be due to some programming error above,
* due to changes to the algorithm that did not preserve this assertion,
* or due to assumptions the programmer made that are not valid at all
* (i.e. the exception is thrown although there is no error here). Within
* the library, this exception is most often used when we write some kind
* of complicated algorithm and are not yet sure whether we got it right;
* we then put in assertions after each part of the algorithm that check
* for some conditions that should hold there, and throw an exception
* if they do not.
*
* We usually leave in these assertions even after we are confident
* that the implementation is correct, since if someone later changes
* or extends the algorithm, these exceptions will indicate to him if he
* violates assumptions that are used later in the algorithm. Furthermore,
* it sometimes happens that an algorithm does not work in very rare
* corner cases. These cases will then be trapped sooner or later by the
* exception, so that the algorithm can then be fixed for these cases
* as well.
*/
DeclException0 (ExcNotInitialized);

/**
* The object is in a state not suitable for this operation.
*/
DeclException0 (ExcNeedsLAPACK);

/**
* This function requires support for the NetCDF library.
*/
}