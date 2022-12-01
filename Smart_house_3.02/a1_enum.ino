
enum MODE_MENU {
  MAIN_LCD , MENU , BRIGHTNESS, MODE_LIGHTING, TEMPERATURE  , 
  MODE_SCRIPT_HOUSE, ALARM_CLOCK, LED_PATTERN
  } mode_menu;
 
enum SCRIPT_HOUSE { 
  FIRST_SCRIP, MOVE,  SLEEP, VIEWING_FILM, NIGHT_MOVE , NO_MOVE, SUNRISE, LAST_SCRIP,
} ;
SCRIPT_HOUSE script_house (NO_MOVE);
SCRIPT_HOUSE last_script_house(LAST_SCRIP);

enum MODE_LIGHT_BEDROM {
  OFF_LIGHT,  START_LIGHT,  NORMAL_LIGHT,  BLACKOUT_LIGHT,
  NIGHT_LIGHT,  SUNRISE_LIGHT, NO_LIGHT, COLOR_MUSIC, SUNSET_LIGHT,
} mode_light_bedroom;
MODE_LIGHT_BEDROM show_mode_light;

struct LIGHT_BEDROM {
  enum PART_LIGHTING{
    FULL, CENTR, PERIMETR,
  } ;
  PART_LIGHTING part_lighting;
  MODE_LIGHT_BEDROM next_mode;
};
LIGHT_BEDROM sunset { LIGHT_BEDROM::FULL, START_LIGHT};

enum {
   off, on,
} ON_OFF ;
