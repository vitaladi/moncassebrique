#include "meilleursScore.h"

//constructeur
meilleursScore::meilleursScore() :
    d_meilleursScore{}
{
    d_meilleursScore.reserve(NB_MEILLEURSSCORE);
}

//capacité
int meilleursScore::capacite () const
{
    return d_meilleursScore.capacity();
}

//taille
int meilleursScore::taille() const
{
    return d_meilleursScore.size();
}

//recupere le joueur en i
joueur* meilleursScore::joueurEn(int i)
{
  return d_meilleursScore[i].get();
}

//ajoute un joueur aux meilleurs score
void meilleursScore::ajouteJoueurAuxMeilleursScore(std::unique_ptr <joueur> j)
{
    d_meilleursScore.push_back(std::move(j));
}

//tri à bulles
void meilleursScore::triMeilleursScore()
{
    bool en_desordre = true;
	for (unsigned int i = 0; i < d_meilleursScore.size() && en_desordre; ++i)
	{
		en_desordre = false;
		for (unsigned int j = 1; j < d_meilleursScore.size() - i; ++j)
			if (d_meilleursScore[j-1]->getScore() < d_meilleursScore[j]->getScore())
			{
				std::swap(d_meilleursScore[j], d_meilleursScore[j-1]);
				en_desordre = true;
 			}
	}
}

//reduit la liste des meilleurs score pour ne garder que les NB_MEILLEURSSCORE meilleurs score
void meilleursScore::reduitListeMeilleursScore()
{
    while (d_meilleursScore.size()>NB_MEILLEURSSCORE)
    {
        d_meilleursScore.pop_back();
    }
}

//récupère les meilleurs score dans le fichier texte nomFichierIN pour les restocker dans le tableau des meilleurs score
void meilleursScore::recupereMeilleursScore(const string &nomFichierIN)
{
    std::ifstream fIN(nomFichierIN+".txt");
    if (!fIN)
    {
        return;
    }
    int classement, score;
    std::string nom, chaine;
    char ponct;
    while (fIN.eof()==false)
    {
        fIN>>classement>>ponct>>nom>>ponct>>chaine>>ponct>>score;
        auto j=std::make_unique<joueur>(nom);
        j->setScore(score);
        d_meilleursScore.push_back(std::move(j));
    }
}

//affiche les meilleurs score dans le fichier texte nomFichierOUT
void meilleursScore::afficheMeilleursScore(const string &nomFichierOUT) const
{
    std::ofstream fOUT(nomFichierOUT+".txt");
    int i=1;
     for (const auto& c:d_meilleursScore)
        {
            fOUT<<i<<" : ";
            c->afficheJoueur(fOUT);
            i++;
        }
}

/*mise à jour des meilleurs scores :
fonction englobant les différentes méthodes nécessaires pour ajouter ou non
aux meilleurs score le score d'un joueur à la fin d'une partie
et l'afficher dans le fichier texte nomFichier
(c'est la seule fonction qui sera appelée dans le programme principal à la fin d'une partie d'un joueur)
*/
void meilleursScore::miseAJourMeilleursScore(const string &nomFichier, std::unique_ptr <joueur> j)
{
    recupereMeilleursScore(nomFichier);
    ajouteJoueurAuxMeilleursScore(std::move(j));
    triMeilleursScore();
    if (taille()>NB_MEILLEURSSCORE)
        reduitListeMeilleursScore();
    afficheMeilleursScore(nomFichier);
}
