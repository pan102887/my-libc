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

    typedef class TimeWheel
    {
    public:
        TimeWheel();
        ~TimeWheel();
        TimerTask *getCurrentTask();

    private:
        // 时间轮的开始时间
        const time_t start_time;

        // 当前所处时间（m_tickMs的整数倍）
        time_t curren_time;

        // 时间轮每个槽的时间跨度，单位： ms
        time_t unit_span;

        // 时间轮大小
        size_t wheel_size;
        std::unique_ptr<std::vector<TimerTask>> m_timerTaskList;
    } TimeWheel;

} // namespace mylib::timew_heel

#endif