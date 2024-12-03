#include <unistd.h>
#include <climits>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdlib.h>

/*
         INFORMATION ABOUT PROJECT
PROJECT NAME     : BOOKSHOP MANAGEMENT SYSTEM
CREATED BY       : AKASH KUMAR
LANGUAGE         : C++
DATE OF CREATION : 01/02/2022
PLATFORM         : LINUX, WINDOWS AND MAC(not tested) 
TESTED ON        : UBUNTU 18.04 , KALI LINUX, RED HAT, WINDOWS 10
ABOUT PROJECT    : Bookshop Management System is a application that helps to keep track of all the book and customer records .
*/

//----------------------------CLASS FOR SHOP---------------------------
class Shop {
  public:
   char ShopName[200];
   char ShopOwner[200];
   char ContactNumber[30];
   char Address[200];
   char EMail[200];
   void GetShopDetails();
   void DisplayDetails_Head();
};

void Shop::GetShopDetails() {
   std::cout << "\n";
   std::cout << "\t Bookshop name         ";
   std::cin.getline(ShopName, 200);
   std::cout << "\t Name of owner         ";
   std::cin.getline(ShopOwner, 200);
   std::cout << "\t Contact Number        ";
   std::cin.getline(ContactNumber, 30);
   std::cout << "\t E-Mail Address        ";
   std::cin.getline(EMail, 200);
   std::cout << "\t Address of Bookshop   ";
   std::cin.getline(Address, 200);
}
//---------------------------------------------------------------------------

//-----------------------CLASS FOR BOOKSHOP------------------------------------
class Bookshop {
  public:
   int BookID;              // Total Number of Copies
   char BookName[100];      // Name of book
   char BookAuthor[100];    // Author of book
   void GetBookData();      // Get Data about book from user
   void DisplayAllBooks();  // Display data of all books
   int NextBookID();        // Return next book ID
   int NoCopies;
   int BookPrice;
   int NextBookPrice();
};

void Bookshop::GetBookData() {
   std::cout << "\n\tBook ID               ";
   std::cin >> BookID;
   std::cout << "\tName of Book          ";
   std::cin.ignore();
   std::cin.getline(BookName, 100);
   std::cout << "\tAuthor of Book        ";
   std::cin.getline(BookAuthor, 100);
   std::cout << "\tNumber of Copies      ";
   std::cin >> NoCopies;
   std::cout << "\tBook price(in ₹)      ";
   std::cin >> BookPrice;
}

void Bookshop::DisplayAllBooks() {
   std::cout << "\n\tBook ID               " << BookID;
   std::cout << "\n\tName Of book          " << BookName;
   std::cout << "\n\tAuthor of Book        " << BookAuthor;
   std::cout << "\n\tNumber of copies      " << NoCopies;
   std::cout << "\n\tBook price            ₹" << BookPrice;
   std::cout << "\n";
}

int Bookshop::NextBookID() { 
   return BookID;
}
int Bookshop::NextBookPrice() {
   return BookPrice;
}
//---------------------------------------------------------------------------

//---------------------------CLASS FOR CUSTOMER------------------------------
class Customer {
  public:
   int CustomerID;
   int CopiesTaken;
   char CustomerName[200];
   int BookIDTaken;
   char ContactNumber[100];
   void GetCustomerData();
   void DisplayCustomerData();
   int NextCustomerID();
};

void Customer::GetCustomerData() {
   std::cout << "\n\tCustomer ID                ";
   std::cin >> CustomerID;
   std::cout << "\tName of Customer           ";
   std::cin.ignore();
   std::cin.getline(CustomerName, 200);
   std::cout << "\tContact Number             ";
   std::cin.ignore();
   std::cin.getline(ContactNumber, 100);
   std::cout << "\tID of Book taken           ";
   std::cin >> BookIDTaken;
   std::cout << "\tNumber of Copies taken     ";
   std::cin >> CopiesTaken;
}

void Customer::DisplayCustomerData() {
   std::cout << "\n\tCustomer ID                          " << CustomerID;
   std::cout << "\n\tName of User                         " << CustomerName;
   std::cout << "\n\tID of Book taken                     " << BookIDTaken;
   std::cout << "\n\tNumber of Copies taken               " << CopiesTaken;
   std::cout << "\n\tContact Number                       +" << ContactNumber;
   std::cout << "\n";
}

int Customer::NextCustomerID() { 
   return CustomerID; 
}
//---------------------------------------------------------------------------

