cmake_minimum_required(VERSION 3.20)


if(DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(bulk_server VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else()
    project(bulk_server VERSION 0.0.1)
endif()

find_package(Boost COMPONENTS COMPONENTS program_options system REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(NETWORK
    network/session.cpp
    network/session.hpp
    network/data_handler.cpp
    network/data_handler.hpp
    network/server.cpp
    network/server.hpp)

set(UTILS
    utils/command_parser.cpp
    utils/command_parser.hpp)

# set(INTERFACES
#     src/include/interfaces/command.h
#     src/include/interfaces/processor.h
#     src/include/interfaces/reader.h
#     src/include/interfaces/writer.h)

# set(HEADERS ${INTERFACES}
#     src/include/implementation/dummy_command.h
#     src/include/implementation/dummy_command_processor.h
#     src/include/implementation/stream_reader.h
#     src/include/implementation/console_writer.h
#     src/include/implementation/file_writer.h
#     src/include/implementation/common_command_buffer.h
#     src/include/implementation/global_state.h

#     src/include/network/server.h
#     src/include/network/session.h
#     src/include/network/raw_data_handler.h

#     src/include/utils/thread_pool.h
#     src/include/utils/utils.h)

# set(SOURCES
#     src/logic/implementation/command.cpp
#     src/logic/implementation/dummy_command.cpp
#     src/logic/implementation/dummy_command_processor.cpp
#     src/logic/implementation/stream_reader.cpp
#     src/logic/implementation/console_writer.cpp
#     src/logic/implementation/file_writer.cpp
#     src/logic/implementation/common_command_buffer.cpp
#     src/logic/implementation/global_state.cpp

#     src/logic/network/server.cpp
#     src/logic/network/session.cpp
#     src/logic/network/raw_data_handler.cpp

#     src/utils/thread_pool.cpp
#     src/utils/utils.cpp)

add_executable(bulk_server main.cpp ${NETWORK} ${UTILS})

# set_target_properties(bulk_server PROPERTIES
#     CXX_STANDARD 17
#     CXX_STANDARD_REQUIRED ON
#     CXX_EXTENSIONS OFF
# )

# target_include_directories(bulk_server PRIVATE "${CMAKE_BINARY_DIR}" "src/include")
# target_link_libraries(bulk_server PRIVATE Boost::program_options Boost::system pthread stdc++fs)

# if(MSVC)
#     target_compile_options(bulk_server PRIVATE
#         /W4
#     )
# else()
#     target_compile_options(bulk_server PRIVATE
#         -Werror -Wall -Wimplicit-fallthrough -pedantic-errors
#     )
# endif()

# install(TARGETS bulk_server DESTINATION bin)

# set(CPACK_GENERATOR DEB)

# set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
# set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
# set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

# set(CPACK_PACKAGE_CONTACT example@example.com)

# include(CPack)
