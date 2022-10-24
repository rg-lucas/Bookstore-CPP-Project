// Lucas Resende Gomes - Real Time Systems - LabWork 2# - 26/09/2022

#include <iostream> //inserting the libraries and standart namespace
#include <string>
#include <fstream>
using namespace std;

class Books { //inicializing the class "Books"
public:
	string Title, FilmTitle;
	int ID, FilmLength, Price, FilmPrice;
	bool True;
	Books* next;
	Books(); //Defining the initial values
	Books(string, int, int);
	Books(const Books&);
	void set_Title(string); //Defining the functions that will get and set the values of the class books
	string get_Title();
	void set_ID(int);
	int get_ID();
	void set_Price(int);
	int get_Price();
	void set_next(Books*);
	Books* get_next();
	void set_FilmTitle(string);
	string get_FilmTitle();
	void set_FilmPrice(int);
	int get_FilmPrice();
	void set_FilmLength(int);
	int get_FilmLength();
	void set_Film(bool);
	bool get_Film();
	//void set_Pages(int);
	//int get_Pages;
	//void set_Stock(int);
	//int get_Stock;
	//string Author;
	//int Pages, Stock;
};
//Coding the preveously defined functions
Books::Books() {
	Title = "";
	ID = 0;
	Price = 0;
	FilmTitle = "";
	FilmPrice = 0;
	FilmLength = 0;
	next = NULL;
}
/*
Books::Books(string Title, int ID, int Price, string FilmTitle, int FilmLenght, int FilmPrice) {
	this->Title = Title;
	this->ID = ID;
	this->Price = Price;
	this->FilmTitle = FilmTitle;
	this->FilmLenght = FilmLenght;
	this->FilmPrice = FilmPrice;
	this->next = NULL;
}

Books::Books(const Books& b) {
	this->Title = b.Title;
	this->ID = b.ID;
	this->Price = b.Price;
	this->FilmTitle = b.FilmTitle;
	this->FilmLength = b.FilmLength;
	this->FilmPrice = b.FilmPrice;
	this->next = b.next;
}
*/
// Functions to Get and Set the data of the Books.
//
// In this part were created the functions that latter will be
// used to set the Book title, Id and Price, as well as the
// Films Title, length and Price.
void Books::set_Title(string Title) {
	this->Title = Title;
}
string Books::get_Title() {
	return Title;
}
void Books::set_ID(int ID) {
	this->ID = ID;
}
int Books::get_ID() {
	return ID;
}
void Books::set_Price(int Price) {
	this->Price = Price;
}
int Books::get_Price() {
	return Price;
}
void Books::set_next(Books* n) {
	this->next = n;
}
Books* Books::get_next() {
	return next;
}
void Books::set_FilmTitle(string FilmTitle) {
	this->FilmTitle = FilmTitle;
}
string Books::get_FilmTitle() {
	return FilmTitle;
}
void Books::set_FilmLength(int FilmLenght) {
	this->FilmLength = FilmLenght;
}
int Books::get_FilmLength() {
	return FilmLength;
}
void Books::set_FilmPrice(int FilmPrice) {
	this->FilmPrice = FilmPrice;
}
int Books::get_FilmPrice() {
	return FilmPrice;
}
void Books::set_Film(bool True) {
	this->True = True;
}
bool Books::get_Film() {
	return True;
}

