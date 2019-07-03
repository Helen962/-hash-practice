

#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <functional>
#include <string>



class HashMap
{
public:
   
    using HashFunction = std::function<unsigned int(const std::string&)>;
    static constexpr unsigned int initialBucketCount = 10;


public:

    HashMap();


    HashMap(HashFunction hasher);


    HashMap(const HashMap& hm);
    ~HashMap();
    HashMap& operator=(const HashMap& hm);

    void add(const std::string& key, const std::string& value);

  
    void remove(const std::string& key);

    bool contains(const std::string& key) const;

   
    std::string value(const std::string& key) const;

    unsigned int size() const;

    unsigned int bucketCount() const;
    double loadFactor() const;

    unsigned int maxBucketSize() const;

  

private:
  
    struct Node
    {
        std::string key;
        std::string value;
        Node* next;
    };

 
    HashFunction hasher;
    //------------------------------------------------------------------------------------------------------------
      void arrayCopy(Node **target, Node **source, unsigned int buckCount) const; // function to copy the whole buckets
      void rehash(const std::string& key, const std::string& value, unsigned int bucount); //function to do the rehash
       //void initializeBucketWIthNullptr(unsigned int buckNum);
       void deleteAll(Node **aim,unsigned int bco); //delete the whole entire buckets
       void initializeArray();  // initializa each bucket to nullptr
    Node **item;  //name of the whole buckte
    unsigned int sz; //the number of key/value pairs 
    unsigned int bucketFill; //bucketFill is the number of buckets that is filled;
    unsigned int bcount; //the total number of buckets
   
};



#endif 

