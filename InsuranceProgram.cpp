//InsuranceProgram
#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

//-----------------------------------------------------------------------------Insurance class
class Insurance{
public: //variables with personal details
	int policyNum = 0;
	int age = 0;
	int customer_ID = 0;
	string first_name = "unknown"; //first word in the person's fullname
	string middle_name = "unknown"; //should handle long names
	string last_name = "unknown"; //last word in the person's fullname
	string phone_number = "unknown";
	string socialsecurity_number = "unknown";
	bool exists_carInsurance= false;
	bool exists_HomeInsurance = false;

public: //constructors
	Insurance(int polnum, string fn, string mn, string ln, string pn, string ssn, int a, int id){
		policyNum = polnum; age = a; customer_ID = id;
		first_name = fn; middle_name = mn; last_name = ln;
		phone_number = pn; socialsecurity_number = ssn;
	}

	virtual void cast(){} //helps with dynamic cast

public:	//methods(getters)
	int get_policyNum(){return policyNum;} 
	int get_age(){return age;}
	int get_customer_ID(){return customer_ID;}
	string get_first_name(){return first_name;}
	string get_middle_name(){return middle_name;}
	string get_last_name(){return last_name;}
	string get_phone_number(){return phone_number;}
	string get_socialsecurity_number(){return socialsecurity_number;}
};
//-----------------------------------------------------------------------------CarInsurance class
class CarInsurance: public Insurance{
private: //variables with details about the car	
	string car_make= "unknown";;
	string car_model = "unknown";
	int car_driver_licensenumber  = 0;
	int car_VIN = 0;/*vehicle id number/license plate #*/
	int car_year = 0;
	int car_annualmiles = 0;
	float CarInsurance_monthlyPayment = 0;
	float amount_paid = 0; //amount
	int months_passed = 0; //track the number of payments needed
	int CarInsurance_expiryDateLimit = 7;
	float carowner_payment = 0;
	vector<string> car_safetyfeatures;
	vector<string> car_antitheftdevices;
	map<int, string> driver_courses; //grade and name of safe driving courses completed
	
public: //constructors
	CarInsurance(string carmake, string carmodel, int driver_ln, int carVIN, int caryear, int annualmiles, float monthly_payment, float ap, int mp, int expiryDateLimit,float cop ,vector<string> sf, vector<string> antitheftdevices, map<int, string> dc, bool exists, int polnum, string fn, string mn, string ln, string pn, string ssn, int a, int id):Insurance(polnum, fn, mn, ln, pn, ssn, a, id){
		car_make = carmake;
		car_model = carmodel;
		car_driver_licensenumber = driver_ln;
		car_VIN = carVIN;
		car_year = caryear;
		car_annualmiles = annualmiles; 
		CarInsurance_monthlyPayment = monthly_payment; //amount needed to be paid for the month
		amount_paid = ap; //amount
		months_passed = mp; //track the number of payments needed
		CarInsurance_expiryDateLimit = expiryDateLimit; //number of months until the policy expires	
		carowner_payment = cop;
		car_safetyfeatures = sf;
		car_antitheftdevices = antitheftdevices;
		driver_courses = dc;
		exists_carInsurance = exists;
	}

	virtual void cast(){} //helps with dynamic cast
public: //methods(getters)
	string get_car_make(){return car_make;}
	string get_car_model(){return car_model;}
	int get_car_driver_licensenumber(){return car_driver_licensenumber;}
	int get_car_VIN(){return car_VIN;}
	int get_car_year(){return car_year;}
	int get_car_annualmiles(){return car_annualmiles;}
	float get_CarInsurance_monthlyPayment(){return CarInsurance_monthlyPayment;}
	float get_amount_paid(){amount_paid = CarInsurance_monthlyPayment * months_passed; return amount_paid;}
	int get_months_passed(){return months_passed;}
	int get_CarInsurance_expiryDateLimit(){return CarInsurance_expiryDateLimit;}
	float get_carowner_payment(){return carowner_payment;}
	vector<string> get_car_safetyfeatures(){return car_safetyfeatures;}
	vector<string> get_car_antitheftdevices(){return car_antitheftdevices;}
	map<int, string> get_driver_courses(){return driver_courses;}
};
// -----------------------------------------------------------------------------HomeInsurance class
class HomeInsurance: public Insurance{
private: //variables with details about the home
	string homeowner_address = "unknown";
	string homeowner_maritalstatus = "unknown";
	string homeowner_homeImprovements = "unknown";
	bool homeowner_petowner = false;
	bool homeowner_entrepreneur = false;
	float HomeInsurance_monthlyPayment = 0; //amount needed to be paid for the month
	float amount_paid = 0; //amount
	int months_passed = 0; //track the number of payments needed
	int HomeInsurance_expiryDateLimit = 0; //number of months until the policy expires
	float homeowner_payment = 0; //amount paid for the month currently
	vector<string> people_at_home;

public: //constructors
	HomeInsurance(string address, string marital_status, string homeImprovements, bool petOwner, bool entrepreneur, float monthly_payment, float ap, int mp, int expiryDateLimit, float hop, vector<string>home_people, bool exists, int polnum, string fn, string mn, string ln, string pn, string ssn, int a, int id):Insurance(polnum, fn, mn, ln, pn, ssn, a, id){
		homeowner_address = address;
		homeowner_maritalstatus = marital_status;
		homeowner_homeImprovements = homeImprovements;
		homeowner_petowner = petOwner;
		homeowner_entrepreneur = entrepreneur;
		HomeInsurance_monthlyPayment = monthly_payment; //amount needed to be paid for the month
		amount_paid = ap; //amount
		months_passed = mp; //track the number of payments needed
		HomeInsurance_expiryDateLimit = expiryDateLimit; //number of months until the policy expires	
		homeowner_payment = hop; //amount paid for the month currently
		people_at_home = home_people;	
		exists_HomeInsurance = exists;	
	}

