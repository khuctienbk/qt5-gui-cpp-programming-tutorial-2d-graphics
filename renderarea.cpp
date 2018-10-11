#include "renderarea.h"
#include <QPaintEvent>
#include <QPainter>

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    mBackgroundColor(0, 0, 255),
    mPen(Qt::white),
    mShape(Asteroid)
{
    mPen.setWidth(2);
    on_shape_change();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(400, 400);
}
QSize RenderArea::sizeHint() const
{
    return QSize(400, 400);
}

void RenderArea::on_shape_change()
{
    switch (mShape) {
    case Asteroid:
        mScale = 90;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Cycloid:
        mScale = 10;
        mIntervalLength = 4 * M_PI;
        mStepCount = 128;
        break;

    case HuygensCycloid:
        mScale = 12;
        mIntervalLength = 4 * M_PI;
        mStepCount = 256;
        break;

    case HypoCycloid:
        mScale = 40;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Line:
        mScale = 100;
        mIntervalLength = 2 ;
        mStepCount = 128;
        break;

    case Circle:
        mScale = 150;
        mIntervalLength = 2 * M_PI;
        mStepCount = 128;
        break;

    case Elipse:
        mScale = 75;
        mIntervalLength = 2 * M_PI;
        mStepCount = 256;
        break;

    case Fancy:
        mScale = 10;
        mIntervalLength = 12 * M_PI;
        mStepCount = 512;
        break;

    case Starfish:
        mScale = 25;
        mIntervalLength = 6 * M_PI;
        mStepCount = 256;
        break;

    default:
        break;

    }
}

QPointF RenderArea::compute(float t)
{
    switch (mShape) {
    case Asteroid:
        return compute_astroid(t);
        break;

    case Cycloid:
        return compute_cycloid(t);
        break;

    case HuygensCycloid:
        return compute_huygens(t);
        break;

    case HypoCycloid:
        return compute_hypo(t);
        break;

    case Line:
        return compute_line(t);
        break;
    case Circle:
        return compute_circle(t);
        break;

    case Elipse:
        return compute_elipse(t);
        break;

    case Fancy:
        return compute_fancy(t);
        break;

    case Starfish:
        return compute_starfish(t);
        break;

    default:
        break;

    }
    return QPointF(0, 0);
}

QPointF RenderArea::compute_astroid(float t) {
    float cos_t = cos(t);
    float sin_t = sin(t);
    float x = 2 * cos_t * cos_t * cos_t;
    float y = 2 * sin_t * sin_t * sin_t;
    return QPointF(x, y);

}

QPointF RenderArea::compute_cycloid(float t)
{
    return QPointF(
                1.5 * (1 - cos(t)),     // X
                1.5 * (t - sin(t))      // Y
    );
}

QPointF RenderArea::compute_huygens(float t)
{
    return QPointF(
                4 * (3 * cos(t) - cos(3 * t)),  // X
                4 * (3 * sin(t) - sin(3 * t))   // Y
    );
}

QPointF RenderArea::compute_hypo(float t)
{
    return QPointF(
                1.5 * (2 * cos(t) + cos(2 * t)),  // X
                1.5 * (2 * sin(t) - sin(2 * t))   // Y
    );
}

QPointF RenderArea::compute_line(float t)
{
    // TBD:
    /*
     * x = fx(t)
     * y = fy(t)
    */
    return QPointF(1 - t, 1 - t);
}

QPointF RenderArea::compute_circle(float t)
{
    return QPointF(cos(t), sin(t));
}
QPointF RenderArea::compute_elipse(float t)
{
    return QPointF(2*cos(t), 1.1*sin(t));
}

QPointF RenderArea::compute_fancy(float t)
{
    return QPointF(
                11*cos(t) - 6*cos(11*t/6),
                11*sin(t) - 6*sin(11*t/6)
    );
}

QPointF RenderArea::compute_starfish(float t)
{
    float R = 5, r = 3, d = 5;
    return QPointF(
                (R - r) * cos(t) + d * cos(t * (R - r) / r),
                (R - r) * sin(t) - d * sin(t * (R - r) / r)
    );
}



void RenderArea::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.setBrush(mBackgroundColor);
    painter.setPen(mPen);

    // drawing area
    painter.drawRect(this->rect());

    QPoint center = this->rect().center();

    QPointF prevPoint = compute(0);
    QPoint prevPixel;
    prevPixel.setX(prevPoint.x() * mScale + center.x());
    prevPixel.setY(prevPoint.y() * mScale + center.y());


    float step = mIntervalLength / mStepCount;
    for(float t = 0; t < mIntervalLength; t += step) {
        QPointF point = compute(t);

        QPoint pixel;
        pixel.setX(point.x() * mScale + center.x());
        pixel.setY(point.y() * mScale + center.y());

 //       painter.drawPoint(pixel);
        painter.drawLine(pixel, prevPixel);

        prevPixel = pixel;
    }

    QPointF point = compute(mIntervalLength);

    QPoint pixel;
    pixel.setX(point.x() * mScale + center.x());
    pixel.setY(point.y() * mScale + center.y());

//       painter.drawPoint(pixel);
    painter.drawLine(pixel, prevPixel);

    prevPixel = pixel;


}
