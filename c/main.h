#define KEY_BOTTOM GDK_KEY_End
#define KEY_CLOSETAB GDK_KEY_w
#define KEY_DELETE GDK_KEY_Delete
#define KEY_DELETELINE GDK_KEY_d
#define KEY_DELETEPREVIOUSWORD GDK_KEY_BackSpace
#define KEY_FIND GDK_KEY_f
#define KEY_FINDMORE GDK_KEY_g
#define KEY_HIDEWINDOWS GDK_KEY_Escape
#define KEY_LINE GDK_KEY_l
#define KEY_NEWTAB GDK_KEY_t
#define KEY_OPEN GDK_KEY_o
#define KEY_REPLACE GDK_KEY_h
#define KEY_SAVE GDK_KEY_s
#define KEY_SELECTALL GDK_KEY_a
#define KEY_SORT GDK_KEY_r
#define KEY_TOP GDK_KEY_Home
#define KEY_UNDO GDK_KEY_z
#define KEY_UNDOCLEAR GDK_KEY_y

gchar *finding = NULL;
GtkNotebook *notebook;
GtkWidget *find_window;
GtkWidget *find_window_find;
GtkWidget *find_window_replace;
GtkWidget *line_window;
GtkWidget *line_window_line;

typedef struct tabcontents{
  int page;
  GtkWidget *text_view;
  GtkTextBuffer *text_buffer;
  GtkTextBuffer *undo_buffer;
  GtkTextBuffer *redo_buffer;
  GtkTextBuffer *map_buffer;
} tabcontents;

void activate(GtkApplication* app, gpointer data);
void block_insertdelete_signals(GtkTextBuffer *text_buffer);
gboolean check_equals_unsaved(void);
void close_tab(void);
void find_clear_tags(void);
void find_close(void);
const gchar* get_current_tab_label_text(void);
gchar* get_find_find(void);
gboolean get_notebook_no_pages(void);
GList* get_tabbox_children(GtkNotebook *tabnotebook, gint page);
struct tabcontents get_tab_contents(gint page);
void go_to_line(void);
int main(int argc, char **argv);
void menu_clearundoredo(void);
void menu_deleteline(void);
void menu_find(void);
void menu_findbottom(void);
void menu_findline(void);
void menu_findnext(void);
void menu_findprevious(void);
void menu_find_recursive(GtkTextBuffer *buffer, GtkTextIter start);
void menu_findreplaceall(void);
void menu_findtop(void);
void menu_hide(void);
void menu_open(void);
void menu_redo(void);
void menu_refind(void);
void menu_save(void);
void menu_saveas(void);
void menu_sort(void);
void menu_undo(void);
GtkWidget* new_scrolled_window(void);
void new_tab(void);
GtkWidget* new_textview(gboolean map);
void open_file(char *filename);
void place_cursor(GtkWidget *text_view, GtkTextBuffer *text_buffer, GtkTextIter *iter);
void save_tab(const char *filename);
void text_deleted(GtkTextBuffer *buffer, GtkTextIter *start, GtkTextIter *end);
void text_inserted(GtkTextBuffer *buffer, GtkTextIter *iter, gchar *value);
void unblock_insertdelete_signals(GtkTextBuffer *text_buffer);
gchar* undoredo_entry(gchar *value, gboolean inserted, gint line, gint lineoffset);
void update_map(void);
void update_opened_files(void);