// FUNCOES DO LED
void ConfigLEDS() {
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
}

void liga_red() {
  desliga_leds();
  for(int i=0; i<9; i++){
      leds[i] = CRGB::Green;
      FastLED.show();
    }
  luz_azul=false;

}

void liga_green() {
  desliga_leds();
  for(int i=0; i<9; i++){
    leds[i] = CRGB::Red;
    FastLED.show();
  }
  luz_azul=false;

}

void liga_blue() {
  desliga_leds();
  for(int i=0; i<9; i++){
    leds[i] = CRGB::Blue;
    FastLED.show();
  }
  luz_azul=true;
}

void liga_yellow() {
  desliga_leds();
  for(int i=0; i<9; i++){
    leds[i] = CRGB::Yellow;
    FastLED.show();
    delay(50);
  }
  luz_azul=false;

}

void desliga_leds() {
  for(int i=0; i<9; i++){
    leds[i] = CRGB::Black;
    FastLED.show();
  }
}