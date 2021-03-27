cmake_minimum_required(VERSION 3.12)

project(dbus-example-multiple-session-brokers)

set(CMAKE_CXX_STANDARD 17)

find_package(sdbus-c++ REQUIRED)

add_executable(dual-bus-service dual-bus-service.cpp)
target_link_libraries(dual-bus-service PRIVATE SDBusCpp::sdbus-c++)

add_executable(dual-bus-client dual-bus-client.cpp)
target_link_libraries(dual-bus-client PRIVATE SDBusCpp::sdbus-c++)

# install(FILES com.example.EchoService.xml DESTINATION /etc/dbus-1/session.d)
# install(FILES com.example.FooService.xml DESTINATION /etc/dbus-1/session.d)