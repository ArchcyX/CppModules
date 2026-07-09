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
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"

// Görselleştirme için renk tanımlamaları
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"
#define MAGENTA "\033[35m"

int main(void)
{
    std::cout << CYAN << "=======================================================" << RESET << std::endl;
    std::cout << CYAN << "        STAJYER (INTERN) SISTEMI TESTLERI BAŞLADI       " << RESET << std::endl;
    std::cout << CYAN << "=======================================================\n" << RESET << std::endl;

    Intern      stajyer;
    Bureaucrat  yuceYonetici("Müdür Ahmet", 1);
    Bureaucrat  stajyerYardimcisi("Stajyer Ali", 150);
    AForm* form = NULL;

    // =========================================================================
    // TEST 1: Shrubbery Creation Form Başarılı Senaryo
    // =========================================================================
    std::cout << YELLOW << "--- TEST 1: Shrubbery Creation (Ağaç Dikme Formu) ---" << RESET << std::endl;
    try 
    {
        form = stajyer.makeForm("shrubbery creation", "Bahce_Hedefi");
        if (form)
        {
            std::cout << *form << std::endl;
            yuceYonetici.signForm(*form);
            yuceYonetici.executeForm(*form);
            
            delete form; // İşimiz bitti, belleği temizliyoruz
            form = NULL;
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Beklenmeyen Hata: " << e.what() << RESET << std::endl;
        if (form) { delete form; form = NULL; } // Hata durumunda sızıntıyı önle
    }

    // =========================================================================
    // TEST 2: Robotomy Request Form Başarılı Senaryo
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 2: Robotomy Request (Robotlaştırma Formu) ---" << RESET << std::endl;
    try 
    {
        form = stajyer.makeForm("robotomy request", "Bender_Target");
        if (form)
        {
            yuceYonetici.signForm(*form);
            yuceYonetici.executeForm(*form);
            
            delete form;
            form = NULL;
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Beklenmeyen Hata: " << e.what() << RESET << std::endl;
        if (form) { delete form; form = NULL; }
    }

    // =========================================================================
    // TEST 3: Presidential Pardon Form Başarılı Senaryo
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 3: Presidential Pardon (Başkanlık Affı Formu) ---" << RESET << std::endl;
    try 
    {
        form = stajyer.makeForm("presidential pardon", "Arthur Dent");
        if (form)
        {
            yuceYonetici.signForm(*form);
            yuceYonetici.executeForm(*form);
            
            delete form;
            form = NULL;
        }
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Beklenmeyen Hata: " << e.what() << RESET << std::endl;
        if (form) { delete form; form = NULL; }
    }

    // =========================================================================
    // TEST 4: GEÇERSİZ FORM ADI - ÖZEL EXCEPTION TESTI
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 4: Hata Yönetimi (Geçersiz Form İsmi) ---" << RESET << std::endl;
    try 
    {
        std::cout << MAGENTA << "[Deneme] Olmayan bir form adı giriliyor ('coffee making')..." << RESET << std::endl;
        form = stajyer.makeForm("coffee making", "Yonetici_Odasi");
        
        // Eğer kod buraya ulaşırsa hata var demektir, çünkü exception fırlatmalıydı!
        std::cout << RED << "HATA: Sistem exception fırlatmadı!" << RESET << std::endl;
        if (form) { delete form; form = NULL; }
    }
    catch (const Intern::FormNotFoundException& e) 
    {
        // Yazdığın özel exception'ın buraya düşmesi bekleniyor
        std::cout << GREEN << "BAŞARILI: Yazdığın özel exception yakalandı!" << RESET << std::endl;
        std::cerr << RED << "Fırlatılan Mesaj: " << e.what() << RESET << std::endl;
    }
    catch (const std::exception& e) 
    {
        std::cerr << RED << "Farklı bir exception yakalandı: " << e.what() << RESET << std::endl;
    }

    // =========================================================================
    // TEST 5: ENTEGRASYON TESTI (Stajyer Oluşturur Ama Bürokratın Gücü Yetmez)
    // =========================================================================
    std::cout << YELLOW << "\n--- TEST 5: Entegrasyon (Form Doğru Ama Bürokrat Yetkisiz) ---" << RESET << std::endl;
    try 
    {
        form = stajyer.makeForm("presidential pardon", "Tehlikeli Suçlu");
        if (form)
        {
            std::cout << MAGENTA << "[Deneme] Düşük rütbeli bürokrat formu imzalamaya çalışıyor..." << RESET << std::endl;
            stajyerYardimcisi.signForm(*form); // İmzalayamayacak (Yetki yetersiz logu basacak)
            
            std::cout << MAGENTA << "[Deneme] Düşük rütbeli bürokrat imzasız formu çalıştırmaya çalışıyor..." << RESET << std::endl;
            stajyerYardimcisi.executeForm(*form); // Form imzasız olduğu için fırlatacak
            
            // Eğer üstteki satır fırlatırsa alt satıra geçmez, catch bloğuna atlar. 
            // Bu yüzden catch bloğunda temizlik kontrolü şarttır.
            delete form;
            form = NULL;
        }
    }
    catch (const std::exception& e) 
    {
        std::cout << GREEN << "BAŞARILI: Yetkisiz işlem engellendi ve hata yakalandı." << RESET << std::endl;
        std::cerr << RED << "Yakalanan Hata: " << e.what() << RESET << std::endl;
        
        // Bellek sızıntısını önlemek için buradaki pointer'ı temizliyoruz
        if (form) 
        {
            delete form; 
            form = NULL;
            std::cout << CYAN << "[Sistem Bilgisi] Bellek sızıntısı başarıyla engellendi (Form heap'ten silindi)." << RESET << std::endl;
        }
    }

    std::cout << GREEN << "\n=======================================================" << RESET << std::endl;
    std::cout << GREEN << "             TÜM TESTLER BAŞARIYLA TAMAMLANDI!             " << RESET << std::endl;
    std::cout << GREEN << "=======================================================\n" << RESET << std::endl;

    return (0);
}
