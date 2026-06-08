/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchaumei <rchaumei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 21:53:31 by rchaumei          #+#    #+#             */
/*   Updated: 2026/06/08 22:35:15 by rchaumei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>


#include <iostream>
#include <algorithm>
#include <vector>
#include "MutantStack.hpp"

// Fonction d'aide pour afficher une pile CONSTANTE (pour tester les const_iterators)
void printConstStack(const MutantStack<int>& s) {
    std::cout << "[Const Iterator] Contenu : ";
    for (MutantStack<int>::const_iterator it = s.begin(); it != s.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "=== TEST 1 : FONCTIONNALITÉS DE BASE DE STACK ===" << std::endl;
    MutantStack<int> mstack;
    
    mstack.push(42);
    mstack.push(17);
    mstack.push(8);
    mstack.push(99);
    mstack.push(3);

    std::cout << "Taille attendue (5) : " << mstack.size() << std::endl;
    std::cout << "Top attendu (3) : " << mstack.top() << std::endl;

    std::cout << "\n=== TEST 2 : ITÉRATEURS STANDARDS (Lecture / Écriture) ===" << std::endl;
    std::cout << "Contenu initial : ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // On modifie le premier élément via l'itérateur pour prouver qu'il n'est pas const
    MutantStack<int>::iterator first = mstack.begin();
    *first = 100; 
    std::cout << "Après modification du premier element (42 -> 100) : " << mstack.begin()[0] << std::endl;


    std::cout << "\n=== TEST 3 : ITÉRATEURS CONST === " << std::endl;
    // On appelle la fonction qui prend une référence CONSTANTE
    printConstStack(mstack);


    std::cout << "\n=== TEST 4 : COMPATIBILITÉ AVEC LA STL (Algorithmes) ===" << std::endl;
    // On va trier notre Stack (ce qui est impossible avec une std::stack normale !)
    std::cout << "Tri de la pile via std::sort..." << std::endl;
    std::sort(mstack.begin(), mstack.end());
    
    std::cout << "Contenu trie : ";
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;


    std::cout << "\n=== TEST 5 : LA FORME CANONIQUE (Copie et Assignation) ===" << std::endl;
    // Test du constructeur par copie
    MutantStack<int> mstackCopy(mstack);
    std::cout << "Copie - Taille (5) : " << mstackCopy.size() << " | Top : " << mstackCopy.top() << std::endl;

    // Test de l'opérateur d'assignation
    MutantStack<int> mstackAssign;
    mstackAssign.push(1);
    mstackAssign.push(2); // Pile temporaire
    
    mstackAssign = mstack; // Doit écraser le contenu par celui de mstack
    std::cout << "Assignation - Taille (5) : " << mstackAssign.size() << " | Top : " << mstackAssign.top() << std::endl;

    // On vérifie que modifier la copie ne modifie pas l'original (Deep Copy)
    mstackCopy.push(666);
    std::cout << "Après push dans la copie -> Top original : " << mstack.top() << " | Top copie : " << mstackCopy.top() << std::endl;


    std::cout << "\n=== TEST 6 : AVEC DES STRINGS ===" << std::endl;
    MutantStack<std::string> sstack;
    sstack.push("Piscine");
    sstack.push("C++");
    sstack.push("42");

    for (MutantStack<std::string>::iterator it = sstack.begin(); it != sstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

// int main()
// {
//     std::list<int> mstack;
//     mstack.push_front(5);
//     mstack.push_front(17);
//     std::cout << *(mstack.begin()) << std::endl;
//     mstack.pop_front();
//     std::cout << mstack.size() << std::endl;
//     mstack.push_back(3);
//     mstack.push_back(5);
//     mstack.push_back(737);
//     //[...]
//     mstack.push_back(0);
//     std::list<int>::iterator it = mstack.begin();
//     std::list<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//     std::cout << *it << std::endl;
//     ++it;
//     }
//     std::list<int> s(mstack);
//     return 0;
// }