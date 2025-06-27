
//"ek_ozellik" FONKSİYONUNU EKLEDİM EK ÖZELLİK OLARAK.OYUN BİTTİĞİNDE KULLANICI ADINI İSTİYOR.
//PROJEDE VERDİĞİM FORMATTAKİ DOSYADAN KULLANICI
//ADINI VE SKORUNU ALARAK KARŞILAŞTIRMA YAPIYOR VE EĞER MAX SKORU GEÇTİYSE GEÇTİĞİ KİŞİNİN KULLANICI
//ADINI VERİYOR BİLGİ OLARAK. EĞER YENİ KULLANICIYSA ALT SATIRA SKORU VE İSMİ KAYDEDİLİYOR DEĞİLSE
//İSMİNİN YANINA SKORU EKLENİYOR.

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    baslangic_suresi = 30;
    zamanlayici_guncelle();

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->start(1000);

    QString filePath = QStringLiteral(":/file/konumlar.txt");
    konumlari_dosyadan_oku(filePath);

    movementTimer = new QTimer(this);
    connect(movementTimer, &QTimer::timeout, this, &MainWindow::karpuz_hareketi);
    movementTimer->start(100);

    kesilen_karpuz = 0;
    kacirilan_karpuz = 0;
    ui->label->installEventFilter(this);

}
MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete movementTimer;

}
void MainWindow::updateTime()
{
    if (baslangic_suresi  > 0) {
        baslangic_suresi--;
        zamanlayici_guncelle();
    } else {
        timer->stop();
        movementTimer->stop();
        ek_ozellik();
        return;
    }
}


//SÜREYİ Uİ EKRANINDA GÜNCELLEYEN FONKSİYON
void MainWindow::zamanlayici_guncelle()
{
    ui->label_sure->setText(QString::number(baslangic_suresi));
}


//KESİLEN KARPUZ SAYISINI Uİ EKRANINDA GÜNCELLEYEN FONKSİYON
void MainWindow::kesilen_karpuz_guncelle()
{
    ui->label_kesilen_sayisi->setText(QString::number(kesilen_karpuz));
}


//KONUMLAR.TXT DOSYASINDAN OKUMA YAPAN FONKSİYON
void MainWindow::konumlari_dosyadan_oku(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Dosya açılamadı!";
        return;
    }
    QTextStream in(&file);
    QVector<QPoint> positions;
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList tokens = line.split(" ");
        if (tokens.size() >= 2) {
            int x = tokens[0].toInt();
            int y = tokens[1].toInt();
            positions.append(QPoint(x, y));
        }
    }
    file.close();
    QTimer *addWatermelonTimer = new QTimer(this);
    connect(addWatermelonTimer, &QTimer::timeout, [=]() mutable {
        QVector<QPoint> mutablePositions = positions;
        if (!mutablePositions.isEmpty()) {
            QPoint position = mutablePositions.takeAt(rand() % mutablePositions.size());
            karpuz_olustur(position.x(), position.y());
        }
    });
    addWatermelonTimer->start(700);
}


//TIKLAMAYLA KESİLMİŞ KARPUZU EKLEYEN FONKSİYON
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QLabel *clickedLabel = qobject_cast<QLabel*>(childAt(event->pos()));
    if (clickedLabel && clickedLabel->objectName() == "karpuz_label") {
        clickedLabel->setPixmap(QPixmap(":/kesikkarpuz/karpuzlar/2.png").scaled(70, 70));
        QTimer::singleShot(1000, clickedLabel, [=]() {
            clickedLabel->clear();
            clickedLabel->deleteLater();
        });
        kesilen_karpuz++;
        kesilen_karpuz_guncelle();
    }
    QMainWindow::mousePressEvent(event);
}


//KARPUZ OLUŞTURAN FONKSİYON
void MainWindow::karpuz_olustur(int x, int y)
{
    if (baslangic_suresi <= 0) {
        return;
    }
    QLabel *karpuz = new QLabel(this);
    karpuz->setObjectName("karpuz_label");
    karpuz->setPixmap(QPixmap(":/tumkarpuz/karpuzlar/1.png").scaled(70, 70));
    karpuz->setFixedSize(70, 70);
    karpuz->move(x, y);
    karpuz->show();
}


//KARPUZLARIN HAREKETİNİ SAĞLAYAN FONKSİYON
void MainWindow::karpuz_hareketi()
{
    for (QLabel *karpuz : this->findChildren<QLabel*>()) {
        if (karpuz->objectName() == "karpuz_label") {
            if (karpuz->y() > this->height() || karpuz->x() > this->width()) {
                karpuz->deleteLater();
                kacirilan_karpuz++;
                ui->label_kacirilan_sayisi->setText(QString::number(kacirilan_karpuz));
            } else {
                karpuz->move(karpuz->x(), karpuz->y() + 5);
            }
        }
    }
}


