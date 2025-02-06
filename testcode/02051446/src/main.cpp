void MainWindow::showSCMFaultTab(int faultLineNumber){
    qDebug() << "31";
    if(faultLineNumber == -1) return;
    QString line = "line " + QString::number(faultLineNumber + 1);
    QTableWidgetItem *item = new QTableWidgetItem(line);
    ui->tableWidgetReport->setItem(0, 1, item);
    ui->verticalLayout->setStretch(0, 0);
    ui->verticalLayout->setStretch(1, 1);
    ui->tabProgramOutput->setCurrentIndex(1);
    ui->tabProgramOutput->show();
    qDebug() << "31";
//    ui->mdiArea->setFocus();
}