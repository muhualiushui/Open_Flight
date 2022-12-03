#include "Transform.hpp"
class Heap{
    public:
    bool hasAChild(size_t currentIdx);
    size_t leftChild(size_t currentIdx);
    size_t rightChild(size_t currentIdx);
    size_t parent(size_t currentIdx);
    size_t maxPriorityChild(size_t currentIdx);

    void heapifyDown(size_t currentIdx);
    void heapifyUp(size_t currentIdx);

    void push(Database::Airports* node);
    Database::Airports* pop();
    Database::Airports* top();
    void change(int position,double new_cost);
    private:
    vector<Database::Airports*> data;
};