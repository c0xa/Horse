#ifndef GRAPHWIDGET_H
#define GRAPHWIDGET_H

#include <QGraphicsView>
#include <QDomNode>
#include <QMessageBox>
#include <QDomElement>
#include <QKeyEvent>
#include <QGraphicsTextItem>
#include <QRandomGenerator>
#include <QFile>
#include <QScrollBar>
#include <QLine>
#include <QXmlStreamReader>
#include <QDebug>

class Node;

class GraphWidget : public QGraphicsView
{
    Q_OBJECT

public:

    GraphWidget(QWidget *parent = nullptr);

    void readRootElement(QDomElement root);
    void parseXmlAndDraw(QRectF* parent, QDomElement root, int arrayCountChild[], int level);
    void run();
    void read();
    void processRates();
    void processRate();
    QString readNextText();

    QString getStringJson(QJsonObject jobj, QString key);
    QRectF getRect(QString text, int xpos, int ypos);
    int calculateX(int index);
    void countLevel(QDomElement root);
    QLineF* getLineBetweenRects(QRectF* parent, QRectF rect);
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

protected:
#if QT_CONFIG(wheelevent)
    void wheelEvent(QWheelEvent *event) override;
#endif
    void scaleView(int scaleFactor);

private:
    QGraphicsScene* scene;
    QPainter *painter;
    QString _filename;
    bool rightMousePressed = false;
    int _panStartY = 0;
    int _panStartX = 0;
    int x = 0;
    int y = 0;
    int size = 0;
};

#endif
