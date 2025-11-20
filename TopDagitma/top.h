#ifndef TOP_H
#define TOP_H

#include <QWidget>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QElapsedTimer>

class Top : public QWidget
{
    Q_OBJECT
public:
    explicit Top(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
    void moveTop();
    QString setImage();
    //oid hizBulma(int *hiz);


private:
    QPixmap resim;
    QTimer *zamanlayici;
    double px, py;
    double dx, dy;
};

#endif // TOP_H
