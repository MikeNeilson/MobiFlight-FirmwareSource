#include <mobiflight.h>
#include "button.h"
struct Config {
};

#ifdef ARDUINO
#include <CmdMessenger.h>

CmdMessenger messenger(Serial);
Config       config;

mobiflight::MobiFlight<CmdMessenger, Config, mobiflight::Buttons<5>> mf(config, messenger);

void setup()
{
}

void loop()
{
    delay(200);
    mf.update();
}

#else
#include <thread>
#include <chrono>
struct CmdMessenger {
};

int main(int argc, char **argv)
{
    Config                                                               conf;
    CmdMessenger                                                         msg;
    mobiflight::MobiFlight<CmdMessenger, Config, mobiflight::Buttons<5>> mf(conf, msg);
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

#endif
