#include <BLE_API.h>

BLE ble;

static String  scale = "5cca8310f88";

void scanCallBack(const Gap::AdvertisementCallbackParams_t *params)
{
  String peerAddr;
  int measunit, measured;

  for (int i = 0; i < 6; i++) {
    peerAddr += String(params->peerAddr[i], HEX);
  }

  if ( peerAddr == scale ) {
    measunit = params->advertisingData[21];
    measured = params->advertisingData[23];
    measured = measured << 8 | params->advertisingData[22];

    if ( measunit == 3 ||  measunit == 179 ) {
      Serial.print(measured * 0.01);
      Serial.println(" Lbs");
    } else if ( measunit == 18 ||  measunit == 178 ) {
      Serial.print(measured * 0.01);
      Serial.println(" Jin");      
    } else if ( measunit == 34 ||  measunit == 162 ) {
      Serial.print(measured * 0.01 / 2);
      Serial.println(" Kg");
    }
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start...");
  ble.init();
  //Note : take care of scheduler, prevent ram leak.See projectconfig.h
  ble.startScan(scanCallBack);
}

void loop()
{
  // put your main code here, to run repeatedly:
  ble.waitForEvent();
}

