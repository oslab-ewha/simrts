#include "simrts.h"

static BOOL
dfdm_assign_task(task_t *task)
{
	mem_type_t	mem_types_try[] = { MEMTYPE_DRAM, MEMTYPE_NVRAM };
	int	i;

	task->idx_cpufreq = 1;
	for (i = 0; i < 2; i++) {
		if (assign_mem(task, mem_types_try[i]))
			return TRUE;
	}
	return FALSE;
}

static BOOL
dfdm_reassign_task(task_t *task)
{
	mem_type_t	mem_types_try[] = { MEMTYPE_NVRAM, MEMTYPE_DRAM };
	int	i;

	revoke_mem(task);

	for (i = 0; i < 2; i++) {
		if (assign_mem(task, mem_types_try[i])) {
			int	j;

			for (j = n_cpufreqs; j > 0; j--) {
				task->idx_cpufreq = j;
				if (is_schedulable())
					return TRUE;
			}
			revoke_mem(task);
		}
	}
	return FALSE;
}

policy_t	policy_dfdm = {
	dfdm_assign_task,
	dfdm_reassign_task
};