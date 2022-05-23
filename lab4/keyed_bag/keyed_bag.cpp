#include <iostream>
#include "keyed_bag.h"
#include <algorithm>
#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cmath>

using namespace std;

namespace coen79_lab4{
	void keyed_bag::erase(){ //set empty keybag
		for (int i=0; i<used;++i){
			keys[i]='\0';
			data[i] = 0.0;
		}
			used = 0;
	}
		    
	bool keyed_bag::erase(const key_type& key){
		assert(used>0);
			for ( int i=0; i<used; ++i){
				if(keys[i]==key){ //erase key
						for ( int j=i;j<used-1;++j){
							keys[j]=keys[j+1];
							data[j]=data[j+1];
						}
						used--; //decrement used
						return true;
				}
												            
			}
			return false;
	}
	bool keyed_bag::has_key(const key_type & key) const {
		for ( int i=0; i<used;++i){
			if(keys[i]==key){
				return true;//has key
			}
											            
		}
		return false;//no key
	}
	void keyed_bag::insert(const value_type& entry, const key_type& key){
		assert(size()<CAPACITY && has_key(key)==false);
		keys[used]=key; //insert keys
		data[used]=entry; //insert data
		used++; //increment used
	}
					    
	void keyed_bag::operator +=(const keyed_bag& addend){
		assert(size() + addend.size()<=CAPACITY);
		for ( int i=0; i<addend.used;++i){
			if(!has_key(addend.keys[i])){//no have key, can add
				keys[used]=addend.keys[i]; //can access private variables
					data[used]=addend.data[i];
						used++;
			}
		}
	}
						    
	keyed_bag::value_type keyed_bag:: get(const key_type& key) const {
		assert(has_key(key));
		for ( int i=0; i<used;++i){
			if(keys[i]==key){ //see if has key
				return data[i];
			}
		}
		return 0.0;
	}
							    
	keyed_bag::size_type keyed_bag::count(const value_type& target) const{
		size_type count=0;
		for ( int i=0; i<used;++i){
			if(data[i]==target){ //count number of similar keys in keyback
				count++;
			}
		}
		return count;
	}
								    
	bool keyed_bag::hasDuplicateKey(const keyed_bag& otherBag) const{
		for( int i=0; i<otherBag.used;++i){
			if(has_key(otherBag.keys[i])){
				return true; //check for duplicates
			}
		}
		return false;
	}
									    
	keyed_bag operator+(const keyed_bag& b1, const keyed_bag& b2){
		assert(b1.size()+b2.size()<=keyed_bag::CAPACITY);
		keyed_bag result; //return new keybag that has union of both
		result+=b1;
		result+=b2;
																			        
																			        
		return result;
	}
										    
}
