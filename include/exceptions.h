/*!
*    @file    MyHeaderFile.h
*    @brief   Brief header file description
*    @author  MHPC
*    @date    2015.1.~27
*/ 
#include <exception>
/**
* This class is the base class for all exception classes. Do not use
* its methods and variables directly since the interface and
* mechanism may be subject to change.
*/
#define DeclException0(Exception0)  class Exception0 :  public std::exception {}


#define DeclException3(Exception3, type1, type2, type3, outsequence)      \
  class Exception3 : public std::exception {				\
  public:                                                                 \
    Exception3 (const type1 a1, const type2 a2, const type3 a3) :         \
      arg1 (a1), arg2(a2), arg3(a3) {}                                    \
    virtual ~Exception3 () throw () {}                                    \
    virtual void print_info (std::ostream &out) const {                   \
      out outsequence << std::endl;                                       \
    }                                                                     \
  private:                                                                \
    const type1 arg1;                                                     \
    const type2 arg2;                                                     \
    const type3 arg3;                                                     \
  }

/**
* Special assertion for index range of nonnegative indices.
*
* Since this is used very often and always repeats the arguments, we
* introduce this special assertion for ExcIndexRange in order
* to keep the user codes shorter.
*/

#ifdef DEBUG
#define Assert(cond, exc)                                                   \
  {                                                                           \
    if (!(cond))                                                              \
      std::exit(0);
  }
#else
#define Assert(cond, exc)                                                   \
  {}
#endif

#define AssertIndexRange(index,range) Assert((index) < (range), ExcIndexRange((index),0,(range))) {}


namespace StandardExceptions
{
/**
* Used for constructors that are disabled. Examples are copy
* constructors and assignment operators of large objects, which are
* only allowed for empty objects.
*/
	DeclException0 (ExcInvalidConstructorCall);
}

