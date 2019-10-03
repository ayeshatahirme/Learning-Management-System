////////////////////////////PROGRAM FOR REGISTRATION OF STUDENT AND COURSES////////////
#include<iostream>
#include<iomanip>
#include<cstring>
#include<sstream>
#include<fstream>
#include<cmath>

using namespace std;

int l=0;
int t=0;

//Bool functions//

bool isValidCourseCode(string code)
{
	bool flag=false;

	if(code.length()<=5)
	{
		for(int i=0;i<2;i++)
		{
			if((code[i]>='a')&&(code[i]<='z')||(code[i]>='A')&&(code[i]<='Z'))
			flag=true;
			else
			flag=false;
		}
	
		for(int i=2;i<5;i++)
		{
			if((code[i]>='0')&&(code[i]<='9'))
			flag=true;
			else
			flag=false;
		}
	}
	else
	flag=false;

return flag;
}

bool isValidCreditHours(int crdHrs)
{
	bool flag=false;	

	if((crdHrs>0)&&(crdHrs<4))
	{
		flag=true;
	}
	else
	{
		flag=false;
	}

return flag;
}

bool isValidSemester(int semester)
{
	bool flag=false;
	
	if(semester>=1 && semester<=8)
	{
		flag=true;
	}
	else
	{
		flag=false;
	}

return flag;
}

bool isValidCourseName(string name)
{
	string s=name;
	bool flag=false;
	
	if(name.length()<=50)
	{
		for(int i=0; i<name.length();i++)
		{
			if((name.at(i)>=65&&name.at(i)<=90)||(name.at(i)>=97 && name.at(i)<=122)||(name.at(i)== 32))
			
			{
				flag=true;
			}
			else
			{
				flag=false;
			}
		}
	}

return flag;
}

bool saveCourse (string codeList[], string nameList[], int crtHrsList[], int semList[], int h)
{
	bool flag=false;
	
	ofstream outfile;
	outfile.open("Courses.txt");
	
	if(flag==false)
	{
		for(int i=0; i<l; i++)
		{
			outfile<<codeList[i]<<","<<nameList[i]<<","<<crtHrsList[i]<<","<<semList[i];
		}
		outfile<<endl;
		l++;
    }
	else
	flag==true;
	
	outfile.close();
	
return flag;
}

bool does_file_exist(const char *filename)
{
    ifstream infile(filename);
    return infile.good();
}

bool isValidData(string arr[],string arr1[],string pas,string user, int s)
{
	bool flag=true;
	
	for (int i=0;i<s;i++)
	{
		if (arr[i]==user && arr1[i]==pas)
		{
			flag=false;
		}
		else
		{
			flag=true; 
		}			
	}
	return flag;
}

bool isValidyear(string year)
{
	bool flag=false;	

	if(year.length()>0 && year.length()<6)
	{
		flag=true;
	}	
	else
	{
		flag=false;
	}
	
return flag;
}

bool isValiddept(string disp)
{
	bool flag=false;	

		for(int i=5;i<7;i++)
	{
		if((disp[i]>='a')||(disp[i]<='z')||(disp[i]>='A')||(disp[i]<='Z'))
		{
			flag=true;
		}
		else
		{
			flag=false;
		}
	}
	
return flag;
}

bool isValidroll_no(string rollno)
{

	bool flag=false;	

	if(rollno.length()>0 && rollno.length()<300)
	{
		flag=true;
	}
	else
	{
		flag=false;
	}
	
return flag;
}

bool isValidname(string name)

{	
	bool flag=false;

	if(name.length()<=100)
	{
		for(int i=0;i<100;i++)
		{
			if((name[i]>='a') || (name[i]<='z') || (name[i]>='A') || (name[i]<='Z') || (name[i]=' '))
			flag=true;
			else
			flag=false;
		}
	}

return flag;
}


