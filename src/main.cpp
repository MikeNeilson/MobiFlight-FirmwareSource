#include <mobiflight.h>
#include <buttons.h>

struct Config {
};

#ifdef ARDUINO
#include <CmdMessenger.h>

CmdMessenger messenger(Serial);
Config       config;

mobiflight::MobiFlight<CmdMessenger, Config, mobiflight::devices::Buttons<5>> mf(config, messenger);

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
#include <iostream>
#include <chrono>
struct CmdMessenger {
};

int main(int argc, char **argv)
{
    std::cout << "hello " << std::endl;
    using PiButtons = mobiflight::devices::Buttons<5>;
    Config                                                  conf;
    CmdMessenger                                            msg;
    mobiflight::MobiFlight<CmdMessenger, Config, PiButtons> mf(conf, msg);
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        mf.update();
        mf.get_module<PiButtons>().update();
    }
}

#endif
