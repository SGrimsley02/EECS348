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

int** matrixAdd(int** matrix1, int** matrix2, int size){
    //Initialize empty matrix
    int** addMatrix = new int*[size];
    for (int i=0; i<size; ++i){
        addMatrix[i] = new int[size];
    }
    //Perform addition
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            addMatrix[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    return addMatrix;
}

int** matrixMult(int** matrix1, int** matrix2, int size){
    //Initialize empty matrix
    int** multMatrix = new int*[size];
    for (int i=0; i<size; ++i){
        multMatrix[i] = new int[size];
    }
    //Perform matrix multiplication
    for (int i=0; i<size; ++i){
        for (int j=0; j<size; ++j){
            for (int k=0; k<size; ++k){
                multMatrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    //Return new matrix
    return multMatrix;
}

int** matrixSub(int** matrix1, int** matrix2, int size){
    //Initialize empty matrix
    int** subMatrix = new int*[size];
    for (int i=0; i<size; ++i){
        subMatrix[i] = new int[size];
    }
    //Perform addition
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            subMatrix[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
    
    return subMatrix;
}

int updateMatrix(int** matrix, int row, int col, int size, int val){
    matrix[row-1][col-1] = val;
    return 0;
}

int getMax(int** matrix, int size){
    int max = matrix[0][0];
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            if (matrix[i][j] > max){
                max = matrix[i][j];
            }
        }
    }
    return max;
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
    int** addMatrix = matrixAdd(matrix1, matrix2, size);
    printMatrix(addMatrix, size);


    cout << "4. Multiply two matrices\n";
    int** multMatrix = matrixMult(matrix1, matrix2, size);
    printMatrix(multMatrix, size);


    cout << "5. Subtract Matrix2 from Matrix1\n";
    int** subMatrix = matrixSub(matrix1, matrix2, size);
    printMatrix(subMatrix, size);



    cout << "6. Update first matrix\n";
    int row, col, val;
    cout << "Row: ";
    cin >> row;
    cout << "Column: ";
    cin >> col;
    cout << "Value: ";
    cin >> val;
    if (row > size || col > size){
        cout << "Invalid index";
    } else {
        updateMatrix(matrix1, row, col, size, val);
        printMatrix(matrix1, size);
    }


    cout << "7. Get max of matrix\n";
    
    int max = getMax(matrix1, size);
    cout << max << endl;
    



    cout << "8. Transpose matrix\n";
    

    return 0;
}