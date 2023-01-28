#include "logging.hpp"

struct NowDate
{
    char date[16]; //年月日
    char time[16]; //时分秒
    char millis[4];  //毫秒
};

NowDate getTime()
{
    std::time_t timep;
    std::time (&timep);
    NowDate date;

    std::strftime(date.date, sizeof(date.date), "%Y-%m-%d",localtime(&timep) );
    std::strftime(date.time, sizeof(date.time), "%H:%M:%S",localtime(&timep) );

    struct timeb tb;
    ftime(&tb);     
    sprintf(date.millis,"%d",tb.millitm);

    return date;
}


std::ostream &defaultLogStream = std::cout;

std::ostream &fcLog(fcLogType lgType = fcLogType::info)
{
    NowDate time = getTime();

    if(lgType == fcLogType::info)
    {
        return defaultLogStream << "[ " << time.time << " ]" << "[ INFO ]:  ";
    }
    else if(lgType == fcLogType::warn)
    {
        return defaultLogStream << "[ " << time.time << " ]" << "[ WARN ]:  ";
    }
    else if(lgType == fcLogType::error)
    {
        return defaultLogStream << "[ " << time.time << " ]" << "[ ERROR ]: ";
    }
    else if(lgType == fcLogType::fatal)
    {
        return defaultLogStream << "[ " << time.time << " ]" << "[ FATAL ]: ";
    }

    return defaultLogStream;
}