#pragma once

#include <AP_Param/AP_Param.h>

class UserParameters {

public:
    UserParameters() {}
    static const struct AP_Param::GroupInfo var_info[];
    
    // Put accessors to your parameter variables here
    // UserCode usage example: g2.user_parameters.get_int8Param()
    AP_Int8 get_int8Param() const { return _int8; }
    AP_Int16 get_int16Param() const { return _int16; }
    AP_Float get_floatParam() const { return _float; }
    AP_Float get_cells(uint8_t num) const {return cells[num];}
    bool Cell_change(float *buf,uint8_t len) 
    {
        if(len != 4 ) return false;
        else{
            cells[0] = *buf;
            cells[0] = *(buf+1);
            cells[0] = *(buf+2);
            cells[0] = *(buf+3);                 
            return true;
        }
        
    }
private:
    // Put your parameter variable definitions here
    AP_Int8 _int8;
    AP_Int16 _int16;
    AP_Float _float;
    AP_Float cells[4];
};
