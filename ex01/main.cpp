/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/06 19:24:28 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/07 22:53:45 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main(){
    Span a(5);

    try{
        a.addNumber(1);
        std::cout<<"add 1"<<std::endl;
        a.addNumber(400);
        std::cout<<"add 2"<<std::endl;
        a.addNumber(398);
        std::cout<<"add 3"<<std::endl;
        a.addNumber(48);
        std::cout<<"add 4"<<std::endl;
        a.addNumber(1000);
        std::cout<<"add 5"<<std::endl;
        a.addNumber(6);
        std::cout<<"add 6"<<std::endl;
    }
    catch(std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
    a.showTab();
    std::cout<<a.longestSpan()<<std::endl;
    std::cout<<a.shortestSpan()<<std::endl;
    a.showTab();
    return 0;
}