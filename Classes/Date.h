struct Date{
    int day = 1;
    int month = 1;
    int year = 2014;
};

string dayOfWeek(Date d){ //regresar dia de la semana
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    int y = d.year;
    y -= d.month < 3;
    int day = (y + y/4 - y/100 + y/400 + t[d.month - 1] + d.day) % 7;
    switch (d){
        case 0:
            return "sunday";
        case 1:
            return "monday";
        case 2:
            return "tuesday";
        case 3:
            return "wednesday";
        case 4:
            return "thursday";
        case 5:
            return "friday";
        case 6:
            return "saturday";
        default:
            return "";
    }
    
}
