/*
g++ -w -Wall -std=c++11 GUI/Graph.cpp GUI/Window.cpp GUI/GUI.cpp GUI/Simple_window.cpp drill15_1.cpp `fltk-config --ldflags --use-images` -o a.out
*/

#include "./GUI/Simple_window.h"
#include "./GUI/Graph.h"

#include <iostream>
#include <string>

using namespace Graph_lib;


double one(double x) {return 1;}
double slope(double x) {return x/2;}
double square (double x) {return x*x;}
double sloping_cos(double x) {return cos(x) + slope(x);}

int main(){

try {

	//Drill 15
	//Function graphing drill:

	Simple_window win(Point{100,100},600,600,"Function graphs");

	Axis xa {Axis::x,Point{100,300},400,20,"1 == 20 pixels"};
	Axis ya {Axis::y,Point{300,500},400,20,"1 == 20 pixels"};

	win.attach(xa);
	win.attach(ya);

	xa.set_color(Color::red);
	ya.set_color(Color::red);

	//range
	const int r_min = -10;
	const int r_max = 11;

	const Point orig {300,300};

	//using 400 points
	const int num_of_points = 400;

	const int x_scale = 20;
	const int y_scale = 20;

	Function func1 {one,r_min,r_max,orig,num_of_points,x_scale,y_scale};
	Function func2 {slope,r_min,r_max,orig,num_of_points,x_scale,y_scale};
	Function func3 {cos,r_min,r_max,orig,num_of_points,x_scale,y_scale};
	func3.set_color(Color::blue);
	Function func4 {sloping_cos,r_min,r_max,orig,num_of_points,x_scale,y_scale};
	
	win.attach(func1);
	win.attach(func2);
	win.attach(func3);
	win.attach(func4);

	win.wait_for_button();

} catch (exception& e){
		cerr << "exception: " << e.what() << endl;
		return 1;
} catch (...) {
		cerr << "error" << endl;
		return 2;
}
}