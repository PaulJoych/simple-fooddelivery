#include <iostream>
#include <fstream>
using namespace std;

class FoodDelivery {
  public:
    string name;
    float total;
    float foodCost;
    float diliveryCost;
    float distance;
    float discont;

  void diliveryDistace() {
    if (distance < 3) {
      diliveryCost = 15000;
    } else {
      diliveryCost = 25000;
    }
  };

  void pickFood(float foodType) {
    foodCost += foodType;
  };

  float totalCost() {
    float a, b;
    if (foodCost > 150000) {
      a = diliveryCost - 8000;
      b = foodCost - (foodCost * 0.35);
    } else if (foodCost > 50000 & foodCost < 150000) {
      a = diliveryCost - 5000;
      b = foodCost - (foodCost * 0.15);
    } else if (foodCost > 25000 & foodCost < 50000) {
      a = diliveryCost - 3000;
    };

    return a + b;
  }

  char discountType() {
    char a;
    if (foodCost > 150000) {
      a = 1;
    } else if (foodCost > 50000 & foodCost < 150000) {
      a = 2;
    } else if (foodCost > 25000 & foodCost < 50000) {
      a = 3;
    };

    return a;
  }
};



int main() {
  FoodDelivery fd;
  cout << "==================================\n";
  cout << "Masukan nama anda : \n";
  cout << "==================================\n";
  cin >> fd.name;


  cout << "==================================\n";
  cout << "Masukan jarak anda : \n";
  cout << "==================================\n";
  cin  >> fd.distance;
  fd.diliveryDistace();

  pesan:
  int menuInput = 0;
  float h;
  cout << "==================================\n";
  cout << "1. Ayam Geprek  : 21000\n" << endl;
  cout << "2. Ayam Goreng  : 17000\n" << endl;
  cout << "3. Udang Goreng : 19000\n" << endl;
  cout << "4. Cumi Goreng  : 20000\n" << endl;
  cout << "5. Ayam Bakar   : 25000\n" << endl;
  cout << "6. Selesai\n" << endl;
  cout << "Pilih menu : \n";
  cout << "==================================\n";
  cin >> menuInput;

  switch(menuInput) {
    case 1:
      h = 21000;
      break;
    case 2:
      h = 17000;
      break;
    case 3:
      h = 19000;
      break;
    case 4:
      h = 19000;
      break;
    case 5:
      h = 25000;
      break;
  }
  if (menuInput != 6){
    fd.pickFood(h);
    goto pesan;
  }

  cout << "==================================\n";
  cout  <<"\nStruk Belanja\n";
  cout  <<"Nama Pelanggan            : " << fd.name << "\n";
  cout  <<"Harga Makanan             : " << fd.foodCost << "\n";
  cout  <<"Ongkir                    : " << fd.diliveryCost << "\n";
  cout << "==================================\n";
  switch (fd.discountType()) {
    case 1:
      cout << "Mendapatkan diskon        : -Rp.8.000 pada ongkir\n";
      cout << "Mendapatkan diskon        : 35% pada makanan\n";
      break;
    case 2:
      cout << "Mendapatkan diskon        : -Rp.5.000 pada ongkir\n";
      cout << "Mendapatkan diskon        : 15% pada makanan\n";
      break;
    case 3:
      cout << "Mendapatkan diskon        : -Rp.3.000 pada ongkir\n";
      cout << "Mendapatkan diskon        : 15% pada makanan\n";
      break;
  }
  cout << "==================================\n";
  cout  << "Total                   : " << fd.totalCost() << "\n";

  ofstream txt("struk.txt");
  txt << "==================================\n";
  txt << "\nStruk Belanja\n";
  txt << "Nama Pelanggan            : " << fd.name << "\n";
  txt << "Harga Makanan             : " << fd.foodCost << "\n";
  txt << "Ongkir                    : " << fd.diliveryCost << "\n";
  txt << "==================================\n";
  switch (fd.discountType()) {
    case 1:
      txt << "Mendapatkan diskon        : -Rp.8.000 pada ongkir\n";
      txt << "Mendapatkan diskon        : 35% pada makanan\n";
      break;
    case 2:
      txt << "Mendapatkan diskon        : -Rp.5.000 pada ongkir\n";
      txt << "Mendapatkan diskon        : 15% pada makanan\n";
      break;
    case 3:
      txt << "Mendapatkan diskon        : -Rp.3.000 pada ongkir\n";
      txt << "Mendapatkan diskon        : 15% pada makanan\n";
      break;
  }
  txt << "==================================\n";
  txt << "Total                     : " << fd.totalCost() << "\n";
  txt.close();
}
