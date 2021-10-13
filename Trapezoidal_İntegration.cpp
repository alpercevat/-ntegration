//TRAPEZOİDAL İNTEGRATİON İLE VERİLEN FONKSİYONUN DEFİNED(a,b) OLDUĞU ARALIKTAKİ İNTEGRAL DEĞERİNİ BULUYORUZ. 
//BURADA DEĞİŞENLER 1-FONKSİYONUN KENDİSİ 2-VERİLEN ARALIKLAR 3- n SEGMENT SAYISI DEĞİŞEBİLİR.
// ÖRNEK OLARAK: 1'DEN 25'E KADAR() F(X)=X.SİNX İNTEGRALİNİ (5,15) ARALIĞINDA BULUN.
//!!!!!!!!!!!!FONKSİYONUN RelError KISMINDA BAZI HATALAR VAR. ONLARI DÜZEL!!!!!!!!

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <ctime>

using namespace std;

double f(double);  //fonksiyon için yazdım.

double trapezoid(double(*f)(double), double a, double b, int n) {
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



int main() {

    double a,b,trap;
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

    cout << setw(10) << "Intervals" << setw(9) << "Trapez" 
		 << setw(12) << "TrueError" << setw(16) << "RelError (%)" << endl;

	for (i=1; i <=ntimes; i=i+1) {
        trap = trapezoid(f, a, b, n); // use trapezoidal rule
		double trueError = trueValue - trap;
		double RelError  = fabs(trueError/trueValue)*100.;
        cout << setw(10) << n << setw(10) << trap << setw(10) << trueError << setw(12) << RelError << endl;

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