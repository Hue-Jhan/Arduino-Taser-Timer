#include <RH_ASK.h>
#include <SPI.h> 
 
RH_ASK rf_driver;
 
void setup() {
    rf_driver.init();
}
 
void loop() {
    const char *msg = "PORCODDIO";
    rf_driver.send((uint8_t *)msg, strlen(msg));
    rf_driver.waitPacketSent();
    delay(1000);
}

/* on the reciever u can put a simple function like:

if *msg = "xxx" 
    digitalwrite(xxx,1)

in order to activate a relay, or u can use a servo or a transistor or anything
*/
