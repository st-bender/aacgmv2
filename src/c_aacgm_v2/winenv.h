/* winenv.h
   =======
   Author: A.G.Burrell
           S.Bender
*/

/*
 (c) 2018 AGB/SB & Others - Please Consult LICENSE.superdarn-rst.3.2-beta-4-g32f7302.txt for more information.
*/

#ifndef _WINENV_H
#define _WINENV_H

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/* For windows, define setenv and unsetenv */
#if defined(_WIN32) || defined(_WIN64)
int setenv(const char *name, const char *value, int overwrite)
{
	int setsize;
	char envset[1000], *testenv;

	if (!overwrite) {
		testenv = getenv(name);
		setsize = strlen(testenv);
		if (setsize > 0)
			return -1;
	}

	snprintf(envset, 1000, "%s=%s", name, value);
	return putenv(envset);
}

int unsetenv(const char *name)
{
	extern char **environ;
	char **ep, **sp;
	size_t len;

	if (name == NULL || name[0] == '\0' || strchr(name, '=') != NULL) {
		errno = EINVAL;
		return -1;
	}

	len = strlen(name);

	for (ep = environ; *ep != NULL; ) {
		if (strncmp(*ep, name, len) == 0 && (*ep)[len] == '=') {
			/* Remove found entry by shifting all successive entries */
			/* back one element                                      */
			for (sp = ep; *sp != NULL; sp++)
				*sp = *(sp + 1);
			/* Continue around the loop to further instances of 'name' */
		}
		else ep++;
	}
	return 0;
}
#endif /* defined(_WIN32) || defined(_WIN64) */

#endif  /* _WINENV_H */
