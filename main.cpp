#include <iostream>
#include<fstream>
#include<string>

using namespace std;


// -----------COLORS WE USE--------------------------------------------------

const string BLUE   = "\033[34m";
    const string YELLOW = "\033[33m";
    const string RED    = "\033[31m";
    const string GREEN  = "\033[32m";
    const string RESET  = "\033[0m";  // DEFOULT COLOR

 // --------------GLOBAL VARIYABLES ------------------------------------------
string username;
string name;
string fileName;


// --------------- Struct -----------------------------------------------------

struct userInfo
{
  string name;
  string userName;
  int password;
};


// -----------------   array --------------------------------------------
// string file[n];

// ------------- Declar non return type functions -----------------------------

void CheekUser(string username , int pass);
void Admins();
void Users();

// ---------------------------------------------------------------

 bool CreateFile(string fileName);
 bool UserRegister(userInfo* u);
 bool UpdateFile(string filesName);
 bool AddData(string filesName);
 string ReadFile(string filesName);


// ---------------LOGO-------------------------------------------

void logo1(){
    cout << GREEN   << "     ================================  "<<endl;
    cout <<            "     =                              =  "<<endl;
    cout <<            "     =    "<<RED<< "     DIGITAL FILE  "<<GREEN<<"       =  "<<endl;
    cout <<            "     =    "<<RED<<"        SYSTEM   "<<GREEN<<"         = "<<endl;
    cout <<            "     =                              = "<<endl;
    cout <<            "     ==============================="<<RESET<<endl;
}

void logo2(){
      cout << RED<<  "         ............................................ "<<endl;
      cout <<        "         .                                          . "<<endl;
      cout <<        "         .            WELCOME MR."<<name<<"              . "<<endl;
      cout <<        "         .                                          . "<<endl;
      cout <<        "         ............................................  "<<RESET<<endl;

}


int main(){
   int choice;
   userInfo user;
   logo1();
   do{
    cout << " "<<endl;
    cout << " "<<endl;
    cout << " 1. Log in "<<endl;
    cout << " 2. Register "<<endl;
    cout << " 0. exit"<<endl;
    cout << " Enter ur choise: ";
    cin>>choice;
    system("clear");       // bulid in function that let us to excute comands like 'clear' 'ls'
    switch (choice)
    {
    case 1:{
        int pass;
      cout << "Enter username: ";
      cin>>username;
      cout << "Enter password: ";
      cin>>pass;
      cout << " "<<endl;
      system("clear");
      CheekUser(username,pass);  // got to cheekUser function and turn back after exctuation
     break;
    }
    case 2:{
      if(UserRegister(&user)){
          cout << "User seccussfully registered! "<<endl;
      }
    }
      break;
    case 0:
      break;
    default:
     cout << RED<< "Invalid INPUT! please try again! "<<RESET<<endl;
      break;
    }
}while(choice!=0);
}

//----------------------REGISTER USERS AND STORE THERE DATA--------------------------

bool UserRegister(userInfo* u){
   string userNameCheek;
   string data;
   string R;


ofstream fout("YotorDb.txt",ios::app);
    cout << " please Enter the following steps to rigister!"<<endl;
    cout << " "<<endl;
    cout << " 1. please Enter ur Name: ";
    cin>>u->name;
    cout << " 2. Enter username: ";
    cin>>u->userName;
    cout << " 3. Enter password: ";
    cin>>u->password;
     ifstream fin("YotorDb.txt");
     while(fin>>userNameCheek){
          // CLOSE AFTER STORING ONLY USERNAMES
      }
        if(u->userName == userNameCheek){
           cout << "Username already used please try again! ";
        }else{
           string cmd = "mkdir " + u->userName;
        system(cmd.c_str());
        fout << u->userName << " User "/* DEFOULT ROLE */ << u->password <<  " " << u->name << " " <<endl;
       }
  fout.close();
  fin.close();
  return true;
}


// ---------------------CHEEKING USERS AND THERE ROLE-----------------------

void CheekUser(string ,int pass){

  ifstream fin("YotorDb.txt");
  string u,r;
  int p;

while(fin>>u>>r>>p>>name){
if( u == username && p == pass && r == "Admin"){
  Admins();
}else if( u == username && p == pass){
  system("clear");
  logo2();
  Users();
}else{
  cout << RED<< "invalid username or password! please try again! "<<RESET<<endl;
}
};
}

// ---------------------ADMINS PAGE ----------------------------------------

