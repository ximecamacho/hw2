#include "movie.h"

Movie:: Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) : Product(category, name, price, qty){
    rating_=rating;
    genre_=genre;

}

std::set<std::string> Movie::keywords() const{
    std::set<std::string> setKeywords = parseStringToWords(genre_);
    std::set<std::string> nameKeywords = parseStringToWords(getName());
    
    for (typename std::set<std::string>::iterator it=nameKeywords.begin(); it != nameKeywords.end(); ++it){
        setKeywords.insert(*it);
    }

    return setKeywords;

}

std::string Movie::displayString() const{
    std::string toDisplay = getName() + "\n" + "Genre: " +genre_+ " Rating: "+rating_+"\n"+std::to_string(getPrice())+" "+ std::to_string(getQty())+ " left.";
    return toDisplay;

}

void Movie::dump(std::ostream& os) const{
    os << category_ << "\n" << getName() << "\n" << getPrice() << "\n" << getQty()<< "\n" << genre_ << "\n" << rating_ << std::endl;

}