//--------------------------CLASS FOR SUCTOMER MODIFICATION WINDOW------------
class Customer_MW {
  public:
   int CustomerID;
   int CopiesTaken;
   char CustomerName[200];
   int BookIDTaken;
   char ContactNumber[100];
   void GetCustomerData_MW();
};

void Customer_MW::GetCustomerData_MW() {
   std::cout << "\n\tCustomer ID                ";
   std::cin >> CustomerID;
   std::cout << "\tName of Customer           ";
   std::cin.ignore();
   std::cin.getline(CustomerName, 200);
   std::cout << "\tContact Number             ";
   std::cin.ignore();
   std::cin.getline(ContactNumber, 100);
}
//---------------------------------------------------------------------------

//-----------------------Functions for Book Management------------------------
void AddBook();
void DeleteBook(int BookID);
void BookFinder();
void ModifyBook(int BookID);
void DisplayAllBooks();
//----------------------------------------------------------------------------

//---------------------Functions for Users Management-------------------------
void AddCustomer();
void DeleteCustomerData(int CustomerID);
void CustomerFinder(int CustomerID);
void ModifyCustomerData(int CustomerID);
void DisplayAllCustomersInDataBase();
void CustomerFinder(int CustomerID);
void Profile();
//----------------------------------------------------------------------------

//------------------------------Basic functions-------------------------------
int BooksAvailableInBookshop(int BookID);
int TotalCopiesInStore(int BookID);
void Menu();
void Ignore();
void CustomerDatabase();
void BookDataBase();
bool isBookExistsInBookshop(int BookID);
bool CustomerIDAvailable(int ID);
void DecreaseCopiesInStore(int CopiesTaken, int BookIDTakingByUser);
void BookNameByID(int BookID);
void AddNewCopiesInStore(int BookID, int NumberOfCopies);
bool BookExistsInBookshop(int BookID);
void Close();
void InstructionsWindow();
void BookFinder_ID(int BookID);
void BookFinder_Price(int MinPrice, int MaxPrice);
void Head();
void AddShopInformation();
bool isFileEmpty(std::ifstream& File);
//------------------------------------------------------------------------------------------------------------------------------------------


