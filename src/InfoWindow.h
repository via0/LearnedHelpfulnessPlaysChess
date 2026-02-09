
#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#define INFO_WINDOW_NUM_ROWS 20
#define INFO_WINDOW_NUM_COLS 80

typedef struct s_InfoWindow {
    char info[INFO_WINDOW_NUM_ROWS][INFO_WINDOW_NUM_COLS];
};

int InfoWindow_Initialize(struct s_InfoWindow* infoWindow);
void InfoWindow_Print(struct s_InfoWindow* infoWindow);
int InfoWindow_WriteLine(struct s_InfoWindow* infoWindow, const char* line);

#endif // INFOWINDOW_H
