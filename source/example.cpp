#include <cstdlib>  // std :: rand ()
#include <vector>  // std::vector<>
#include <list>   // std::list<>
#include <iostream>  // std :: cout
#include <iterator>  // std::ostream_iterator <>
#include <algorithm> // std::reverse, std::generate


int main () {

 std::vector<int> v0(10); // Erstellt Vektor v0 mit 10 Speicherplaetzen
 for (std::vector<int>::iterator it = v0.begin(); it != v0.end(); ++it) 
{ // iteriert ueber den Vektor von Beginn (0) bis Ende (9) und erhoeht i um 1
  *it = std::rand(); // belegt diese Plaetze mit Zufallszahlen
}
 // oder
 //for (auto& v : v0) {
 // v = std::rand();
 //}

 // Uebergibt den Inhalt v0 an Ausgabeiterator, der diese ausgibt 
 std::copy(std::begin(v0), std::end(v0), std::ostream_iterator<int>(std::cout, "\n"));

 std::list<int> l0(v0.size()); // erstellt Liste l0 mit der Groeße von v0
 std::copy(std::begin(v0), std::end(v0), std::begin(l0)); // kopiert den Inhalt von v0 in l0 (Ziel ist Anfang l0)
 std::list<int> l1(std::begin(l0), std::end(l0)); // erstellt Liste l1 und uebernimmt alle Parameter von l0
 std::reverse(std::begin(l1), std::end(l1)); // dreht die Reihenfolge der Listen-Elemente um
 std::copy(std::begin(l1), std::end(l1), std::ostream_iterator<int>(std::cout, "\n")); // und gibt die Liste l1 aus

 // sortiert die Liste l1 nach aufsteigender Reihenfolge. Die Reihenfolge gleicher Elemente bleibt bestehen
 l1.sort();
 std::copy( l1.begin(), l1.end(), std::ostream_iterator<int>(std::cout, "\n")); // gibt die sortierte Liste l1 aus

 std::generate(std::begin(v0), std::end(v0), std::rand); // belegt den Vektor v0 mit Zufallszahlen (generate gibt uebergebenen Elementen neuen Wert letzter Parameter ist dazu genutzte Funktion)
 std::copy( v0.rbegin(), v0.rend(), std::ostream_iterator<int>(std::cout, "\n")); // Iterator gibt die Elemente von v0 in umgekehrter Reihenfolgen aus

 return 0;
}
