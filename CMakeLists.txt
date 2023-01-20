cmake_minimum_required(VERSION 3.12)
#cmake_cxx_standard_required()
project(Freecraft)

include_directories(${PROJECT_SOURCE_DIR}/include/)
link_directories(${PROJECT_SOURCE_DIR}/lib/)
file(GLOB libraries CONFIGURE_DEPENDS *.dll *.a)

aux_source_directory(${PROJECT_SOURCE_DIR}/src/ srcDir)
add_executable(Freecraft ${srcDir})

target_link_libraries(Freecraft ${libraries})