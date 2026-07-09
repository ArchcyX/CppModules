/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alermi <alermi@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/07 09:35:51 by alermi            #+#    #+#             */
/*   Updated: 2026/06/07 09:35:52 by alermi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include "Form.hpp"
#include "Bureaucrat.hpp"

// Konsol çıktılarını renklendirmek için makrolar
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

int main(void)
{
    std::cout << CYAN << "=======================================================" << RESET << std::endl;
    std::cout << CYAN << "           MODULE 05 - EX01 TEST SENARYOLARI           " << RESET << std::endl;
    std::cout << CYAN << "=======================================================\n" << RESET << std::endl;

    // -------------------------------------------------------------------------
    std::cout << YELLOW << "--- TEST 1: Geçerli ve Geçersiz Form Oluşturma ---" << RESET << std::endl;
    try {
        Form validForm("Vergi Formu", 50, 25);
        std::cout << GREEN << "[BAŞARILI] " << validForm.getName() << " oluşturuldu." << RESET << std::endl;
        std::cout << validForm << std::endl; // << operatörünün testi
    } catch (const std::exception& e) {
        std::cerr << RED << "Hata: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << MAGENTA << "\n[Deneme] Derecesi 0 olan (Çok Yüksek) bir form oluşturuluyor..." << RESET << std::endl;
        Form invalidHighForm("Hatalı Form 1", 0, 50); 
    } catch (const std::exception& e) {
        std::cerr << RED << "Yakalandı: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << MAGENTA << "\n[Deneme] Derecesi 151 olan (Çok Düşük) bir form oluşturuluyor..." << RESET << std::endl;
        Form invalidLowForm("Hatalı Form 2", 100, 151); 
    } catch (const std::exception& e) {
        std::cerr << RED << "Yakalandı: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    std::cout << YELLOW << "\n--- TEST 2: Bürokrat Form İmzalama (BAŞARILI SENARYO) ---" << RESET << std::endl;
    try {
        Bureaucrat mudur("Müdür Ahmet", 10);
        Form izinFormu("Yıllık İzin Formu", 50, 50);

        std::cout << mudur << std::endl;
        
        mudur.signForm(izinFormu); // Müdürün derecesi (10), formun istendiği dereceden (50) daha iyi olduğu için imzalar.
        
        std::cout << GREEN << "\nİmza sonrası formun durumu:" << RESET << std::endl;
        std::cout << izinFormu << std::endl; 
    } catch (const std::exception& e) {
        std::cerr << RED << "Beklenmeyen Hata: " << e.what() << RESET << std::endl;
    }

    // -------------------------------------------------------------------------
    std::cout << YELLOW << "\n--- TEST 3: Bürokrat Form İmzalama (YETKİSİZ SENARYO) ---" << RESET << std::endl;
    try {
        Bureaucrat stajyer("Stajyer Ali", 150);
        Form gizliBelge("Çok Gizli Belge", 5, 5); // İmzalamak için en az 5. seviye olmak lazım

        std::cout << stajyer << std::endl;
        
        // Stajyer 150. seviyede olduğu için bu formu imzalayamaz
        stajyer.signForm(gizliBelge);
        
        std::cout << MAGENTA << "\nİmza denenmesinden sonra formun durumu:" << RESET << std::endl;
        std::cout << gizliBelge << std::endl;
    } catch (const std::exception& e) {
        std::cerr << RED << "Hata Yakalandı: " << e.what() << RESET << std::endl;
    }

    std::cout << CYAN << "\n=======================================================" << RESET << std::endl;
    std::cout << CYAN << "             TÜM TESTLER BAŞARIYLA TAMAMLANDI!             " << RESET << std::endl;
    std::cout << CYAN << "=======================================================\n" << RESET << std::endl;

    return (0);
}
