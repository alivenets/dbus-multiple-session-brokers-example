#include <memory>
#include <iostream>
#include <thread>

#include "echo-service/echo-service.h"
#include "foo-service/foo-service.h"


int main(void)
{
    auto connection = sdbus::createSessionBusConnection();
    auto connection2 = sdbus::createSessionBusConnectionWithAddress("unix:path=/tmp/custom-session-bus.sock");

    auto proxy = sdbus::createProxy(std::move(connection), echoServiceName, "/com/example/EchoService");

    auto proxy2 = sdbus::createProxy(std::move(connection2), fooServiceName, "/com/example/FooService");


    auto method = proxy->createMethodCall("com.example.EchoService", "Echo");
    method << "Hello";
    auto reply = proxy->callMethod(method);
    std::string result;
    reply >> result;
    std::cout << result << std::endl;

    auto method2 = proxy2->createMethodCall("com.example.FooService", "EmitFoo");
    auto reply2 = proxy2->callMethod(method);

    return 0;
}
