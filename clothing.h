#include "product.h"
#include "util.h"

class Clothing : public Product{
    public:
    Clothing(const std::string category, const std::string name, double price, int qty, std::string brand, std::string size);
    std::set<std::string> keywords() const;
    std::string displayString() const;
    void dump(std::ostream& os) const;

    std::string brand_;
    std::string size_;
};