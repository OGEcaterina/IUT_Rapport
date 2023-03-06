/*Sélectionner tous les employés et leur spécialité correspondante*/
SELECT nom_employe, prenom_employe, specialite_employe
FROM EMPLOYE
INNER JOIN SPECIALITE
ON EMPLOYE.specialite_employe = SPECIALITE.num_specialite;
/*    Sélectionner tous les employés intervenant sur un chantier donné */
SELECT nom_employe, prenom_employe
FROM EMPLOYE
INNER JOIN INTERVENTION
ON EMPLOYE.num_employe = INTERVENTION.num_employe
WHERE num_chantier = 1;
/*    Sélectionner le nom et l'adresse de tous les chantiers en cours*/
SELECT nom_chantier, adresse_chantier
FROM CHANTIER
INNER JOIN ADRESSE
ON CHANTIER.adresse_chantier = ADRESSE.num_adresse
WHERE etat = 1;
/*    Sélectionner le nom et le nombre d'employés pour chaque spécialité*/
SELECT nom_specialite, COUNT(num_employe)
FROM SPECIALITE
INNER JOIN EMPLOYE
ON SPECIALITE.num_specialite = EMPLOYE.specialite_employe
GROUP BY nom_specialite;
/*    Sélectionner le nom de tous les employés ayant une spécialité en commun*/
SELECT DISTINCT nom_employe, prenom_employe
FROM EMPLOYE
INNER JOIN EMPLOYE as e2
ON EMPLOYE.specialite_employe = e2.specialite_employe
WHERE EMPLOYE.num_employe != e2.num_employe;
/*    Sélectionner le nom et la durée moyenne des chantiers pour chaque responsable*/
SELECT nom_employe, AVG(duree_chantier)
FROM CHANTIER
INNER JOIN EMPLOYE
ON CHANTIER.responsable = EMPLOYE.num_employe
GROUP BY nom_employe;
/*    Sélectionner le nom et le coût total des chantiers pour chaque responsable*/
SELECT nom_employe, SUM(coute_chantier)
FROM CHANTIER
INNER JOIN EMPLOYE
ON CHANTIER.responsable = EMPLOYE.num_employe
GROUP BY nom_employe;
/*    Sélectionner le nom des employés ayant plus de 3 ans d'expérience*/
SELECT nom_employe, prenom_employe
FROM EMPLOYE
WHERE DATEDIFF(NOW(), date_naissance_employe) >= 3;
/*    Sélectionner le nom des tâches liées au chantier 1*/
SELECT nom_tache
FROM TACHE
WHERE num_chantier = 1;
/*    Sélectionner le nom des employés ayant une spécialité Plomberie*/
SELECT nom_employe, prenom_employe
FROM EMPLOYE
WHERE specialite_employe = 'plomberie';
/*Cette requête permet de sélectionner les chantiers dont le coût est supérieur à 100 000e.*/
SELECT nom_chantier
FROM CHANTIER
WHERE coute_chantier > 100000;
/*Cette requête permet de sélectionner les employés intervenant sur un chantier donné (ici le chantier 1) et ayant la spécialité de plomberie.*/
SELECT nom_employe, prenom_employe
FROM EMPLOYE
INNER JOIN INTERVENTION
ON EMPLOYE.num_employe = INTERVENTION.num_employe
WHERE num_chantier = 1 AND specialite_employe = 'plomberie';
/*Cette requête permet de sélectionner les employés ayant la spécialité de plomberie et ne participant pas sur un chantier donné (ici le chantier 1).*/
SELECT nom_employe, prenom_employe
FROM EMPLOYE
LEFT JOIN INTERVENTION
ON EMPLOYE.num_employe = INTERVENTION.num_employe
WHERE specialite_employe = 'plomberie' AND num_chantier != 1;
/*Cette requête permet de sélectionner les employés ayant la spécialité de plomberie et intervenant sur un nombre de chantiers supérieur à 3.*/
SELECT nom_employe, prenom_employe, COUNT(num_chantier)
FROM EMPLOYE
INNER JOIN INTERVENTION
ON EMPLOYE.num_employe = INTERVENTION.num_employe
WHERE specialite_employe = 'plomberie'
GROUP BY nom_employe
HAVING COUNT(num_chantier) > 3;
/*Cette requête permet de sélectionner le coût total des chantiers pour chaque spécialité d'employé, et de les trier par coût décroissant.*/
SELECT specialite_employe, SUM(coute_chantier)
FROM CHANTIER
INNER JOIN INTERVENTION
ON CHANTIER.num_chantier = INTERVENTION.num_chantier
INNER JOIN EMPLOYE
ON INTERVENTION.num_employe = EMPLOYE.num_employe
GROUP BY specialite_employe
ORDER BY SUM(coute_chantier) DESC;
/*Cette requête permet de sélectionner le nom et le nombre d'employés pour chaque spécialité, ayant plus de 2 ans d'expérience.*/
SELECT nom_specialite, COUNT(num_employe)
FROM SPECIALITE
INNER JOIN EMPLOYE
ON SPECIALITE.num_specialite = EMPLOYE.specialite_employe
WHERE DATEDIFF(NOW(), date_naissance_employe) >= 2
GROUP BY nom_specialite;
/*Cette requête permet de sélectionner le nom et le nombre de tâches pour chaque chantier, ayant plus de 3 tâches.*/
SELECT nom_chantier, COUNT(num_tache)
FROM CHANTIER
INNER JOIN TACHE
ON CHANTIER.num_chantier = TACHE.num_chantier
GROUP BY nom_chantier
HAVING COUNT(num_tache) > 3;
/*Cette requête permet de sélectionner le nom et l'adresse de tous les chantiers en cours, et de les trier par ville.*/
SELECT nom_chantier, nom_adresse, nom_ville
FROM CHANTIER
INNER JOIN ADRESSE
ON CHANTIER.adresse_chantier = ADRESSE.num_adresse
WHERE etat = 1
ORDER BY nom_ville;
/*Cette requête permet de sélectionner le nom des employés ayant une spécialité donnée (plomberie) et intervenant sur un nombre de chantiers inférieur à 3, trié par nom d'employé.
*/
SELECT nom_employe, prenom_employe, COUNT(num_chantier)
FROM EMPLOYE
INNER JOIN INTERVENTION
ON EMPLOYE.num_employe = INTERVENTION.num_employe
WHERE specialite_employe = 'plomberie'
GROUP BY nom_employe, prenom_employe
HAVING COUNT(num_chantier) < 3
ORDER BY nom_employe;