	virtual void cast(){} //helps with dynamic cast

public: //methods(getters)
	string get_homeowner_address(){return homeowner_address;}
	string get_homeowner_maritalstatus(){return homeowner_maritalstatus;}
	string get_homeowner_homeImprovements(){return homeowner_homeImprovements;}
	bool get_homeowner_petowner(){return homeowner_petowner;}
	bool get_homeowner_entrepreneur(){return homeowner_entrepreneur;}
	float get_HomeInsurance_monthlyPayment(){return HomeInsurance_monthlyPayment;}
	float get_amount_paid(){return amount_paid;}
	int get_months_passed(){return months_passed;}
	int get_HomeInsurance_expiryDateLimit(){return HomeInsurance_expiryDateLimit;}
	float get_homeowner_payment(){return homeowner_payment;}
	vector<string> get_people_at_home(){return people_at_home;}
};
// -----------------------------------------------------------------------------Customer Node
struct Customer{
	vector<Insurance*>policyList; //to add a policy do: policyList.push_back(new CarInsurance(arg1, arg2, arg3...))
	Customer* next; //points to the next customer in the linked list.
};
// -----------------------------------------------------------------------------Linked List class
class LinkedList{
private: //all temporary nodes and variables
	//customer nodes
	Customer* temp1; //to loop through the customers
	Customer* temp; //to create a new customer
	Customer* head = NULL; //the front of the linked list

	//all variables used for each class
	string carmake, carmodel, fn, mn, ln, pn, ssn, address, marital_status, homeImprovements; 
	int driver_ln, carVIN, caryear, annualmiles, mp, expiryDateLimit, polNum, a, id;
	float monthly_payment, ap, cop/*car owner payment*/, hop/*home owner payment*/; 
	bool petOwner, entrepreneur, exists; 
	vector<string> antitheftdevices;
	vector<string> home_people;
	vector<string> sf;
	map<int, string> dc;
	//note that both mp, ap, expiryDateLimit and monthly_payment are reused to initialize both car and motor insurance objects.

public://other method declarations
	void display_Heading();
	void display_main_Menu();
	void display_insurancetype_Menu();
	//methods for testing
	void add_NewCarInsurancePolicy(string carma, string carmo, int d_ln, int carV, int cary, int annualm, float monthlyp, float amountp, int monthsp, int edl ,float carop ,vector<string> safetyf, vector<string> atd, map<int, string> driverc, bool exists, int polnum, string firstn, string middlen, string lastn, string phonen, string social, int cust_age, int cust_id);
	void add_NewHomeInsurancePolicy(string add, string maritals, string homei, bool peto, bool entr, float monthlyp, float amountp, int monthsp, int edl, float homeop, vector<string>hp, bool exists, int polnum, string firstn, string middlen, string lastn, string phonen, string social, int cust_age, int cust_id);

	//methods to suit conditions for adding a customer
	void add_ToExistingPolicy(int index, int insuranceOption);
	void add_InsuranceDetails();
	void add_NewCarInsuranceDetails();
	void add_NewHomeInsuranceDetails();
	void add_NewCarInsurancePolicy();
	void add_NewHomeInsurancePolicy();

	//methods to renew policies
	void renew_CarInsurancePolicy();
	void renew_HomeInsurancePolicy();

	//methods to display policies
	void display_InsuranceDetails(Customer* node); //this node is used to identify which customer's personal details to print 
	void display_CarInsurancePolicy(int customer_ID);
	void display_HomeInsurancePolicy(int customer_ID);

