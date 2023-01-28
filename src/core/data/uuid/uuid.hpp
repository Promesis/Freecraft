/**
 * @file uuid.hpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief universal unique identifier
 * @version 00.01b01-dev
 * @date 2023-01-25
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#ifndef uuid_hpp
#define uuid_hpp

#include <string>
#include <random>
#include <cctype>
#include <stdexcept>

class fcUUID
{
    private:
    char data_[33];

    public:
    fcUUID(void);
    fcUUID(const std::string &data);
    // fcUUID(uint16_t p1, uint16_t p2, uint16_t p3, uint16_t p4, uint16_t p5, uint16_t p6, uint16_t p7, uint16_t p8);

    operator std::string(void) const;
    virtual ~fcUUID(void);
    friend const fcUUID &newUUID( void );
};

const fcUUID &newUUID( void );

#endif