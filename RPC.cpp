#include "RPC.h"

RPC::RPC()
    : tb(espClient, MAX_MESSAGE_SIZE),
    subscribed(false)
{
}

void RPC::loop() {
  if (!subscribed) {
    Serial.println("Subscribing for RPC...");
    if (!tb.RPC_Subscribe(callbacks.cbegin(), callbacks.cend())) {
      Serial.println("Failed to subscribe for RPC");
      return;
    }

    Serial.println("Subscribe done");
    subscribed = true;
  }

  tb.loop();
}

RPC_Response RPC::processSwitchChange(const RPC_Data &data) {
  Serial.println("Received the set switch method");
  const bool switch_state = data[RPC_SWITCH_KEY];
  Serial.print("Example switch state: ");
  Serial.println(switch_state);

  StaticJsonDocument<JSON_OBJECT_SIZE(1)> doc;
  doc[RPC_RESPONSE_KEY] = 22.02;
  return RPC_Response(doc);
}

const std::array<RPC_Callback, 2U> RPC::callbacks = {
  RPC_Callback{ RPC_SWITCH_METHOD, processSwitchChange }
};
