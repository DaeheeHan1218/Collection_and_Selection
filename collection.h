#ifndef COLLECTION_H
#define COLLECTION_H
#include <cstddef>
#include <iostream>

using namespace std;

template <typename Object>
class Collection {
  private:
    size_t length;
    Object* link;
  public:
    Collection (): length(0), link(new Object[0]){}
    Collection(const Collection& cpyCol);
    ~Collection(){
        length = 0;
        delete [] link;
        link = nullptr;
    }
    Collection& operator=(const Collection&);
    size_t size() const{
        return length;
    }
    bool is_empty() const{
        if(length == 0){
            return true;
        }
        else{
            return false;
        }
    }
    void make_empty(){
        delete [] link;
        link = nullptr;
        length = 0;
    }
    void insert(const Object& obj);
    void remove(const Object& obj);
    bool contains(const Object& obj) const{
        bool exists = false;
        for(size_t i = 0; i < length; i+= 1){
            if(link[i] == obj){
                exists = true;
                break;
            }
        }
        return exists;
    }
};

template <typename Object>
Collection<Object>::Collection(const Collection<Object>& cpyCol): length(cpyCol.length), link(new Object[cpyCol.length]){
    for(size_t i = 0; i < length; i += 1){
        link[i] = cpyCol.link[i];
    }
}

template <typename Object>
Collection<Object>& Collection<Object>::operator=(const Collection& cpyCol){
    if(this != &cpyCol){
        length = cpyCol.length;
        Object* newLink = new Object[length];
        for(size_t i = 0; i < length; i+= 1){
            newLink[i] = cpyCol.link[i];
        }
        delete [] link;
        link = newLink;
    }
    return *this;
}

template <typename Object>
void Collection<Object>::insert(const Object& obj){
    if(length != 0){
        length += 1;
        Object* newLink = new Object[length];
        for(size_t i = 0; i < length - 1; i += 1){
            newLink[i] = link[i];
        }
        newLink[length - 1] = obj;
        delete [] link;
        link = newLink;
    }
    else{
        length = 1;
        Object* newLink = new Object[length];
        newLink[0] = obj;
        delete [] link;
        link = newLink;
    }
}

template <typename Object>
void Collection<Object>::remove(const Object& obj){
    if(length > 0){
        size_t index = 0;
        for(size_t i = 0; i < length; i+= 1){
            if(link[i] == obj){
                index = i;
                break;
            }
        }
        Object* newLink = new Object[length - 1];
        for(size_t i = 0; i < length; i += 1){
            if(i < index){
                newLink[i] = link[i];
            }
            else if(i > index){
                newLink[i - 1] = link[i];
            }
        }
        length -= 1;
        delete [] link;
        link = newLink;
    }
}
#endif  // COLLECTION_H