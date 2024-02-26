#include <bits/stdc++.h>
using namespace std;

/**
 * Vérifie si deux chaînes sont des anagrammes en utilisant la méthode de comptage des caractères.
 * @param str1 La première chaîne.
 * @param str2 La deuxième chaîne.
 * @return Vrai si les chaînes sont des anagrammes, faux sinon.
 */
bool sontAnagrammes1(string str1, string str2)
{
    // Tableau pour stocker le nombre d'occurrences de chaque caractère de taille 256 (caractères ASCII)
    int count[256] = {0};

    if (str1.length() != str2.length())
    {
        // Si les deux chaînes n'ont pas la même longueur, elles ne peuvent pas être des anagrammes
        return false;
    }

    /*
    * Parcourir les deux chaînes et incrémenter le compteur pour chaque caractère de la première 
    * chaîne et décrémenter le compteur pour chaque caractère de la deuxième chaîne
    */
    for (int i = 0; i < str1.length(); i++) 
    {
        count[str1[i]]++;
        count[str2[i]]--;
    }

    // Si les deux chaînes sont des anagrammes, le tableau de comptage doit être rempli de zéros
    for (int i = 0; i < 256; i++)
    {
        if (count[i])
        {
            return false;
        }
    }

    return true;
}

/**
 * Vérifie si deux chaînes sont des anagrammes en utilisant la méthode de comptage des caractères avec optimisation de l'espace.
 * @param str1 La première chaîne.
 * @param str2 La deuxième chaîne.
 * @return Vrai si les chaînes sont des anagrammes, faux sinon.
 */
bool sontAnagrammes2(string str1, string str2)
{
    // Tableau pour stocker le nombre d'occurrences de chaque caractère de taille 256 (caractères ASCII)
    int count[256] = {0};

    // Nombre de caractères différents entre les deux chaînes
    int diff = 0;

    // Si les deux chaînes n'ont pas la même longueur, elles ne peuvent pas être des anagrammes
    if (str1.length() != str2.length())
    {
        return false;
    }

    // Parcourir les deux chaînes et incrémenter le compteur pour chaque caractère de la première
    for (int i = 0; i < str1.length(); i++) 
    {
        /*
        * Si le compteur pour le caractère de la première chaîne est 0, 
        * cela signifie que le caractère n'a pas été rencontré auparavant
        */
        if (count[str1[i]]++ == 0)
        {
            diff++;
        }

        /*
        * Si le compteur pour le caractère de la deuxième chaîne est 1,
        * cela signifie que le caractère a été rencontré dans la première chaîne 
        */
        if (count[str2[i]]-- == 1) 
        {
            diff--;
        }
    }

    return diff == 0;
}

int main()
{
    // Cas de test 1: Deux chaînes vides sont des anagrammes
    assert(sontAnagrammes2("", "") == true);

    // Cas de test 2: Deux chaînes identiques sont des anagrammes
    assert(sontAnagrammes2("abc", "abc") == true);

    // Cas de test 3: Deux chaînes avec les mêmes caractères mais dans un ordre différent sont des anagrammes
    assert(sontAnagrammes2("abc", "cba") == true);

    // Cas de test 4: Deux chaînes avec des caractères différents ne sont pas des anagrammes
    assert(sontAnagrammes2("abc", "def") == false);

    // Cas de test 5: Deux chaînes avec le même ensemble de caractères mais des comptes différents ne sont pas des anagrammes
    assert(sontAnagrammes2("aabc", "abc") == false);

    // Cas de test 6: Les chaînes avec des caractères en majuscules et minuscules ne sont pas des anagrammes
    assert(sontAnagrammes2("abc", "ABC") == false);

    cout << "Tous les tests ont réussi.\n";

    return 0;
}