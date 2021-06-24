#include <iomanip>
#include <string>
#include <iostream>
#include <cmath>

using namespace std;

void DoAddition( long long int x,  long long int y, long long int& prev);
void DoMulti( long long int x,  long long int y, long long int& prev);
void DoSubtract( long long int x,  long long int y, long long int& prev);
void DoDivision( long long int x, long long int& prev);
int IdentifyOp(string val);
void BreakUp( long long int& x, long long int& y, string& z, string tmp);



int main(){
	string tmp;
	int loops = 0;
	long long int preCalc = 1;
	string oper;
	long long int a = 0;
	int i = 0;
	long long int b = 0;
	
	getline(cin,tmp);
	loops = stoi(tmp);
	
	while(i < loops){
		getline(cin,tmp);
	
		BreakUp(a,b,oper,tmp);
	
		if(IdentifyOp(oper) == 0){
			DoAddition(a,b,preCalc);
		}else if(IdentifyOp(oper) == 1){
			DoSubtract(a,b,preCalc);
		}else if(IdentifyOp(oper) == 2){
			DoDivision(a,preCalc);
		}else if(IdentifyOp(oper) == 3){
			DoMulti(a,b,preCalc);
		}
		
		i++;
	}

	
	return 0;
}

void BreakUp( long long int& x, long long int& y, string& z, string tmp){
	string var;
	
	
	while(tmp != ""){
			var = tmp.substr(0,tmp.find(" "));
			x = stoi(var);
			tmp.erase(0,tmp.find(" ")+1);
			z =  tmp.at(0);
			tmp.erase(0,tmp.find(" ")+1);
			y = stoi(tmp);
			tmp = "";
	}
	
	return ;
}


int IdentifyOp(string val){
	int rv = 0;
	
	if( val == "+"){
		rv = 0;
	}else if(val == "-"){
		rv = 1;
	}else if(val == "/"){
		rv = 2;
	}else if(val == "*"){
		rv = 3;
	}else{
		rv = 4;
	}
	
	return rv;
	
}

void DoAddition( long long int x,  long long int y, long long int& prev){
	long long int rv = 0;
	
	rv = x + y;
	
	rv = rv - prev;
	
	cout << rv << endl;
	prev = rv;
	
	return ;
}
void DoMulti( long long int x,  long long int y, long long int& prev){
	long long int rv = 0;
	
	rv = pow((x*y),2);

	cout << rv << endl;
	prev = rv;
	
	return ;
}


void DoSubtract( long long int x,  long long int y, long long int& prev){
	long long int rv = 0;
	
	rv = x - y;

	rv = rv * prev;
	cout << rv << endl;
	prev =  rv;
	
	return ;
}
void DoDivision( long long int x, long long int& prev){
	long long int rv = 0;
	
	if((x % 2) > 0){
		rv = (x+1)/2;
	}else{
		rv = x/2;
	}
	
	cout << rv << endl;
	prev = rv;
	
	return ;
}
