/*
  Скетч к проекту "Моддинг ПК с LED и Arduino"
  Страница проекта (схемы, описания): https://alexgyver.ru/PCdisplay_v2/
  Исходники на GitHub: https://github.com/AlexGyver/PCdisplay_v2
  Нравится, как написан и закомментирован код? Поддержи автора! https://alexgyver.ru/support_alex/
  Автор: AlexGyver Technologies, 2018
  http://AlexGyver.ru/
*/

/*
  Анимация
  - Цветная полоса
    - Левая половина: температура ЦП/ГП, цвет жёлтый-красный от минимума к максимуму
    - Правая половина: загрузка ЦП/ГП, цвет зелёный-синий от минимума к максимуму
  - Огонь
    - Левая половина: температура ЦП/ГП, красное пламя
    - Правая половина: загрузка ЦП/ГП, синее пламя
*/

// ************* НАСТРОЙКИ **************
#define CP_MODE 0       // режим анимации ЦП: 0 - цветная полоса, 1 - огонь
#define GP_MODE 1       // режим анимации ГП: 0 - цветная полоса, 1 - огонь
#define TIMEOUT 5000    // таймаут соединения, мс

// температура
#define CP_TEMP_MIN 35
#define CP_TEMP_MAX 60
#define GP_TEMP_MIN 35
#define GP_TEMP_MAX 60

// яркость
#define MIN_BRIGHTNESS 3
#define MAX_BRIGHTNESS 100
#define MIN_PHOTO 40
#define MAX_PHOTO 700

// лента
#define NUM_LEDS 40
#define LED_PIN 6       // диоды ГП
#define LED2_PIN 7      // диоды ЦП

// другое
#define AUTO_BRIGHT 1   // вкл/выкл автоуправление яркостью. Если выкл, яркость будет установлена в MIN_BRIGHTNESS!
#define PHOTO_PIN A0

// --------- ДЛЯ РАЗРАБОТЧИКОВ ---------

#include <FastLED.h>
CRGB leds[NUM_LEDS];    // диоды ЦП
CRGB leds2[NUM_LEDS];   // диоды ГП
CRGBPalette16 gPal;

#include "timerMinim.h"
timerMinim effTimer(80);
timerMinim brightTimer(200);

float senFil;
float tempCP, loadCP, tempGP, loadGP;

// загрузка
int8_t arcStart, arcEnd = 1;
byte arcSpeed = 1;
boolean arcDir;
byte arcIncr[] = {3, 10, 5, 4, 3, 3, 2, 2, 1, 1, 1, 1};   // сумма не более NUM LEDS
#define INCR_AMOUNT 12
byte counter;
byte colorCounter;
CRGB thisColor;

// парсинг
boolean onlineFlag;
uint32_t timeoutTimer;
char inData[82];       // массив входных значений (СИМВОЛЫ)
int PCdata[20];        // массив численных значений показаний с компьютера
byte index = 0;
String string_convert;

void setup() {
  Serial.begin(9600);
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.addLeds<WS2811, LED2_PIN, GRB>(leds2, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(MIN_BRIGHTNESS);
  FastLED.show();
}

void loop() {
  parsing();

  if (effTimer.isReady()) {
    FastLED.clear();
    if (onlineFlag) {
      if (CP_MODE) fireCP();
      else lineCP();

      if (GP_MODE) fireGP();
      else lineGP();
    }
    else loading();
    FastLED.show();
  }

  if (AUTO_BRIGHT && brightTimer.isReady()) {
    senFil += (analogRead(PHOTO_PIN) - senFil) * 0.2;   // фильтр
    int thisBrightness = map((int)senFil, MIN_PHOTO, MAX_PHOTO, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
    thisBrightness = constrain(thisBrightness, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
    FastLED.setBrightness(thisBrightness);
  }
}

void fillArc(byte startPos, byte endPos, CRGB color, CRGB *leds) {
  for (byte i = startPos; i < endPos; i++) {
    leds[i] = color;
  }
}
