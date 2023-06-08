/**
 * @file doublevector.cpp
 * @author  Luis Estevam Rosa Chaves (536699), Gustavo Henrique Freitas de Sousa (535735)
 * @brief 
 * @date 2023-06-08
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>
#include "doublevector.h"

#define VERIF_OP_VALID(index) (index >= this->size() || !(this->empty()))

DoubleVector::DoubleVector() {
  this->m_capacity = 16;
  this->m_list = new int[this->m_capacity];
  this->m_head = 7;
  this->m_tail = 8;
  this->m_size = 0;
}

DoubleVector::DoubleVector(int n){
  this-> m_capacity = n;
  this->m_list = new int[this->m_capacity];
  this->m_head = (n - 1) / 2;
  this->m_tail = (n - 1)  - this->m_head;
  this->m_size = 0;
}

DoubleVector::~DoubleVector(){
  if(!empty()) delete[] this->m_list;
}


bool DoubleVector::empty(){
  return !(this->size());
}

int DoubleVector::size(){
  return this->m_size;
}

void DoubleVector::push_back(int value){

}

int DoubleVector::pop_back(){

}

void DoubleVector::push_front(int value){

}

int DoubleVector::pop_front(){

}

int DoubleVector::at(unsigned int index) {
  if(VERIF_OP_VALID(index)) {
    return -1;
  }

  int idx_real = this->m_head + index;
  
  return this->m_list[idx_real];
}

void DoubleVector::resize() {
  
}


// TODO: Verificar ponto 1.1.2 do pdf;
void DoubleVector::remove(unsigned int index){
  if(VERIF_OP_VALID(index)){
    return;
  }
  
  for(unsigned int i = index; i < this->size() - 1; ++ i){
    replaceAt(this->at(i + 1), i);
  }

  pop_back();
}


// TODO: Verificar ponto 1.1.2 do pdf;
void DoubleVector::removeAll(int value){

}

void DoubleVector::print() {
  for(int i = 0; i < this->size(); ++ i) {
    printf("%d ", this->at(i));
  }
}

void DoubleVector::printReverse(){
  for(int i = this->size(); i >= 0; -- i) {
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
  if(VERIF_OP_VALID(index)) {
    return;
  }
  
  this->m_list[index] = value;
}

void DoubleVector::insert(int value, unsigned int index){

}

