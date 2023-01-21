#ifndef items_hpp
#define items_hpp

#include "json/json.h"

/**
 * @brief defines items data structure. 
 * @author Promesis
 */

#include <string>

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
    Json::String uuid;
    /**
     * @brief unique identifier for player has current item.
     * 
     */
    Json::String playerUUID;
    /**
     * @brief UUID of current item type.
     * 
     */
    char itemTypeUUID [16];

    public:
    /**
     * @brief count of item in inventory.
     * 
     */
    unsigned int cnt;


}










#endif