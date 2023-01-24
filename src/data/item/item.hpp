/**
 * @file items.hpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief defines items.
 * @version 0.1
 * @date 2023-01-21
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */


#ifndef items_hpp
#define items_hpp

#include "json/json.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "uuid.hpp"


/**
 * @brief defines item.
 * 
 */
class fcitem
{
    public:
    /**
     * @brief name of current item.
     * 
     */
    Json::String name;
    /**
     * @brief unique identifier for current item.
     * 
     */
    uuid itemUUID;
    /**
     * @brief unique identifier for player has current item.
     * 
     */
    uuid ownerUUID;
    /**
     * @brief UUID of current item type.
     * 
     */
    uuid categoryUUID;
    /**
     * @brief count of item in inventory.
     * 
     */
    unsigned int count;

    /**
     * @brief convert to jsoncpp object.
     * 
     * @return Json::value 
     */
    virtual Json::Value toJson(void) const;
};










#endif