#include <bits/stdc++.h>

using namespace std;

string entrada = "B:=C*A*C+B", saida = "<id>:=<exp>", aux = "";
int indice = 0;

void bt(int ind){
        char c = entrada[ind];
        if(c == 'A' || c == 'B' || c == 'C'){
            if(ind == 0){
                aux = "";
                aux += c;
                saida.replace(saida.find("<id>"), 4, aux);
                cout << saida << endl;
                bt(ind+1);
            }
            else{
                bt(ind+1);
                aux = "";
                aux += c;
                indice = saida.find("<id>");
                if(indice == std::string::npos){
                    saida.replace(saida.find("<exp>"), 5, "<id>");
                    cout << saida << endl;
                    bt(ind);
                }
                else{
                    saida.replace(saida.find("<id>"), 4, aux);
                    cout << saida << endl;
                    if(ind+2 < entrada.size()){
                        bt(ind+2);
                    }
                }
            }
        }
        else if(c == '*'){
            saida.replace(saida.find("<exp>"), 5, "<id>*<exp>");
            cout << saida << endl;
        }
        else if(c == '+'){
            saida.replace(saida.find("<exp>"), 5, "<id>+<exp>");
            cout << saida << endl;
        }
        else if(c == ':' || c == '='){
            bt(ind+1);
        }
}

int main() {

    cout << "<atr>" << endl << saida << endl;
    bt(0);
    
    return 0;
}