//--------------------------------------------------     Brain      ------------------------------------------------------------------------
void Menu() {
   system("clear");
   std::string Confirmation;
   int CodeEntry;
   int BookID;
   int CustomerID;
   int NumberOfCopies;
   Shop shop;
   std::ifstream DataFile;
   DataFile.open("ShopData.dat", std::ios::binary);
   DataFile.seekg(0, std::ios::beg);
   while (DataFile.read(reinterpret_cast<char*>(&shop), sizeof(Shop))) {
      std::cout << std::right << std::setw(60) << shop.ShopName << std::endl;
      std::cout << std::right << std::setw(70) << shop.Address << std::endl;
      std::cout << std::right << std::setw(57) << "Contact Number : " << shop.ContactNumber << std::endl;
      std::cout << std::right << std::setw(57) << "E-Mail Address : " << shop.EMail;
      std::cout << "\n\n";
      break;
   }
   std::cout << "\t\t+------------------------     Option Menu     -----------------------+" << std::endl;
   std::cout << "\t\t|                                                                    |" << std::endl;
   std::cout << "\t\t|                      1.  Sell a book                               |" << std::endl;
   std::cout << "\t\t|                      2.  Delete a Customer                         |" << std::endl;
   std::cout << "\t\t|                      3.  Edit a Customer Information               |" << std::endl;
   std::cout << "\t\t|                      4.  Display all Customers                     |" << std::endl;
   std::cout << "\t\t|                      5.  Search a Customer Data                    |" << std::endl;
   std::cout << "\t\t|                      6.  Add New Book                              |" << std::endl;
   std::cout << "\t\t|                      7.  Display All Books                         |" << std::endl;
   std::cout << "\t\t|                      8.  Search for a Book                         |" << std::endl;
   std::cout << "\t\t|                      9.  Delete a Book                             |" << std::endl;
   std::cout << "\t\t|                     10.  Modify a Book Data                        |" << std::endl;
   std::cout << "\t\t|                     11.  Add more Copies to a book                 |" << std::endl;
   std::cout << "\t\t|                     12.  My Bookshop Profile                       |" << std::endl;
   std::cout << "\t\t|                     13.  Exit                                      |" << std::endl;
   std::cout << "\t\t|                                                                    |" << std::endl;
   std::cout << "\t\t+--------------------------------------------------------------------+" << std::endl;

   std::cout << "Code@Entry ~$  ";
   std::cin >> CodeEntry;

   switch (CodeEntry) {
      case 1:
         AddCustomer();
         Ignore();
         Menu();
         break;
      case 2:
         system("clear");
         CustomerDatabase();
         std::cout << "\t\tDELETE A CUSTOMER DATA\n";
         std::cout << "Enter User ID                       ";
         std::cin >> CustomerID;
         DeleteCustomerData(CustomerID);
         break;
      case 3:
         system("clear");
         CustomerDatabase();
         std::cout << "\t\tEDIT DATA OF CUSTOMER\n";
         std::cout << "Enter Customer ID                   ";
         std::cin >> CustomerID;
         ModifyCustomerData(CustomerID);
         break;
      case 4:
         system("clear");
         DisplayAllCustomersInDataBase();
         Menu();
         break;
      case 5:
         system("clear");
         CustomerDatabase();
         std::cout << "\n\nSEARCH FOR A CUSTOMER\n";
         std::cout << "Enter customer ID                   ";
         std::cin >> CustomerID;
         CustomerFinder(CustomerID);
         break;
      case 6:
         system("clear");
         BookDataBase();
         AddBook();
         Menu();
         break;
      case 7:
         system("clear");
         DisplayAllBooks();
         Ignore();
         Menu();
         break;
      case 8:
         system("clear");
         BookFinder();
         break;
      case 9:
         system("clear");
         BookDataBase();
         std::cout << "\t\tDELETE A BOOK DATA";
         std::cout << "Enter BookID      ";
         std::cin >> BookID;
         std::cout << "Are you sure want to remove data of Book ID '" << BookID << "'[y/n]     ";
         std::cin >> Confirmation;
         if (Confirmation == "Y" || Confirmation == "y") {
            DeleteBook(BookID);
         } else {
            std::cout << "Information[011111]   : Confirmation cancelled\n";
            Ignore();
            Menu();
         }
         break;
      case 10:
         system("clear");
         BookDataBase();
         std::cout << "\t\tMODIFY A BOOK DATA";
         std::cout << "\n\nEnter Book ID                   ";
         std::cin >> BookID;
         ModifyBook(BookID);
         break;
      case 11:
         system("clear");
         BookDataBase();
         std::cout << "\n\nEnter Book ID                   ";
         std::cin >> BookID;
         std::cout << "Number of copies to add         ";
         std::cin >> NumberOfCopies;
         AddNewCopiesInStore(NumberOfCopies, BookID);
         break;
      case 12:
         system("clear");
         Profile();
         break;
      case 13:
         system("clear");
         Close();
         break;
      default:
         std::cout << "Error[1000] : No such type of option in menu !";
         Ignore();
         Menu();
   }
}

void Profile() {
   Shop shop;
   std::ifstream DataFile;
   DataFile.open("ShopData.dat", std::ios::binary);
   system("clear");
   std::cout << "\n\t\t\tMY BOOKSHOP PROFILE\n\n";
   while (DataFile.read(reinterpret_cast<char*>(&shop), sizeof(Shop))) {
      std::cout << "\t\tName of Bookshop       " << shop.ShopName << std::endl;
      std::cout << "\t\tOwner of Bookshop      " << shop.ShopOwner << std::endl;
      std::cout << "\t\tAddress                " << shop.Address << std::endl;
      std::cout << "\t\tContact Number         " << shop.ContactNumber << std::endl;
      std::cout << "\t\tE-Mail Adress          " << shop.EMail << std::endl;
      std::cout << std::endl << std::endl;
   }
   DataFile.close();
   Ignore();
   Menu();
}

bool isFileEmpty(std::ifstream& File) { 
   return File.peek() == std::ifstream::traits_type::eof(); 
}

void BooknameByID(int BookID) {
   std::ifstream DataFile;
   DataFile.open("BookDataBase.dat", std::ios::binary);
   Bookshop bookshop;
   while (DataFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookID() == BookID) {
         std::cout << bookshop.BookName;
      }
   }
}

void Ignore() {
   std::cout << "\nHit 'Enter' to continue ...";
   std::cin.ignore();
   std::cin.get();
}

void AddBook() {
   Bookshop bookshop;
   std::ofstream DataFile;
   DataFile.open("BookDataBase.dat", std::ios::binary | std::ios::app);
   bookshop.GetBookData();
   if (isBookExistsInBookshop(bookshop.BookID) == false) {
      DataFile.write(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop));
   } else {
      std::cout << "Database Error[11011] : Book ID is already taken for another book ...";
      Ignore();
      system("clear");
      Menu();
   }
   DataFile.close();
}

