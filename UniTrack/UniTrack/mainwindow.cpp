#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QInputDialog>
#include <QFileDialog>
#include <QMessageBox>
#include "styles.h"
using namespace std;

// Costruttore della finestra principale
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Applica il foglio di stile moderno tramite funzione dedicata
    getStyle();

    // Inizializza il modello dati per la tabella Qt
    modelloTabella = new QStandardItemModel(this);
    impostaTabella();
}

// Distruttore - libera la memoria allocata per l'interfaccia
MainWindow::~MainWindow()
{
    delete ui;
}

// Configura le proprietà e l'aspetto della tabella principale
void MainWindow::impostaTabella()
{
    // Definisce le intestazioni delle colonne della tabella
    QStringList colonneIntestazione = {"Codice Corso", "Descrizione Corso", "Codice Materia",
                                       "Descrizione Materia", "Matricola", "Cognome", "Nome"};
    modelloTabella->setHorizontalHeaderLabels(colonneIntestazione);
    ui->vistaTabella->setModel(modelloTabella);

    // Abilita il ridimensionamento automatico delle colonne in base al contenuto
    ui->vistaTabella->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);

    // Imposta larghezza minima per evitare colonne troppo compresse
    ui->vistaTabella->horizontalHeader()->setMinimumSectionSize(100);

    // Nasconde i numeri di riga e mostra la griglia
    ui->vistaTabella->verticalHeader()->setVisible(false);
    ui->vistaTabella->setShowGrid(true);
}

// Rimuove tutti i dati dalla tabella visualizzata
void MainWindow::pulisciTabella()
{
    modelloTabella->removeRows(0, modelloTabella->rowCount());
}

// Carica i dati da un file CSV e li visualizza nella tabella
void MainWindow::caricaCSV(string percorsoFile)
{
    ifstream fileInput(percorsoFile); // Apre il file in modalità lettura

    // Verifica se il file è stato aperto correttamente
    if (!fileInput.is_open()) {
        QMessageBox::critical(this, "Errore", "Impossibile aprire il file CSV.");
        return;
    }

    datiCorsi.clear(); // Svuota i dati precedenti dalla memoria
    pulisciTabella(); // Pulisce la visualizzazione della tabella

    string rigaCorrente;
    getline(fileInput, rigaCorrente); // Salta la prima riga (intestazioni del CSV)

    // Legge ogni riga del file fino alla fine
    while (!fileInput.eof()) {
        string codCorso, descCorso, codMateria, descMateria,
            numeroMatricola, cognomeStudente, nomeStudente;

        // Legge ogni campo separato da virgola
        getline(fileInput, codCorso, ',');
        if (codCorso == "") // Se il primo campo è vuoto, siamo alla fine del file
            break;

        getline(fileInput, descCorso, ',');
        getline(fileInput, codMateria, ',');
        getline(fileInput, descMateria, ',');
        getline(fileInput, numeroMatricola, ',');
        getline(fileInput, cognomeStudente, ',');
        getline(fileInput, nomeStudente); // Ultimo campo della riga

        // Crea un oggetto DatiCorso con i dati letti
        DatiCorso recordStudente{codCorso, descCorso, codMateria, descMateria,
                                 numeroMatricola, cognomeStudente, nomeStudente};

        datiCorsi.push_back(recordStudente); // Aggiunge il record al vettore principale

        // Crea una riga per la visualizzazione nella tabella Qt
        QList<QStandardItem*> rigaTabella;
        rigaTabella << new QStandardItem(QString::fromStdString(codCorso))
                    << new QStandardItem(QString::fromStdString(descCorso))
                    << new QStandardItem(QString::fromStdString(codMateria))
                    << new QStandardItem(QString::fromStdString(descMateria))
                    << new QStandardItem(QString::fromStdString(numeroMatricola))
                    << new QStandardItem(QString::fromStdString(cognomeStudente))
                    << new QStandardItem(QString::fromStdString(nomeStudente));

        modelloTabella->appendRow(rigaTabella); // Aggiunge la riga alla tabella visibile
    }

    fileInput.close();
    // Mostra messaggio informativo con il numero di record caricati
    QMessageBox::information(this, "Info", QString("Dati caricati: %1 record").arg(datiCorsi.size()));
}

