# datalogger-project
Datalogger's development in order to monitor a wind turbine (wind speed, wind direction, power).

This work is an initiative by Gilles LONGUET from Tripalium and the Measurment working group from WindEmpowerment.

# Organisation :
This datalogger is design on two principal boards, one for the sensor signal adaptation on a second for the numerical work.
Plug the first on the second and you have the hardware to monitor a wind turbine with these possibilities :
	- 2 anemometers
	- 1 windvane
	- 1 AC voltage sensor
	- 1 DC voltage sensor
	- 4 DC/AC current sensors
	- 1 RPM sensors
	- 1 temperature sensor
	
The data is available on an UART permanently and with the UART to USB converter you can collect them directly on a computer.
Data can be write on the SD card too.
To transmit the data, you need to chose a transmitter. You can connect a ESP wifi module to send it on your local network or use a GPRS module to transmit on a remote network.
Emoncms is used to collect data on a remote server, to add process on and record data. It's also used to visualize data.


# datalogger-project
Développement d'un enregistreur de données pour monitorer une éolienne (vitesse et direction du vent et puissance produite).

Ce travail est une initiative de Gilles Longuet pour Tripalium et le Measurment working group de WindEmpowerment.

# Organisation :
Cet enregistreur de données est développé autour de deux cartes, une première pour le traitement des signaux provenant des capteurs et une seconde pour tout le traitement numérique des données.
Il suffit de connecter la première carte sur la seconde pour avoir un enregistreur de données avec les possibilités suivantes :
	- 2 anémomètres
	- 1 girouette
	- 1 sonde de tension AC
	- 1 sonde de tension DC
	- 4 sondes de courant AC ou DC
	- 1 sonde RPM
	- 1 sonde de température
	
Les données sont disponibles sur un UART de façon permanente et avec l'adaptateur UART/USB vous pouvez directement collecter les données sur un ordinateur. Les données peuvent aussi être enregistré sur une carte SD.
Pour transmettre les données, vous devez choisir un module. Soit vous utilisez un module du type ESP wifi, pour envoyer vos données sur votre wifi local. Soit vous utilisez un module GPRS pour transmettre les donnés à distances.
Emoncms est utilisé pour la collecte des données sur un serveur distant. On peut appliquer sur les données des processus puis les enregistrer. Emoncms permet aussi la visualisation des données.

# Repositories description :
## Emoncms_add-ons repo :
Contain different add-ons to simplify the wind visualization.

## Firmware :
Contain the software for the microcontroller.

## Hardware :
Contain the files on the different hardware boards.

## windlogger_shield(old) repo :
contain the work than was done by Etienne, a student. He does that to help us for an internship of 6 weeks. This is an archive, the new version is in the Hardware repo.
The report is in French.