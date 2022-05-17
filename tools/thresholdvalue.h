#ifndef THRESHOLDVALUE_H
#define THRESHOLDVALUE_H

//该类存储阈值，且都为静态
class ThresholdValue
{
public:
    ThresholdValue();
    static const int tv_arterial_max;//动脉压阈值Max
    static const int tv_arterial_min;//动脉压阈值Min
    static const int tv_venous_max;//静脉压阈值Max
    static const int tv_venous_min;//静脉压阈值Min
    static const int tv_conductivity_max;//电导度阈值Max
    static const int tv_conductivity_min;//电导度阈值Min
    static const int tv_tmp_max;//跨膜压阈值Max
    static const int tv_tmp_min;//跨膜压阈值Min
    static const int tv_blood_pump_speed_max;//血泵最大速度
    static const int tv_blood_pump_speed_min;//血泵最小速度
};

#endif // THRESHOLDVALUE_H
