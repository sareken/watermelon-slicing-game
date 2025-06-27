// SARE EKEN 22100011016
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QLabel>
#include <QMessageBox>
#include <QPixmap>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QMouseEvent>
#include <QPoint>
//#include <QPointerEvent>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void updateTime();
    void zamanlayici_guncelle();
    void ek_ozellik();
    void kesilen_karpuz_guncelle();
    void konumlari_dosyadan_oku(const QString &fileName);
    void karpuz_olustur(int x, int y);
    void karpuz_hareketi();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int baslangic_suresi;
    int kacirilan_karpuz;
    int kesilen_karpuz;
    QTimer *movementTimer;
    QVector<QPoint> watermelonPositions;
protected:
    void mousePressEvent(QMouseEvent *event) override;
};
#endif // MAINWINDOW_H