bool saveStudents(string stdNamesList[], string stdRegNoList[], string studentName[], string regNo[], string courseCode[], string stdCourseList1[])
{
	ofstream outfile;
	outfile.open("Students.txt");
	
	int k=2;
	int j=1;
	string Fnames[100];
		
	bool flag=false;
	bool valid_flag=false;
	
	if(flag==false)
	{
		cout<<" Enter your full name please: ";
		getline(cin,Fnames[k],' ');
		getline(cin,Fnames[j]);
		
		for( int i=1; i<l; i++)
		{
			while (valid_flag==false)
			{
				outfile<<regNo[i]<<"-"<<stdRegNoList[i]<<"-"<<courseCode[i]<<","<<Fnames[k]<<" "<<Fnames[j];
				outfile<<stdCourseList1[i];								
				valid_flag=true;
			}
		}
		outfile<<endl;
		l++;
	}
	else
	{
		flag=true;
	}
	
	outfile.close();

return flag;
}

//***********************************************************************************************************************************//

//Void functions//

void AddCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int h) 
{
	string courseCode,courseName;
	int crdHrs,semester;

	bool t=false;

	while(t==false)
	{
		cout<<" Enter details of course (For Example: CS101 3 1 Programming Fundamentals): ";
		cin>>courseCode>>crdHrs>>semester;
		getline(cin,courseName);
		
		bool a=isValidCourseCode(courseCode);
		bool x=isValidCreditHours(crdHrs);
	    bool y=isValidSemester(semester);
	    bool z=isValidCourseName(courseName);
	    
	    if(a==true&&x==true&&y==true&&z==true)
		{
			codeList[l]=courseCode;
			crtHrsList[l]=crdHrs;
			nameList[l]=courseName;
			semList[l]=semester;
			t=true;
			cout<<"\n Course has been added successfully."<<endl<<endl;
			l++;
		}
		else
		{
			cout<<" Details you entered are not valid";
		}
	}
}

void EditCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int h)
{
	string courseCode,courseName;
	int crdHrs,semester;
	
	bool t=false;
	cout<<" Enter course code to edit: ";
	cin>>courseCode;
	
	while(t==false)
	{
		cout<<" Enter new details of the course: ";
		cin>>courseCode>>crdHrs>>semester;
		getline(cin,courseName);		
		
		bool a=isValidCourseCode(courseCode);
		bool x=isValidCreditHours(crdHrs);
		bool y=isValidSemester(semester);
		bool z=isValidCourseName(courseName);
		if(a==true&&x==true&&y==true&&z==true)
		{
			codeList[t]=courseCode;
			crtHrsList[t]=crdHrs;
			nameList[t]=courseName;
			semList[t]=semester;
			cout<<"\n Course has been edited successfully."<<endl<<endl;
			t=true;
		}
		else
		{
			cout<<" Delails you entered are not valid."<<endl;
		}
	}
}
void DeleteCourse(string codeList[], string nameList[], int crtHrsList[], int semList[], int h) 
{
	string courseCode;

	cout<<" Enter course code to delete: ";
	cin>>courseCode;
	
	int waste=0;
	
	bool a=isValidCourseCode(courseCode);

	if(a==true)
	{
		for(t=0;t<l;t++)
		{
			if(courseCode==codeList[t])
			{
				string valid=codeList[t];
				codeList[t]=codeList[t+1];
				codeList[t+1]=valid;
				
				string valid1=nameList[t];
				nameList[t]=nameList[t+1];
				nameList[t+1]=valid1;
				
				int valid3=semList[t];
				semList[t]=semList[t+1];
				semList[t+1]=valid3;
				
				int valid4=crtHrsList[t];
				crtHrsList[t]=crtHrsList[t+1];
				crtHrsList[t+1]=valid4;
				
				crtHrsList[t+1]='\0';
				semList[t+1]='\0';
				nameList[t+1]='\0';
				codeList[t+1]='\0';
								
			}
		}
	}
	
	cout<<" Your course "<<courseCode<<" has been deleted."<<endl<<endl;
}
void ViewCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int h) 
{ 
	cout<<endl<<setw(5);
	cout<<setw(15)<<"Course Code";
	cout<<setw(15)<<"Course Name";
	cout<<setw(15)<<"Credit Hours";
	cout<<setw(11)<<"Semester";

	for(int i=0; i<l; i++)
	{
		cout<<endl<<setw(5);
		cout<<setw(15)<<codeList[i];
		cout<<setw(15)<<nameList[i];
		cout<<setw(15)<<crtHrsList[i];
		cout<<setw(11)<<semList[i];	
	}
	l++;
}
void ViewSemesterCourses(string codeList[], string nameList[], int crtHrsList[], int semList[], int h)
{
	int semester;
	
	cout<<" Enter the semester: ";
	cin>>semester;
	
	bool w=isValidSemester(semester);
	
	if(w==true)
	{
		cout<<endl<<setw(5);
	    cout<<setw(15)<<"Course Code";
	    cout<<setw(15)<<"Course Name";
	    cout<<setw(15)<<"Credit Hours";
	    cout<<setw(11)<<"Semester"<<endl;
	    
		for (int i=0; i<h; i++)
		{
			if(semester==semList[i])
			{
				cout<<endl<<setw(5);
				cout<<setw(15)<<codeList[i];
				cout<<setw(15)<<nameList[i];
				cout<<setw(15)<<crtHrsList[i];
				cout<<setw(11)<<semList[i];
			}
		}
		
	cout<<endl;
}
	else
	{
		cout<<" Invalid input.\n";
	}
}

