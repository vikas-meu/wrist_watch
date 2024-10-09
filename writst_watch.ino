#Created by : vikas singh Thakur 
#date : 12/3/24 

# use at ur own risk 

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <WiFi.h>
#include "time.h"
#include "esp_sntp.h"

// OLED display settings
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// Wi-Fi and NTP settings
const char *ssid = "vipi";
const char *password = "12345678vipi";
const char *ntpServer1 = "pool.ntp.org";
const char *ntpServer2 = "time.nist.gov";
const long gmtOffset_sec = 19800; // IST is GMT+5:30, so 5 hours 30 minutes = 19800 seconds
const int daylightOffset_sec = 0; // No daylight saving time adjustment

// Callback function for time synchronization
void timeavailable(struct timeval *t) {
  Serial.println("Got time adjustment from NTP!");
}

void setup() {
  Serial.begin(115200);

  // Initialize OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
  
  display.display();
  delay(2000);
  display.clearDisplay();

  // Display name
   
  display.clearDisplay();

  // Display name
  display.setTextSize(2); // Larger text for name
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(2, 9); // Start at top-left corner
  display.println("chapple");
  display.display();
  delay(1000); // Show name for 2 seconds
  display.setTextSize(4); // Larger text for name
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(100, 2); // Start at top-left corner
  display.println("X");
  display.display();
  delay(3000); // Show name for 2 seconds

  display.clearDisplay();

  // Display name
  display.setTextSize(1); // Larger text for name
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 10); // Start at top-left corner
  display.println("designed By.");
  display.display();
  delay(2000); // Show name for 2 seconds

  display.clearDisplay();
  display.setTextSize(2); // Larger text for name
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0); // Start at top-left corner
  display.println("Vikas.");
  display.display();
  delay(2000); // Show name for 2 seconds
 
 
  // Connect to Wi-Fi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println(" CONNECTED");

  // Set up NTP and timezone
  sntp_set_time_sync_notification_cb(timeavailable);
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer1, ntpServer2);
}

void loop() {
  // Get current time
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("No time available (yet)");
    return;
  }
  
  // Print time to Serial Monitor
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");

  // Display time on OLED
  display.clearDisplay();
  display.setTextSize(2); // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text
  display.setCursor(0, 0); // Start at top-left corner
  display.printf("%02d/%02d/%04d\n", timeinfo.tm_mday, timeinfo.tm_mon + 1, timeinfo.tm_year + 1900); // Date
  display.printf("%02d:%02d:%02d", timeinfo.tm_hour, timeinfo.tm_min, timeinfo.tm_sec); // Time
  display.display();

  delay(5000); // Update every 5 seconds
}
