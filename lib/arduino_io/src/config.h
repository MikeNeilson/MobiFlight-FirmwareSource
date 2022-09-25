#pragma once

#include "button.h"
#include "mobiflight.h"

namespace mobiflight
{
    void resetConfig();
    void readConfig();
    void _activateConfig();

    struct Config {
        template <typename Director>
        void loadConfig(Director &director)
        {
            director.send<kStatus>(F("OK"));
        }
        bool getStatusConfig(void);
        void generateSerial(bool);
        void OnSetConfig(void);
        template <typename Director>
        void OnResetConfig(Director &director)
        {
            resetConfig();
            director.send<kStatus>(F("OK"));
        }
        void OnSaveConfig(void);
        void OnActivateConfig(void);
        void OnGetConfig(void);
        void OnGetInfo(void);
        void OnGenNewSerial(void);
        void OnSetName(void);
        void restoreName(void);
    };

}