/*EK ÖZELLİK EKLENMEDEN ÖNCEKİ,VERDİĞİNİZ SKOR DOSYASINDAN OKUYARAK İŞLEM YAPTIĞI HALİ.
void MainWindow::endGame()
{
    timer->stop();
    movementTimer->stop();
    QString resultMessage;

    QFile scoreFile(":/file/skorlar.txt");
    if (scoreFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&scoreFile);
        int maxScore = 0;
        while (!in.atEnd()) {
            QString line = in.readLine();
            int score = line.toInt();
            maxScore = qMax(maxScore, score);
        }
        scoreFile.close();

        if (kesilen_karpuz > maxScore) {
            resultMessage = "Oyun Bitti.Tebrikler! En yüksek skoru geçtiniz!";
        } else {
            resultMessage = "Oyun Bitti. Maalesef en yüksek skoru geçemediniz.";
        }
        resultMessage += "\nMaksimum Skor: " + QString::number(maxScore);

    } else {
        resultMessage = "Skor dosyası okunamadı.";
    }

    QFile file(":/file/skorlar.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Append)) {
        QTextStream out(&file);
        out << kesilen_karpuz << "\n";
        file.close();
    }
    // Bilgi ekranını göster
    QMessageBox::information(this,"Oyun Bitti!",
                                "\n" + (resultMessage)+
                                "\n Kesilen Karpuz Sayısı: " + QString::number(kesilen_karpuz) +
                                "\nKaçırılan Karpuz Sayısı: " + QString::number(kacirilan_karpuz));
}*/


//EK ÖZELLİKLE BİRLİKTE SON HALİ
void MainWindow::ek_ozellik() {
    QString oyuncu_ismi = QInputDialog::getText(this, "KULLANICI ADI", "LÜTFEN KULLANICI ADINIZI GİRİNİZ:");

    //****************DOSYA YOLU****************
    //RESOURCE YAPMAYA ÇALIŞTIM DOSYAYI OKUMADI
    QFile scoreFile("/Users/sareeken/Desktop/22100011016/skorlar.txt");
    if (scoreFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QTextStream in(&scoreFile);
        QVector<QStringList> playerScores;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList parts = line.split(" ", Qt::SkipEmptyParts);
            if (parts.size() >= 2) {
                playerScores.append(parts);
            }
        }
        int maxScore = 0;
        QString maxPlayer;
        for (const QStringList& playerScore : playerScores) {
            for (int i = 1; i < playerScore.size(); ++i) {
                int score = playerScore[i].toInt();
                if (score > maxScore) {
                    maxScore = score;
                    maxPlayer = playerScore[0];
                }
            }
        }
        int playerIndex = -1;
        for (int i = 0; i < playerScores.size(); ++i) {
            if (playerScores[i][0] == oyuncu_ismi) {
                playerIndex = i;
                break;
            }
        }
        if (playerIndex == -1) {
            QStringList newPlayerScore;
            newPlayerScore.append(oyuncu_ismi);
            newPlayerScore.append(QString::number(kesilen_karpuz));
            playerScores.append(newPlayerScore);
        } else {
            playerScores[playerIndex].append(QString::number(kesilen_karpuz));
        }
        scoreFile.resize(0);
        QTextStream out(&scoreFile);
        for (const QStringList& playerScore : playerScores) {
            out << playerScore.join(" ") << "\n";
        }
        scoreFile.close();
        QString resultMessage;
        if (kesilen_karpuz > maxScore) {
            resultMessage += "\nOyun Bitti.Tebrikler! En yüksek skoru geçtiniz!";
        } else {
            resultMessage += "\nOyun Bitti.Maalesef en yüksek skoru geçemediniz.";
        }
        resultMessage += "\nEn Yüksek Skor: " + QString::number(maxScore) +
                         "\nEn Yüksek Skor Sahibi: (" + maxPlayer + ")";
        resultMessage += "\nKesilen Karpuz Sayısı: " + QString::number(kesilen_karpuz) +
                         "\nKaçırılan Karpuz Sayısı: " + QString::number(kacirilan_karpuz);

        QMessageBox::information(this, "Oyun Bitti!", resultMessage);
    } else {
        QMessageBox::warning(this, "Hata", "Skor dosyası açılamadı!");
    }
}




