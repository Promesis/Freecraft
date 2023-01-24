#ifndef uuid_hpp
#define uuid_hpp

#include "json/json.h"
#include "../../fcexceptions.hpp"

#include <string>
#include <random>

//xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
class uuid
{
    protected:
    char data[37];
    public:
    /**
     * @brief set uuid randomly.
     * 
     */
    void setrandomly(void);
    /**
     * @brief Construct a new uuid object.
     * 
     */
    uuid(void);
    /**
     * @brief Construct a new uuid object.
     * 
     * @param dat
     */
    uuid(const uuid &dat);
    /**
     * @brief Construct a new uuid object.
     * 
     * @param str 
     */
    uuid(const Json::String &str);
    /**
     * @brief assignment operator overloading.
     * 
     * @param dat uuid to assign.
     * @return const uuid& 
     */
    const uuid &operator=(const uuid &dat);
    /**
     * @brief check if two uuids is equal.
     * 
     * @param dat 
     * @return true equal.
     * @return false not equal.
     */
    bool operator==(const uuid &dat) const;
    /**
     * @brief same. reversed.
     * 
     * @param dat 
     * @param dat 
     * @return true 
     * @return false 
     */
    friend bool operator==(const Json::String &datL, const uuid &datR);
    
    //const Json::String &getuuid(void) const;
    /**
     * @brief conversation function.
     * 
     */
    operator Json::String(void) const;
};

bool operator==(const Json::String &datL, const uuid &datR);

#endif