	//methods that handle the linked list
	bool isEmpty();
	void traverseCustomers();
	void deleteList();
	void executeProgram();
};

bool LinkedList::isEmpty(){
	return (head == NULL);
}
void LinkedList::traverseCustomers(){
	temp1 = head;
	if(isEmpty()){
		cout<<"There are no customers to show.\n\n";
	}else{
		int count = 1;
		while(temp1 != NULL){
			cout<<count<<".) "<<temp1->policyList[0]->get_first_name()<<" "<<temp1->policyList[0]->get_last_name();
			cout<<"->ID: "<<temp1->policyList[0]->get_customer_ID()<<" ->PolicyNumber: "<<temp1->policyList[0]->get_policyNum();
			temp1 = temp1->next;
			cout<<"\n";
			++count;
		}
		count = 1;
	}
}
// -----------------------------------------------------------------------------Menus and headings
void LinkedList::display_Heading(){
	cout<<"+----------------------+\n";
	cout<<"+ BELIZE INSURANCE LTD +\n";
	cout<<"+----------------------+\n";
}
void LinkedList::display_main_Menu(){
	cout<<"+----------------------+\n";
	cout<<"+       main menu      +\n";
	cout<<"+   SELECT AN OPTION   +\n";
	cout<<"+----------------------+\n";	
	cout<<" 1. Add an Insurance Policy\n";
	cout<<" 2. View Policy Details\n";
	cout<<" 3. Renew Policy\n";
	cout<<" 4. Exit\n";
	cout<<"+--------------choice: ";
}
void LinkedList::display_insurancetype_Menu(){
	cout<<"+-----------------------+\n";
	cout<<"+ SELECT INSURANCE TYPE +\n";
	cout<<"+-----------------------+\n";
	cout<<"1. Car Insurance\n";
	cout<<"2. Home Insurance\n";
	cout<<"3. Go back to main menu\n";
	cout<<"+--------------choice: ";
}
// -----------------------------------------------------------------------------"Add" policy and details methods
void LinkedList::add_InsuranceDetails(){
	//Getting personal details
	cout<<"+--------------------------+\n";
	cout<<"+ Adding Insurance Details +\n";
	cout<<"+--------------------------+\n";
	cout<<"First name: "; cin>>fn; cin.ignore();
	cout<<"Middle name(can be multiple): "; getline(cin, mn);
	cout<<"Last name: "; cin>>ln;
	cout<<"Age: "; cin>>a; cin.ignore();
	cout<<"Phone Number: "; getline(cin, pn);
	cout<<"Social Security Number: "; cin>>ssn; cin.ignore();
	id = (rand() % 400000) + 100000; //generates a random number between 100,000 and 499,999.
	polNum = (rand() % 900000) + 600000; //generates a random number between 600000 and 1,499,999
	cout<<"Generated ID number: " <<id;
	cout<<"\nGenerated Policy num: "<<polNum;
	cout<<"\n";
	//Done getting personal details
}

void LinkedList::add_NewCarInsuranceDetails(){
	cout<<"+-----------------------------+\n";
	cout<<"+ Adding CarInsurance Details +\n";
	cout<<"+-----------------------------+\n";
	cout<<"Car make: "; cin>>carmake;
	cout<<"Car model: "; cin>>carmodel;
	cout<<"Driver License Number: "; cin>>driver_ln;
	cout<<"Car License Plate(VIN) number: "; cin>>carVIN;
	cout<<"Car year: "; cin>>caryear;
	cout<<"Car annual miles: "; cin>>annualmiles;
	cout<<"Agreed Monthly Payment: $"; cin>>monthly_payment;
	cout<<"Car Insurance Duration(months): "; cin>>expiryDateLimit;
	cout<<"Insurance charge for "<<expiryDateLimit<<" months: $"<<monthly_payment * expiryDateLimit;
	cout<<"\nEnter amount paid now towards insurance: $"; cin>>cop; //carowner_payment
	mp = cop/monthly_payment; //getting how many months are paid for in advance
	ap = 0; //only necessary when renewing policy;
	int count =1;
	char choice;
	string input_sf, input_atd, input_course;
	do{ //getting the safety features
		cout<<"Add a safety feature(y/n)?: "; cin>>choice; cin.ignore();
		switch(choice){
			case 'y': 
				cout<<"Enter feature("<<count<<"): "; 
				getline(cin, input_sf); //get safety feature
				sf.push_back(input_sf); //add safety feature to vector array
				cout<<"\n";
				count++;
				break;
			case 'n':
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Not an option...skipping this step...";
				choice = 'n';
				cout<<"\n";			
		}
	}while(choice != 'n');

	count = 1;
	do{ //getting the antitheft devices
		cout<<"Add an anti theft device(y/n)?: "; cin>>choice; cin.ignore();
		switch(choice){
			case 'y': 
				cout<<"Enter device name("<<count<<"): "; 
				getline(cin, input_atd); 
				sf.push_back(input_atd);
				cout<<"\n";
				count++;
				break;
			case 'n':
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Not an option...skipping this step...";
				choice = 'n';
				cout<<"\n";			
		}
	}while(choice != 'n');

	count = 1;
	do{ //getting the completed driver courses
		cout<<"Add a completed driver course(y/n)?: "; cin>>choice; cin.ignore();
		switch(choice){
			case 'y': 
				cout<<"Enter course name("<<count<<"): "; 
				getline(cin, input_course); 
				dc.insert(pair<int, string>(count, input_course));
				cout<<"\n";
				count++;
				break;
			case 'n':
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Not an option...skipping this step...";
				choice = 'n';
				cout<<"\n";			
		}
	}while(choice != 'n');
}