//Creating the Catalog, that will be filled by the books. The books data were defined on the class Books, defined above.
//In this part of the code, we will be using the get and set functions to make Catalog functions work.
//The functions present in this class will be calling the functions of the class Books, so that they can work properly.
class Catalog {
private:
	Books* head, * tail; //Creating the head and tail of the book list
public:
	Catalog();
	Catalog(const Catalog &c);
	void addBook(string, int, int); //Add a book to the list
	void addBF(string, int, int, string, int, int);
	void deleteBook(int); //Delete a book from the list
	void showCatalog(); //Showing the list of books
	void editTitle(int, string);//Editing the Title
	void editPrice(int, int);//Editing the Price
	void editFilmTitle(int, string);//Editing the Film Title
	void editFilmPrice(int, int);//Editing the Film Price
	void editFilmLength(int, int);//Editing the Film Length
	void searchID(int);//Function that Searches the Book by it's ID
	void searchTitle(string);//Function that Searches the Book by it's Title
	void saveCatalog();// Function That Saves the Catalog in a .txt fille, so that we can have the data latter
	void readCatalog();// Function that reads the preveously saved catalog (the .txt file)
	void Menu();// The Manu Function, this function will be called repetedly, so we can keep calling the catalog functions while using the code, it will be explained latter
};
Catalog::Catalog() { //Defining the initial values
	head = NULL;
	tail = NULL;
}
Catalog::Catalog(const Catalog& c) { // Defining the Catalog const, so we kepp a copy of it saved.
	this->head = c.head;
	this->tail = c.tail;
}
void Catalog::addBook(string Title, int ID, int Price) {
	Books* NewBook = new Books;
	NewBook->set_Title(Title); //Setting the new book informations, this function call the Class Book functions.
	NewBook->set_ID(ID);
	NewBook->set_Price(Price);

	if (head == NULL) { //If the head = Null, that means that  there isn't a book in the list,
		head = NewBook; //so it will be the head and the tail ate the same time,
		tail = NewBook; //because it's the only book.
	}
	else {
		Books* temp = tail;			//In case that the add book isn't the first one
		temp->next = NewBook;		//It will be placed after the preveously defined book
		tail = NewBook;				//Creating a linked List, or as we called, our Catalog.

	}
}
void Catalog::addBF(string Title, int ID, int Price, string FilmTitle, int FilmPrice, int FilmLength) {
	Books* NewBook = new Books;
	NewBook->set_Title(Title);				// This function is an enrenciment of the AddBook
	NewBook->set_ID(ID);					// Now it's possible to also add a related film, in case there is an adaption
	NewBook->set_Price(Price);				// This function will be called in the Menu only if the user asks to add a movie.
	NewBook->set_FilmTitle(FilmTitle);		// In case that there isn't a film, the function AddBook will be called,
	NewBook->set_FilmPrice(FilmPrice);		// Then only the books title, Id and Price will be added to the catalog
	NewBook->set_FilmLength(FilmLength);

	if (head == NULL) {						//If the head = Null, that means that  there isn't a book in the list,
		head = NewBook;						//so it will be the head and the tail ate the same time,
		tail = NewBook;						//because it's the only book.
		return;
	}
	else{
		Books* temp = head;
		while (temp->next != NULL) {		// If it isn't the first, it will keep the linked list
			temp = temp->next;
		}
		temp->next = NewBook;
	}

}
void Catalog::deleteBook(int BookDel) {
	Books* temp1 = head, * temp2 = NULL;

	if (head == NULL) {
		cout << "Catalog is empty!" << endl;
		return;
	}

	temp1 = head;

	while (temp1 != NULL) {
		if (temp1->get_ID() == BookDel) {
			if (temp1 == head) {
				head = head->next;
				delete temp1;
				return;
			}

			temp2->next = (temp1->next);
			delete temp1;
		}
		temp2 = temp1;
		temp1 = temp1->next;
	}
}
void Catalog::showCatalog() {				// This is the function that acceses the linked list and prints its data
	Books* temp = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first\n\n";			// If there isn't a list, it's impossible to print
		return;
	}
	else {
		cout << endl << "Your Catalog: " << endl << endl;
		while (temp != NULL) {
			cout << "Title: " << temp->get_Title() << "\tID: " << temp->get_ID() << "\tBook Price: " << temp->get_Price() << "\n"; // In case of a Book without an movie/film
			if (temp->get_FilmTitle()!="") { // Cheking if there is a Film linked to the book, by seeing if it matches the "basic" value, given when no other data is atribuated to the Film category
				cout << "\nFilm Title: " << temp->get_FilmTitle() << "\tFilm Lenght: " << temp->get_FilmLength() << "\tFilm Price: " << temp->get_FilmPrice() << endl;
			} //Printing the Films data when there was a film adaptation
			cout << "\n";

			temp = temp->next; //Moving to the next book of the linked list
		}
	}
}
void Catalog::editTitle(int ID, string title) {
	Books* temp1 = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first" << endl;
		return;
	}

	temp1 = head;

	while (temp1 != NULL) {
		if (temp1->get_ID() == ID) {			//This function gets the ID chosen by the client, and if there is a book
			temp1->set_Title(title);			// that matches the chosen ID, it will asks for the new Title and then recive the new title
		}
		temp1 = temp1->next;
	}
}
void Catalog::editPrice(int ID, int price) {
	Books* temp1 = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first" << endl;
		return;
	}

	temp1 = head;

	while (temp1 != NULL) {
		if (temp1->get_ID() == ID) {			//This function gets the ID chosen by the client, and if there is a book
			temp1->set_Price(price);			// that matches the chosen ID, it will asks for the new Price and then recive the new Price
		}
		temp1 = temp1->next;
	}
}
void Catalog::editFilmTitle(int ID, string FilmTitle) {
	Books* temp1 = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first" << endl;
		return;
	}

	temp1 = head;

	while (temp1 != NULL) {
		if (temp1->get_ID() == ID) {				//This function have two main porpuses, the first is to chance a defined Film title, the second one is to
			temp1->set_FilmTitle(FilmTitle);		// Add a film inside the book variable, in case there wasn't a film adaptation when the library added the book
		}
		temp1 = temp1->next;
	}
}
void Catalog::editFilmPrice(int ID, int Filmprice) {
	Books* temp1 = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first" << endl;
		return;
	}

	temp1 = head;

	while (temp1 != NULL) {
		if (temp1->get_ID() == ID) {			 // As well as the Edit Film Title, this function have the same two porpuses, change and defines a film price
			temp1->set_FilmPrice(Filmprice);
		}
		temp1 = temp1->next;
	}
}
void Catalog::editFilmLength(int ID, int lenght) {
	Books* temp1 = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first" << endl;
		return;
	}

	temp1 = head;

	while (temp1 != NULL) {
		if (temp1->get_ID() == ID) {
			temp1->set_FilmLength(lenght);			// As well as the Edit Film Title, this function have the same two porpuses, change and defines a film length
		}
		temp1 = temp1->next;
	}
}
void Catalog::searchID(int ID) {
	Books* temp = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first" << endl;		// It's impossible to find a book if there isn't any book in the catalog
		return;
	}

	temp = head;

	cout << endl << "Results of ID:" << endl;

	while (temp != NULL) {														// It will call the get Id function and then print the details of the Book with matched ID.
		if (temp->get_ID() == ID) {
			cout << "Title: " << temp->get_Title() << "\tID: " << temp->get_ID() << "\tBook Price: " << temp->get_Price() << "\n";
			if (temp->get_FilmTitle() != "") {									// If there is a Movie, it will also print their details.
				cout << "\nFilm Title: " << temp->get_FilmTitle() << "\tFilm Lenght: " << temp->get_FilmLength() << "\tFilm Price: " << temp->get_FilmPrice() << endl;
			}
		}
		temp = temp->next;
	}
}
void Catalog::searchTitle(string title) {
	Books* temp = head;

	if (head == NULL) {
		cout << "No catalog to show, please add some books first" << endl;		// Still is impossible to find a book if there isn't any book in the catalog
		return;
	}

	temp = head;

	cout << endl << "Results of title:" << endl;

	while (temp != NULL) {
		if (temp->get_Title() == title) {										// It will call the get Title function and then print the details of the Book with that Title
			cout << "Title: " << temp->get_Title() << "\tID: " << temp->get_ID() << "\tBook Price: " << temp->get_Price() << "\n";
			if (temp->get_FilmTitle() != "") {									// If there is a Movie, it will also print their details.
				cout << "\nFilm Title: " << temp->get_FilmTitle() << "\tFilm Lenght: " << temp->get_FilmLength() << "\tFilm Price: " << temp->get_FilmPrice() << endl;
			}
		}
		temp = temp->next;
	}
}
void Catalog::saveCatalog() {

	ofstream write("Saraiva_Catalog.txt");
	Books* temp = head;

	while (temp) {							// This function will save the catalog data in a .txt file, so that we can save this details and call for it latter
		write << "id: " << temp->get_ID() << "\t Price: " << ":" << temp->get_Price() << "\t Title: " << temp->get_Title() << endl;			// Saving the books details
		if (temp->get_FilmTitle() != "") {				// Saving the film adaptation details if necessary
			write << "Flim: " << temp->get_FilmTitle() << "\t FlimPrice: " << temp->get_FilmPrice() << "\t FilmLenght: " << temp->get_FilmLength();
		}
		write << endl;
		temp = temp->next;
	}
	write.close();
}
/*void Catalog::readCatalog() {

	ifstream read("Saraiva_Catalog.txt");
	char pv = ';', dp = ':', pt = '.';
	string lin, name, aux, esp = " ", filmname;
	int ID, filmlenght;
	int price, filmprice;

	if (read.fail()) {
		cout << endl << "No catalog file to read" << endl;		// if there is no catalog, this message will be printed
	}
	else {

		if (!read.is_open()) {
			cout << endl << "Catalog was download, please continue" << endl;		// When finished the reading, this message will be sent
			read.clear();
			read.close();
		}
		else {

			while (!read.eof()) {								// Reading the .txt file and allocating the data inside the catagories,
				getline(read, lin);								// Using the off stream and instream functions, as well as the Add Book and Add Book and Film functions
				if (lin.length() > 1) {
					ID = stoi(lin.substr(lin.find("ID:") + 3, 4));
					price = stoi(lin.substr(lin.find("Price:") + 6, 5));
					name = lin.substr(lin.find("Title:") + 6, (lin.find(";") - lin.find("Title:") - 6));
					if ((lin.substr(lin.find(";\t") + 2, 6)) == "FilmTitle:") {
						filmname = lin.substr(lin.find("FilmTitle:") + 10, (lin.find("FilmPrice:") - lin.find(";") - 9));
						filmprice = stoi(lin.substr(lin.find("FilmPrice:") + 10, 5));
						filmlenght = stoi(lin.substr(lin.find("FilmLength:") + 6, 3));
						addBF(name, ID, price, filmname, filmprice, filmlenght);
					}
					else {
						addBook(name, ID, price);
					}
				}
			}
		}
	}
	cout << "\n\tDatabase download\n\n";
	read.close();
}
*/
void Catalog::Menu() {
	int id = 0, option = 0, filmlenght = 0, editname, yes; // Defining the variables that will be running the Menu
	int price = 0, filmprice = 0;
	string name = "NoTitle", Film = "NoFilmName";
	bool back = 1;

	cout << "MAIN MENU - Select operation:";				// Printing the Menu option for the client to chose
	cout << "\n1- Show Catalog";
	cout << "\n2- Add Book";
	cout << "\n3- Delete Book";
	cout << "\n4- Edit Book";
	cout << "\n5- Search Book";
	cout << "\n6- Save Catalog";
	cout << "\n7- Edit Film\n\n";
	cin >> option;

	if (option == 1) {									// After the chosen option, it will run in this if/else until matches to one possibility
		showCatalog(); // Print the catalog
	}
	else {
		if (option == 2) { // Adding a Book
			cout << "Please type the name of the Book:  "; //Asking to the client to input the Book data
			cin >> name;
			cout << "Please type the ID of the Book:  ";
			cin >> id;
			cout << "Please type the Price of the Book:  ";
			cin >> price;
			cout << "If this Book doesn't have a film adaptation, type 0, if it does, type 1 \n\n";
			cin >> yes;
			if (yes == 0) { // Defining if there will be a movie adaptation or not
				addBook(name, id, price); // If there isn't, AddBook will be called
				showCatalog();
				cout << endl;
			}
			else { // If there is, new data will be called, the Film data now.
				cout << "Please type the name of the film:  ";
				cin >> Film;
				cout << "Please type the lenght in minutes of the:  ";
				cin >> filmlenght;
				cout << "Please type the Price of the Film:  ";
				cin >> filmprice;
				addBF(name, id, price, Film, filmlenght, filmprice);  // And then the AddBF function will be called
				showCatalog();
				cout << "\n";
			}
		}
		else {
			if (option == 3) {			// Matching the Delete function
				cout << endl << "Select the ID to be deleted, or 0 to come back to menu: ";
				cin >> id;			// Receving the book Id to be deleted
				if (id == 0) {}
				else {
					deleteBook(id); // Matching the given ID to the Get Id function
					cout << endl << "This is your new catalog: ";
					showCatalog(); // Printing the new catalog after deleting
				}
			}
			else {
				if (option == 4) {	//Matching the Edit Function and asking for the Id of the book to be edited
					cout << "\nSelect the book ID that will be edited, or 0 to come back to menu: ";		// Checking if that was a mistake or not
					cin >> id;
					if (id == 0) { // IF there was a mistake, it will go back to the menu
						cout << "Ok, voltando pro menu";
					}
					else { // If there wasn't a mistake, askes for what information it will be changing
						cout << "\nDo you wish to edit the title of this book (1) or edit the price (2)?";
						cin >> editname;
					}
					if (editname == 1) { // Changing the name
						cout << "\nNew Title: ";
						cin >> name;
						editTitle(id, name);
					}
					else {
						if (editname == 2) { // Changing the price
							cout << "\nNew Price: ";
							cin >> price;
							editPrice(id, price);
						}
					}
					cout << "\nThe new Catalog is: "; // Printing the new catalog after editing
					showCatalog();
				}
				else {
					if (option == 5) {			// Matching the search functions, and making sure that you want to search for a book
						cout << endl << "What's the Book Title or Book Id that you're seaching for? To go back to menu (0): ";
						cin >> name; // Checking if you asked for the title search or the Id search
						if (isdigit(name[0])) {
							id = stoi(name);
							if (id == 0) {}
						}
						searchID(id); // Showing the results of and ID search
						searchTitle(name);	// Showing the results of the Title search
					}
					else {
						if (option == 6) { // Matching tho the save catalog function
							cout << endl << "To save the Catalog type 1.\nTo go back to menu(0): ";
							cin >> back;
							if (!back) {}
							saveCatalog(); // Saving the catalog
							cout << "Catalog uploaded";
						}
						else {
							if (option == 7) {	// Matching to the Edit Films data, that can have those two porpuses, adding a film to an old book or editing the film data
								cout << "\nSelect the book ID that the correspondend Film will be edited, or 0 to come back to menu: ";
								cin >> id;		// Chosing the film ID to make the changes
								if (id == 0) {}
								cout << "\nDo you wish to edit the title of this Film (1), edit the price (2), or edit the Film Lenght (3)?";
								cin >> editname; // Checking what film information to edit
								if (editname == 1) {
									cout << "\nNew Film Title: "; // Editing the Film Title
									cin >> name;
									editFilmTitle(id, name);
									showCatalog();

								}
								else {
									if (editname == 2) {
										cout << "\nNew Film Price: ";	// Editing the Film Price
										cin >> price;
										editFilmPrice(id, price);
										showCatalog();
										option = 0;

									}
									else {
										if (editname == 3) {
											cout << "\nNew Lenght: ";	// Editing the Film Length
											cin >> filmlenght;
											editFilmLength(id, filmlenght);
											showCatalog();
											option = 0;
										}
									}
								}
							}

						}
					}
				}
			}
		}
	}
}

int main() { // Initializing the main function
	Catalog Saraiva; // Giving the name to our catalog (Saraiva is a big book store in Brazil)
	int x = 1;
	// Saraiva.readCatalog(); //Doesn't Work

	while (x == 1) { // Creating a loop to keep getting inside of the Menu Function, and keep waiting for the client inputs to make the code run the proper way
		Saraiva.Menu();
		system("PAUSE");
		system("cls");
	}
	return 0;
}

