#include "Copter.h"

#ifdef USERHOOK_INIT
void Copter::userhook_init()
{
    // put your initialisation code here
    // this will be called once at start-up
}
#endif

#ifdef USERHOOK_FASTLOOP
void Copter::userhook_FastLoop()
{
    // put your 100Hz code here
}
#endif

#ifdef USERHOOK_50HZLOOP
void Copter::userhook_50Hz()
{
    // put your 50Hz code here
}
#endif

#ifdef USERHOOK_MEDIUMLOOP
void Copter::userhook_MediumLoop()
{
    // put your 10Hz code here
}
#endif

#ifdef USERHOOK_SLOWLOOP
void Copter::userhook_SlowLoop()
{
    // put your 3.3Hz code here
}
#endif

#ifdef USERHOOK_SUPERSLOWLOOP
void Copter::userhook_SuperSlowLoop()
{
    // put your 1Hz code here
    // reference : https://ardupilot.org/dev/docs/debug-with-send-text.html
    static uint16_t counter = 0;
    static float cells[4] = {4.0854f,4.1104f,4.1324f,4.1435f};
    counter++;
    if(counter > 5){
        counter = 0;
        // send message to QGC/
        // gcs().send_text(MAV_SEVERITY_INFO,"cell 1  : %5.3f",0.5f);
        
        if(up1.Cell_change(cells,4)) { 
            gcs().send_text(MAV_SEVERITY_DEBUG, "ASTROX BMS - cell data updated "); 
            // gcs().send_text(MAV_SEVERITY_WARNING, "ASTROX BMS in operation...");
            gcs().send_message(MSG_PRI_BAT_INFO);
        } // copter.g2.user_parameters -> expected position of parameter 
    }    
    
}
#endif

#ifdef USERHOOK_AUXSWITCH
void Copter::userhook_auxSwitch1(uint8_t ch_flag)
{
    // put your aux switch #1 handler here (CHx_OPT = 47)
}

void Copter::userhook_auxSwitch2(uint8_t ch_flag)
{
    // put your aux switch #2 handler here (CHx_OPT = 48)
}

void Copter::userhook_auxSwitch3(uint8_t ch_flag)
{
    // put your aux switch #3 handler here (CHx_OPT = 49)
}
#endif