// Salva tutti i dati attualmente in memoria in un file CSV
void MainWindow::salvaCSV(string percorsoFile)
{
    ofstream fileOutput(percorsoFile); // Apertura del file in scrittura

    if (!fileOutput.is_open()) {
        QMessageBox::critical(this, "Errore", "Impossibile salvare il file CSV.");
        return;
    }

    // Scrive la riga di intestazione del CSV
    fileOutput << "codice_corso,descrizione_corso,codice_materia,descrizione_materia,matricola_studente,cognome_studente,nome_studente" << endl;

    // Scrive ogni record del vettore datiCorsi nel file
    for (vector<DatiCorso>::const_iterator iteratore = datiCorsi.begin(); iteratore != datiCorsi.end(); ++iteratore) {
        fileOutput << iteratore->codiceCorso << ","
                   << iteratore->descrizioneCorso << ","
                   << iteratore->codiceMateria << ","
                   << iteratore->descrizioneMateria << ","
                   << iteratore->matricola << ","
                   << iteratore->cognome << ","
                   << iteratore->nome << endl;
    }

    fileOutput.close();
    QMessageBox::information(this, "Info", "File salvato correttamente");
}

// Slot per il menu "Carica CSV" - apre dialog di selezione file
void MainWindow::on_actionCaricaCSV_triggered()
{
    QString pathFileQt = QFileDialog::getOpenFileName(this, "Seleziona file CSV");
    string pathFile = pathFileQt.toStdString(); // Conversione da QString a std::string
    caricaCSV(pathFile);
}

// Slot per il menu "Salva CSV" - apre dialog di salvataggio
void MainWindow::on_actionSalvaCSV_triggered()
{
    QString pathFileQt = QFileDialog::getSaveFileName(this, "Salva file CSV");
    string pathFile = pathFileQt.toStdString();
    salvaCSV(pathFile);
}

// Cerca e visualizza tutti i record di uno studente tramite matricola
void MainWindow::on_btnCercaPerMatricola_clicked()
{
    QString matricolaQt = ui->lineEditMatricola->text().trimmed(); // Rimuove spazi iniziali/finali
    string matricolaCercata = matricolaQt.toStdString();

    pulisciTabella(); // Pulisce la tabella prima di mostrare i risultati

    bool recordTrovato = false;

    // Scorre tutti i dati cercando la matricola specificata
    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        if (iter->matricola == matricolaCercata) {
            // Crea e aggiunge una riga alla tabella per ogni match trovato
            QList<QStandardItem*> rigaRisultato;
            rigaRisultato << new QStandardItem(QString::fromStdString(iter->codiceCorso))
                          << new QStandardItem(QString::fromStdString(iter->descrizioneCorso))
                          << new QStandardItem(QString::fromStdString(iter->codiceMateria))
                          << new QStandardItem(QString::fromStdString(iter->descrizioneMateria))
                          << new QStandardItem(QString::fromStdString(iter->matricola))
                          << new QStandardItem(QString::fromStdString(iter->cognome))
                          << new QStandardItem(QString::fromStdString(iter->nome));
            modelloTabella->appendRow(rigaRisultato);
            recordTrovato = true;
        }
    }

    if (!recordTrovato) {
        QMessageBox::information(this, "Risultato", "Matricola non trovata");
    }
}

// Cerca studenti per cognome (ricerca case-insensitive)
void MainWindow::on_btnCercaPerCognome_clicked()
{
    QString cognomeQt = ui->lineEditCognome->text().trimmed().toLower(); // Converte in minuscolo
    string cognomeCercato = cognomeQt.toStdString();

    pulisciTabella();

    bool studenteTrovato = false;

    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        // Converte il cognome del record corrente in minuscolo per confronto case-insensitive
        string cognomeMinuscolo = iter->cognome;
        for (string::iterator carattere = cognomeMinuscolo.begin(); carattere != cognomeMinuscolo.end(); ++carattere) {
            *carattere = tolower(*carattere);
        }

        if (cognomeMinuscolo == cognomeCercato) {
            QList<QStandardItem*> rigaRisultato;
            rigaRisultato << new QStandardItem(QString::fromStdString(iter->codiceCorso))
                          << new QStandardItem(QString::fromStdString(iter->descrizioneCorso))
                          << new QStandardItem(QString::fromStdString(iter->codiceMateria))
                          << new QStandardItem(QString::fromStdString(iter->descrizioneMateria))
                          << new QStandardItem(QString::fromStdString(iter->matricola))
                          << new QStandardItem(QString::fromStdString(iter->cognome))
                          << new QStandardItem(QString::fromStdString(iter->nome));
            modelloTabella->appendRow(rigaRisultato);
            studenteTrovato = true;
        }
    }

    if (!studenteTrovato) {
        QMessageBox::information(this, "Risultato", "Nessuno studente trovato con questo cognome");
    }
}

