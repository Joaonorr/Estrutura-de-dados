#include <iostream>
#include <vector>
using namespace std;


void show(vector<string> mat){
    for(int l = 0; l < (int) mat.size(); l++)
        cout << mat[l] << "\n";
}

void tocar_fogo(vector<string> &mat, int l, int c){
    int nl = mat.size();
    int nc = mat[0].size();

    if(mat[l][c] == '.'){
        return;
    }

    if(l+1 < nl && mat[l+1][c] == '#'){
        mat[l+1][c] = 'o';
        tocar_fogo(mat, l+1, c);
    }
    if(l-1 >= 0 && mat[l-1][c] == '#'){
        mat[l-1][c] = 'o';
        tocar_fogo(mat, l-1, c);
    }
    if(c+1 < nc && mat[l][c+1] == '#'){
        mat[l][c+1] = 'o';
        tocar_fogo(mat, l, c+1);
    }
    if(c-1 >= 0 && mat[l][c-1] == '#'){
        mat[l][c-1] = 'o';
        tocar_fogo(mat, l, c-1);
    }

    return;
}

int main(){
    int nl = 0, nc = 0, lfire = 0, cfire = 0;
    scanf("%d %d %d %d\n", &nl, &nc, &lfire, &cfire);
    vector<string> mat;
    for(int l = 0; l < nl; l++){
        string line;
        cin >> line;
        mat.push_back(line);
    }
    tocar_fogo(mat, lfire, cfire);
    show(mat);
}