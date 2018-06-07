#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

/*
 * Complete the chocolateGame function below.
 */

vector<int> arr;

int solve(int start){
    
    int nim_sum = 0;
    int res = 0;
    map<int,int> Map_defeats;
    Map_defeats.clear();
    //Se a nim sum for igual a 0 já é uma derrota
    Map_defeats[0] = 1;
    //Seleciona apenas as colunas ímpares das diferenças, colunas pares não influenciam o jogo
    //Se a nim sum das colunas ímpares == 0 é uma derrota
    //Quais colunas são as ímpares depende da posição inicial da sequência considerada
    for(int i = start; i >= 0; i -= 2) {
        int chocolates_diff = arr[i];
        if(i > 0) chocolates_diff = arr[i] - arr[i - 1];
        res += Map_defeats[nim_sum ^ arr[i]];
        if(i > 0) res += Map_defeats[nim_sum ^ chocolates_diff];
        nim_sum ^=chocolates_diff;
        Map_defeats[nim_sum]++;
        }
    return res;
}
    
long long chocolateGame() {
    int n = arr.size();
    long long odd, even,defeats, wins;
    //Considerando que a coluna inicial é a última e as variações
    odd = solve(n-1);
    //Considerando que a coluna inicial é a penúltima e as variações
    even = solve(n-2);
    defeats = odd+even;
    wins = (long long) n * (n - 1) / 2 - defeats;
    return wins;
}

int main() {
    int n;
    long long wins;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    
    wins = chocolateGame();
    cout << wins << endl;
    return 0;
}