void LinkedList::add_NewHomeInsuranceDetails(){
	cout<<"+------------------------------+\n";
	cout<<"+ Adding HomeInsurance Details +\n";
	cout<<"+------------------------------+\n";
	cout<<"Home address: "; cin.ignore(); getline(cin, address);
	cout<<"Marital Status(Married, Widowed, Single, Divorced, Separated): "; cin>>marital_status; cin.ignore();

	char option;
	cout<<"Home improvements(multiple statements allowed): "; getline(cin, homeImprovements);
	cout<<"Pet owner(t for true, f for false): "; cin>>option;
	if(option == 't'){petOwner = true;}
	else if(option == 'f'){petOwner = false;}
	else{cout<<"Not an option...skipping this step...\n";}

	cout<<"Home entrepreneur(t for true, f for false): "; cin>>option;
	if(option == 't'){entrepreneur = true;}
	else if(option == 'f'){entrepreneur = false;}
	else{cout<<"Not an option...skipping this step...\n";}

	cout<<"Agreed Monthly Payment: $"; cin>>monthly_payment;
	cout<<"Home Insurance Duration(months): "; cin>>expiryDateLimit;
	cout<<"Insurance charge for "<<expiryDateLimit<<" months: $"<<monthly_payment * expiryDateLimit;
	cout<<"\nEnter amount paid now towards insurance: $"; cin>>hop; //carowner_payment
	mp = hop/monthly_payment; //getting how many months are paid for in advance
	ap = 0; //only necessary when renewing policy;
	int count =1;
	char choice;
	string name;
	do{ //getting the names of persons at the home
		cout<<"Add a person(y/n)?: "; cin>>choice; cin.ignore();
		switch(choice){
			case 'y': 
				cout<<"Enter person name("<<count<<"): "; 
				getline(cin, name); //get safety feature
				home_people.push_back(name); //add safety feature to vector array
				cout<<"\n";
				count++;
				break;
			case 'n':
				cout<<"Exiting\n";
				break;
			default:
				cout<<"Not an option...skipping this step...";
				choice = 'n';
				cout<<"\n";			
		}
	}while(choice != 'n');
}

void LinkedList::add_NewCarInsurancePolicy(){
	// creating the customer Node and adding the data to the class in the vector array of the customer node
	// policyList.push_back(new CarInsurance(arg1, arg2, arg3...))
	exists = true;
	if(isEmpty()){//if the list is empty
		//temp = (Node*)malloc(sizeof(Node)); // can also use "new Node();"
		temp = new Customer(); //create a memory block for this node
		temp->policyList.push_back(new CarInsurance(carmake, carmodel, driver_ln, carVIN, caryear, annualmiles, monthly_payment, ap, mp, expiryDateLimit, cop , sf, antitheftdevices, dc, exists, polNum, fn, mn, ln, pn, ssn, a, id));
		temp->next = NULL;
		//the node has been prepped 

		head = temp; //head node in the list has a value
	}else{ //if the list is not empty
		temp1 = head;
		while(temp1->next != NULL){//loop all nodes in the list 
			temp1 = temp1->next;
		}
		temp = new Customer();
		temp->policyList.push_back(new CarInsurance(carmake, carmodel, driver_ln, carVIN, caryear, annualmiles, monthly_payment, ap, mp, expiryDateLimit, cop , sf, antitheftdevices, dc, exists, polNum, fn, mn, ln, pn, ssn, a, id));
		temp->next = NULL;
		temp1->next = temp;
	}
	cout<<"CAR INSURANCE ADDED"<<"\n\n";

	//resetting data structures and variables
	sf.clear();  //clears the safety features array
	antitheftdevices.clear(); //clears the anti theft devices array
	dc.clear();  //clears the driver courses map
	exists = false;
}

