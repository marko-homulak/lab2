#include <iostream>
#include <iomanip>
#include <string>
#include "windows.h"
#include <vector>

using namespace std;

class Ingredient
{
private:
	string ingredientName;
	double dosage;
	double price;
public:

	Ingredient(string ingredientName, double dosage, double price) {
		this->ingredientName = ingredientName;
		this->dosage = dosage;
		this->price = price;
	}

	static Ingredient buildIngredient() {
		cout << "Enter ingredient name: ";
		string ingredientName = string();
		getline(cin, ingredientName);
		cout << "Enter ingredient dosage: ";
		string productDosage = string();
		getline(cin, productDosage);
		cout << "Enter ingredient price: ";
		string productPrice = string();
		getline(cin, productPrice);
		cout << endl;
		return Ingredient(ingredientName, stod(productDosage), stod(productPrice));
	}

	double getTotalPrice() {
		return price * dosage;
	}

};

class Receipt
{
private:
	string productName;
	vector<Ingredient> ingredients;
public:

	Receipt(string productName)
	{
		ingredients = vector<Ingredient>();
		this->productName = productName;
	}

	static Receipt buildReceipt() {
		cout << "Enter ingredient name: ";
		string productName = string();
		getline(cin, productName);
		cout << endl;
		return Receipt(productName);
	}

	void fillIngredients(int numberOfIngredients) {
		for (int i = 0; i < numberOfIngredients; i++) {
			ingredients.push_back(Ingredient::buildIngredient());
		}
	}

	double getPrice() {
		double receiptPrice = 0;
		for (Ingredient ingredient : ingredients) {
			receiptPrice += ingredient.getTotalPrice();
		}
		return receiptPrice;
	}

};


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "Enter product name: ";
	string productName;
	getline(cin, productName);

	Receipt receipt = Receipt(productName);
	string size;
	cout << "Enter number of ingredients in product: ";
	getline(cin, size);
	receipt.fillIngredients(stoi(size));
	cout << "Total receipt price: " << receipt.getPrice() << endl;

	return 0;
}
