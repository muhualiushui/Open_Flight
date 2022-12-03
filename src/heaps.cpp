#include "../includes/heaps.hpp"

void Heap::push(Database::Airports* node){
    data.push_back(node);
    heapifyUp(data.size()-1);
}
void Heap::change(int position,double new_cost){
    int idx=0;
    for(auto i:data){
        if(i->ID==position)break;
        idx++;
    }
    data[idx]->cost=new_cost;
    heapifyDown(idx);
    heapifyUp(idx);
}
Database::Airports* Heap::pop(){
    auto result= data[0];
    std::swap(data.back(),data[0]);
    data.pop_back();
    heapifyDown(0);
    return result;
}
Database::Airports* Heap::top(){
    return data[0];
}

void Heap::heapifyDown(size_t currentIdx){
    if(! hasAChild(currentIdx)){
        return;
    }
    size_t min=maxPriorityChild(currentIdx);
    if(data[currentIdx]>data[min]){
        std::swap(data[currentIdx],data[min]);
        return heapifyDown(min);
    }
}

void Heap::heapifyUp(size_t currentIdx){
    if (currentIdx==0)
        return;
    size_t parentIdx = parent(currentIdx);
    if (data[currentIdx]->cost<data[parentIdx]->cost) {
        std::swap(data[currentIdx], data[parentIdx]);
        heapifyUp(parentIdx);
    }
}

bool Heap::hasAChild(size_t currentIdx){
    return (leftChild(currentIdx)<data.size());
}

size_t Heap::leftChild(size_t currentIdx) 
{
    return 2*currentIdx+1;
}

size_t Heap::rightChild(size_t currentIdx){
    return 2*currentIdx+2;
}

size_t Heap::parent(size_t currentIdx){
    return (currentIdx-1)/2;
}
size_t Heap::maxPriorityChild(size_t currentIdx){
    size_t left=leftChild(currentIdx);
    if(rightChild(currentIdx)<data.size()){
        size_t right=rightChild(currentIdx);
        return data[left]->cost<data[right]->cost? left:right;
    }
    return left;
}