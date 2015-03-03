#include "glwidget.h"
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <QTextStream>
#include <QRgb>
using namespace std;
/*
for(i=0; i< num_pts; i++)
    float angle = PI *2

        draw mode gl triangle

*/
GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent), outline(false), drawMode(0) {
    num_pts = 0;
    drawMode = GL_TRIANGLES;
    square = true;
    r =10;


    inputImg = new QImage("Guatemala_flag_300.png");

}

GLWidget::~GLWidget() {

}



void GLWidget::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
        case Qt::Key_C:
            if(square)
                square = false;
            else square = true;

            break;
        case Qt::Key_Up:
            r++;
            break;
        case Qt::Key_Down:
            r--;
            break;
        case Qt::Key_Space:
        vec2 g(r,r);
        vec2 p(r,r);
        for(;g.y < 480; g.y += r *3){
        for(g.x = r; g.x< 640; g.x += r*3){
            cout << g.y<<"and" <<g.x<< endl;
        if(square){
            p.y = g.y;
            p.x =g.x;
            p.x += -r;
            p.y += r;
            vec2 upper_left(p);
            p.x += r *2;
            vec2 upper_right(p);
            p.y += -r *2;
            vec2 lower_right(p);
            p.x += -r *2;
            vec2 lower_left(p);
            p.x += r *2;
            vec2 re_lower_right(p);
            p.y += r *2;
            p.x += -r *2;
            vec2 re_upper_left(p);

            pts.push_back(upper_left);
            pts.push_back(upper_right);
            pts.push_back(lower_right);
            pts.push_back(lower_left);
            pts.push_back(re_lower_right);
            pts.push_back(re_upper_left);
            num_pts += 6;
        }
        else{
            p.y = g.y;
            p.x =g.x;
            pts.push_back(p);
            vec2 c(p);
            p.x += -r;
            p.y += r;
            vec2 upper_left(p);
            p.x += r *2;
            vec2 upper_right(p);
            p.y += -r *2;
            vec2 lower_right(p);
            p.x += -r *2;
            vec2 lower_left(p);
            p.y += r;
            p.x += r;
            p.x += sqrt(pow(r,2)+pow(r,2)) ;
            vec2 right(p);
            p.x -= sqrt(pow(r,2)+pow(r,2))*2;
            vec2 left(p);
            p.x += sqrt(pow(r,2)+pow(r,2));
            p.y += sqrt(pow(r,2)+pow(r,2));
            vec2 up(p);
            p.y -= sqrt(pow(r,2)+pow(r,2))*2;
            vec2 down(p);


            pts.push_back(upper_left);
            pts.push_back(up);
            pts.push_back(c);
            pts.push_back(up);
            pts.push_back(upper_right);
            pts.push_back(c);
            pts.push_back(upper_right);
            pts.push_back(right);
            pts.push_back(c);
            pts.push_back(right);
            pts.push_back(lower_right);
            pts.push_back(c);
            pts.push_back(lower_right);
            pts.push_back(down);
            pts.push_back(c);
            pts.push_back(down);
            pts.push_back(lower_left);
            pts.push_back(c);
            pts.push_back(lower_left);
            pts.push_back(left);
            pts.push_back(c);
            pts.push_back(left);
            pts.push_back(upper_left);

            num_pts += 24;
        }

        glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
        glBufferData(GL_ARRAY_BUFFER, num_pts*8, pts.data(), GL_DYNAMIC_DRAW);
        update();
    }
        }
            break;
    }


}

