//traitement_image.cpp : définit le point d'entrée pour l'application console.

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include "opencv2/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <string>

using namespace std;
using namespace cv;

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "Left button of the mouse is c00licked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_RBUTTONDOWN)
	{
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_MBUTTONDOWN)
	{
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if (event == EVENT_MOUSEMOVE)
	{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;

	}
}

int main()
{

	VideoCapture cap(0);

	if (!cap.isOpened())
		return -1;

	while (1)
	{
		Mat frame;
		cap.read(frame);
		imshow("Camera", frame);

		/*if (waitKey(30) == 's')
		{
			break;
		}*/
	
	//Mat img;
	
	Mat mask_bleu_BGR, mask_rouge_BGR, mask_Yellow_BGR, mask_vert_BGR, mask_blanc_BGR, mask_orange_BGR;
	Mat result_bleu_BGR, result_rouge_BGR, result_Yellow_BGR, result_vert_BGR, result_blanc_BGR, result_orange_BGR;
	Mat Detect_Bleu_BGR, Detect_Rouge_BGR, Detect_Yellow_BGR, Detect_Vert_BGR, Detect_Blanc_BGR, Detect_Orange_BGR;

	
	// Load webcam picture capture and display it
	// make a condition to take a picture of every face of the cube by pressing a button 
	// a for of 6 values for the 6 faces{
	// take a picture
	// analyse the colors
	// map the face with letters
	// end for }
	/*printf("Good morning");
	img = imread("P:\\2_Eme_annee\\ER4\\Détection_couleur\\TUTO_OPENCV\\Rubiks1.PNG");
	if (img.empty())
	{
		fprintf(stderr, "couldn't open image file: %s\n", "P:\\2_Eme_annee\\ER4\\Détection_couleur\\TUTO_OPENCV\\Capture.PNG");
		return EXIT_FAILURE;
	}

	cvNamedWindow("Image original", CV_WINDOW_AUTOSIZE);
	imshow("Image original", img);
	*/
	//Mat imgMap;
	//imgMap = imread("P:\\2_Eme_annee\\ER4\\Détection_couleur\\TUTO_OPENCV\\Rubiks1.PNG");
	/*
	rectangle(frame, Point(0, 0), Point(1000, 1000), Scalar(0, 0, 0), -1);
	rectangle(frame, Point(120, 70), Point(220, 220), Scalar(255, 255, 255), -1);
	rectangle(frame, Point(400, 70), Point(550, 220), Scalar(255, 255, 255), -1);
	rectangle(frame, Point(730, 70), Point(900, 220), Scalar(255, 255, 255), -1);
	rectangle(frame, Point(120, 350), Point(220, 550), Scalar(255, 255, 255), -1);
	rectangle(frame, Point(730, 350), Point(900, 550), Scalar(255, 255, 255), -1);
	rectangle(frame, Point(120, 700), Point(220, 850), Scalar(255, 255, 255), -1);
	rectangle(frame, Point(400, 700), Point(550, 850), Scalar(255, 255, 255), -1);
	rectangle(frame, Point(730, 700), Point(900, 850), Scalar(255, 255, 255), -1);*/
	//cvNamedWindow("oui", CV_WINDOW_AUTOSIZE);
	//imshow("oui", imgMap);
	

	//				/******************DÉTECTION DE LA COULEUR BLEU******************************/
	//


	Vec3b bgrPixel_bleu(150, 40, 40); //Pixel bleu
	Mat3b bgr_bleu(bgrPixel_bleu);

	//// Calcul of min and max BGR
	int thresh_bleu = 60;
	Scalar minBGR_bleu = Scalar(bgrPixel_bleu.val[0] - thresh_bleu, bgrPixel_bleu.val[1] - thresh_bleu, bgrPixel_bleu.val[2] - thresh_bleu);
	Scalar maxBGR_bleu = Scalar(bgrPixel_bleu.val[0] + thresh_bleu, bgrPixel_bleu.val[1] + thresh_bleu, bgrPixel_bleu.val[2] + thresh_bleu);

	////Affichage de la détection du bleu
	inRange(frame, minBGR_bleu, maxBGR_bleu, mask_bleu_BGR);
	//cvNamedWindow("Détection du bleu", CV_WINDOW_AUTOSIZE);
	//imshow("Détection du bleu", mask_bleu_BGR);

	////Opérateur ET entre l'image original et la détection du bleu
	bitwise_and(frame, frame, result_bleu_BGR, mask_bleu_BGR);
	//cvNamedWindow("Résultat bleu", CV_WINDOW_AUTOSIZE);
	//imshow("Résultat bleu", result_bleu_BGR);

	bitwise_and(frame, result_bleu_BGR, result_bleu_BGR, Detect_Bleu_BGR);
	cvNamedWindow("Detect blue", CV_WINDOW_AUTOSIZE);
	imshow("Detect blue", result_bleu_BGR);
	//

	//				//******************DÉTECTION DE LA COULEUR ROUGE******************************
	//
	Vec3b bgrPixel_rouge(0, 0, 160); //Pixel rouge
	Mat3b bgr_rouge(bgrPixel_rouge);

	//// Calcul of min and max BGR
	int thresh_rouge = 40;
	Scalar minBGR_rouge = Scalar(bgrPixel_rouge.val[0] - thresh_rouge, bgrPixel_rouge.val[1] - thresh_rouge, bgrPixel_rouge.val[2] - thresh_rouge);
	Scalar maxBGR_rouge = Scalar(bgrPixel_rouge.val[0] + thresh_rouge, bgrPixel_rouge.val[1] + thresh_rouge, bgrPixel_rouge.val[2] + thresh_rouge);

	////Affichage de la détection du rouge
	inRange(frame, minBGR_rouge, maxBGR_rouge, mask_rouge_BGR);
	//cvNamedWindow("Détection du rouge", CV_WINDOW_AUTOSIZE);
	//imshow("Détection du rouge", mask_rouge_BGR);

	////Opérateur ET entre l'image original et la détection du rouge
	bitwise_and(frame, frame, result_rouge_BGR, mask_rouge_BGR);
	//cvNamedWindow("Résultat rouge", CV_WINDOW_AUTOSIZE);
	//imshow("Résultat rouge", result_rouge_BGR);

	bitwise_and(frame, result_rouge_BGR, result_rouge_BGR, Detect_Rouge_BGR);
	cvNamedWindow("Detect Rouge", CV_WINDOW_AUTOSIZE);
	imshow("Detect Rouge", result_rouge_BGR);

	//				//******************DÉTECTION DE LA COULEUR VERT******************************

	Vec3b bgrPixel_vert(20, 95, 30); //Pixel vert
	Mat3b bgr_vert(bgrPixel_vert);

	//// Calcul of min and max BGR
	int thresh_vert = 50;
	Scalar minBGR_vert = Scalar(bgrPixel_vert.val[0] - thresh_vert, bgrPixel_vert.val[1] - thresh_vert, bgrPixel_vert.val[2] - thresh_vert);
	Scalar maxBGR_vert = Scalar(bgrPixel_vert.val[0] + thresh_vert, bgrPixel_vert.val[1] + thresh_vert, bgrPixel_vert.val[2] + thresh_vert);

	////Affichage de la détection du vert
	inRange(frame, minBGR_vert, maxBGR_vert, mask_vert_BGR);
	//cvNamedWindow("Détection du vert", CV_WINDOW_AUTOSIZE);
	//imshow("Détection du vert", mask_vert_BGR);

	////Opérateur ET entre l'image original et la détection du vert
	bitwise_and(frame, frame, result_vert_BGR, mask_vert_BGR);
	//cvNamedWindow("Résultat vert", CV_WINDOW_AUTOSIZE);
	//imshow("Résultat vert", result_vert_BGR);

	bitwise_and(frame, result_vert_BGR, result_vert_BGR, Detect_Vert_BGR);
	cvNamedWindow("Detect Green", CV_WINDOW_AUTOSIZE);
	imshow("Detect Green", result_vert_BGR);
	//
	//				//******************DÉTECTION DE LA COULEUR BLANC******************************
	//
	Vec3b bgrPixel_blanc(255, 255, 255); //Pixel blanc
	Mat3b bgr_blanc(bgrPixel_blanc);

	//// Calcul of min and max BGR
	int thresh_blanc = 140;
	Scalar minBGR_blanc = Scalar(bgrPixel_blanc.val[0] - thresh_blanc, bgrPixel_blanc.val[1] - thresh_blanc, bgrPixel_blanc.val[2] - thresh_blanc);
	Scalar maxBGR_blanc = Scalar(bgrPixel_blanc.val[0] + thresh_blanc, bgrPixel_blanc.val[1] + thresh_blanc, bgrPixel_blanc.val[2] + thresh_blanc);

	////Affichage de la détection du blanc
	inRange(frame, minBGR_blanc, maxBGR_blanc, mask_blanc_BGR);
	//cvNamedWindow("Détection du blanc", CV_WINDOW_AUTOSIZE);
	//imshow("Détection du blanc", mask_blanc_BGR);

	////Opérateur ET entre l'image original et la détection du blanc
	bitwise_and(frame, frame, result_blanc_BGR, mask_blanc_BGR);
	//cvNamedWindow("Résultat blanc", CV_WINDOW_AUTOSIZE);
	//imshow("Résultat blanc", result_blanc_BGR);

	bitwise_and(frame, result_blanc_BGR, result_blanc_BGR, Detect_Blanc_BGR);
	cvNamedWindow("Detect White", CV_WINDOW_AUTOSIZE);
	imshow("Detect White", result_blanc_BGR);
	//
	//				//******************DÉTECTION DE LA COULEUR ORANGE******************************

	Vec3b bgrPixel_orange(0, 60, 180); //Pixel orange
	Mat3b bgr_orange(bgrPixel_orange);

	//// Calcul of min and max BGR
	int thresh_orange = 50;
	Scalar minBGR_orange = Scalar(bgrPixel_orange.val[0] - thresh_orange, bgrPixel_orange.val[1] - thresh_orange, bgrPixel_orange.val[2] - thresh_orange);
	Scalar maxBGR_orange = Scalar(bgrPixel_orange.val[0] + thresh_orange, bgrPixel_orange.val[1] + thresh_orange, bgrPixel_orange.val[2] + thresh_orange);

	////Affichage de la détection du orange
	inRange(frame, minBGR_orange, maxBGR_orange, mask_orange_BGR);
	//cvNamedWindow("Détection du orange", CV_WINDOW_AUTOSIZE);
	//imshow("Détection du orange", mask_orange_BGR);

	////Opérateur ET entre l'image original et la détection du orange
	bitwise_and(frame, frame, result_orange_BGR, mask_orange_BGR);
	//cvNamedWindow("Résultat orange", CV_WINDOW_AUTOSIZE);
	//imshow("Résultat orange", result_orange_BGR);

	bitwise_and(frame, result_orange_BGR, result_orange_BGR, Detect_Orange_BGR);
	cvNamedWindow("Detect Orange", CV_WINDOW_AUTOSIZE);
	imshow("Detect Orange", result_orange_BGR);

	//***************************Yellow******************//

	// Calcul of min and max BGR

	Vec3b bgrPixel_Yellow(0, 200, 150); //Pixel yellow
	Mat3b bgr_Yellow(bgrPixel_Yellow);

	int thresh_Yellow = 100;
	Scalar minBGR_Yellow = Scalar(bgrPixel_Yellow.val[0] - thresh_Yellow, bgrPixel_Yellow.val[1] - thresh_Yellow, bgrPixel_Yellow.val[2] - thresh_Yellow);
	Scalar maxBGR_Yellow = Scalar(bgrPixel_Yellow.val[0] + thresh_Yellow, bgrPixel_Yellow.val[1] + thresh_Yellow, bgrPixel_Yellow.val[2] + thresh_Yellow);

	//Affichage de la détection du orange
	inRange(frame, minBGR_Yellow, maxBGR_Yellow, mask_Yellow_BGR);
	//cvNamedWindow("Yellow detection", CV_WINDOW_AUTOSIZE);
	//imshow("Yellow detecttion", mask_Yellow_BGR);

	//Opérateur ET entre l'image original et la détection du orange
	bitwise_and(frame, frame, result_Yellow_BGR, mask_Yellow_BGR);
	//cvNamedWindow("Résultat Yellow", CV_WINDOW_AUTOSIZE);
	//imshow("Résultat Yellow", result_Yellow_BGR);

	bitwise_and(frame, frame, Detect_Yellow_BGR, mask_Yellow_BGR);
	cvNamedWindow("Detect Yellow", CV_WINDOW_AUTOSIZE);
	imshow("Detect Yellow", Detect_Yellow_BGR);
	



	//Convert pixel values to other color spaces.

	Mat3b hsv;
	Mat3b brightHSV;
	//Vec3b bgrPixel_orange(30, 30, 190); //Pixel orange
	Mat3b bgr(bgrPixel_orange);
	cvtColor(bgr, hsv, COLOR_BGR2HSV);
	//printf("%c"&hsvPixel);

	//Get back the vector from Mat
	Vec3b hsvPixel(hsv.at<Vec3b>(0, 0));
	int thresh= 50;


	Scalar minHSV = Scalar(hsvPixel.val[0] - thresh, hsvPixel.val[1] - thresh, hsvPixel.val[2] - thresh);
	Scalar maxHSV = Scalar(hsvPixel.val[0] + thresh, hsvPixel.val[1] + thresh, hsvPixel.val[2] + thresh);

	// convert picture into HSV
	cvtColor(frame, brightHSV, COLOR_BGR2HSV);
	Mat maskHSV, resultHSV;
	inRange(brightHSV, minHSV, maxHSV, maskHSV);
	bitwise_and(brightHSV, brightHSV, resultHSV, maskHSV);
	////Affichage de la détection du orange
	//inRange(frame, minHSV, maxHSV, mask_orange_BGR);
	//cvNamedWindow("Détection du orange", CV_WINDOW_AUTOSIZE);
	//imshow("Détection du orange", mask_orange_BGR);

	////Opérateur ET entre l'image original et la détection du orange
	//bitwise_and(frame, frame, result_orange_BGR, mask_orange_BGR);
	//cvNamedWindow("Résultat orange", CV_WINDOW_AUTOSIZE);
	//imshow("Résultat orange", result_orange_BGR);

//set the callback function for any mouse event
	setMouseCallback("Image original", CallBackFunc, NULL);

	// draw rectangle
	IplImage* image2;
	image2 = cvCreateImage(cvSize(frame.cols, frame.rows), 8, 3);
	IplImage ipltemp = frame;
	cvCopy(&ipltemp, image2);

	cvSetImageROI(image2, Rect(Point(120, 70), Point(220, 220)));
	CvScalar  meanValue = cvAvg(image2);
	printf("\nUpper Left meanValue %f\t%f\t%f\t%f\n", meanValue);


	cvWaitKey(1);
	cvDestroyAllWindows;
	}
	return 0;
	
}

