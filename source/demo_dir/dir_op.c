#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main()
{
    DIR *dp;
    struct dirent *ep;

    dp = opendir("./");
    if(dp != NULL) {
        while(ep = readdir(dp)) {
            printf("%s\n", ep->d_name);
        }
    } else {
        perror("opendir error!\n");
    }

    closedir(dp);

    return 0;
}

