#include <iostream>
#include <iomanip>
using namespace std;

// Juan Carlos Juárez
//This Project is a mathematical concept developed by Juan Carlos Juárez, still in research

void SUVP(){
  double numGlobal=0, numCentral=0, numBegin=0, numCurr=0, numPast=0;
  double vP1=0, vP2=0, vP3=0, vP4=0;

  cout << endl;
  cout << "Enter the main number: ";
  cin >> numGlobal;
  cout << endl;
  cout << endl;

  numCentral=numGlobal/2;
  numPast=numCentral;

  for(int cont=0; cont<100; cont++){
    if(cont<2){
      numCurr=(numBegin+numPast)/2;
        if(cont==1){
          numBegin=numPast;
        }
      numPast=numCurr;
    }
    else{
      numCurr=(numBegin+numPast)/2;
      numBegin=numPast;
      numPast=numCurr;
    }
  }

  cout << "Vacuous Point 1: " << setprecision(20) << numCurr << endl;
  cout << endl;
  cout << "Vacuous Point 2: " << setprecision(20) << numCentral-numCurr << endl;
  cout << endl;
  cout << "Vacuous Point 3: " << setprecision(20) << numCentral+numCurr << endl;
  cout << endl;
  cout << "Vacuous Point 3: " << setprecision(20) << numGlobal-numCurr << endl;
}

void SPVP(){
  double numGlobal=0, numCentral=0, numBegin=0, numCurr=0, numPast=0, numPastStatic=0;
  double vP1=0, vP2=0, vP3=0, vP4=0, vTP3=0;
  double prevVTP3=0;
  double vTP3Change=0;
  int k=0;
  bool oscillator=false;
  
  do{
  cout << endl;
  cout << "Enter the main number: ";
  cin >> numGlobal;
  cout << "Enter the proportionality constant: ";
  cin >> k;
  cout << endl;
  cout << endl;
  }while(k<1 || k%1!=0);

  numCentral=numGlobal/2;
  numPast=numCentral;

  for(int cont=1; cont<=100; cont++){

    if(cont<3){
      numPastStatic=numCurr;
      numCurr=(numBegin+numPast)/2;
        if(cont==2){
          numBegin=numPast;
        }
      numPast=numCurr;
    }
    else{
      numPastStatic=numCurr;
      numCurr=(numBegin+numPast)/2;
      numBegin=numPast;
      numPast=numCurr;
    }

    
    
    if(oscillator==false){
      if(cont>0){
        prevVTP3=vTP3;
        vTP3Change=(numCurr-numPastStatic);
        if(vTP3Change<0)
          vTP3Change=vTP3Change*-1;
        vTP3=vTP3+vTP3Change;
        /*
        cout << cont << endl;
        cout << prevVTP3 << " "<< numCurr << " " << numPastStatic << endl;
        cout << vTP3 << endl;
        cout << vTP3+numCentral << endl;
        cout << "-------------------"<<endl;
        */
      }
    }
    else{
      if(cont>0){
        prevVTP3=vTP3;
        vTP3Change=(numCurr-numPastStatic);
        if(vTP3Change<0)
          vTP3Change=vTP3Change*-1;
        vTP3=vTP3-vTP3Change;
        /*
        cout << cont << endl;
        cout << prevVTP3 << " "<< numCurr << " " << numPastStatic << endl;
        cout << vTP3 << endl;
        cout << vTP3+numCentral << endl;
        cout << "-------------------"<<endl;
        */
      }
    }
    
    if(cont%(k)==0){
      if(oscillator==true)
        oscillator=false;
      else
        oscillator=true;
    }
    
  }
  /*
  cout << "Vacuous Point 1: " << setprecision(20) << numCurr << endl;
  cout << endl;
  cout << "Vacuous Point 2: " << setprecision(20) << numCentral-numCurr << endl;
  */
  cout << endl;
  vP3=numCentral+vTP3;
  if(vP3<=0.1){
    cout << "Vacuous Point 3 tends to its lower limit." << endl;
  }
  else if(vP3>=(numGlobal-0.1)){
    cout << "Vacuous Point 3 tends to its upper limit." << endl;
  }
  else{
  cout << "Vacuous Point 3: " << setprecision(20) << vP3 << endl;
  }
  cout << endl;
  /*
  cout << "Vacuous Point 3: " << setprecision(20) << numGlobal-numCurr << endl;
  */
}

int main() {
  
  char x;
  cout << "Change lower limit from 0 to someyhinge elsee";
  cout << endl;
  cout << "*****Real Vacuous Points Calculator*****" << endl;
  cout << endl << endl;
  cout << "Please select the real vacuous point type: " << endl;
  cout << endl;
  cout << "1) Symmetrical Unitary Vacuous Points." << endl;
  cout << "2) Symmetrical Proportional Vacuous Points." << endl;
  cout << endl;
  cin >> x;
  switch (x){
    case '1':{
      SUVP();
      break;
    }
    case '2':{
      SPVP();
      break;
    }
    break;
  }
}