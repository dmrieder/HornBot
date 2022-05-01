#include <TinyGPS.h>

/* This sample code demonstrates the normal use of a TinyGPS object.
   It requires the use of SoftwareSerial, and assumes that you have a
   4800-baud serial GPS device hooked up on pins 3(rx) and 4(tx).
*/

TinyGPS gps;

static void gpsdump(TinyGPS &gps);
static bool feedgps();
static void print_float(float val, float invalid, int len, int prec);
static void print_int(unsigned long val, unsigned long invalid, int len);
static void print_date(TinyGPS &gps);
static void print_str(const char *str, int len);

void setup()
{
  Serial.begin(9600);
  Serial3.begin(4800);
  
}

void loop()
{
  bool newdata = false;
  unsigned long start = millis();
  
  // Every second we print an update
  while (millis() - start < 1000)
  {
    if (feedgps())
      newdata = true;
  }
  
  gpsdump(gps);
}

static void gpsdump(TinyGPS &gps)
{
  float flat, flon;
  unsigned long age, date, time, chars = 0;
  unsigned short sentences = 0, failed = 0;
  static const float LONDON_LAT = 51.508131, LONDON_LON = -0.128002;
  
  gps.f_get_position(&flat, &flon, &age);
  
  print_float(flat, TinyGPS::GPS_INVALID_F_ANGLE, 9, 5);
  Serial.print(";");
  print_float(flon, TinyGPS::GPS_INVALID_F_ANGLE, 10, 5);
  Serial.print(";");
  print_float(gps.f_speed_kmph(), TinyGPS::GPS_INVALID_F_SPEED, 6, 2);
  Serial.print(";");
  print_float(gps.f_altitude(), TinyGPS::GPS_INVALID_F_ALTITUDE, 8, 2);
  Serial.println("");
  gps.stats(&chars, &sentences, &failed);

}

static void print_float(float val, float invalid, int len, int prec)
{
  char sz[32];
  if (val == invalid)
  {
    strcpy(sz, "*");
    sz[len] = 0;
        if (len > 0) 
          sz[len-1] = ' ';
    for (int i=7; i<len; ++i)
        sz[i] = ' ';
    Serial.print(sz);
  }
  else
  {
    Serial.print(val,prec);
    int vi = abs((int)val);
    int flen = prec + (val < 0.0 ? 2 : 1);
    flen += vi >= 1000 ? 4 : vi >= 100 ? 3 : vi >= 10 ? 2 : 1;
    for (int i=flen; i<len; ++i)
      Serial.print("");
  }
  feedgps();
}

static bool feedgps()
{
  while (Serial3.available())
  {
    if (gps.encode(Serial3.read()))
      return true;
  }
  return false;
}
