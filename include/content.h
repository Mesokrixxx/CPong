# ifndef PONG_CONTENT_H
# define PONG_CONTENT_H

typedef struct CONTENT_STRUCT {
	void (*init)(void* vSelf);
	void (*update)(void* vSelf);
	void (*draw)(void* vSelf);
} Content;

Content* initContent();
Content* contentConstructor(Content* self, void (*init)(void* vSelf), void (*update)(void* vSelf), void (*draw)(void* vSelf));
void contentInit(void* vSelf);
void contentUpdate(void* vSelf);
void contentDraw(void* vSelf);

# endif