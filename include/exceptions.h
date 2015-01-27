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
* Used for constructors that are disabled. Examples are copy
* constructors and assignment operators of large objects, which are
* only allowed for empty objects.
*/
	DeclException0 (ExcInvalidConstructorCall);
}

/**
* Special assertion for index range of nonnegative indices.
*
* Since this is used very often and always repeats the arguments, we
* introduce this special assertion for ExcIndexRange in order
* to keep the user codes shorter.
*/
AssertIndexRange(index,range)
