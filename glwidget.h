#ifndef __GLWIDGET__INCLUDE__
#define __GLWIDGET__INCLUDE__

#include <QOpenGLWidget>
#include <QOpenGLFunctions_3_3_Core>
#include <QMouseEvent>
#include <glm/glm.hpp>
#include <QDialog>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QImage>
// glm by default uses degrees, but that functionality
// is deprecated so GLM_FORCE_RADIANS turns off some 
// glm warnings
#define GLM_FORCE_RADIANS

using glm::vec2;
using glm::vec3;

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions_3_3_Core {
    Q_OBJECT

    public:
        GLWidget(QWidget *parent=0);
        ~GLWidget();


    protected:
        void initializeGL();
        void resizeGL(int w, int h);
        void paintGL();

        void mousePressEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void keyPressEvent(QKeyEvent *event);

    private:
        GLuint loadShaders();
        static const GLchar* readShader(const char* filename);

        GLuint positionBuffer;
        GLuint colorBuffer;
        bool outline;
        bool square;
        GLenum drawMode;
        GLint projectionIndex;


        GLuint vao;
        GLuint program;
        QImage img;


        std::vector<vec2> pts;
        std::vector<vec3> color;
        int num_pts;
        int r; //radious of shapes

        QGridLayout* gridLayout;
            QImage* inputImg;
            QLabel* imgDisplayLabel;
            QScrollArea* scrollArea;

};

#endif
