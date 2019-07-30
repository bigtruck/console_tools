#include <iostream>
#include <fstream>

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace std;

int convertDepth(const cv::Mat img);

int main(int argc, char const *argv[])
{
	cout << "!!!TOOL BY xiaoyong!!!" << endl;
	if(argc < 2)
	{
		cout << "缺少参数" << endl;
		for (int i = 1; i < argc; i++)
		{
			cout << "argv-" << i << ' ' << argv[i] << endl;
		}
		return -1;
	}

	char buffer[255];
	// cout << "!hello word!" << endl;
	// cv::Mat imgInput = cv::imread("/Users/XiaoYong/Projects/console_tool/bmp2c/test.bmp");
	string inName = argv[1];
	cv::Mat imgInput = cv::imread(inName);
	// cv::imshow("test",imgInput);
	cv::Mat imgBGR565 ;
	cv::Mat imgRGB ;
	cv::cvtColor(imgInput,imgBGR565,cv::COLOR_BGR2BGR565);
	// cout << "bgr565 data:\r\n" << imgBGR565 << endl ;

	if(imgInput.type() == CV_8UC3)
	{
		int w = imgBGR565.cols;
		int h = imgBGR565.rows;
		int byteLength = w * h * 2 ;
		uchar *pIndex = imgBGR565.ptr() ;
		// cout << "\r\nimgBGR565:\r\n" << imgBGR565 << "\r\n" << endl ;
		int cnt = 0 ;
		int bl,bh;
		unsigned short rgb;
		int l ;
		cout << "x size:" << w << endl ;
		cout << "y size:" << h << endl ;
		if(byteLength > 0)
		{
			string outName ;
			if(argc > 2)
			{
				outName = argv[2];
			}
			else
			{
				string str = argv[1];
				size_t found = str.find_last_of('.');
				outName = str.substr(0,found);
				outName += ".h";
			}
			ofstream outFile(outName,ios::binary | ios::out);
			if(!outFile)
			{
				cout << "connot create out file !!!" << endl ;
			}
			else
			{
				outFile.seekp(outFile.beg);

				string name ;
				size_t i = inName.find_last_of('/');
				size_t d = inName.find_last_of('.');
				if(d >= inName.length())
				{
					d = inName.length() ;
				}
				name = inName.substr(i+1,d-i-1);
				for (int j = 0; j < name.length(); j++)
				{
					name[j] = toupper(name[j]);
				}
				l = sprintf(buffer,"#ifndef __%s_H\r\n#define __%s_H\r\n",name.data(),name.data());
				outFile.write(buffer,l);

				l = sprintf(buffer,"\r\n#define BMP_X_SIZE_%s\t\t\t%d\r\n",name.data(),w);
				outFile.write(buffer,l);

				l = sprintf(buffer,"#define BMP_Y_SIZE_%s\t\t\t%d\r\n",name.data(),h);
				outFile.write(buffer,l);

				l = sprintf(buffer,"\r\nconst unsigned short bmp_%s[]={\r\n",name.data());
				outFile.write(buffer,l);
				
				while(cnt < byteLength)
				{
					bl = *pIndex++;
					bh = *pIndex++;
					rgb = bl | (bh << 8) ;
					l = sprintf(buffer,"0x%04x,",rgb) ;
					outFile.write(buffer,l);
					cnt += 2;
					if((cnt % (w*2)) == 0)
					{
						outFile.write("\r\n",2);
					}
				}
				outFile.write("\r\n};\r\n\r\n#endif\r\n",16);
				outFile.close();
				cout << "convert done ^_^ " << endl;
			}
		}
		else
		{
			cout << "Data error !!!" << endl ;
		}
	}
	else
	{
		cout << "this image format not support !!!" << endl ;
	}

	
	//cv::waitKey();

	// cv::Mat img_bgr565 ;
	// cv::Mat img_rgb565 ;
	// cv::cvtColor(imgInput,img_bgr565,cv::COLOR_BGR2BGR565);
	// cv::cvtColor(img_bgr565,img_rgb565,cv::COLOR_BGR5652RGB);
	// cv::imshow("rgb",img_rgb565);
	// cout << "img depth:" << img_rgb565.depth() << endl;
	// cout << "img_out" << img_rgb565 << endl ;
	// cv::waitKey();

	// cv::Mat imgbgr888(3,3,CV_8UC3,cv::Scalar(0,255,255));
	// cout << "show 888" << endl ;
	// cout << imgbgr888 << endl ;
	// cv::Mat imgbgr565;
	// cv::cvtColor(imgbgr888,imgbgr565,cv::COLOR_BGR2BGR565);
	// cout << "show 565" << endl ;
	// cout << imgbgr565 << endl ;

	return 0;
}


int convertDepth(const cv::Mat img)
{
	int type = img.type() ;
	cv::Mat imgRGB,imgBGR565 ;
	cv::cvtColor(img,imgBGR565,cv::COLOR_BGR2BGR565);
	cv::cvtColor(imgBGR565,imgRGB,cv::COLOR_BGR2RGB);
	
	switch (type)
	{
	case CV_8UC1:
		cout << "image type CV_8UC1" << endl ;
		cout << "not support!!!" << endl ;
		break;
	case CV_8UC2:
		cout << "image type CV_8UC2" << endl ;
		cout << "not support!!!" << endl ;
		break;
	case CV_8UC3:
		cout << "image type CV_8UC3" << endl ;
		cout << imgRGB << endl ;
		break;
	case CV_8UC4:
		cout << "image type CV_8UC4" << endl ;
		cout << "not support!!!" << endl ;
		break;
	default:
		break;
	}
	return 0;
}

