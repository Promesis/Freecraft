cmake_minimum_required ( VERSION 3.15 )

project ( Freecraft )

set ( PRJ_SRC_LIST )    #all sources in the project
set ( PRJ_LIBRARIES )   #all libraries in the project
set ( PRJ_INCLUDE_DIRS )#all headers in the project

#set ( GLFW "d:/software/GLFW3" )

file ( GLOB_RECURSE root_header_files "${PROJECT_SOURCE_DIR}/src/*.h" "${PROJECT_SOURCE_DIR}/src/*.hpp" )
file ( GLOB_RECURSE root_src_files "${PROJECT_SOURCE_DIR}/src/*.cpp" "${PROJECT_SOURCE_DIR}/src/*.c" )


set ( GL_INC "${PROJECT_SOURCE_DIR}/include/" )
set ( GLFW_LIB "${PROJECT_SOURCE_DIR}/lib/glfw3.dll" )

list ( APPEND PRJ_INCLUDE_DIRS . )
list ( APPEND PRJ_INCLUDE_DIRS ${GL_INC} )
#list ( APPEND PRJ_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include/glad/" )
#list ( APPEND PRJ_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/include/KHR" )

list ( APPEND PRJ_SRC_LIST ${root_src_files} )
list ( APPEND PRJ_LIBRARIES ${GLFW_LIB} )


add_executable ( ${PROJECT_NAME} ${PRJ_SRC_LIST} )

target_include_directories ( ${PROJECT_NAME}
	PRIVATE 
    ${PRJ_INCLUDE_DIRS}
)

target_link_libraries ( ${PROJECT_NAME} 
    PRIVATE 
    ${PRJ_LIBRARIES}
)
