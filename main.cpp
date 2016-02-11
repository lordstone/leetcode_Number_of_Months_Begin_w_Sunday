class countMoBeginSundays{

public:
    countMoBeginSundays(date_t theSunday){
        sunday = theSunday;
        monthDay[1] = 31;
        monthDay[2] = 28;
        monthDay[3] = 31;
        monthDay[4] = 30;
        monthDay[5] = 31;
        monthDay[6] = 30;
        monthDay[7] = 31;
        monthDay[8] = 31;
        monthDay[9] = 30;
        monthDay[10] = 31;
        monthDay[11] = 30;
        monthDay[12] = 31;
        dayofweek = (monthDay[sunday.month] - sunday.day) % 7;
        sunday.day = 1;
        if(sunday.month != 12) sunday.month ++;
        else{
            sunday.month = 1;
            sunday.year ++;
        }
    }

    int numSunday(date_t theDate){
        int sundayCount = 0;
        date_t cur = sunday;
        int countDay = dayofweek;
        while( cur.month < theDate.month || cur.year < theDate.year ){
            countDay += monthDay[cur.month];
            if(cur.month == 2 && cur.year % 4 == 0) countDay ++;

            if(countDay % 7 == 0) sundayCount ++;
            if(cur.month < 12){
                cur.month ++;
            }else{
                cur.month = 1;
                cur.year ++;
            }
        }
        return sundayCount;
    }

    int findMonthBeginSundays(date_t startDate, date_t endDate){
        int count = 0;
        //find the startDate to sunday date
        int a = numSunday(startDate);
        int b = numSunday(endDate);
        return b - a;
    }
private:
    date_t sunday;
    int dayofweek;
    unordered_map<int, int> monthDay;
};