void CustomerDataEntry_ModificationWin(int BookID_customer, int CopiesTaken_customer) {
   Customer_MW customer_mw;
   Customer customer;
   std::ofstream file;
   file.open("CustomerDataBase.dat", std::ios::binary | std::ios::app);
   customer_mw.GetCustomerData_MW();
   if (CustomerIDAvailable(customer_mw.CustomerID) != false) {
      customer_mw.CopiesTaken = CopiesTaken_customer;
      customer_mw.BookIDTaken = BookID_customer;
      file.write(reinterpret_cast<char*>(&customer_mw), sizeof(Customer_MW));
   } else {
      std::cout << "Database Error[1111]  : Customer ID is already taken for someone else ... ";
      file.close();
      Ignore();
      Menu();
   }
   file.close();
}

void DisplayAllBooks() {
   Bookshop bookshop;
   std::ifstream f;
   f.open("BookDataBase.dat", std::ios::binary);
   std::cout << "\n\n";
   std::cout << "+--------------------------------------------------------------------------------------------------------------+\n";
   std::cout << "|                                                  BOOK  DATABASE                                              |\n";
   std::cout << "|______________________________________________________________________________________________________________|\n";
   std::cout << "| " << std::left << std::setw(9) << "Book ID"
             << "|  " << std::setw(39) << std::left << "Book Name"
             << "| " << std::left << std::setw(35) << "Book Author "
             << "| " << std::left << std::setw(10) << "Copies"
             << "| " << std::left << std::setw(7) << "Price"
             << "|\n";
   std::cout << "+----------+-----------------------------------------+------------------------------------+-----------+--------|\n";
   while (f.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      std::cout << "| " << std::left << std::setw(9) << bookshop.BookID << "| " << std::setw(40) << std::left << bookshop.BookName << "| " << std::left << std::setw(35) << bookshop.BookAuthor << "| " << std::left << std::setw(10) << bookshop.NoCopies << "| " << std::left << "₹ " << std::setw(5) << bookshop.BookPrice;
      std::cout << "|\n";
   }
   std::cout << "|______________________________________________________________________________________________________________|\n\n";
   f.close();
}

void DisplayAllCustomersInDataBase() {
   std::ifstream DataFile1;
   DataFile1.open("CustomerDataBase.dat", std::ios::binary);
   Customer customer;
   std::cout << "+-----------------------------------------------------------------------------------------------------------------------+\n";
   std::cout << "|                                              CUSTOMER DATABASE                                                        |\n";
   std::cout << "|_______________________________________________________________________________________________________________________|\n";
   std::cout << "|" << std::left << std::setw(11) << "Customer ID"
             << "| " << std::setw(35) << std::left << "Customer Name"
             << "| " << std::left << std::setw(40) << "Book Name"
             << "| " << std::left << std::setw(8) << "Copies"
             << "| " << std::left << std::setw(17) << "Contact"
             << "|\n";
   std::cout << "+-----------+------------------------------------+-----------------------------------------+---------+------------------+\n";
   while (DataFile1.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
      std::cout << "| " << std::left << std::setw(10) << customer.CustomerID << "| " << std::setw(35) << std::left << customer.CustomerName << "| " << std::left << std::setw(40);
      BooknameByID(customer.BookIDTaken);
      std::cout << "| " << std::left << std::setw(8) << customer.CopiesTaken << "| "
                << "+" << std::setw(16) << customer.ContactNumber << "|\n";
   }
   std::cout << "|_______________________________________________________________________________________________________________________|\n\n";
   Ignore();
   Menu();
}

void BookFinder_ID(int BookID) {
   Bookshop bookshop;
   std::ifstream DataFile;
   DataFile.open("BookDataBase.dat");
   bool found = false;
   if (!DataFile) {
      std::cout << "\nFile Error[10011]   : Data File is missing from your System !";
      std::cout << "\nHit 'Enter' to continue ...";
      std::cin.ignore();
      std::cin.get();
   }
   while (DataFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookID() == BookID) {
         bookshop.DisplayAllBooks();
         found = true;
      }
   }
   DataFile.close();
   if (found == false) {
      std::cout << "DataBase Error[10111]   : No such type of Book exists in your database !";
      Ignore();
   }
   if (DataFile.is_open()) {
      DataFile.close();
   }
   Ignore();
   Menu();
}

