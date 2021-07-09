#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent),ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    VTK_MODULE_INIT(vtkRenderingOpenGL2);               //注册使用，暂时还看不懂
    VTK_MODULE_INIT(vtkInteractionStyle);               //注册使用，暂时还看不懂
    renderJpegImage(1,"D:/00_Code/SecondVTK/images/test.jpg");
    renderPngImage(2,"D:/00_Code/SecondVTK/images/pngTest.png");
    renderTiffImage(3,"D:/00_Code/SecondVTK/images/tiffTest.tif");
    renderBmprImage(4,"D:/00_Code/SecondVTK/images/BmpTest.bmp");
    renderDicomImage(5,"D:/00_Code/SecondVTK/images/DICOMTest.dcm");
    drawVtkCube(6);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::renderJpegImage(int index, const char *temp)
{
    /**
     * @brief 读取本地图片
     * 1. 获取本地资源地址
     * 2. 新建渲染对象
     * 3. 设置图像名称
     * 4. 更新
     */
    vtkSmartPointer<vtkJPEGReader> render = vtkSmartPointer<vtkJPEGReader>::New();
    render -> SetFileName(temp);
    render -> Update();
    /**
     * @brief 设置图片视图
     * 1. 新建视图
     * 2. 设置视图输入
     * 3. 设置视图窗口
     * 4. 视图渲染
     */
    vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
    viewer -> SetInputData(render -> GetOutput());
    switch (index) {
    case 1:
        viewer -> SetRenderWindow(ui->widget_VTK_1->GetRenderWindow());
        break;
    case 2:
        viewer -> SetRenderWindow(ui->widget_VTK_2->GetRenderWindow());
        break;
    case 3:
        viewer -> SetRenderWindow(ui->widget_VTK_3->GetRenderWindow());
        break;
    case 4:
        viewer -> SetRenderWindow(ui->widget_VTK_4->GetRenderWindow());
        break;
    case 5:
        viewer -> SetRenderWindow(ui->widget_VTK_5->GetRenderWindow());
        break;
    case 6:
        viewer -> SetRenderWindow(ui->widget_VTK_6->GetRenderWindow());
        break;
    case 7:
        viewer -> SetRenderWindow(ui->widget_VTK_7->GetRenderWindow());
        break;
    case 8:
        viewer -> SetRenderWindow(ui->widget_VTK_8->GetRenderWindow());
        break;
    default:
        break;
    }
    viewer -> Render();
}

void MainWindow::renderPngImage(int index, const char *temp)
{
    /**
     * @brief 读取本地图片
     * 1. 获取本地资源地址
     * 2. 新建渲染对象
     * 3. 设置图像名称
     * 4. 更新
     */
    vtkSmartPointer<vtkPNGReader> render = vtkSmartPointer<vtkPNGReader>::New();
    render -> SetFileName(temp);
    render -> Update();
    /**
     * @brief 设置图片视图
     * 1. 新建视图
     * 2. 设置视图输入
     * 3. 设置视图窗口
     * 4. 视图渲染
     */
    vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
    viewer -> SetInputData(render -> GetOutput());
    switch (index) {
    case 1:
        viewer -> SetRenderWindow(ui->widget_VTK_1->GetRenderWindow());
        break;
    case 2:
        viewer -> SetRenderWindow(ui->widget_VTK_2->GetRenderWindow());
        break;
    case 3:
        viewer -> SetRenderWindow(ui->widget_VTK_3->GetRenderWindow());
        break;
    case 4:
        viewer -> SetRenderWindow(ui->widget_VTK_4->GetRenderWindow());
        break;
    case 5:
        viewer -> SetRenderWindow(ui->widget_VTK_5->GetRenderWindow());
        break;
    case 6:
        viewer -> SetRenderWindow(ui->widget_VTK_6->GetRenderWindow());
        break;
    case 7:
        viewer -> SetRenderWindow(ui->widget_VTK_7->GetRenderWindow());
        break;
    case 8:
        viewer -> SetRenderWindow(ui->widget_VTK_8->GetRenderWindow());
        break;
    default:
        break;
    }
    viewer -> Render();
}

void MainWindow::renderTiffImage(int index, const char *temp)
{
    /**
     * @brief 读取本地图片
     * 1. 获取本地资源地址
     * 2. 新建渲染对象
     * 3. 设置图像名称
     * 4. 更新
     */
    vtkSmartPointer<vtkTIFFReader> render = vtkSmartPointer<vtkTIFFReader>::New();
    render -> SetFileName(temp);
    render -> Update();
    /**
     * @brief 设置图片视图
     * 1. 新建视图
     * 2. 设置视图输入
     * 3. 设置视图窗口
     * 4. 视图渲染
     */
    vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
    viewer -> SetInputData(render -> GetOutput());
    switch (index) {
    case 1:
        viewer -> SetRenderWindow(ui->widget_VTK_1->GetRenderWindow());
        break;
    case 2:
        viewer -> SetRenderWindow(ui->widget_VTK_2->GetRenderWindow());
        break;
    case 3:
        viewer -> SetRenderWindow(ui->widget_VTK_3->GetRenderWindow());
        break;
    case 4:
        viewer -> SetRenderWindow(ui->widget_VTK_4->GetRenderWindow());
        break;
    case 5:
        viewer -> SetRenderWindow(ui->widget_VTK_5->GetRenderWindow());
        break;
    case 6:
        viewer -> SetRenderWindow(ui->widget_VTK_6->GetRenderWindow());
        break;
    case 7:
        viewer -> SetRenderWindow(ui->widget_VTK_7->GetRenderWindow());
        break;
    case 8:
        viewer -> SetRenderWindow(ui->widget_VTK_8->GetRenderWindow());
        break;
    default:
        break;
    }
    viewer -> Render();
}

