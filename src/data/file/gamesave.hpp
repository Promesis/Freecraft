/**
 * @file gamesave.hpp
 * @author Promesis (m3149154722@outlook.com)
 * @brief deal with filesystem.
 * @version 0.1
 * @date 2023-01-24
 * 
 * Promesis 2023
 * the Freecraft dev
 * 
 */
ifndef gamesave_hpp
#define gamesave_hpp

#include <filesystem>
#include <string>
#include <cstdlib>
#include <fstream>

enum struct fcGamesaveMode
{
    binary,
    json
};

struct gamesave
{
    fcGamesaveMode filemode;
    std::filesystem::path worldInfoFile;
    std::filesystem::path playerDataDirectory;
    std::filesystem::path chunksFilesDirectory;
};



#endif