// Cerca materie per descrizione (ricerca parziale case-insensitive)
void MainWindow::on_btnCercaPerMateria_clicked()
{
    pulisciTabella();
    QString materiaQt = ui->lineEditMateria->text().trimmed().toLower();
    string testoCercato = materiaQt.toStdString();

    bool materiaTrovata = false;

    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        // Converte la descrizione materia in minuscolo
        string descrizioneMinuscola = iter->descrizioneMateria;
        for (string::iterator carattere = descrizioneMinuscola.begin(); carattere != descrizioneMinuscola.end(); ++carattere) {
            *carattere = tolower(*carattere);
        }

        // Verifica se la descrizione contiene la stringa cercata (ricerca parziale)
        if (descrizioneMinuscola.find(testoCercato) != string::npos) {
            QList<QStandardItem*> rigaRisultato;
            rigaRisultato << new QStandardItem(QString::fromStdString(iter->codiceCorso))
                          << new QStandardItem(QString::fromStdString(iter->descrizioneCorso))
                          << new QStandardItem(QString::fromStdString(iter->codiceMateria))
                          << new QStandardItem(QString::fromStdString(iter->descrizioneMateria))
                          << new QStandardItem(QString::fromStdString(iter->matricola))
                          << new QStandardItem(QString::fromStdString(iter->cognome))
                          << new QStandardItem(QString::fromStdString(iter->nome));
            modelloTabella->appendRow(rigaRisultato);
            materiaTrovata = true;
        }
    }

    if (!materiaTrovata) {
        QMessageBox::information(this, "Risultato", "Nessuna materia trovata");
    }
}

// Aggiunge un nuovo studente tramite input dialogs sequenziali
void MainWindow::on_btnAggiungiStudente_clicked()
{
    bool inputValido; // Flag per verificare se l'utente ha confermato l'input

    // Richiede la matricola e verifica che non esista già
    QString matricolaQt = QInputDialog::getText(this, "Aggiungi studente", "Matricola:",
                                                QLineEdit::Normal, "", &inputValido);
    if (!inputValido || matricolaQt.trimmed().isEmpty())
        return;

    string nuovaMatricola = matricolaQt.trimmed().toStdString();

    // Controlla se la matricola esiste già nel sistema
    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        if (iter->matricola == nuovaMatricola) {
            QMessageBox::warning(this, "Errore", "Matricola già esistente");
            return;
        }
    }

    // Raccoglie tutti i dati necessari tramite dialog sequenziali
    QString nomeQt = QInputDialog::getText(this, "Aggiungi studente", "Nome:",
                                           QLineEdit::Normal, "", &inputValido);
    if (!inputValido || nomeQt.trimmed().isEmpty()) return;
    string nuovoNome = nomeQt.trimmed().toStdString();

    QString cognomeQt = QInputDialog::getText(this, "Aggiungi studente", "Cognome:",
                                              QLineEdit::Normal, "", &inputValido);
    if (!inputValido || cognomeQt.trimmed().isEmpty()) return;
    string nuovoCognome = cognomeQt.trimmed().toStdString();

    QString codCorsoQt = QInputDialog::getText(this, "Aggiungi studente", "Codice Corso:",
                                               QLineEdit::Normal, "", &inputValido);
    if (!inputValido || codCorsoQt.trimmed().isEmpty()) return;
    string nuovoCodiceCorso = codCorsoQt.trimmed().toStdString();

    QString descCorsoQt = QInputDialog::getText(this, "Aggiungi studente", "Descrizione Corso:",
                                                QLineEdit::Normal, "", &inputValido);
    if (!inputValido || descCorsoQt.trimmed().isEmpty()) return;
    string nuovaDescrizioneCorso = descCorsoQt.trimmed().toStdString();

    QString codMateriaQt = QInputDialog::getText(this, "Aggiungi studente", "Codice Materia:",
                                                 QLineEdit::Normal, "", &inputValido);
    if (!inputValido || codMateriaQt.trimmed().isEmpty()) return;
    string nuovoCodiceMateria = codMateriaQt.trimmed().toStdString();

    QString descMateriaQt = QInputDialog::getText(this, "Aggiungi studente", "Descrizione Materia:",
                                                  QLineEdit::Normal, "", &inputValido);
    if (!inputValido || descMateriaQt.trimmed().isEmpty()) return;
    string nuovaDescrizioneMateria = descMateriaQt.trimmed().toStdString();

    // Crea il nuovo record studente con tutti i dati raccolti
    DatiCorso nuovoStudente;
    nuovoStudente.codiceCorso = nuovoCodiceCorso;
    nuovoStudente.descrizioneCorso = nuovaDescrizioneCorso;
    nuovoStudente.codiceMateria = nuovoCodiceMateria;
    nuovoStudente.descrizioneMateria = nuovaDescrizioneMateria;
    nuovoStudente.matricola = nuovaMatricola;
    nuovoStudente.cognome = nuovoCognome;
    nuovoStudente.nome = nuovoNome;

    datiCorsi.push_back(nuovoStudente); // Aggiunge il nuovo studente alla collezione

    QMessageBox::information(this, "Successo", "Studente aggiunto correttamente");
}

