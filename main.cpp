#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include "classTeatro.h"

using namespace std;

int main()
{
    //Definindo a Matriz de Lugares
    int linha = 5;
    int coluna = 8;
    Teatro<int> tl(linha, coluna);

    //Resetando todos os Lugares
    for (int i=0; i<linha; i++){
        for (int j=0; j<coluna; j++){
            tl.resetarLugar(i, j);
        }
    }

    setlocale(LC_ALL, "Portuguese");
    int esc;
    int fileira, f2;
    int poltrona, p2;
    for( ; ; )
    {
        cout << "\n                        T E A T R O         \n";
        cout << "        __________________________________________\n\n";
        cout << "          |   1   |     Comprar o Ingresso     |\n";
        cout << "          |   2   |     Devolver o Ingresso    |\n";
        cout << "          |   3   |     Trocar de Lugar        |\n";
        cout << "          |   4   |     Finalizar Aplicação    |\n";
        cout << "        __________________________________________\n";
        cout << "\n\tFaça sua Escolha: ";
        cin >> esc;

        system("cls");

        switch(esc){
            //Comprar Ingresso e Reservar Lugar:
            case 1:
                do{
                    do{
                        tl.mostrarLugares(linha, coluna);
                        cout << "\n\n\n    Informe a Fileira (1 a 5): ";
                        cin >> fileira;
                        fileira--; //A Fileira se inicia em 1

                        //Caso Fileira não existir
                        if(fileira<0 || fileira>linha)
                        {
                            system("cls");
                        }
                    }
                    while(fileira<0 || fileira>linha);

                    do{
                        cout << "\n\n    Informe a Poltrona (1 a 8): ";
                        cin >> poltrona;
                        poltrona--; //A Poltrona se inicia em 1

                        //Caso Poltrona não existir
                        if(poltrona<0 || poltrona>coluna)
                        {
                            cout << "    Não é possível Localizar essa Poltrona!";
                        }
                    }
                    while(poltrona<0 || poltrona>coluna);

                    //Lugar já Ocupado
                    if(tl.getPosicao(fileira, poltrona) == 1)
                    {
                        system("cls");
                        cout << "        _______________________________________________________________\n\n";
                        cout << "             Esse Lugar já está Ocupado. Por favor, escolha outro!\n";
                        cout << "        _______________________________________________________________\n\n\n";
                        system("pause");
                        system("cls");
                    }
                }
                while(tl.getPosicao(fileira, poltrona) == 1);

                //Reservar Lugar inserido pelo Usuário
                tl.inserirLugar(fileira, poltrona);

                //Mostrar Lugares Atualizado
                system("cls");
                tl.mostrarLugares(linha, coluna);
                cout << "\n\n\n\t\t\t\t    O Ingresso foi Vendido!\n\n\n\n\n";
                system("pause");
                break;
       /****************************************************************************************/

            //Devolver Ingresso:
            case 2:
                do{
                    do{
                        tl.mostrarLugares(linha, coluna);
                        cout << "\n\n\n    Informe a Fileira (1 a 5): ";
                        cin >> fileira;
                        fileira--; //A Fileira se inicia em 1

                        //Caso Fileira não existir
                        if(fileira<0 || fileira>linha)
                        {
                            system("cls");
                        }
                    }
                    while(fileira<0 || fileira>linha);

                    do{
                        cout << "\n\n    Informe a Poltrona (1 a 8): ";
                        cin >> poltrona;
                        poltrona--; //A Poltrona se inicia em 1

                        //Caso Poltrona não existir
                        if(poltrona<0 || poltrona>coluna)
                        {
                            cout << "    Não é possível Localizar essa Poltrona!";
                        }
                    }
                    while(poltrona<0 || poltrona>coluna);

                    //Lugar vazio
                    if(tl.getPosicao(fileira, poltrona) == 0)
                    {
                        system("cls");
                        cout << "        _______________________________________________________________\n\n";
                        cout << "             Esse Lugar está Vazio. Por favor, informe outro Lugar!\n";
                        cout << "        _______________________________________________________________\n\n\n";
                        system("pause");
                        system("cls");
                    }
                }
                while(tl.getPosicao(fileira, poltrona) == 0);

                //Resetar Lugar
                tl.resetarLugar(fileira, poltrona);

                //Mostrar Lugares Atualizado
                system("cls");
                tl.mostrarLugares(linha, coluna);
                cout << "\n\n\n\t\t\t\t    O Ingresso foi Devolvido!\n\n\n\n\n";
                system("pause");
                break;
        /****************************************************************************************/

            //Realizar Troca de Lugar:
            case 3:
                tl.mostrarLugares(linha, coluna);
                do{
                    cout << "\n\n\n    Informe a Fileira Atual (1 a 5): ";
                    cin >> fileira;
                    fileira--; //A Fileira se inicia em 1

                    //Caso Fileira não existir
                    if(fileira<0 || fileira>linha)
                    {
                        system("cls");
                    }
                }
                while(fileira<0 || fileira>linha);

                do{
                    cout << "\n\n    Informe a Poltrona Atual (1 a 8): ";
                    cin >> poltrona;
                    poltrona--; //A Poltrona se inicia em 1

                    //Caso Poltrona não existir
                    if(poltrona<0 || poltrona>coluna)
                    {
                        cout << "    Não é possível Localizar essa Poltrona!";
                    }
                }
                while(poltrona<0 || poltrona>coluna);

                cout << "\n    _________________________________________________";

                do{
                    do{
                        cout << "\n\n\n    Informe a Nova Fileira (1 a 5): ";
                        cin >> f2;
                        f2--; //A Fileira se inicia em 1

                        //Caso Fileira não existir
                        if(f2<0 || f2>linha)
                        {
                            system("cls");
                        }
                    }
                    while(f2<0 || f2>linha);

                    do{
                        cout << "\n\n    Informe a Nova Poltrona (1 a 8): ";
                        cin >> p2;
                        p2--; //A Poltrona se inicia em 1

                        //Caso Poltrona não existir
                        if(p2<0 || p2>coluna)
                        {
                            cout << "    Não é possível Localizar essa Poltrona!";
                        }
                    }
                    while(p2<0 || p2>coluna);

                    //Caso Lugar já Ocupado
                    if(tl.getPosicao(f2, p2) == 1)
                    {
                        system("cls");
                        cout << "        _______________________________________________________________\n\n";
                        cout << "             Esse Lugar já está Ocupado. Por favor, escolha outro!\n";
                        cout << "        _______________________________________________________________\n\n\n";
                        system("pause");
                        system("cls");
                        tl.mostrarLugares(linha, coluna);
                    }
                }
                while(tl.getPosicao(f2, p2) == 1);

                //Trocar Lugar
                tl.trocarLugar(fileira, poltrona, f2, p2);

                //Mostrar Lugares Atualizado
                system("cls");
                tl.mostrarLugares(linha, coluna);
                cout << "\n\n\n\t\t\t\t      O Lugar foi Trocado!\n\n\n\n\n";
                system("pause");
                break;
        /****************************************************************************************/

            //Finalizar a Aplicação:
            case 4:
                cout << "\n                        T E A T R O         \n";
                cout << "        __________________________________________\n\n";
                cout << "                  Tenha um Bom Espetáculo!\n";
                cout << "        __________________________________________\n\n\n";
                return 0;
                break;
        /****************************************************************************************/

            //Caso seja inserido um Número Diferente
            default:
                system("cls");
                continue;
        }
        system("cls");
    }
}
