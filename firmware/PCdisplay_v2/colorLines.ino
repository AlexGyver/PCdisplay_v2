#define COEF 0.2    // плавность движения полосы

void lineCP() {
  // переводим температуру от мин-макс в диапазон 0-(половина кольца)
  int thisTemp = map(PCdata[0], CP_TEMP_MIN, CP_TEMP_MAX, 0, NUM_LEDS / 2);

  // ограничиваем диапазон
  thisTemp = constrain(thisTemp, 0, NUM_LEDS / 2);

  // фильтруем running average
  tempCP += (thisTemp - tempCP) * COEF;

  // заливаем дугу
  fillArc(0, ceil(tempCP), CHSV(map((int)tempCP, 0, NUM_LEDS / 2, 65, 0), 255, 255), leds);

  // переводим загрузку от 0-100 в диапазон 0-(половина кольца)
  int thisLoad = map(PCdata[4], 0, 100, 0, NUM_LEDS / 2);

  // фильтруем
  loadCP += (thisLoad - loadCP) * COEF;

  // заливаем дугу
  fillArc(NUM_LEDS - 1 - (int)loadCP, NUM_LEDS, CHSV(map((int)loadCP, 0, NUM_LEDS / 2, 85, 140), 255, 255), leds);
}

// тут тож самое, только для ГП
void lineGP() {
  int thisTemp = map(PCdata[1], CP_TEMP_MIN, CP_TEMP_MAX, 0, NUM_LEDS / 2);
  thisTemp = constrain(thisTemp, 0, NUM_LEDS / 2);
  tempGP += (thisTemp - tempGP) * COEF;
  fillArc(0, ceil(tempGP), CHSV(map((int)tempGP, 0, NUM_LEDS / 2, 65, 0), 255, 255), leds2);

  int thisLoad = map(PCdata[5], 0, 100, 0, NUM_LEDS / 2);
  loadGP += (thisLoad - loadGP) * COEF;
  fillArc(NUM_LEDS - 1 - (int)loadGP, NUM_LEDS, CHSV(map((int)loadGP, 0, NUM_LEDS / 2, 85, 140), 255, 255), leds2);
}
