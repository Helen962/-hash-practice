

#include "HashMap1.hpp"
#include <iostream>


namespace
{
    // hash function to calculate the hashvalue
unsigned int HashFunction1(const std::string& key)
{
  
    unsigned int hashVal = 0;
    unsigned int c = 0;
    while (c<key.length())
    {
        hashVal = (hashVal << 5) + (hashVal >> 3) + key[c];
        ++c;
        }
        return hashVal;
    }
}

// delete the all the buckets, include all the node pointers
void HashMap::deleteAll(Node **aim,unsigned int bco)
    {
        for (unsigned int x = 0; x < bco; ++x)
        {
            Node *head;
            head = aim[x];
            if (head != nullptr)
            {
              
                while (head->next != nullptr)
                {
                    Node*inteNode = head;
                    head = head->next;
                    delete inteNode;
                    
                }

               

                delete aim[x];
            }
        }
    }






// function to copy an array
  void HashMap::arrayCopy(Node **target, Node **source, unsigned int buckCount) const
    {
        unsigned int buckCt;
        buckCt = buckCount;
         for (unsigned int j3= 0; j3 < bcount; j3++)
            {
                target[j3] = nullptr;
            } 
        for (unsigned int i = 0; i < buckCt; i++)
        {
            Node *currentPot = source[i];
            while (currentPot != nullptr)
            {            

                Node *targetPot = new Node;
                Node *temp;
                targetPot->key = currentPot->key;
                targetPot->value = currentPot->value;
                temp = target[i];
                target[i]=targetPot;
                targetPot->next = temp;
                currentPot=currentPot->next;
            }
        }
    }





HashMap::HashMap()
    : hasher{HashFunction1},item{new Node*[HashMap::initialBucketCount]},sz{0},bucketFill{0},bcount{HashMap::initialBucketCount}
{
     initializeArray();
}
HashMap::HashMap(HashFunction hasher)
    : hasher{hasher},item{new Node*[HashMap::initialBucketCount]},sz{0},bucketFill{0},bcount{HashMap::initialBucketCount}
{
     initializeArray();
}


HashMap::HashMap(const HashMap& hm)
    : hasher{hm.hasher},item{new Node*[hm.bcount]},sz{hm.sz},bucketFill{hm.bucketFill},bcount{hm.bcount}
{
    arrayCopy(item,hm.item, hm.bcount);
}


HashMap::~HashMap()
{


    deleteAll(item,bcount);

    delete[] item;

}



HashMap& HashMap::operator=(const HashMap& hm)
{
    if (this != &hm)
    {
        Node**newItems = new Node*[hm.bcount];
        arrayCopy(newItems, hm.item, hm.bcount);
        hasher = hm.hasher;
        sz = hm.sz;
        bcount = hm.bcount;
        bucketFill = hm.bucketFill;
        delete[] item;
        item = newItems;
    }
    return *this;
}





// initialize all the buckets with nullptr
void HashMap::initializeArray()
{
    for (unsigned int z = 0; z < bcount; z++)
     {
       item[z] = nullptr;
     }
}





// the function to rehash the whole array
void HashMap::rehash(const std::string& key, const std::string& value, unsigned int bucount)
{
    unsigned int hashValuer;
    unsigned int newbcount = bcount * 2 + 1;
    Node ** newItem = new Node*[newbcount];
    for (unsigned int j4= 0; j4 < newbcount; j4++){
            newItem[j4] = nullptr;} 
    for (unsigned int v = 0; v < bcount; v++){
        while (item[v]!= nullptr)
        {
            unsigned int hashNew = hasher(item[v]->key);
            Node *temp2;
            Node *targetPot2 = new Node;
            targetPot2->key = item[v]->key;
            targetPot2->value = item[v]->value;
            temp2 = newItem[hashNew%newbcount];
            newItem[hashNew%newbcount] = targetPot2;
            targetPot2->next = temp2;
            item[v]=item[v]->next;}
        }
        item = newItem;bcount = newbcount;
        if (not contains(key))
        {
            hashValuer = hasher(key);
            Node *inter1 = new Node;
            inter1->key = key;
            inter1->value = value;
            if (item[hashValuer%bcount] == nullptr)
            {
                inter1->next = nullptr;
                item[hashValuer%bcount]=inter1;
                bucketFill++;
                sz++;}
            else
            {
                inter1->next = item[hashValuer%bcount];
                item[hashValuer%bcount] = inter1;
                sz++;}}}


// function to add elements
void HashMap::add(const std::string& key, const std::string& value)
{
    double loadFact;
    int hashValuek,answer1;
    loadFact = loadFactor();
    if (loadFact < 0.8)
    {
        if (not contains(key))
        {
            hashValuek = hasher(key);
            answer1 = hashValuek%bcount;
            Node* k = item[answer1];
            if (k == nullptr)
            {
                 item[hashValuek%bcount] = new Node{key,value,nullptr};
                //item[hashValuek%bcount] = mc;
                bucketFill++;
                sz++;
            }
            else
            {
                Node *d = new Node{key,value,item[hashValuek%bcount]};
                item[hashValuek%bcount] = d;
                sz++;}}}
    else
    {
    rehash(key,value,bcount);     
    }
}

//function to remove elements
void HashMap::remove(const std::string& key)
{
    unsigned int hashValuerem;
    hashValuerem = hasher(key);
    Node *track2 = nullptr;
    Node *between = nullptr;
    Node *start = nullptr;
    Node *targetNode = nullptr;
    track2 = item[hashValuerem%bcount]; //point to the head
    if (item[hashValuerem%bcount] != nullptr and item[hashValuerem%bcount]->key == key)
    {
            between = item[hashValuerem%bcount];
            start = between->next;
            delete between;
            item[hashValuerem%bcount] = start;
            sz --;
        if (item[hashValuerem%bcount] == nullptr)
        {
            bucketFill --;
        }}
    else if(item[hashValuerem%bcount] == nullptr){}
    else{
        while (track2->next != nullptr)
        {
            if (track2->next->key == key)
            {
                targetNode = track2->next;
                track2->next=track2->next->next;
            }}
        sz--;
        if (item[hashValuerem%bcount] == nullptr)
        {
            bucketFill --;
        }}}





// function that test if contain an element
bool HashMap::contains(const std::string& key) const
{
    unsigned int hashValue;
    Node *newPointer = nullptr; 
    hashValue = hasher(key);
    newPointer = item[hashValue%bcount];
    while (newPointer != nullptr)
    {
        if (key == newPointer->key)
        {
            return true;
        }
        newPointer = newPointer->next;
    }
    return false;
}



// find the value of a given key
std::string HashMap::value(const std::string& key) const
{
    //std::cout<<"ddd"<<std::endl;
    for (unsigned int v = 0; v < bcount; v++)
    {
        Node*track = item[v];
        while (track!= nullptr)
        {
            if (track->key == key)
            {
                return track->value;
            }
            track = track->next;
        }
    }
    return "";
    
}







unsigned int HashMap::size() const
{
    return sz;
}


unsigned int HashMap::bucketCount() const
{
    return bcount;
}


double HashMap::loadFactor() const
{
    double ans;
    ans = (double)bucketFill/(double)bcount;
    return ans;
}




unsigned int HashMap::maxBucketSize() const
{
    Node *goal;
    unsigned int interchange = 0;
    for (unsigned int buck = 0; buck < bcount; buck++)
        {
            unsigned int maxSize = 0;
            goal = item[buck];
            while (goal != nullptr)
            { 
                goal = goal->next;
                maxSize ++;
            }
            if (maxSize > interchange)
            {
                interchange = maxSize;
            }
        }
        return interchange;
    }


