#include <iostream>
#include <fstream>
using namespace std;

int getMatrixSize(const string& filename){
    //Open file
    ifstream inputFile(filename);
    if (!inputFile.is_open()) { //Check that it opened
        cerr << "Error opening file." << endl;
        return 0; // Return 0 if file cannot be opened
    }
    //Get size
    int size;
    inputFile >> size;
    inputFile.close();
    //Return size
    return size;
}

int** getMatrix(string filename, int size, int matrixNum){
    //Initialize an empty matrix of size
    int** matrix = new int*[size];
    for (int i=0; i<size; ++i){
        matrix[i] = new int[size];
    }
    //Open the file
    ifstream inputFile(filename);

    string line; //Skip first line (size line)
    getline(inputFile, line);
    //If second matrix, skip the first matrix
    if (matrixNum == 2){ 
        for (int i = 0; i<size; i++){
            getline(inputFile, line);
        }
    }
    //Add values to the matrix
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            inputFile >> matrix[i][j];
        }
    }
    //Close file
    inputFile.close();
    //Return new matrix
    return matrix;
}

int printMatrix(int** matrix, int size){
    for (int i = 0; i < size; ++i) { //for row
        for (int j = 0; j < size; ++j) { //for col
            cout << matrix[i][j] << " "; //add to the output
        }
        cout << endl; //next line
    }
    return 0;
}

int main(){

    cout << "1. Get matrices\n";

    string filename;
    cout << "Filename: ";
    cin >> filename;
    static int size = getMatrixSize(filename);
    int** matrix1 = getMatrix(filename, size, 1);
    int** matrix2 = getMatrix(filename, size, 2);
    

    cout << "2. Print matrices\n";
    cout << "Matrix 1:\n";
    printMatrix(matrix1, size);
    cout << "Matrix 2:\n";
    printMatrix(matrix2, size);


    cout << "3. Add two matrices\n";



    cout << "4. Multiply two matrices\n";



    cout << "5. Subtract Matrix2 from Matrix1\n";





    cout << "6. Update first matrix\n";






    cout << "7. Get max of matrix\n";






    cout << "8. Transpose matrix\n";
    

    return 0;
}