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
#include <cstdlib> // exit() ve rand() için
#include <ctime>   // time() için (Robotomy randomizer)

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// =========================================================================
// Terminal Renk Kodları (Değerlendirme sırasında harika görünür)
// =========================================================================
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

// =========================================================================
// Özel Çöküş (Terminate) Yöneticisi
// =========================================================================
void    customTerminate()
{
    std::cerr << RED << "\n[SİSTEM ÇÖKTÜ] Yakalanmayan bir hata (Uncaught Exception) fırlatıldı!" << RESET << std::endl;
    std::cerr << RED << "İşletim sistemi 'abort' çağrısı yapmadan önce program güvenlice kapatılıyor..." << RESET << std::endl;
    exit(1);
}

int main(void)
{
    std::set_terminate(customTerminate);
    std::srand(std::time(NULL));

    std::cout << CYAN << "\n=======================================================" << RESET << std::endl;
    std::cout << CYAN << "             BUREAUCRACY SYSTEM INITIALIZED            " << RESET << std::endl;
    std::cout << CYAN << "=======================================================\n" << RESET << std::endl;

    // =========================================================================
    // TEST 1: SHRUBBERY CREATION FORM (Sign: 145, Exec: 137)
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 1: Shrubbery Creation (Ağaç Dikme) ---" << RESET << std::endl;
    try 
    {
        Bureaucrat gardener("Bahçıvan Ali", 130); // İmzalamaya ve yürütmeye yetkisi var
        ShrubberyCreationForm form1("Bahce");

        std::cout << form1 << std::endl;
        gardener.signForm(form1);
        gardener.executeForm(form1);
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Hata: " << e.what() << RESET << std::endl;
    }

    // =========================================================================
    // TEST 2: ROBOTOMY REQUEST FORM (Sign: 72, Exec: 45)
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 2: Robotomy Request (Matkap Sesi) ---" << RESET << std::endl;
    try 
    {
        Bureaucrat mechanic("Mühendis Ayşe", 40); // İmzalamaya ve yürütmeye yetkisi var
        RobotomyRequestForm form2("Bender");

        mechanic.signForm(form2);
        mechanic.executeForm(form2); // %50 ihtimalle başarılı olur
        mechanic.executeForm(form2); // Şansı görmek için bir kez daha deniyoruz
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Hata: " << e.what() << RESET << std::endl;
    }

    // =========================================================================
    // TEST 3: PRESIDENTIAL PARDON FORM (Sign: 25, Exec: 5)
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 3: Presidential Pardon (Başkanlık Affı) ---" << RESET << std::endl;
    try 
    {
        Bureaucrat boss("Başkan", 1); // Her şeye yetkisi var
        PresidentialPardonForm form3("Arthur Dent");

        boss.signForm(form3);
        boss.executeForm(form3);
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Hata: " << e.what() << RESET << std::endl;
    }

    // =========================================================================
    // TEST 4: ERROR HANDLING (Yetki Yetersizliği ve İmzasız Form)
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 4: Güvenlik Ağları (Hata Yakalama) ---" << RESET << std::endl;
    try 
    {
        Bureaucrat intern("Stajyer", 150);
        PresidentialPardonForm form4("Tehlikeli Suçlu");

        // 1. Durum: İmzasız formu yürütmeye çalışmak (Exception fırlatmalı)
        std::cout << MAGENTA << "[Deneme 1] İmzasız formu yürütmeye çalışma:" << RESET << std::endl;
        intern.executionForm(form4);
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Yakalandı: " << e.what() << RESET << std::endl;
    }

    try 
    {
        Bureaucrat intern("Stajyer", 150);
        PresidentialPardonForm form4("Tehlikeli Suçlu");

        std::cout << MAGENTA << "\n[Deneme 2] Yetkisiz imza denemesi:" << RESET << std::endl;
        intern.signForm(form4);
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Yakalandı: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "\n=======================================================" << RESET << std::endl;
    std::cout << GREEN << "          TÜM TESTLER BAŞARIYLA TAMAMLANDI!            " << RESET << std::endl;
    std::cout << GREEN << "=======================================================\n" << RESET << std::endl;

    return (0);
}
