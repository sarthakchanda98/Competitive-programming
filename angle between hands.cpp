class Solution {
public:
    double angleClock(int hour, int minutes) {
        double deghrs = 0;
        double degmins = 0;
        double angle;
        double check;
        if(hour == 12)
        {
            deghrs = 0.5*minutes;
        }
        else
        {
            deghrs = 30*hour + 0.5*minutes;
        }

        degmins = 6*minutes;
        angle = abs(deghrs-degmins);
        check = abs(360-angle);
        if(check > angle)
        {
            return angle;
        }
        else
        {
            return check;
        }
        
    }
};
