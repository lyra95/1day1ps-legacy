#include <vector>
using std::vector;


class poly2D{
    public: struct pos
    {
        double x=0;
        double y=0;

        pos(double x,double y):x(x),y(y){}
        pos normal(pos p){
            return pos(-p.y,p.x);
        }
        double operator*(pos p){
            return x*p.x + y*p.y;
        }
    };
    
    private:
        int theSize;
        vector<pos> sides;
    public:
        poly2D(vector<pos> s): sides(s),theSize(s.size()){}

        int size() const {return theSize;}
        bool is_selfcrossed() const;
        bool is_convex() const;

        bool is_inside(pos p) const{    
        }

        bool is_on_boundary(pos p) const;
        
};
int main(){return 0;}

