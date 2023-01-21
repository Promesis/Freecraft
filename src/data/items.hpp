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


/**
 * @brief defines item.
 * 
 */
class fcitems
{
    protected:
    /**
     * @brief unique identifier for current item.
     * 
     */
    Json::String UUID;
    /**
     * @brief unique identifier for player has current item.
     * 
     */
    Json::String ownerUUID;
    /**
     * @brief UUID of current item type.
     * 
     */
    Json::String itemTypeUUID;



    public:
    /**
     * @brief count of item in inventory.
     * 
     */
    unsigned int cnt;
    /**
     * @brief get UUID of object.
     * 
     * @return const Json::String& 
     */
    virtual const Json::String &getUUID(void) const;
    /**
     * @brief Get the Owner UUID of object.
     * 
     * @return const Json::String& 
     */
    virtual const Json::String &getOwnerUUID(void) const;
    /**
     * @brief Get the Item Type UUID of object.
     * 
     * @return const Json::String& 
     */
    virtual const Json::String &getItemTypeUUID(void) const;
    /**
     * @brief Get the Item Name of object.
     * 
     * @return const Json::String& 
     */
    virtual const Json::String &getItemName(void) const;
    /**
     * @brief convert to jsoncpp object.
     * 
     * @return Json::value 
     */
    virtual Json::Value toJson(void) const;

};










#endif