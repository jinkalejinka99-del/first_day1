#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define API_KEY "YOUR_API_KEY"
#define BUFFER_SIZE 8192

// ---------------- GET WEATHER ----------------
void get_weather(char *city, char *weather, float *temp, int *humidity) {
    char command[512];
    snprintf(command, sizeof(command),
        "curl -s \"http://api.openweathermap.org/data/2.5/weather?q=%s&appid=%s&units=metric\"",
        city, API_KEY);

    FILE *fp = popen(command, "r");
    if (fp == NULL) {
        strcpy(weather, "Error");
        return;
    }

    char buffer[BUFFER_SIZE];
    fread(buffer, 1, BUFFER_SIZE, fp);
    pclose(fp);

    // crude JSON parsing (simple but works)
    char *w = strstr(buffer, "\"description\":\"");
    char *t = strstr(buffer, "\"temp\":");
    char *h = strstr(buffer, "\"humidity\":");

    if (w && t && h) {
        sscanf(w, "\"description\":\"%[^\"]\"", weather);
        sscanf(t, "\"temp\":%f", temp);
        sscanf(h, "\"humidity\":%d", humidity);
    } else {
        strcpy(weather, "Not found");
        *temp = 0;
        *humidity = 0;
    }
}

// ---------------- GET RAM ----------------
float get_ram_usage() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) return 0;

    long total = 0, free = 0;
    char label[64];
    long value;

    while (fscanf(fp, "%s %ld kB\n", label, &value) != EOF) {
        if (strcmp(label, "MemTotal:") == 0)
            total = value;
        else if (strcmp(label, "MemAvailable:") == 0) {
            free = value;
            break;
        }
    }

    fclose(fp);
    return
