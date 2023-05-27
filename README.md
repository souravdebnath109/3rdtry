
#Project Title : Online shopping Management

#Description:

This is a C++ project for an online shopping system. The project allows customers to browse products, add them to a cart, remove products from the cart, view the cart, and checkout. The project also includes an administrator menu for managing products, including adding new products, displaying existing products, and saving the product data to a file.

#Features of oop used in the project:


->Class
->Nested function
->Abstraction
->Encapsulation
->Inheritance
->Polymorphism
->RTTI
->File I/O operation
->Constructor
->Managing Console I/0 Operation
->STL
->Static Variable
->Many more
#Features:

# 1.Customer Menu:

->Display Products: Lists all available products.
->Add to Cart: Allows customers to add products to  their cart.
->Remove from Cart: Allows customers to remove products from their cart.
->View Cart: Displays the products in the customer's cart along with the total amount.
->Checkout: Calculates the total amount and completes the purchase.
->Exit: Exits the customer menu.

# 2.Administrator Menu:

->Add Product: Enables the administrator to add new products to the system.
->Display Products: Shows all existing products.
->Save Products: Saves the product data to a file.
->Exit: Exits the administrator menu.
#File management:
The project uses file handling to load and save product data. The product information is stored in a text file named "products.txt". When the program starts, it loads the product data from the file, and when the administrator chooses to save the products, it writes the product data back to the file.
#Usage
1.Compile the C++ code using a C++ compiler.
2.Run the compiled executable.
3.The program will display the main menu, where you can choose either the Customer or Administrator role
4.For the Customer role, you can browse and interact with the available products, add them to your cart, and complete the purchase.
5.For the Administrator role, you can add new products, display the existing products, and save the product data to a file.
6.You can exit the program by selecting the "Exit" option in either the Customer or Administrator menu.
#Additional notes:
1.The product data is stored in memory while the program is running. If you make changes to the product data during the session, remember to save the changes using the Administrator menu's "Save Products" option to persist the changes for future sessions.
2.The product data is stored as plain text in the "products.txt" file, with each product's ID, name, and price on separate lines.
3.The program handles invalid input and displays appropriate error messages when necessary.
4.The project could be further enhanced by adding additional functionalities such as searching for products, updating product information, and managing customer accounts.
