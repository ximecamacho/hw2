#include "mydatastore.h"
#include "util.h"


void MyDataStore::addProduct(Product* p){
    prods_.insert(p);
     std::set<std::string> totalKeywordsTemp=p->keywords();

    for(std::set<std::string>::iterator it= totalKeywordsTemp.begin(); it != totalKeywordsTemp.end(); ++it){
       totalKeywords.insert(*it);
    }


}

void MyDataStore::addUser(User* u){
    std::set<Product*> temp;
    user_.insert(std::make_pair(u,temp));

}

std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
    std::vector<Product*> hitsToReturn;
    /*std::set<std::string> termsSet;
    for(std::vector<std::string>::iterator it= terms.begin(); it != terms.end(); ++it){
       termsSet.insert(*it);
    }
    std::set<std::string> hitsSet;
   //OR
    if (type == 1){
        hitsSet=setUnion(termsSet, totalKeywords);
    }
    //and
    else if (type == 0){
        hitsSet=setIntersection(termsSet, totalKeywords);

    }
    for(std::set<std::string>::iterator it2= hitsSet.begin(); it2 != hitsSet.end(); ++it2){
       hitsToReturn.push_back(prods_.find(*it2));
    }*/
   
    return hitsToReturn;

}

void MyDataStore::dump(std::ostream& ofile){
    ofile<< "<products>"<<std::endl;
    for(std::set<Product*>::iterator it= prods_.begin(); it != prods_.end(); ++it){
       (*it)->dump(ofile);
    }
    for(std::set<Product*>::iterator it= prods_.begin(); it != prods_.end(); ++it){
       delete *it;
    }
    ofile<< "</products>"<<std::endl;
    ofile<< "<users>"<<std::endl;
    for(std::map< User* , std::set<Product*> >::iterator it= user_.begin(); it != user_.end(); ++it){
        (it->first)->dump(ofile);
    }
    for(std::map< User* , std::set<Product*> >::iterator it= user_.begin(); it != user_.end(); ++it){
        delete it->first;
        
        
    }
    
    ofile<< "</users>"<<std::endl;


}