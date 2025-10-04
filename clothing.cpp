#include "clothing.h"

Clothing:: Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size) : Product(category, name, price, qty){
    brand_ = brand;
    size_ = size;
}

std::set<std::string> Clothing::keywords() const{
    std::set<std::string> setKeywords = parseStringToWords(brand_);
    std::set<std::string> nameKeywords = parseStringToWords(getName());
    
    for (typename std::set<std::string>::iterator it=nameKeywords.begin(); it != nameKeywords.end(); ++it){
        setKeywords.insert(*it);
    }

    return setKeywords;

}

std::string Clothing::displayString() const{
    std::string toDisplay = getName() + "\n" + "Size: " +size_+ " Brand: "+brand_+"\n"+std::to_string(getPrice())+" "+ std::to_string(getQty())+ " left.";
    return toDisplay;
}

void Clothing::dump(std::ostream& os) const{
    os << category_ << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << size_ << "\n" << brand_ << std::endl;

}