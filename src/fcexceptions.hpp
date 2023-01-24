#ifndef fcexceptions_hpp
#define fcexceptions_hpp

#include <exception>
#include "fcenums.hpp"

typedef std::exception fcexception;

class fcRuntimeException : public fcexception
{
    private:
    const char *why;

    public:
    fcRuntimeException(const char *whyException = "runtime exception occured") : why(whyException);
    const char *what();
};

class fcRuntimeError : public fcexception
{
    private:
    const char *why;

    public:
    fcRuntimeError(const char *whyError = "runtime error occured") : why(whyError);

    const char *what();
};





class fcCalcException : public fcRuntimeException
{
    public:
    fcCalcException(const char *whyException = "calculation gets errors") : fcRuntimeError(whyException);
};

class fcDivisionZeroException : public fcCalcException
{
    public:
    fcCalcException(const char *whyException = "calculation get errors when dividing a num with zero") : fcCalcException(whyException);
};

class fcSyntaxException : public fcRuntimeException
{
    public:
    fcSyntaxException(const char *whyException = "the syntax isn't right") : fcRuntimeException(whyException);
};

class fcArrayIndexOutOfBoundsException : public fcRuntimeException
{
    public:
    fcArrayIndexOutOfBoundsException(const char *whyException = "the array index is out of bound.") : fcRuntimeException(whyException);
};

#endif