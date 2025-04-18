#ifndef SENECA_FILE_H
#define SENECA_FILE_H



namespace seneca {
	FILE* fptr;
	bool openFile(const char filename[]);
	void closeFile();
	bool readTitle(char title[]);
	bool readYear(int* year);
	bool readMovieRating(char rating[]);
	bool readDuration(int* duration);
	bool readGenres(char genres[][11]);
	bool readConsumerRating(float* rating);

}

#endif // !SENECA_FILE_H
