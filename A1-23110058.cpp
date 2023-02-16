///////////////////////////////////////////////
// Assignment 1
// Name:    Abdul Hannan Chaudhry
// Roll No: 23110058
// CS 200
// Date: February 2021
///////////////////////////////////////////////
#include <iostream>
#include <time.h>
#include <string>
using namespace std;


//////////////////////////////////////////////
// Question 1
//////////////////////////////////////////////

class Student
{
    private: 
        string name;
        int age;
        double percentage;

    public:
        Student();
        Student(string n, int a, double p);
        ~Student();
        void setName(string n);
        void setAge(int a);
        void setPercentage(double p);
        string getName();
        int getAge();
        double getPercentage() const;
        friend ostream &operator << (ostream &output, const Student &X);
        friend istream &operator>>( istream  &input, Student &X );


};

// Constructors
Student::Student()
{
    name = "";
    age = 0;
    percentage = 0.0;
}
Student::Student(string n, int a, double p)
{
    name = n;
    while (a > 200 && a < 0)
    {
        cout << "\nError. Re-Enter age,";
        cin >> a;
    }
    age = a;
    while (p >= 100 && p <= 0)
    {
        cout << "\nError. Re-Enter percentage,";
        cin >> p;
    }
    percentage = p;
}

// Destructor
Student::~Student()
{
    
}

// Setters
void Student::setName(string n)
{
    name = n;
}

void Student::setAge(int a)
{
    age = a;
}

void Student::setPercentage(double p)
{
    percentage = p;
}

// Getters
string Student::getName()
{
    return name;
}

int Student::getAge()
{
    return age;
}

double Student::getPercentage() const
{
    return percentage;
}

// Utility / Helper Functions


// Overloaded <<, >> Functions
ostream &operator << (ostream &output, const Student &X)
{
    output << "Student Name: " << X.name << "\nStudent Age: " << X.age << "\nStudent Percentage: " << X.percentage;
    return output;
}

istream &operator>> ( istream  &input, Student &X )
{

    input >> X.name >> X.age >> X.percentage;
    while (X.age > 200 || X.age < 0 )
    {
        cout << "Error. Invalid input. Re enter age:\n";
        input >> X.age;
    }
     while (X.percentage > 100 || X. percentage < 0)
    {
        cout << "Error. Invalid input. Re enter percentage:\n";
        input >>X.percentage;
    }
   
    return input;
}



// Other Functions


//////////////////////////////////////////////

class University
{
    private: 
        string name;
        int merit;
    public:
        University();
        University(string a, int b);
        ~University();
        void setName(string n);
        void setMerit(int m);
        string getName();
        int getMerit() const;
        friend ostream &operator << (ostream &output, const University &Y);
        friend istream &operator>>( istream  &input, University &Y );
        

};

// Constructors
University::University()
{
    name = "";
    merit = 0;
}

University::University(string a, int b)
{
    name = a;
    merit = b;
}

// Destructor
University::~University()
{
    
}

// Setters
void University::setName(string n)
{
    name = n;
}
void University::setMerit(int m)
{
    merit = m;
}

// Getters
string University::getName()
{
    return name;
}
int University::getMerit() const
{
    return merit;
}

// Utility / Helper Functions


// Overloaded Operator (<<, >>) Functions
ostream &operator << (ostream &output, const University &Y)
{
    output << "University name: " << Y.name << "\nUniversity merit: " << Y.merit;
    return output;
}

istream &operator>>( istream  &input, University &Y )
{
    input >> Y.name >> Y.merit;
    while (Y.merit > 100 || Y.merit < 0)
    {
        cout << "Re-enter merit. Invalid input:\n";
        input >> Y.merit;
    }
    return input;
}
// Other Functions


//////////////////////////////////////////////

bool checkEligibility(const Student& s, const University& u)
{
    double x = s.getPercentage();
    double v = u.getMerit();
   
    if (x >= v)
    {
        return true;
    }
    else 
    {
        return false;
    }

}

