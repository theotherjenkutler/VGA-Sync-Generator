#define HSYNC_PIN 9   // OC1A - Timer1 hardware output
#define VSYNC_PIN 5   // manual vsync toggle in ISR

volatile uint16_t lineCount = 0;

ISR(TIMER1_COMPA_vect) {
  lineCount++;
  
  if (lineCount >= 628) {
    lineCount = 0;
  }
  
  // vsync pulse low for 4 lines per VESA 800x600 spec
  if (lineCount < 4) {
    digitalWrite(VSYNC_PIN, LOW);
  } else {
    digitalWrite(VSYNC_PIN, HIGH);
  }
}

void setup() {
  pinMode(HSYNC_PIN, OUTPUT);
  pinMode(VSYNC_PIN, OUTPUT);

  digitalWrite(HSYNC_PIN, HIGH);
  digitalWrite(VSYNC_PIN, HIGH);

  // Timer1 Fast PWM, ICR1 as TOP, no prescaler
  // 16MHz / 37879Hz = 422.4 counts per period → ICR1 = 421
  // actual frequency: 16000000 / 422 = 37914Hz (0.09% off spec)
  // hsync pulse width: VESA spec = 3.2us → 16MHz * 0.0000032 = 51.2 → OCR1A = 51

  TCCR1A = (1 << COM1A1) | (1 << COM1A0) | (1 << WGM11);
  TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS10);
  // CS10 = no prescaler

  ICR1  = 421;  // period
  OCR1A = 51;   // hsync pulse width ~3.2us

  TIMSK1 = (1 << OCIE1A);

  sei();
}

void loop() {
}