void GLWidget::mouseMoveEvent(QMouseEvent *event){

    vec2 p(event->x() , (event->y() ) );

    QRgb rgb = inputImg->pixel(p.y,p.x);
    int red = qRed(rgb);
    int green = qGreen(rgb);
    int blue = qBlue(rgb);

    float r = (float)red/255;
    float g = (float) green/255;
    float b = (float) blue/255;
    cout << r << " " << g << " " <<b << endl;
    if(square){
        p.x += -r;
        p.y += r;
        vec2 upper_left(p);
        p.x += r *2;
        vec2 upper_right(p);
        p.y += -r *2;
        vec2 lower_right(p);
        p.x += -r *2;
        vec2 lower_left(p);
        p.x += r *2;
        vec2 re_lower_right(p);
        p.y += r *2;
        p.x += -r *2;
        vec2 re_upper_left(p);


        color.push_back(vec3(r,g,b));
        pts.push_back(upper_left);
        color.push_back(vec3(r,g,b));
        pts.push_back(upper_right);
        color.push_back(vec3(r,g,b));
        pts.push_back(lower_right);
        color.push_back(vec3(r,g,b));
        pts.push_back(lower_left);
        color.push_back(vec3(r,g,b));
        pts.push_back(re_lower_right);
        color.push_back(vec3(r,g,b));
        pts.push_back(re_upper_left);
        num_pts += 6;
    }
    else{
        pts.push_back(p);
        vec2 c(p);
        p.x += -r;
        p.y += r;
        vec2 upper_left(p);
        p.x += r *2;
        vec2 upper_right(p);
        p.y += -r *2;
        vec2 lower_right(p);
        p.x += -r *2;
        vec2 lower_left(p);
        p.y += r;
        p.x += r;
        p.x += sqrt(pow(r,2)+pow(r,2)) ;
        vec2 right(p);
        p.x -= sqrt(pow(r,2)+pow(r,2))*2;
        vec2 left(p);
        p.x += sqrt(pow(r,2)+pow(r,2));
        p.y += sqrt(pow(r,2)+pow(r,2));
        vec2 up(p);
        p.y -= sqrt(pow(r,2)+pow(r,2))*2;
        vec2 down(p);


        pts.push_back(upper_left);
        pts.push_back(up);
        pts.push_back(c);
        pts.push_back(up);
        pts.push_back(upper_right);
        pts.push_back(c);
        pts.push_back(upper_right);
        pts.push_back(right);
        pts.push_back(c);
        pts.push_back(right);
        pts.push_back(lower_right);
        pts.push_back(c);
        pts.push_back(lower_right);
        pts.push_back(down);
        pts.push_back(c);
        pts.push_back(down);
        pts.push_back(lower_left);
        pts.push_back(c);
        pts.push_back(lower_left);
        pts.push_back(left);
        pts.push_back(c);
        pts.push_back(left);
        pts.push_back(upper_left);

        num_pts += 24;
    }


    cout << "Added point (" << p.x << ", " << p.y << ") " << endl;

    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    glBufferData(GL_ARRAY_BUFFER, num_pts*8, pts.data(), GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    update();
}

void GLWidget::mousePressEvent(QMouseEvent *event) {
    /*if(num_pts < 3) {
        // devicePixelRatio will be 1 on standard displays.
        // On retina display devices (mac book pro retina, tablets, phones, etc)
        // devicePixelRatio will be greater than 1.
        // The coordinates of the event are in points (like font points,
        // not vertex points) rather than pixels.
        // There are devicePixelRatio pixels in a single point, so here
        // we are converting to pixels.
        qreal pixelRatio = this->devicePixelRatio();
        pts[num_pts].x = event->x()*pixelRatio;
        pts[num_pts].y = event->y()*pixelRatio;

        cout << "Added point (" << pts[num_pts].x << ", " << pts[num_pts].y << ") " << endl;
        cout << "Make sure your orthographic projection matrix "
                "is set up so you can see the points." << endl;

        num_pts++;


        glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(pts), pts, GL_DYNAMIC_DRAW);
        update();
    } else {
        cout << "Three points is the max. "
                "You must change this to make "
                "it so any number of points can be created." << endl;
    }*/

    vec2 p(event->x() , (event->y() ) );
    QRgb rgb = inputImg->pixel(p.y,p.x);
    int red = qRed(rgb);
    int green = qGreen(rgb);
    int blue = qBlue(rgb);

    float r = (float)red/255;
    float g = (float) green/255;
    float b = (float) blue/255;

    if(square){
        p.x += -r;
        p.y += r;
        vec2 upper_left(p);
        p.x += r *2;
        vec2 upper_right(p);
        p.y += -r *2;
        vec2 lower_right(p);
        p.x += -r *2;
        vec2 lower_left(p);
        p.x += r *2;
        vec2 re_lower_right(p);
        p.y += r *2;
        p.x += -r *2;
        vec2 re_upper_left(p);

        pts.push_back(upper_left);
        color.push_back(vec3(r,g,b));
        pts.push_back(upper_right);
        color.push_back(vec3(r,g,b));
        pts.push_back(lower_right);
        color.push_back(vec3(r,g,b));
        pts.push_back(lower_left);
        color.push_back(vec3(r,g,b));
        pts.push_back(re_lower_right);
        color.push_back(vec3(r,g,b));
        pts.push_back(re_upper_left);
        color.push_back(vec3(r,g,b));
        num_pts += 6;
    }
    else{
        pts.push_back(p);
        vec2 c(p);
        p.x += -r;
        p.y += r;
        vec2 upper_left(p);
        p.x += r *2;
        vec2 upper_right(p);
        p.y += -r *2;
        vec2 lower_right(p);
        p.x += -r *2;
        vec2 lower_left(p);
        p.y += r;
        p.x += r;
        p.x += sqrt(pow(r,2)+pow(r,2)) ;
        vec2 right(p);
        p.x -= sqrt(pow(r,2)+pow(r,2))*2;
        vec2 left(p);
        p.x += sqrt(pow(r,2)+pow(r,2));
        p.y += sqrt(pow(r,2)+pow(r,2));
        vec2 up(p);
        p.y -= sqrt(pow(r,2)+pow(r,2))*2;
        vec2 down(p);


        pts.push_back(upper_left);
        pts.push_back(up);
        pts.push_back(c);
        pts.push_back(up);
        pts.push_back(upper_right);
        pts.push_back(c);
        pts.push_back(upper_right);
        pts.push_back(right);
        pts.push_back(c);
        pts.push_back(right);
        pts.push_back(lower_right);
        pts.push_back(c);
        pts.push_back(lower_right);
        pts.push_back(down);
        pts.push_back(c);
        pts.push_back(down);
        pts.push_back(lower_left);
        pts.push_back(c);
        pts.push_back(lower_left);
        pts.push_back(left);
        pts.push_back(c);
        pts.push_back(left);
        pts.push_back(upper_left);

        num_pts += 24;
    }


    cout << "Added point (" << p.x << ", " << p.y << ") " << endl;

    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    glBufferData(GL_ARRAY_BUFFER, num_pts*8, pts.data(), GL_DYNAMIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    update();
}

void GLWidget::initializeGL() {
    initializeOpenGLFunctions();

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glPointSize(4.0f);

    // Create a new Vertex Array Object on the GPU which
    // saves the attribute layout of our vertices.
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    // Create a buffer on the GPU for position data
    glGenBuffers(1, &positionBuffer);

    // Upload the position data to the GPU, storing
    // it in the buffer we just allocated.
    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);

    glGenBuffers(1, &colorBuffer);

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glBufferData(GL_ARRAY_BUFFER, 0, NULL, GL_DYNAMIC_DRAW);

    // Load our vertex and fragment shaders into a program object
    // on the GPU
    program = loadShaders();

    // Bind the attribute "position" (defined in our vertex shader)
    // to the currently bound buffer object, which contains our
    // position data for a single triangle. This information
    // is stored in our vertex array object.
    glBindBuffer(GL_ARRAY_BUFFER, positionBuffer);
    GLint positionIndex = glGetAttribLocation(program, "position");
    glEnableVertexAttribArray(positionIndex);
    glVertexAttribPointer(positionIndex, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    GLint colorIndex = glGetAttribLocation(program, "color_in");
    glEnableVertexAttribArray(colorIndex);
    glVertexAttribPointer(colorIndex, 3, GL_FLOAT, GL_FALSE, 0, 0);

    projectionIndex = glGetUniformLocation(program, "p_matrix");
}

void GLWidget::resizeGL(int w, int h) {
    glViewport(0,0,w,h);

    // When our OpenGL context is resized, we need to change
    // our projection matrix to match. Create an orthographic
    // projection matrix that converts window coordinates to normalized
    // device coordinates.  This is similar to our previous lab,
    // except the conversion will happen in our vertex shader.
    // This way we won't need to do any conversions on our mouse
    // event coordinates and when we resize the window the geometry
    // won't be scaled unevenly.

       // float r = w;
        //float l = 0;
        //float t = 0;
       // float b = h;
glm::mat4 projection = glm::ortho(0.0f,(float)w,(float)h,0.0f);
        /*glm::mat4 projection = glm::mat4(
            2/(r-l),        0,              0,              0,
            0,              2/(t-b),        0,              0,
            0,              0,              -1,             0,
            -1,              -1,              0,             1
                             );
*/
    glUniformMatrix4fv(projectionIndex, 1, GL_FALSE, glm::value_ptr(projection));


    }


void GLWidget::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT);

    // draw primitives based on the current draw mode
    glDrawArrays(drawMode, 0, num_pts);


    // draw points so we can always see them
    // glPointSize adjusts the size of point
    // primitives
    glPointSize(.5);
    glDrawArrays(GL_POINTS, 0, num_pts);
}

