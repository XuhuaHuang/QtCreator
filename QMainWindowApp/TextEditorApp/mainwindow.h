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
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void createMenu(void);
    void createActions(void);
    void createToolBars(void);

    /* BUILD 5 - FINISH OFF APP */
    void init();
    void loadFile(const QString &fileName);
    void saveFile(const QString &fileName);
    void setName(const QString &fileName);
    void reset(const QString &fileName);
    void clearUntitledWin(); // close untitiled window
    void load();
public slots:
    void newFile();
    void open();
    void save();
    void saveAs();
    void about();
    void windowIsMod();
protected:
    void closeEvent(QCloseEvent *event);
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

    /* BUILD 5 - FINISH OFF */
    QString curFileName; // current file name
};
#endif // MAINWINDOW_H
