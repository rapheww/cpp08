/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 17:27:35 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/06 19:08:24 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

void displayInt(int i){
    std::cout<<i<<std::endl;
}

int main(){
    std::cout<<"---TESTS WITH A LIST---\n";
    std::list<int> a;
    
    a.push_back(1);
    a.push_back(-2);
    a.push_back(43);
    
    std::for_each(a.begin(), a.end(), displayInt);
    try{
        std::list<int>::const_iterator it = easyfind(a, 1);
        std::cout<<*it<<std::endl;
        std::list<int>::const_iterator it2 = easyfind(a, -2);
        std::cout<<*it2<<std::endl;
        std::list<int>::const_iterator it3 = easyfind(a, 500);
        std::cout<<*it3<<std::endl;
    }
    catch(std::out_of_range& e){
        std::cout<<e.what()<<std::endl;
    }

    std::cout<<"\n---TESTS WITH A VECTOR---\n";
    std::vector<int> b;

    b.insert(b.begin(), 1);
    b.insert(b.begin(), 4504);
    b.insert(b.begin(), 234);
    b.insert(b.begin(), 23);
    
    std::for_each(b.begin(), b.end(), displayInt);
    try{
        std::vector<int>::const_iterator it = easyfind<std::vector<int> >(b, 23);
        std::cout<<"value find "<<*it<<std::endl;
        std::vector<int>::const_iterator it2 = easyfind<std::vector<int> >(b, -2);
        std::cout<<"value find "<<*it2<<std::endl;
        std::vector<int>::const_iterator it3 = easyfind<std::vector<int> >(b, 4504);
        std::cout<<"value find "<<*it3<<std::endl;
    }
    catch(std::out_of_range& e){
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}