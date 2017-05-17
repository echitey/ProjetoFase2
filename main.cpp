#include <iostream>
#include "screen.h"
#include "figurageometrica.h"
#include "reta.h"
#include "retangulo.h"
#include "circulo.h"
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int main(int argc, char *argv[]){

    Screen *t;
    FiguraGeometrica *f;


    ifstream input;
    ofstream output;
    string codigo;
    string file = "entrada.txt";
    string ofile = "saida.txt";

    int nlinhas, ncolunas, largura, altura, x0, y0, x1, y1, raio, fillMode;
    char brush;

    input.open(file.c_str());
    output.open(ofile.c_str());

    if(input.is_open()){
        cout << "Opening The File"<<endl;

        string line;

        while(getline(input, line)){
            stringstream sstream(line);

            sstream >> codigo;

            if(codigo == "dim"){
                sstream >> nlinhas;
                sstream >> ncolunas;
                t = new Screen(nlinhas, ncolunas);
                t->clear();

                if(output.is_open()){
                    output << "Arquivo de saida com "<< nlinhas<< " linhas e "<<ncolunas<<" colunas" <<endl<<endl;;
                }

            }else if(codigo == "brush"){
                sstream >> brush;

                if(!sstream.good()){
                    brush = ' ';
                }
                t->setBrush(brush);

            }else if(codigo == "line"){
                sstream >> x0;
                sstream >> y0;
                sstream >> x1;
                sstream >> y1;
                f = new Reta(x0, y0, x1, y1);
                f->draw(*t);
                cout << *t;
                if(output.is_open()){
                    output << *t <<endl;
                }
                t->clear();
            }else if(codigo == "rectangle"){
                sstream >> x0;
                sstream >> y0;
                sstream >> largura;
                sstream >> altura;
                f = new Retangulo(x0, y0, largura, altura);
                f->draw(*t);
                cout << *t;
                if(output.is_open()){
                    output << *t <<endl;
                }
                t->clear();
            }else if(codigo == "circle"){
                sstream >> x0;
                sstream >> y0;
                sstream >> raio;
                sstream >> fillMode;
                if(fillMode == 0){
                    f = new Circulo(x0, y0, raio, false);
                }else if(fillMode == 1){
                    f = new Circulo(x0, y0, raio, true);
                }
                f->draw(*t);
                cout << *t;
                if(output.is_open()){
                    output << *t <<endl;
                }
                t->clear();

            }
            delete(f);
            codigo.clear();
        }
    }else{
        cout << "File cant be opened"<<endl;
    }
    output.close();
    input.close();



    /*
    cout << "Hello World!" << endl;

    Screen s = Screen(20, 20);
    s.setBrush('*');

    Retangulo r = Retangulo(1, 1, 16, 8);
    r.draw(s);

    //Reta r = Reta(3.0,1.0,3.0,18.0);
    //r.draw(s);

    //Circulo c = Circulo(10, 10,8 ,false);
    //c.draw(s);

    vector< vector<char> > matriz = s.getMat();


    for(int j=0; j< 20; j++){
        for(int i=0; i< 20; i++){
            cout << matriz[i][j];
        }
        cout << endl;
    }

        */
    return 0;
}
