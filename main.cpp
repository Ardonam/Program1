#include "glwidget.h"
#include <QApplication>
#include <QtGui>
#include <QLabel>
#include <QPixmap>
#include <iostream>
#include <QOpenGLWidget>


QImage * image = new QImage();

int main(int argc, char** argv) {
    //argv[0];
    QApplication a(argc, argv);

    QImage img;
    img.load(argv[1]);

//png_texture_load("/Guatemala_flag_300", 500,300);
    QSurfaceFormat format;
    format.setVersion(3,3);
    format.setProfile(QSurfaceFormat::CoreProfile);
    QSurfaceFormat::setDefaultFormat(format);

    GLWidget glWidget;
    qreal pixelRatio = glWidget.devicePixelRatio();
    glWidget.resize(640/pixelRatio,480/pixelRatio);
    glWidget.show();

    return a.exec();
}
