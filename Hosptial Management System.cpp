#include<iostream>
#include<cstring>
#include<fstream>
#include<string.h>

using namespace std;

struct Address
{
	
		string house_no , street_no , postal_code ;
		string city , province , country ;
		
};
class General_Info
{
	private:
		string  L_name,F_name , gender ;
		long long int phone_no;
	protected:
		int age;
		string blood_group;
	public:
		
		Address a;
		General_Info() //default constructor
		{
		}
		General_Info(string a ,string b,string c,long long int d)//parameterized constructor
		{
			L_name=a; 
			gender=b; 
			F_name=c;
			phone_no=d;
		}
		void print_address() //printing address
 		{
 			cout<<"Address: "<<a.house_no<<"-"<<a.street_no<<"-"<<a.city<<", "<<a.postal_code<<", "<<a.country<<endl;
 		}
 		void set_gender(const string n) //setter for private member
 		{
		 	gender=n;	
		}
		string get_gender() const //getter for private member
		 {
		 	return gender;
		 }
 		void set_Lname(const string n)//setter for private member
 		{
		 	L_name=n;	
		}
		string get_Lname() const //getter for private member
		 {
		 	return L_name;
		 }
 		void set_Fname(const string n)//setter for private member
 		{
			 F_name=n;	
		}
		string get_Fname() const //getter for private member
		 {
		 	return F_name;
		 }
 		void setphone_no(const long long int p)//setter for private member
	 	{
		 	phone_no=p;
		 }
		long long int getphone_no() const //getter for private member
		 {
		 	return phone_no;
		 }
		virtual void set_age(const int a) //setter for private member //virtual to achieve polymorphism

		{
			age=a;
		}
		virtual void setblood_group(const string b)  //setter for private member //virtual to achieve polymorphism
		{
			blood_group=b;
		}
		virtual void print_info();
		~General_Info()//destructor
		{
			cout<<endl<<"Destructor called!";
		}
};
void General_Info::print_info()
{
	cout<<endl<<"Name: "<<get_Fname()<<" "<<get_Lname()<<endl<<"Gender: "<<get_gender()<<endl<<"Phone: "<<getphone_no()<<endl;
	print_address();
}
class Pharmacy//abstract class
{
	protected:
	string prescribtion[20];	
	public:
		Pharmacy()//setting prescription to blank in default constructor
		{
			int i;
			for(i=0;i<20;i++)
			{
				prescribtion[i]=" ";
			}
		}
	static string medicines[20];//static because it can not be declared within the class and also it will remain same for all
	 virtual void print_pharm()=0;//pure virtual function
	
};
 string Pharmacy:: medicines[20] ={"Panadol","Arinac","Sancose","Rigix","Mytica","Disperene","Calpol","Brufen","Entamizole","ORS","Aspirin","Nitroglycerine","Salmeterol","Peramivir","Amoxicillin","Naprosyn","Aspirin","High-FlourideSensodyne","Listerine","Pepto-Bismol"};
void Pharmacy:: print_pharm()//definition of pure virtual function
	    {
	    	int i;
	    	for(i=0;i<20;i++)
	    	{
	    		cout<<endl<<i+1<<". "<<medicines[i];
			}
	}
