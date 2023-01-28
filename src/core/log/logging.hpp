/**
 * @file logging.hpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief defines ostream loggings.
 * @version 00.01b01-dev
 * @date 2023-01-25
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#ifndef logging_hpp
#define logging_hpp


#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ostream>
#include <chrono>
#include <ctime>

///@brief log types.
enum struct fcLogType
{
    info,
    warn,
    error,
    fatal
};

/**
 * @brief log to default log file.
 * 
 * @param lgType type of logging. can be set to fcLogType::info for normal logging, fcLogType::warn for warning, fcLogType::error for error warning, fcLogType::fatal for fatal error warning.
 * @return std::ostream& 
 */
std::ostream &fcLog(fcLogType lgType);
///@brief default logging. normal logging.
#define flog fcLog(fcLogType::info)
///@brief warning logging.
#define fwrn fcLog(fcLogType::warn)
///@brief error logging.
#define ferr fcLog(fcLogType::error)
///@brief fatal error logging.
#define fftl fcLog(fcLogType::fatal)

#define fcendl std::endl;


#endif