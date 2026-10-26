#include <GxEPD2_BW.h>
#include <Fonts/FreeMonoBold12pt7b.h>

// CS, DC, RST, BUSY
GxEPD2_BW<GxEPD2_290_T94_V2, GxEPD2_290_T94_V2::HEIGHT> display(
    GxEPD2_290_T94_V2(5, 17, 16, 4));