void testStudentUniversity()
{
    Student student_a,student_b,student_c,student_d,student_e,student_f;
    University uni_a,uni_b;
    cout << "Enter Student 1 Information. Enter name, followed by age, followed by percentage. Each seperated by Enter/Space.\n";
    cin >> student_a;
    cout << "\nEnter Student 2 Information. Enter name, followed by age, followed by percentage. Each seperated by Enter/Space.\n";
    cin >> student_b;
    cout << "\nEnter Student 3 Information. Enter name, followed by age, followed by percentage. Each seperated by Enter/Space.\n";
    cin >> student_c;
    cout << "\nEnter Student 4 Information. Enter name, followed by age, followed by percentage. Each seperated by Enter/Space.\n";
    cin >> student_d;
    cout << "\nEnter Student 5 Information. Enter name, followed by age, followed by percentage. Each seperated by Enter/Space.\n";
    cin >> student_e;
    cout << "\nEnter Student 6 Information. Enter name, followed by age, followed by percentage. Each seperated by Enter/Space.\n";
    cin >> student_f;
    cout << "Enter University 1 Information. Enter name followed by merit. Each seperate by Enter/Space\n";
    cin >> uni_a;
    cout << "Enter University 2 Information. Enter name followed by merit. Each seperate by Enter/Space\n";
    cin >> uni_b;

    cout << "Now for eligibility\n.";
    cout << student_a << "\n can apply to:\n";
    if (checkEligibility(student_a, uni_a) == 1)
    {
        cout << uni_a;
    }
    if (checkEligibility(student_a, uni_b)==1)
    {
        cout << uni_b;
    }
    cout << student_b << "\n can apply to:\n";
    if (checkEligibility(student_b, uni_a) == 1)
    {
        cout << uni_a;
    }
    if (checkEligibility(student_b, uni_b)==1)
    {
        cout << uni_b;
    }
    cout << student_c << "\n can apply to:\n";
    if (checkEligibility(student_c, uni_a) == 1)
    {
        cout << uni_a;
    }
    if (checkEligibility(student_c, uni_b)==1)
    {
        cout << uni_b;
    }
    cout << student_d << "\n can apply to:\n";
    if (checkEligibility(student_d, uni_a) == 1)
    {
        cout << uni_a;
    }
    if (checkEligibility(student_d, uni_b)==1)
    {
        cout << uni_b;
    }
    cout << student_e << "\n can apply to:\n";
    if (checkEligibility(student_e, uni_a) == 1)
    {
        cout << uni_a;
    }
    if (checkEligibility(student_e, uni_b)==1)
    {
        cout << uni_b;
    }
    cout << student_f << "\n can apply to:\n";
    if (checkEligibility(student_f, uni_a) == 1)
    {
        cout << uni_a;
    }
    if (checkEligibility(student_f, uni_b)==1)
    {
        cout << uni_b;
    }

}

//////////////////////////////////////////////
// Question 2
//////////////////////////////////////////////

class Set
{   
    private:
        int *array_set;
        int size; 
    public:
        Set();
        Set (int s);
        Set (int *ref, int s);
        Set (const Set& obj); //copy constructor
        

        void setArray(int *xyz);
        void setSize(int siz);
        int getSize();
        int getArray();
        void print();
        void removeDup(int *set,int &size);
        void setSort(int arr[], int n);
        ~Set();

     Set operator +(const Set& obj)
    {
       int m = size + obj.size;
       int* b = new int[m];
       int index= 0;
      for (int x = 0; x < size; x++){
      	b[x] = array_set[x];
         index++;
      }
      int temp =0;
      cout <<index<< endl;
      for (int x = 0; x < obj.size; x++){
      	b[index] = obj.array_set[x];
      	index++;
      }
      Set to_return(b, m);
      setSort(to_return.array_set, to_return.size);
      removeDup(to_return.array_set, to_return.size);
      return to_return;

    }
 Set operator -(const Set& obj)
    {
        Set x;
        x.size = 0;
        for (int i = 0; i < size; i++)
        {
            for (int z = 0; z < obj.size; z++)
            {
                if (array_set[i]==obj.array_set[z])
                {
                    x.array_set[x.size] = array_set[i];
                    x.size = x.size + 1;

                }
            }
        }
        return x;

    }
 friend ostream& operator<<(ostream& os, Set& obj) {
 	os << "{";
 	for (int i = 0; i < obj.size; i++) {
 	os <<  obj.array_set[i] << " ";
 	}
 	os << "}";
 	return os;
 }
 friend istream& operator >>(istream& os, Set& obj)
 {
     cout << "\nEnter size of array\n";
     os >> obj.size;
     cout << "\n Enter elements of array\n";
     for (int i = 0; i < obj.size; i++) {
 	os >>  obj.array_set[i];
 	}
 	return os;
 }


