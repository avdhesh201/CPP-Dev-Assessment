#include <bits/stdc++.h>
using namespace std;

//  read file data into a vector of strings
void openfile(const string& filename, vector<string>& array) {
    ifstream inputfile(filename);
    
    if (!inputfile) {
        cerr << "Error: Unable to open file " << filename << "!" << endl;
        return;
    }
    string line;
    while (getline(inputfile, line))array.push_back(line);
    inputfile.close();
}

//  print data with a label
void printfield(const string& label, const string& value) {
    cout << label << ": " << value << endl;
}

// print a grouped set of values
void printgrouped(const string& label, const vector<string>& values) {
    cout << label << ": [";
    bool first = true;
    for (const auto& x : values) {
        if (!first) cout << ", ";
        cout << x;
        first = false;
    }
    cout << "]" << endl;
}

// process and print a single line of data
void printwithlabels(const string& dataline) {
    stringstream ss(dataline);
    string field;

    getline(ss, field, ',');
    printfield("Time", field);

    vector<vector<string>> fieldvectors(4, vector<string>(5));
    vector<string> labels = { "BidQty", "Bid Prices", "Ask Prices", "Ask Qty" };
    
    // processing the data in the  ds
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 4; ++j) {
            getline(ss, field, ',');
            fieldvectors[j][i] = field;
        }
    }

    for (int i = 0; i < 4; ++i) {
        printgrouped(labels[i], fieldvectors[i]);
    }

    // Read and print remaining fields
    vector<string> additionallabels = { "Open", "High", "Low", "Ltp", "Volume", "Ignore" };
    for (const auto& label : additionallabels) {
        getline(ss, field, ',');
        printfield(label, field);
    }

    // R & p additional fields
    for (int i = 1; i <= 3; ++i) {
        getline(ss, field, ',');
        printfield("Additional Field " + to_string(i), field);
    }
}

// print a single line of data
void print(const string& dataline) {
    printwithlabels(dataline);
    cout << endl;
}

//  ask user if they want to select a new file
bool asknewfile() {
    char choice;
    cout << "No more data to load. Would you like to select a new file (y/n)? ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}

// display menu and load the next line 
bool nextdata(vector<string>& array, int& currentindex) {
    if (currentindex < array.size()) {
        char choice;
        cout << "Do you want to load the nextdata data line (y/n)? ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            print(array[currentindex]);
            currentindex++;
            return (currentindex < array.size()); // Continue only if data is ther e
        }
    }
    return false;
}

// file processing and user interactions
void processfiles(int& filecounter) {
    while (filecounter > 0) {
        string filename;
        cout << "Enter the file path : ";
        cin >> filename;

        vector<string> array;       // CREATING ARRAY  
        
        openfile(filename, array);

        // Check if the file is empty
        if (array.empty()) {
            cerr << "Error: No data available to load from " << filename << "." << endl;
            cout << "Please enter a different filename: ";
            continue;
        }

        int currentindex = 0;

        // Load and display the first data set by default
        print(array[currentindex]);
        currentindex++;

        // allow the user to load additional data line by line
        while (true) {
            bool shouldcontinue = nextdata(array, currentindex);
            if (!shouldcontinue)break; 
        }
        filecounter--;

        // if more files are available
        if (filecounter > 0) {
            if (!asknewfile()) {
                cout << "Exiting program." << endl;
                return;
            }
        } else {
            cout << "No more files are available." << endl;
            return;
        }
    }
}

int main() {
    int filecounter;
    cout << "Enter the number of files to process: ";
    cin >> filecounter;

    if (filecounter <= 0) {
        cerr << "Error: Number of files must be greater than 0." << endl;
        return 1;
    }

    processfiles(filecounter);
    return 0;
}




