#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Product {
    int id;
    string name;
    float price;

public:
    Product(int id, const string& name, float price)
        : id(id), name(name), price(price) {}

    int getId() const {
        return id;
    }

    string getName() const {
        return name;
    }

    float getPrice() const {
        return price;
    }

    friend ostream& operator<<(ostream& os, const Product& product) {
        os << "Product ID: " << product.id << endl;
        os << "Name: " << product.name << endl;
        os << "Price: " << product.price << endl;
        return os;
    }
};
class Book : public Product {
    string author;
    int pages;

public:
    Book(int id, const string& name, float price, const string& author, int pages)
        : Product(id, name, price), author(author), pages(pages) {}

    string getAuthor() const {
        return author;
    }

    int getPages() const {
        return pages;
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << static_cast<const Product&>(book);
        os << "Author: " << book.author << endl;
        os << "Pages: " << book.pages << endl;
        return os;
    }
};
class DiscountedProduct : public Product {
    float discount;

public:
    DiscountedProduct(int id, const string& name, float price, float discount)
        : Product(id, name, price), discount(discount) {}

    float getDiscount() const {
        return discount;
    }
    friend ostream& operator<<(ostream& os, const DiscountedProduct& product) {
        os << static_cast<const Product&>(product);
        os << "Discount: " << product.discount << endl;
        return os;
    }
};



class OnlineShopping {
    string fileName;
    vector<Product> products;

public:
    OnlineShopping(const string& fileName)
        : fileName(fileName) {}

    void loadProducts() {
        ifstream file(fileName);
        if (file.is_open()) {
            int id;
            string name;
            float price;

            while (file >> id) {
                file.ignore();
                getline(file, name);
                file >> price;
                file.ignore();

                Product product(id, name, price);
                products.push_back(product);
            }

            file.close();
        } else {
            cout << "Unable to open the file." << endl;
        }
    }

    void saveProducts() {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const auto& product : products) {
                file << product.getId() << endl;
                file << product.getName() << endl;
                file << product.getPrice() << endl;
            }

            file.close();
            cout << "Products saved successfully!" << endl;
        } else {
            cout << "Unable to open the file." << endl;
        }
    }

    void addProduct() {
        int id;
        string name;
        float price;

        cout << "Enter product ID: ";
        cin >> id;
        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter product price: ";
        cin >> price;

        Product product(id, name, price);
        products.push_back(product);

        cout << "Product added successfully!" << endl;
    }

    void displayProducts() {
        for (const auto& product : products) {
            cout << product << endl;
        }
    }

    Product* findProductById(int id) {
        for (auto& product : products) {
            if (product.getId() == id) {
                return &product;
            }
        }
        return nullptr;
    }
};

class Customer {
public:
    void menu(OnlineShopping& shopping) {
        int choice;
        vector<Product*> cart;
        float totalAmount = 0.0;

        do {
            cout << "===== Customer Menu =====" << endl;
            cout << "1. Display Products" << endl;
            cout << "2. Add to Cart" << endl;
            cout << "3. Remove from Cart" << endl;
            cout << "4. View Cart" << endl;
            cout << "5. Checkout" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    shopping.displayProducts();
                    break;
                case 2: {
                    int productId;
                    cout << "Enter product ID to add to cart: ";
                    cin >> productId;

                                        Product* product = shopping.findProductById(productId);
                    if (product != nullptr) {
                        cart.push_back(product);
                        totalAmount += product->getPrice();
                        cout << "Product added to cart successfully!" << endl;
                    } else {
                        cout << "Product not found!" << endl;
                    }
                    break;
                }
                case 3: {
                    int productId;
                    cout << "Enter product ID to remove from cart: ";
                    cin >> productId;

                    for (auto it = cart.begin(); it != cart.end(); ++it) {
                        if ((*it)->getId() == productId) {
                            totalAmount -= (*it)->getPrice();
                            cart.erase(it);
                            cout << "Product removed from cart successfully!" << endl;
                            break;
                        }
                    }
                    break;
                }
                case 4:
                    cout << "===== Cart =====" << endl;
                    if (!cart.empty()) {
                        for (const auto& product : cart) {
                            cout << *product << endl;
                        }
                        cout << "Total Amount: " << totalAmount << endl;
                    } else {
                        cout << "Cart is empty!" << endl;
                    }
                    break;
                case 5:
                    cout << "===== Checkout =====" << endl;
                    cout << "Total Amount: " << totalAmount << endl;
                    cout << "Thank you for shopping with us!" << endl;
                    cart.clear();
                    totalAmount = 0.0;
                    break;
                case 6:
                    cout << "Exiting customer menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 6);
    }
};

class Administrator {
public:
    void menu(OnlineShopping& shopping) {
        int choice;

        do {
            cout << "===== Administrator Menu =====" << endl;
            cout << "1. Add Product" << endl;
            cout << "2. Display Products" << endl;
            cout << "3. Save Products" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    shopping.addProduct();
                    break;
                case 2:
                    shopping.displayProducts();
                    break;
                case 3:
                    shopping.saveProducts();
                    break;
                case 4:
                    cout << "Exiting administrator menu..." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    break;
            }
        } while (choice != 4);
    }
};

int main() {
    OnlineShopping shopping("products.txt");
    shopping.loadProducts();

    Customer customer;
    Administrator administrator;

    int roleChoice;
    do {
        cout << "===== Online Shopping =====" << endl;
        cout << "1. Customer" << endl;
        cout << "2. Administrator" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> roleChoice;

        switch (roleChoice) {
            case 1:
                customer.menu(shopping);
                break;
            case 2:
                administrator.menu(shopping);
                break;
            case 3:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (roleChoice != 3);

    return 0;
}


