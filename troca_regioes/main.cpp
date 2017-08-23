#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;
void dofor(Mat &image,Mat &sub_image,int i_start,int i_end,int j_start,int j_end){
    int i_aux=0;
    int j_aux=0;
    for(int i=i_start; i<i_end;i++){
        j_aux=0;

        for(int j=j_start;j<j_end;j++){
            image.at<uchar>(i,j)=sub_image.at<uchar>(i_aux,j_aux)+0;
            j_aux++;
        }
        i_aux++;
    }

}
int main()
{   Mat image;
    Mat image1(Size(256,256),CV_8UC1);
    Mat sub_image1,sub_image2,sub_image3,sub_image4;
    image=imread("biel.png",CV_LOAD_IMAGE_GRAYSCALE);
    if(!image.data)
        cout<<"Nao abriu imagem"<<endl;
    sub_image1=image(Range(0,127),Range(0,127));        //IIQ
    sub_image2=image(Range(128,255),Range(0,127));      //IIIQ
    sub_image3=image(Range(0,127),Range(128,255));      //IQ
    sub_image4=image(Range(128,255),Range(128,255));    //IVQ
//    namedWindow("janela1",WINDOW_AUTOSIZE);
//    imshow("janela1", sub_image1);
//    waitKey();
//    namedWindow("janela2",WINDOW_AUTOSIZE);
//    imshow("janela2", sub_image2);
//    waitKey();
//    namedWindow("janela3",WINDOW_AUTOSIZE);
//    imshow("janela3", sub_image3);
//    waitKey();
//    namedWindow("janela4",WINDOW_AUTOSIZE);
//    imshow("janela4", sub_image4);
//    waitKey();
//    int i_aux=0;
//    int j_aux=0;
//    for(int i=0; i<128;i++){
//        j_aux=0;

//        for(int j=0;j<128;j++){
//            image.at<uchar>(i,j)=sub_image3.at<uchar>(i_aux,j_aux)+0;
//            j_aux++;
//        }
//        i_aux++;
//    }
        dofor(image1,sub_image2,0,128,128,255);  //sub_image2 eh IIIQ e o range eh o primeiro
        dofor(image1,sub_image3,128,256,0,128);//sub_image3 eh o IQ e o range eh o terceiro
        dofor(image1,sub_image1,128,256,128,256);//sub_image1 eh o IIQ e o range eh o quarto
        dofor(image1,sub_image4,0,128,0,128);   //sub_image4 eh o IV4 e o range, o segundo
        namedWindow("janela1",WINDOW_AUTOSIZE);
        imshow("janela1", image1);
        waitKey();


    return 0;
}
