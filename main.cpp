#include <LcdMenu.h>
#include <Button.h>

static const int kLCD_ROWS = 2;
static const int kLCD_COLS = 16;

static const int kPIN_UP = 12;
static const int kPIN_DOWN = 11;
static const int kPIN_ENTER = 10;

// Define the main menu
extern MenuItem mainMenu[];
LcdMenu menu(kLCD_ROWS, kLCD_COLS);

// Define buttons
#define DECLARE_BUTTON_CLASS(cname, pin) \
class cname : public ButtonAction {\
public:\
  explicit cname(): ButtonAction(pin) {}\
  inline void pressing(bool) const override
#define EO_DECLARE_BUTTON_CLASS() };
DECLARE_BUTTON_CLASS(UpButton, kPIN_UP) { menu.up(); } EO_DECLARE_BUTTON_CLASS()
DECLARE_BUTTON_CLASS(DownButton, kPIN_DOWN) { menu.down(); } EO_DECLARE_BUTTON_CLASS()
DECLARE_BUTTON_CLASS(EnterButton, kPIN_ENTER) { menu.enter(); } EO_DECLARE_BUTTON_CLASS()
ButtonAction* ba[] = {
  new UpButton(),
  new DownButton(),
  new EnterButton(),
  new ButtonActionFooter(),
};
Button btn(ba, 10);

// main functions
extern void more_setup();
extern void more_loop();
void setup() {
  Serial.begin(115200);
  // Initialize LcdMenu with the menu items
  menu.setupLcdWithMenu(0x27, mainMenu);
  more_setup();
}
void loop() {
  btn.action();
  more_loop();
  delay(50);
}
