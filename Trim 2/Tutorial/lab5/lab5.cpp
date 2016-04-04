#include<iostream>
using namespace std;

class Rational{
	int num, den;
	public:
	Rational (int num=0, int den =1):num(num), den(den){}
	int getNum(){return num;}
	int getDen(){return den;}
	friend istream& operator>>(istream& is, Rational& r);
	 //ostream& operator<<(ostream& os, Rational& r);
	
};

Rational operator+(Rational &r1, Rational &r2){
		int nums, dens;
		if(r1.getDen()==r2.getDen()){ 
			nums = r1.getNum()+r2.getNum();
			dens = r1.getDen();
		}
		else if(r1.getDen() != r2.getDen()){
			nums = r1.getNum()*r2.getDen() + r2.getNum()*r1.getDen();
			dens = r1.getDen()*r2.getDen();
		}
		return Rational(nums, dens);
		
}

Rational operator-(Rational &r1, Rational &r2){
		int nums, dens;
		if(r1.getDen()==r2.getDen()){ 
			nums = r1.getNum()-r2.getNum();
			dens = r1.getDen();
		}
		else if(r1.getDen() != r2.getDen()){
			nums = r1.getNum()*r2.getDen() - r2.getNum()*r1.getDen();
			dens = r1.getDen()*r2.getDen();
		}
		return Rational(nums, dens);
		
}
bool operator==(Rational &r1, Rational &r2){
			int nums1,nums2, dens;		
			if(r1.getDen() != r2.getDen()){
				nums1 = r1.getNum()*r2.getDen();
				nums2 = r2.getNum()*r1.getDen();
				return nums1==nums2;
			} else {
				return r1.getNum()==r2.getNum();
			}
}
bool operator<(Rational &r1, Rational &r2){
			int nums1,nums2, dens;		
			if(r1.getDen() != r2.getDen()){
				nums1 = r1.getNum()*r2.getDen();
				nums2 = r2.getNum()*r1.getDen();
				return nums1<nums2;
			} else {
				return r1.getNum()<r2.getNum();
			}	
}

istream& operator>>(istream& is, Rational& r){
	is >> r.num >> r.den;
	return is;
}

ostream& operator<<(ostream& os, Rational& r){
		os << r.getNum() << "/" << r.getDen();
		return os;
}


int main() {
  Rational r1, r2;
  cout << "Input a rational number (num den): ";
  cin >> r1;
  cout << "Input a rational number (num den): ";
  cin >> r2;
    
  Rational r3;
  r3=r1+r2;
  cout << r1 << " + " << r2 << " = " << r3 << endl;
  r3=r1-r2;
  cout << r1 << " - " << r2 << " = " << r3 << endl;
  
  if (r1 < r2)
   cout << r1 << " is smaller than " << r2 << endl;
  else if (r1 == r2)
    cout << r1 << " is equal to " << r2 << endl;
  else
	cout << r1 << " is larger than " << r2 << endl;
}