void BookFinder_Price(int MinPrice, int MaxPrice) {
   Bookshop bookshop;
   std::ifstream DataFile;
   DataFile.open("BookDataBase.dat");
   bool status = false;
   if (!DataFile) {
      std::cout << "\nFile Error : File named as 'BookDataBase.dat' is missing from your system";
      Ignore();
      Menu();
   }
   DataFile.seekg(0, std::ios::beg);
   while (DataFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookPrice() >= MinPrice && bookshop.NextBookPrice() <= MaxPrice) {
         bookshop.DisplayAllBooks();
         status = true;
         std::cout << "\n----------------------------------------------------------------------\n";
      }
      if (DataFile.eof()) {
         Ignore();
         Menu();
      } else {
         continue;
      }
   }
   DataFile.close();
   if (status == false) {
      std::cout << "\n\nNo book is between range of ₹" << MinPrice << " and ₹" << MaxPrice << " .";
      Ignore();
      Menu();
   }
   Ignore();
   Menu();
}
void BookFinder() {
   int Code;
   int BookID;
   int Max, Min;
   std::cout << "\t\t+-------------------- Query Options ---------------------------+\n";
   std::cout << "\t\t|                                                              |\n";
   std::cout << "\t\t|            1.  Find Book Information with Book ID            |\n";
   std::cout << "\t\t|            2.  Find Books between  price range               |\n";
   std::cout << "\t\t|                                                              |\n";
   std::cout << "\t\t+--------------------------------------------------------------+\n";
   std::cout << "\n\n Code@Entry  ~$  ";
   std::cin >> Code;
   switch (Code) {
      case 1:
         system("clear");
         BookDataBase();
         std::cout << "\n\n\t\t\tFIND BOOK USING BOOK ID\n";
         std::cout << "Enter Book ID              ";
         std::cin >> BookID;
         Ignore();
         BookFinder_ID(BookID);
         break;
      case 2:
         system("clear");
         BookDataBase();
         std::cout << "Minimum price of book should be    ";
         std::cin >> Min;
         std::cout << "\nMaximum price of book should be    ";
         std::cin >> Max;
         BookFinder_Price(Min, Max);
         break;
      default:
         std::cout << "\n\nError : Code '" << Code << "' is not a option !";
         Ignore();
         BookFinder();
   }
}

void CustomerFinder(int CustomerID) {
   Customer customer;
   std::ifstream DataFile;
   DataFile.open("CustomerDataBase.dat");
   bool found = true;
   if (!DataFile) {
      std::cout << "\nFile Error[10011]   : Data File is missing from your System !";
      std::cout << "\nHit 'Enter' to continue ...";
      std::cin.ignore();
      std::cin.get();
   }
   while (DataFile.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
      if (customer.NextCustomerID() == CustomerID) {
         customer.DisplayCustomerData();
         Ignore();
         Menu();
         found = false;
      }
   }
   DataFile.close();
   if (found == false) {
      std::cout << "Query Error[10010]  : No such type of customer ID is exists in your database";
      Ignore();
   }
}

void DeleteBook(int BookID) {
   Bookshop bookshop;
   std::ifstream inFile;
   inFile.open("BookDataBase.dat", std::ios::binary);
   if (!inFile) {
      std::cout << "File_Error[1011]    : Data File is missing from your System !";
      Ignore();
      Menu();
      ;
   }
   std::ofstream outFile;
   outFile.open("Temporary.dat", std::ios::out);
   inFile.seekg(0, std::ios::beg);
   while (inFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookID() != BookID) {
         outFile.write(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop));
      }
   }
   std::cout << "Data of Book ID " << BookID << " is deleted succesfully from your DataBase .";
   std::cin.ignore();
   std::cin.get();
   outFile.close();
   inFile.close();
   remove("BookDataBase.dat");
   rename("Temporary.dat", "BookDataBase.dat");
   Ignore();
   Menu();
}

