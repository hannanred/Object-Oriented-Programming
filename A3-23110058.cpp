//Press Alt + Z in VS Code to see comments better

#include <iostream>

using namespace std;


class Item
{
	string name;
	int price;
public:
	Item();
	Item(string s, int p);

	//function to display an item
	void display();

	//getters and setters
	string getName();
	int getPrice();
};


class Menu
{
	//You can change these items if you want :P
	Item menu_array[10] = { Item("McArabia",500), Item("McFlurry Oreo",150), Item("Chicken McNuggets",200), Item("Happy Meal",400), Item("Strawberry Shake",300), Item("Brownie",650), Item("Waffle Cone",120), Item("Choco Cone",160), Item("McCrispy",350), Item("Cappuccino Latte",250) };

public:
	void display();

	//getters (implement only when you need them)
	string getName(int i);
	int getPrice(int i);
};
class Order
{
	// this is a static variable used to give a unique order_number to every Order Object that is created. You can remove it if you don't need it.
	static int current_order_number;

	// the unique order number
	int order_number;

	int** order_items; //the 2D array

	//the number of items in this order (also the horizontal size of the order_items array)
	int num_items;

	//the total bill of this order
	int total_bill;

public:
	Order(); //default constructor

	~Order(); //destructor deletes the order_items 2D array

	Order(Menu menu);
	//parameterized constructor to which I am passing the Menu object.
	//Because to place the order, we will have to show the Menu to the user from which the user will choose items. We will also need the prices of these items from the menu.

	void display(Menu menu);
	//display all items in the menu

	//setters and getters (remove if not needed)
	void setStatus(int i);
	int getStatus();
	int getOrderNumber();

};


class Node
{
public:
	//Order is a pointer because it will be created Dynamically using the "new" keyword.
	Order* order;
	Node* next;
	Node();
	Node(Menu menu); //default constructor
	~Node(); //destructor deletes the "order"
   // Node(Menu *menu); 
	//You may use a parameterized constructor as well if that's your style. It's fine if you don't.
};


class LinkedList
{
	Node* head;
	Node* tail;

public:
	//default constructor
	LinkedList();

	~LinkedList();  //destructor traverses the list from head to tail and deletes every Node

	//this method copies a node (ptr) from another list to this list's tail
	void add(Node* ptr);

	//this method adds an Order object node to the tail of this list. For that, we will have to create an Order object. This method takes menu as argument because we must display the Menu to the user so that the user can choose the items for creating the Order.
	//Try implementing it without the menu and you will see the need for the menu arise. No need to take my word for it. You are allowed to change functions and their parameters. If you can make do without passing the menu, go ahead.
	void addToTail(Menu menu);

	//this function deletes the head node of the List. Be sure to use the "delete" keyword to delete the Node from memory as well.
	void removeFromHead();

	//the following moveOrderToCollectList function is a non-member friend function. It moves the head node of the preparing_queue list to the tail of the collect_queue list. This function may need a helper function called removeHeadWithoutDeleting. It's upto you. See if the need arises.
	friend void moveOrderToCollectList(LinkedList& preparing_queue, LinkedList& collect_queue);

	//you may need this helper function (it's okay if you don't)
	Node* removeHeadWithoutDeleting(Node* ptr);

	void display(Menu menu, bool option);

	//You may need to add parameters to the display() function. It's upto you.
	//One way is this:
	// void display(Menu *menu, bool option);
	//I'm passing the menu to the display() function because it may need to display the name and price of items in the order, which are in the Menu
	//The "option" parameter saves you from having to make two different display() functions with repeating code. 
	//If option=0, display only order_number of each order. If option=1, display all information of every order including items, price, etc.
	//You may need a heler function as well (it's upto you)
	// void displayHelper(Node *ptr, Menu *menu, bool option);
	//Try implementing a simple display() without passing it anything. You will feel the need to pass some stuff. Then start passing whatever you need.
};




class OrderSystem
{
	Menu menu;
	LinkedList preparing_queue;
	LinkedList collect_queue;

public:
	void addOrderToQueue();
	void setOrderToPrepared();

	void removeOrderFromQueue();
	void displayQueue();

	//I've already implementated this function for you :)
	bool displayOptions();
};

int main()
{
	OrderSystem system;
	bool continue_or_not;
	do continue_or_not = system.displayOptions();
	while (continue_or_not);

	return 0;
}


// //ITEM CLASS METHODS

Item::Item()
{
	name = "";
	price = 0;

}
Item::Item(string s, int p)
{
	name = s;
	price = p;
}
void Item::display()
{
	cout << name << "\t" << price;
}
string Item::getName()
{
	return name;
}
int Item::getPrice()
{
	return price;
}


// //MENU CLASS METHODS

// // make sure that the table is properly presented
// // item# is right aligned,

// // Item Name is left aligned
// // Item Price is right aligned
void Menu::display()
{
	cout << "-----MENU-----\n";
	cout << "Index\tName\tPrice\n";
	for (int i = 0; i < 10; i++)
	{
		cout << i + 1 << "\t";
		menu_array[i].display();
		cout << endl;
	}
}
string Menu::getName(int i)
{
	return menu_array[i].getName();
}
int Menu::getPrice(int i)
{
	return menu_array[i].getPrice();
}


// //ORDER CLASS METHODS AND ATTRIBUTE

Order::Order()
{
	order_number = 0;
	order_items[0][0];
	num_items = 0;
	total_bill = 0;
}

