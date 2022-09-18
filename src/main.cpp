#include <mobiflight.h>

struct Config {
};

#ifdef ARDUINO
#include <CmdMessenger.h>

mobiflight::MobiFlight<CmdMessenger, Config> mf;

void setup()
{
}

void loop()
{
    delay(200);
    mf.update();
}

#else

#endif