void ModifyBook(int BookID) {
   std::string Confirmation;
   Bookshop bookshop;
   std::ifstream DataFile;
   DataFile.open("BookDataBase.dat");
   bool found = false;
   if (!DataFile) {
      std::cout << "\nFile Error[10011]   : Data File is missing from your System !";
      Ignore();
   }
   while (DataFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookID() == BookID) {
         std::cout << "\tCurrent Information about Book ID '" << BookID << "'\n";
         bookshop.DisplayAllBooks();
         found = true;
      }
   }
   DataFile.close();
   if (found == false) {
      std::cout << "DataBase Error[10111]   : No such type of Book exists in your database !";
      Ignore();
      Menu();
   }

   std::cout << "Are you sure want to modify data of '" << BookID << "'[y/n]: ";
   std::cin >> Confirmation;
   if (Confirmation == "Y" || Confirmation == "y") {
      sleep(2);
      std::ifstream inFile;
      inFile.open("BookDataBase.dat", std::ios::binary);
      if (!inFile) {
         std::cout << "\nFile Error[10011]   : Data File 'BookDataBase.dat' is missing from your System !";
         Ignore();
         Menu();
      }
      std::ofstream outFile;
      outFile.open("Temporary.dat");
      inFile.seekg(0, std::ios::beg);
      while (inFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
         if (bookshop.NextBookID() != BookID) {
            outFile.write(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop));
         }
      }
      inFile.close();
      outFile.close();
      remove("BookDataBase.dat");
      rename("Temporary.dat", "BookDataBase.dat");
      AddBook();
      std::cout << "\nData Updated Successfully of BookID '" << BookID << "'\n";
      Ignore();
      Menu();
   } else {
      std::cout << "\nConfirmation Cancelled ...\n";
      Ignore();
      system("clear");
      Menu();
   }
}

void ModifyCustomerData(int CustomerID) {
   Customer customer;
   Customer_MW customer1;
   std::ifstream in;
   std::ofstream out;
   in.open("CustomerDataBase.dat");
   out.open("temp.bin");
   int BookID, Copies;
   bool found = false;
   std::string Input;
   if (!in) {
      std::cout << "File Error[1001]  : Datafile 'CustomerDataBase.dat' is missing from your system ! ";
      Ignore();
      Menu();
   }
   while (in.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
      if (customer.NextCustomerID() == CustomerID) {
         std::cout << "\n\t\tCurrent Information of Customer";
         std::cout << "\n\tCustomer ID              " << customer.CustomerID;
         std::cout << "\n\tCustomer name            " << customer.CustomerName;
         std::cout << "\n\tContact Number           +" << customer.ContactNumber;
         BookID = customer.BookIDTaken;
         Copies = customer.CopiesTaken;
         std::cout << "\n\n";
         found = true;
      }
   }
   in.close();
   if (found == false) {
      std::cout << "\nQuery Error[111110]  : No such type of Customer ID is esists in your database";
      Ignore();
      Menu();
   }
   std::cout << "Are you sure want to edit information of '" << CustomerID << "' {y/n}   ";
   std::cin >> Input;
   if (Input == "y" || Input == "Y") {
      in.seekg(0, std::ios::beg);
      in.open("CustomerDataBase.dat", std::ios::binary);
      while (in.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
         if (customer.NextCustomerID() != CustomerID) {
            out.write(reinterpret_cast<char*>(&customer), sizeof(Customer));
         }
      }
      in.close();
      out.close();
      remove("CustomerDataBase.dat");
      rename("temp.bin", "CustomerDataBase.dat");
      CustomerDataEntry_ModificationWin(BookID, Copies);
      std::cout << "DONE ";
      Ignore();
      Menu();
   } else {
      std::cout << "Mofification is cancelled by you ...";
      Ignore();
      Menu();
   }
}

void DecreaseCopiesInStore(int CopiesTaken, int BookIDTakingByUser) {
   Bookshop bookshop;
   std::ifstream In;
   In.open("BookDataBase.dat", std::ios::binary);
   std::ofstream Out;
   In.seekg(0, std::ios::beg);
   Out.open("Temporary_BookDataBase.dat", std::ios::binary | std::ios::app);
   while (In.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookID() != BookIDTakingByUser) {
         Out.write(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop));
      }
      if (bookshop.NextBookID() == BookIDTakingByUser) {
         bookshop.NoCopies -= CopiesTaken;
         Out.write(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop));
      }
   }
   In.close();
   Out.close();
   remove("BookDataBase.dat");
   rename("Temporary_BookDataBase.dat", "BookDataBase.dat");
}

bool isBookExistsInBookshop(int BookID) {
   Bookshop bookshop;
   std::ifstream DataFile;
   DataFile.open("BookDataBase.dat", std::ios::binary);
   while (DataFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookID() == BookID) {
         return true;
      }
   }
}

int TotalCopiesInStore(int BookID) {
   Bookshop bookshop;
   std::ifstream DataFile;
   DataFile.open("BookDataBase.dat");
   while (DataFile.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop)))
      ;
   {
      if (bookshop.NextBookID() == BookID) {
         return bookshop.NoCopies;
      }
   }
}

