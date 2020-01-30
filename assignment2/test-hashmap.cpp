//
// Created by 王镱霏 on 1/28/20.
//

#include "HashMap.h"
#include "object.h"
#include "string.h"

void FAIL() { exit(1); }

void OK(const char *m) { std::cout<< m <<std::endl; }

void t_true(bool p) { if (!p) FAIL(); }

void t_false(bool p) { if (p) FAIL(); }

//test
void test1(HashMap *hashmap) {
    String* str = new String("hello");
    String* str2 = new String("hello");
    String* str1 = new String("world");
    hashmap->put(str, str1);

    t_true(hashmap->size() == 1);

    hashmap->remove(str2);

    std::cout<<hashmap->size()<<std::endl;
    t_true(hashmap->size() == 0);

    OK("test1");
}


//test storage
void test2(HashMap *hashmap) {
    String* str = new String("hello");
    String* str1 = new String("world");
//    std::cout<<"here"<<std::endl;
    for(int i =0; i< 100; i++){
//        std::cout<<"current ith round:"<<i<<std::endl;
        hashmap->put(str, str1);
    }
//    std::cout<<"here1"<<std::endl;
    t_true(hashmap->size() == 100);
//    std::cout<<"here"<<std::endl;
    hashmap->remove(str);
    t_true(hashmap->size() == 99);
//    std::cout<<"here"<<std::endl;
    OK("test2");
}
void test3(HashMap *hashmap){
    String *str = new String("hello");
    String *str1 = new String("world");
    String *str2 = new String("hello1");
    String *str3 = new String("world1");

    hashmap->put(str, str1);
    hashmap->put(str2, str3);

    t_true(hashmap->get(str2) == str3);
    t_true(hashmap->get(str) == str1);
    OK("test3");
}
int main() {
    HashMap HashMap;

    test1(&HashMap);
    test2(&HashMap);
    test3(&HashMap);
}