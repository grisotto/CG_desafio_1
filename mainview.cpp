#include "mainview.h"
#include "ui_mainview.h"
#include "math.h"
#include "time.h"
#include <QVector>
#include <algorithm>
#include <iostream>


bool operator<(const MainView::ponto_a& a, const MainView::ponto_a& b) { return a.anglo < b.anglo; }



//MainView::ponto* firstPoint;
//MainView::ponto pontos_temp2[200];

MainView::MainView(QWidget *parent) :
    QMainWindow(parent),

    ui(new Ui::MainView)
{
     ui->setupUi(this);
     this->setWindowState(Qt::WindowMaximized);
     scene = new QGraphicsScene(this);
     ui->graphicsView->setScene(scene);
     ui->graphicsView->setRenderHint(QPainter::Antialiasing);
     scene->setSceneRect(-200,-200,300,300);
     srand(time(NULL));





}

MainView::~MainView()
{
    delete ui;
}

void MainView::on_pushButton_clicked()
{
    scene->clear();
    int n;
    double raio;
    QString n_string=ui->le_n->text();
    QString raio_string=ui->le_raio->text();
    n = n_string.toInt();
    raio = raio_string.toDouble();


    GerarPoly1(n,raio);



}
void MainView::GerarPoly1(int n, double raio)
{
    int i;



    ponto_a pontos[n];
      QVector<ponto_a> pontoss;




// 1 - ordenar o valor do raio a partir da lista
// achar a distancia dos pontos mais distantes, achar o ponto medio entre eles, após
// calcular o raio entre cada um dos pontos e ordenar estes raio com os pontos

    for (i = 0; i < n; i++) {


                 raio =  getRandomNoY2();
                 pontos[i].anglo = raio;


                 pontos[i].x = raio * cos(2*M_PI*(i+1)/n);


                pontos[i].y = raio * sin(2*M_PI*(i+1)/n );


         scene->addEllipse(pontos[i].x, pontos[i].y, 1*3.0, 1*3.0,
                QPen(), QBrush(Qt::SolidPattern));



    }
    // ordena uma struct em Qt
    //lendo um elemento
   //    pontoss.append(pontos[i]);


//    for (int j = 0; j < n; j++) {
//        std::cout<<"X:"<<pontoss.at(j).x;
//        std::cout<<" Y:"<<pontoss.at(j).y;
//        std::cout<<" Anglo:"<<pontoss.at(j).anglo<<std::endl;

//    }


//    std::sort(pontoss.begin(), pontoss.end());

//     std::cout<<"Depois:"<<std::endl;
//    for (int j = 0; j < n; j++) {
//        std::cout<<"X:"<<pontoss.at(j).x;
//        std::cout<<" Y:"<<pontoss.at(j).y;
//        std::cout<<" Anglo:"<<pontoss.at(j).anglo<<std::endl;


//    }

//    for (i = 0; i < n; i++) {


//        if((i+1) == n ){
//            scene->addLine(pontoss.at(i).x ,pontoss.at(i).y ,pontoss.at(0).x ,pontoss.at(0).y,
//                QPen());
//        }
//        else
//        {
//            scene->addLine(pontoss.at(i).x ,pontoss.at(i).y ,pontoss.at(i+1).x ,pontoss.at(i+1).y,
//                    QPen());

//        }

//    }

    for (i = 0; i < n; i++) {


        if((i+1) == n ){
            scene->addLine(pontos[i].x ,pontos[i].y ,pontos[0].x ,pontos[0].y,
                QPen());
        }
        else
        {
            scene->addLine(pontos[i].x ,pontos[i].y ,pontos[i+1].x ,pontos[i+1].y,
                    QPen());

        }

    }







}






void MainView::on_pushButton_2_clicked()
{
    scene->clear();
//    int n_pontos, n_poly;


//    QString n_string=ui->le_n->text();
//    n_pontos = n_string.toInt();
//    QString n_poly_string=ui->le_raio->text();
//    n_poly = n_poly_string.toInt();

    //GerarPoly2(n_pontos);
//    grahamInit(n_pontos);
//    drawPoints();
//    drawPermeter(1,n_pontos);
//    grahamScan(firstPoint->pro);
//    drawPermeter(2,n_pontos);






}
//void MainView::drawPoints()
//{
//    ponto *curPoint = firstPoint;

