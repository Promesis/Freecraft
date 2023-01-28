/**
 * @file fcDataFile.hpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief this file defines a base class for binary data saving and recognization.
 * @version 00.01b01-dev
 * @date 2023-01-25
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#ifndef fcdatafile_hpp
#define fcdatafile_hpp

#include <fstream>
#include <string>

class fcDataFile
{
    protected:
    std::string fileType;
    public:
    fcDataFile(void);
    virtual getFileType(void);
};

#endif