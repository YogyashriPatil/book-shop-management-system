The Bookshop Management System is designed to manage a bookshop's operations, including managing books and customer transactions. This system uses C++ and encapsulates various functionalities within different classes and functions.
1.Class Definitions
   - Shop: This class captures details about the bookshop such as name, owner, contact number, address, and email.
   - Bookshop: This class manages book-related information like book ID, name, author, number of copies, and price. It includes methods to get book data and display all books.
   - Customer: This class handles customer-related information such as customer ID, name, contact number, book ID taken, and number of copies taken. It includes methods to get and display customer data.
   - Customer_MW: This is a modification window class for managing customer information.

2.Function Definitions:
   - Functions to manage book operations: `AddBook`, `DeleteBook`, `BookFinder`, `ModifyBook`, `DisplayAllBooks`.
   - Functions to manage customer operations: `AddCustomer`, `DeleteCustomerData`, `CustomerFinder`, `ModifyCustomerData`, `DisplayAllCustomersInDataBase`, `Profile`.
   - Basic utility functions: `BooksAvailableInBookshop`, `TotalCopiesInStore`, `Menu`, `Ignore`, `CustomerDatabase`, `BookDataBase`, `isBookExistsInBookshop`, `CustomerIDAvailable`, `DecreaseCopiesInStore`, `BookNameByID`, `AddNewCopiesInStore`, `BookExistsInBookshop`, `Close`, `InstructionsWindow`, `BookFinder_ID`, `BookFinder_Price`, `Head`, `AddShopInformation`, `isFileEmpty`.

3.Menu Function
   - The `Menu` function presents a list of options to the user, allowing them to select different operations such as selling a book, deleting a customer, editing customer information, adding new books, displaying all books, searching for a book, deleting a book, modifying book data, adding more copies to a book, and viewing the bookshop profile.
   - This function is the main control center of the application, directing the flow based on user input.

4.I/O Operations
   - Uses file streams to read and write data, particularly for storing shop details and customer information in binary format.
   - `std::ifstream` is used to open and read files.
