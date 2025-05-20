#include <stdio.h>

#define MAX_FRAMES 10
#define MAX_PAGES 50

void printFrames(int frames[], int frameCount) {
    for(int i = 0; i < frameCount; i++) {
        if(frames[i] == -1)
            printf(" - ");
        else
            printf(" %d ", frames[i]);
    }
    printf("\n");
}

int isInFrames(int frames[], int frameCount, int page) {
    for(int i = 0; i < frameCount; i++) {
        if(frames[i] == page)
            return 1;
    }
    return 0;
}

int main() {
    int pageSequence[MAX_PAGES], frames[MAX_FRAMES];
    int nPages, nFrames, i, j, pageFaults = 0;
    int pointer = 0;

    printf("Enter number of pages: ");
    scanf("%d", &nPages);
    printf("Enter the page reference string (space separated): ");
    for(i = 0; i < nPages; i++) {
        scanf("%d", &pageSequence[i]);
    }
    printf("Enter number of frames: ");
    scanf("%d", &nFrames);


    for(i = 0; i < nFrames; i++)
        frames[i] = -1;

    printf("\nPage Reference\tFrames\n");
    printf("----------------------------\n");
    for(i = 0; i < nPages; i++) {
        printf("     %2d\t\t", pageSequence[i]);

        if(!isInFrames(frames, nFrames, pageSequence[i])) {

            frames[pointer] = pageSequence[i];
            pointer = (pointer + 1) % nFrames;
            pageFaults++;
            printFrames(frames, nFrames);
        } else {
            printFrames(frames, nFrames);
        }
    }
    printf("\nTotal Page Faults = %d\n", pageFaults);

    return 0;
}

