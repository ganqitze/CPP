#include <iostream>
#include <cstdlib>
using namespace std;

void H(){
	cout << " H   H" <<endl;
	cout << " H   H" <<endl;
	cout << " HHHHH" <<endl;
	cout << " H   H" <<endl;
	cout << " H   H" <<endl<<endl;
}
void E(){
	cout << " EEEEE" <<endl;
	cout << " E" <<endl;
	cout << " EEEE" <<endl;
	cout << " E" <<endl;
	cout << " EEEEE" <<endl<<endl;
}
void L(){
	cout << " L" <<endl;
	cout << " L" <<endl;
	cout << " L" <<endl;
	cout << " L" <<endl;
	cout << " LLLLL" <<endl<<endl;
}
void O(){
	cout << "  OOO " <<endl;
	cout << " O   O" <<endl;
	cout << " O   O" <<endl;
	cout << " O   O" <<endl;
	cout << "  OOO " <<endl <<endl;
}
void hue(){
	cout << "   !  " <<endl;
	cout << "   !  " <<endl;
	cout << "   !  " <<endl;
	cout << endl<< "   !  " <<endl<<endl;
}
void alpha(){
	H();
	E();
	L();
	L();
	O();
	hue();	
}
void accept(char alphabeth){
	switch(alphabeth){
		case 'h':
		case 'H': H();
						break;
		case 'e':
		case 'E': E();
						break;
		case 'l':
		case 'L': L();
						break;
		case 'o':
		case 'O': O();
						break;
		case '!': hue();
						break;						
	}
}
void accept6var(char a, char b, char c, char d, char e, char f){
	accept (a);
	accept (b);
	accept (c);
	accept (d);
	accept (e);
	accept (f);	
}
void rotate(char& a, char& b, char& c, char& d, char& e, char& f){
	char temp = a;
	a=b;
	b=c;
	c=d;
	d=e;
	e=f;
	f=temp;
}
void slow(){
	for(int i; i<=440000000; i++);

}
int main(){
	char a='H', b='E', c='L', d='L', e='O', f='!';
	do{
	system("cls");	
	accept6var(a, b, c, d, e, f);
	slow();
	rotate( a, b, c, d, e, f);
	slow();	
	}while(1);

}
