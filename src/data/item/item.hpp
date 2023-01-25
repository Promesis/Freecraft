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


#ifndef item_hpp
#define item_hpp

#include "json/json.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <string>

#include "../uuid/uuid.hpp"
// #include "../structure/list.hpp"






/**
 * @brief defines item.
 * 
 */
class fcitem
{
    protected:
    /**
     * @brief name of current item.
     * 
     */
    std::string name;
    /**
     * @brief namespace ID for current item.
     * 
     */
    std::string itemID;
    /**
     * @brief namespace ID of current item type.
     * 
     */
    std::string categoryID;
    /**
     * @brief count of item in inventory.
     * 
     */
    unsigned int count;
    /**
     * @brief is this item unbreakable?
     * 
     */
    bool unbreakable;
    /**
     * @brief slot of item.
     * 
     */
    unsigned int slot;//TODO : edit it when completed inventory part
    /**
     * @brief tags of item.
     * 
     */
    Json::Value tags;

    public:

    /**
     * @brief convert to jsoncpp object.
     * 
     * @return Json::value 
     */
    virtual Json::Value toJson(void) const;
};










#endif