void MainWindow::renderBmprImage(int index, const char *temp)
{
    /**
     * @brief 读取本地图片
     * 1. 获取本地资源地址
     * 2. 新建渲染对象
     * 3. 设置图像名称
     * 4. 更新
     */
    vtkSmartPointer<vtkBMPReader> render = vtkSmartPointer<vtkBMPReader>::New();
    render -> SetFileName(temp);
    render -> Update();
    /**
     * @brief 设置图片视图
     * 1. 新建视图
     * 2. 设置视图输入
     * 3. 设置视图窗口
     * 4. 视图渲染
     */
    vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
    viewer -> SetInputData(render -> GetOutput());
    switch (index) {
    case 1:
        viewer -> SetRenderWindow(ui->widget_VTK_1->GetRenderWindow());
        break;
    case 2:
        viewer -> SetRenderWindow(ui->widget_VTK_2->GetRenderWindow());
        break;
    case 3:
        viewer -> SetRenderWindow(ui->widget_VTK_3->GetRenderWindow());
        break;
    case 4:
        viewer -> SetRenderWindow(ui->widget_VTK_4->GetRenderWindow());
        break;
    case 5:
        viewer -> SetRenderWindow(ui->widget_VTK_5->GetRenderWindow());
        break;
    case 6:
        viewer -> SetRenderWindow(ui->widget_VTK_6->GetRenderWindow());
        break;
    case 7:
        viewer -> SetRenderWindow(ui->widget_VTK_7->GetRenderWindow());
        break;
    case 8:
        viewer -> SetRenderWindow(ui->widget_VTK_8->GetRenderWindow());
        break;
    default:
        break;
    }
    viewer -> Render();

}

void MainWindow::renderDicomImage(int index, const char *temp)
{
    /**
     * @brief 读取本地图片
     * 1. 获取本地资源地址
     * 2. 新建渲染对象
     * 3. 设置图像名称
     * 4. 更新
     */
    vtkSmartPointer<vtkDICOMImageReader> render = vtkSmartPointer<vtkDICOMImageReader>::New();
    render -> SetFileName(temp);
    render -> Update();
    /**
     * @brief 设置图片视图
     * 1. 新建视图
     * 2. 设置视图输入
     * 3. 设置视图窗口
     * 4. 视图渲染
     */
    vtkSmartPointer<vtkImageViewer2> viewer = vtkSmartPointer<vtkImageViewer2>::New();
    viewer -> SetInputData(render -> GetOutput());
    switch (index) {
    case 1:
        viewer -> SetRenderWindow(ui->widget_VTK_1->GetRenderWindow());
        break;
    case 2:
        viewer -> SetRenderWindow(ui->widget_VTK_2->GetRenderWindow());
        break;
    case 3:
        viewer -> SetRenderWindow(ui->widget_VTK_3->GetRenderWindow());
        break;
    case 4:
        viewer -> SetRenderWindow(ui->widget_VTK_4->GetRenderWindow());
        break;
    case 5:
        viewer -> SetRenderWindow(ui->widget_VTK_5->GetRenderWindow());
        break;
    case 6:
        viewer -> SetRenderWindow(ui->widget_VTK_6->GetRenderWindow());
        break;
    case 7:
        viewer -> SetRenderWindow(ui->widget_VTK_7->GetRenderWindow());
        break;
    case 8:
        viewer -> SetRenderWindow(ui->widget_VTK_8->GetRenderWindow());
        break;
    default:
        break;
    }
    viewer -> Render();
}

void MainWindow::drawVtkCube(int index)
{
    vtkNew <vtkNamedColors> colors;
    std::array<std::array<double, 3>, 8> pts = {{{{0, 0, 0}},
                                                 {{0.2, 0, 0}},
                                                 {{0.2, 0.2, 0}},
                                                 {{0, 0.2, 0}},
                                                 {{0, 0, 0.2}},
                                                 {{0.2, 0, 0.2}},
                                                 {{0.2, 0.2, 0.2}},
                                                 {{0, 0.2, 0.2}}}};
    std::array<std::array<vtkIdType,4>,6> ording = {{{{0, 1, 2, 3}},
                                                     {{4, 5, 6, 7}},
                                                     {{0, 1, 5, 4}},
                                                     {{1, 2, 6, 5}},
                                                     {{2, 3, 7, 6}},
                                                     {{3, 0, 4, 7}}}};
    vtkNew <vtkPolyData> cube;
    vtkNew <vtkPoints> points;
    vtkNew <vtkCellArray> polys;
    vtkNew <vtkFloatArray> scalars;
    for (auto i = 0ul;i < pts.size();++i)
    {
        points -> InsertPoint(i,pts[i].data());
        scalars -> InsertTuple1(i,i);
    }
    for (auto &&i : ording)
        polys -> InsertNextCell(vtkIdType(i.size()),i.data());
    cube -> SetPoints(points);
    cube -> SetPolys(polys);
    cube -> GetPointData() -> SetScalars(scalars);
    vtkNew<vtkPolyDataMapper> cubeMapper;
    cubeMapper->SetInputData(cube);
    cubeMapper->SetScalarRange(cube->GetScalarRange());
    vtkNew<vtkActor> cubeActor;
    cubeActor->SetMapper(cubeMapper);
    vtkNew<vtkCamera> camera;
    camera->SetPosition(1, 1, 1);
    camera->SetFocalPoint(0, 0, 0);
    vtkNew<vtkRenderer> render;
    render -> AddActor(cubeActor);
    render -> SetActiveCamera(camera);
    render -> SetBackground(colors -> GetColor3d("Cornsilk").GetData());
    ui->widget_VTK_6->GetRenderWindow()->AddRenderer(render);
}


