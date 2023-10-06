// This code fetches data of all of the files placed in the folder pointed by the link placed below, a small description is also placed there,  
// The total data size is 832000 Bytes = 832 KB.  
// There are 13 files, and all the file containes 125 count of 512 Bytes Strings.  
// https://github.com/my-dudhwala/Test_Repo3/tree/main/Random_data/13_Strings_64000_Bytes.  

#include <WiFi.h>
#include <HTTPClient.h>
#include <SPIFFS.h>

const char* ssid = "R&D Web";
const char* password = "123456789";
const char* githubRawBaseURL = "https://raw.githubusercontent.com/my-dudhwala/Test_Repo3/main/Random_data/13_Strings_64000_Bytes";//(/String1.txt)
const char* spiffsBasePath = "/String1.txt";

// Define an array of file names on GitHub
const char* githubFiles[] = {"/String1.txt", "/String2.txt", "/String3.txt", "/String4.txt", "/String5.txt", "/String6.txt", "/String7.txt", "/String8.txt", "/String9.txt", "/String10.txt", "/String11.txt", "/String12.txt", "/String13.txt"};
const int numFiles = sizeof(githubFiles) / sizeof(githubFiles[0]);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize SPIFFS
  if (!SPIFFS.begin(true)) {
    Serial.println("SPIFFS initialization failed!");
    return;
  }

  // Loop through the array of GitHub files and fetch each one
  for (int i = 0; i < numFiles; i++) {
    String githubURL = String(githubRawBaseURL) + String(githubFiles[i]);
    String spiffsFilePath = githubFiles[i];

    // Fetch data from GitHub
    HTTPClient http;
    http.begin(githubURL);
    int httpCode = http.GET();
    if (httpCode == HTTP_CODE_OK) {
      File file = SPIFFS.open(spiffsFilePath, FILE_WRITE);
      if (!file) {
        Serial.println("Failed to open SPIFFS file for writing");
      } else {
        String payload = http.getString();
        for (char c : payload) {
          file.write(c);
        }
        file.close();
        Serial.print("Data written to SPIFFS file: ");
        Serial.println(spiffsFilePath);
        delay(50);
      }
    } else {
      Serial.println("Failed to fetch data from GitHub: " + githubURL);
      Serial.println("Retrying...........");
      i--;
    }
    http.end();
    delay(50);
  }
}

void loop() {
  // Your main code here
}
