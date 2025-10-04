#include "mydatastore.h"


void MyDataStore::addProduct(Product* p){
    prods_.insert(p);

}

void MyDataStore::addUser(User* u){
    std::set<Product*> temp;
    user_.insert(std::make_pair(u,temp));

}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::vector<Product*> hitsToReturn;
    return hitsToReturn;

}

void MyDataStore::dump(std::ostream& ofile){
    ofile<< "<products>"<<std::endl;
    for(std::set<Product*>::iterator it= prods_.begin(); it != prods_.end(); ++it){
        (*it)->dump(ofile);
    }
    ofile<< "</products>"<<std::endl;
    ofile<< "<users>"<<std::endl;
    for(std::map< User* , std::set<Product*> >::iterator it= user_.begin(); it != user_.end(); ++it){
        (it->first)->dump(ofile);
    }
    ofile<< "<users/>"<<std::endl;


}