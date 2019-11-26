#include <time.h>
#include <errno.h>

#include "cache/cache.h"

#include "vcc_sleep_if.h"

#define VMOD_SLEEP_NS	(1000 * 1000 * 1000)

VCL_VOID
vmod_sleep(VRT_CTX, VCL_DURATION t)
{
	struct timespec tspec, rem;

	tspec.tv_sec = (time_t)floor(t);
	tspec.tv_nsec = ((long)(t * VMOD_SLEEP_NS)) % VMOD_SLEEP_NS;

	VSLb(ctx->vsl, SLT_VCL_Log, "sleep %lfs (%lds %ldns)", t, tspec.tv_sec, tspec.tv_nsec);

	while (nanosleep(&tspec, &rem) && errno == EINTR) {
		tspec.tv_sec = rem.tv_sec;
		tspec.tv_nsec = rem.tv_nsec;

		VSLb(ctx->vsl, SLT_VCL_Log, "interrupted, sleep %lfs (%lds %ldns)", t, tspec.tv_sec, tspec.tv_nsec);
	}
}
