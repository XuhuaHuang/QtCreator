/*****************************************************************//**
 * \file   filedialog.cpp
 * \brief  Contains implementation for class FileDialog
 * 
 * \author Xuhua Huang
 * \date   April 2021
 *********************************************************************/

#include "filedialog.h"

FileDialog::FileDialog(QWidget *parent)
    : QWidget(parent)
{
    /* INSTANCIATE PRIVATE ATTRIBUTES */
    openFileBtn = new QPushButton("Open Text File");
    saveFileBtn = new QPushButton("Save File");
    plnTxtEdt = new QPlainTextEdit();

    /* Layout Manager */
    btnHbox = new QHBoxLayout();
    vbox = new QVBoxLayout();

    /* SET APPLICATION LAYOUT */
    btnHbox->addWidget(openFileBtn); btnHbox->addWidget(saveFileBtn);
    vbox->addLayout(btnHbox);
    vbox->addWidget(plnTxtEdt);
    setLayout(vbox);
    setWindowTitle("File Dialog");
    setWindowIcon(QIcon("./images/editor.png"));
    resize(400, 500);

    /* CONNECT SIGNALS AND SLOTS */
    connect(openFileBtn, SIGNAL(clicked()), this, SLOT(openBtnClicked()));
    connect(saveFileBtn, SIGNAL(clicked()), this, SLOT(saveBtnClicked()));
}

FileDialog::~FileDialog() {}

void FileDialog::openBtnClicked()
{
    qDebug() << "FileDialog::openBtnClicked() invoked" << endl;
    // default filter
    QString fileFilter = tr("Text Files (*.txt)");
    // retreive the file name with path
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Text Files"), "C:/",
        tr("Text Files (*.txt)"), &fileFilter);
    // create a QFile object with known file path
    QFile data(fileName);
    // string to store actual content in the file
    QString content;

    if (data.open(QFile::ReadOnly)) {
        QTextStream in(&data);
        in.setCodec("UTF-8");
        // clelar text edit field
        plnTxtEdt->clear();
        do {
            content = in.readLine();
            plnTxtEdt->insertPlainText(content + "\n");
            // start a new line at the end of each read line
        } while (!content.isNull());
    } // end reading QFile object
    data.close();
}

void FileDialog::saveBtnClicked()
{
    qDebug() << "FileDialog::saveBtnClicked() invoked" << endl;
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Save Text File"), "C:/untitled.txt", // default to "untitled.txt"
        tr("Text Files (*.txt)"));
    // check if provided file name is empty
    if (fileName != NULL) { // valid file name
        // create file object to write to
        QFile outputFile(fileName);
        // check if the file can be opened to write
        if (outputFile.open(QFile::WriteOnly)) {
            // create an output stream object with overloaded constructor
            // pass the pointer to output file as the argument
            QTextStream out(&outputFile);
            // tolerate any languages with UTF-8 encoder
            out.setCodec("UTF-8");
            out << plnTxtEdt->toPlainText(); // write to file
        }
        outputFile.close();
    }
    else { // if provided file name is empty, throw a critical error
        QMessageBox::critical(this,
                              tr("Error"),
                              tr("File name is not specified."));
    }
}
