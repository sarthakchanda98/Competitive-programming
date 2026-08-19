class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats)
    {
        sort(reservedSeats.begin(), reservedSeats.end());

        int group = 2 * n;
        int i = 0;

        while(i < reservedSeats.size())
        {
            int row = reservedSeats[i][0];
            vector<int> seats(11, 0);

            while(i < reservedSeats.size() && reservedSeats[i][0] == row)
            {
                seats[reservedSeats[i][1]] = 1;
                i++;
            }

            int count = 0;

            if(seats[2] == 0 && seats[3] == 0 && seats[4] == 0 && seats[5] == 0)
            {
                count++;
            }

            if(seats[6] == 0 && seats[7] == 0 && seats[8] == 0 && seats[9] == 0)
            {
                count++;
            }

            if(count == 0 &&
               seats[4] == 0 && seats[5] == 0 &&
               seats[6] == 0 && seats[7] == 0)
            {
                count++;
            }

            group -= 2;
            group += count;
        }

        return group;
    }
};