// ****************************** ОГОНЬ ******************************
#define COOLING  55
// SPARKING: What chance (out of 255) is there that a new spark will be lit?
// Higher chance = more roaring fire.  Lower chance = more flickery fire.
// Default 120, suggested range 50-200.
#define SPARKING 120
#define FIRE_HEIGHT 20

void fireCP() {
  random16_add_entropy(random());

  // расчёт длины полосы от температуры ЦП
  int thisTemp = map(PCdata[0], CP_TEMP_MIN, CP_TEMP_MAX, 0, NUM_LEDS / 2);
  thisTemp = constrain(thisTemp, 0, NUM_LEDS / 2);
  FireRED_CP(thisTemp);

  // расчёт длины полосы от нагрузки ЦП
  FireBLUE_CP(map(PCdata[4], 0, 100, 0, NUM_LEDS / 2));
}
void fireGP() {
  random16_add_entropy(random());

  // расчёт длины полосы от температуры ГП
  int thisTemp = map(PCdata[1], GP_TEMP_MIN, GP_TEMP_MAX, 0, NUM_LEDS / 2);
  thisTemp = constrain(thisTemp, 0, NUM_LEDS / 2);
  FireRED_GP(thisTemp);

  // расчёт длины полосы от нагрузки ГП
  FireBLUE_GP(map(PCdata[5], 0, 100, 0, NUM_LEDS / 2));
}

void FireBLUE_CP(byte height) {
  byte startPos = NUM_LEDS - height;
  gPal = CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White);

  // Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < height; i++) {
    heat[i] = qsub8(heat[i],  random8(0, ((COOLING * 10) / height) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = height - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < height; j++) {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    int pixelnumber;
    pixelnumber = (height - 1) - j;
    leds[startPos + pixelnumber] = color; // в обратном направлении начиная с конца пламени
  }
}
void FireRED_CP(byte height) {
  gPal = HeatColors_p;

  // Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < height; i++) {
    heat[i] = qsub8(heat[i],  random8(0, ((COOLING * 10) / height) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = height - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < height; j++) {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    leds[j] = color;      // в прямом направлении начиная с 0 (начала ленты)
  }
}


void FireBLUE_GP(byte height) {
  byte startPos = NUM_LEDS - height;
  gPal = CRGBPalette16(CRGB::Black, CRGB::Blue, CRGB::Aqua, CRGB::White);

  // Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < height; i++) {
    heat[i] = qsub8(heat[i],  random8(0, ((COOLING * 10) / height) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = height - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < height; j++) {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    int pixelnumber;
    pixelnumber = (height - 1) - j;
    leds2[startPos + pixelnumber] = color;
  }
}
void FireRED_GP(byte height) {
  gPal = HeatColors_p;

  // Array of temperature readings at each simulation cell
  static byte heat[NUM_LEDS];

  // Step 1.  Cool down every cell a little
  for ( int i = 0; i < height; i++) {
    heat[i] = qsub8(heat[i],  random8(0, ((COOLING * 10) / height) + 2));
  }

  // Step 2.  Heat from each cell drifts 'up' and diffuses a little
  for ( int k = height - 1; k >= 2; k--) {
    heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2] ) / 3;
  }

  // Step 3.  Randomly ignite new 'sparks' of heat near the bottom
  if ( random8() < SPARKING ) {
    int y = random8(7);
    heat[y] = qadd8(heat[y], random8(160, 255) );
  }

  // Step 4.  Map from heat cells to LED colors
  for ( int j = 0; j < height; j++) {
    // Scale the heat value from 0-255 down to 0-240
    // for best results with color palettes.
    byte colorindex = scale8(heat[j], 240);
    CRGB color = ColorFromPalette(gPal, colorindex);
    leds2[j] = color;
  }
}