void loadCourses(string codeList[],string nameList[],int crtHrs[],int semList[],ifstream &outfile, int i,int b, int &n)
{
	n=0;
	char ch;
  	
	for (int j=i;j<b && outfile!=0;j++)
	{   getline(outfile,codeList[j],',');
	     getline(outfile,nameList[j],',');
	     outfile>>crtHrs[j]>>ch;
	     outfile>>semList[j];
		n++;
	}
}

void loadStudents(string stdNamesList[], string stdRegNoList[], string studentName[], string regNo[],ifstream &Students, int i,int b, int &n)
{
	n=0;
	char ch;
  	
	for (int j=i;j<b && Students!=0;j++)
	{   getline(Students,stdNamesList[j],',');
	    getline(Students,stdRegNoList[j],',');
	    Students>>studentName[j]>>ch;
	    Students>>regNo[j];
		n++;
	}
}

void loadUsers(string arr[], string arr1[], ifstream &data, int &counter, int s)
{
	counter=0;
	
	for (int k=0; data!=0 && k<100; k++)
	{
		getline(data,arr[k],',');
		getline(data,arr1[k]);
		counter++;
	}
}

void addStudent(string stdNamesList[], string stdRegNoList[], string studentName[], string regNo[], int h)
{
	bool flag=false;
	
	int j=0;
	string name[100], year[10], dept[10], roll_no[10];
	
	while(flag==false)
	{
		cout<<" Enter details of student (For Example: 2018-CS-22 Muhammad Abdullah): ";
		{
			getline(cin,year[j],'-');
			getline(cin,dept[j],'-');
			getline(cin,roll_no[j],' ');
			getline(cin,name[j]);
			
			string w=year[j];
			string x=dept[j];
			string y=roll_no[j];
			string z=name[j];
			
			bool a=isValidyear(w);
			bool b=isValiddept(x);
			bool c=isValidroll_no(y);
			bool d=isValidname(z);
				
			if(a==true && b==true && c==true && d==true)
			{
				regNo[l]=year[j];
				stdNamesList[l]=dept[j];
				stdRegNoList[l]=roll_no[j];
				studentName[l]=name[j];
				
				cout<<endl<<" Student has been added successfully."<<endl<<endl;
				l++;
				j++;
				flag=true;
			}
			else
			{
				cout<<" Details you entered are not valid";
			}
		}
	}
}

