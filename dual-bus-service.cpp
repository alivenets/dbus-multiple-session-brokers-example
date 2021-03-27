#include <memory>
#include <iostream>
#include <thread>

#include "echo-service/echo-service.h"
#include "foo-service/foo-service.h"


int main(void)
{

    std::cout << "1" << std::endl;
    auto connection = sdbus::createSessionBusConnection();
    connection->requestName(echoServiceName);

    std::cout << "2" << std::endl;
    auto connection2 = sdbus::createSessionBusConnectionWithAddress("unix:path=/tmp/custom-session-bus.sock");
    connection2->requestName(fooServiceName);
    EchoService echoService{connection.get()};
    FooService fooService{connection2.get()};

    connection2->enterEventLoopAsync();
    connection->enterEventLoop();

    return 0;
}
