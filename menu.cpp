#include "menu.h"
#include "ui_menu.h"
#include <string>
#include <QMessageBox>
#include "connectionbd.h"
#include <QSqlDatabase>
#include<QDesktopServices>
#include <QSqlQueryModel>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>
#include "gestionnaire_client.h"
#include "client.h"
#include "mainwindow.h"
#include<QPrinter>
#include<QPainter>
#include <QDateTimeEdit>
#include<QDate>

menu::menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::menu)
{
    ui->setupUi(this);
    ui->label_19->setText
  (" envoyer une observation avec email ");
}

menu::~menu()
{
    delete ui;
}



void menu::on_delete_2_clicked()
{

    QMessageBox msgBox;
    client C;
    QSqlQuery query;
gestionnaire_client G;

    QString  cin = ui->lineEdit_10->text();
    C.Setcin(cin);

    bool test= G.SupprimerClient(C);
    if(test==true){

     msgBox.setText("suppression avec succés");}


    ui->label_5->hide();




}

void menu::on_load_table_clicked()
{
    gestionnaire_client G;
    ui->tableView->setModel(G.AfficherClient());
}

void menu::on_ajouter_clicked(bool checked)
{
    gestionnaire_client G;
    QString civilite,type_client;
    QMessageBox msg;
    qDebug()<<ui->lineEdit->text();

    if (ui->radioButton->isChecked())
    {
        civilite="M";
    }
    else if (ui->radioButton_2->isChecked())
    {
        civilite="Mme";
    }
    else if (ui->radioButton_3->isChecked())
    {
        civilite="Mle";
    }

    if (ui->checkBox->isChecked())
    {
        type_client="developpeur";
    }
    else if(ui->checkBox_2->isChecked())
    {
        type_client="entreprise";
    }

    client C
               (ui->lineEdit->text() ,
                ui->lineEdit_2->text() ,
                ui->lineEdit_3->text(),
                ui->lineEdit_4->text(),
                ui->lineEdit_12->text(),
                ui->spinBox_3->text(),
                type_client,
                civilite

                );



    if (ui->lineEdit->text().isEmpty())
        {
        QMessageBox::warning(this,"Erreur","Vous devez saisir un cin !");
         ui->lineEdit->setFocus(Qt::OtherFocusReason);
         ui->lineEdit->setStyleSheet("background-color:#FF0000;");
         return;
         }
    else{ui->lineEdit->setStyleSheet("background-color:#FF0000;"); }


    if (ui->lineEdit_2->text().isEmpty())
        {
        QMessageBox::warning(this,"Erreur","Vous devez saisir un nom !");
         ui->lineEdit_2->setFocus(Qt::OtherFocusReason);
         ui->lineEdit_2->setStyleSheet("background-color:#FF0000;");
         return;
         }
    else{ui->lineEdit_2->setStyleSheet("background-color:#FF0001;"); }





    if (ui->lineEdit_3->text().isEmpty())
        {
        QMessageBox::warning(this,"Erreur","Vous devez saisir un prenom !");
         ui->lineEdit_3->setFocus(Qt::OtherFocusReason);
         ui->lineEdit_3->setStyleSheet("background-color:#FF0000;");
         return;
         }
    else{ui->lineEdit_3->setStyleSheet("background-color:#FF0001;"); }

    if (ui->spinBox_3->text()=="0")
        {
        QMessageBox::warning(this,"Erreur","Vous devez saisir une age !");
         ui->spinBox_3->setFocus(Qt::OtherFocusReason);
         ui->spinBox_3->setStyleSheet("background-color:#FF0000;");
         return;
         }
    else{ui->spinBox_3->setStyleSheet("background-color:#FF0000;"); }


    if (ui->lineEdit_4->text().isEmpty())
        {
        QMessageBox::warning(this,"Erreur","Vous devez saisir un email !");
         ui->lineEdit_4->setFocus(Qt::OtherFocusReason);
         ui->lineEdit_4->setStyleSheet("background-color:#FF0000;");
         return;
         }
    else{ui->lineEdit_4->setStyleSheet("background-color:#FF0000;"); }

    if (ui->lineEdit_12->text().isEmpty())
        {
        QMessageBox::warning(this,"Erreur","Vous devez saisir un activité !");
         ui->lineEdit_12->setFocus(Qt::OtherFocusReason);
         ui->lineEdit_12->setStyleSheet("background-color:#FF0000;");
         return;
         }
    else{ui->lineEdit_12->setStyleSheet("background-color:#FF0000;"); }


    qDebug()<<"testttttt"<<C.getcin();
    G.AjouterClient(C);
}

void menu::on_modification_clicked()
{
    connectionBD *conneSQL=new connectionBD();

    gestionnaire_client G;
    QString cin,nom,prenom,email,activite,age,civilite,type_client;
QMessageBox msg;
    client C;
    cin = ui->lineEdit->text();
     nom = ui->lineEdit_2->text();
     prenom = ui->lineEdit_3->text();
     email = ui->lineEdit_4->text();
   activite=  ui->lineEdit_12->text();
     age= ui->spinBox_3->text();
    // civilite= ui->radioButton->text();

      type_client= ui->checkBox->text();

     if (ui->radioButton->isChecked())
     {
         civilite="M";
     }
     else if (ui->radioButton_2->isChecked())
     {
         civilite="Mme";
     }
     else if (ui->radioButton_3->isChecked())
     {
         civilite="Mle";
     }

     if (ui->checkBox->isChecked())
     {
         type_client="developpeur";
     }
     else if(ui->checkBox_2->isChecked())
     {
         type_client="entreprise";
     }

    C.Setcin(cin);
    C.Setnom(nom);
    C.Setprenom(prenom);
    C.Setemail(email);
    C.Setactivite(activite);
    C.Setage(age);
    C.Setcivilite(civilite);
    C.Settype_client(type_client);


    bool test= G.ModifierClient(C);
    if(test==true){

     msg.setText("update avec succés");}

}

