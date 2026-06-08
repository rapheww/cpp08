/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:24:28 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/08 20:52:13 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(){
    Span a(11000);
    Span b(1);
    std::vector<int> bigV(100, 1);
    
    try{
        // a.addNumber(1);
        // std::cout<<"add 1"<<std::endl;
        // a.addNumber(400);
        // std::cout<<"add 2"<<std::endl;
        // a.addNumber(398);
        // std::cout<<"add 3"<<std::endl;
        // a.addNumber(48);
        // std::cout<<"add 4"<<std::endl;
        // a.addNumber(1000);
        // std::cout<<"add 5"<<std::endl;
        // a.addNumber(6);
        // std::cout<<"add 6"<<std::endl;
        a.addNumber(bigV.begin(), bigV.end());
        std::cout<<"add 10 000 numbers successfully\n";
        a.addNumber(48);
        std::cout<<"add 48"<<std::endl;
        a.addNumber(1000);
        std::cout<<"add 1000"<<std::endl;
    }
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    a.showTab();
    std::cout<<"longest span is "<<a.longestSpan()<<std::endl;
    std::cout<<"shortest span is "<<a.shortestSpan()<<std::endl;
    std::cout<<"--- Exception ---\n";
    try{
        b.addNumber(1);
        std::cout<<"add 1"<<std::endl;
        b.addNumber(400);
        std::cout<<"add 400"<<std::endl;
    }
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    try{
        int shortest = b.shortestSpan();
        std::cout<<"shortest span is "<<shortest<<std::endl;
    }
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    try{
        int longest = b.longestSpan();
        std::cout<<"longest span is "<<longest<<std::endl;
    }
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }      
    return 0;
}