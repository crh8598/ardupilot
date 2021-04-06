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

const float cellInit[]= {4.0854f,4.1104f,4.1324f,4.1435f};
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
        // gcs().send_text(MAV_SEVERITY_DEBUG,"ASTROX BMS - cell data updated "); 
        for(int i = 0 ;i<4;i++)
        {
            cells[i] += 0.001;
            if(cells[i] > 4.21) cells[i] = cellInit[i];
        }
        // for(uint8_t i  =0; i<gcs().num_gcs(); i++)
        // {
            gcs()._chan[0]->update_BMS_cells(cells);
            gcs()._chan[0]->send_pri_bat_info();
        // }
        
        
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
