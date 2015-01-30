    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <iostream>
    #include <iterator>
    #include <string>

    using namespace std;

int intoInt(string line)
{ //48 57
    int res = 0;
    for (unsigned int u = 0; u<line.size(); u++)
    {
        char tmp = line.at(u);
        //cout << " lettre" << tmp << " -> " << (int)tmp << endl;
        if (((int)tmp>47) && ((int)tmp<58) )
        {

            int other = tmp - '0';
            res = res*10 + other;
        }
    }
    return res;
}

vector< vector<int> > extractData(char * fileName)
{
    vector< vector<int> > vertical;
    string ligne;

    //On ouvre le fichier.
    ifstream fichier(fileName);

    // On vérifie si le fichier existe.
    if(fichier)
    {
    //L'ouverture s'est bien passée, on peut donc lire.
    // La variable ligne.
    std::string Line;
    // On lit la première ligne.
    std::getline(fichier,ligne);
    // On l'affiche.
    //std::cout << ligne << std::endl;
    int nbLigne =0;

        // On lit la ligne suivante.
        while (getline(fichier,Line))
        {

        vector<int> horizontal;
        std::size_t pos;
        string ligne = Line;

        // On l'affiche.
        //std::cout << ligne << std::endl;

        while (ligne.size()>5) // On s'arrête avent qu'il y ait un problème.
        {
            // On affiche la ligne
            //cout << endl << ligne << endl;
            // On cherche l'enplacement de la tabulation.
            pos = ligne.find("\t") ;
            // On affiche l'emplacement de la tabulation.
            //cout << pos << " " ;

            if (pos > ligne.size() )// On sort du while si ya un problème
                break;

            // On découpe la ligne à l'emplacementde la tabulation.
            string deb = ligne.substr(1,pos);
            // On ajoute ce morceau au vecteur représentant la ligne
            int elem = intoInt(deb);
            horizontal.push_back(elem);
            // On affiche le morceau
            //cout << " [" << deb << "] " ;
            // On prend le reste de la ligne.
            string res = ligne.substr(pos+1);
            // On affecte ligne.
            ligne = res;
            // on affiche la taille de la nouvelle ligne
            //cout << ligne.size();

        }

        // Le reste de la ligne -> une dernière colonne.
        //cout << endl;
        int fin = intoInt(ligne);
        horizontal.push_back(fin);
        vertical.push_back(horizontal);
        nbLigne++;

        }

    }
    else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }

    return vertical;
}

void afficherTableau(vector< vector<int> > tab)
{
    for( int i=0; i<tab.size(); i++)
    {
        vector<int> vect = tab.at(i);

        for( int j=0; j<vect.size(); j++)
        {
            cout << vect.at(j) << " ";
        }
        cout << "\n";
    }
}

int main()
{
    char * fileName = "faidatanum.txt";
    vector< vector<int> > vertical = extractData(fileName);

    return 0;
}