void menu::on_load_table_2_clicked()
{
    gestionnaire_client G;
    ui->tableView_2->setModel(G.AfficherClient());
}


void menu::on_pushButton_11_clicked()
{
    hide();
    MainWindow *n=new MainWindow();
    n->show();
}

void menu::on_pushButton_5_clicked()
{


/*        QAxWidget outlook;
            if(outlook.setControl( "Outlook.Application" )){
                 qDebug() << "Success to get Outlook application";
                QAxObject *mail = outlook.querySubObject("CreateItem(olMailItem)");
                if(mail){
                   mail->setProperty("To","toto@titi.com");
                     mail->setProperty("Subject","test automation");
                   mail->setProperty("Body", "Hello, this is the mail body.\n Goodbye");
                    mail->dynamicCall("Display()");
                    //pour l'envoi
                 //   mail->dynamicCall("Send()");
                }
                else
                {
                    qDebug() << "Failed to create mail item";
                }
            }
            else
            {
                qDebug() << "failed to get oultook application";
            }
*/
}

void menu::on_label_19_clicked()
{
    QDesktopServices::openUrl(QUrl("https://mail.google.com/mail/u/0/?tab=wm#inbox?compose=new",
                                   QUrl::TolerantMode));
}

void menu::on_pushButton_6_clicked()
{
    connectionBD *connSQL=new connectionBD();
    QString Idrec;
       QModelIndexList indexes = ui->tableView_2->selectionModel()->selection().indexes();
       if (indexes.isEmpty())
       {
           QMessageBox::warning(this,"Erreur","Veuillez selectioner un client ");
       }
       for (int i=0; i<indexes.count() ; i++)
       { QModelIndex index = indexes.at(i);
           if (index.column() == 0)
           { Idrec = index.data().toString();
               qDebug() << "yyyyyyyyyyyyy"<<Idrec;}}
       QSqlQuery req;
       QString cin,Nom,Prenom,civilite,email,age,activite,type_client;
       QString fileName = QFileDialog::getSaveFileName(0, "Export PDF",
                                                       QString(), "*.pdf");
       if (!fileName.isEmpty()) {
           if (QFileInfo(fileName).suffix().isEmpty())
               fileName.append(".pdf");
           QPrinter printer(QPrinter::HighResolution);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName(fileName);
           printer.setPageMargins(8,3,3,5,QPrinter::Millimeter);
           QPainter painter(&printer);
           qDebug("test");
            QSqlQuery req;
            bool test=req.exec("SELECT * FROM client where cin='"+Idrec+"'");
           qDebug()<<req.lastError().text()<<"test="<<test;
           while (req.next())
   {
            cin = req.value(0).toString();
            Nom = req.value(1).toString();
            Prenom = req.value(2).toString();
            email = req.value(4).toString();
            civilite = req.value(3).toString();
            activite= req.value(5).toString();
            age = req.value(6).toString();
            type_client = req.value(7).toString();
            qDebug()<<"iddd"<<cin;
   }
           painter.drawText(180,100,"cin:"+Idrec);
           painter.drawText(180,300,"nom:"+Nom);
           painter.drawText(180,500,"prenom:"+Prenom);
           painter.drawText(180,700,"civilite:"+civilite);
           painter.drawText(180,900,"email:"+email);
           painter.drawText(180,1100,"activite:"+activite);
           painter.drawText(180,1300,"age:"+age);
           painter.drawText(180,1500,"type_client:"+type_client);
       }

}


void menu::on_pushButton_2_clicked()
{
    connectionBD *connSQL=new connectionBD();
    QSqlQuery* query=new QSqlQuery;
    QSqlQueryModel * model=new QSqlQueryModel();
   // QSqlQuery query;
    client C;

    QString l,email;
    if (ui->lineEdit_11->text().isEmpty())
    {
     QMessageBox::warning(this,"Erreur","Veuillez saisir un client qui à contacter ");
    }
    l=ui->lineEdit_11->text();
    bool a=query->exec("select email from client where cin='"+l+"'");
    if (a==true)
{    model->setQuery(*query);
    ui->tableView_4->setModel(model);
    }else      QMessageBox::warning(this,"Erreur"," le client n'existe pas ");

   // email= query.value(0).toString();
  //  ui->label_15->text("");



}



void menu::on_pushButton_8_clicked()
{
    connectionBD *connSQL=new connectionBD();
    gestionnaire_client g;
        ui->tableView_3->setModel(g.prix_max());
}

void menu::on_pushButton_7_clicked()
{
    connectionBD *connSQL=new connectionBD();
    gestionnaire_client g;
        ui->tableView_3->setModel(g.prix_min());
}



void menu::on_pushButton_9_clicked()
{
    connectionBD *connSQL=new connectionBD();
    gestionnaire_client g;
        ui->tableView_3->setModel(g.produit_plus_vendus());
}
