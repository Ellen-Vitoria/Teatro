#ifndef CLASSTEATRO_H_INCLUDED
#define CLASSTEATRO_H_INCLUDED
#include <iostream>

using namespace std;

template <typename Tipo>

class Teatro{

private:
    int linha;
    int coluna;
    int tamanho;
    Tipo *lugar;

public:
    //Função incializadora;
    Teatro(int lin, int col){
        linha = lin;
        coluna = col;
        tamanho = linha * coluna;
        lugar = new Tipo[tamanho];
    }

    ~Teatro() {
        delete []lugar;
    }

    void resetarLugar(int i, int j)
    {
        lugar[i*coluna+j] = 0;
        //cout << lugar[i*coluna+j] << "   ";
    }

    void mostrarLugares(int lin, int col)
    {
        cout << "\n\t\t\t\t\t   POLTRONAS\n";
        //cout << "\n\t\t\t    1     2     3     4     5     6     7     8\n";
        for(int j=0; j<col; j++)
        {
            if(j==0)
            {
                cout << "\n\t\t\t    " << j+1 << "     ";
            }
            else
            {
                cout << "" << j+1 << "     ";
            }
        }
        cout << "\n\t\t     _______________________________________________________\n\t\t     |\n";

        //Organização das Fileiras
        for (int i=0; i<lin; i++){
            if(i==2)
            {
                cout << "    FILEIRAS      " << i+1 << "  |  ";
            }
            else
            {
                cout << "                  " << i+1 << "  |  ";
            }
            for (int j=0; j<col; j++){
                cout << "    " << lugar[i*coluna+j] << " ";
            }
        cout<<endl;
        }
    }

    void inserirLugar(int i, int j)
    {
        lugar[i*coluna+j] = 1;
    }

    void trocarLugar(int iAnterior, int jAnterior, int iAtual, int jAtual)
    {
        lugar[iAnterior*coluna+jAnterior] = 0;
        lugar[iAtual*coluna+jAtual] = 1;
    }

    Tipo getPosicao(int i, int j)
    {
        return lugar[i*coluna+j];
    }
};





#endif // CLASSTEATRO_H_INCLUDED
