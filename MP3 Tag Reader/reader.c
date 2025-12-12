#include <stdio.h>
#include <string.h>
#include "reader.h"

int readTag(const char *filename, id3v *tag)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp)
    {
        printf("File is not present\n");
        return 0;
    }

    if (fseek(fp, -128, SEEK_END) != 0)
    {
        printf("File too small or corrupted.\n");
        fclose(fp);
        return 0;
    }

    if (fread(tag, 1, sizeof(id3v), fp) != sizeof(id3v))
    {
        printf("Failed to read tag.\n");
        fclose(fp);
        return 0;
    }

    if (strncmp(tag->tag, "TAG", 3) != 0)
    {
        printf("🔈 ID3 TAG is not present 🎵\n");
        fclose(fp);
        return 0;
    }

    fclose(fp);
    return 1;
}

void displayID3v1(const id3v *tag)
{
    const char *RESET   = "\x1b[0m";
    const char *BOLD    = "\x1b[1m";
    const char *BLUE    = "\x1b[34m";
    const char *CYAN    = "\x1b[36m";
    const char *YELLOW  = "\x1b[33m";
    const char *MAGENTA = "\x1b[35m";

    // Header
    printf("\n%s%s╔══════════════════════════════════════════════════════╗%s\n", BOLD, BLUE, RESET);
    printf("%s%s              MP3 TAG INSIGHT REPORT (ID3v1)          %s\n", BOLD, CYAN, RESET);
    printf("%s%s╚══════════════════════════════════════════════════════╝%s\n\n", BOLD, BLUE, RESET);

    // Content block – NO SIDE BOUNDARIES
    printf("%s══════════════════════════════════════════════════════%s\n", BLUE, RESET);

    printf("Title        : %s%s%s\n",   YELLOW, tag->title,   RESET);
    printf("Artist       : %s%s%s\n",   YELLOW, tag->artist,  RESET);
    printf("Album        : %s%s%s\n",   YELLOW, tag->album,   RESET);
    printf("Year         : %s%.4s%s\n", YELLOW, tag->year,    RESET);
    printf("Comment      : %s%s%s\n",   YELLOW, tag->comment, RESET);
    printf("Genre        : %s%d%s\n",   YELLOW, tag->genre,   RESET);

    printf("%s══════════════════════════════════════════════════════%s\n\n", BLUE, RESET);

    printf("%s%sMetadata extraction completed.%s\n\n", BOLD, MAGENTA, RESET);
}



