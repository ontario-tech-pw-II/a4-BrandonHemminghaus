#include <iostream>
using namespace std;

class Circle {
  private:  
    int x,y;      // center of circle
    double r;    // radius of circle

  public:
   
    Circle(int =0,int=0, double =1.0);
    void print();
    double area();

    double operator+(const Circle &) const;

    Circle & operator++();
    Circle operator++(int);

  friend ostream & operator<<(ostream &out, const Circle &);
  friend istream & operator>>(istream &in, Circle &);
};

Circle::Circle(int x,int y, double r)
{
  this->x = x;
  this->y = y;
  this->r = r;
}

double Circle::area(){
	return 3.14*r*r;
}


double Circle::operator+(const Circle & c) const
{
   double result = c;
   return result;
}

Circle & Circle::operator++()
{
  r++;
  return *this;
}

Circle Circle::operator++(int)
{
  Circle temp = *this;
  r++;
  return temp;
}

ostream & operator<<(ostream &out, const Circle &c)
{

  out << "\tx: " << c.x << endl;
  out << "\ty: " << c.y << endl;
  out << "\tr: " << c.r << endl;
  return out;
}

istream & operator>>(istream &in, Circle &c)
{
	int tmp_x;
	int tmp_y;
	double tmp_r;


	cout << "\tx: ";
	in >> tmp_x;

	cout << "\ty: ";
	in >> tmp_y;

	cout << "\tr: ";
	in >> tmp_r;

	c = Circle(tmp_x,tmp_y,tmp_r);

  return in;
}


void Circle::print()
{
  cout << "Circle =(" << x << "," << y << "," << r << ")" << endl;
}



int main()
{
  Circle a;
  Circle b(2,3,3.0);

  a.print();
  b.print();
  
  //cout << "The area a + b is: " << a+b << endl;
  ++a;
  a.print();

  a++;
  a.print();

  cout << a;

  cin >> a;
  cout <<a;

  return 0;

}