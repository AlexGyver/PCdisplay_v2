void parsing() {
  if (onlineFlag && millis() - timeoutTimer > TIMEOUT) {
    onlineFlag = false;
  }
  
  while (Serial.available() > 0) {
    char aChar = Serial.read();
    if (aChar != 'E') {
      inData[index] = aChar;
      index++;
      inData[index] = '\0';
    } else {
      char *p = inData;
      char *str;
      index = 0;
      String value = "";
      while ((str = strtok_r(p, ";", &p)) != NULL) {
        string_convert = str;
        PCdata[index] = string_convert.toInt();
        index++;
      }
      index = 0;
      timeoutTimer = millis();
      onlineFlag = true;
    }
  }
}

/*
  Содержимое массива PCdata
  0-CPU temp,
  1-GPU temp,
  2-mother temp,
  3-max HDD temp,
  4-CPU load,
  5-GPU load,
  6-RAM use,
  7-GPU memory use,
  8-maxFAN,
  9-minFAN,
  10-maxTEMP,
  11-minTEMP,
  12-manualFAN,
  13-manualCOLOR,
  14-fanCtrl,
  15-colorCtrl,
  16-brightCtrl,
  17-LOGinterval,
  18-tempSource
*/
