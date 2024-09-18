#ifndef SENECA_UTILS_H
#define SENECA_UTILS_H

namespace seneca {
    bool readTitle(char title[]);
    bool readYear(int* year);
    bool readMovieRating(char rating[]);
    bool readDuration(int* duration);
    bool readGenres(char genres[][11]);
    bool readConsumerRating(float* rating);
    void flushkeys();
    bool yes();
    void toLowerCase(char* des, const char* src);

    bool openFile(const char filename[]);
    void closeFile();
}
#endif // SENECA_UTILS