void Admins(){
bool DeleteUser(string uname);
bool AddAdmin(string uname);
void ViewDatabase();
void ViewUserFiles(string uname);


    cout << GREEN << "ADMIN PANEL\n" << RESET;
    system("cat YotorDb.txt");
  int AdminChoise;
  string u;
  do{
  system("clear");  // allow to excute clear cmd to get clean terminal but it works only for mac users
  cout << "WELCOME BACK "<<username<<" \n. You are Admin of the system! "<<endl;
  cout << " "<<endl;
  cout << "   what are you locking for! \n         1.DELETE users file\n         2.ADD Admin\n         3.View DATABASE\n         4.View USER DATA\n         0.exit"<<endl;
  cout << "Enter your choise: ";
  cin>>AdminChoise;
   switch (AdminChoise) {
        case 1:
            cout<<"enter username to delete: ";
            cin>>u;
            DeleteUser(u);
            break;
        case 2:
            cout << "Enter username to make admin: ";
            cin >> u;
            AddAdmin(u);
            break;
        case 3:
            ViewDatabase();
            break;
        case 4:
            cout<<"enter username: ";
            cin>>u;
            ViewUserFiles(u);
            break;

        case 5:
            cout << "Exiting admin panel...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }


  }while(AdminChoise != 0);
}






// ----------------------USER PAGE --------------------------------------

void Users(){
  int Uchoise;
//  cout << " WELCOME  USER " <<  name <<endl;
cout << " "<<endl;
cout << " "<<endl;
do{
  cout << "   what are you locking for! \n         1.CREATE FILE\n         2.UPDATE A FILE(REWRITE)\n         3.ADD DATA TO A FILE\n         4.FILE LIST\n         5.READ FILE\n         0.exit"<<endl;
  cout << " Enter your choice: ";
  cin>>Uchoise;
  cout << " "<<endl;


  switch (Uchoise)
  {
  case 1:{
    int s;
    string file[s];
    cout << "Enter number of file you want to create: ";
    cin>>s;
    for(int i = 0;i<s;i++){
   cout << "Enter file name: ";
    cin>>file[i];
    cout << " "<<endl;
    if(CreateFile(file[i])){
    cout << "File created("<<file[i]<<".txt)!"<<endl;
   }   else {
    cout << RED << "UNKOWN error! "<<RESET<<endl;
   }
  }
    }
    break;
  case 2:{
    string fName;
    cout << "Enter file Name: ";
    cin>>fName;
   if(UpdateFile(fName)){
    cout << "File " << fName << " UPDATED! "<<endl;
   }  else {
    cout << RED << "UNKOWN error! "<<RESET<<endl;
   }
  }
    break;
  case 3:{
    string fName;
    cout << "Enter file name: ";
    cin>>fName;
     if(AddData(fName)){
    cout << "File " << fName << " UPDATED! "<<endl;
   }  else {
    cout << RED << "UNKOWN error! "<<RESET<<endl;
   }
  }
    break;
  case 4:{
    string comand = "ls ./" + username;
    system(comand.c_str());
  }
    break;
  case 5:{
    string fName;
    cout << "Enter file name to read: ";
    cin>>fName;
    cout << ReadFile(fName) <<endl;
  }
    break;
  case 0:
   break;
  default:
   cout << RED<< "Invalid INPUT! please try again! "<<RESET<<endl;
    break;
  }
}while (Uchoise != 0);
}


// ---------------- user fuctions ----------------------------

bool CreateFile(string f){
  string data;
  string comand = username + "/" + f + ".txt";
  ofstream fout(comand.c_str(),ios::app);
  cout << "Enter your Data Here: ";
  cin.ignore(); // to handele auto enter key
  getline(cin,data);
  fout << data <<endl;
  fout.close();
  return true;
}


bool UpdateFile(string filesName){
  string data;
  string comand = username + "/" + filesName + ".txt";
  ofstream fout(comand.c_str(),ios::out);
  cout << "Enter New Data: ";
  cin.ignore();
  getline(cin,data);
  fout << data <<endl;
  return true;
}

bool AddData(string filesName){
  string data;
  string comand = username + "/" + filesName + ".txt";
  ofstream fout(comand.c_str(),ios::app);
  cout << "Enter the data you want add to a file "<<filesName<<": ";
  cin.ignore();
  getline(cin,data);
  fout << data <<endl;
  return true;
}

string ReadFile(string filesName){
    string data;
  string comand = username + "/" + filesName + ".txt";
  ifstream fin(comand.c_str());
//  cin.ignore(); // to handele auto enter key
  getline(fin,data);
  fin.close();
  return data;
}


// --------------- Admins function ------------------





/*

bool DELETE(string file, int){
  cout << file <<endl;

  // string COMAND = "./" + username ; // + file

 //  system("rm" + c_str(COMAND) ) ;
}

*/














