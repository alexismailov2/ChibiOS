/*
    ChibiOS - Copyright (C) 2006..2022 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <dirent.h>

#define NEWLINE_STR         "\r\n"

/*
 * Application entry point.
 */
int main(int argc, char *argv[], char *envp[]) {
  const char *path;
  DIR *dirp;
  struct dirent *dep;

  (void)envp;

  if (argc > 2) {
    fprintf(stderr, "Usage: ls [<dirpath>]" NEWLINE_STR);
    return 1;
  }

  if (argc == 1) {
    path = ".";
  }
  else {
    path = argv[1];
  }

  dirp = opendir(path);
  if (dirp == NULL) {
    fprintf(stderr, "ls: %s" NEWLINE_STR, strerror(errno));
    return 1;
  }

  while ((dep = readdir(dirp)) != NULL) {
    printf("%s" NEWLINE_STR, dep->d_name);
  }

  closedir(dirp);

  return 0;
}
