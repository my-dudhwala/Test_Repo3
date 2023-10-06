// This code is originally created to test files written by different code, the main code gets data from GitHub and writes to SPIFFS.  
// HAVE A LOOK AT GIVEN GitHub dir.  
//https://github.com/my-dudhwala/Test_Repo3/tree/main/Random_data/13_Strings_64000_Bytes  

#include "FS.h"
#include "SPIFFS.h"

/* You only need to format SPIFFS the first time you run a
   test or else use the SPIFFS plugin to create a partition
   https://github.com/me-no-dev/arduino-esp32fs-plugin */
#define FORMAT_SPIFFS_IF_FAILED true

void listDir(fs::FS &fs, const char * dirname, uint8_t levels) {
  Serial.println("");
  Serial.printf("Listing directory: %s\r\n", dirname);

  File root = fs.open(dirname);
  if (!root) {
    Serial.println("- failed to open directory");
    return;
  }
  if (!root.isDirectory()) {
    Serial.println(" - not a directory");
    return;
  }

  File file = root.openNextFile();
  while (file) {
    if (file.isDirectory()) {
      Serial.print("  DIR : ");
      Serial.println(file.name());
      if (levels) {
        listDir(fs, file.path(), levels - 1);
      }
    } else {
      Serial.print("  FILE: ");
      Serial.print(file.name());
      Serial.print("\tSIZE: ");
      Serial.println(file.size());
    }
    file = root.openNextFile();
  }
}

void readFile(fs::FS &fs, const char * path) {
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if (!file || file.isDirectory()) {
    Serial.println("- failed to open file for reading");
    return;
  }

  Serial.println("- read from file:");
  while (file.available()) {
    Serial.write(file.read());
  }
  file.close();
}

void setup() {
  Serial.begin(115200);
  if (!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)) {
    Serial.println("SPIFFS Mount Failed");
    return;
  }
  Serial.println("");
  Serial.println("");

  listDir(SPIFFS, "/", 0);
  readFile(SPIFFS, "/String1.txt");
  readFile(SPIFFS, "/String2.txt");
  readFile(SPIFFS, "/String3.txt");
  readFile(SPIFFS, "/String4.txt");
  readFile(SPIFFS, "/String5.txt");
  readFile(SPIFFS, "/String6.txt");
  readFile(SPIFFS, "/String7.txt");
  readFile(SPIFFS, "/String8.txt");
  readFile(SPIFFS, "/String9.txt");
  readFile(SPIFFS, "/String10.txt");
  readFile(SPIFFS, "/String11.txt");
  readFile(SPIFFS, "/String12.txt");
  readFile(SPIFFS, "/String13.txt");
}

void loop() {

}
