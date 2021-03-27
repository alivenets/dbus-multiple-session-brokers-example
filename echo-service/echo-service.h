#pragma once

#include <sdbus-c++/sdbus-c++.h>

#include <memory>

static const char* echoInterfaceName = "com.example.EchoService";
static const char *echoServiceName = "com.example.EchoService";

class EchoService
{
public:
    EchoService(sdbus::IConnection *conn)
        : m_connection(conn)
    {
        assert(conn != nullptr);

        const char* objectPath = "/com/example/EchoService";
        m_dbusObject = sdbus::createObject(*conn, objectPath);

        m_dbusObject->registerMethod("Echo").onInterface(echoInterfaceName).implementedAs([this](std::string s){return this->echo(s);});
        m_dbusObject->finishRegistration();
    }

    std::string echo(std::string input) {
        auto signal = m_dbusObject->createSignal(echoInterfaceName, "EchoSignal");
        signal << "BOOM!";
        m_dbusObject->emitSignal(signal);
        return "Echo: " + input;
    }
    
private:
    sdbus::IConnection *m_connection;
    std::unique_ptr<sdbus::IObject> m_dbusObject;
};

// TODO: how to link signal FooService::FooSignal and call method EchoService::BarFromFoo ? 