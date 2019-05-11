void loading() {
  if (!arcDir) {
    arcStart += arcSpeed;
    arcEnd += arcIncr[counter] + arcSpeed;
  } else {
    arcStart += arcIncr[counter] + arcSpeed;
    arcEnd += arcSpeed;
  }
  if (arcStart >= NUM_LEDS) arcStart = (arcStart - NUM_LEDS);
  if (arcEnd >= NUM_LEDS) arcEnd = (arcEnd - NUM_LEDS);

  if (++counter >= INCR_AMOUNT) {
    counter = 0;
    arcDir = !arcDir;
    if (!arcDir) {
      colorCounter += 70;
      thisColor = CHSV(colorCounter, 255, 255);
    }
  }

  if (arcStart < arcEnd) {
    fillArc(arcStart, arcEnd, thisColor, leds);
    fillArc(arcStart, arcEnd, thisColor, leds2);
  } else {
    fillArc(arcStart, NUM_LEDS, thisColor, leds);
    fillArc(arcStart, NUM_LEDS, thisColor, leds2);
    fillArc(0, arcEnd, thisColor, leds);
    fillArc(0, arcEnd, thisColor, leds2);
  }
}
