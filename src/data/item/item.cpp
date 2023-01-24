/**
 * @file items.cpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief implements items.hpp
 * @version 0.1
 * @date 2023-01-21
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */

#include "items.hpp"

Json::Value fcitem::toJson(void) const
{
    Json::Value retVal;
    retVal["name"]=name;
    retVal["itemUUID"]=itemUUID.data;
    retVal["ownerUUID"]=ownerUUID.data;
    retVal["categoryUUID"]=categoryUUID.data;
    retVal["count"]=count;
}