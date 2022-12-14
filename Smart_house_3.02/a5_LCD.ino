//--------вывод на экран---------
void lcd_imagin () {
  {PERIOD(1000)  { analogWrite ( LCD_BRIGHTNESS , map( analogRead (PHOTO_SENSOR) , 1023 , 200, 0 , 255)); }}
  
  if ( last_mode_menu != mode_menu)             //если сменился режим 
  {
    LCD.clear();    
   
  }
  
  switch(mode_menu) 
  {
    case (MAIN_LCD) :
    LCD.setCursor(0, 0);    time_show ();
    LCD.setCursor(0, 1);    alarm_clock_show();
    LCD.setCursor(0, 2);    temperature_show ( FULL_STRING );
    LCD.setCursor(0, 3);   
    break;
    
    case (MENU) :
    static bool flag_return;
    static uint32_t timer;
    if (last_mode_menu != mode_menu ) flag_return = true;     //если первый запуск 
    if (flag_return && millis() - timer >= 800) 
    { 
      timer = millis();
      flag_return = !flag_return;
      LCD.clear();
      LCD.setCursor(0, 0);    LCD.print( "temperature");
      LCD.setCursor(0, 1);    LCD.print( "mode house");
      LCD.setCursor(0, 2);    LCD.print( "alarm clock");
      LCD.setCursor(0, 3);    LCD.print( "- - - ");
    }
    if (!flag_return && millis() - timer >= 300) 
    {
      timer = millis();
      flag_return = !flag_return;
      LCD.clear();  
      if (line_menu != 0) {LCD.setCursor(0, 0);    LCD.print( "temperature");}
      if (line_menu != 1) {LCD.setCursor(0, 1);    LCD.print( "mode house");}
      if (line_menu != 2) {LCD.setCursor(0, 2);    LCD.print( "alarm clock");}
      if (line_menu != 3) {LCD.setCursor(0, 3);    LCD.print( "- - - ");}
    }
    if (menu_click) {
      menu_click = false;
      switch (line_menu) {
      case 0 : mode_menu = TEMPERATURE; LCD.clear();  break;
      case 1 : mode_menu = MODE_SCRIPT_HOUSE; LCD.clear(); break;
      case 2 : mode_menu = ALARM_CLOCK; LCD.clear();  break;
      case 3 : break; 
      }
    }
    break;

    case (MODE_SCRIPT_HOUSE) :
    LCD.setCursor(0, 0);    
    script_house_show();
    break;
  
    case (BRIGHTNESS) :
    LCD.setCursor(0, 0);
    LCD.print("Brightness ");
    LCD.print(Brightness);
    break;
  
    case (MODE_LIGHTING) : 
    LCD.setCursor(0, 0);
    LCD.print("LIGHTING ");
    break;

    case (TEMPERATURE) :
    LCD.setCursor(0, 0);
    temperature_show ( FULL_STRING );
    LCD.setCursor(0, 1);
    LCD.print("Temp day: ");
    LCD.print(temperature_day);
    LCD.setCursor(0, 2);
    LCD.print("Temp now: ");
    LCD.print(temperature_now);
    LCD.setCursor(0, 3);
    LCD.print("Temp night: ");
    LCD.print(temperature_night);
    break;

    case (LED_PATTERN) : 
    LCD.setCursor(0, 0);
    LCD.print("led pattern show ");
    LCD.setCursor(0, 1);
    LCD.print(led_pattern_name[led_pattern_number]);
    LCD.setCursor(0, 2);
    LCD.print("speed: ");
    LCD.setCursor(8, 2);
    LCD.print(sped_led_show);
    break;
    
    default :
    break;
 }

 if ( last_mode_menu != mode_menu)  last_mode_menu = mode_menu;         //если сменился режим обнуляем флаг первого показа
    
}     

  

void script_house_show () {
 // if ( script_house != last_script_house) {
 // LCD.clear();
  LCD.print("Script: ");
  switch (script_house) {
    case(MOVE) :
    LCD.print( "MOVE   " );
    break;
    case(NO_MOVE) :
    LCD.print( "NO_MOVE " );
    break;
    case(SLEEP) :
    LCD.print( "SLEEP   " );
    break;
    case(SUNRISE) :
    LCD.print( "SUNRISE " );
    break;
    case(VIEWING_FILM) :
    LCD.print( "VIEWING_FILM " );
    break;
    case(NIGHT_MOVE) :
    LCD.print( "NIGHT_MOVE " );
    break;
    default:
    break;
  } 
  //}
}

void temperature_show (byte i) {
  static float last_temperature;
  if ( (temperature_now != last_temperature) || (last_mode_menu != mode_menu)) {
    last_temperature = temperature_now;
    switch(i) {
    case(LIGHT_STRING) :
     LCD.print(temperature_now,1); LCD.print(char(223)); LCD.print("C "); 
     break;
    case(FULL_STRING) :
     LCD.print("Temperature: ");
     LCD.print(temperature_now,1); LCD.print(char(223)); LCD.print("C "); 
     break;
    default:
     break;
  }}
}
void time_show () {
 
  static uint8_t last_seconds;
  if (last_seconds != timeNow.second || last_mode_menu != mode_menu) {
    last_seconds = timeNow.second;
    char time[9]; 
    time[0] = timeNow.hour / 10 + '0';
    time[1] = timeNow.hour % 10 + '0';
    time[2] = ':';
    time[3] = timeNow.minute / 10 + '0';
    time[4] = timeNow.minute % 10 + '0';
    time[5] = ':';
    time[6] = timeNow.second / 10 + '0';
    time[7] = timeNow.second % 10 + '0';
    time[8] = '\0';
    LCD.print(time);
  }
}

//-------отображение будильника----------
void alarm_clock_show() {
  static char alarm[6];
  if (last_mode_menu != mode_menu) {
    LCD.print( "Alarm clock: "); 
    alarm[0] =  alarmTime.hour / 10 + '0';
    alarm[1] =  alarmTime.hour % 10 + '0';
    alarm[2] = ':';
    alarm[3] =  alarmTime.minute / 10 + '0';
    alarm[4] =  alarmTime.minute % 10 + '0';
    alarm[5] = '\0';
    LCD.print (alarm); 
  } 
}