struct Timing
{
	int start_time,end_time;
};
 class Doctor: public General_Info//inheritting class//child class 
 {
 	private:
 	double salary ;
	int hours_day , service_yrs ;
 	int ID;
 	protected:
 		int room_no;
 	public:
 		Doctor()//default constructor
 		{
		 }
		 Doctor(int e,int f,int g,double h,string a ,string b,string c,long long int d):General_Info(a,b,c,d)//parameterized constructor
  		{
  			salary=h;
			hours_day=e;
			service_yrs=f;
 	        ID=g;
		}
	struct Timing t;
	 void set_timing(const int t1,const int t2)//setter function for private members
	 {
	 	 t.start_time=t1;
	 	 t.end_time=t2;
	 }
	 
	 void sethours_day(const float h)//setter function for private members
	 {
	 	hours_day=h; 
	 }
	 void setsalary(const double s)//setter function for private members
	 {
	 	salary=s;
	 }
	 void setservice_yrs(const float sy)//setter function for private members
	 {
	 	service_yrs=sy;
	 }
	 void set_ID(const int sy)//setter function for private members
	 {
	 	ID=sy;
	 }
	 void set_rno(const int rno)//setter function for private members
	 {
	 	room_no=rno;
	 }
	 double get_salary() //getter function for private members
	 {
	 	if(getservice_yrs()>10)//condition for salary
	 	bonus_add(10000.0);
	 	
	 	return salary;
	 }
	  float get_ID() const //getter function for private members
	 {
	 	return ID;
	 }
	 float getservice_yrs() const//getter function for private members
	 {
	 	return service_yrs;
	 }
	 float gethours_day() const//getter function for private members
	 {
	 	return hours_day;
	 }
	 int get_rno() const//getter function for private members
	 {
	 	return room_no;
	 }
	 void bonus_add(double bonus)//adding the bonus 
	 {
	 	salary+=bonus;
	 }
	 
	 virtual void print_info()//redefining the function already defined in base class
		{
			General_Info::print_info();
			cout<<endl<<"Timing: "<<t.start_time<<" to "<<t.end_time;
			cout<<endl<<"Service Years:: "<<getservice_yrs()<<endl<<"Hours a day: "<<gethours_day()<<endl<<"Salary: "<<get_salary()<<endl<<"Room no: "<<room_no<<endl;
		}
		void operator=(Doctor& obj)//operator overloading achieved
		{
			this->a.city=obj.a.city;
			this->a.country=obj.a.country;
			this->a.house_no=obj.a.house_no;
			this->a.postal_code=obj.a.postal_code;
			this->a.province=obj.a.province;
			this->a.street_no=obj.a.street_no;
			this->age=obj.age;
			this->set_Fname(obj.get_Fname());
			this->set_Lname(obj.get_Lname());
			this->setphone_no(obj.getphone_no());
			this->ID=obj.ID;
			this->set_gender(obj.get_gender());
			this->room_no=obj.get_rno();
			this->salary=obj.get_salary();
			this->service_yrs=obj.getservice_yrs();
			this->hours_day=obj.hours_day;
			this->t.start_time=obj.t.start_time;
			this->t.end_time=obj.t.end_time;
			
		}
		~Doctor()//destructor
		{
			cout<<endl<<"Destructor called!";
		}
};
class Patient : public Pharmacy, public General_Info//multiple inherritance child class 
{
	
	private:
		int  num_med;
		string  disease;
		int problem;
	public:
		int ID ;
		
		Patient()//default constructor
		{
		}
		Patient(int i,int j,string k,string a ,string b,string c,long long int d):General_Info(a,b,c,d)//parameterized constructor
		{
			num_med=i;
		    disease=k;
		    problem=j;
		}
		int med[20];
		void set_num_med(int a)
		{
			num_med=a;
		}
		void set_age(const int a)//setter function for private members

		{
			age=a;
		}
		void setblood_group(const string b)//setter function for private members
		{
			blood_group=b;
		}
		
		int get_age() const//getter function for private members
		{
			return age;
		}
		string getblood_group() const//getter function for private members
		{
			return blood_group;
		}
		void set_problem(const int i)//setter function for private members
		{
			problem=i ;
		}
	    int get_problem()const//getter function for private members
		{
			return problem ;
		}
		
