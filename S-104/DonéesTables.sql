INSERT INTO CHANTIER
(num_chantier,nom_chantier,duree_chantier,coute_chantier,adresse_chantier,etat,responsable,employes)
VALUES
(1,'Chantier Opera Garnier','3 mois','1 million',1,1,1,20),
(2,'Chantier Ris-Orangis','1 mois','100 milles',2,1,1,8),
(3,'Chantier Chatillon','2 mois','200 milles',3,1,1,12),
(4,'Chantier Paris 2e','1 mois','250 milles',4,1,1,15),
(5,'Chantier Courbevoie','2 mois','150 milles',5,1,1,6),
(6,'Chantier Orsay','2 mois','100 milles',6,1,1,10),
(7,'Chantier Villejuif','4 mois','300 milles',7,1,1,18),
(5,'Chantier Massy','1 mois','170 milles',8,1,1,9);

INSERT INTO EMPLOYE
(num_employe,nom_employe,prenom_employe,date_naissance_employe,nationalite_employe,telephone_employe,specialite_employe)
VALUES
(1,'Noureddine','Moez','01/10/1990','Tunisien','0699658104',1),
(1,'Mamadou','','01/10/1985','Nigerien','0619264931',2),
(1,'Khalifa','Ahmed','01/10/1995','Algerien','0629644198',3),
(1,'Khalifa','Ahmed','20/01/1996','Algerien','0624499228',3),
(1,'Kalia','Antoni','01/10/1990','Nigerian','0696473828',1),
(1,'Chtioui','Amine','03/08/1992','Marocain','0684633517',1),
(1,'Mark','Leclerc','15/12/1989','Français','0629112344',2),
(1,'chahin','','09/03/1988','Indien','0609710348',2);


INSERT INTO ETAT
(num_etat,aspect_etat)
VALUES
(1,'bon etat'),
(2,'mauvais etat'),
(2,'très mauvais etat');

INSERT INTO SPECIALITE
(num_specialite,nom_specialite)
VALUES
(1,'maçon'),
(2,'peintre'),
(3,'plombier'),
(4,'ouvrier');

INSERT INTO TACHE
(num_chantier,num_tache,nom_tache)
VALUES
(1,1,'rennovation'),
(2,1,'rennovation'),
(3,1,'rennovation'),
(3,1,'Plomberie'),
(4,2,'Peinture'),
(5,1,'Plomberie'),
(6,2,'Peinture'),
(7,1,'rennovation'),
(8,2,'peinture');

INSERT INTO ADRESSE
(num_adresse,nom_adresse,nom_ville,code_postale)
VALUES
(1,'Galeries Lafayettes','Opera Garnier','75008'),
(2,'près Gare rer D','Ris-Orangis','91521'),
(5,'près de la mairie','Courbevoie','92026'),
(4,'Rue de Caire','Sentier','75002'),
(6,'Rue de la pacaterie','Orsay','91400'),
(7,'Rue Bd dubreuil','Villejuif','94800'),
(8,'Rue de la republique','Massy','91500');