void LinkedList::add_NewHomeInsurancePolicy(){
	// creating the customer Node and adding the data to the class in the vector array of the customer node
	// policyList.push_back(new CarInsurance(arg1, arg2, arg3...))

	exists = true;
	if(isEmpty()){//if the list is empty
		//temp = (Node*)malloc(sizeof(Node)); // can also use "new Node();"
		temp = new Customer(); //create a memory block for this node
		temp->policyList.push_back(new HomeInsurance(address, marital_status, homeImprovements, petOwner, entrepreneur, monthly_payment, ap, mp, expiryDateLimit, hop, home_people, exists, polNum, fn, mn, ln, pn, ssn, a, id));
		temp->next = NULL;
		//the node has been prepped 

		head = temp; //head node in the list has a value
	}else{ //if the list is not empty
		temp1 = head;
		while(temp1->next != NULL){//loop all nodes in the list 
			temp1 = temp1->next;
		}
		temp = new Customer();
		temp->policyList.push_back(new HomeInsurance(address, marital_status, homeImprovements, petOwner, entrepreneur, monthly_payment, ap, mp, expiryDateLimit, hop, home_people, exists, polNum, fn, mn, ln, pn, ssn, a, id));
		temp->next = NULL;
		temp1->next = temp;
	}
	cout<<"HOME INSURANCE ADDED"<<"\n\n";	

	//resetting variables and data structures
	home_people.clear();
	exists = false;
}

void LinkedList::add_ToExistingPolicy(int index, int insuranceOption){
	temp1 = head;
	int count = 1;
	for(int i = 1; i<index; i++){ //get to the customer node who wants to add insurance
		temp1 = temp1->next;
		++count;
	}
	//getting all personal details from the insurance policy that already exists.
	fn = temp1->policyList[0]->get_first_name();
	mn = temp1->policyList[0]->get_middle_name();
	ln = temp1->policyList[0]->get_last_name();
	polNum = temp1->policyList[0]->get_policyNum();
	a = temp1->policyList[0]->get_age();
	id = temp1->policyList[0]->get_customer_ID();
	pn = temp1->policyList[0]->get_phone_number();
	ssn = temp1->policyList[0]->get_socialsecurity_number();

	if(insuranceOption == 1){ 
		//add new insurance details from existing insurance policy;
		add_NewCarInsuranceDetails(); //get details for car insurance pplicy
		temp1->policyList.push_back(new CarInsurance(carmake, carmodel, driver_ln, carVIN, caryear, annualmiles, monthly_payment, ap, mp, expiryDateLimit, cop , sf, antitheftdevices, dc, true/*exists*/, polNum, fn, mn, ln, pn, ssn, a, id));
		// CarInsurance* t = dynamic_cast<CarInsurance*>(temp1->policyList[1]);
		// cout<<"New values at for customer "<<count<<" and his name is "<<temp1->policyList[1]->get_first_name()<<" and car make is "<<t->get_car_make()<<"\n\n";

		//below comments were used to test if the object was being added to the array
		// CarInsurance* t = dynamic_cast<CarInsurance*>(temp1->policyList[1]);
		// cout<<"New car name is "<<t->get_car_make()<<"\n\n";
	}else if(insuranceOption == 2){
		//add new insurance details from existing insurance policy;
		add_NewHomeInsuranceDetails(); //get details for home insurance pplicy
		temp1->policyList.push_back(new HomeInsurance(address, marital_status, homeImprovements, petOwner, entrepreneur, monthly_payment, ap, mp, expiryDateLimit, hop, home_people, true/*exists*/, polNum, fn, mn, ln, pn, ssn, a, id));
	}
}
// -----------------------------------------------------------------------------"Display" policy methods
void LinkedList::display_InsuranceDetails(Customer* node){
	cout<<"ID: "<<node->policyList[0]->get_customer_ID()<<"\n";
	cout<<"Policy NUmber: "<<node->policyList[0]->get_policyNum()<<"\n";
	cout<<"Name: "<<node->policyList[0]->get_first_name()<<" "<<node->policyList[0]->get_middle_name()<<" "<<node->policyList[0]->get_last_name()<<"\n";
	cout<<"Age: "<<node->policyList[0]->get_age()<<"\n";
	cout<<"Phone Number: "<<node->policyList[0]->get_phone_number()<<"\n";
	cout<<"Social Security Number: "<<node->policyList[0]->get_socialsecurity_number()<<"\n";
	//Done showing personal details
}

