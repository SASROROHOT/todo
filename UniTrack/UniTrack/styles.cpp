#include "styles.h"
#include <QString>

QString styles::getStyle()
{

    return R"(
        QWidget {
            background-color: #1e1e1e;
            color: #d4d4d4;
            font-family: 'Courier New', monospace;
            font-size: 13px;
        }

        QLabel {
            color: #00ff88;
            font-weight: normal;
            height: 20px;
        }

        QTabWidget::pane {
            border: 1px solid #444;
            background: #2a2a2a;
        }

        QTabBar::tab {
            background: #2e2e2e;
            color: #cccccc;
            padding: 5px 10px;
            border: 1px solid #444;
            border-bottom: none;
            font-weight: bold;
        }

        QTabBar::tab:selected {
            background: #1e1e1e;
            color: #00ff88;
            border: 1px solid #00ff88;
            border-bottom: none;
        }

        QFrame {
            background-color: #2b2b2b;
            border: 1px solid #555;
        }

        QPushButton {
            background-color: #333333;
            color: #00ff88;
            border: 1px solid #00ff88;
            padding: 6px 10px;
        }

        QPushButton:hover {
            background-color: #00ff88;
            color: #1e1e1e;
        }

        QPushButton:pressed {
            background-color: #009966;
            color: #ffffff;
        }

        QLineEdit {
            background-color: #111111;
            color: #00ff88;
            border: 1px solid #00ff88;
            padding: 4px;
        }

        QTableView {
            background-color: #1e1e1e;
            color: #dddddd;
            alternate-background-color: #262626;
            gridline-color: #444;
            border: 1px solid #444;
        }

        QHeaderView::section {
            background-color: #00ff88;
            color: #1e1e1e;
            padding: 4px;
            border: 1px solid #00ff88;
        }

        QMenuBar {
            background-color: #2a2a2a;
        }

        QMenuBar::item {
            color: #cccccc;
            background: transparent;
            padding: 4px 8px;
        }

        QMenuBar::item:selected {
            background: #00ff88;
            color: #1e1e1e;
        }

        QStatusBar {
            background-color: #2e2e2e;
            color: #00ff88;
        }

        QGroupBox#groupBoxRisultati {
            padding: 20px;
            margin-top: 10px;
            font-size: 14px;
        }
    )";
}
