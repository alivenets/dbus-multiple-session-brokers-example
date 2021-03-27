# D-Bus service/client example with multiple brokers

This example demonstrates usage of multiple D-Bus session brokers for service and client using sdbus-c++ library.

# HOW TO USE

In docker container, run:

```
mkdir build && cd build && cmake .. && make && sudo make install

source ../run-brokers.sh
# Run services
./dual-bus-service &
# Run client
./dual-bus-client
```