void AddNewCopiesInStore(int NewCopies, int BookID) {
   Bookshop bookshop;
   std::ifstream In;
   In.open("BookDataBase.dat", std::ios::binary);
   std::ofstream Out;
   In.seekg(0, std::ios::beg);
   Out.open("Temporary_BookDataBase.dat", std::ios::binary | std::ios::app);
   while (In.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      if (bookshop.NextBookID() != BookID) {
         Out.write(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop));
      }
      if (bookshop.NextBookID() == BookID) {
         bookshop.NoCopies += NewCopies;
         Out.write(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop));
      }
   }
   In.close();
   Out.close();
   remove("BookDataBase.dat");
   rename("Temporary_BookDataBase.dat", "BookDataBase.dat");
   Ignore();
   Menu();
}

bool IsCustomerIDAvailable(int CustomerID) {
   Customer customer;
   std::ifstream DataFile;
   DataFile.open("CustomerDataBase.dat");
   while (DataFile.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
      if (customer.NextCustomerID() == CustomerID) {
         return false;
      }
   }
}

bool CustomerIDAvailable(int ID) {
   std::ifstream DataFile;
   DataFile.open("CustomerDataBase.dat");
   Customer customer;
   while (DataFile.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
      if (customer.NextCustomerID() == ID) {
         return false;
         break;
      }
   }
}

void CustomerDatabase() {
   std::ifstream DataFile1;
   DataFile1.open("CustomerDataBase.dat", std::ios::binary);
   Customer customer;
   std::cout << "+-----------------------------------------------------------------------------------------------------------------------+\n";
   std::cout << "|                                                  CUSTOMER DATABASE                                                    |\n";
   std::cout << "|_______________________________________________________________________________________________________________________|\n";
   std::cout << "| " << std::left << std::setw(12) << "   ID"
             << "| " << std::setw(40) << std::left << "Customer Name"
             << "| " << std::left << std::setw(40) << "Book Name"
             << "| " << std::left << std::setw(20) << "Contact Number"
             << "|\n";
   std::cout << "+-------------+-----------------------------------------+-----------------------------------------+---------------------+\n";
   while (DataFile1.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
      std::cout << "| " << std::left << std::setw(12) << customer.CustomerID << "| " << std::setw(40) << std::left << customer.CustomerName << "| " << std::left << std::setw(40);
      BooknameByID(customer.BookIDTaken);
      std::cout << "| "
                << "+" << std::setw(19) << customer.ContactNumber << "|\n";
   }
   std::cout << "|_______________________________________________________________________________________________________________________|\n\n";
}

void BookDataBase() {
   Bookshop bookshop;
   std::ifstream f;
   f.open("BookDataBase.dat", std::ios::binary);
   std::cout << "\n\n";
   std::cout << "+-----------------------------------------------------------------------------------------------------------------------+\n";
   std::cout << "|                                                      BOOK  DATABASE                                                   |\n";
   std::cout << "|_______________________________________________________________________________________________________________________|\n";
   std::cout << "| " << std::left << std::setw(11) << "Book ID"
             << "| " << std::left << std::setw(42) << "Book Name"
             << "| " << std::left << std::setw(33) << "Book Author "
             << "| " << std::left << std::setw(12) << "Copies"
             << "| " << std::left << std::setw(12) << "Price"
             << "|\n";
   std::cout << "+------------+-------------------------------------------+----------------------------------+-------------+-------------+\n";
   while (f.read(reinterpret_cast<char*>(&bookshop), sizeof(Bookshop))) {
      std::cout << "| " << std::left << std::setw(10) << bookshop.BookID << " | " << std::setw(42) << std::left << bookshop.BookName << "| " << std::left << std::setw(33) << bookshop.BookAuthor << "| " << std::left << std::setw(12) << bookshop.NoCopies << "|  "
                << "₹" << std::left << std::setw(10) << bookshop.BookPrice << "|\n";
   }
   std::cout << "|_______________________________________________________________________________________________________________________|\n\n";
   f.close();
}

void AddCustomer() {
   system("clear");
   std::ofstream DataFile;
   DataFile.open("CustomerDataBase.dat", std::ios::binary | std::ios::app);
   Customer customer;
   CustomerDatabase();
   BookDataBase();
   customer.GetCustomerData();

   if (isBookExistsInBookshop(customer.BookIDTaken)) {
      if (CustomerIDAvailable(customer.CustomerID) != false) {
         if (TotalCopiesInStore(customer.BookIDTaken) == 0) {
            std::cout << "Copies are not available in your Bookshop";
         } else if (customer.CopiesTaken <= TotalCopiesInStore(customer.BookIDTaken) && TotalCopiesInStore(customer.BookIDTaken) != 0) {
            DecreaseCopiesInStore(customer.CopiesTaken, customer.BookIDTaken);
            DataFile.write(reinterpret_cast<char*>(&customer), sizeof(Customer));
         } else if (customer.CopiesTaken > TotalCopiesInStore(customer.BookIDTaken) && TotalCopiesInStore(customer.BookIDTaken) != 0) {
            std::cout << "Error[1011]  : Customer is demanding more copies than you have in your Bookshop";
         }
         DataFile.close();
         Ignore();
         Menu();
      }
      if (CustomerIDAvailable(customer.CustomerID) == false) {
         std::cout << "ERROR!";
         Ignore();
         Menu();
      }
   }
   if (!isBookExistsInBookshop(customer.BookIDTaken)) {
      std::cout << "Error[101010] :  No such kind of book availble in your Bookshop";
      Ignore();
      Menu();
   }
}

