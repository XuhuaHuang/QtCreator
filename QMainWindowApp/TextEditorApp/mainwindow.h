#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QAction>
#include <QMenu>
#include <QToolBar>
#include <QMenuBar>
#include <QStatusBar>
#include <QApplication>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createMenu(void);
    void createActions(void);
    void createToolBars(void);
public slots:
    void newFile();
    void open();
    void save();
    void saveAs();
    void about();

private:
    QPlainTextEdit *plntxtedt; // plain text editing field
    QAction *newFileAct; // action to create a new file
    QMenu *fileMenu; // contains available options related to File

    /* BUILD 2 - ADD A TOOLBAR */
    QToolBar *fileToolBar;

    /* BUILD 3 - ADD VARIOUS "QACtion" OBJECT */
    QAction *openAct, *saveAct, *saveAsAct, *closeAct, *exitAct;
    QAction *cutAct, *copyAct, *pasteAct, *aboutAct;

    /* BUILD 4 - ADD VARIOUS BUILD 3 "QActions" TO MENU & DOCKABLE TOOLBAR */
    QMenu *editMenu, *helpMenu;
    QToolBar *editToolBar;
};
#endif // MAINWINDOW_H
