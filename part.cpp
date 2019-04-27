#include "classtable.h"

void timeRestrict(table A){
  while (true){
    if (A.type=='A'||A.type=='B'){
      if ((double)(clock()-A.starttime)/CLOCKS_PER_SEC>=30){
        cout << "\ntable " << A.type << A.numb << " has been occupied for too long" << endl;
        break;
      }
    }
    else{
      if ((double)(clock()-A.starttime)/CLOCKS_PER_SEC>=45){
        cout << "\ntable " << A.type << A.numb << " has been occupied for too long" << endl;
        break;
      }
    }
  }
}

void timming(table A){
  thread t(timeRestrict,A);
  t.detach();
}

void occupyTable(table tables[], int numA, int numB, int numC){
  cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
  char t;
  int n;
  cin >> t;
  cout << endl;
  while (t != '0'){
    switch (t){
      case 'A': cin >> n;
        if (n <=numA){
          tables[n-1].occupy();
          timming(tables[n-1]);
          cout << t << n<< " is occupied\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'B': cin >> n;
        if (n <=numB){
          tables[10+n-1].occupy();
          timming(tables[10+n-1]);
          cout << t << n << " is occupied\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'C': cin >> n;
        if (n <=numC){
          tables[20+n-1].occupy();
          timming(tables[20+n-1]);
          cout << t << n << " is occupied\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      default: cin >> n;cout << "input is invalid\n" << endl;
    }
    cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
    cin >> t;
    cout << endl;
  }
}


void releaseTable(table tables[], int numA, int numB, int numC){
  cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
  char t;
  int n;
  cin >> t;
  cout << endl;
  while (t != '0'){
    switch (t){
      case 'A': cin >> n;
        if (n <=numA){
          tables[n-1].status="available";
          cout << t << n << " is released\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'B': cin >> n;
        if (n <=numB){
          tables[10+n-1].status="available";
          cout << t << n << " is released\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'C': cin >> n;
        if (n <=numC){
          tables[20+n-1].status="available";
          cout << t << n << " is released\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      default: cin >> n;cout << "input is invalid\n" << endl;
    }
    cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
    cin >> t;
    cout << endl;
  }
}


void reserveTable(table tables[], int numA, int numB, int numC){
  cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
  char t;
  int n;
  cin >> t;
  cout << endl;
  while (t != '0'){
    switch (t){
      case 'A': cin >> n;
        if (n <= numA){
          tables[n-1].status="reserved" ;
          cout << t << n << " is reserved\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'B': cin >> n;
        if (n <= numB){
          tables[10+n-1].status="reserved" ;
          cout << t << n << " is reserved\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'C': cin >> n;
        if (n <= numC){
          tables[20+n-1].status="reserved" ;
          cout << t << n << " is reserved\n"<<endl; break;}
        else {cout << "input is invalid\n" << endl; break;}
      default: cin >> n; cout << "input is invalid\n" << endl;
    }
    cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
    cin >> t;
    cout << endl;
  }
}
