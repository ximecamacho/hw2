#include "datastore.h"
#include <map>

class MyDataStore : public DataStore {
    public: 
    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);

    std::map< User* , std::set<Product*> > user_;
    std::set<Product*> prods_;
    std::set<std::string> totalKeywords;



};