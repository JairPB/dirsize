// This is a program to find the size of any entire directory we pass

#define _XOPEN_SOURCE 500
#include <ftw.h>
#include <stdio.h>
#include <stdlib.h>

size_t dirsize = 0;

// This function will sum up every file under the pathname we pass
int add_to_filesize(const char *fpath, const struct stat *sb, int typeflag,
                    struct FTW *ftwbuf) {
  dirsize += sb->st_size;
  return 0;
}

void pretty_print_size() {
  char *sizes[] = {
      "B", "KB", "MB", "GB", "TB",
  };
  int count = sizeof(sizes) / sizeof(sizes[0]);
  double bytes = dirsize;

  int i;
  for (i = 0; i < count && bytes > 1000; i++) {
    // Divide the number by 1000
    bytes /= 1000;
  }
  printf("%.2f %s\n", bytes, sizes[i]);
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("You need to pass a directory like this: %s <dirname>\n", argv[0]);
    exit(0);
  }

  // Get the directory name
  char *dirname = argv[1];
  printf("Directory: %s\n", dirname);

  // Take the files under our passed directory name
  // using our previous declared function
  nftw(dirname, add_to_filesize, 20, 0);
  pretty_print_size();
  return 0;
}
