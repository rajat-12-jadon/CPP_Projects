#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class groceryItem
{
private:
    string name;
    float price;
    int quantity;

public:
    groceryItem(string name, float price, int quantity)
    {
        this->name = name;
        this->price = price;
        this->quantity = quantity;
    }

    string getName() { return name; }
    float getPrice() { return price; }
    int getQuantity() { return quantity; }

    float getTotalPrice()
    {
        return price * quantity;
    }
};

class shoppingCart
{
    vector<groceryItem> cartItems;

public:
    void addItemtoCart(const groceryItem &item)
    {
        cartItems.push_back(item);
    }

    void displayBill()
    {
        cout << "--------------------------------------------\n";
        cout << "                  Grocery Store\n";
        cout << "--------------------------------------------\n";
        cout << setw(20) << left << "Item" << setw(10) << "Qty" << setw(10) << "Price" << setw(15) << "Total Price\n";
        cout << "--------------------------------------------\n";

        float totalAmount = 0.0;
        for (int i = 0; i < cartItems.size(); i++)
        {
            cout << setw(20) << left << cartItems[i].getName()
                 << setw(10) << cartItems[i].getQuantity()
                 << setw(10) << fixed << setprecision(2) << cartItems[i].getPrice()
                 << setw(15) << fixed << setprecision(2) << cartItems[i].getTotalPrice() << endl;
            totalAmount += cartItems[i].getTotalPrice();
        }

        cout << "--------------------------------------------\n";

        float gst = totalAmount * 0.09;
        float cgst = totalAmount * 0.09;
        float grandTotal = totalAmount + gst + cgst;

        cout << setw(40) << left << "Total amount: " << "Rs. " << fixed << setprecision(2) << totalAmount << endl;
        cout << setw(40) << left << "GST (9%): " << "Rs. " << fixed << setprecision(2) << gst << endl;
        cout << setw(40) << left << "CGST (9%): " << "Rs. " << fixed << setprecision(2) << cgst << endl;

        cout << setw(40) << left << "Grand Total: " << "Rs. " << fixed << setprecision(2) << grandTotal << endl;

        cout << "--------------------------------------------\n";
    }
};

class groceryStore
{
private:
    vector<groceryItem> inventory;

public:
    void addItemToStore(const groceryItem &item)
    {
        inventory.push_back(item);
    }

    void displayStore()
    {
        cout << "Available Items in Store:\n";

        for (int i = 0; i < inventory.size(); i++)
        {
            cout << "Item: " << inventory[i].getName() << " | Price: Rs. " << fixed << setprecision(2) << inventory[i].getPrice() << " | Quantity: " << inventory[i].getQuantity() << endl;
        }
    }

    groceryItem *getItemByName(const string &name)
    {
        for (int i = 0; i < inventory.size(); i++)
        {
            if (inventory[i].getName() == name)
            {
                return &inventory[i];
            }
        }
        return nullptr;
    }
};

int main()
{
    groceryStore store;

    store.addItemToStore(groceryItem("Apple", 5.20, 50));
    store.addItemToStore(groceryItem("Mango", 3.20, 50));
    store.addItemToStore(groceryItem("Guava", 1.20, 50));
    store.addItemToStore(groceryItem("Rice", 4.00, 50));
    store.addItemToStore(groceryItem("Wheat", 5.20, 50));
    store.addItemToStore(groceryItem("Potato", 3.50, 50));
    store.addItemToStore(groceryItem("Tomato", 6.00, 50));
    store.addItemToStore(groceryItem("Legumes", 0.50, 50));
    store.addItemToStore(groceryItem("Milk", 1.50, 30));
    store.addItemToStore(groceryItem("Bread", 2.00, 20));
    store.addItemToStore(groceryItem("Eggs", 2.50, 40));

    store.displayStore();

    shoppingCart cart;

    groceryItem *apple = store.getItemByName("Apple");

    if (apple != nullptr)
    {
        cart.addItemtoCart(*apple);
    }

    groceryItem *milk = store.getItemByName("Milk");

    if (milk != nullptr)
    {
        cart.addItemtoCart(*milk);
    }

    groceryItem *rice = store.getItemByName("Rice");

    if (rice != nullptr)
    {
        cart.addItemtoCart(*rice);
    }

    cart.displayBill();

    return 0;
}