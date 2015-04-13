LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

include /opt/NVKit/NVPACK/OpenCV-2.4.8.2-Tegra-sdk/sdk/native/jni/OpenCV.mk

ifeq (1, $(NDK_DEBUG))
LOCAL_CFLAGS += -DWAIT_FOR_DEBUGGER
endif

LOCAL_MODULE    := TrojanCam
LOCAL_SRC_FILES := TrojanCam.cpp

LOCAL_LDLIBS +=  -llog -ldl

include $(BUILD_SHARED_LIBRARY)

