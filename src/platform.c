#include <abyss/platform.h>

#include <stdalign.h>

#include "lay_out.h"

///////////////////////////////////////////////////////////////////////////////

abyss_error_t abyss_platform_acquire_handler(abyss_platform_t *self,
    abyss_allocator_t *allocator,
    size_t context_size, size_t context_alignment,
    abyss_handler_t **handler_out)
{
    abyss_task_t *task = NULL;

    abyss_error_t error = ABYSS_ERROR_NONE;

    size_t offsets[2];
    size_t task_context_size;
    size_t task_context_alignment;
    abyss_impl_lay_out(2,
        (size_t[]) { sizeof(abyss_handler_t), context_size },
        (size_t[]) { alignof(abyss_handler_t), context_alignment },
        offsets,
        &task_context_size, &task_context_alignment);
    size_t handler_offset = offsets[0];
    size_t context_offset = offsets[1];

    if ((error = abyss_platform_acquire_task(self,
        allocator, task_context_size, task_context_alignment, &task)))
    { goto out; }
    abyss_handler_t *handler =
        (void *) ((char *) task->context + handler_offset);
    *handler = (abyss_handler_t) {
        .task = task,
        .context = (char *) task->context + context_offset,
    };

    *handler_out = handler; task = NULL;
out:
    abyss_task_release(task);

    return error;
}