void LinkedList::display_CarInsurancePolicy(int c_ID){
	temp1 = head;
	int i;
	while(temp1->policyList[0]->customer_ID != c_ID){ //finding which customer Node has the matching customer_ID
		temp1 = temp1->next;
	}
	cout<<"+------------------------------+\n";
	cout<<"+ Showing CarInsurance Details +\n";
	cout<<"+------------------------------+\n";
	display_InsuranceDetails(temp1);

	/*When you retrieve an element from the list, it will be typed to Insurance*. If you only need to call non-virtual methods 
	in your Insurance class, or virtual methods first declared in Insurance, then you're done. 
	If you need to call non-virtual methods in your subclass, or access public fields in your subclass, you will have to 
	cast the retrieved Insurance* to Car/HomeInsurance* before use.*/
	if(temp1->policyList[0]->exists_carInsurance == true){ //find where in the vector array has the car insurance(either position 0 or 1)
		i = 0;
	}else if(temp1->policyList[1]->exists_carInsurance == true){
		i = 1;
	}
	CarInsurance* t = dynamic_cast<CarInsurance*>(temp1->policyList[i]); //cast a car Insurance policy to pointer t.
	cout<<"Car make: "<<t->get_car_make()<<"\n";
	cout<<"Car model: "<<t->get_car_model()<<"\n";
	cout<<"Driver License Number: "<<t->get_car_driver_licensenumber()<<"\n";
	cout<<"Car License Plate(VIN) number: "<<t->get_car_VIN()<<"\n";
	cout<<"Car year: "<<t->get_car_year()<<"\n";
	cout<<"Car annual miles: "<<t->get_car_annualmiles()<<"\n";
	//safetyfeatures
	sf = t->get_car_safetyfeatures();
	if(sf.size()>0){
	    for(int j = 0; j<= sf.size() - 1; ++j){
	    	cout<<"\tSafety feature("<<j+1<<"): "<<sf.at(i)<<"\n";
	    }
	}
	//anti theft devices
	antitheftdevices = t->get_car_antitheftdevices();
	if(antitheftdevices.size() > 0){
	    for(int j = 0; j<= antitheftdevices.size() - 1; ++j){
	    	cout<<"Anti-theft device("<<j+1<<"): "<<antitheftdevices.at(i)<<"\n";
	    }		
	}
	//driver courses
	dc = t->get_driver_courses();
	for(auto itr = dc.begin(); itr != dc.end(); ++itr){
		cout<<"Driver Course("<<itr->first<<"): "<<itr->second<<"\n";
	}
	cout<<"Monthly payment: $"<<t->get_CarInsurance_monthlyPayment()<<"\n";
	cout<<"Months paid: "<<t->get_months_passed()<<"\n";
	cout<<"Payment Remaining: $"<<(t->get_CarInsurance_expiryDateLimit() - t->get_months_passed()) * t->get_CarInsurance_monthlyPayment()<<"\n";
	cout<<"\n";
}

void LinkedList::display_HomeInsurancePolicy(int c_ID){
	temp1 = head;
	int i;
	while(temp1->policyList[0]->customer_ID != c_ID){ //finding which customer Node has the matching customer_ID
		temp1 = temp1->next;
	}
	cout<<"+-------------------------------+\n";
	cout<<"+ Showing HomeInsurance Details +\n";
	cout<<"+-------------------------------+\n";
	display_InsuranceDetails(temp1);

	/*When you retrieve an element from the list, it will be typed to Insurance*. If you only need to call non-virtual methods 
	in your Insurance class, or virtual methods first declared in Insurance, then you're done. 
	If you need to call non-virtual methods in your subclass, or access public fields in your subclass, you will have to 
	cast the retrieved Insurance* to Car/HomeInsurance* before use.*/
	if(temp1->policyList[0]->exists_HomeInsurance == true){ //find where in the vector array has the car insurance(either position 0 or 1)
		i = 0;
	}else if(temp1->policyList[1]->exists_HomeInsurance == true){
		i = 1;
	}
	HomeInsurance* t = dynamic_cast<HomeInsurance*>(temp1->policyList[i]);  //cast a Home Insuranc policy to pointer t.
	cout<<"Address: "<<t->get_homeowner_address();
	cout<<"\nMarital Status: "<<t->get_homeowner_maritalstatus();
	cout<<"\nHome improvements: "<<t->get_homeowner_homeImprovements();
	//persons at home
	home_people = t->get_people_at_home();
	cout<<"\nPersons at home: "<<"\n";
	if(home_people.size()>0){
	    for(int j = 0; j<= home_people.size() - 1; ++j){
	    	cout<<"\tPerson("<<j+1<<"): "<<home_people.at(i)<<"\n";
	    }
	}
    cout<<"Monthly payment: $"<<t->get_HomeInsurance_monthlyPayment()<<"\n";
	cout<<"Months paid: "<<t->get_months_passed()<<"\n";
	cout<<"Payment Remaining: $"<<(t->get_HomeInsurance_expiryDateLimit() - t->get_months_passed()) * t->get_HomeInsurance_monthlyPayment()<<"\n";
	cout<<"\n";
}
// -----------------------------------------------------------------------------
//to do: the renew policy methods.

