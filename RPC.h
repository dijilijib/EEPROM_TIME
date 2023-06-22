#include "RPC.h"

#define ENCRYPTED false
constexpr const char RPC_SWITCH_METHOD[] PROGMEM = "example_set_switch";
constexpr const char RPC_SWITCH_KEY[] PROGMEM = "switch";
constexpr const char RPC_RESPONSE_KEY[] PROGMEM = "example_response";

class RPC {
public:
    RPC();
    void loop();

private:
    WiFiClient espClient;
    ThingsBoard tb;
    bool subscribed;
    RPC_Response processSwitchChange(const RPC_Data &data);
};

#endif //RPC_H