// Restituisce un vettore degli studenti unici iscritti a un corso specifico
vector<DatiCorso> MainWindow::getStudentiIscritti(string codiceCorso)
{
    vector<DatiCorso> studentiUnici;
    set<string> matricoleGiaViste; // Set per evitare duplicati di matricole

    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        if (iter->codiceCorso == codiceCorso) {
            // Aggiunge lo studente solo se la matricola non è già stata processata
            if (matricoleGiaViste.find(iter->matricola) == matricoleGiaViste.end()) {
                matricoleGiaViste.insert(iter->matricola);
                studentiUnici.push_back(*iter);
            }
        }
    }

    return studentiUnici;
}

// Restituisce tutti i record di esami per un corso (inclusi duplicati di studenti)
vector<DatiCorso> MainWindow::getDatiEsamiCorso(string codiceCorso)
{
    vector<DatiCorso> esamiDelCorso;

    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        if (iter->codiceCorso == codiceCorso) {
            esamiDelCorso.push_back(*iter);
        }
    }

    return esamiDelCorso;
}

// Calcola il numero di studenti unici per ogni corso
map<string, int> MainWindow::getNumeroStudentiPerCorso()
{
    map<string, int> conteggioStudenti;
    map<string, set<string>> matricolePerCorso; // Mappa corso -> set di matricole uniche

    // Raccoglie le matricole uniche per ogni corso
    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        matricolePerCorso[iter->codiceCorso].insert(iter->matricola);
    }

    // Conta le matricole uniche per ogni corso
    for (map<string, set<string>>::const_iterator iter = matricolePerCorso.begin();
         iter != matricolePerCorso.end(); ++iter) {
        conteggioStudenti[iter->first] = iter->second.size();
    }

    return conteggioStudenti;
}

// Calcola il numero di materie distinte per ogni corso
map<string, int> MainWindow::getNumeroMateriePerCorso()
{
    map<string, int> conteggioMaterie;
    map<string, set<string>> materiePerCorso; // Mappa corso -> set di codici materia unici

    // Raccoglie i codici materia distinti per ogni corso
    for (vector<DatiCorso>::const_iterator iter = datiCorsi.begin(); iter != datiCorsi.end(); ++iter) {
        materiePerCorso[iter->codiceCorso].insert(iter->codiceMateria);
    }

    // Conta le materie distinte per ogni corso
    for (map<string, set<string>>::const_iterator iter = materiePerCorso.begin();
         iter != materiePerCorso.end(); ++iter) {
        conteggioMaterie[iter->first] = iter->second.size();
    }

    return conteggioMaterie;
}

// Visualizza un vettore di risultati nella tabella principale
void MainWindow::mostraRisultatiInTabella(const vector<DatiCorso>& risultatiRicerca)
{
    pulisciTabella(); // Pulisce la tabella prima di mostrare i nuovi risultati

    for (vector<DatiCorso>::const_iterator iter = risultatiRicerca.begin();
         iter != risultatiRicerca.end(); ++iter) {

        QList<QStandardItem*> rigaVisualizzazione;
        rigaVisualizzazione << new QStandardItem(QString::fromStdString(iter->codiceCorso))
                            << new QStandardItem(QString::fromStdString(iter->descrizioneCorso))
                            << new QStandardItem(QString::fromStdString(iter->codiceMateria))
                            << new QStandardItem(QString::fromStdString(iter->descrizioneMateria))
                            << new QStandardItem(QString::fromStdString(iter->matricola))
                            << new QStandardItem(QString::fromStdString(iter->cognome))
                            << new QStandardItem(QString::fromStdString(iter->nome));
        modelloTabella->appendRow(rigaVisualizzazione);
    }
}

