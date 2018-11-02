#include <cassert>
#include <iostream>

/*
Homework: Imagine you are part of a software developer team that is developing a new software framework for neutrino telescopes. Your task is to implement two classes that represent a position vector and a directional unit vector, respectively. Your team puts the implementation details completely into your hands. The only wishes are that it is possible to do arithmetic operations on these objects (implement at least the dot product) and that you apply the Rule of Six (see the lecture notes). Think also about other potential features: string representation, access operator, initialization list, etc. But try to keep the classes as minimal as possible.
*/

class position
{
    public:
        position(double x = 0., double y = 0., double z = 0.)
        : x_(x), y_(y), z_(z) {}


        //copy constructor
        position( const position& p) : x_(p.x_), y_(p.y_), z_(p.z_) {}

        //move constructor
        position(double&& p)
        : x_(p.x_), y_(p.y_), z_(p.z_)
        {
            p.x_ = 0;
            p.y_ = 0;
            p.z_ = 0;

        }

        //move assignment
        position& operator=(position&& src)
        {
            std::swap(x,src.x)
            std::swap(y,src.y)
            std::swap(z,src.z)

        }

        //get x
        double const get_x()
        {
            return x_;
        }

        //set x
        void set_x(const double& x)
        {
            x_ = x;
        }

        //get y
        double const get_y()
        {
            return y_;
        }

        //set y
        void set_y(const double& y)
        {
            y_ = y;
        }

        //get z
        double const get_z()
        {
            return z_;
        }

        //set z
        void set_z(const double& z)
        {
            z_ = z;
        }

        //destructor
        ~position() {}

    private:
        double x_;
        double y_;
        double z_;
};


class direction
{
    public:
        direction(double theta = 0., double phi = 0.) 
        {
            x_hat = std::sin(theta)*std::cos(phi) + std::cos(theta)*std::cos(phi) - std::sin(phi);
            y_hat = std::sin(theta)*std::sin(phi) + std::cos(theta)*std::sin(phi) + std::cos(phi);
            z_hat = std::cos(theta) + std::sin(theta);
        }

        //copy constructor
        direction( const direction& d) : x_hat(d.x_hat), y_hat(d.y_hat), z_hat(d.z_hat) {}

        //move constructor
        position(double&& d)
        : x_hat(d.x_hat), y_hat(d.y_hat), z_hat(d.z_hat)
        {
            d.x_hat = 0;
            d.y_hat = 0;
            d.z_hat = 0;

        }


        //set theta
        void set_angles(const double& theta, const double& phi)
        {
            x_hat = std::sin(theta)*std::cos(phi) + std::cos(theta)*std::cos(phi) - std::sin(phi);
            y_hat = std::sin(theta)*std::sin(phi) + std::cos(theta)*std::sin(phi) + std::cos(phi);
            z_hat = std::cos(theta) + std::sin(theta);
        }

        //get x_hat
        double const get_xhat()
        {
            return x_hat;
        }

        //get y_hat
        double const get_yhat()
        {
            return y_hat;
        }
        
        //get z_hat
        double const get_zhat()
        {
            return z_hat;
        }

        private:
            double x_hat;
            double y_hat;
            double z_hat;

};
