#include <TFT_eFEX.h>
#include <NTPClient.h>
// change next line to use with another board/shield
//#include <ESP8266WiFi.h>
#include <WiFi.h> // for WiFi shield
//#include <WiFi101.h> // for WiFi 101 shield or MKR1000
#include <WiFiUdp.h>
#include <TFT_eSPI.h> // Graphics and font library for ST7735 driver chip
#include <SPI.h>
#include <math.h>


TFT_eSPI tft = TFT_eSPI();  // Invoke library, pins defined in User_Setup.h

TFT_eFEX  fex = TFT_eFEX(&tft);    // Create TFT_eFEX object "fex" with pointer to "tft" object

TFT_eSprite spr = TFT_eSprite(&tft); // Sprite object


const char *ssid     = "<SSID>";
const char *password = "<PASSWORD>";

WiFiUDP ntpUDP;

// You can specify the time server pool and the offset (in seconds, can be
// changed later with setTimeOffset() ). Additionaly you can specify the
// update interval (in milliseconds, can be changed using setUpdateInterval() ).
NTPClient timeClient(ntpUDP, "north-america.pool.ntp.org", -25200, 60000);

  byte xcolon = 0;
  byte ogMinute = 99;

void setup(){
  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);

  tft.setTextColor(TFT_CYAN, TFT_BLACK); // Note: the new fonts do not draw the background colour

  WiFi.begin(ssid, password);

  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }

  timeClient.begin();
}

void loop() {
  int xw = tft.width()/2;
  int yh = tft.height();
  int hour = timeClient.getHours();
  byte hour1 = 0;
  byte hour2 = 0;
  int minute = timeClient.getMinutes();
  byte minute1 = 0;
  byte minute2 = 0;
  byte second = timeClient.getSeconds();
  String AMorPM = "am";
  timeClient.update();

  Serial.println(timeClient.getFormattedTime());
  
  if(ogMinute != minute){
    if (hour > 12){
      hour = hour - 12;
      AMorPM = "pm";
    }else if (hour == 0){
      hour = 12;
    }

    if (hour < 10){
      hour1 = 0;
      hour2 = hour;
    }else{
      hour2 = hour % 10;
      hour1 = (hour - hour2)/10;
    }
  
    if (minute < 10){
      minute1 = 0;
      minute2 = minute;
    }else{
      minute2 = minute % 10;
      minute1 = (minute - minute2)/10;
    }
  
    tft.fillCircle(xw, yh, 110, TFT_BLACK);
  
    tft.setPivot(xw, yh + 30);
  
    spr.createSprite(40, 60);     // Create a new Sprite 40x60
    spr.setPivot(20,130);         // Set Sprite pivot at 20,130
  
    spr.setTextColor(TFT_CYAN);    // Cyan text in Sprite
    spr.setTextDatum(MC_DATUM);   // Middle centre datum
  
    spr.fillSprite(TFT_BLACK);  // Clear the Sprite
    if (hour1 == 1){
      spr.drawNumber(hour1, 20, 30, 6);    // Plot number, in Sprite at 20,30 and with font 6
      spr.pushRotated(-36, TFT_BLACK); // Plot rotated Sprite, black being transparent
    }
    spr.fillSprite(TFT_BLACK);  
    spr.drawNumber(hour2, 20, 30, 6);
    spr.pushRotated(-19, TFT_BLACK);
    spr.fillSprite(TFT_BLACK);   
    spr.drawNumber(minute1, 20, 30, 6);
    spr.pushRotated(4, TFT_BLACK);
    spr.fillSprite(TFT_BLACK);  
    spr.drawNumber(minute2, 20, 30, 6);
    spr.pushRotated(21, TFT_BLACK);
    spr.fillSprite(TFT_BLACK);  
    spr.drawString(AMorPM, 20, 30, 4);
    spr.pushRotated(39, TFT_BLACK);
  
    spr.deleteSprite();
  }

  spr.deleteSprite();
  
  spr.createSprite(40, 60);
  spr.setPivot(25,145);

  spr.setTextColor(TFT_CYAN);
  spr.setTextDatum(MC_DATUM);

  spr.fillSprite(TFT_BLACK);
  if (second % 2){
    spr.setTextColor(TFT_CYAN);
    spr.drawChar(':', 20, 20, 6);
  }else{
    spr.setTextColor(0x0861);
    spr.drawChar(':', 20, 20, 6);
  }
  spr.pushRotated(-9, TFT_BLACK);

  ogMinute = minute;

  delay(1000);
}
