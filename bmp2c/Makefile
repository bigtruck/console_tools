TARGET=bmp2c
CC=gcc
CXX=g++
CXXFLAGS =-std=c++0x
OBJ=bmp2c.o
SRC=bmp2c.cpp

HEADER_PATH = -I/usr/local/include/opencv4
LIB_PATH = -L/usr/local/lib
LIBS =  -lopencv_aruco \
		-lopencv_bgsegm \
		-lopencv_bioinspired \
		-lopencv_calib3d \
		-lopencv_ccalib \
		-lopencv_core \
		-lopencv_datasets \
		-lopencv_dnn \
		-lopencv_dpm \
		-lopencv_face \
		-lopencv_features2d \
		-lopencv_flann \
		-lopencv_fuzzy \
		-lopencv_highgui \
		-lopencv_imgcodecs \
		-lopencv_imgproc \
		-lopencv_line_descriptor \
		-lopencv_ml \
		-lopencv_objdetect \
		-lopencv_optflow \
		-lopencv_phase_unwrapping \
		-lopencv_photo \
		-lopencv_plot \
		-lopencv_reg \
		-lopencv_rgbd \
		-lopencv_saliency \
		-lopencv_shape \
		-lopencv_stereo \
		-lopencv_stitching \
		-lopencv_structured_light \
		-lopencv_superres \
		-lopencv_video \
		-lopencv_videoio

$(TARGET):$(OBJ)
	$(CXX) -o $(TARGET) $(OBJ) $(LIB_PATH) $(LIBS)

$(OBJ):$(SRC)
	$(CXX) -c $(SRC) $(HEADER_PATH) $(CXXFLAGS)

clean:
	rm $(OBJ) $(TARGET)