// Copied from LoadShaders.cpp in the the oglpg-8th-edition.zip
// file provided by the OpenGL Programming Guide, 8th edition.
const GLchar* GLWidget::readShader(const char* filename) {
#ifdef WIN32
        FILE* infile;
        fopen_s( &infile, filename, "rb" );
#else
    FILE* infile = fopen( filename, "rb" );
#endif // WIN32

    if ( !infile ) {
#ifdef _DEBUG
        std::cerr << "Unable to open file '" << filename << "'" << std::endl;
#endif /* DEBUG */
        return NULL;
    }

    fseek( infile, 0, SEEK_END );
    int len = ftell( infile );
    fseek( infile, 0, SEEK_SET );

    GLchar* source = new GLchar[len+1];

    fread( source, 1, len, infile );
    fclose( infile );

    source[len] = 0;

    return const_cast<const GLchar*>(source);
}

GLuint GLWidget::loadShaders() {
    GLuint program = glCreateProgram();

    // read vertex shader from Qt resource file
    QFile vertFile(":/vert.glsl");
    vertFile.open(QFile::ReadOnly | QFile::Text);
    QString vertString;
    QTextStream vertStream(&vertFile);
    vertString.append(vertStream.readAll());
    string vertSTLString = vertString.toStdString();

    cout << "Vertex Shader:" << endl;
    cout << vertSTLString << endl;

    const GLchar* vertSource = vertSTLString.c_str();

    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertShader, 1, &vertSource, NULL);
    glCompileShader(vertShader);
    {
        GLint compiled;
        glGetShaderiv( vertShader, GL_COMPILE_STATUS, &compiled );
        if ( !compiled ) {
            GLsizei len;
            glGetShaderiv( vertShader, GL_INFO_LOG_LENGTH, &len );

            GLchar* log = new GLchar[len+1];
            glGetShaderInfoLog( vertShader, len, &len, log );
            std::cout << "Shader compilation failed: " << log << std::endl;
            delete [] log;
        }
    }
    glAttachShader(program, vertShader);

    // read fragment shader from Qt resource file
    QFile fragFile(":/frag.glsl");
    fragFile.open(QFile::ReadOnly | QFile::Text);
    QString fragString;
    QTextStream fragStream(&fragFile);
    fragString.append(fragStream.readAll());
    string fragSTLString = fragString.toStdString();

    cout << "Fragment Shader:" << endl;
    cout << fragSTLString << endl;

    const GLchar* fragSource = fragSTLString.c_str();

    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragShader, 1, &fragSource, NULL);
    glCompileShader(fragShader);
    {
        GLint compiled;
        glGetShaderiv( fragShader, GL_COMPILE_STATUS, &compiled );
        if ( !compiled ) {
            GLsizei len;
            glGetShaderiv( fragShader, GL_INFO_LOG_LENGTH, &len );

            GLchar* log = new GLchar[len+1];
            glGetShaderInfoLog( fragShader, len, &len, log );
            std::cerr << "Shader compilation failed: " << log << std::endl;
            delete [] log;
        }
    }
    glAttachShader(program, fragShader);

    glLinkProgram(program);
    glUseProgram(program);

    return program;
}
