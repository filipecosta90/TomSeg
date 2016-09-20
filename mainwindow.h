#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "seedinfo.h"
#include "sliceinfo.h"
#include "myqgraphicsscene.h"

#include "segmentation-manager/segmentationmanager.h"

#include <QMainWindow>
#include <QVector>
#include <QGraphicsScene>
#include <QTableWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void on_actionOpen_triggered();
    void on_addSeedButton_released();
    void on_seedsTableWidget_itemSelectionChanged();
    void on_seedsTableWidget_itemChanged(QTableWidgetItem* item);
    void on_removeSeedButton_released();
    void on_nextSliceButton_released();
    void on_previousSliceButton_released();
    void on_currentSliceNumberSpinner_valueChanged(int newSliceNumber);
    void on_goButton_released();
    void resizeEvent(QResizeEvent* event);
    void seedCreated(float x, float y, float width, float height);
    void sliceSceneMouseMoved(QPointF mousePosition);

private:
    Ui::MainWindow *ui;
    MyQGraphicsScene* sliceScene;

    SegmentationManager segManager;

    int currentSliceIndex;
    QVector<SliceInfo> slices;

    void openFileDialog();
    void drawSeeds();
    void showSlice(int sliceNumber);
    void updateSeedsTable();
};

#endif // MAINWINDOW_H