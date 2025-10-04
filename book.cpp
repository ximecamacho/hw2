#include "book.h"

Book :: Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn) : Product (category, name, price, qty){
    isbn_ = isbn;
    author_ = author;

}

std::set<std::string> Book:: keywords() const{
    std::set<std::string> setKeywords = parseStringToWords(author_);
    std::set<std::string> nameKeywords = parseStringToWords(getName());
    setKeywords.insert(isbn_);

    for (typename std::set<std::string>::iterator it=nameKeywords.begin(); it != nameKeywords.end(); ++it){
        setKeywords.insert(*it);
    }

    return setKeywords;

}


std::string Book::displayString() const{
    std::string toDisplay=getName()+"\n"+"Author: "+ author_+" ISBN: "+isbn_+"\n"+std::to_string(getPrice())+" "+ std::to_string(getQty())+ " left.";
    return toDisplay;
}

void Book::dump(std::ostream& os) const{
    os << category_ << "\n" << getName() << "\n" << getPrice() << "\n" << getQty() << "\n" << isbn_ << "\n" << author_ << std::endl;
}