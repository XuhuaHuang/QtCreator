#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    plntxtedt = new QPlainTextEdit();
    this->setCentralWidget(plntxtedt);
    createActions();
    createMenu();

    /* BUILD 2 - ADD A TOOLBAR */
    createToolBars();
    statusBar()->showMessage("Ready");

    setWindowIcon(QIcon("./images/editor.png"));
    resize(400, 500);
}

MainWindow::~MainWindow() {}

void MainWindow::createActions()
{
    newFileAct = new QAction(QIcon("./images/new.png"), tr("&New"), this);
    newFileAct->setShortcuts(QKeySequence::New);
    // QKeySequence defaults to "Ctrl + N"
    newFileAct->setStatusTip(tr("Create a new file"));
    connect(newFileAct, SIGNAL(triggered()), this, SLOT(newFile()));

    /* BUILD 3 - ADD VARIOUS "QACtion" OBJECTS & CONNECT CUSTOM SIGNALS */
    /* To open a new file */
    openAct = new QAction(QIcon("images/open.png"), "&Open...", this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip("Open an existing file");
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    /* To save a file */
    saveAct = new QAction(QIcon("images/save.png"), "&Save", this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip("Save the document to disk");
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    /* To save a file in a different name */
    saveAsAct = new QAction(QIcon("images/saveAs.png"), "Save &As...", this);
    saveAsAct->setShortcuts(QKeySequence::SaveAs);
    saveAsAct->setStatusTip("Save the document under a new name");
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    /* To close a file */
    closeAct = new QAction(QIcon("images/close.png"), "&Close", this);
    closeAct->setShortcut(Qt::CTRL + Qt::Key_W);
    closeAct->setStatusTip("Close this window");
    connect(closeAct, SIGNAL(triggered()), this, SLOT(close()));

    /* To exit the application */
    exitAct = new QAction(QIcon("images/exit.png"), "E&xit", this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip("Exit the application");
    connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));
    // connect(exitAct, SIGNAL(triggered()), qApp, SLOT(quit()));

    /* To cut selected texts when the copyAvailable() signal is emitted */
    cutAct = new QAction(QIcon("images/cut.png"), "Cu&t", this);
    cutAct->setShortcuts(QKeySequence::Cut);
    cutAct->setStatusTip("Cut the current selection's contents to the clipboard");
    connect(cutAct, SIGNAL(triggered()), plntxtedt, SLOT(cut()));

    /* To copy selected texts when the copyAvailable() signal is emitted */
    copyAct = new QAction(QIcon("images/copy.png"), "&Copy", this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip("Copy the current selection's contents to the clipboard");
    connect(copyAct, SIGNAL(triggered()), plntxtedt, SLOT(copy()));

    /* To paste selected texts */
    pasteAct = new QAction(QIcon("images/paste.png"), "&Paste", this);
    pasteAct->setShortcuts(QKeySequence::Paste);
    pasteAct->setStatusTip("Paste the clipboard's contents into the current selection");
    connect(pasteAct, SIGNAL(triggered()), plntxtedt, SLOT(paste()));

    /* TO show About information */
    aboutAct = new QAction(QIcon("images/about.png"), "&About", this);
    aboutAct->setStatusTip("Show the application's About information");
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    cutAct->setEnabled(false);
    copyAct->setEnabled(false);
    connect(plntxtedt, SIGNAL(copyAvailable(bool)),cutAct, SLOT(setEnabled(bool)));
    connect(plntxtedt, SIGNAL(copyAvailable(bool)),copyAct, SLOT(setEnabled(bool)));
}

void MainWindow::createMenu()
{
    fileMenu = menuBar()->addMenu("&File");
    fileMenu->addAction(newFileAct);

    /* BUILD 4 - ADD VARIOUS BUILD 3 "QActions" TO MENU & DOCKABLE TOOLBAR */
    /* Add file related actions */
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(closeAct);
    fileMenu->addAction(exitAct);

    /* Add text editting related actions */
    editMenu = menuBar()->addMenu("&Edit");
    editMenu->addAction(cutAct);
    editMenu->addAction(copyAct);
    editMenu->addAction(pasteAct);

    menuBar()->addSeparator();

    /* Add action to show About information */
    helpMenu = menuBar()->addMenu("&Help");
    helpMenu->addAction(aboutAct);
}

void MainWindow::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newFileAct);

    /* BUILD 4 - ADD VARIOUS BUILD 3 "QActions" TO MENU & DOCKABLE TOOLBAR */
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    /* Add ToolBar related to editting field */
    editToolBar = addToolBar(tr("Edit"));
    editToolBar->addAction(cutAct);
    editToolBar->addAction(copyAct);
    editToolBar->addAction(pasteAct);
}

void MainWindow::newFile()
{
    statusBar()->showMessage("New file Created");
}

void MainWindow::open()
{

}

void MainWindow::save()
{

}

void MainWindow::saveAs()
{

}

void MainWindow::about()
{

}
