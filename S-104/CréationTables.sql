CREATE TABLE CHANTIER (
    num_chantier int NOT NULL,
    nom_chantier varchar(50) NOT NULL,
    duree_chantier varchar(20),
    coute_chantier varchar(50),
    adresse_chantier varchar(50),
    etat int,
    responsable int,
    employes int,
    PRIMARY KEY (num_chantier),
    CONSTRAINT FK1 FOREIGN KEY (adresse_chantier)
    REFERENCES EMPLOYE(adresse_chantier),
   CONSTRAINT FK2 FOREIGN KEY (etat)
    REFERENCES ADRESSE(num_adresse),
   CONSTRAINT FK3 FOREIGN KEY (responsable)
    REFERENCES EMPLOYE(num_employe)
);
CREATE TABLE EMPLOYE (
    num_employe int NOT NULL,
    nom_employe varchar(50) NOT NULL,
    prenom_employe varchar(50) NOT NULL,
    date_naissance_employe varchar(20),
    nationalite_employe varchar(50),
    telephone_employe varchar(50),
    specialite_employe varchar(50),
    PRIMARY KEY (num_employe),
    CONSTRAINT FK FOREIGN KEY (specialite_employe)
    REFERENCES SPECIALITE(num_specialite)
);
CREATE TABLE SPECIALITE (
    num_specialite int NOT NULL,
    nom_ specialite varchar(50) NOT NULL,
    PRIMARY KEY (num_specialite)
);
CREATE TABLE ETAT (
    num_etat int NOT NULL,
    nom_ etat varchar(50) NOT NULL,
    PRIMARY KEY (num_etat)
);

CREATE TABLE INTERVENTION (
    num_employe int NOT NULL,
    num_chantier int NOT NULL,
    CONSTRAINT PK PRIMARY KEY (num_employe,num_chantier)
    CONSTRAINT FK1 FOREIGN KEY (num_employe)
    REFERENCES EMPLOYE(num_employe)
    CONSTRAINT FK2 FOREIGN KEY (num_chantier)
    REFERENCES CHANTIER(num_chantier)
);

CREATE TABLE ADRESSE (
    num_adresse int NOT NULL,
    nom_adresse varchar(50) NOT NULL,
    nom_ville varchar(50) NOT NULL,
    code_postale varchar(50) NOT NULL,
    PRIMARY KEY (num_adresse)
);
CREATE TABLE TACHE (
    num_chantier int NOT NULL,
    num_tache int NOT NULL,
    nom_tache varchar(50) NOT NULL,
   CONSTRAINT PK PRIMARY KEY (num_tache,num_chantier)
);
