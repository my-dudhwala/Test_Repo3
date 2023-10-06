### Random Data
### SUCCESS!  
I have succefully managed to get 1625 Strings of 512 Bytes(approx.), means data of 1625 Strings X 512 Bytes = 832000 Bytes = 832KB  
   1. The folder above named 13_Strings_64000_Bytes, contains 13 Text files (.txt), each file containes 125 Strings of 512 Bytes.  
   2. The folder also contains 2 code tested on ESP32 4MB.  
      2.1 One code fetches all of the file data and writes on SPIFFS.  
      2.2 The second code is to verify all of the files on SPIFF Storage. The code shows all of the file on the SPIFFS, then it reads data of all the files one by one.  
   3. The link URL in the main code points it in the same directory, means just you have to change the wifi name and password, then it will fetch all of the file contents placed here.  
   4. If you want to change contents of the file, (Obviuosly this is a test only, to check if everything is fine or not), the main goal is to syncronise data with more then 1 ESP32 devices (Like attendence data).  

#### Warning : Do not focus on the file names...

1. You can download this files for your experiments, I have an experiment of downloading text file and parsing the data.
2. The python script is to generate random data,  
   2.1 You can specify character need to be used, I wanted hex so placed 1 to f,  
   2.2 You can change "1500" number to get number of coma seperated strings,  
   2.3 You can change size of a string in bytes, it is 512 currently...
