dbus-daemon --session  --address=unix:path=/tmp/session-bus.sock --fork
dbus-daemon --session --address=unix:path=/tmp/custom-session-bus.sock --fork

# Set default session bus address
export DBUS_SESSION_BUS_ADDRESS=unix:path=/tmp/session-bus.sock