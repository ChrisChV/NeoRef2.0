#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3){
        cout<<"Escriba la ruta del archivo y el nombre del archivo de salida";
        return 0;
    }
    string file (argv[1]);
    string temp(argv[2]);
    string out = "NeoRef/latex/" + temp + ".tex";
    ifstream archivo(file.c_str(), ios::in);
    ofstream ltx(out.c_str(), ios::out);
    ltx<<"\\documentclass[a4paper,12pt]{article}"<<endl;
    ltx<<"\\usepackage[utf8]{inputenc}"<<endl;
    ltx<<"\\usepackage[spanish]{babel}"<<endl;
    ltx<<"\\usepackage{epstopdf}"<<endl;
    ltx<<"\\begin{document}"<<endl;
    ltx<<"\\begin{tabular}{| l | l | l | l | l | l | l | l |}"<<endl;
    ltx<<"\\hline"<<endl;
    ltx<<"Referido & L & M & M & J & V & S & D \\\\ \\hline"<<endl;
    char line[200];
    while(archivo.getline(line,200)){
        string referido(line);
        for(auto iter = referido.begin(); iter != referido.end() and *iter != ','; ++iter){
            ltx<<*iter;
        }
        ltx<<" & & & & & & & \\\\ \\hline"<<endl;
    }
    ltx<<"\\end{tabular}"<<endl;
    ltx<<"\\end{document}"<<endl;
    archivo.close();
    ltx.close();
    string comando = "pdflatex " + out;
    system(comando.c_str());
}
