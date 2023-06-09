/**
 * @file doublevector.cpp
 * @authors Luis Estevam Rosa Chaves (536699), Gustavo Henrique Freitas de Sousa (535735)
 * @brief 
 * @date 2023-06-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#ifndef DOUBLEVECTOR_H
#define DOUBLEVECTOR_H

class DoubleVector {
  private: 
    int *m_list;
    int m_capacity;
    int m_size;
    int m_head;
    int m_tail; 

  public:
    DoubleVector();


    DoubleVector(int n);

    ~DoubleVector();
    
    int size();

    bool empty();
    
    void push_back(int value);

    int pop_back();

    void push_front(int value);
    
    int pop_front();
    
    int at(unsigned int index);
    
    void shift();
    
    void resize();
    
    void remove(unsigned int index);

    void removeAll(int value);
    
    void print();
    
    void printReverse();
    
    void concat(DoubleVector& lst);
    
    bool equals(DoubleVector& lst);

    void replaceAt(int value, unsigned int index);

    void insert(int value, unsigned int index);

};

#endif