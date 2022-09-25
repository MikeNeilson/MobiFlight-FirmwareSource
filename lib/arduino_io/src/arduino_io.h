#pragma once

#include <Arduino.h>
#include "MFBoards.h"
#include <mobiflight.h>
#include "button.h"

#include "cmd_io.h"

using ButtonType = mobiflight::devices::Buttons<MAX_BUTTONS, Button>;

using FlightDirector = mobiflight::MobiFlight<Messenger, ButtonType>;

#include "config.h"