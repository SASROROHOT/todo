#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <fstream>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

// Definizione della struct DatiCorso
struct DatiCorso {
    string codiceCorso;
    string descrizioneCorso;
    string codiceMateria;
    string descrizioneMateria;
    string matricola;
    string cognome;
    string nome;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionCaricaCSV_triggered();
    void on_actionSalvaCSV_triggered();
    void on_btnCercaPerMatricola_clicked();
    void on_btnCercaPerCognome_clicked();
    void on_btnCercaPerMateria_clicked();
    void on_btnAggiungiStudente_clicked();
    void on_btnListaStudentiCorso_clicked();
    void on_btnDatiEsamiCorso_clicked();
    void on_btnConteggioStudentiPerCorso_clicked();
    void on_btnConteggioMateriePerCorso_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *modelloTabella;
    vector<DatiCorso> datiCorsi;

    // Prototipi delle funzioni

    void getStyle();
    void impostaTabella();
    void pulisciTabella();
    void caricaCSV(string percorsoFile);
    void salvaCSV(string percorsoFile);

    vector<DatiCorso> getStudentiIscritti(string codiceCorso);
    vector<DatiCorso> getDatiEsamiCorso(string codiceCorso);
    map<string, int> getNumeroStudentiPerCorso();
    map<string, int> getNumeroMateriePerCorso();

    void mostraRisultatiInTabella(const vector<DatiCorso>& risultati);
    void mostraTabellaConteggi(const map<string, int>& conteggi, const string& intestazioneColonna1, const string& intestazioneColonna2);
};

#endif // MAINWINDOW_H