 string operator ==(const Set& obj)
    {
       if (size != obj.size) {
       	return "false";
       }
       else {
       	for (int x = 0; x < size; x++) {
       		if(array_set[x] != obj.array_set[x]) {
       			return "false";
       		}
       	}
       }
       return "true";
    }




        //overload + for union of set
        //overload - for intersection of two sets
        //overload == to see if two sets equal
        //overload >> to input all elements of a set
        //overload << to print the entire set
        


};

// Constructors
    Set::Set()
    {
        size = 0;
        array_set = new int [size];

    }

    Set::Set (int s)
    {
        size = s;
        array_set=new int[s];
        for(int i = 0; i < size; i++)
        {
            array_set[i] = 0;
        }
    }

    Set::Set (int *ref, int s)
    {
        size = s;
        array_set = new int[size];
        for (int i=0; i<size; i++)
        {
            array_set[i] = ref[i];
        }
    }

    Set::Set(const Set& obj)
    {
        array_set = new int[size];
        for (int i = 0; i< size; i++)
        {
            array_set[i] = obj.array_set[i];
        }
    }

// Destructor
Set::~Set()
{
  cout << "\ndestructor for set object called\n";
}

// Setters
void Set::setArray(int *xyz)
{
    array_set = xyz;
}
void Set::setSize(int siz)
{
    size = siz;
}

// Getters
int Set::getArray()
{
    return *array_set;
}
int Set::getSize()
{
    return size;
}

// Utility / Helper Functions

void Set::print()
{
    for (int i=0; i<size; i++)
    {
        cout << array_set[i] << " ";
    }
    cout << endl;
}
void Set::setSort(int arr[], int n)
{
   int m;
   int t;
   for (int z = 0; z < n - 1; z++) {
      m = z;
      for (int j = z + 1; j < n; j++)
      {
      if (arr[j] < arr[m])
     { m = j;
      t = arr[z];
      arr[z] = arr[m];
      arr[m] = t;
     }
      }
}
}
void Set::removeDup(int *set,int &size)
{
  int pos = 0;
	for (int i=0; i<size; i++)
	{
		if (set[i] == set[i+1])
		{
			pos = i;

			for (int j = pos + 1; j <= size; j++)
			{
 				set[j-1] = set[j];
			}
			size--;
			i=0;
		}
	}
}
// Overloaded Operator (<<, >>) Functions


void testSet() 
{
    int size1 = 0;
    int size2 = 0;
    cout << "Please enter array size" << endl;
    cin >> size1;
    int arr1[size1];
    for (int i=0; i<size1; i++)
    {
        cout << "please enter element for index " << i << endl;
        cin >> arr1[i];
    }
    Set set1(arr1,size1);

    cout << "Please enter array size" << endl;
    cin >> size2;
    int arr2[size2];
    for (int i=0; i<size2; i++)
    {
        cout << "please enter element for index " << i << endl;
        cin >> arr2[i];
    }

    Set set2(arr2,size2);
    Set set3;
    set3 = set1 + set2;
    
    cout << "the union is " << set3;
    cout << "\nNow we check intersection\n";
    Set set4;
    set4 = set1 - set2;
    cout << set4 <<endl;
    
    string isEqual;
    cout <<"\nchecking == overloaded operator" << endl;
    isEqual = set1==set2;
    cout << isEqual << endl;
   
    cout <<"\nchecking >> overloaded operator\n";
    Set testset1;
    cin >> testset1;
    cout << "\nchecking  << overloaded operator \n" << endl;
      cout<<testset1;

    
}
    

//////////////////////////////////////////////
// Question 3
//////////////////////////////////////////////

class Player
{
    private: 
        string name;
        int id;
    public:
        Player();
        Player(string s, int i);
        string getName();
        int getId();
        void setName(string s);
        void setId(int i);
        int rollADice();

        

};


// Constructors
Player::Player()
{
    name = "";
    id = 0;
}
Player::Player(string s, int i)
{
    name = s;
    id = i;
}

// Destructor


// Setters
void Player::setName(string s)
{
    name = s;
}
void Player::setId(int i)
{
    id = i;
}
// Getters
int Player::getId()
{
    return id;
}
string Player::getName()
{
    return name;
}

// Utility / Helper Functions


// Overloaded Operator (<<, >>) Functions


// Other Operations - e.g., rollADice()