void updateStudent(string stdNamesList[], string stdRegNoList[], string studentName[], string regNo[]) 
{
	bool flag=false;
	int j=0;
	string name[100], year[10], dept[10], roll_no[10], year1[10], dept1[10], roll_no1[10];
	
	while(flag==false)
	{
		cout<<" Enter registration number of student to edit: ";
		{
			getline(cin,year1[l],'-');
			getline(cin,dept1[l],'-');
			getline(cin,roll_no1[l]);
			
			cout<<" Enter new details of the student: ";
			
			getline(cin,year[j],'-');
			getline(cin,dept[j],'-');
			getline(cin,roll_no[j],' ');
			getline(cin,name[j]);
			
			string w=name[j];
			string x=year[j];
			string y=dept[j];
			string z=roll_no[j];
			
			bool a=isValidyear(x);
			bool b=isValiddept(y);
			bool c=isValidroll_no(z);
			bool d=isValidname(w);
			
			if(a==true && b==true && c==true && d==true)
			{
				for(int i=0; i<l; i++)
				{
					if(year1[l]==regNo[i] && dept1[l]==stdNamesList[i] && roll_no1[l]==stdRegNoList[i])
					{
						regNo[i]=year[j];
						stdNamesList[i]=dept[j];
						stdRegNoList[i]=roll_no[j];
						studentName[i]=name[j];
						
						cout<<endl<<" Course has been edited successfully."<<endl<<endl;
						flag=true;
						
					}
					else
					{
						cout<<" Details you entered are not valid"<<endl;
					}
				}
				l++;
				j++;
			}
			else
			cout<<" Invalid data."<<endl;		
		}

	}
}

void deletestudent(string stdNamesList[], string stdRegNoList[], string studentName[], string regNo[])
{
	bool flag=false;
	
	int j=0;
	string name[100], year[10], dept[10], roll_no[10];
	
	while(flag==false)
	{
		
		cout<<" Enter registration number of student to delete: ";
		
		getline(cin,year[l],'-');
		getline(cin,dept[l],'-');
		getline(cin,roll_no[l]);
		
		bool a=isValidyear(year[l]);
		bool b=isValiddept(dept[l]);
		bool c=isValidroll_no(roll_no[l]);
		
		if(a==true && b==true && c==true)
		{
			for(int t=0;t<=l;t++)
			{
				if(year[l]==regNo[t] && dept[l]==stdNamesList[t] && roll_no[l]==stdRegNoList[t])
				{
					string valid=regNo[t];
					regNo[t]=regNo[t+1];
					regNo[t+1]=valid;
					
					string valid1=stdNamesList[t];
					stdNamesList[t]=stdNamesList[t+1];
					stdNamesList[t+1]=valid1;
					
					string valid3=stdRegNoList[t];
					stdRegNoList[t]=stdRegNoList[t+1];
					stdRegNoList[t+1]=valid3;
					
					string valid4=studentName[t];
					studentName[t]=studentName[t+1];
					studentName[t+1]=valid4;
					
					regNo[t+1]='\0';
					stdNamesList[t+1]='\0';
					stdRegNoList[t+1]='\0';
					studentName[t+1]='\0';
					
					cout<<" Student of registration number "<<year[l]<<"-"<<dept[l]<<"-"<<roll_no[l]<<" has been deleted."<<endl<<endl;
					l++;
				}
				else
				{
					cout<<" Registration number you entered is not available.";
				}
			 }	
		}
		else
		{
			cout<<" Details you entered are not valid\n";
		}
		flag=true;
		
	}
}

void Viewstudents(string stdNamesList[], string stdRegNoList[], string studentName[], string regNo[])
{ 
	cout<<endl<<setw(5);
	cout<<setw(15)<<"Session";
	cout<<setw(15)<<"Department";
	cout<<setw(15)<<"Roll Number";
	cout<<setw(11)<<"Name";

	for(int i=0; i<l; i++)
	{
		cout<<endl<<setw(5);
		cout<<setw(15)<<regNo[i];
		cout<<setw(15)<<stdNamesList[i];
		cout<<setw(15)<<stdRegNoList[i];
		cout<<setw(13)<<studentName[i];
	}
	l++;
	cout<<endl;
}

