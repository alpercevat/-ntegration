
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

double f(double);  //fonksiyon için yazdım.

double rectangle(double(*f)(double), double a, double b, int n) {
    double r, h, x;
    double area = 0.0;
    h = (b-a)/n;
	for (int i = 0; i < n; ++i) { 
		//area += f(a+i*h)*h;  // (left point)
		area = area +  f(a+(i+0.5)*h)*h;  // (midpoint)
	}
    return area;
}


int main() {

    double a,b,rect;
    int i,n;
    int ntimes;
    const double pi = 3.1415926;
    double trueValue = 0.89397; //İntegralin gerçek değeri. Karşılaştırmak için yazılmış.

    cout.precision(5);
    cout.setf(ios::fixed | ios::showpoint);

    a = 0.1;     //Başlangıç noktası
    b = 1.3;     //Bitiş noktası
    n = 1;       //Segment sayısı
    ntimes= 12;  // 12 olana kadar segment sayısını 1er 1er arttır. kodu alt kısmında for döngüsünün olduğu yerde

    cout << setw(10) << "Intervals" << setw(11) << "Rectangle" 
		 << setw(12) << "TrueError" << setw(16) << "RelError (%)" << endl;

	for (i=1; i <=ntimes; i=i+1) {
        rect = rectangle(f, a, b, n); // use rectangle rule
		double trueError = trueValue - rect;
		double RelError  = fabs(trueError/trueValue)*100.;
        cout << setw(10) << n << setw(10) << rect << setw(10) << trueError << setw(12) << RelError << endl;

        //++n; // n'i 1er 1er arttırır.
        n = n*2; //  n'i 1er 1er arttırmak yerine karesiyle arttırmaya yarayan kod.

    }

    return 0;

}

    double f(double x) {
    const double pi = 3.1415926;
    double y;
//    y = sin(x);                      
      //y = 30.914*x-100.93;
     y=5*x*exp(-2*x); // !Problemdeki fonksiyon. Burası değişebilir. f(x)=sinx gibi örnek olarak.
    return y;
}

//Klasik sınav sorusu: Bir tablo oluşturun.