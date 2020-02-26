#include <iostream>
#include <math.h>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <cmath>


using namespace std;

int main(int argc, char* argv[])
{
  int sum = 0;
  double avg = 0.0;
  double variance = 0.0;
  double stdDev = 0.0;
  double numLines = 0.0;
  double countA = 0.0;
  double countG = 0.0;
  double countC = 0.0;
  double countT = 0.0;
  double countAA = 0.0;
  double countAC = 0.0;
  double countAG = 0.0;
  double countAT = 0.0;
  double countCA = 0.0;
  double countCC = 0.0;
  double countCG = 0.0;
  double countCT = 0.0;
  double countGA = 0.0;
  double countGC = 0.0;
  double countGG = 0.0;
  double countGT = 0.0;
  double countTA = 0.0;
  double countTC = 0.0;
  double countTG = 0.0;
  double countTT = 0.0;
  double probabilityA = 0.0;
  double probabilityC = 0.0;
  double probabilityG = 0.0;
  double probabilityT = 0.0;
  string check = "";
  float probabilityAA = 0.0;
  float probabilityAC = 0.0;
  float probabilityAG = 0.0;
  float probabilityAT = 0.0;
  float probabilityCA = 0.0;
  float probabilityCC = 0.0;
  float probabilityCG = 0.0;
  float probabilityCT = 0.0;
  float probabilityGA = 0.0;
  float probabilityGC = 0.0;
  float probabilityGG = 0.0;
  float probabilityGT = 0.0;
  float probabilityTA = 0.0;
  float probabilityTC = 0.0;
  float probabilityTG = 0.0;
  float probabilityTT = 0.0;
  int lineL;
  double a = 0.0;
  double b = 0.0;
  double C = 0.0;
  float D = 0.0;
  string sample = "ACGT";
  string dna = "";
  char decision = 'y';
  string newFile = "";

  while (decision == 'y' || decision == 'Y')
  {
    if (argc != 2) // the number of arguments in the command line should be 2 (program name and name of file being read).
      cout<<"You entered: "<< argv[0] <<" Enter the name of the file \n"; // when they only enter the program name

    else
    {
      ifstream inputFile (argv[1]); // the second argument they provide should be the file we want to read in
      if (!inputFile.is_open())
        cout <<"The file did not open\n"; // checking to see if the file was opened

      else
      {
        string line;

        while(getline(inputFile, line)) // gets line until there are no strings left to get
        {
          for (int k = 0; k < line.length(); ++k)
          {
            line[k] = tolower(line[k]);
          }

          // cout << line << '\n';
        }

        inputFile.close();
        inputFile.open(argv[1]);

        while(getline(inputFile, line))
        {
          for (int i = 0; i <= line.length(); ++i)
          {
            if (line[i] == 'A')
            {
              ++countA;
            }

            if (line[i] == 'C')
            {
              ++countC;
            }

            if (line[i] == 'G')
            {
              ++countG;
            }

            if (line[i] == 'T')
            {
              ++countT;
            }

          }

          numLines += 1;
          sum = countA + countC + countG + countT;
          avg = sum / numLines;
          variance += pow(line.length() - avg, 2);
          stdDev = sqrt(variance);
          probabilityA = countA / sum;
          probabilityC = countC / sum;
          probabilityG = countG / sum;
          probabilityT = countT / sum;

        }

        /* inputFile.close();
        inputFile.open(argv[1]);

        while(getline(inputFile, line))
        {
          variance += pow(line.length() - avg, 2);
          stdDev = sqrt(variance);
        } */

        inputFile.close();
        inputFile.open(argv[1]);
        while(getline(inputFile, line))
        {
          for (int j = 0; j <= line.length(); ++j)
          {
            if (line.substr(j, 2) == "AA")
            {
              ++countAA;
            }

            if (line.substr(j, 2) == "AC")
            {
              ++countAC;
            }

            if (line.substr(j, 2) == "AG")
            {
              ++countAG;
            }

            if (line.substr(j, 2) == "AT")
            {
              ++countAT;
            }

            if (line.substr(j, 2) == "CA")
            {
              ++countCA;
            }

            if (line.substr(j, 2) == "CC")
            {
              ++countCC;
            }

            if (line.substr(j, 2) == "CG")
            {
              ++countCG;
            }

            if (line.substr(j, 2) == "CT")
            {
              ++countCT;
            }

            if (line.substr(j, 2) == "GA")
            {
              ++countGA;
            }

            if (line.substr(j, 2) == "GC")
            {
              ++countGC;
            }

            if (line.substr(j, 2) == "GG")
            {
              ++countGG;
            }

            if (line.substr(j, 2) == "GT")
            {
              ++countGT;
            }

            if (line.substr(j, 2) == "TA")
            {
              ++countTA;
            }

            if (line.substr(j, 2) == "TC")
            {
              ++countTC;
            }

            if (line.substr(j, 2) == "TG")
            {
              ++countTG;
            }

            if (line.substr(j, 2) == "TT")
            {
              ++countTT;
            }
          }

          probabilityAA = countAA / sum;
          probabilityAC = countAC / sum;
          probabilityAG = countAG / sum;
          probabilityAT = countAT / sum;
          probabilityCA = countCA / sum;
          probabilityCC = countCC / sum;
          probabilityCG = countCG / sum;
          probabilityCT = countCT / sum;
          probabilityGA = countGA / sum;
          probabilityGC = countGC / sum;
          probabilityGG = countGG / sum;
          probabilityGT = countGT / sum;
          probabilityTA = countTA / sum;
          probabilityTC = countTC / sum;
          probabilityTG = countTG / sum;
          probabilityTT = countTT / sum;

        }

        inputFile.close();
        ofstream outputFile ("KodyNihei.out");

        srand (time(NULL));
        a = ((double)rand()/(double)RAND_MAX);
        b = ((double)rand()/(double)RAND_MAX);

        //cout << a << '\n';
        //cout << b << '\n';
        C = sqrt(-2 * log(a)) * (cos(2 * M_PI * b));
        D = (stdDev * C) + avg;

        for (int t = 0; t <= 1000; ++t)
        {
          for (int f = 0; f <= D; ++f)
          {
            dna += sample[rand() % 4];
          }
        }

        if (outputFile.is_open())
        {
          outputFile << "Name: Kody Nihei\n";
          outputFile << "Student ID: 2276423\n";
          outputFile << "The sum of the length of the DNA strings is: " << sum << '\n';
          outputFile << "The mean of the length of the DNA strings is " << avg << '\n';
          outputFile << "The variance of the length of the DNA strings is: " << variance << '\n';
          outputFile << "The standard deviation of the length of the DNA strings is " << stdDev << '\n';
          outputFile << "Here is the probability of each nucleotide:" << '\n';
          outputFile << "A: " << probabilityA << '\n';
          outputFile << "C: " << probabilityC << '\n';
          outputFile << "G: " << probabilityG << '\n';
          outputFile << "T: " << probabilityT << '\n';
          outputFile << "Here is the probability of each nucleotide bigram: " << '\n';
          outputFile << "AA: " << probabilityAA << '\n';
          outputFile << "AC: " << probabilityAC << '\n';
          outputFile << "AG: " << probabilityAG << '\n';
          outputFile << "AT: " << probabilityAT << '\n';
          outputFile << "CA: " << probabilityCA << '\n';
          outputFile << "CC: " << probabilityCC << '\n';
          outputFile << "CG: " << probabilityCG << '\n';
          outputFile << "CT: " << probabilityCT << '\n';
          outputFile << "GA: " << probabilityGA << '\n';
          outputFile << "GC: " << probabilityGC << '\n';
          outputFile << "GG: " << probabilityGG << '\n';
          outputFile << "GT: " << probabilityGT << '\n';
          outputFile << "TA: " << probabilityTA << '\n';
          outputFile << "TC: " << probabilityTC << '\n';
          outputFile << "TG: " << probabilityTG << '\n';
          outputFile << "TT: " << probabilityTT << '\n';
          outputFile << dna << '\n';

          outputFile.close();
        }

        else
        {
          cout << "Unable to open file.";
        }

        cout << "Do you want to process another program? (y/n)" << '\n';
        cin >> decision;

        if (decision == 'n' || decision == 'N')
        {
          break;
        }

        else
        {
          cout << "Enter file name: " << '\n';
          cin >> newFile;
          continue;
        }
      }
    }
  }
}
