#ifndef MYQGRAPHICSSCENE_H
#define MYQGRAPHICSSCENE_H

#include "segmentation-manager/slice.h"

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

class MyQGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    MyQGraphicsScene(QObject *parent = 0);

    void setSlice( Slice* slice );
    void updateSliceDisplayer();
    void updateSeedsDisplayer();
    void updateResultDisplayer();
    QGraphicsItemGroup* getResultItemGroup();
    QGraphicsPixmapItem* getSlicePixmapItem();
    void setGridVisibility( bool visible );

public slots:
    void mouseMoveEvent( QGraphicsSceneMouseEvent * mouseEvent );
    void mouseReleaseEvent( QGraphicsSceneMouseEvent * mouseEvent );
    void drawForeground( QPainter *painter, const QRectF &rect );

private:
    Slice* slice;
    bool firstClick;
    QPointF firstPoint;
    QPointF lastPoint;
    bool gridVisible;
    QGraphicsPixmapItem* slicePixmapItem;

    QList<QGraphicsItem *> resultDraw;
    QGraphicsItemGroup * resultZone;

    QList<QGraphicsItem *> sliceDraw;
    QGraphicsItemGroup * sliceZone;

    QList<QGraphicsItem *> seedsDraw;
    QGraphicsItemGroup * seedsZone;

    QList<QGraphicsItem *> itemDraw;
    QGraphicsItemGroup * drawZone;


    QGraphicsPixmapItem* setSlicePixmap( QPixmap pix );
    QGraphicsRectItem* addSeed( qreal x, qreal y, qreal w, qreal h, const QColor& seedColor = QColor() );
    QGraphicsPixmapItem* setResultPixmap( QPixmap pix );

    QGraphicsRectItem *drawRectangle( QPointF pointHG, QPointF pointBD );

signals:
    void drawnRectangle( float x, float y, float width, float height );
    void mouseMoved( QPointF mousePosition );
};

#endif // MYQGRAPHICSSCENE_H
