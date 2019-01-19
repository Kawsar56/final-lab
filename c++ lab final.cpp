#include <bits/stdc++.h>
using namespace std;

class Person
{
    string name,birthday;
    public:
    Person(){};
    Person(string name,string birthday)
    {
        this->name=name;
        this->birthday=birthday;
    }
    void View_Person()
    {
        cout<<"Name : "<<this->name<<endl;
        cout<<"Birthday : "<<this->birthday<<endl;
    }

};

class CustomerCategory
{
   string category;
   public:
       CustomerCategory(){};
       CustomerCategory(string category)
       {
           this->category=category;
       }
       void View_Customer_Category()
       {
         cout<<"Category : "<<this->category<<endl;
       }
};

class Customer : public Person
{
    int customer_id;
    CustomerCategory customer_category;
public:
    Customer(){};
    Customer(string name, string birthday, int customer_id,CustomerCategory customer_category) : Person(name,birthday)
    {
        this->customer_id=customer_id;
        this->customer_category=customer_category;
    }
    void View_Customer()
    {
        View_Person();
        cout<<"Customer ID : "<<this->customer_id<<endl;
    }
};

class ProductCategory
{
   string category;
   public:
       ProductCategory(){};
       ProductCategory(string category)
       {
           this->category=category;
       }
       void View_Product_Category()
       {
           cout<<"Product Category : "<<this->category<<endl;
       }
};

class Product
{
    string product_name;
    double price;
    int quantity;
    ProductCategory product_category;
   public:
    Product(){};
    Product(string product_name,double price, int quantity,ProductCategory product_category)
    {
        this->product_name=product_name;
        this->price=price;
        this->quantity=quantity;
        this->product_category=product_category;
    }
    void View_Product()
    {
        cout<<"Product Name : "<<this->product_name<<endl;
        product_category.View_Product_Category();
        cout<<"Product Quantity : "<<this->quantity<<endl;
        cout<<"Product Price : "<<this->price<<endl;
    }
};

int main()
{
    CustomerCategory *customer_category[3]={
                                           new CustomerCategory("male"),
                                           new CustomerCategory("female"),
                                           new CustomerCategory("child")
                                           };
    Customer *customer[3]={
                                           new Customer("Mou","21-03-1996",11001,*customer_category[0]),
                                           new Customer("Khadiza","11-12-1995",11034,*customer_category[1]),
                                           new Customer("piu","01-09-2000",11056,*customer_category[2])
                                           };

    ProductCategory *product_category[3]={
                                           new ProductCategory("Garment"),
                                           new ProductCategory("Stationary"),
                                           new ProductCategory("Cosmetics")
                                         };
   Product *products[3]={
                                           new Product("Shirts",1250.00,10,*product_category[0]),
                                           new Product("Pencils",12.00,100,*product_category[1]),
                                           new Product("Lipstick",125.00,35,*product_category[2]),
                                        };
   int buying_frequency[3]={6,10,2};

   /// View Products ///
   cout<<"******Available Products*******"<<endl;
   for(int i=0;i<3;i++)
   {
       products[i]->View_Product();
       cout<<endl;
   }
   for(int i=0;i<3;i++)
   {
      if(buying_frequency[i]>=5 && buying_frequency[i]<=7)
      {
          cout<<"+_+_+_+_+_+    GREAT NEWS!  YOU HAVE EARNED 35% DISCOUNT ON YOUR PURCHASE     +_+_+_+_+_+"<<endl;
          cout<<endl<<"Eligible Customer Information: "<<endl;
          customer[i]->View_Customer();
          cout<<endl;
      }
      else if(buying_frequency[i]>7)
      {
          cout<<"+_+_+_+_+_+    GREAT NEWS!  YOU HAVE EARNED 65% DISCOUNT ON YOUR PURCHASE     +_+_+_+_+_+"<<endl;
          cout<<endl<<"Eligible Customer Information: "<<endl;
          customer[i]->View_Customer();
          cout<<endl;
      }
      else
      {
          cout<<"Keep Buying Products! Discount is on the way."<<endl;
          cout<<endl<<"Customer Information: "<<endl;
          customer[i]->View_Customer();
          cout<<endl;

      }
   }
}

