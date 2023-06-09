/**
 * @file doublevector.cpp
 * @authors Luis Estevam Rosa Chaves (536699), Gustavo Henrique Freitas de Sousa (535735)
 * @brief 
 * @date 2023-06-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "doublevector.h"

#define VERIF_OP_VALID(index) ((int)index >= this->size() || this->empty())
#define SPACES_AVAILABLE_FRONT (this->m_head + 1)
#define SPACES_AVAILABLE_BACK (this->m_capacity - this->m_tail) 

DoubleVector::DoubleVector() {
  this->m_capacity = 16;
  this->m_list = new int[this->m_capacity];
  this->m_head = 7;
  this->m_tail = 8;
  this->m_size = 0;
}

DoubleVector::DoubleVector(int n) {
  this->m_capacity = n;
  this->m_list = new int[this->m_capacity];
  this->m_tail = n - 1 - ((n - 1) / 2);
  this->m_head = this->m_tail - 1;
  this->m_size = 0;
}

DoubleVector::~DoubleVector() {
  if(this->m_list != nullptr) delete[] this->m_list;
}


bool DoubleVector::empty() {
  return this->size() == 0;
}

int DoubleVector::size() {
  return this->m_size;
}

void DoubleVector::push_front(int value){
  if(SPACES_AVAILABLE_FRONT <= 0) {
    if(SPACES_AVAILABLE_BACK > 0) {
      this->shift();
    } else {
      this->resize();
    }
  }

  this->m_list[this->m_head --] = value;

  this->m_size ++;
}

void DoubleVector::push_back(int value){
  if(SPACES_AVAILABLE_BACK <= 0) {
    if(SPACES_AVAILABLE_FRONT > 0) {
      this->shift();
    } else {
      this->resize();
    }
  }

  this->m_list[this->m_tail ++] = value;
  this->m_size ++;
}

int DoubleVector::pop_back() {
  if(this->empty()) {
    return -1;
  }

  int element_rmv = this->at(this->size() - 1);

  this->m_size --;
  this->m_tail --;

  return element_rmv;
}

int DoubleVector::pop_front() {
  if(this->empty()) {
    return -1;
  }

  int element_rmv = this->at(0);

  this->m_size --;
  this->m_head ++;

  return element_rmv;
}

int DoubleVector::at(unsigned int index) {
  if(VERIF_OP_VALID(index)) {
    return -1;
  }

  int idx_real = this->m_head + index + 1;
  
  return this->m_list[idx_real];
}

void DoubleVector::resize() {
  this->m_capacity <<= 1;

  int cap_in_left = (this->m_capacity / 2);
  int sz_in_left  = ((this->size() + 1)/2);

  int cap_in_right = ((this->m_capacity)/ 2);
  int sz_in_right  = (this->size()/2);

  int new_head =  cap_in_left  - sz_in_left;
  int new_tail =  sz_in_right + 1 + cap_in_left;

  int * new_list = new int[this->m_capacity];

  for(int i = new_head + 1, sz = 0; sz < this->size(); ++ i, ++ sz) {
    new_list[i] = this->at(sz);
  }

  if (this->m_list != nullptr)
    delete[] this->m_list;

  this->m_list = new_list;

  this->m_head = new_head;
  this->m_tail = new_tail;
}

void DoubleVector::shift() {
  int cap_in_left = (this->m_capacity / 2);
  int sz_in_left = ((this->size() + 1) / 2);

  int cap_in_right = ((this->m_capacity) / 2);
  int sz_in_right = (this->size() / 2);

  int new_head = cap_in_left - sz_in_left;
  int new_tail = sz_in_right + 1 + cap_in_left;

  int * new_list = new int[this->m_capacity + 1];

  for (int i = new_head + 1, sz = 0; sz < this->size(); ++i, ++sz) {
    new_list[i] = this->at(sz);
  }

  delete[] this->m_list;

  this->m_head = new_head;
  this->m_tail = new_tail;


  this->m_list = new_list;
}


/* void double_vector::removeAt(int k) {
    if(k >= this->m_capacity/2) {
        for(int i = m_head+1+k; i+1 != m_tail; i++) m_list[i] = m_list[i+1];
        m_tail--; 
    } else {
        for(int i = m_head+1+k; i-1 != m_head; i--) m_list[i] = m_list[i-1];
        m_head++;
    }
    m_size--;
}; */
void DoubleVector::remove(unsigned int index) {
  if(SPACES_AVAILABLE_FRONT < SPACES_AVAILABLE_BACK) {
    for(int idx_real = this->m_head + index + 1; idx_real <= this->m_tail - 2; ++ idx_real) {
      this->m_list[idx_real] = this->m_list[idx_real + 1]; 
    }
    -- this->m_tail;
  } else {
    for(int idx_real = this->m_head + index + 1; idx_real >= this->m_head - 2; -- idx_real) {
      this->m_list[idx_real] = this->m_list[idx_real - 1]; 
    }
    ++ m_head;
  }
  -- m_size;
};

void DoubleVector::removeAll(int value){
  for(unsigned int i = 0; i < this->size(); ++i){
    if(this->at(i) == value){
      remove(i);
      i--;
    }
  }
}

void DoubleVector::print() {
  for(int i = 0; i < this->size(); ++ i) {
    printf("%d ", this->at(i));
  }
}

void DoubleVector::printReverse(){
  for(int i = this->size() - 1; i >= 0; -- i) {
    printf("%d ", this->at(i));  
  }
}

void DoubleVector::concat(DoubleVector& lst){
  for(int i = 0; i < lst.size(); ++ i){
    this->push_back(lst.at(i));
  }
}

bool DoubleVector::equals(DoubleVector& lst){
  if(this->size() != lst.size()) {
    return false;
  }
  
  for(int i = 0; i < this->size(); ++ i) {
    if(this->at(i) != lst.at(i)) {
      return false;
    }
  }
  
  return true;
}

void DoubleVector::replaceAt(int value, unsigned int index) {
   int idx_real = this->m_head + index + 1;

  if(VERIF_OP_VALID(idx_real)) {
    return;
  }
  
  this->m_list[idx_real] = value;
}

void DoubleVector::insert(int value, unsigned int index) {
  if(this->size() == this->m_capacity) {
    resize();
  }

  if(index == 0) {
    this->push_front(value);
  } else if(index == this->size()) {
    this->push_back(value);
  } else if(SPACES_AVAILABLE_FRONT < SPACES_AVAILABLE_BACK) {
    this->m_head--;
    for(int i = this->m_head + 1; i <= index + this->m_head; ++i) {
      this->m_list[i] = this->m_list[i + 1];
    }
    this->m_list[index + this->m_head] = value;
    this->m_size++;
  } else {
    for(int i = this->m_tail; i >= index + this->m_head + 1; --i) {
      this->m_list[i] = this->m_list[i - 1];
    }
    this->m_tail++;
    this->m_list[index + this->m_head + 1] = value;
    this->m_size++;
  }
}
