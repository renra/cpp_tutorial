#include <iostream>
using namespace std;

class FirstSource{
public:
  void introduce(){
    cout << "I am First Source and Last Effect connected in an undivided chain." << endl;
  }
};

class Singularity {
  //Pure virtual function makes the class abstract
  public:
  virtual void print_location() =0;
};

class Point : public Singularity, public FirstSource {
  //This virtual function can still be called
  public:
  virtual void print_location(){
    cout << "I am virtual. I am nowhere." << endl;
  }
};

class Point2d : public Point {
  static int count;

  protected:
  float coor_x;
  float coor_y;

  static void increment_count(){
    Point2d::count++;
  }

  void set_coors_and_increment_count(float x, float y){
    set_coors(x, y);
    increment_count();
  }

  public:
  Point2d(){
    cout << "2D Default constructor called" << endl;
    set_coors_and_increment_count(0.0, 0.0);
  }

  Point2d(int x, int y){
    cout << "2D Int constructor called" << endl;
    set_coors_and_increment_count((float) x, (float) y);
  }

  Point2d(float x, float y){
    cout << "2D Float constructor called" << endl;
    set_coors_and_increment_count(x, y);
  }

  Point2d(const Point2d& point){
    cout << "Calling the 2D copy constructor" << endl;
    set_coors_and_increment_count(point.coor_x, point.coor_y);
  }

  ~Point2d(){
    cout << "2D Destructor called" << endl;
    Point2d::count--;
  }

  Point2d operator + (const Point2d& factor){
    float x = coor_x + factor.coor_x;
    float y = coor_y + factor.coor_y;

    return Point2d(x, y);
  }

  void operator += (const Point2d& factor){
    coor_x += factor.coor_x;
    coor_y += factor.coor_y;
  }

  void set_coors(float x, float y){
    coor_x = x;
    coor_y = y;
  }

  bool is_origin(){
    return coor_x == 0 && coor_y == 0;
  }

  void print_location(){
    cout << "You can find me at: [" 
	 << coor_x << ", " 
	 << coor_y << "]" 
	 << endl;
  }

  static int get_count(){
    return Point2d::count;
  }
  
  friend void dangerous_function();
};

class Point3d : public Point2d {
  //private just for this class
  typedef Point2d super;

  static int count;

  protected:
  float coor_z;

  void set_z_and_increment_count(float z){
    set_z(z);
    increment_count();
  }

  static void increment_count(){
    Point3d::count++;
  }

  public:
  //Don't call one overloaded constructor from another!!!
  //That would create two objects instead of one
  //Use other methods instead
  Point3d(){
    cout << "3D Default constructor called" << endl;
    set_z_and_increment_count(0.0);
  }

  Point3d(int x, int y, int z) : Point2d(x, y){
    cout << "3D Int constructor called" << endl;
    set_z_and_increment_count((float) z);
  }
  
  Point3d(float x, float y, float z) : Point2d(x, y){
    cout << "3D Float constructor called" << endl;
    set_z_and_increment_count(z);
  }

  Point3d(const Point3d& point) : Point2d(point){
    cout << "Calling the 3D copy constructor" << endl;
    set_z_and_increment_count(point.coor_z);
  }

  ~Point3d(){
    cout << "3d Destructor called" << endl;
    Point3d::count--;
  }

  //OPTIMIZE : use the inherited function
  Point3d operator + (const Point3d& factor){
    float x = coor_x + factor.coor_x;
    float y = coor_y + factor.coor_y;
    float z = coor_z + factor.coor_z;

    return Point3d(x, y, z);
  }

  void operator += (const Point3d& factor){
    coor_x += factor.coor_x;
    coor_y += factor.coor_y;
    coor_z += factor.coor_z;
  }

  void set_coors(float x, float y, float z){
    coor_x = x;
    coor_y = y;
    coor_z = z;
  }

  void set_z(float z){
    coor_z = z;
  }

  bool is_origin(){
    return coor_x == 0 && coor_y == 0 && coor_z == 0;
  }

  void print_location(){
    cout << "You can find me at: [" 
	 << coor_x << ", " 
	 << coor_y << ", " << coor_z << "]" 
	 << endl;
  }

  static int get_count(){
    return Point3d::count;
  }
  
  //Friendship is not inherited, though some sources mentioned it should be
  friend void dangerous_function();
};

//I don't think friend functions are a good practice
//but it's good to know about them
void dangerous_function(){
  Point3d::increment_count();
}

//Seems this has to be outside the class. That's a little strange.
int Point2d::count = 0;
int Point3d::count = 0;

void do_nothing(Point3d point){}
void do_nothing_pointer(Point3d * point){}
void do_nothing_reference(Point3d & point){}

void oop_exercise(){
  //Singularity s;
  Point p;
  p.print_location();
  p.introduce();

  Point2d Origin2d(0, 0);
  Point3d Origin(0, 0, 0);
  Point3d X(1, 2, 3);
  Point3d * p_X = &X;

  cout << "The point Origin is at the origin: " << Origin.is_origin() << endl;

  //This does not fire the copy constructor
  //but it would if Origin were not initialized
  Origin = X;
  do_nothing_pointer(p_X);
  do_nothing_reference(X);

  //This fires the copy constructor
  do_nothing(Origin);

  //This also fires the copy constructor
  Point3d Y (X);

  X.set_coors(10, 10, 10);
  Point3d Z = Origin + X;
  Origin += Z;            //Origin.operator+= (Z);

  Origin.print_location();
  Z.print_location();
  cout << "The point is at the origin: " << Origin.is_origin() << endl;
  cout << "We currently have: " << Point2d::get_count() << " 2d points created" << endl;
  cout << "We currently have: " << Point3d::get_count() << " 3d points created" << endl;
  
  dangerous_function();
  cout << "We currently have: " << Point2d::get_count() << " 2d points created" << endl;
  cout << "We currently have: " << Point3d::get_count() << " 3d points created" << endl;
}