// -----------------------------------------------------------------------------Methods for testing
void LinkedList::add_NewCarInsurancePolicy(string carma, string carmo, int d_ln, int carV, int cary, int annualm, float monthlyp, float amountp, int monthsp, int edl ,float carop ,vector<string> safetyf, vector<string> atd, map<int, string> driverc, bool ex, int polnum, string firstn, string middlen, string lastn, string phonen, string social, int cust_age, int cust_id){
	monthsp = carop/monthlyp; //getting how many months are paid for in advance
	amountp = 0; //only necessary when renewing policy;
	if(isEmpty()){//if the list is empty
		//temp = (Node*)malloc(sizeof(Node)); // can also use "new Node();"
		temp = new Customer(); //create a memory block for this node
		temp->policyList.push_back(new CarInsurance(carma, carmo, d_ln, carV, cary, annualm, monthlyp, amountp, monthsp, edl , carop, safetyf, atd, driverc, ex, polnum, firstn, middlen, lastn, phonen, social, cust_age, cust_id));
		temp->next = NULL;
		//the node has been prepped 

		head = temp; //head node in the list has a value
	}else{ //if the list is not empty
		temp1 = head;
		while(temp1->next != NULL){//loop all nodes in the list 
			temp1 = temp1->next;
		}
		temp = new Customer();
		temp->policyList.push_back(new CarInsurance(carma, carmo, d_ln, carV, cary, annualm, monthlyp, amountp, monthsp, edl , carop, safetyf, atd, driverc, ex, polnum, firstn, middlen, lastn, phonen, social, cust_age, cust_id));
		temp->next = NULL;
		temp1->next = temp;
	}
	cout<<"CAR INSURANCE ADDED\n\n";
}
void LinkedList::add_NewHomeInsurancePolicy(string add, string maritals, string homei, bool peto, bool entr, float monthlyp, float amountp, int monthsp, int edl, float homeop, vector<string>hp, bool exists, int polnum, string firstn, string middlen, string lastn, string phonen, string social, int cust_age, int cust_id){
	monthsp = homeop/monthlyp; //getting how many months are paid for in advance
	ap = 0; //only necessary when renewing policy;
	if(isEmpty()){//if the list is empty
		//temp = (Node*)malloc(sizeof(Node)); // can also use "new Node();"
		temp = new Customer(); //create a memory block for this node
		temp->policyList.push_back(new HomeInsurance(add, maritals, homei, peto, entr, monthlyp, amountp, monthsp, edl, homeop, hp, exists, polnum, firstn, middlen, lastn, phonen, social, cust_age, cust_id));
		temp->next = NULL;
		//the node has been prepped 

		head = temp; //head node in the list has a value
	}else{ //if the list is not empty
		temp1 = head;
		while(temp1->next != NULL){//loop all nodes in the list 
			temp1 = temp1->next;
		}
		temp = new Customer();
		temp->policyList.push_back(new HomeInsurance(add, maritals, homei, peto, entr, monthlyp, amountp, monthsp, edl, homeop, hp, exists, polnum, firstn, middlen, lastn, phonen, social, cust_age, cust_id));
		temp->next = NULL;
		temp1->next = temp;
	}
	cout<<"HOME INSURANCE ADDED"<<"\n\n";
}
// -----------------------------------------------------------------------------Program Execution
void LinkedList::executeProgram(){
	int option_MainMenu, option_ExistingorNew, option_InsuranceOption, option_index, option_customer_ID;

	do{
		display_main_Menu();
		cin>>option_MainMenu;
		switch(option_MainMenu){
			case 1: //Add an Insurance Policy
					cout<<"+----------------------+\n";
					cout<<"+   SELECT AN OPTION   +\n";
					cout<<"+----------------------+\n";
					cout<<" 1. Add to a NEW customer policy\n";
					cout<<" 2. Add to an EXISTING customer policy\n";
					cout<<" 3. Go back to main menu\n";
					cout<<"+--------------choice: ";
					cin>>option_ExistingorNew;
					if(option_ExistingorNew == 3){break;} //go back and display the main menu
					switch(option_ExistingorNew){
						case 1: //Add to a NEW customer policy
								display_insurancetype_Menu();
								cin>>option_InsuranceOption;
								if(option_InsuranceOption == 3){break;} //Go back to main menu
								switch(option_InsuranceOption){
									case 1: //Add a New Car Insurance
											add_InsuranceDetails();
											add_NewCarInsuranceDetails();
											add_NewCarInsurancePolicy();
											break;
									case 2: //Add a New Home Insurance
											add_InsuranceDetails();
											add_NewHomeInsuranceDetails();
											add_NewHomeInsurancePolicy();			
											break;
									default: cout<<"That was not an option..."<<endl;					
								}
								break;					
						case 2: //Add to an EXISTING customer policy
								if(isEmpty()){
									traverseCustomers();
									break;
								}
								cout<<"\nyou chose to add to an existing policy\n";
								cout<<"+------------------------------+\n";
								cout<<"+      SELECT CUSTOMER INDEX   +\n";
								cout<<"+------------------------------+\n";
								traverseCustomers();
								cout<<"+----Customer Index(ex: 1, 2, 3...): ";
								cin>>option_index;
								cout<<"\n";
								display_insurancetype_Menu();
								cin>>option_InsuranceOption;
								if(option_InsuranceOption == 3){break;} //Go back to main menu									
								add_ToExistingPolicy(option_index, option_InsuranceOption);
								break;
						default: cout<<"That was not an option..."<<endl;
					}
					break;
			case 2: //View Policy Details
					if (isEmpty()){
						traverseCustomers();
						break;
					}
					cout<<"+----------------------+\n";
					cout<<"+  SELECT CUSTOMER ID  +\n";
					cout<<"+----------------------+\n";
					traverseCustomers();
					cout<<"+----------customer ID: ";
					cin>>option_customer_ID;
					cout<<"\n";

					//seeing which insurance policy exists and display it
					temp1 = head;
					while(temp1->policyList[0]->customer_ID != option_customer_ID){ //finding which customer Node has the matching customer_ID
						temp1 = temp1->next;
					}

					//considered catching a bad_cast exception by using the dynamic cast operator but was too time consuming :(
					if(temp1->policyList[0]->exists_carInsurance == true || temp1->policyList[1]->exists_carInsurance == true){
						display_CarInsurancePolicy(option_customer_ID);
					}
					if(temp1->policyList[0]->exists_HomeInsurance == true || temp1->policyList[1]->exists_HomeInsurance == true){
						display_HomeInsurancePolicy(option_customer_ID);
					}
					break;
			case 3: //Renew a Policy

			case 4: //exit
				break;

			default: cout<<"That was not an option..."<<endl;
		}
	}while(option_MainMenu != 4);
}
// -----------------------------------------------------------------------------Delete List
void LinkedList::deleteList(){
	if(isEmpty()){
		cout<<"There are no customers to delete.\n";
	}else{
		temp1 = head;
		while(temp1 != NULL){
			temp1 = temp1->next;
			free(head);
			head = temp1;
		}
		cout<<"All customers deleted.\n";
	}
}