int Player::rollADice()
{
    return (rand()%7 + 1);
}

//////////////////////////////////////////////

class Team
{
    private:
        Player *Team_List;
        int curr_players, curr_score;
        string team_name;
    public:
        Team();
        Team(string t, int p);
        void printTeam();
        void setScore(int s);
        void setName(string s);
        int getScore();
        string getName();
        int chooseAndPlay();

};

// Constructors
    Team::Team()
    {
        curr_score = 0;
        curr_players = 0;
        team_name="";
    }
    Team::Team (string t, int p) {
      curr_score = 0;
	team_name = t;
	curr_players = p;
	Team_List = new Player[p];
	for (int x = 0; x < p; x++) {
		string name; 
		cout << "Type member name: "; // Type name and press enter
        cin >> name ; // Get user input from the keyboard
        Team_List[x] = Player(name, x+1);
	}
    }



// Destructor


// Setters
void Team::setScore(int s)
{
    curr_score = s;
}
void Team::setName(string s)
{
    team_name = s;
}
// Getters
string Team::getName()
{
    return team_name;
}
int Team::getScore()
{
    return curr_score;
}

// Utility / Helper Functions


// Overloaded Operator (<<, >>) Functions


// Other Operations - e.g., printTeam(), chooseAndPlay()
void Team::printTeam() {
	cout << "Team Name is: " << team_name <<endl;
	cout << "Total Players are: " << curr_players << endl;
	cout << "Player details are as follows" << endl;
	for (int x = 0; x < curr_players; x++) {
		cout << Team_List[x].getName() << ",";
		cout << Team_List[x].getId() << endl;
	}
}
int Team::chooseAndPlay() {
    int rand_index = rand() % curr_players;
    Player Chosen_Player = Team_List[rand_index];
    cout << "Randomly chosen player and ID is:" << Chosen_Player.getName()<<"," << Chosen_Player.getId() <<endl;
    int diceroll;
    diceroll = Chosen_Player.rollADice();
    return diceroll;
}

void testPlay() 
{
string t_name;
int t_players;
cout << "Enter Team Name for Team 1" << endl;
cin >> t_name;
cout << "Enter Total Players in Team 1" << endl;
cin >> t_players;
Team FirstTeam = Team(t_name, t_players);
FirstTeam.printTeam();
cout << "Enter Team Name for Team 2" << endl;
cin >> t_name;
cout << "Enter Total Players in Team 2" << endl;
cin >> t_players;
Team SecondTeam = Team(t_name, t_players);
SecondTeam.printTeam();
int new_score = 0;
 while (1) {
 string input;
 cout << "Type anything to start the game. Type ""stop"" to end it:"  << endl;
 cin >> input;
 if (input == "stop") {
 	int team1 = FirstTeam.getScore();
 	int team2 = SecondTeam.getScore();
 	if (team1 > team2) {
      cout << "WINNER INFO:" << endl;
      FirstTeam.printTeam();

 	}
 	else if (team2 > team1) {
    cout << "WINNER INFO:" << endl;
      SecondTeam.printTeam();
 	}

 	else {
     cout << "The match was a draw" << endl;
 	}
 	break;
 }
 else {

 	int P1 = FirstTeam.chooseAndPlay();
 	int P2 = SecondTeam.chooseAndPlay();
 	cout <<FirstTeam.getName()<<"rolled: "<< P1 << endl;
 	cout << SecondTeam.getName()<< "rolled: " << P2 << endl;
 	if (P1 > P2) {
 		new_score = FirstTeam.getScore();
 		new_score = new_score + 1;
 		FirstTeam.setScore(new_score);
 		cout <<FirstTeam.getName() << " has a score of:" << FirstTeam.getScore() << endl;
 		cout <<SecondTeam.getName() << " has a score of:" << SecondTeam.getScore() << endl;
 	}
 	else if (P1 < P2) {
        new_score = SecondTeam.getScore();
 		new_score = new_score + 1;
 		SecondTeam.setScore(new_score);
 		cout <<FirstTeam.getName() << " has a score of:" << FirstTeam.getScore() << endl;
 		cout <<SecondTeam.getName() << " has a score of:" << SecondTeam.getScore() << endl;
 	}
 }

 }
    
}


//////////////////////////////////////////////
// main()
// calls test funcitons
//////////////////////////////////////////////

int main()
{
   testStudentUniversity();

   testSet();

   testPlay();

   return 0;
}