void registerCourse(string stdRegNoList1[], string stdCourseList1[], string courseCodeList1[], string stdNamesList1[], string regNo1[], string courseCode1[])
{
	string name1[100], year1[10], dept1[10], roll_no1[10];
	string coursecode;
	
	cout<<" Enter registration number of student for course registration: ";
	getline(cin,year1[l],'-');
	getline(cin,dept1[l],'-');
	getline(cin,roll_no1[l]);
	
	string w=year1[l];
	string x=dept1[l];
	string y=roll_no1[l];
	
	bool a=isValidyear(w);
	bool b=isValiddept(x);
	bool c=isValidroll_no(y);
	
	if(a==true && b==true && c==true)
	{
		regNo1[l]=year1[l];
		stdNamesList1[l]=dept1[l];
		stdRegNoList1[l]=roll_no1[l];
		
		cout<<" Enter course code to register: ";
		cin>>coursecode;
		
		bool a=isValidCourseCode(coursecode);
		
		if(a==true)
		{
			stdCourseList1[l]=coursecode;
			cout<<"\n Course has been registered for student.";
		}
		else
		{
			cout<<"\n Invalid data.";
		}
		l++;
	}
}

void unRegisterCourse(string stdNamesList[], string stdRegNoList[], string studentName[], string regNo[], string coursecode[])
{
	bool flag=false;
	
	int j=0;
	string courseCode;
	string name[100], year[10], dept[10], roll_no[10];
	
	while(flag==false)
	{
		
		cout<<" Enter registration number of student: ";
		
		getline(cin,year[l],'-');
		getline(cin,dept[l],'-');
		getline(cin,roll_no[l]);
				
		bool a=isValidyear(year[l]);
		bool b=isValiddept(dept[l]);
		bool c=isValidroll_no(roll_no[l]);
		
		if(a==true && b==true && c==true)
		{
			regNo[l]=year[l];
			stdNamesList[l]=dept[l];
			stdRegNoList[l]=roll_no[l];
			
			cout<<" Enter Course Code to unregister: ";
			cin>>courseCode;
			
			if(isValidCourseCode(courseCode)==true)
			{
				coursecode[l]=courseCode;
				for(int t=0;t<l;t++)
				{
					if(year[l]==regNo[t] && dept[l]==stdNamesList[t] && roll_no[l]==stdRegNoList[t])
					{
						if(coursecode[j]==coursecode[t])
						{
							coursecode[t]='\0';
							cout<<" Course code of registration number "<<year[l]<<"-"<<dept[l]<<"-"<<roll_no[l]<<" is unregistered."<<endl<<endl;
							l++;
						}
						else
						{
							cout<<" Course Code you entered is not registered by student.\n";
						}
					}
					else
					{
						cout<<" Details you entered are not valid\n";
					}
					flag=true;
				}
			}
		}
	}
}

