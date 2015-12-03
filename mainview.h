#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>


namespace Ui {
class MainView;


}

class MainView : public QMainWindow
{
    Q_OBJECT


public:

    explicit MainView(QWidget *parent = 0);
    ~MainView();
//    struct ponto
//    {
//        double x; //X POSITION
//        double y; //Y POSITION
//        ponto *pro; //POINTER TO NEXT NODE IN THE LIST
//        ponto *ant; //POINTER TO PREVIOUS NODE IN THE LIST
//        double anglo; //INTERMEDIATE ANGLE VALUE STORAGE
//    };

    struct ponto_a{
        double x;
        double y;
        double anglo;

    };



private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainView *ui;
    // criar um tela
    QGraphicsScene *scene;


    double getRandomNoX();
    double getRandomNoY();

    void GerarPoly1(int n, double raio);
    void GerarPoly2(int n);





//    void grahamInit(int n_pontos);
//    void addPoint(ponto);
//    bool isConvexPoint(ponto *P);
//    void grahamScan(ponto *P);
//    double findAngle(double x1, double y1, double x2, double y2);
//    void drawPermeter(int color, int n_pontos);
//    void drawPoints();
    double getRandomNoX2();
    double getRandomNoY2();




};

#endif // MAINVIEW_H
