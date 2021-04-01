#include <vector>

using namespace std;

class Vec{
    private:
        vector<double> v;
        int dimension;
    public:
        class dimension_mismatch{};
        Vec(int d=2):dimension(d){
            v = vector<double>(d,0);
        }

        Vec(vector<double> v2): v(v2){ dimension=v2.size();}

        int dim() const { return dimension; }

        double operator[](int pos) const {
            if(pos<0 || pos>=dim()) __throw_range_error;
            return v[pos];
        }

        double & operator[](int pos) {
            if(pos<0 || pos>=dim()) __throw_range_error;
            return v[pos];
        }        
        Vec operator+(const Vec & vec2) const{
            if(dim()!=vec2.dim()) __throw_length_error;

            Vec sum(dim());
            for(int i=0;i<dim();++i){
                sum[i] = (*this)[i] + vec2[i];
            }
            return sum;
        }

        bool operator==(const Vec & vec2) const{
            for(int i=0;i<dim();++i){
                if(v[i]!=vec2.v[i]) return false;
            }
            return true;
        }

        void operator+=(const Vec & vec2){
            (*this) = (*this) + vec2;
        }
};

class polygon{
    private:
        vector<Vec> sides{};
        int theSize = 0;
        int theDim;
        bool is_valid() const{
            if(size()==0) return true;
            
            Vec sum{dim()};
            for(const Vec & side:sides){
                if(side.dim()!=dim()) __throw_length_error;
                sum += side;
            }
            Vec zero{dim()};
            return sum==zero;
        }
    public:
        polygon(vector<Vec> sides2): sides(sides2), theSize(sides2.size()){
            if (size()==0) theDim=2;
            else theDim=sides2[0].dim();
        }

        int size() const { return theSize; }
        int dim() const { return theDim; }
        bool is_selfcrossed() const;
        bool is_convex() const;

        bool is_inside()



};

int main()
{
    return 0;
}