// NOTE: TRY to pass it directly instead of using a function to do it for the get details
int main(){
	srand(time(0));
	vector<string> safetyf;
	vector<string> hp;
	vector<string> atd;
	map<int, string> driverc;
	LinkedList LL;
	cout<<"Works"<<endl;
	LL.traverseCustomers();
	LL.add_NewHomeInsurancePolicy("Princess DIana street", "single", "none", true, false, 25, 0, 0, 8, 0, hp, true, 678928, "Mary", "Lorraine", "Jane", "655-5886", "887323123", 92, 15000000);
	LL.add_NewCarInsurancePolicy("Toyota", "Corola", 1234567, 123456, 2008, 120000, 25/*monthlyp*/, 0 /*amountp*/, 3 /*monthsp*/, 12 /*edl*/ , 0 /*carop*/ , safetyf/*safetyf*/, atd /*atd*/, driverc/*driverc*/, true /*exists*/, 12897542 /*polnum*/, "John" /*firstn*/, "Mert" /*middlen*/, "Doe" /*lastn*/, "604-8941" /*phonen*/, "123456789" /*social*/, 45 /*cust_age*/, 587645 /*cust_id*/);
	LL.add_NewCarInsurancePolicy("Nissan", "Altima", 1234567, 123456, 2002, 120000, 25/*monthlyp*/, 0 /*amountp*/, 3 /*monthsp*/, 12 /*edl*/ , 0 /*carop*/ , safetyf/*safetyf*/, atd /*atd*/, driverc/*driverc*/, true /*exists*/, 9255123 /*polnum*/, "Tadeo" /*firstn*/, "Humberto" /*middlen*/, "Bennett" /*lastn*/, "625-4777" /*phonen*/, "123456789" /*social*/, 19 /*cust_age*/, 499845 /*cust_id*/);
	LL.traverseCustomers();
	LL.display_Heading();
	char option;
	do{
		LL.executeProgram();
		cout<<"Would you like to continue(y/n)?: ";
		cin>>option;
	}while(option != 'n');
	system("CLS");
	LL.deleteList();
	cout<<"\nThank you for testing my program. - TadeoBennett";
}
