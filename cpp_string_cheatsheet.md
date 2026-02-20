# 🧵 C++ String Cheat Sheet

## 📌 Osnove

``` cpp
#include <string>
using namespace std;

string s = "Hello";
```

-   `std::string` je del STL
-   Indeksiranje se začne pri 0
-   Stringi so **mutable**

------------------------------------------------------------------------

## 🔎 Dostop do znakov

``` cpp
string s = "Hello";

s[0];        // 'H'
s.at(1);     // 'e' (varno, preverja meje)
```

------------------------------------------------------------------------

## ➕ Združevanje in ponavljanje

``` cpp
string a = "Hi";
string b = "!";

string c = a + b;   // "Hi!"
```

------------------------------------------------------------------------

## 📏 Dolžina

``` cpp
s.length();
s.size();   // isto kot length()
```

------------------------------------------------------------------------

## ✂️ Podniz (substring)

``` cpp
s.substr(1, 3);   // od indeksa 1, dolžina 3
```

------------------------------------------------------------------------

## 🔍 Iskanje

``` cpp
s.find("ell");     // vrne pozicijo ali string::npos
s.rfind("l");      // zadnja pojavitev
```

------------------------------------------------------------------------

## 🔄 Brisanje in vstavljanje

``` cpp
s.erase(1, 2);        // izbriše 2 znaka od indeksa 1
s.insert(1, "ABC");   // vstavi na indeks 1
s.replace(1, 2, "XX");
```

------------------------------------------------------------------------

## 🔠 Pretvorbe

``` cpp
#include <algorithm>

transform(s.begin(), s.end(), s.begin(), ::tolower);
transform(s.begin(), s.end(), s.begin(), ::toupper);
```

------------------------------------------------------------------------

## 🔢 Pretvorbe tipov

``` cpp
int x = stoi("123");
double d = stod("3.14");

string s = to_string(123);
```

------------------------------------------------------------------------

## 🔁 Iteracija

``` cpp
for(char c : s) {
    cout << c << endl;
}
```

------------------------------------------------------------------------

## 🧹 Primerjava

``` cpp
if (s == "Hello") {}
if (s.compare("Hello") == 0) {}
```

------------------------------------------------------------------------

## 🧠 Koristni triki

``` cpp
// preveri ali vsebuje
if (s.find("abc") != string::npos) {}

// obrni string
reverse(s.begin(), s.end());
```

------------------------------------------------------------------------

## 🔌 C-style string

``` cpp
const char* cstr = s.c_str();
```

------------------------------------------------------------------------

# ✅ Hitri povzetek

-   Uporabljaj `std::string`, ne C-style stringov
-   `size()` in `length()` sta enaka
-   `find()` vrne `string::npos`, če ne najde
-   Pretvorbe: `stoi`, `stod`, `to_string`
