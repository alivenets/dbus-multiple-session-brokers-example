#pragma once

#include <sdbus-c++/sdbus-c++.h>

#include <memory>

static const char* fooInterfaceName = "com.example.FooService";
static const char *fooServiceName = "com.example.FooService";

class FooService
{
public:
    FooService(sdbus::IConnection *conn)
        : m_connection(conn)
    {
        assert(conn != nullptr);

        const char* objectPath = "/com/example/FooService";
        m_dbusObject = sdbus::createObject(*conn, objectPath);

        m_dbusObject->registerMethod("EmitFoo").onInterface(fooInterfaceName).implementedAs([this](){std::cout << "Emit Foo signal" << std::endl; m_dbusObject->emitSignal("FooSignal").onInterface(fooInterfaceName).withArguments((uint32_t)42);});
        m_dbusObject->registerSignal(fooInterfaceName, "FooSignal", "i");

        m_dbusObject->finishRegistration();
    }
private:
    sdbus::IConnection *m_connection;
    std::unique_ptr<sdbus::IObject> m_dbusObject;
};
