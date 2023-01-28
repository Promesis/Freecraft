/**
 * @file uuid.cpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief 
 * @version 00.01b01-dev
 * @date 2023-01-27
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#include "uuid.hpp"
//xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx

//moved from 00.01a07-dbg
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


inline bool isHexChar(char c)
{
    char ch=std::isalpha(c)? std::tolower(c) : c;
    switch(ch)
    {
        case 'a':   case 'b':   case 'c':   case 'd':   case 'e':   case 'f':
        case '0':   case '1':   case '2':   case '3':   case '4':   case '5':
        case '6':   case '7':   case '8':   case '9': 
        {
            return true;
            break;
        }
        default:
        {
            return false;
            break;
        }
    }
}

//cast
inline bool ishexnum(char c)
{
    return isHexChar(c);
}

//moved from 00.01a07-dbg
inline bool checksyntax(const std::string &str)
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

fcUUID::fcUUID(void)
{
    data_="00000000000000000000000000000000";
}

fcUUID::fcUUID(const std::string &data)
{
    if(!checksyntax(data))
    {
        ferr << "UUID grammar isn't right" << fcendl;
        return;
    }
    for(int i = 0; i < 8; ++i)
        data_[i] = data[i];
    for(int i = 8; i < 12; ++i)
        data_[i] = data[i+1];
    for(int i = 12; i < 16; ++i)
        data_[i] = data[i+2];
    for(int i = 16; i < 20; ++i)
        data_[i] = data[i+3];
    for(int i = 20; i < 24; ++i)
        data_[i] = data[i+4];
    for(int i = 24; i < 28; ++i)
        data_[i] = data[i+5];
    for(int i = 28; i < 32; ++i)
        data_[i] = data[i+6];
}

const fcUUID & newUUID( void )
{
    std::default_random_engine eng;
    std::uniform_int_distribution< unsigned int > uni(0,15);
    fcUUID retVal;
    for(int i = 0; i < 32; ++i)
    {
        retVal.data_[i] = uitchex( uni( eng ) );
    }
}