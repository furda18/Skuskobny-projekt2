od zaciatku:
//open git bash
git init //v priecinku kde robim
touch .gitignore //ignoruje to s cim nerobim
//pridam do neho tie files ktore chcem ignorovat
touch README	//to je tento subor
git add . 	//prida vsetko
git reset 	//ak som addol pred .gitignore

git commit 	//pridam popisok shift+ins
		//stlacim Esc a napsem :wq

// kopcim to SHIFT +Insert
git remote add origin https://github.com/furda18/Skuskobny-projekt2.git
git push -u origin master //tymito som to pridal na stranku

Toto je dokumentacia vytvorenia branchu:
git branch meinebranch //vytvorenie branchu
git checkout meinebranch //prepnutie do branchu
touch README - //tento subor
upravenie README, aj main.c
git status  //vypisalo zmeny
git add .  //pridalo to
git commit //zakomentoval som commit - SHIFT+insert, Esc na zadanie :wq a preplo ma to nazad
git remote -v //ze ci to ukladam do dobreho repozitara
git push --all //pridalo mi to na github

Github:
isiel som do Branchov
New pull request
dal som mu len nadpis, komentar, a dal som MERGE
spojilo to dokopy a vidno teraz pekne v grafe tie Branche

