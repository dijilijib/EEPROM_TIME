#include "KittyServer.h"

KittyServer ks;

void setup() {
  Serial.begin(115200);
  ks.setup();
}

void loop() {
  ks.handleClient();
  // Add your additional code here
}
