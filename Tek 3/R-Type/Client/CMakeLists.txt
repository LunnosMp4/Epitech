cmake_minimum_required(VERSION 3.22)

SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(r-type_client)

add_compile_definitions(_WIN32_WINNT=0x0601)

file(GLOB_RECURSE SRC_TEMP "../*.cpp")
set(SRC "")
foreach(FILE ${SRC_TEMP})
    string(FIND ${FILE} "/build/" BUILD_POSITION)
    string(FIND ${FILE} "/Server/" SERVER_POSITION)
    string(FIND ${FILE} "/libs/" LIBS_POSITION)
    string(FIND ${FILE} "/Bonus/" BONUS_POSITION)
    if(BUILD_POSITION EQUAL -1 AND SERVER_POSITION EQUAL -1 AND LIBS_POSITION EQUAL -1 AND BONUS_POSITION EQUAL -1)
        list(APPEND SRC ${FILE})
    endif()
endforeach()

find_package(asio REQUIRED)
find_package(raylib REQUIRED)

add_executable(r-type_client ${SRC} ${ENGINE_SRC})

target_link_libraries(r-type_client PRIVATE asio::asio raylib)

add_custom_target(clean_files_project
        COMMAND ${CMAKE_COMMAND} -P clean.cmake
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_command(TARGET r-type_client POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E remove $<TARGET_FILE_DIR:r-type_client>/*~
        COMMAND ${CMAKE_COMMAND} -E remove ${CMAKE_CURRENT_BINARY_DIR}/*~
        COMMAND ${CMAKE_COMMAND} -E copy_directory "${CMAKE_SOURCE_DIR}/assets" $<TARGET_FILE_DIR:r-type_client>/assets
)

add_custom_target(clean_project
        COMMAND ${CMAKE_COMMAND} -P clean.cmake
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/clean.cmake
        "file(REMOVE_RECURSE \"${CMAKE_BINARY_DIR}/*\")"
)
