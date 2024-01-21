#include <iostream>
#include <cctype>
#include "modAlphaCipher.h"
#include <locale>
#include <codecvt>
#include <typeinfo>
using namespace std;
void check(const wstring& Text, const wstring& key, const bool destructCipherText=false)
{
    try {
        wstring cipherText;
        wstring decryptedText;
        modAlphaCipher cipher(key);
        cipherText = cipher.encrypt(Text);
        if (destructCipherText)
            cipherText.front() = towlower(cipherText.front());
        decryptedText = cipher.decrypt(cipherText);
        wcout<<L"key="<<key<<endl;
        wcout<<Text<<endl;
        wcout<<cipherText<<endl;
        wcout<<decryptedText<<endl;
    } catch (const cipher_error & e) {
        wcerr<<"Error: "<<e.what()<<endl;
    }
    
}

int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    check(L"КОРОВА",L"НИКИТА");
    check(L"НИКИТА",L"");
    check(L"НИКИТА",L"КОРОВА222");
    check(L"Н И К И Т А",L"КОРОВА");
    check(L"222",L"КОРОВА");
}