		void set_prescribtion(string a)//setter function for private members
		{
			int i;
			for(i=0;i<5;i++)
			{
				if(a==prescribtion[i])//condition for medicine already present
				{
					cout<<endl<<"This medicine is already in the list!";
					return ;
				}
				else if(prescribtion[i]==" ")
				{
					prescribtion[i]=a;
					return;
				}
			}
		}
		void print_prescribtion()
		{
			int i;
			cout<<endl<<"Medicines that are prescribed to this patient are as follows:";
			for(i=0;i<5;i++)
			{
				if(prescribtion[i]!=" ")
				{
					cout<<endl<<i+1<<"."<<prescribtion[i];}

			}
		}
		void del_medicine(int number)
		{
			int i,j;
			for(j=0;j<20;j++)
			{
				if(j==number-1)
				{
					for(i=j+1;i<20;i++,j++)
					{
						prescribtion[j]=prescribtion[i];
						prescribtion[i]==" ";
					}
				}
			}
		}
		void set_disease( string a)//setter function for private members
		{
			disease=a;
		}
		string get_disease() const//getter function for private members
		{
			return disease;
		}
		void dec_disease_physician()//disease decision taking function
		{
			if(get_problem()==1)
			{
				set_disease("Typhoid.");
			}
			else if(get_problem()==2)
			{
				set_disease("Flu.");
			}
			else if(get_problem()==3)
			{
				set_disease("Chicken Pox or Some allergy.");
			}
		}
		void dec_disease_cardiologist()//disease decision taking function
		{
			if(get_problem()==1)//unconcious//breathing problem// irresponsive
			{
				set_disease("Cardiac Arrest.");
			}
			else if(get_problem()==2)//cough,swollowing,stomach pain,sore throat
			{
				set_disease("Heart Burn");
			}
			else if(get_problem()==3)//nausea, pain in neck and jaw and arm, short breading , dizziness
			{
				set_disease("Angina");
			}
			
		}
		void dec_disease_dentist()//disease decision taking function
		{
			if(get_problem()==1)
			{
				set_disease("Oral Cancer.");//Swellings, Development of velvety white and red patches, Bleeding in the mouth.
			}
			else if(get_problem()==2)
			{
				set_disease("Dental Plaque.");//yellowish white appearing on the teeth.
			}
			else if(get_problem()==3)//Small holes, Pits in the tooth, Consistent Toothache.
			{
				set_disease("Tooth Decay");
			}
			
		}
		void pat_info()//print the information of patient
		{
			General_Info::print_info();
			cout<<endl<<"Age: "<<get_age();
			cout<<endl<<"Blood Group: "<<getblood_group()<<endl;
		}
		void print_pharm()//redefining the pure virtual function of abstract class
		{
			Pharmacy::print_pharm();
		}
		void operator=(Patient& obj)//operator overloading
		{
			this->a.city=obj.a.city;
			this->a.country=obj.a.country;
			this->a.house_no=obj.a.house_no;
			this->a.postal_code=obj.a.postal_code;
			this->a.province=obj.a.province;
			this->a.street_no=obj.a.street_no;
			this->age=obj.age;
			this->blood_group=obj.blood_group;
			this->set_Fname(obj.get_Fname());
			this->set_Lname(obj.get_Lname());
			this->setphone_no(obj.getphone_no());
			this->ID=obj.ID;
			this->set_gender(obj.get_gender());
			
		}
		~Patient()//destructor
		{
			cout<<endl<<"Destructor called!";
		}
		
	
};
struct dated
{
	int day , month , year ;
};
class Appointment //composition class of doctor and patient
{
	private: 
	 
	 double charges;
	public:
		int type;
		struct dated d;
		Doctor doct;
		Patient pati;
		void set_charges(const double x)//setter function
		{
				charges=x;
			
		}
		double get_charges()const//getter function
		{
			return charges;
		}
		void decision_disease(int type)//decision at the time of appointment
		{
			switch(type)
			{
				case 1:
					{
						pati.dec_disease_physician();
						break;
					}
				case 2:
					{
						pati.dec_disease_cardiologist();
						break;
					}
				case 3:
					{
						pati.dec_disease_dentist();
						break;
					}
				default:
					{
						cout<<"No type defined! Please enter a proper type of Doctor!.";
						break;
					}
			}}
		
