void setup() {
  // put your setup code here, to run once:

}

void ringBells (int nRings, boolean thirty) {
  int i;
  for (i = 1; i <= nRings;  i++) {
    myDFPlayer.play(1);  //Play 2 bells
    delay (1500);
  }
  if (thirty) myDFPlayer.play(2);  //Play 1 bell
  hasRun = true;
}

void loop() {

  //Give s/w time to settle down
  if ( Minute == 5 || Minute == 35 ) hasRun = false;

  Hour = ( clock.getHour (h12Flag, pmFlag));
  Minute = ( clock.getMinute) ();
  Second = (clock.getSecond)();

  if ( Minute == 5 || Minute == 35 ) //Give s/w time to settle down
  {
    hasRun = false;
  }
  if ( Second % 60 == 0 ) //Even minute
    if ( Minute == 30) Thirty = true;
    else
      Thirty = false;
  if (Second == 0) {
    if ( Minute == 0 || Thirty) {
      if (!hasRun) {
        Serial.println( Hour );
        Hour = ( clock.getHour (h12Flag, pmFlag));
        Bells = Hour % 4;
        // Determine number of bells to ring depending on the value of Hour:
        switch (Bells) {
          case 0:    // 12:00, 4:00, 8:00
            if ( !Thirty) {
              ringBells ( 4, Thirty);
            }
            else {
              ringBells ( 0, Thirty);
            }
            break;
          case 1:    // 1:00, 5:00, 9:00
            ringBells (1, Thirty);
            break;
          case 2:    // 2:00, 6:00, 10:00
            ringBells (2, Thirty);
            break;
          case 3:    // 3:00, 7:00, 11:00
            ringBells (3, Thirty);
            break;
        }
      }
    }
  }
}
