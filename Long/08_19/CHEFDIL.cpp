/* Problem link: https://www.codechef.com/AUG19B/problems/CHEFDIL
    Author: Vinay Somawat
    Webpage: http://vinaysomawat.github.io/
    Contest: CodeChef Auguest Long challange
*/

#include<bits/stdc++.h>
using namespace std;


auto flip_cards(const std::vector<unsigned>& b) {
    bool higher{false};
    unsigned sz = b.size();
    std::list<unsigned> solution;
    auto lit = solution.begin();
    for (unsigned i{0}; i < sz; i++) {
        if (higher)
            solution.emplace_back(i);
        else {
            solution.emplace(next(lit, i), i);
        }
        higher ^= (b[i] == 1);
    }
    return solution;
}

void play_game(string str) {
    if (!(std::count_if(cbegin(str), cend(str), [](const char c) { return c == '1';}) & 1)) {
        std::cout << "LOSE"; 
        return;
    }
    std::vector<unsigned> cards;
    std::transform(cbegin(str), cend(str), std::back_inserter(cards), [](const char c) { return (c == '1' ? 1 : 0);});
    std::cout << "WIN"; 
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        cin>>s1;
        play_game(s1);
        cout<<endl;
    }
    return 0;
}