			void print_detailsOfAppointment()//printing full details of appointment
			{
				cout<<endl<<"Patient Details: "<<endl;
				pati.pat_info();
				cout<<endl<<"Disease: "<<pati.get_disease();
				cout<<endl<<"Doctor Details: "<<endl;
				cout<<"Docto Name: "<<doct.get_Fname()<<" "<<doct.get_Lname();
				cout<<endl<<"Timing: "<<doct.t.start_time<<" to "<<doct.t.end_time;
				cout<<endl<<"Date: "<<d.day<<"-"<<d.month<<"-"<<d.year<<endl;
				cout<<"Prescribtion: \n";
				pati.print_prescribtion();
				cout<<endl<<"Charges: "<<get_charges();
				
			}
			
			~Appointment()//destructor
		{
			cout<<endl<<"Destructor called!";
		}
	
};
template<typename T>//templates achieved
void Billing(Appointment* obj, T x, T y)
{
	double z;
	z=(x*y);
	obj->set_charges(z);
}

long int id_patient=10001;
long int id_doc=10001;
long int id_app=10001;
int main()
{
	cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"...........................................-:Welcome to ABC Hospital:-................................................"<<endl;
	cout<<"----------------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<"\nDesigned by:\n1.Aiman Siddiqui 17K-3810 \n2.Saba Pervez 17K-3881\n"<<endl;
	Doctor doc[20],doc_dummy;
	Patient pat[100],pat_dummy;
	Appointment appp,app_dummy;
	int num_doc=0, num_pat=0, num_app=0,option1 , option2 , x , y ,z,id;
	double r;
	long long int lx;
	string a,b;
	for(;;)
	{
		cout<<"---------------------------------------------------------------------------------------------------------------"<<endl;
		cout<<"What operation do you want to perform?\n1.Add Patient.\n2.Add Doctor.\n3.Add Appointment.\n4.View details of Patient.\n5.View details of Doctor.\n6.View details of Appointment.\n7.Exit\n\nAnswwer: ";
		cin>>option1;
		while(cin.fail()) {
        cout<<"Enter an integer from above choices";
        cin.clear();
        cin.ignore(256,'\n');
        
        cin >> option1;
    }
	bool check=false;
	
	while(!check){
	if(option1>=1&&option1<=7){
		check=true;
	}
	else{
		try//exceptional handling
		{
			throw &option1;
		}
		catch(int *option1)
		{
			cout<<"enter valid input:"<<endl;
			cin>>*option1;
			 while(cin.fail()) {
        cout<<"enter an integer from above choices";
        cin.clear();
        cin.ignore(256,'\n');
        
        cin >> *option1;
    }
		}
	}
}
	switch(option1)
		{
			case 1://adding a patient
				{
					General_Info* ptr=&pat[num_pat];//polymorphism by upcasting
					cout<<endl<<"First Name: ";
					cin.ignore();
					getline(cin,a);
					ptr->set_Fname(a);
					cout<<"Last Name: ";
					getline(cin,a);
					ptr->set_Lname(a);
					cout<<"Adress:\nHouse No: ";
					getline(cin,a);
					ptr->a.house_no=a;
					cout<<"Street No: ";
					getline(cin,a);
					ptr->a.street_no=a;
					cout<<"Postal Code: ";
					getline(cin,a);
					pat[num_pat].a.postal_code=a;
					cout<<"City: ";
					getline(cin,a);
					ptr->a.city=a;
					cout<<"Province: ";
					getline(cin,a);
					ptr->a.province=a;
					cout<<"Country: ";
					getline(cin,a);
					ptr->a.country=a;
					cout<<"Gender: ";
					getline(cin,a);
					ptr->set_gender(a);
					cout<<"Phone No: ";
					cin>>lx;
					ptr->setphone_no(lx);
					cout<<"Blood Group: ";
					cin.ignore();
					getline(cin,a);
					ptr->setblood_group(a);
					cout<<"Age: ";
					cin>>x;
					ptr->set_age(x);
				//saving the object in a file
					ofstream outfile("Patients.bin", ios::out|ios::app|ios::binary);//opening file in write mode
					outfile.write(reinterpret_cast<char*>(&pat[num_pat]), sizeof(pat[num_pat]));
					outfile.close();//closing file 			
					num_pat++; 		
					break;
				}
			case 2://adding doctor
				{
					cout<<endl<<"First Name: ";
					cin.ignore();
					getline(cin,a);
					doc[num_doc].set_Fname(a);
					cout<<"Last Name: ";
					getline(cin,a);
					doc[num_doc].set_Lname(a);
					cout<<"Adress:\nHouse No: ";
					getline(cin,a);
					doc[num_doc].a.house_no=a;
					cout<<"Street No: ";
					getline(cin,a);
					doc[num_doc].a.street_no=a;
					cout<<"Postal Code: ";
					getline(cin,a);
					doc[num_doc].a.postal_code=a;
					cout<<"City: ";
					cin.ignore();
					getline(cin,a);
					doc[num_doc].a.city=a;
					cout<<"Province: ";
					getline(cin,a);
					doc[num_doc].a.province=a;
					cout<<"Country: ";
					getline(cin,a);
					doc[num_doc].a.country=a;
					cout<<"Gender: ";
					getline(cin,a);
					doc[num_doc].set_gender(a);
					cout<<"Phone No: ";
					cin>>lx;
					doc[num_doc].setphone_no(lx);
					cout<<"Room No: ";
					cin>>x;
					doc[num_doc].set_rno(x);
					cout<<"Hours a day: ";
					cin>>r;
					doc[num_doc].sethours_day(r);
					cout<<"Service years: ";;
					cin>>r;
					doc[num_doc].setservice_yrs(r);
					cout<<"Salary: ";
					cin>>r;
					doc[num_doc].setsalary(r);
					cout<<"Start time: ";
					cin>>x;
					cout<<"End time: ";
						cin>>y;
					
					doc[num_doc].set_timing(x,y);
					cout<<"ID: ";
					cin>>x;
					doc[num_doc].set_ID(x);
					cout<<"\nYour ID is: "<<doc[num_doc].get_ID()<<endl;
					//saving the doctor object in file
					ofstream outfile("Doctors.bin", ios::out|ios::app|ios::binary);//opening file in write mode
					outfile.write(reinterpret_cast<char*>(&doc[num_doc]), sizeof(Doctor));
					outfile.close();//closing the file			
					num_doc++;
					break;
				}
			case 3://adding appointment
				{
					for(;;)
					{
					
					cout<<endl<<"Patient is visiting first time : Press '1' for yes and '2' for no: ";//asking if the patient is already added in the patients details
					cin>>option2;
					while(cin.fail()) {
        					cout<<"enter an integer from above choices";
     					   cin.clear();
     					   cin.ignore(256,'\n');
        
  					       cin >> option2;
   							 }
				bool check=false;
	
				while(!check){
					if(option2>=1&&option2<=2){
						check=true;
					}
					else{
						try//exceptional handling
						{
							throw &option2;
						}
						catch(int *option2)
						{
							cout<<"enter valid input:"<<endl;
							cin>>*option2;
							while(cin.fail()) {
       						cout<<"Enter an integer from above choices";
							cin.clear();
        					cin.ignore(256,'\n');
       		 
    					    cin >> *option2;
   								 }
						}
					}
					}
					switch(option2)
					{
						case 1:
							{
								cout<<endl<<"First Name: ";
					cin.ignore();
					getline(cin,a);
					pat[num_pat].set_Fname(a);
					cout<<"Last Name: ";
					getline(cin,a);
					pat[num_pat].set_Lname(a);
					cout<<"Adress:\nHouse No: ";
					getline(cin,a);
					pat[num_pat].a.house_no=a;
					cout<<"Street No: ";
					getline(cin,a);
					pat[num_pat].a.street_no=a;
					cout<<"Postal Code: ";
					getline(cin,a);
					pat[num_pat].a.postal_code=a;
					cout<<"City: ";
					cin.ignore();
					getline(cin,a);
					pat[num_pat].a.city=a;
					cout<<"Province: ";
					getline(cin,a);
					pat[num_pat].a.province=a;
					cout<<"Country: ";
					getline(cin,a);
					pat[num_pat].a.country=a;
					cout<<"Gender: ";
					getline(cin,a);
					pat[num_pat].set_gender(a);
					cout<<"Phone No: ";
					cin>>lx;
					pat[num_pat].setphone_no(lx);
					cout<<"Blood Group: ";
					cin.ignore();
					getline(cin,a);
					pat[num_pat].setblood_group(a);
					cout<<"Age: ";
					cin>>x;
					pat[num_pat].set_age(x);
					pat[num_pat].ID=id_patient;
					id_patient++;
					//saving the object in a file
					ofstream outfile("Patients.bin", ios::out|ios::app|ios::binary);//opening file in write mode
					outfile.write(reinterpret_cast<char*>(&pat[num_pat]), sizeof(pat[num_pat]));
					outfile.close();//closing file 
					appp.pati.operator=(pat[num_pat]); 
					z=0;
					break;
							}
						case 2:
							//if already present then searching in the file
					{
						cout<<"Enter the first name of the Patient: ";
						cin.ignore();
						cin>>a;
						ifstream infile("Patients.bin", ios::in|ios::binary);//opening file in readmode
						if(infile.is_open())
						{
						
					 while(infile.read(reinterpret_cast<char*>(&pat_dummy), sizeof(Patient)))//receiving the object in the file
					 {

					 	if(a==pat_dummy.get_Fname())//if the name matches
					 	{
					 		appp.pati.operator=(pat_dummy);//copying the patient in the object of appointnment
					 		x=1;
						}
					 }
					 if(x!=1)
					 {
					 	cout<<"NOT FOUND!";
					 }}
					 else
					 cout<<"File not opened!";
					 infile.close();//closing the file
					 z=0;
						break;
					}
					default:
						{
							cout<<"You entered a wrong option! ";
							z=1;
							break;
						}
							
					}
					if(z==1)
					continue;
					else break;
					
				}
					cout<<endl<<"Which type of Doctor you want to visit: \n1.General Physician\n2.Cardiologist\n3.Dentist\nAnswer:";
					cin>>x;
					appp.type=x;
					cout<<"Enter the name for the doctor you want to visit: ";//asking for the doctor you want to visit
					cin.ignore();
					cin>>a;
					ifstream infile("Doctors.bin", ios::in|ios::binary);//searching for the doctor in the file
						if(infile.is_open())
						{
						
					 while(infile.read(reinterpret_cast<char*>(&doc_dummy), sizeof(Doctor)))
					 {

					 	if(a==doc_dummy.get_Fname())
					 	{
					 		appp.doct.operator=(doc_dummy);
					 		x=1;
						}
					 }
					 if(x!=1)
					 {
					 	cout<<"NOT FOUND!";
					 }}
					 else
					 cout<<"File not opened!";
					 infile.close();
					//searching for the doctor in files
					//switch cases for type
					switch(x)
					{
						case 1:
						{
							cout<<endl<<"What problem you are having: \n1.poor appetite, abdominal pain and peritonitis, high fever up to 104 F.\n2.Cough, Sore throat, Runny or stuffy nose.\n3.High temperature (fever), Spots appear in crops, Loss of appetite.\nAnswer:  ";
							
							cin>>y;
							appp.pati.set_problem(y);
							appp.decision_disease(x);
							break;
						}
						case 2:
							{
							cout<<endl<<"What problem you are having: \n1.Unconcious, Breathing problem, Irresponsive.\n2.Cough, Swollowing, Stomach pain, Sore throat.\n3.Nausea, Pain in neck and jaw and arm, Short breading , Dizziness.\nAnswer:  ";
							cin>>y;
							appp.pati.set_problem(y);
							appp.decision_disease(x);
							break;
							}
						case 3:
							{
							cout<<endl<<"What problem you are having: \n1.Swellings, Development of velvety white and red patches, Bleeding in the mouth.\n2.//yellowish white appearing on the teeth.\n3.Small holes, Pits in the tooth, Consistent Toothache.\nAnswer:  ";
							cin>>y;
							appp.pati.set_problem(y);
							appp.decision_disease(x);
							break;
							}
						default:
							{
								cout<<"You entered an invalid option. Please try again! ";
								break;
							}
							
					}
					//additional details
					cout<<endl<<"Day of Appointment: ";
					cin>>x;
					appp.d.day=x;
					cout<<endl<<"Month of Appointment: ";
					cin>>x;
					appp.d.month=x;
					cout<<endl<<"Year of Appointment: ";
					cin>>x;
					appp.d.year=x;
					appp.pati.print_pharm();
					cout<<endl<<"Enter the medicines prescribed from the above menu in the form of string: ";
					while(1)
					{
						cout<<endl<<"Medicine name: ";
						cin>>a;
						appp.pati.set_prescribtion(a);
						cout<<"Do you want to add another medicine :   1.Yes   Any other Number.No\n";
						cin>>x;
						if(x==1)
						continue;
						else break;
					}
					//selecting  the billing type
					cout<<endl<<"Please select the right option: \n1.Visiting Patient\n2.Staying Patient\nAnswer:";
					cin>>x;
					switch(x)
					{
						case 1:
							{
								y=1;//days default 1
								Billing(&appp,2500,y);
								break;
							}
						case 2:
							{
								double f;
								cout<<"Enter the number of days: ";
								cin>>f;
								
								Billing(&appp,10000.25,f);
								break;
							}
							
							
						
					}
					//saving app
					ofstream outfile("Appointments.bin", ios::out|ios::app|ios::binary); //opening file in writing mode
					outfile.write(reinterpret_cast<char*>(&appp), sizeof(Appointment));
					outfile.close();
					num_app++;
					break;
				}
			case 4://searching data in the form of filing
				{
					cin.ignore();
					cout<<"Enter the Fisrt name: ";
					 getline(cin,b);
					 
					 ifstream infile;
					 infile.open("Patients.bin", ios::binary|ios::in);
				
						
					 if(infile.is_open())
					 {
					 	 while(infile.read(reinterpret_cast<char*>(&pat_dummy), sizeof(Patient)))
					 {
					 	if(b==pat_dummy.get_Fname())
					 	{
					 		pat_dummy.pat_info();
						 }
					 }}
					 else
					 cout<<"File not opened!";
					
					 infile.close();
					break;
				}
			case 5://searching data in the form of filing
				{
					cin.ignore();
					cout<<"Enter the Fisrt name: ";
					 getline(cin,b);
					 ifstream infile("Doctors.bin", ios::in|ios::binary);
					 if(infile.is_open())
					 {

					 while(infile.read(reinterpret_cast<char*>(&doc_dummy), sizeof(Doctor)))
					 {

					 	if(b==doc_dummy.get_Fname())
					 	{
					 		doc_dummy.print_info();
						}
					 }}
					 else 
					 cout<<"File not opened!";
					 infile.close();
					//searching 
					
					break;
				}
			case 6://searching data in the form of filing
				{
					
					cin.ignore();
					cout<<"Enter the Fisrt name: ";
					 getline(cin,b);
					 ifstream infile("Appointments.bin", ios::in|ios::binary);
					 if(infile.is_open())
					 {
					 
					 while(infile.read(reinterpret_cast<char*>(&app_dummy), sizeof(Appointment)))
					 {

					 	if(b==app_dummy.pati.get_Fname())
					 	{
					 		app_dummy.print_detailsOfAppointment();
						}
					 }
				}
				else 
				cout<<"File not opened!";
					 infile.close();
					//searching 
					break;
				}
			case 7:
				{
					return 0;
				}
			default:
				{
					cout<<"Please enter a right option! "<<endl;
					break;
				}
		}
	}
}