//    do
//    {
//          scene->addEllipse(curPoint->x, curPoint->y, 1*5.0, 1*5.0,
//                QPen(), QBrush(Qt::SolidPattern));
//        curPoint=curPoint->pro;
//    } while (curPoint!=firstPoint);

//    return;
//}

//void MainView::GerarPoly2(int n)
//{
//    int i;


//    for (i = 0; i < n; i++) {


//                pontos_temp2[i].x = getRandomNoX();
//                pontos_temp2[i].y = getRandomNoY();



//        scene->addEllipse(pontos_temp2[i].x, pontos_temp2[i].y, 1*5.0, 1*5.0,
//                QPen(), QBrush(Qt::SolidPattern));


//    }

//}
//void MainView::grahamInit(int n_pontos)
//{
//    int minPoint=0;

//        ponto pontos_temp[1000];
//        ponto *tempPtr;

//        firstPoint=NULL;
//        //gerando pontos aleatorios
//        for (int i=0;i<n_pontos;i++)
//        {
//            pontos_temp[i].x=getRandomNoX();

//            pontos_temp[i].y=getRandomNoY();

//            scene->addEllipse(pontos_temp[i].x, pontos_temp[i].y, 1*5.0, 1*5.0,
//                    QPen(), QBrush(Qt::SolidPattern));


//        }
//        //encontrando o menor ponto
//        for (int k=1;k<n_pontos;k++)
//            if (pontos_temp[k].y<pontos_temp[minPoint].y)
//                minPoint=k;

//        //ordenar os pontos aliatorios
//        for (int i=0;i<n_pontos;i++)
//        {
//            pontos_temp[i].anglo=findAngle(pontos_temp[minPoint].x,pontos_temp[minPoint].y,pontos_temp[i].x,pontos_temp[i].y);
//            addPoint(pontos_temp[i]);
//        }

//        tempPtr=firstPoint;
//        do  //procura o ultimo no na lista linkada
//        {
//            tempPtr=tempPtr->pro;
//        } while (tempPtr->pro!=NULL);
//        //completa a lista circular
//        tempPtr->pro=firstPoint;
//        firstPoint->ant=tempPtr;

//        tempPtr=firstPoint->pro;

//        //linhas do menor ponto ate todos os outros
//        for (int i=1;i<n_pontos;i++)
//        {
//            //drawLine(firstPoint, tempPtr, 3);
//            scene->addLine(firstPoint->x ,firstPoint->y ,tempPtr->x ,tempPtr->y,
//                    QPen(Qt::yellow));
//            tempPtr=tempPtr->pro;
//        }



//}

//void MainView::addPoint(ponto Ponto)
//{
//    ponto *tempPoint,*tempPointA,*tempPointB, *curPoint;


//    tempPoint = new ponto;
//    tempPoint->x=Ponto.x;
//    tempPoint->y=Ponto.y;
//    tempPoint->anglo=Ponto.anglo;
//    tempPoint->pro=NULL;
//    tempPoint->ant=NULL;

//    //testa se a lista eh vazia
//    if (firstPoint==NULL)
//    {
//        firstPoint=tempPoint;
//        return;
//    }

//    if (firstPoint->pro==NULL && tempPoint->anglo >= firstPoint->anglo)

//    //testa se um nó na lista e o nó atual tem um angulo grande
//    {
//        firstPoint->pro=tempPoint;
//        tempPoint->ant=firstPoint;
//        return;
//    }

//    curPoint=firstPoint;

//    while (tempPoint->anglo >= curPoint->anglo && curPoint->pro!=NULL)

//        curPoint=curPoint->pro;

//    if (curPoint==firstPoint)
//    {
//        firstPoint->ant=tempPoint;
//        tempPoint->pro=firstPoint;
//        firstPoint=tempPoint;
//        return;
//    }
//    else if (curPoint->pro==NULL && tempPoint->anglo >= curPoint->anglo)

//    {
//        curPoint->pro=tempPoint;
//        tempPoint->ant=curPoint;
//        return;
//    }
//    else
//    {

