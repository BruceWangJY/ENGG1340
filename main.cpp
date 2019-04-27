#include "part.cpp"

int recommendTable(table tables[], int numA, int numB, int numC){
  int customers;
  cout << "Please input the number (no lager than 6) of customers: ";
  cin >> customers;
  cout << endl;
  if (customers <= 2){
    for (int i=0;i<numA;i++){
      if (tables[i].status=="available"){
        cout << "table A" << i+1<< " is suitable for a group of "<<customers << " customers\n"<< endl;
        return 0;
      }
    }
    cout << " No suitable table is available now\n"<<endl;
    return 0;
  }
  else if (customers <=4){
    for (int i=10;i<10+numB;i++){
      if (tables[i].status=="available"){
        cout << "table B" << i+1-10 << " is suitable for a group of "<<customers << " customers\n"<< endl;
        return 0;
      }
    }
    cout << " No suitable table is available now\n"<<endl;
    return 0;
  }
  else if (customers <=6){
    for (int i=20;i<20+numC;i++){
      if (tables[i].status=="available"){
        cout << "table C" << i+1-20 << " is suitable for a group of "<<customers << " customers\n"<< endl;
        return 0;
      }
    }
    cout << "No suitable table is available now\n"<<endl;
    return 0;
  }
  else{
    cout << "invalid number of customers\n" << endl;
    return 0;
  }
}


void checkTable(table tables[], int numA, int numB, int numC){
  char t;
  int n;
  cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
  cin >> t;
  cout << endl;
  while (t != '0'){
    switch (t){
      case 'A':cin >> n;
        if (n <=numA){
          cout <<"table "<< t << n << " is now "<<tables[n-1].status<< "\n"<<endl;break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'B':cin >> n;
        if (n <=numB){
          cout <<"table "<< t << n << " is now "<<tables[10+n-1].status<< "\n"<<endl;break;}
        else {cout << "input is invalid\n" << endl; break;}
      case 'C':cin >> n;
        if (n <=numC){
          cout <<"table "<< t << n << " is now "<<tables[20+n-1].status<< "\n"<<endl;break;}
        else {cout << "input is invalid\n" << endl; break;}
      default: cin >> n; cout << "input is invalid\n" << endl;
    }
    cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
    cin >> t;
    cout << endl;
  }
}


void changeSetting(int &numA, int &numB, int &numC){
  char t;
  int n;
  cout << "please input the type and No. of the table (e.g. A 1 to change the number of table A to 1) or 0 to return: ";
  cin >> t;
  cout << endl;
  while (t != '0'){
    switch (t){
      case 'A':
        cin >> n;
        numA=n;
        cout <<"the number of table "<< t << " is now changed to "<<n<< "\n"<<endl;
        break;
      case 'B':
        cin >> n;
        numB=n;
        cout <<"the number of table "<< t << " is now changed to "<<n<< "\n"<<endl;
        break;
      case 'C':
        cin >> n;
        numC=n;
        cout <<"the number of table "<< t << " is now changed to "<<n<< "\n"<<endl;
        break;
      default: cin >> n; cout << "input is invalid\n" << endl;
    }
    cout << "please input the type and No. of the table (e.g. A 1) or 0 to return: ";
    cin >> t;
    cout << endl;
  }
}


void printAll(table tables[], int numA, int numB, int numC){
    cout << "type    status" << endl;
    int i=0;
    while (i < 30){
      if (i>=numC+20) break;
      else if (i>=numB+10&&i<20) {i=20;continue;}
      else if (i>=numA&&i<10){i=10;continue;}
      tables[i].print();
      i++;
    }
    cout << endl;
}


int main () {
  table tables[30];
  for (int i=0;i<30;i++){
    if (i<10) {tables[i].type='A';tables[i].numb=i+1;}
    else if (i<20) {tables[i].type='B';tables[i].numb=i+1-10;}
    else {tables[i].type='C';tables[i].numb=i+1-20;}
  }
  int command,numA,numB,numC;
  while (true){
  cout << "Enter 1 to read from file for the table setting" <<endl;
  cout << setw(7)<<"2" <<" to randomly generate the setting or" << endl;
  cout << setw(7)<<"0" << " to end the program" <<endl;
  cout << "Please input your command: ";
  cin >> command;
  cout << endl;
  if (command == 1) {
    string filename;
    cout << "Please input the name of the file: ";
    cin >> filename;
    cout<<endl;
    char type;
    ifstream fin(filename.c_str());
    if ( fin.fail() ){
		  cout << "fail to open"<< filename << endl;
 		  exit(1);}
    while (fin >> type){
      switch (type){
        case 'A': fin >> numA; break;
        case 'B': fin >> numB; break;
        case 'C': fin >> numC; break;
        default: cout << "content is invalid\n" << endl;
      }
    }
    fin.close();
    printAll(tables,numA,numB,numC);
  }
  else if (command == 2) {
    srand((unsigned)time(NULL));
    numA=(rand() % (7))+1;
    numB=(rand() % (4))+1;
    numC=(rand() % (3))+1;
    printAll(tables,numA,numB,numC);
  }
  else if (command ==0) return 0;
  while (true){
    cout << "1 occupy a table" << endl;
    cout << "2 release a table" << endl;
    cout << "3 reserve a table" << endl;
    cout << "4 recommend a table" << endl;
    cout << "5 check the status of a table" << endl;
    cout << "6 show current status of all table" << endl;
    cout << "7 change the table setting" << endl;
    cout << "8 cancle a reservation" << endl;
    cout << "9 initialization" << endl;
    cout << "0 end the program" << endl;
    cout << endl;
    cout << "Please input the number of your command: ";
    cin >> command;
    cout << endl;
    int k;
    k=0;
    switch (command){
      case 0: return 0;
      case 1: occupyTable(tables,numA,numB,numC);break;
      case 2: releaseTable(tables,numA,numB,numC);break;
      case 3: reserveTable(tables,numA,numB,numC);break;
      case 4: recommendTable(tables,numA,numB,numC);break;
      case 5: checkTable(tables,numA,numB,numC);break;
      case 6: printAll(tables,numA,numB,numC);break;
      case 7: changeSetting(numA,numB,numC);break;
      case 8: releaseTable(tables,numA,numB,numC);break;
      case 9: for(int i=0;i<30;i++)tables[i].status="available";
              k=1;
              break;
    }
    if (k==1)break;
  }
  }
  return 0;
}
