#include "product.h"
#include "util.h"

class Book : public Product{
    public:
    Book(const std::string category, const std::string name, double price, int qty, std::string author, std::string isbn);
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    std::string isbn_;
    std::string author_;

};