int Order::current_order_number = 0;
// //You can use this static variable to generate unique incrementing order_numbers. You can use some other way if you don't like this.

Order::Order(Menu menu)
{
	order_number = 0;
	total_bill = 0;
	current_order_number = current_order_number + 1;
	order_number = current_order_number;
	cout << "How many items do you want to order?: ";
	cin >> num_items;
	cout << "\n";
	menu.display();

	order_items = new int* [3];
	for (int i = 0; i < 3; i++)
	{
		order_items[i] = new int[num_items];
	}
	cout << endl;
	cout << endl;
	for (int i = 0; i < num_items; i++)
	{
		int z;
		int x;
		cout << "Enter Item " << i + 1 << " Number: ";
		cin >> z;
		z = z - 1;
		order_items[0][i] = z;
		cout << "\tEnter Quantity of " << menu.getName(z) << ": ";
		cin >> x;
		order_items[1][i] = x;
		order_items[2][i] = menu.getPrice(z) * x;
		total_bill = total_bill + (menu.getPrice(z) * x);

	}
}


Order::~Order()
{
	for (int i = 0; i < 3; i++)
	{
		delete[] order_items[i];
	}
	delete[] order_items;
}




// // make sure that the table is properly presented
// // item# is right aligned,
// // Item Name is left aligned
// // Item Price is right aligned
void Order::display(Menu menu)
{
	cout << "Order Number: " << order_number;
	for (int i = 0; i < num_items; i++)
	{
		cout << "\n" << menu.getName(order_items[0][i]) << "\tx" << order_items[1][i] << "\t" << order_items[2][i];
	}
	cout << "\nTotal Bill: " << total_bill;
}

// void Order::setStatus(int i) 
// {

// }

// int Order::getStatus() 
// {

// }

int Order::getOrderNumber()
{
	return order_number;
}





// //NODE CLASS METHODS
Node::Node()
{
	Order* order = new Order;
	Node* next;
}
Node::Node(Menu menu)
{
	order = new Order;
}
Node::~Node()
{
	delete order;
}



// //LINKED LIST CLASS METHODS

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
}
void LinkedList::add(Node* ptr)
{
	if (tail == NULL || head == NULL)
	{
		head = tail = ptr;
		head->next = NULL;
		tail->next = NULL;
	}
	else if (ptr != NULL)
	{
		tail->next = ptr;
		tail = ptr;
		tail->next = NULL;
	
	}
}
void LinkedList::addToTail(Menu menu)
{
	menu.display();
	Node* temp = new Node(menu);
	Order* ord = new Order(menu);


	if (head == NULL || tail == NULL)
	{
		temp->order = ord;
		head = tail = temp;
	}
	else
	{
		temp->order = ord;
		tail->next = temp;
		tail = temp;
	}


}
void LinkedList::removeFromHead()
{
	if (head == NULL)
	{
		return;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		temp->next = NULL;

	}
}
void moveOrderToCollectList(LinkedList& preparing_queue, LinkedList& collect_queue)
{
	Node* temp;
	temp = preparing_queue.head;
	preparing_queue.removeFromHead();
	collect_queue.add(temp);

}

LinkedList::~LinkedList()
{
	Node* temp;
	Node* temps;
	temp = head;
	if (temp == NULL) return;
	do {

		temps = temp->next;
		delete temp;

	} while (temps != NULL);

}

void LinkedList::display(Menu menu, bool option)
{
	Node* temp = head;
	if (option == 0) {
		while (temp != NULL)
		{
			cout << temp->order->getOrderNumber() << "\n";
			temp = temp->next;
		}
	}
	else if (option == 1)
	{
		
			while (temp != NULL)
			{
				temp->order->display(menu);
				cout << "\n\n";
				temp = temp->next;
			}
		
	}
}



// //ORDER SYSTEM CLASS METHODS


void OrderSystem::addOrderToQueue()
{
	Menu menu;
	Order* order = new Order(menu);
	Node* temp = new Node();
	temp->order = order;
	preparing_queue.add(temp);
	cout << "-----Preparing-----\n";
	preparing_queue.display(menu, 1);


}
void OrderSystem::setOrderToPrepared() {
	Menu menu;
	moveOrderToCollectList(preparing_queue, collect_queue);
	cout << "\n----Preparing----\n";
	preparing_queue.display(menu, 0);
	cout << "\n----Collect:----\n";
	collect_queue.display(menu, 0);
}
void OrderSystem::removeOrderFromQueue() {
	Menu menu;
	collect_queue.removeFromHead();

	cout << "\n----Preparing----\n";
	preparing_queue.display(menu, 0);
	cout << "\n----Collect:----\n";
	collect_queue.display(menu, 0);
}
void OrderSystem::displayQueue() {
	Menu menu;
	cout << "\n----Preparing----\n";
	preparing_queue.display(menu, 1);
	cout << "\n----Collect:----\n";
	collect_queue.display(menu, 1);
}



bool OrderSystem::displayOptions()
{
	cout << "\nPress 1 to Place New Order\nPress 2 to Set Order to Prepared\nPress 3 to Collect Order\nPress 4 to View Queue\nPress 5 to Quit.\nYour Input: ";
	int option;
	cin >> option;

	switch (option)
	{
	case 1:
		addOrderToQueue();
		return 1;
	case 2:
		setOrderToPrepared();
		return 1;
	case 3:
		removeOrderFromQueue();
		return 1;
	case 4:
		displayQueue();
		return 1;
	default:
		return 0;
	}
}

// //END