// Visualizza statistiche di conteggio in una tabella a due colonne
void MainWindow::mostraTabellaConteggi(const map<string, int>& statistiche,
                                       const string& titoloColonna1, const string& titoloColonna2)
{
    pulisciTabella();

    // Imposta le intestazioni personalizzate per la tabella di conteggi
    QStringList intestazioniPersonalizzate = {QString::fromStdString(titoloColonna1),
                                              QString::fromStdString(titoloColonna2)};
    modelloTabella->setHorizontalHeaderLabels(intestazioniPersonalizzate);

    // Popola la tabella con i dati statistici
    for (map<string, int>::const_iterator iter = statistiche.begin(); iter != statistiche.end(); ++iter) {
        QList<QStandardItem*> rigaStatistica;
        rigaStatistica << new QStandardItem(QString::fromStdString(iter->first)) // Chiave (es. codice corso)
                       << new QStandardItem(QString::number(iter->second)); // Valore numerico
        modelloTabella->appendRow(rigaStatistica);
    }
}

// Slot per visualizzare la lista degli studenti iscritti a un corso
void MainWindow::on_btnListaStudentiCorso_clicked()
{
    bool inputConfermato;
    QString codiceCorsoQt = QInputDialog::getText(this, "Lista Studenti", "Codice Corso:",
                                                  QLineEdit::Normal, "", &inputConfermato);
    if (!inputConfermato || codiceCorsoQt.isEmpty())
        return;

    string corsoSelezionato = codiceCorsoQt.toStdString();
    vector<DatiCorso> studentiDelCorso = getStudentiIscritti(corsoSelezionato);

    if (studentiDelCorso.empty()) {
        QMessageBox::information(this, "Risultato", "Nessuno studente trovato per questo corso");
        return;
    }

    mostraRisultatiInTabella(studentiDelCorso);
}

// Slot per visualizzare tutti i dati degli esami di un corso
void MainWindow::on_btnDatiEsamiCorso_clicked()
{
    bool inputConfermato;
    QString codiceCorsoQt = QInputDialog::getText(this, "Dati Esami", "Codice Corso:",
                                                  QLineEdit::Normal, "", &inputConfermato);
    if (!inputConfermato || codiceCorsoQt.isEmpty())
        return;

    string corsoSelezionato = codiceCorsoQt.toStdString();
    vector<DatiCorso> esamiCorso = getDatiEsamiCorso(corsoSelezionato);

    if (esamiCorso.empty()) {
        QMessageBox::information(this, "Risultato", "Nessun esame trovato per questo corso");
        return;
    }

    mostraRisultatiInTabella(esamiCorso);
}

// Slot per mostrare il conteggio studenti per ogni corso
void MainWindow::on_btnConteggioStudentiPerCorso_clicked()
{
    map<string, int> statisticheStudenti = getNumeroStudentiPerCorso();

    if (statisticheStudenti.empty()) {
        QMessageBox::information(this, "Risultato", "Nessun corso trovato");
        return;
    }

    mostraTabellaConteggi(statisticheStudenti, "Codice Corso", "Numero Studenti");
}

// Slot per mostrare il conteggio materie per ogni corso
void MainWindow::on_btnConteggioMateriePerCorso_clicked()
{
    map<string, int> statisticheMaterie = getNumeroMateriePerCorso();

    if (statisticheMaterie.empty()) {
        QMessageBox::information(this, "Risultato", "Nessun corso trovato");
        return;
    }

    mostraTabellaConteggi(statisticheMaterie, "Codice Corso", "Numero Materie");
}

// Applica lo stile CSS personalizzato alla finestra principale
void MainWindow::getStyle() {
    QString foglioStile = styles::getStyle(); // Ottiene il CSS dal modulo styles
    this->setStyleSheet(foglioStile); // Applica lo stile alla finestra
}