//        tempPointA=curPoint->ant;
//        tempPointB=curPoint->ant->pro;
//        tempPoint->pro=tempPointB;
//        tempPoint->ant=tempPointA;
//        tempPoint->ant->pro=tempPoint;
//        tempPoint->pro->ant=tempPoint;
//    }

//    return;
//}

//bool MainView::isConvexPoint(ponto* P)
//{
//    //calcula o angulo horario
//    double CWAngle=findAngle(P->x,P->y,P->ant->x,P->pro->y);
//    //calcula o angulo antihorario
//    double CCWAngle=findAngle(P->x,P->y,P->pro->x,P->pro->y);
//    double difAngle;

//    //drawLine(P->ant, P->pro, 3);
//    scene->addLine(P->ant->x ,P->ant->y ,P->pro->x ,P->pro->y,
//           QPen(Qt::yellow));

//    if (CWAngle>CCWAngle)
//    {
//        //calcula a diferenca entre dois angulos
//        difAngle=CWAngle-CCWAngle;

//        if (difAngle>180)
//            //ponto eh conclave
//            return false;
//        else
//            // o ponto eh convexo
//            return true;
//    }
//    else if (CWAngle<CCWAngle)
//    {
//        //calcula a diferenca entre dois angulos
//        difAngle=CCWAngle-CWAngle;

//        if (difAngle>180)
//            //ponto eh conclave
//            return true;
//        else
//            // o ponto eh convexo
//            return false;
//    }
//    else if (CWAngle == CCWAngle)
//        //ponto eh colinear
//    return false;
//}

//void MainView::grahamScan(ponto *P)
//{
//    ponto *tempPrev, *tempNext;

//    //retorna se for o primeiro ponto.
//    if (P==firstPoint)
//        return;
//    //se o ponto eh conclave, elimina do perimetro
//    if (!isConvexPoint(P))
//    {
//        tempPrev=P->ant;
//        tempNext=P->pro;
//        tempPrev->pro=tempNext;
//        tempNext->ant=tempPrev;
//        //drawLine(tempPrev, tempNext,3); //DRAW LINE SHOWING NEW EDGE
//       scene->addLine(tempPrev->x ,tempPrev->y ,tempNext->x ,tempNext->y,
//                QPen(Qt::yellow));
//        delete P; //FREE MEMORY
//        // roda a funcao novamente com o ponto anterior para chegar se a conectividade foi alterada
//        grahamScan(tempPrev);

//    }
//    else // o ponto eh convexo
//        grahamScan(P->pro); // verificar o proximo ponto
//}


//double MainView::findAngle(double x1, double y1, double x2, double y2)
//{
//    double deltaX=(double)(x2-x1);
//    double deltaY=(double)(y2-y1);
//    double angle;

//    if (deltaX==0 && deltaY==0)
//        return 0;

//    angle=atan2(deltaY,deltaX)*57.295779513082;

//   if (angle < 0)
//    angle += 360.;

//    return angle;
//}

//void MainView::drawPermeter(int color, int n_pontos)
//{
//    ponto *tempPtr=firstPoint;

//    for (int i=0;i<n_pontos;i++)
//    {
//       // drawLine(tempPtr, tempPtr->next, color);  //DRAW LINE
//        if(color == 1){
////          scene->addLine(tempPtr->x ,tempPtr->y ,tempPtr->pro->x ,tempPtr->pro->y,
////                   QPen(Qt::blue));

//        }
//        else{
//            scene->addLine(tempPtr->x ,tempPtr->y ,tempPtr->pro->x ,tempPtr->pro->y,
//                    QPen(Qt::red));

//        }

//        tempPtr=tempPtr->pro;
//    }
//}










double MainView::getRandomNoX()
{
    //-900,800
    double max = 600.0;
    double min = -700.0;
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}
double MainView::getRandomNoY()
{
    //-400,300
    double max = 200.0;
    double min = - 300.0;
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

double MainView::getRandomNoX2()
{
    //-900,800
    double max = 300.0;
    double min = -700.0;
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}
double MainView::getRandomNoY2()
{
    //-400,300
    double max = 360.0;
    double min = 0;
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}








void MainView::on_pushButton_3_clicked()
{

}
