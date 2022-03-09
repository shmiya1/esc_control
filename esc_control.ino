int i;
unsigned long timer_1, timer_2, timer_3, timer_4, current_time;
unsigned long timer_channel_1;
unsigned long loop_timer,esc_loop_timer;
void setup() {
  // put your setup code here, to run once:
  DDRD |= B11110000;                                                        //Configure digital poort 4, 5, 6 and 7 as output.
  loop_timer = micros();
}

void loop() {
  // put your main code here, to run repeatedly:
  while(micros() - loop_timer < 4000);
  
  loop_timer = micros();
  PORTD |= B11110000;
  timer_channel_1 = 800 + loop_timer;
  
  while(PORTD >= 16){
    esc_loop_timer = micros();
    if(timer_channel_1 <= esc_loop_timer)PORTD &= B00001111;
  }
}
