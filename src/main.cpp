
#ifdef ARDUINO
#include <mobiflight.h>
#include <arduino_io.H>

using namespace mobiflight;

CmdMessenger cm(Serial);
Messenger    messenger(cm);
Config       config;

using MFTYPE = MobiFlight<Messenger, devices::Buttons<5, devices::Button>>;

MFTYPE mf(config, messenger);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    delay(200);
    mf.update();
}

#else
#include <pi.h>
#include <mobiflight.h>
#include <thread>
#include <iostream>
#include <chrono>

struct CmdMessenger {
    void send(mobiflight::devices::button_event &&event)
    {
        std::cout << "Button event" << event.name << std::endl;
    }
};

int main(int argc, char **argv)
{
    using mobiflight::devices::Button;
    std::cout << "hello " << std::endl;
    gpiod_chip *chip0 = gpiod_chip_open_by_name("gpiochip0");
    gpiod_line *line  = gpiod_chip_get_line(chip0, 21);
    const char *name  = "testbutton";
    gpiod_line_request_input(line, name);
    using PiButtons = mobiflight::devices::Buttons<5, Button>;
    Config                                                  conf;
    CmdMessenger                                            msg;
    mobiflight::MobiFlight<CmdMessenger, Config, PiButtons> mf(conf, msg);

    mf.get_module<PiButtons>().add(new Button(chip0, line, "test"));
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        mf.update();
        std::cout << "watchdog" << std::endl;
    }
}

#endif
