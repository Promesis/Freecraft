#include "uuid.hpp"
#include <cctype>
#include <stdexcept>

inline char uitchex(unsigned int i)
{
    switch(i)
    {
        case 0: return '0'; break;
        case 1: return '1'; break;
        case 2: return '2'; break;
        case 3: return '3'; break;
        case 4: return '4'; break;
        case 5: return '5'; break;
        case 6: return '6'; break;
        case 7: return '7'; break;
        case 8: return '8'; break;
        case 9: return '9'; break;
        case 10: return 'a'; break;
        case 11: return 'b'; break;
        case 12: return 'c'; break;
        case 13: return 'd'; break;
        case 14: return 'e'; break;
        case 15: return 'f'; break;
        default: return '\0'; break;
    }
}

inline bool ishexnum(char ch)
{
    char c=tolower(ch);
    return (c=='0' || c=='1' || c=='2' || c=='3' || c=='4' || c=='5' || c=='6' || c=='7' || c=='8' || c=='9' 
         || c=='a' || c=='b' || c=='c' || c=='d' || c=='e' || c=='f');
}

//        +    +    +    +
//xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx\0
//012345678901234567890123456789012345 6
void uuid::setrandomly(void)
{
    std::default_random_engine e;int i=0;
    std::uniform_int_distribution<unsigned int> u(0,15);
    for(i=0; i <= 7; ++i)
        data[i]=uitchex(u(e));
    data[8]='-';
    for(i=9; i <= 12; ++i)
        data[i]=uitchex(u(e));
    data[13]='-';
    for(i=14; i <= 17; ++i)
        data[i]=uitchex(u(e));
    data[18]='-';
    for(i=19; i <= 22; ++i)
        data[i]=uitchex(u(e));
    data[23]='-';
    for(i=24; i <= 35; ++i)
        data[i]=uitchex(u(e));
    data[36]='\0';
}

uuid::uuid(void)
{
    for(int i=0; i < 37; ++i)
        data[i]=0;
}

uuid::uuid(const uuid &dat)
{
    for(int i=0; i < 37; ++i)
        data[i]=dat.data[i];
}

inline bool checksyntax(const Json::String &str)
{
    if(str.length() != 36)
        return false;
    for(i=0; i <= 7; ++i)
        if(!ishexnum(str[i]))
            return false;
    if(str[8]!='-') return false;
    for(i=9; i <= 12; ++i)
        if(!ishexnum(str[i]))
            return false;
    if(str[13]!='-') return false;
    for(i=14; i <= 17; ++i)
        if(!ishexnum(str[i]))
            return false;
    if(str[18]!='-') return false;
    for(i=19; i <= 22; ++i)
        if(!ishexnum(str[i]))
            return false;
    if(str[23]!='-') return false;
    for(i=24; i <= 35; ++i)
        if(!ishexnum(str[i]))
            return false;
    return true;
}

uuid::uuid(const Json::String &str)
{
    if(!checksyntax(str))
        throw fcSyntaxException("UUID format is not wanted");
    data = str;
}

uuid::operator Json::String(void) const
{
    return Json::String(data);
}

bool uuid::operator==(const uuid &dat) const
{
    return dat.data == data;
}

bool operator==(const Json::String &datL, const uuid &datR)
{
    return datR.data == datL;
}

uuid::operator=(const uuid &dat)
{
    data = dat.data;
}