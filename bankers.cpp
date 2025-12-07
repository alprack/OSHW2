#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;


int main(int argc, char* argv[]){
    //check user provided text file
    if(argc < 2){
        cerr << "Input file" << endl;
        cerr << "ex: ./bankers input.txt" << endl;
        cerr << "See README" << endl;
        return 1;
    }

    //open file
    ifstream fin(argv[1]);
    if (!fin) {
        cerr << "Could not open file.\n";
        return 1;
    }

    int numProcess = 0;
    int numResource = 0;
    //read number of processes and resource
    fin >> numProcess >> numResource;

    //construct vectors
    vector<vector<int>> allocation(numProcess, vector<int>(numResource));
    vector<vector<int>> max(numProcess, vector<int>(numResource));
    vector<int> available(numResource);

    //read allocation matrix
    for(int i = 0; i < numProcess; i++)
        for(int j = 0; j < numResource; j++)
            fin >> allocation[i][j];

    //read max matrix
    for(int i = 0; i < numProcess; i++)
        for(int j = 0; j < numResource; j++)
            fin >> max[i][j];

    //read available vector
    for(int j = 0; j < numResource; j++)
        fin >> available[j];

    vector<bool> processDone (numProcess, false);
    vector<vector<int>> need(numProcess, vector<int>(numResource));
    vector<int> safeProcessOrder(numProcess);
    int numProcessDone = 0;

    //build need matrix
    for(int i = 0; i < numProcess; ++i){
        for(int j = 0; j < numResource; ++j){
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    //banker's algorithm
    for(int i = 0; i < numProcess; ++i){
        for(int process = 0; process < numProcess; ++process ){
            if(!processDone[process]){
                bool enoughResource = true;
                for(int i = 0; i < numResource; ++i){
                    if(need[process][i] > available[i]){
                        enoughResource = false;
                        break;
                    }
                }
                //can complete process if enough resources
                if(enoughResource){
                    //record process to make safe order
                    safeProcessOrder[numProcessDone] = process;
                    ++numProcessDone;
                    //allocated resources from done processes to avaiable
                    for(int j = 0; j < numResource; ++j){
                        available[j] += allocation[process][j];
                    }
                    processDone[process] = true;
                }
            }
        }
    }

    //print results
    if(numProcessDone == numProcess){
        cout << "Safe order of process:" << endl;
        for(int i = 0; i < numProcess; ++i){
            cout << "P" << safeProcessOrder[i];
            if(i + 1 < numProcess) cout << ", ";
        }
        cout << endl;
    } else {
        cout << "No safe order of processes" << endl;
    }

    return 0;
}