void DeleteCustomerData(int CustomerID) {
   std::ifstream in;
   std::ofstream out;
   in.open("CustomerDataBase.dat");
   out.open("Temp.dat", std::ios::binary | std::ios::app);
   Customer customer;
   if (!in) {
      std::cout << "File Error[10011]   : Data File is missing from your System !";
      Ignore();
      Menu();
   }
   in.seekg(0, std::ios::beg);
   while (in.read(reinterpret_cast<char*>(&customer), sizeof(Customer))) {
      if (customer.NextCustomerID() != CustomerID) {
         out.write(reinterpret_cast<char*>(&customer), sizeof(Customer));
      }
   }
   in.close();
   out.close();
   remove("CustomerDataBase.dat");
   rename("Temp.dat", "CustomerDataBase.dat");
   std::cout << "Database Information[10100]  : Data of Customer ID '" << CustomerID << "' is deleted from your database\n";
   Ignore();
   Menu();
}

void Close() {
   system("clear");
   std::string _EXIT_;
   std::cout << "Are you sure want to exit[y/n]        ";
   std::cin >> _EXIT_;
   if (_EXIT_ == "y" || _EXIT_ == "Y") {
      sleep(3);
      system("clear");
      exit(0);
   } else if (_EXIT_ == "N" || _EXIT_ == "n") {
      std::cout << "Cancelled ....";
      Ignore();
      Close();
   } else {
      std::cout << "Error[1010]  : Not a option ... ";
      Ignore();
      Menu();
   }
}

void InstructionsWindow() {
   std::cout << "\n\t\t\t   INSTRUCTIONS TO USE\n\n\n";
   std::cout << "\t1.  Book ID or Customer ID should be an integer .\n\n"
             << "\t2.  Use format '+91 xxxxx xxxxx' for contact Number .\n\n"
             << "\t3.  Minimum dimension to get better experiance is '645x1106' units .\n\n"
             << "\t4.  You can use diifernt ID of different Books or Customers .\n\n"
             << "\t5.  If the data of a customer or book is edited or deleted by you, then\n"
             << "\t     you cannot restore those deleted data again .\n\n"
             << "\t6.  Write codes (written before every option) to select a option\n\n"
             << "\t7.  Don't remove files named as 'CustomerDataBase.dat' and 'BookDataBase.dat' \n"
             << "\t     else your all data will be removed permanently.\n\n\n"
             << "\nHave a nice day 🙂️ !";
}

void AddShopInformation() {
   std::ofstream DataFile;
   DataFile.open("ShopData.dat", std::ios::binary | std::ios::app);
   Shop shop;
   shop.GetShopDetails();
   std::cout << shop.ShopName << std::endl << shop.Address << std::endl << shop.ContactNumber << std::endl << shop.ShopOwner;
   DataFile.write(reinterpret_cast<char*>(&shop), sizeof(Shop));
   DataFile.close();
}
//------------------------------------------------------------------------------------------------------------------------------------------

//--------------------------------------------------DRIVER CODE------------------------------------------------------------------------------
int main() {
   system("clear");
   InstructionsWindow();
   std::cout << "\n\nHit 'Enter' to continue ...";
   std::cin.get();
   std::ifstream DataFile;
   Shop shop;
   DataFile.open("ShopData.dat", std::ios::binary | std::ios::app);
   if (isFileEmpty(DataFile) || (!DataFile)) {
      system("clear");
      std::cout << "\n\tEnter information of your Bookshop\n";
      AddShopInformation();
      std::cout << "\n\n";
      Ignore();
      DataFile.close();
      Menu();
   }
   if (!isFileEmpty(DataFile)) {
      system("clear");
      DataFile.close();
      Menu();
   }
}
//------------------------------------------------------------------------------------------------------------------------------------------
