cmake_minimum_required ( VERSION 3.15 )

project ( Freecraft )

set ( PRJ_SRC_LIST )    #all sources in the project
set ( PRJ_LIBRARIES )   #all libraries in the project
set ( PRJ_INCLUDE_DIRS )#all headers in the project


file ( GLOB_RECURSE root_header_files "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.hpp" )
file ( GLOB_RECURSE root_src_files "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.c" )


set ( INCLUDES "${PROJECT_SOURCE_DIR}/include/" )
set ( GLFW_LIB "${PROJECT_SOURCE_DIR}/lib/glfw3.dll" )          #GLFW library
set ( JSONCPP_LIB "${PROJECT_SOURCE_DIR}/lib/libjsoncpp.dll")   #jsoncpp library


#######PROJECT INCLUDE DIR
list ( APPEND PRJ_INCLUDE_DIRS ${PROJECT_SOURCE_DIR} )
list ( APPEND PRJ_INCLUDE_DIRS ${INCLUDES} )
list ( APPEND PRJ_INCLUDE_DIRS ${PROJECT_SOURCE_DIR}/src/)

#######custom appends header files we need
list ( APPEND PRJ_SRC_LIST ${root_src_files} )

#######custom appends libraries we need
list ( APPEND PRJ_LIBRARIES ${GLFW_LIB} )
list ( APPEND PRJ_LIBRARIES ${JSONCPP_LIB} )

add_executable ( ${PROJECT_NAME} ${PRJ_SRC_LIST} )

#includes
target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
    ${PRJ_INCLUDE_DIRS}
)

#libraries
target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
    ${PRJ_LIBRARIES}
)
