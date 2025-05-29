/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCaricaCSV;
    QAction *actionSalvaCSV;
    QAction *actionEsci;
    QAction *actionPulisciTabella;
    QAction *actionInfo;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *tabRicerca;
    QVBoxLayout *verticalLayout;
    QFrame *frameRicerca;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QLabel *labelMatricola;
    QLineEdit *lineEditCognome;
    QLineEdit *lineEditMateria;
    QLabel *labelMateria;
    QLineEdit *lineEditMatricola;
    QLabel *labelCognome;
    QPushButton *btnCercaPerMateria;
    QPushButton *btnCercaPerCognome;
    QPushButton *btnCercaPerMatricola;
    QPushButton *btnAggiungiStudente;
    QWidget *tabGestioneCorsi;
    QVBoxLayout *verticalLayout_3;
    QFrame *frameCorsi;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QPushButton *btnListaStudentiCorso;
    QPushButton *btnDatiEsamiCorso;
    QPushButton *btnConteggioStudentiPerCorso;
    QPushButton *btnConteggioMateriePerCorso;
    QFrame *frameTabella;
    QGridLayout *gridLayout_3;
    QLabel *labelTitoloTabella;
    QTableView *vistaTabella;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1688, 836);
        QIcon icon;
        icon.addFile(QString::fromUtf8("."), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        MainWindow->setWindowIcon(icon);
        actionCaricaCSV = new QAction(MainWindow);
        actionCaricaCSV->setObjectName("actionCaricaCSV");
        actionSalvaCSV = new QAction(MainWindow);
        actionSalvaCSV->setObjectName("actionSalvaCSV");
        actionEsci = new QAction(MainWindow);
        actionEsci->setObjectName("actionEsci");
        actionPulisciTabella = new QAction(MainWindow);
        actionPulisciTabella->setObjectName("actionPulisciTabella");
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName("actionInfo");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(20, 20, 20, 20);
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setTabPosition(QTabWidget::TabPosition::North);
        tabWidget->setTabShape(QTabWidget::TabShape::Rounded);
        tabWidget->setIconSize(QSize(24, 24));
        tabRicerca = new QWidget();
        tabRicerca->setObjectName("tabRicerca");
        verticalLayout = new QVBoxLayout(tabRicerca);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(20, 25, 20, 20);
        frameRicerca = new QFrame(tabRicerca);
        frameRicerca->setObjectName("frameRicerca");
        frameRicerca->setFrameShape(QFrame::Shape::Box);
        frameRicerca->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frameRicerca);
        verticalLayout_4->setSpacing(20);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(30, 25, 30, 25);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(20);
        gridLayout->setObjectName("gridLayout");
        labelMatricola = new QLabel(frameRicerca);
        labelMatricola->setObjectName("labelMatricola");

        gridLayout->addWidget(labelMatricola, 0, 0, 1, 1);

        lineEditCognome = new QLineEdit(frameRicerca);
        lineEditCognome->setObjectName("lineEditCognome");

        gridLayout->addWidget(lineEditCognome, 1, 1, 1, 1);

        lineEditMateria = new QLineEdit(frameRicerca);
        lineEditMateria->setObjectName("lineEditMateria");

        gridLayout->addWidget(lineEditMateria, 2, 1, 1, 1);

        labelMateria = new QLabel(frameRicerca);
        labelMateria->setObjectName("labelMateria");

        gridLayout->addWidget(labelMateria, 2, 0, 1, 1);

        lineEditMatricola = new QLineEdit(frameRicerca);
        lineEditMatricola->setObjectName("lineEditMatricola");

        gridLayout->addWidget(lineEditMatricola, 0, 1, 1, 1);

        labelCognome = new QLabel(frameRicerca);
        labelCognome->setObjectName("labelCognome");

        gridLayout->addWidget(labelCognome, 1, 0, 1, 1);

        btnCercaPerMateria = new QPushButton(frameRicerca);
        btnCercaPerMateria->setObjectName("btnCercaPerMateria");

        gridLayout->addWidget(btnCercaPerMateria, 2, 2, 1, 1);

        btnCercaPerCognome = new QPushButton(frameRicerca);
        btnCercaPerCognome->setObjectName("btnCercaPerCognome");

        gridLayout->addWidget(btnCercaPerCognome, 1, 2, 1, 1);

        btnCercaPerMatricola = new QPushButton(frameRicerca);
        btnCercaPerMatricola->setObjectName("btnCercaPerMatricola");

        gridLayout->addWidget(btnCercaPerMatricola, 0, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        btnAggiungiStudente = new QPushButton(frameRicerca);
        btnAggiungiStudente->setObjectName("btnAggiungiStudente");

        verticalLayout_4->addWidget(btnAggiungiStudente);


        verticalLayout->addWidget(frameRicerca);

        tabWidget->addTab(tabRicerca, QString());
        tabGestioneCorsi = new QWidget();
        tabGestioneCorsi->setObjectName("tabGestioneCorsi");
        verticalLayout_3 = new QVBoxLayout(tabGestioneCorsi);
        verticalLayout_3->setSpacing(25);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(20, 25, 20, 20);
        frameCorsi = new QFrame(tabGestioneCorsi);
        frameCorsi->setObjectName("frameCorsi");
        frameCorsi->setFrameShape(QFrame::Shape::Box);
        frameCorsi->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_5 = new QVBoxLayout(frameCorsi);
        verticalLayout_5->setSpacing(25);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(30, 25, 30, 25);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(25);
        gridLayout_2->setVerticalSpacing(20);
        btnListaStudentiCorso = new QPushButton(frameCorsi);
        btnListaStudentiCorso->setObjectName("btnListaStudentiCorso");

        gridLayout_2->addWidget(btnListaStudentiCorso, 0, 0, 1, 1);

        btnDatiEsamiCorso = new QPushButton(frameCorsi);
        btnDatiEsamiCorso->setObjectName("btnDatiEsamiCorso");

        gridLayout_2->addWidget(btnDatiEsamiCorso, 0, 1, 1, 1);

        btnConteggioStudentiPerCorso = new QPushButton(frameCorsi);
        btnConteggioStudentiPerCorso->setObjectName("btnConteggioStudentiPerCorso");

        gridLayout_2->addWidget(btnConteggioStudentiPerCorso, 1, 0, 1, 1);

        btnConteggioMateriePerCorso = new QPushButton(frameCorsi);
        btnConteggioMateriePerCorso->setObjectName("btnConteggioMateriePerCorso");

        gridLayout_2->addWidget(btnConteggioMateriePerCorso, 1, 1, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);


        verticalLayout_3->addWidget(frameCorsi);

        tabWidget->addTab(tabGestioneCorsi, QString());

        horizontalLayout->addWidget(tabWidget);

        frameTabella = new QFrame(centralwidget);
        frameTabella->setObjectName("frameTabella");
        frameTabella->setCursor(QCursor(Qt::CursorShape::ArrowCursor));
        frameTabella->setFrameShape(QFrame::Shape::Box);
        frameTabella->setFrameShadow(QFrame::Shadow::Raised);
        gridLayout_3 = new QGridLayout(frameTabella);
        gridLayout_3->setObjectName("gridLayout_3");
        gridLayout_3->setContentsMargins(20, 15, 20, 20);
        labelTitoloTabella = new QLabel(frameTabella);
        labelTitoloTabella->setObjectName("labelTitoloTabella");
        labelTitoloTabella->setEnabled(true);
        labelTitoloTabella->setBaseSize(QSize(1, 20));
        labelTitoloTabella->setStyleSheet(QString::fromUtf8("height: 20px;"));
        labelTitoloTabella->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_3->addWidget(labelTitoloTabella, 0, 0, 1, 1);

        vistaTabella = new QTableView(frameTabella);
        vistaTabella->setObjectName("vistaTabella");
        vistaTabella->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        vistaTabella->setAlternatingRowColors(true);
        vistaTabella->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        vistaTabella->setGridStyle(Qt::PenStyle::SolidLine);
        vistaTabella->setSortingEnabled(false);

        gridLayout_3->addWidget(vistaTabella, 1, 0, 1, 1);


        horizontalLayout->addWidget(frameTabella);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1688, 21));
        menubar->setAcceptDrops(true);
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionCaricaCSV);
        menuFile->addAction(actionSalvaCSV);
        menuFile->addSeparator();
        menuFile->addAction(actionEsci);

        retranslateUi(MainWindow);
        QObject::connect(actionEsci, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", " Sistema Gestione Studenti | Dashboard", nullptr));
        actionCaricaCSV->setText(QCoreApplication::translate("MainWindow", "Carica CSV (obbligatorio)", nullptr));
#if QT_CONFIG(tooltip)
        actionCaricaCSV->setToolTip(QCoreApplication::translate("MainWindow", "Carica dati da file CSV", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionCaricaCSV->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        actionSalvaCSV->setText(QCoreApplication::translate("MainWindow", "Salva file CSV", nullptr));
#if QT_CONFIG(tooltip)
        actionSalvaCSV->setToolTip(QCoreApplication::translate("MainWindow", "Salva dati su file CSV", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionSalvaCSV->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_CONFIG(shortcut)
        actionEsci->setText(QCoreApplication::translate("MainWindow", " Esci", nullptr));
#if QT_CONFIG(tooltip)
        actionEsci->setToolTip(QCoreApplication::translate("MainWindow", "Chiudi l'applicazione", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionEsci->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_CONFIG(shortcut)
        actionPulisciTabella->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
#if QT_CONFIG(tooltip)
        actionPulisciTabella->setToolTip(QCoreApplication::translate("MainWindow", "Svuota la tabella dei risultati", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionPulisciTabella->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+L", nullptr));
#endif // QT_CONFIG(shortcut)
        actionInfo->setText(QCoreApplication::translate("MainWindow", "Informazioni Sistema", nullptr));
#if QT_CONFIG(tooltip)
        actionInfo->setToolTip(QCoreApplication::translate("MainWindow", "Informazioni sul sistema", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(shortcut)
        actionInfo->setShortcut(QCoreApplication::translate("MainWindow", "F1", nullptr));
#endif // QT_CONFIG(shortcut)
        labelMatricola->setText(QCoreApplication::translate("MainWindow", " Matricola Studente:", nullptr));
        lineEditCognome->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserisci il cognome...", nullptr));
        lineEditMateria->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserisci il nome della materia...", nullptr));
        labelMateria->setText(QCoreApplication::translate("MainWindow", "Materia di Studio:", nullptr));
        lineEditMatricola->setPlaceholderText(QCoreApplication::translate("MainWindow", "Inserisci la matricola...", nullptr));
        labelCognome->setText(QCoreApplication::translate("MainWindow", " Cognome Studente:", nullptr));
#if QT_CONFIG(tooltip)
        btnCercaPerMateria->setToolTip(QCoreApplication::translate("MainWindow", "Trova studenti iscritti a materia specifica", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCercaPerMateria->setText(QCoreApplication::translate("MainWindow", "Ricerca Materia", nullptr));
#if QT_CONFIG(tooltip)
        btnCercaPerCognome->setToolTip(QCoreApplication::translate("MainWindow", "Trova studenti con cognome specifico", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCercaPerCognome->setText(QCoreApplication::translate("MainWindow", "Ricerca Cognome", nullptr));
#if QT_CONFIG(tooltip)
        btnCercaPerMatricola->setToolTip(QCoreApplication::translate("MainWindow", "Trova studente per matricola specifica", nullptr));
#endif // QT_CONFIG(tooltip)
        btnCercaPerMatricola->setText(QCoreApplication::translate("MainWindow", "Ricerca Matricola", nullptr));
#if QT_CONFIG(tooltip)
        btnAggiungiStudente->setToolTip(QCoreApplication::translate("MainWindow", "Registra un nuovo studente nel sistema", nullptr));
#endif // QT_CONFIG(tooltip)
        btnAggiungiStudente->setText(QCoreApplication::translate("MainWindow", "+Nuovo Studente", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRicerca), QCoreApplication::translate("MainWindow", "Ricerca degli Studenti", nullptr));
#if QT_CONFIG(tooltip)
        btnListaStudentiCorso->setToolTip(QCoreApplication::translate("MainWindow", "Visualizza tutti gli studenti iscritti ad un corso", nullptr));
#endif // QT_CONFIG(tooltip)
        btnListaStudentiCorso->setText(QCoreApplication::translate("MainWindow", "Lista Studenti del Corso", nullptr));
#if QT_CONFIG(tooltip)
        btnDatiEsamiCorso->setToolTip(QCoreApplication::translate("MainWindow", "Mostra informazioni dettagliate sugli esami", nullptr));
#endif // QT_CONFIG(tooltip)
        btnDatiEsamiCorso->setText(QCoreApplication::translate("MainWindow", "Dati Esami del Corso", nullptr));
#if QT_CONFIG(tooltip)
        btnConteggioStudentiPerCorso->setToolTip(QCoreApplication::translate("MainWindow", "Statistiche numeriche studenti per ogni corso", nullptr));
#endif // QT_CONFIG(tooltip)
        btnConteggioStudentiPerCorso->setText(QCoreApplication::translate("MainWindow", "Conteggio Studenti per Corso", nullptr));
#if QT_CONFIG(tooltip)
        btnConteggioMateriePerCorso->setToolTip(QCoreApplication::translate("MainWindow", "Numero di materie disponibili per corso", nullptr));
#endif // QT_CONFIG(tooltip)
        btnConteggioMateriePerCorso->setText(QCoreApplication::translate("MainWindow", "Conteggio Materie Corso", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestioneCorsi), QCoreApplication::translate("MainWindow", "Gestione dei Corsi", nullptr));
        labelTitoloTabella->setText(QCoreApplication::translate("MainWindow", "|          PARTE TABELLARE         |", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
#if QT_CONFIG(tooltip)
        statusbar->setToolTip(QCoreApplication::translate("MainWindow", "Stato del sistema", nullptr));
#endif // QT_CONFIG(tooltip)
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
