
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

double f(double);  //fonksiyon için yazdım.

double trapezoid(double(*f)(double), double a, double b, int n) { //Trapezoid metodu
    double r, dx, x;
    r = 0.0;
    dx = (b-a)/static_cast<float>(n);
    for (int i = 1; i <= n-1; i=i+1) {
        x = a + static_cast<float>(i)*dx;
        r = r + f(x);
    }
    r = (r + (f(a)+f(b))/2.0)*dx;
    return r;
}

double rectangle(double(*f)(double), double a, double b, int n) {  // Rectangle metodu
    double r, h, x;
    double area = 0.0;
    h = (b-a)/n;
	for (int i = 0; i < n; ++i) { 
		//area += f(a+i*h)*h;  // (left point)
		area = area +  f(a+(i+0.5)*h)*h;  // (midpoint)
	}
    return area;
}


double simpson(double(*f)(double), double a, double b, int n) {
    double s, h, x;
    if((n/2)*2 != n) {n=n+1;}
    s=0.0;
    h=(b-a)/n;
    
    for (int i=1; i <= n-1; i=i+2 ) {
        x=a+i*h;
        s = s + 4.0*f(x);
    }
    for (int i=2; i <= n-2; i=i+2 ) {
        x=a+i*h;
        s = s + 2.0*f(x);
    }
    s = (h/3.0)*(s+f(a)+f(b));
    return s;
}



int main() {

    double a,b,trap,rect,simp;
    int i,n;
    int ntimes;
    const double pi = 3.1415926;
    double trueValue = 0.89397; //İntegralin gerçek değeri. Karşılaştırmak için yazılmış.

    cout.precision(5); //! Değişbilir 1
    cout.setf(ios::fixed | ios::showpoint);

    a = 0.1;     //Başlangıç noktası    //! Değişebilir 2
    b = 1.3;     //Bitiş noktası         //! Değişebilir 3
    n = 1;       //Segment sayısı          //! Değişebilir 4
    ntimes= 12;  // 12 olana kadar segment sayısını 1er 1er arttır. kodu alt kısmında for döngüsünün olduğu yerde       //! Değişebilir 5

    cout << setw(10) << "Intervals" << setw(9) << "Trapez"  << setw(11) << "TrueError" << setw(12) << " RelError(%)" 
         << setw(10) << "Intervals" << setw(10) << " Rectangle"  << setw(11) << "TrueError" << setw(13) << "RelError(%)" 
         << setw(10) << "Intervals" << setw(11) << "Simpson's" << setw(12) << "TrueError" << setw(16) << "RelError (%)" << endl;

 

	for (i=1; i <=ntimes; i=i+1) {
        trap = trapezoid(f, a, b, n);
        rect = rectangle(f, a, b, n);
        simp = simpson(f, a, b, n);
		double trueError = trueValue - trap;
		double RelError  = fabs(trueError/trueValue)*100.;
        double trueErrorRect = trueValue - rect;
		double RelErrorRect  = fabs(trueErrorRect/trueValue)*100.;
        double trueErrorSimp = trueValue - simp;
		double RelErrorSimp  = fabs(trueErrorSimp/trueValue)*100.;
        cout << setw(10) << n << setw(9) << trap << setw(10) << trueError << setw(12) << RelError 
             << setw(10) << n << setw(10) << rect << setw(10) << trueErrorRect << setw(12) << RelErrorRect
             << setw(11) << n << setw(11) << simp << setw(12) << trueErrorSimp << setw(13) << RelErrorSimp << endl;
        //++n; // n'i 1er 1er arttırır.
         n = n+1;
        //n = n*2; //  n'i 1er 1er arttırmak yerine karesiyle arttırmaya yarayan kod.      //! Değişebilir 6

    }


    return 0;

}

    double f(double x) {
    const double pi = 3.1415926;
    double y;
        //y = sin(x);                      
      //y = 30.914*x-100.93;
     y=5*x*exp(-2*x); // !Problemdeki fonksiyon. Burası değişebilir. f(x)=sinx gibi örnek olarak.       //! Değişebilir 7
    return y;
}

//!Klasik sınav sorusu: Bir tablo oluşturun.
//? Fonksiyon değişebilir. n değişebilir(Bu halde biz n leri karesi ile değiştiriyoruz). ntimes değişebilir 12 değil de 25 olabilir. precision değişebilir 5 değiş de 4 olabilir.