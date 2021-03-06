#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QWidget>
#include <QColor>
#include <QPen>

class RenderArea : public QWidget
{
    Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = nullptr);

    QSize minimumSizeHint() const Q_DECL_OVERRIDE;
    QSize sizeHint() const Q_DECL_OVERRIDE;

    enum ShapeType {Asteroid,
                    Cycloid,
                    HuygensCycloid,
                    HypoCycloid,
                    Line,
                    Circle,
                    Elipse,
                    Fancy,
                    Starfish
    };

    void setBackgroundColor(QColor color) { mBackgroundColor = color; }      // setter
    QColor backgroundColor() const { return mBackgroundColor; }              // getter

    void setShape(ShapeType shape) { mShape = shape; on_shape_change(); }
    ShapeType shape() const { return  mShape; }

    void setScale(float scale) { mScale = scale; repaint(); }
    float scale() const { return mScale; }

    void setIntervalLength(float intervalLength) { mIntervalLength = intervalLength; repaint(); }
    float intervalLength() const { return mIntervalLength; }

    void setStepCount(int stepCount) { mStepCount = stepCount; repaint(); }
    int stepCount() const { return mStepCount; }

    void setShapeColor(QColor shapeColor) { mPen.setColor(shapeColor); }
    QColor shapeColor() const { return mPen.color(); }


protected:
    void paintEvent(QPaintEvent *event) Q_DECL_OVERRIDE;

signals:

public slots:

private:
    void on_shape_change();
    QPointF compute(float t);
    QPointF compute_astroid(float t);
    QPointF compute_cycloid(float t);
    QPointF compute_huygens(float t);
    QPointF compute_hypo(float t);
    QPointF compute_line(float t);
    QPointF compute_circle(float t);
    QPointF compute_elipse(float t);
    QPointF compute_fancy(float t);
    QPointF compute_starfish(float t);


private:
    QColor    mBackgroundColor;
    ShapeType mShape;
    QPen      mPen;

    float mIntervalLength;
    float mScale;
    int mStepCount;
};

#endif // RENDERAREA_H
