#include "Date.h"
#include <time.h>

void Date::SetDate(int year_, int month_, int date_)
{
    year = year_;
    month = month_;
    day = date_;
}

int Date::CalcDifDay()
{
    //  現在時間
    time_t nowTime = time(NULL);
    //  締め切り
    struct tm deadline;
    deadline.tm_sec = 0;
    deadline.tm_min = 0;
    deadline.tm_hour = 0;
    deadline.tm_mday = day;
    deadline.tm_mon = month - 1;
    deadline.tm_year = year - 1900;
    deadline.tm_isdst = -1;

    //  変換
    time_t deadline_t = mktime(&deadline);

    float diff = difftime(deadline_t, nowTime);

    //  秒から分
    diff /= 60;
    //  分から時間
    diff /= 60;
    //  時間から日
    diff /= 24;

    return (int)diff;
}
