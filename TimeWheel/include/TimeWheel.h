#ifndef _TIME_WHEEL_H_
#define _TIME_WHEEL_H_

#include "ExportApi.h"
#include <vector>
#include <memory>

namespace mylibc::timew_heel
{
    typedef class TimerTask
    {
    public:
        TimerTask();
        ~TimerTask();

    private:
        /* data */
    } TimerTask;

    
    using WheelSize = size_t;
    typedef class TimeWheel
    {
    public:
        TimeWheel();
        ~TimeWheel();

    private:
        // 时间轮每个槽的时间跨度，单位： ms
        time_t kick;
        // 时间轮的开始时间
        time_t start_time;
        // 时间轮大小
        WheelSize wheel_size;
        // 当前所处时间（m_tickMs的整数倍）
        time_t curren_time;
        std::unique_ptr<std::vector<TimerTask>> m_timerTaskList;

    } TimeWheel;

} // namespace mylib::timew_heel

#endif