int main()
{
	string passwordList[100];
	ifstream myfile;
	ifstream store;
	string username,password;
	string  stdNamesList[60], stdRegNoList[60], studentName[60], regNo[200], stdCourseList[100], courseCodeList[100], courseCode[100], stdCourseList1[100];
	string codeList[100], nameList[100], emailList[100];
	int n, n1, crtHrsList[100], semList[100];
	string coursecode, course;
	int crdHrs, semester, repeat, Name, i, b;
	ifstream outfile;
	ifstream Students;

	loadCourses (codeList, nameList, crtHrsList, semList, outfile, n, i, b);	
	loadStudents(stdNamesList, stdRegNoList, studentName, regNo, Students, n, i, b);
	
	
	bool file = does_file_exist("Courses.txt");
	bool file1 = does_file_exist("Students.txt");
	
	if(file && file1)
		{
			loadUsers(emailList,passwordList,myfile,n1,100);
			cout<<""<<"	  **"<<"Welcome to university of Engineering and Technolohgy"<<""<<"**"<<endl;
			cout<<"Dear user current software is intended for authorized users only."<<endl;

			cout<<"Login to the system to get access"<<endl<<endl;
			
			cout<<"Username: ";
			cin>>username;
			cout<<"Password: ";
			cin>>password;
			
			cout<<endl;
			cout<<"Your Username:"<<username<<endl;
			cout<<"Your Password:"<<password<<endl<<endl;
			
			bool data=isValidData(emailList,passwordList,password,username,n1);
						
			while (!data)
			{
				cout<<endl<<""<<"	**"<<"Welcome to university of Engineering and Technolohgy"<<"**"<<""<<endl;
				cout<<"Dear user current software is intended for authorized users only"<<endl;
				cout<<"your email/password is not correct Login again  to the system to get access"<<endl;
				cout<<"Enter username:";
				cin>>username;
			
				cout<<"Enter password :";
				cin>>password;
			
				cout<<"\nDear user,username/password is incorrect.Again enter username/password to login access the system"<<endl;
				cout<<"Password:"<<password<<endl;
				cout<<"Username:"<<username<<endl;

				data=isValidData(emailList,passwordList,password,username,n1);
				
			}
			
			if(data==true)
			{
				while(n!=6)
				{			
					for(i=0;i<5;i++)
					{
						cout<<"You have successfully logged into the system"<<endl;
						cout<<" Choose the following option"<<endl;
						cout<<" 1\tAdd course"<<endl;
						cout<<" 2\tUpdate course"<<endl;
						cout<<" 3\tDelete course"<<endl;
						cout<<" 4\tView all course"<<endl;
						cout<<" 5\tView course of a semester"<<endl;
						cout<<" 6\tAdd new student"<<endl;
						cout<<" 7\tUpdate Student"<<endl;
						cout<<" 8\tDelete Student"<<endl;
						cout<<" 9\tView all Student"<<endl;
						cout<<" 10\tRegister the course for Student"<<endl;
						cout<<" 11\tUnregister the course for Student"<<endl;
						cout<<" 12\tLogout of the system"<<endl;
						cout<<" 13\tExit program"<<endl;
						while(n!=13)
						{
							cout<<"\n Choose option: ";
							cin>>n;
							
							if(n>=1 && n<=13)
							{
								if(n==1)
								{
									AddCourse(codeList,nameList,crtHrsList,semList, repeat);
									repeat++;
								}
								else if(n==2)
								{
									EditCourse(codeList,nameList,crtHrsList,semList,repeat);
									repeat++;
								}
								else if(n==3)
								{
									DeleteCourse(codeList, nameList, crtHrsList, semList, repeat);
									repeat++;
								}
								else if(n==4)
								{
									ViewCourses(codeList, nameList, crtHrsList, semList, repeat);
									repeat++;
								}
								else if(n==5)
								{
									ViewSemesterCourses(codeList, nameList,crtHrsList, semList, repeat);
									repeat++;
								}
								else if(n==6)
								{
									addStudent(stdNamesList, stdRegNoList, studentName, regNo, repeat);
									repeat++;
								}
								else if(n==7)
								{
									updateStudent(stdNamesList, stdRegNoList, studentName, regNo);
								}
								else if(n==8)
								{
									deletestudent(stdNamesList, stdRegNoList, studentName, regNo);
								}
								else if(n==9)
								{
									Viewstudents(stdNamesList, stdRegNoList, studentName, regNo);
								}
								else if(n==10)
								{
									registerCourse(stdRegNoList, stdCourseList, courseCodeList, stdNamesList, regNo, courseCode);
								}
								else if(n==11)
								{
									 unRegisterCourse(stdNamesList, stdRegNoList, studentName, regNo, courseCode);
								}
								else if(n==12)
								{
									cout<<" Logged out!";
									return 0;
								}
								else if(n==13)
								{
									saveCourse(codeList, nameList, crtHrsList, semList, repeat);
									saveStudents(stdRegNoList, stdNamesList, courseCode, regNo, stdRegNoList, stdCourseList1);
									
									cout<<"\n File saved successfully.";
									cout<<"\n Program is closed.";
									return 0;
								}
								else
								{
									cout<<" Invalid input. Access your program again.\n";
									return 0;
								}
							}
							else
							{
								cout<<"\n Invalid input. Access your program again.";
								return 0;
							}
						}
					}
				}
			}					
			else
			{
				cout<<"You entered wrong data.";
			}
		}
		else
		{
			cout<<"We are unable to run programe because data does not exist"<<endl;	
		}


return 0;
}

