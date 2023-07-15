/* https://leetcode.com/problems/design-parking-system
1603. Design Parking System
Easy
Design
*/
class ParkingSystem
{
public:
    int b, s, m;
    
    ParkingSystem(int big, int medium, int small)
    {
        b = big;
        m = medium;
        s = small;
    }

    bool addCar(int carType)
    {
        switch (carType)
        {
        case 1:
            if (b)
                b--;
            else
                return false;
            break;
        case 2:
            if (m)
                m--;
            else
                return false;
            break;
        default:
            if (s)
                s--;
            else
                return false;
        }
        return true;
    }
}