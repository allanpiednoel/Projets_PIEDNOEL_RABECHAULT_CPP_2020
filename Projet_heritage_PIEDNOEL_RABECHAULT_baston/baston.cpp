
#include "baston.h"
#include "individu.h"

baston::baston(){
}

bool baston::match_nul(Individu * ind1, Individu * ind2) {
   //si la différence entre chaque *ind est inférieur à la marge_match_nul, retourne vrai, sinon faux
   if ((ind1->m_skill-ind2->m_skill)>(-Parameters::marge_match_nul)&&(ind1->m_skill-ind2->m_skill<Parameters::marge_match_nul)){
       //qDebug()<<"match nul";
   return true;}
   //qDebug()<<"pas match nul";
   return false;
}

// retourne True si match nul ( ecart de skill < marge_match_nul)
int baston::match(Individu * ind1, Individu * ind2) {
int vainqueur =0;
    if (match_nul(ind1,ind2)==false)
    {

        if(ind1->m_skill>ind2->m_skill){
            vainqueur = 1;
        }
        else if (ind1->m_skill<ind2->m_skill){
            vainqueur = 2;
        }
    }
    return vainqueur;
}

// utilise match_nul comme condition, retourne 1 si * ind1 est gagnant
//et 2 si * ind2 gagnant
void baston::tournoi(int indice_p1, Population * p1, Population * p2) {
//faire combattre un individu d'une famille avec chaques inds de la famille adverse

    //pour chaques membres de la famille, les faire se battre avec l'individu
    foreach (Individu *ind,p2->liste_individu) {
        int vainqueur=match(p1->liste_individu.at(indice_p1),ind);

        //conditions d'attribution des stats
        //si il est vainceur, lui ajouter une victoire
        //sinon, lui ajouter une defaite
        if (vainqueur==1){
            p1->liste_individu.at(indice_p1)->incr_victoires();

            ind->incr_defaites();
        }
        else if (vainqueur ==2) {
            p1->liste_individu.at(indice_p1)->incr_defaites();
            ind->incr_victoires();
        }

    }


}

//faire combattre un individu d'une famille avec chaques inds de la famille adverse
//pour chaques membres de la famille, les faire se battre avec l'individu indice_p1
//attribution des victoires et des défaites de chaques individu
void baston::launchEvo(Population * p1, Population * p2) {
    p1->evolutionnaryProcess();
    p2->evolutionnaryProcess();
}

//sers juste à éxécuter evolutionnaryProcess
int baston::AlphaVsAlpha(Population * p1, Population * p2, Population * alf1, Population * alf2) {
    float totalRatio_1 =0;
    float totalRatio_2 =0;
    //calcul et affichage de la moyenne familiale des ratios
    foreach(Individu *ind, p1->liste_individu)
    {
        totalRatio_1+=ind->Ratio();
    }
    foreach(Individu *ind, p2->liste_individu)
    {
        totalRatio_2+=ind->Ratio();
    }

    totalRatio_1 = totalRatio_1/(NbIndividus-1);
    cout<<endl<<"le ratio moyen (famille 1) est : "<<totalRatio_1<<endl;
    totalRatio_2 = totalRatio_2/(NbIndividus-1);
    cout<<endl<<"le ratio moyen (famille 2) est : "<<totalRatio_2<<endl<<endl;

//combat des deux alphas, determination du vainceur,
    //si match nul, on compare les ratios familiaux et le plus grand l'emporte
    cout<<"-combat final des deux alphas : "<<endl;
    cout<<" alpha de la famille 1: "<<endl<<alf1->tooString()<<endl;
    cout<<" alpha de la famille 2: "<<endl<<alf2->tooString()<<endl;
    if(match(alf1->liste_individu.at(0), alf2->liste_individu.at(0))!=0) //si c'est pas un match nul
        {
    cout<<"le gagnant est l'alpha de la famille "<<match(alf1->liste_individu.at(0), alf2->liste_individu.at(0))<<endl;
    cout<<" sa famille est elue gagnante de cette baston!"<<endl<<endl;
    return 1;
        }
    else if(match(alf1->liste_individu.at(0), alf2->liste_individu.at(0))==0) {
    cout<<"aucun gagnant, un match a mort familial s'impose ! les perdants de duels meurent"<<endl;
    return 2;

}
    return 0;
}

//fait se battre les deux alphas, et calcul la moyenne de
//chaque familles au cas ou le combat est nul.
//determine le vainceur de la bataille
void baston::slatra(int indice_p1, Population * p1, Population * p2) {
//faire combattre un individu d'une famille avec chaques inds de la famille adverse
//qDebug()<<"slatra";
    //pour chaques membres de la famille, les faire se battre avec l'individu
    foreach (Individu *ind,p2->liste_individu) {

        int vainqueur=match(p1->liste_individu.at(indice_p1),ind);

        //conditions d'attribution des stats
        //si il est vainceur, lui ajouter une victoire
        //sinon, le tuer
        if (vainqueur==1){
            p1->liste_individu.at(indice_p1)->incr_victoires();

            ind->death();//death mets l'id à -1;
        }
        else if (vainqueur ==2) {
            p1->liste_individu.at(indice_p1)->death();
            ind->incr_victoires();
        }

    }

//qDebug()<<" fin";
}

