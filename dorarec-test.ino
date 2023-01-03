void more_setup() {
  // called from at end of setup()
}

void more_loop() {
  // called from at end of loop()
}

void power_on_MOB_BATT() {
  Serial.println("power_on_MOB_BATT");
}

void cut_off_from_MOB_BATT() {
  Serial.println("cut_off_from_MOB_BATT");
}

void start_charging_MOB_BATT() {
  Serial.println("start_charging_MOB_BATT");
}

void stop_charging_MOB_BATT() {
  Serial.println("stop_charging_MOB_BATT");
}

void recording_using_MAIN_PW() {
  Serial.println("recording_using_MAIN_PW");
}

void recording_using_MOB_BATT() {
  Serial.println("recording_using_MOB_BATT");
}

void cut_off_from_MAIN_PW() {
  Serial.println("cut_off_from_MAIN_PW");
}

#include <MenuItem.h>
// Initialize the main menu items
MenuItem mainMenu[] = { ItemHeader(),
                        ItemCommand("Power-on MB", power_on_MOB_BATT),
                        ItemCommand("cut-off MB", cut_off_from_MOB_BATT),
                        ItemCommand("start cg MB", start_charging_MOB_BATT),
                        ItemCommand("stop cg MB", stop_charging_MOB_BATT),
                        ItemCommand("rec using PW", recording_using_MAIN_PW),
                        ItemCommand("rec using MB", recording_using_MOB_BATT),
                        ItemCommand("cut-off PW", cut_off_from_MAIN_PW),
                        ItemFooter() };
