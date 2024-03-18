#include "init.c"
#include "getargs.c"
#include "getargsfast.c"
#include "int_ops.c"
#include "float_ops.c"
#include "str_ops.c"
#include "bytes_ops.c"
#include "list_ops.c"
#include "dict_ops.c"
#include "set_ops.c"
#include "tuple_ops.c"
#include "exc_ops.c"
#include "misc_ops.c"
#include "generic_ops.c"
#include "__native.h"
#include "__native_internal.h"

static int
Game_init(PyObject *self, PyObject *args, PyObject *kwds)
{
    return 0;
}
static PyObject *Game_setup(PyTypeObject *type);
PyObject *CPyDef_Game(PyObject *cpy_r_master);

static PyObject *
Game_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_Game) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    PyObject *self = Game_setup(type);
    if (self == NULL)
        return NULL;
    PyObject *ret = CPyPy_Game_____init__(self, args, kwds);
    if (ret == NULL)
        return NULL;
    return self;
}

static int
Game_traverse(main___GameObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->_dictionary);
    Py_VISIT(self->_scores);
    Py_VISIT(self->_master);
    if (CPyTagged_CheckLong(self->_word_length)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_word_length));
    }
    if (CPyTagged_CheckLong(self->_time_limit)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_time_limit));
    }
    if (CPyTagged_CheckLong(self->_score)) {
        Py_VISIT(CPyTagged_LongAsObject(self->_score));
    }
    Py_VISIT(self->_used_words);
    Py_VISIT(self->_entry);
    Py_VISIT(self->_label);
    return 0;
}

static int
Game_clear(main___GameObject *self)
{
    Py_CLEAR(self->_dictionary);
    Py_CLEAR(self->_scores);
    Py_CLEAR(self->_master);
    if (CPyTagged_CheckLong(self->_word_length)) {
        CPyTagged __tmp = self->_word_length;
        self->_word_length = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_time_limit)) {
        CPyTagged __tmp = self->_time_limit;
        self->_time_limit = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    if (CPyTagged_CheckLong(self->_score)) {
        CPyTagged __tmp = self->_score;
        self->_score = CPY_INT_TAG;
        Py_XDECREF(CPyTagged_LongAsObject(__tmp));
    }
    Py_CLEAR(self->_used_words);
    Py_CLEAR(self->_entry);
    Py_CLEAR(self->_label);
    return 0;
}

static void
Game_dealloc(main___GameObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, Game_dealloc)
    Game_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem Game_vtable[8];
static bool
CPyDef_Game_trait_vtable_setup(void)
{
    CPyVTableItem Game_vtable_scratch[] = {
        (CPyVTableItem)CPyDef_Game_____init__,
        (CPyVTableItem)CPyDef_Game___update,
        (CPyVTableItem)CPyDef_Game___is_time_up,
        (CPyVTableItem)CPyDef_Game___end_game,
        (CPyVTableItem)CPyDef_Game___check_and_update_word,
        (CPyVTableItem)CPyDef_Game___level_up,
        (CPyVTableItem)CPyDef_Game___save_score,
        (CPyVTableItem)CPyDef_Game___show_leaderboard,
    };
    memcpy(Game_vtable, Game_vtable_scratch, sizeof(Game_vtable));
    return 1;
}

static PyObject *
Game_get_dictionary(main___GameObject *self, void *closure);
static int
Game_set_dictionary(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_scores(main___GameObject *self, void *closure);
static int
Game_set_scores(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_master(main___GameObject *self, void *closure);
static int
Game_set_master(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_word_length(main___GameObject *self, void *closure);
static int
Game_set_word_length(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_time_limit(main___GameObject *self, void *closure);
static int
Game_set_time_limit(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_score(main___GameObject *self, void *closure);
static int
Game_set_score(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_start_time(main___GameObject *self, void *closure);
static int
Game_set_start_time(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_used_words(main___GameObject *self, void *closure);
static int
Game_set_used_words(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_entry(main___GameObject *self, void *closure);
static int
Game_set_entry(main___GameObject *self, PyObject *value, void *closure);
static PyObject *
Game_get_label(main___GameObject *self, void *closure);
static int
Game_set_label(main___GameObject *self, PyObject *value, void *closure);

static PyGetSetDef Game_getseters[] = {
    {"dictionary",
     (getter)Game_get_dictionary, (setter)Game_set_dictionary,
     NULL, NULL},
    {"scores",
     (getter)Game_get_scores, (setter)Game_set_scores,
     NULL, NULL},
    {"master",
     (getter)Game_get_master, (setter)Game_set_master,
     NULL, NULL},
    {"word_length",
     (getter)Game_get_word_length, (setter)Game_set_word_length,
     NULL, NULL},
    {"time_limit",
     (getter)Game_get_time_limit, (setter)Game_set_time_limit,
     NULL, NULL},
    {"score",
     (getter)Game_get_score, (setter)Game_set_score,
     NULL, NULL},
    {"start_time",
     (getter)Game_get_start_time, (setter)Game_set_start_time,
     NULL, NULL},
    {"used_words",
     (getter)Game_get_used_words, (setter)Game_set_used_words,
     NULL, NULL},
    {"entry",
     (getter)Game_get_entry, (setter)Game_set_entry,
     NULL, NULL},
    {"label",
     (getter)Game_get_label, (setter)Game_set_label,
     NULL, NULL},
    {NULL}  /* Sentinel */
};

static PyMethodDef Game_methods[] = {
    {"__init__",
     (PyCFunction)CPyPy_Game_____init__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"update",
     (PyCFunction)CPyPy_Game___update,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"is_time_up",
     (PyCFunction)CPyPy_Game___is_time_up,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"end_game",
     (PyCFunction)CPyPy_Game___end_game,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"check_and_update_word",
     (PyCFunction)CPyPy_Game___check_and_update_word,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"level_up",
     (PyCFunction)CPyPy_Game___level_up,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"save_score",
     (PyCFunction)CPyPy_Game___save_score,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"show_leaderboard",
     (PyCFunction)CPyPy_Game___show_leaderboard,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_Game_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "Game",
    .tp_new = Game_new,
    .tp_dealloc = (destructor)Game_dealloc,
    .tp_traverse = (traverseproc)Game_traverse,
    .tp_clear = (inquiry)Game_clear,
    .tp_getset = Game_getseters,
    .tp_methods = Game_methods,
    .tp_init = Game_init,
    .tp_basicsize = sizeof(main___GameObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_Game_template = &CPyType_Game_template_;

static PyObject *
Game_setup(PyTypeObject *type)
{
    main___GameObject *self;
    self = (main___GameObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = Game_vtable;
    self->_word_length = CPY_INT_TAG;
    self->_time_limit = CPY_INT_TAG;
    self->_score = CPY_INT_TAG;
    self->_start_time = -113.0;
    return (PyObject *)self;
}

PyObject *CPyDef_Game(PyObject *cpy_r_master)
{
    PyObject *self = Game_setup(CPyType_Game);
    if (self == NULL)
        return NULL;
    char res = CPyDef_Game_____init__(self, cpy_r_master);
    if (res == 2) {
        Py_DECREF(self);
        return NULL;
    }
    return self;
}

static PyObject *
Game_get_dictionary(main___GameObject *self, void *closure)
{
    if (unlikely(self->_dictionary == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'dictionary' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_dictionary);
    PyObject *retval = self->_dictionary;
    return retval;
}

static int
Game_set_dictionary(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'dictionary' cannot be deleted");
        return -1;
    }
    if (self->_dictionary != NULL) {
        CPy_DECREF(self->_dictionary);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_dictionary = tmp;
    return 0;
}

static PyObject *
Game_get_scores(main___GameObject *self, void *closure)
{
    if (unlikely(self->_scores == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'scores' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_scores);
    PyObject *retval = self->_scores;
    return retval;
}

static int
Game_set_scores(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'scores' cannot be deleted");
        return -1;
    }
    if (self->_scores != NULL) {
        CPy_DECREF(self->_scores);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_scores = tmp;
    return 0;
}

static PyObject *
Game_get_master(main___GameObject *self, void *closure)
{
    if (unlikely(self->_master == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'master' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_master);
    PyObject *retval = self->_master;
    return retval;
}

static int
Game_set_master(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'master' cannot be deleted");
        return -1;
    }
    if (self->_master != NULL) {
        CPy_DECREF(self->_master);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_master = tmp;
    return 0;
}

static PyObject *
Game_get_word_length(main___GameObject *self, void *closure)
{
    if (unlikely(self->_word_length == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'word_length' of 'Game' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_word_length);
    PyObject *retval = CPyTagged_StealAsObject(self->_word_length);
    return retval;
}

static int
Game_set_word_length(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'word_length' cannot be deleted");
        return -1;
    }
    if (self->_word_length != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_word_length);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_word_length = tmp;
    return 0;
}

static PyObject *
Game_get_time_limit(main___GameObject *self, void *closure)
{
    if (unlikely(self->_time_limit == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'time_limit' of 'Game' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_time_limit);
    PyObject *retval = CPyTagged_StealAsObject(self->_time_limit);
    return retval;
}

static int
Game_set_time_limit(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'time_limit' cannot be deleted");
        return -1;
    }
    if (self->_time_limit != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_time_limit);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_time_limit = tmp;
    return 0;
}

static PyObject *
Game_get_score(main___GameObject *self, void *closure)
{
    if (unlikely(self->_score == CPY_INT_TAG)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'score' of 'Game' undefined");
        return NULL;
    }
    CPyTagged_INCREF(self->_score);
    PyObject *retval = CPyTagged_StealAsObject(self->_score);
    return retval;
}

static int
Game_set_score(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'score' cannot be deleted");
        return -1;
    }
    if (self->_score != CPY_INT_TAG) {
        CPyTagged_DECREF(self->_score);
    }
    CPyTagged tmp;
    if (likely(PyLong_Check(value)))
        tmp = CPyTagged_FromObject(value);
    else {
        CPy_TypeError("int", value); return -1;
    }
    CPyTagged_INCREF(tmp);
    self->_score = tmp;
    return 0;
}

static PyObject *
Game_get_start_time(main___GameObject *self, void *closure)
{
    PyObject *retval = PyFloat_FromDouble(self->_start_time);
    return retval;
}

static int
Game_set_start_time(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'start_time' cannot be deleted");
        return -1;
    }
    double tmp;
    tmp = PyFloat_AsDouble(value);
    if (tmp == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", value); return -1;
    }
    self->_start_time = tmp;
    return 0;
}

static PyObject *
Game_get_used_words(main___GameObject *self, void *closure)
{
    if (unlikely(self->_used_words == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'used_words' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_used_words);
    PyObject *retval = self->_used_words;
    return retval;
}

static int
Game_set_used_words(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'used_words' cannot be deleted");
        return -1;
    }
    if (self->_used_words != NULL) {
        CPy_DECREF(self->_used_words);
    }
    PyObject *tmp;
    if (likely(PySet_Check(value)))
        tmp = value;
    else {
        CPy_TypeError("set", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->_used_words = tmp;
    return 0;
}

static PyObject *
Game_get_entry(main___GameObject *self, void *closure)
{
    if (unlikely(self->_entry == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'entry' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_entry);
    PyObject *retval = self->_entry;
    return retval;
}

static int
Game_set_entry(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'entry' cannot be deleted");
        return -1;
    }
    if (self->_entry != NULL) {
        CPy_DECREF(self->_entry);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_entry = tmp;
    return 0;
}

static PyObject *
Game_get_label(main___GameObject *self, void *closure)
{
    if (unlikely(self->_label == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute 'label' of 'Game' undefined");
        return NULL;
    }
    CPy_INCREF(self->_label);
    PyObject *retval = self->_label;
    return retval;
}

static int
Game_set_label(main___GameObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'Game' object attribute 'label' cannot be deleted");
        return -1;
    }
    if (self->_label != NULL) {
        CPy_DECREF(self->_label);
    }
    PyObject *tmp = value;
    CPy_INCREF(tmp);
    self->_label = tmp;
    return 0;
}

static PyObject *show_leaderboard_Game_env_setup(PyTypeObject *type);
PyObject *CPyDef_show_leaderboard_Game_env(void);

static PyObject *
show_leaderboard_Game_env_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType_show_leaderboard_Game_env) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return show_leaderboard_Game_env_setup(type);
}

static int
show_leaderboard_Game_env_traverse(main___show_leaderboard_Game_envObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_self__);
    Py_VISIT(self->_self);
    Py_VISIT(self->_leaderboard_window);
    Py_VISIT(self->_name);
    Py_VISIT(self->_score);
    return 0;
}

static int
show_leaderboard_Game_env_clear(main___show_leaderboard_Game_envObject *self)
{
    Py_CLEAR(self->___mypyc_self__);
    Py_CLEAR(self->_self);
    Py_CLEAR(self->_leaderboard_window);
    Py_CLEAR(self->_name);
    Py_CLEAR(self->_score);
    return 0;
}

static void
show_leaderboard_Game_env_dealloc(main___show_leaderboard_Game_envObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, show_leaderboard_Game_env_dealloc)
    show_leaderboard_Game_env_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem show_leaderboard_Game_env_vtable[1];
static bool
CPyDef_show_leaderboard_Game_env_trait_vtable_setup(void)
{
    CPyVTableItem show_leaderboard_Game_env_vtable_scratch[] = {
        NULL
    };
    memcpy(show_leaderboard_Game_env_vtable, show_leaderboard_Game_env_vtable_scratch, sizeof(show_leaderboard_Game_env_vtable));
    return 1;
}

static PyMethodDef show_leaderboard_Game_env_methods[] = {
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType_show_leaderboard_Game_env_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "show_leaderboard_Game_env",
    .tp_new = show_leaderboard_Game_env_new,
    .tp_dealloc = (destructor)show_leaderboard_Game_env_dealloc,
    .tp_traverse = (traverseproc)show_leaderboard_Game_env_traverse,
    .tp_clear = (inquiry)show_leaderboard_Game_env_clear,
    .tp_methods = show_leaderboard_Game_env_methods,
    .tp_basicsize = sizeof(main___show_leaderboard_Game_envObject),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC,
};
static PyTypeObject *CPyType_show_leaderboard_Game_env_template = &CPyType_show_leaderboard_Game_env_template_;

static PyObject *
show_leaderboard_Game_env_setup(PyTypeObject *type)
{
    main___show_leaderboard_Game_envObject *self;
    self = (main___show_leaderboard_Game_envObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = show_leaderboard_Game_env_vtable;
    return (PyObject *)self;
}

PyObject *CPyDef_show_leaderboard_Game_env(void)
{
    PyObject *self = show_leaderboard_Game_env_setup(CPyType_show_leaderboard_Game_env);
    if (self == NULL)
        return NULL;
    return self;
}


static PyObject *CPyDunder___get____mypyc_lambda__0_show_leaderboard_Game_obj(PyObject *self, PyObject *instance, PyObject *owner) {
    instance = instance ? instance : Py_None;
    return CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(self, instance, owner);
}
PyMemberDef __mypyc_lambda__0_show_leaderboard_Game_obj_members[] = {
    {"__dict__", T_OBJECT_EX, sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject), 0, NULL},
    {"__weakref__", T_OBJECT_EX, sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject) + sizeof(PyObject *), 0, NULL},
    {0}
};
static PyObject *__mypyc_lambda__0_show_leaderboard_Game_obj_setup(PyTypeObject *type);
PyObject *CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj(void);

static PyObject *
__mypyc_lambda__0_show_leaderboard_Game_obj_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    if (type != CPyType___mypyc_lambda__0_show_leaderboard_Game_obj) {
        PyErr_SetString(PyExc_TypeError, "interpreted classes cannot inherit from compiled");
        return NULL;
    }
    return __mypyc_lambda__0_show_leaderboard_Game_obj_setup(type);
}

static int
__mypyc_lambda__0_show_leaderboard_Game_obj_traverse(main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self, visitproc visit, void *arg)
{
    Py_VISIT(self->___mypyc_env__);
    Py_VISIT(*((PyObject **)((char *)self + sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject))));
    Py_VISIT(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject))));
    return 0;
}

static int
__mypyc_lambda__0_show_leaderboard_Game_obj_clear(main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self)
{
    Py_CLEAR(self->___mypyc_env__);
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject))));
    Py_CLEAR(*((PyObject **)((char *)self + sizeof(PyObject *) + sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject))));
    return 0;
}

static void
__mypyc_lambda__0_show_leaderboard_Game_obj_dealloc(main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self)
{
    PyObject_GC_UnTrack(self);
    CPy_TRASHCAN_BEGIN(self, __mypyc_lambda__0_show_leaderboard_Game_obj_dealloc)
    __mypyc_lambda__0_show_leaderboard_Game_obj_clear(self);
    Py_TYPE(self)->tp_free((PyObject *)self);
    CPy_TRASHCAN_END(self)
}

static CPyVTableItem __mypyc_lambda__0_show_leaderboard_Game_obj_vtable[2];
static bool
CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_trait_vtable_setup(void)
{
    CPyVTableItem __mypyc_lambda__0_show_leaderboard_Game_obj_vtable_scratch[] = {
        (CPyVTableItem)CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____call__,
        (CPyVTableItem)CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____get__,
    };
    memcpy(__mypyc_lambda__0_show_leaderboard_Game_obj_vtable, __mypyc_lambda__0_show_leaderboard_Game_obj_vtable_scratch, sizeof(__mypyc_lambda__0_show_leaderboard_Game_obj_vtable));
    return 1;
}

static PyObject *
__mypyc_lambda__0_show_leaderboard_Game_obj_get___3_mypyc_env__(main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self, void *closure);
static int
__mypyc_lambda__0_show_leaderboard_Game_obj_set___3_mypyc_env__(main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self, PyObject *value, void *closure);

static PyGetSetDef __mypyc_lambda__0_show_leaderboard_Game_obj_getseters[] = {
    {"__mypyc_env__",
     (getter)__mypyc_lambda__0_show_leaderboard_Game_obj_get___3_mypyc_env__, (setter)__mypyc_lambda__0_show_leaderboard_Game_obj_set___3_mypyc_env__,
     NULL, NULL},
    {"__dict__", PyObject_GenericGetDict, PyObject_GenericSetDict},
    {NULL}  /* Sentinel */
};

static PyMethodDef __mypyc_lambda__0_show_leaderboard_Game_obj_methods[] = {
    {"__call__",
     (PyCFunction)CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____call__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__get__",
     (PyCFunction)CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____get__,
     METH_FASTCALL | METH_KEYWORDS, NULL},
    {"__setstate__", (PyCFunction)CPyPickle_SetState, METH_O, NULL},
    {"__getstate__", (PyCFunction)CPyPickle_GetState, METH_NOARGS, NULL},
    {NULL}  /* Sentinel */
};

static PyTypeObject CPyType___mypyc_lambda__0_show_leaderboard_Game_obj_template_ = {
    PyVarObject_HEAD_INIT(NULL, 0)
    .tp_name = "__mypyc_lambda__0_show_leaderboard_Game_obj",
    .tp_new = __mypyc_lambda__0_show_leaderboard_Game_obj_new,
    .tp_dealloc = (destructor)__mypyc_lambda__0_show_leaderboard_Game_obj_dealloc,
    .tp_traverse = (traverseproc)__mypyc_lambda__0_show_leaderboard_Game_obj_traverse,
    .tp_clear = (inquiry)__mypyc_lambda__0_show_leaderboard_Game_obj_clear,
    .tp_getset = __mypyc_lambda__0_show_leaderboard_Game_obj_getseters,
    .tp_methods = __mypyc_lambda__0_show_leaderboard_Game_obj_methods,
    .tp_call = PyVectorcall_Call,
    .tp_descr_get = CPyDunder___get____mypyc_lambda__0_show_leaderboard_Game_obj,
    .tp_members = __mypyc_lambda__0_show_leaderboard_Game_obj_members,
    .tp_basicsize = sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject) + 2*sizeof(PyObject *),
    .tp_dictoffset = sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject),
    .tp_weaklistoffset = sizeof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject) + sizeof(PyObject *),
    .tp_vectorcall_offset = offsetof(main_____mypyc_lambda__0_show_leaderboard_Game_objObject, vectorcall),
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_HEAPTYPE | Py_TPFLAGS_BASETYPE | Py_TPFLAGS_HAVE_GC | _Py_TPFLAGS_HAVE_VECTORCALL,
};
static PyTypeObject *CPyType___mypyc_lambda__0_show_leaderboard_Game_obj_template = &CPyType___mypyc_lambda__0_show_leaderboard_Game_obj_template_;

static PyObject *
__mypyc_lambda__0_show_leaderboard_Game_obj_setup(PyTypeObject *type)
{
    main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self;
    self = (main_____mypyc_lambda__0_show_leaderboard_Game_objObject *)type->tp_alloc(type, 0);
    if (self == NULL)
        return NULL;
    self->vtable = __mypyc_lambda__0_show_leaderboard_Game_obj_vtable;
    self->vectorcall = CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____call__;
    return (PyObject *)self;
}

PyObject *CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj(void)
{
    PyObject *self = __mypyc_lambda__0_show_leaderboard_Game_obj_setup(CPyType___mypyc_lambda__0_show_leaderboard_Game_obj);
    if (self == NULL)
        return NULL;
    return self;
}

static PyObject *
__mypyc_lambda__0_show_leaderboard_Game_obj_get___3_mypyc_env__(main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self, void *closure)
{
    if (unlikely(self->___mypyc_env__ == NULL)) {
        PyErr_SetString(PyExc_AttributeError,
            "attribute '__mypyc_env__' of '__mypyc_lambda__0_show_leaderboard_Game_obj' undefined");
        return NULL;
    }
    CPy_INCREF(self->___mypyc_env__);
    PyObject *retval = self->___mypyc_env__;
    return retval;
}

static int
__mypyc_lambda__0_show_leaderboard_Game_obj_set___3_mypyc_env__(main_____mypyc_lambda__0_show_leaderboard_Game_objObject *self, PyObject *value, void *closure)
{
    if (value == NULL) {
        PyErr_SetString(PyExc_AttributeError,
            "'__mypyc_lambda__0_show_leaderboard_Game_obj' object attribute '__mypyc_env__' cannot be deleted");
        return -1;
    }
    if (self->___mypyc_env__ != NULL) {
        CPy_DECREF(self->___mypyc_env__);
    }
    PyObject *tmp;
    if (likely(Py_TYPE(value) == CPyType_show_leaderboard_Game_env))
        tmp = value;
    else {
        CPy_TypeError("main.show_leaderboard_Game_env", value); 
        tmp = NULL;
    }
    if (!tmp)
        return -1;
    CPy_INCREF(tmp);
    self->___mypyc_env__ = tmp;
    return 0;
}
static PyMethodDef module_methods[] = {
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "main",
    NULL, /* docstring */
    -1,       /* size of per-interpreter state of the module,
                 or -1 if the module keeps state in global variables. */
    module_methods
};

PyMODINIT_FUNC PyInit_main(void)
{
    PyObject* modname = NULL;
    if (CPyModule_main_internal) {
        Py_INCREF(CPyModule_main_internal);
        return CPyModule_main_internal;
    }
    CPyModule_main_internal = PyModule_Create(&module);
    if (unlikely(CPyModule_main_internal == NULL))
        goto fail;
    modname = PyObject_GetAttrString((PyObject *)CPyModule_main_internal, "__name__");
    CPyStatic_globals = PyModule_GetDict(CPyModule_main_internal);
    if (unlikely(CPyStatic_globals == NULL))
        goto fail;
    CPyType_show_leaderboard_Game_env = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType_show_leaderboard_Game_env_template, NULL, modname);
    if (unlikely(!CPyType_show_leaderboard_Game_env))
        goto fail;
    CPyType___mypyc_lambda__0_show_leaderboard_Game_obj = (PyTypeObject *)CPyType_FromTemplate((PyObject *)CPyType___mypyc_lambda__0_show_leaderboard_Game_obj_template, NULL, modname);
    if (unlikely(!CPyType___mypyc_lambda__0_show_leaderboard_Game_obj))
        goto fail;
    if (CPyGlobalsInit() < 0)
        goto fail;
    char result = CPyDef___top_level__();
    if (result == 2)
        goto fail;
    Py_DECREF(modname);
    return CPyModule_main_internal;
    fail:
    Py_CLEAR(CPyModule_main_internal);
    Py_CLEAR(modname);
    Py_CLEAR(CPyType_Game);
    Py_CLEAR(CPyType_show_leaderboard_Game_env);
    Py_CLEAR(CPyType___mypyc_lambda__0_show_leaderboard_Game_obj);
    return NULL;
}

char CPyDef_Game_____init__(PyObject *cpy_r_self, PyObject *cpy_r_master) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject **cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject **cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject **cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject **cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject **cpy_r_r35;
    PyObject *cpy_r_r36;
    PyObject *cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    double cpy_r_r42;
    char cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject **cpy_r_r50;
    PyObject *cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    PyObject **cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject **cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject **cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject **cpy_r_r76;
    PyObject *cpy_r_r77;
    char cpy_r_r78;
    cpy_r_r0 = CPyStatics[3]; /* 'en_US' */
    cpy_r_r1 = CPyStatic_globals;
    cpy_r_r2 = CPyStatics[4]; /* 'Dict' */
    cpy_r_r3 = CPyDict_GetItem(cpy_r_r1, cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 37, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r4[1] = {cpy_r_r0};
    cpy_r_r5 = (PyObject **)&cpy_r_r4;
    cpy_r_r6 = _PyObject_Vectorcall(cpy_r_r3, cpy_r_r5, 1, 0);
    CPy_DECREF(cpy_r_r3);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 37, CPyStatic_globals);
        goto CPyL29;
    }
    ((main___GameObject *)cpy_r_self)->_dictionary = cpy_r_r6;
    cpy_r_r7 = CPyStatics[5]; /* 'scores.json' */
    cpy_r_r8 = CPyStatic_globals;
    cpy_r_r9 = CPyStatics[6]; /* 'isfile' */
    cpy_r_r10 = CPyDict_GetItem(cpy_r_r8, cpy_r_r9);
    if (unlikely(cpy_r_r10 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 40, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r11[1] = {cpy_r_r7};
    cpy_r_r12 = (PyObject **)&cpy_r_r11;
    cpy_r_r13 = _PyObject_Vectorcall(cpy_r_r10, cpy_r_r12, 1, 0);
    CPy_DECREF(cpy_r_r10);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 40, CPyStatic_globals);
        goto CPyL29;
    }
    if (unlikely(!PyBool_Check(cpy_r_r13))) {
        CPy_TypeError("bool", cpy_r_r13); cpy_r_r14 = 2;
    } else
        cpy_r_r14 = cpy_r_r13 == Py_True;
    CPy_DECREF(cpy_r_r13);
    if (unlikely(cpy_r_r14 == 2)) {
        CPy_AddTraceback("main.py", "__init__", 40, CPyStatic_globals);
        goto CPyL29;
    }
    if (!cpy_r_r14) goto CPyL11;
    cpy_r_r15 = CPyStatics[5]; /* 'scores.json' */
    cpy_r_r16 = CPyStatics[7]; /* 'r' */
    cpy_r_r17 = CPyModule_builtins;
    cpy_r_r18 = CPyStatics[8]; /* 'open' */
    cpy_r_r19 = CPyObject_GetAttr(cpy_r_r17, cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 39, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r20[2] = {cpy_r_r15, cpy_r_r16};
    cpy_r_r21 = (PyObject **)&cpy_r_r20;
    cpy_r_r22 = _PyObject_Vectorcall(cpy_r_r19, cpy_r_r21, 2, 0);
    CPy_DECREF(cpy_r_r19);
    if (unlikely(cpy_r_r22 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 39, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyStatics[9]; /* 'load' */
    cpy_r_r25 = CPyDict_GetItem(cpy_r_r23, cpy_r_r24);
    if (unlikely(cpy_r_r25 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 39, CPyStatic_globals);
        goto CPyL30;
    }
    PyObject *cpy_r_r26[1] = {cpy_r_r22};
    cpy_r_r27 = (PyObject **)&cpy_r_r26;
    cpy_r_r28 = _PyObject_Vectorcall(cpy_r_r25, cpy_r_r27, 1, 0);
    CPy_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 39, CPyStatic_globals);
        goto CPyL30;
    }
    CPy_DECREF(cpy_r_r22);
    cpy_r_r29 = cpy_r_r28;
    goto CPyL15;
CPyL11: ;
    cpy_r_r30 = (PyObject *)&PyLong_Type;
    cpy_r_r31 = CPyStatic_globals;
    cpy_r_r32 = CPyStatics[10]; /* 'defaultdict' */
    cpy_r_r33 = CPyDict_GetItem(cpy_r_r31, cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 41, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r34[1] = {cpy_r_r30};
    cpy_r_r35 = (PyObject **)&cpy_r_r34;
    cpy_r_r36 = _PyObject_Vectorcall(cpy_r_r33, cpy_r_r35, 1, 0);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 41, CPyStatic_globals);
        goto CPyL29;
    }
    if (likely(PyDict_Check(cpy_r_r36)))
        cpy_r_r37 = cpy_r_r36;
    else {
        CPy_TypeErrorTraceback("main.py", "__init__", 41, CPyStatic_globals, "dict", cpy_r_r36);
        goto CPyL29;
    }
    cpy_r_r29 = cpy_r_r37;
CPyL15: ;
    ((main___GameObject *)cpy_r_self)->_scores = cpy_r_r29;
    CPy_INCREF(cpy_r_master);
    ((main___GameObject *)cpy_r_self)->_master = cpy_r_master;
    ((main___GameObject *)cpy_r_self)->_word_length = 6;
    ((main___GameObject *)cpy_r_self)->_time_limit = 10;
    ((main___GameObject *)cpy_r_self)->_score = 0;
    cpy_r_r38 = CPyStatic_globals;
    cpy_r_r39 = CPyStatics[11]; /* 'time' */
    cpy_r_r40 = CPyDict_GetItem(cpy_r_r38, cpy_r_r39);
    if (unlikely(cpy_r_r40 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 48, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r41 = _PyObject_Vectorcall(cpy_r_r40, 0, 0, 0);
    CPy_DECREF(cpy_r_r40);
    if (unlikely(cpy_r_r41 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 48, CPyStatic_globals);
        goto CPyL29;
    }
    cpy_r_r42 = PyFloat_AsDouble(cpy_r_r41);
    if (cpy_r_r42 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r41); cpy_r_r42 = -113.0;
    }
    CPy_DECREF(cpy_r_r41);
    cpy_r_r43 = cpy_r_r42 == -113.0;
    if (unlikely(cpy_r_r43)) goto CPyL19;
CPyL18: ;
    ((main___GameObject *)cpy_r_self)->_start_time = cpy_r_r42;
    cpy_r_r44 = PySet_New(NULL);
    if (unlikely(cpy_r_r44 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 49, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL20;
CPyL19: ;
    cpy_r_r45 = PyErr_Occurred();
    if (unlikely(cpy_r_r45 != NULL)) {
        CPy_AddTraceback("main.py", "__init__", 48, CPyStatic_globals);
        goto CPyL29;
    } else
        goto CPyL18;
CPyL20: ;
    ((main___GameObject *)cpy_r_self)->_used_words = cpy_r_r44;
    cpy_r_r46 = CPyStatic_globals;
    cpy_r_r47 = CPyStatics[12]; /* 'Entry' */
    cpy_r_r48 = CPyDict_GetItem(cpy_r_r46, cpy_r_r47);
    if (unlikely(cpy_r_r48 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 50, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r49[1] = {cpy_r_master};
    cpy_r_r50 = (PyObject **)&cpy_r_r49;
    cpy_r_r51 = _PyObject_Vectorcall(cpy_r_r48, cpy_r_r50, 1, 0);
    CPy_DECREF(cpy_r_r48);
    if (unlikely(cpy_r_r51 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 50, CPyStatic_globals);
        goto CPyL29;
    }
    ((main___GameObject *)cpy_r_self)->_entry = cpy_r_r51;
    cpy_r_r52 = ((main___GameObject *)cpy_r_self)->_entry;
    CPy_INCREF(cpy_r_r52);
    cpy_r_r53 = CPyStatics[13]; /* 'pack' */
    PyObject *cpy_r_r54[1] = {cpy_r_r52};
    cpy_r_r55 = (PyObject **)&cpy_r_r54;
    cpy_r_r56 = PyObject_VectorcallMethod(cpy_r_r53, cpy_r_r55, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r56 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 51, CPyStatic_globals);
        goto CPyL31;
    } else
        goto CPyL32;
CPyL23: ;
    CPy_DECREF(cpy_r_r52);
    cpy_r_r57 = CPyStatics[14]; /* '' */
    cpy_r_r58 = CPyStatic_globals;
    cpy_r_r59 = CPyStatics[15]; /* 'Label' */
    cpy_r_r60 = CPyDict_GetItem(cpy_r_r58, cpy_r_r59);
    if (unlikely(cpy_r_r60 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 53, CPyStatic_globals);
        goto CPyL29;
    }
    PyObject *cpy_r_r61[2] = {cpy_r_master, cpy_r_r57};
    cpy_r_r62 = (PyObject **)&cpy_r_r61;
    cpy_r_r63 = CPyStatics[73]; /* ('text',) */
    cpy_r_r64 = _PyObject_Vectorcall(cpy_r_r60, cpy_r_r62, 1, cpy_r_r63);
    CPy_DECREF(cpy_r_r60);
    if (unlikely(cpy_r_r64 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 53, CPyStatic_globals);
        goto CPyL29;
    }
    ((main___GameObject *)cpy_r_self)->_label = cpy_r_r64;
    cpy_r_r65 = ((main___GameObject *)cpy_r_self)->_label;
    CPy_INCREF(cpy_r_r65);
    cpy_r_r66 = CPyStatics[13]; /* 'pack' */
    PyObject *cpy_r_r67[1] = {cpy_r_r65};
    cpy_r_r68 = (PyObject **)&cpy_r_r67;
    cpy_r_r69 = PyObject_VectorcallMethod(cpy_r_r66, cpy_r_r68, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 54, CPyStatic_globals);
        goto CPyL33;
    } else
        goto CPyL34;
CPyL26: ;
    CPy_DECREF(cpy_r_r65);
    cpy_r_r70 = ((main___GameObject *)cpy_r_self)->_master;
    CPy_INCREF(cpy_r_r70);
    cpy_r_r71 = CPyStatics[17]; /* 'update' */
    cpy_r_r72 = CPyObject_GetAttr(cpy_r_self, cpy_r_r71);
    if (unlikely(cpy_r_r72 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 56, CPyStatic_globals);
        goto CPyL35;
    }
    cpy_r_r73 = CPyStatics[18]; /* 'after' */
    cpy_r_r74 = CPyStatics[71]; /* 1000 */
    PyObject *cpy_r_r75[3] = {cpy_r_r70, cpy_r_r74, cpy_r_r72};
    cpy_r_r76 = (PyObject **)&cpy_r_r75;
    cpy_r_r77 = PyObject_VectorcallMethod(cpy_r_r73, cpy_r_r76, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r77 == NULL)) {
        CPy_AddTraceback("main.py", "__init__", 56, CPyStatic_globals);
        goto CPyL36;
    } else
        goto CPyL37;
CPyL28: ;
    CPy_DECREF(cpy_r_r70);
    CPy_DECREF(cpy_r_r72);
    return 1;
CPyL29: ;
    cpy_r_r78 = 2;
    return cpy_r_r78;
CPyL30: ;
    CPy_DecRef(cpy_r_r22);
    goto CPyL29;
CPyL31: ;
    CPy_DecRef(cpy_r_r52);
    goto CPyL29;
CPyL32: ;
    CPy_DECREF(cpy_r_r56);
    goto CPyL23;
CPyL33: ;
    CPy_DecRef(cpy_r_r65);
    goto CPyL29;
CPyL34: ;
    CPy_DECREF(cpy_r_r69);
    goto CPyL26;
CPyL35: ;
    CPy_DecRef(cpy_r_r70);
    goto CPyL29;
CPyL36: ;
    CPy_DecRef(cpy_r_r70);
    CPy_DecRef(cpy_r_r72);
    goto CPyL29;
CPyL37: ;
    CPy_DECREF(cpy_r_r77);
    goto CPyL28;
}

PyObject *CPyPy_Game_____init__(PyObject *self, PyObject *args, PyObject *kw) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"master", 0};
    PyObject *obj_master;
    if (!CPyArg_ParseTupleAndKeywords(args, kw, "O", "__init__", kwlist, &obj_master)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    PyObject *arg_master = obj_master;
    char retval = CPyDef_Game_____init__(arg_self, arg_master);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "__init__", 30, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game___update(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    char cpy_r_r1;
    char cpy_r_r2;
    char cpy_r_r3;
    char cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    char cpy_r_r13;
    cpy_r_r0 = ((main___GameObject *)cpy_r_self)->_word_length;
    cpy_r_r1 = cpy_r_r0 != 146;
    if (!cpy_r_r1) goto CPyL6;
    cpy_r_r2 = CPyDef_Game___is_time_up(cpy_r_self);
    if (unlikely(cpy_r_r2 == 2)) {
        CPy_AddTraceback("main.py", "update", 66, CPyStatic_globals);
        goto CPyL9;
    }
    if (!cpy_r_r2) goto CPyL5;
    cpy_r_r3 = CPyDef_Game___end_game(cpy_r_self);
    if (unlikely(cpy_r_r3 == 2)) {
        CPy_AddTraceback("main.py", "update", 67, CPyStatic_globals);
        goto CPyL9;
    }
    return 1;
CPyL5: ;
    cpy_r_r4 = CPyDef_Game___check_and_update_word(cpy_r_self);
    if (unlikely(cpy_r_r4 == 2)) {
        CPy_AddTraceback("main.py", "update", 69, CPyStatic_globals);
        goto CPyL9;
    }
CPyL6: ;
    cpy_r_r5 = ((main___GameObject *)cpy_r_self)->_master;
    CPy_INCREF(cpy_r_r5);
    cpy_r_r6 = CPyStatics[17]; /* 'update' */
    cpy_r_r7 = CPyObject_GetAttr(cpy_r_self, cpy_r_r6);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("main.py", "update", 70, CPyStatic_globals);
        goto CPyL10;
    }
    cpy_r_r8 = CPyStatics[18]; /* 'after' */
    cpy_r_r9 = CPyStatics[71]; /* 1000 */
    PyObject *cpy_r_r10[3] = {cpy_r_r5, cpy_r_r9, cpy_r_r7};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r8, cpy_r_r11, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main.py", "update", 70, CPyStatic_globals);
        goto CPyL11;
    } else
        goto CPyL12;
CPyL8: ;
    CPy_DECREF(cpy_r_r5);
    CPy_DECREF(cpy_r_r7);
    return 1;
CPyL9: ;
    cpy_r_r13 = 2;
    return cpy_r_r13;
CPyL10: ;
    CPy_DecRef(cpy_r_r5);
    goto CPyL9;
CPyL11: ;
    CPy_DecRef(cpy_r_r5);
    CPy_DecRef(cpy_r_r7);
    goto CPyL9;
CPyL12: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL8;
}

PyObject *CPyPy_Game___update(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":update", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Game___update(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "update", 58, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game___is_time_up(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    double cpy_r_r4;
    char cpy_r_r5;
    double cpy_r_r6;
    double cpy_r_r7;
    CPyTagged cpy_r_r8;
    double cpy_r_r9;
    char cpy_r_r10;
    PyObject *cpy_r_r11;
    char cpy_r_r12;
    PyObject *cpy_r_r13;
    char cpy_r_r14;
    cpy_r_r0 = CPyStatic_globals;
    cpy_r_r1 = CPyStatics[11]; /* 'time' */
    cpy_r_r2 = CPyDict_GetItem(cpy_r_r0, cpy_r_r1);
    if (unlikely(cpy_r_r2 == NULL)) {
        CPy_AddTraceback("main.py", "is_time_up", 79, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r3 = _PyObject_Vectorcall(cpy_r_r2, 0, 0, 0);
    CPy_DECREF(cpy_r_r2);
    if (unlikely(cpy_r_r3 == NULL)) {
        CPy_AddTraceback("main.py", "is_time_up", 79, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r4 = PyFloat_AsDouble(cpy_r_r3);
    if (cpy_r_r4 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r3); cpy_r_r4 = -113.0;
    }
    CPy_DECREF(cpy_r_r3);
    cpy_r_r5 = cpy_r_r4 == -113.0;
    if (unlikely(cpy_r_r5)) goto CPyL4;
CPyL3: ;
    cpy_r_r6 = ((main___GameObject *)cpy_r_self)->_start_time;
    cpy_r_r7 = cpy_r_r4 - cpy_r_r6;
    cpy_r_r8 = ((main___GameObject *)cpy_r_self)->_time_limit;
    CPyTagged_INCREF(cpy_r_r8);
    cpy_r_r9 = CPyFloat_FromTagged(cpy_r_r8);
    CPyTagged_DECREF(cpy_r_r8);
    cpy_r_r10 = cpy_r_r9 == -113.0;
    if (unlikely(cpy_r_r10)) {
        goto CPyL6;
    } else
        goto CPyL5;
CPyL4: ;
    cpy_r_r11 = PyErr_Occurred();
    if (unlikely(cpy_r_r11 != NULL)) {
        CPy_AddTraceback("main.py", "is_time_up", 79, CPyStatic_globals);
        goto CPyL7;
    } else
        goto CPyL3;
CPyL5: ;
    cpy_r_r12 = cpy_r_r7 > cpy_r_r9;
    return cpy_r_r12;
CPyL6: ;
    cpy_r_r13 = PyErr_Occurred();
    if (unlikely(cpy_r_r13 != NULL)) {
        CPy_AddTraceback("main.py", "is_time_up", 79, CPyStatic_globals);
    } else
        goto CPyL5;
CPyL7: ;
    cpy_r_r14 = 2;
    return cpy_r_r14;
}

PyObject *CPyPy_Game___is_time_up(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":is_time_up", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Game___is_time_up(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = retval ? Py_True : Py_False;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "is_time_up", 72, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game___end_game(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject **cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject **cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_player_name;
    CPyTagged cpy_r_r16;
    char cpy_r_r17;
    char cpy_r_r18;
    char cpy_r_r19;
    cpy_r_r0 = ((main___GameObject *)cpy_r_self)->_label;
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyStatics[19]; /* "Time's up. Game Over." */
    cpy_r_r2 = CPyStatics[20]; /* 'config' */
    PyObject *cpy_r_r3[2] = {cpy_r_r0, cpy_r_r1};
    cpy_r_r4 = (PyObject **)&cpy_r_r3;
    cpy_r_r5 = CPyStatics[73]; /* ('text',) */
    cpy_r_r6 = PyObject_VectorcallMethod(cpy_r_r2, cpy_r_r4, 9223372036854775809ULL, cpy_r_r5);
    if (unlikely(cpy_r_r6 == NULL)) {
        CPy_AddTraceback("main.py", "end_game", 88, CPyStatic_globals);
        goto CPyL8;
    } else
        goto CPyL9;
CPyL1: ;
    CPy_DECREF(cpy_r_r0);
    cpy_r_r7 = CPyStatics[21]; /* 'Input' */
    cpy_r_r8 = CPyStatics[22]; /* 'Enter your name:' */
    cpy_r_r9 = CPyStatic_globals;
    cpy_r_r10 = CPyStatics[23]; /* 'askstring' */
    cpy_r_r11 = CPyDict_GetItem(cpy_r_r9, cpy_r_r10);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("main.py", "end_game", 89, CPyStatic_globals);
        goto CPyL7;
    }
    PyObject *cpy_r_r12[2] = {cpy_r_r7, cpy_r_r8};
    cpy_r_r13 = (PyObject **)&cpy_r_r12;
    cpy_r_r14 = _PyObject_Vectorcall(cpy_r_r11, cpy_r_r13, 2, 0);
    CPy_DECREF(cpy_r_r11);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("main.py", "end_game", 89, CPyStatic_globals);
        goto CPyL7;
    }
    if (PyUnicode_Check(cpy_r_r14))
        cpy_r_r15 = cpy_r_r14;
    else {
        cpy_r_r15 = NULL;
    }
    if (cpy_r_r15 != NULL) goto __LL1;
    if (cpy_r_r14 == Py_None)
        cpy_r_r15 = cpy_r_r14;
    else {
        cpy_r_r15 = NULL;
    }
    if (cpy_r_r15 != NULL) goto __LL1;
    CPy_TypeErrorTraceback("main.py", "end_game", 89, CPyStatic_globals, "str or None", cpy_r_r14);
    goto CPyL7;
__LL1: ;
    cpy_r_player_name = cpy_r_r15;
    cpy_r_r16 = ((main___GameObject *)cpy_r_self)->_score;
    CPyTagged_INCREF(cpy_r_r16);
    cpy_r_r17 = CPyDef_Game___save_score(cpy_r_self, cpy_r_player_name, cpy_r_r16);
    CPy_DECREF(cpy_r_player_name);
    CPyTagged_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r17 == 2)) {
        CPy_AddTraceback("main.py", "end_game", 90, CPyStatic_globals);
        goto CPyL7;
    }
    cpy_r_r18 = CPyDef_Game___show_leaderboard(cpy_r_self);
    if (unlikely(cpy_r_r18 == 2)) {
        CPy_AddTraceback("main.py", "end_game", 91, CPyStatic_globals);
        goto CPyL7;
    }
    return 1;
CPyL7: ;
    cpy_r_r19 = 2;
    return cpy_r_r19;
CPyL8: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL7;
CPyL9: ;
    CPy_DECREF(cpy_r_r6);
    goto CPyL1;
}

PyObject *CPyPy_Game___end_game(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":end_game", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Game___end_game(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "end_game", 81, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game___check_and_update_word(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject **cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_word;
    int64_t cpy_r_r6;
    char cpy_r_r7;
    CPyTagged cpy_r_r8;
    CPyTagged cpy_r_r9;
    int64_t cpy_r_r10;
    char cpy_r_r11;
    int64_t cpy_r_r12;
    char cpy_r_r13;
    char cpy_r_r14;
    char cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject **cpy_r_r19;
    PyObject *cpy_r_r20;
    int32_t cpy_r_r21;
    char cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_r24;
    int32_t cpy_r_r25;
    char cpy_r_r26;
    char cpy_r_r27;
    char cpy_r_r28;
    char cpy_r_r29;
    char cpy_r_r30;
    cpy_r_r0 = ((main___GameObject *)cpy_r_self)->_entry;
    CPy_INCREF(cpy_r_r0);
    cpy_r_r1 = CPyStatics[24]; /* 'get' */
    PyObject *cpy_r_r2[1] = {cpy_r_r0};
    cpy_r_r3 = (PyObject **)&cpy_r_r2;
    cpy_r_r4 = PyObject_VectorcallMethod(cpy_r_r1, cpy_r_r3, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "check_and_update_word", 100, CPyStatic_globals);
        goto CPyL15;
    }
    CPy_DECREF(cpy_r_r0);
    if (likely(PyUnicode_Check(cpy_r_r4)))
        cpy_r_r5 = cpy_r_r4;
    else {
        CPy_TypeErrorTraceback("main.py", "check_and_update_word", 100, CPyStatic_globals, "str", cpy_r_r4);
        goto CPyL14;
    }
    cpy_r_word = cpy_r_r5;
    cpy_r_r6 = CPyStr_Size_size_t(cpy_r_word);
    cpy_r_r7 = cpy_r_r6 >= 0;
    if (unlikely(!cpy_r_r7)) {
        CPy_AddTraceback("main.py", "check_and_update_word", 102, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r8 = cpy_r_r6 << 1;
    cpy_r_r9 = ((main___GameObject *)cpy_r_self)->_word_length;
    cpy_r_r10 = cpy_r_r8 & 1;
    cpy_r_r11 = cpy_r_r10 != 0;
    if (cpy_r_r11) goto CPyL5;
    cpy_r_r12 = cpy_r_r9 & 1;
    cpy_r_r13 = cpy_r_r12 != 0;
    if (!cpy_r_r13) goto CPyL6;
CPyL5: ;
    cpy_r_r14 = CPyTagged_IsLt_(cpy_r_r8, cpy_r_r9);
    if (cpy_r_r14) {
        goto CPyL17;
    } else
        goto CPyL7;
CPyL6: ;
    cpy_r_r15 = (Py_ssize_t)cpy_r_r8 >= (Py_ssize_t)cpy_r_r9;
    if (!cpy_r_r15) goto CPyL17;
CPyL7: ;
    cpy_r_r16 = ((main___GameObject *)cpy_r_self)->_dictionary;
    CPy_INCREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[25]; /* 'check' */
    PyObject *cpy_r_r18[2] = {cpy_r_r16, cpy_r_word};
    cpy_r_r19 = (PyObject **)&cpy_r_r18;
    cpy_r_r20 = PyObject_VectorcallMethod(cpy_r_r17, cpy_r_r19, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("main.py", "check_and_update_word", 103, CPyStatic_globals);
        goto CPyL18;
    }
    CPy_DECREF(cpy_r_r16);
    cpy_r_r21 = PyObject_IsTrue(cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r22 = cpy_r_r21 >= 0;
    if (unlikely(!cpy_r_r22)) {
        CPy_AddTraceback("main.py", "check_and_update_word", 103, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r23 = cpy_r_r21;
    if (!cpy_r_r23) goto CPyL17;
    cpy_r_r24 = ((main___GameObject *)cpy_r_self)->_used_words;
    CPy_INCREF(cpy_r_r24);
    cpy_r_r25 = PySet_Contains(cpy_r_r24, cpy_r_word);
    CPy_DECREF(cpy_r_r24);
    CPy_DECREF(cpy_r_word);
    cpy_r_r26 = cpy_r_r25 >= 0;
    if (unlikely(!cpy_r_r26)) {
        CPy_AddTraceback("main.py", "check_and_update_word", 104, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r27 = cpy_r_r25;
    cpy_r_r28 = cpy_r_r27 ^ 1;
    if (!cpy_r_r28) goto CPyL13;
    cpy_r_r29 = CPyDef_Game___level_up(cpy_r_self);
    if (unlikely(cpy_r_r29 == 2)) {
        CPy_AddTraceback("main.py", "check_and_update_word", 106, CPyStatic_globals);
        goto CPyL14;
    }
CPyL13: ;
    return 1;
CPyL14: ;
    cpy_r_r30 = 2;
    return cpy_r_r30;
CPyL15: ;
    CPy_DecRef(cpy_r_r0);
    goto CPyL14;
CPyL16: ;
    CPy_DecRef(cpy_r_word);
    goto CPyL14;
CPyL17: ;
    CPy_DECREF(cpy_r_word);
    goto CPyL13;
CPyL18: ;
    CPy_DecRef(cpy_r_word);
    CPy_DecRef(cpy_r_r16);
    goto CPyL14;
}

PyObject *CPyPy_Game___check_and_update_word(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":check_and_update_word", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Game___check_and_update_word(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "check_and_update_word", 93, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game___level_up(PyObject *cpy_r_self) {
    CPyTagged cpy_r_r0;
    CPyTagged cpy_r_r1;
    char cpy_r_r2;
    CPyTagged cpy_r_r3;
    CPyTagged cpy_r_r4;
    char cpy_r_r5;
    CPyTagged cpy_r_r6;
    CPyTagged cpy_r_r7;
    char cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject **cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    double cpy_r_r20;
    char cpy_r_r21;
    char cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    CPyTagged cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    CPyTagged cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    CPyTagged cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject **cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    char cpy_r_r40;
    cpy_r_r0 = ((main___GameObject *)cpy_r_self)->_score;
    cpy_r_r1 = CPyTagged_Add(cpy_r_r0, 20);
    CPyTagged_DECREF(((main___GameObject *)cpy_r_self)->_score);
    ((main___GameObject *)cpy_r_self)->_score = cpy_r_r1;
    cpy_r_r3 = ((main___GameObject *)cpy_r_self)->_word_length;
    cpy_r_r4 = CPyTagged_Add(cpy_r_r3, 2);
    CPyTagged_DECREF(((main___GameObject *)cpy_r_self)->_word_length);
    ((main___GameObject *)cpy_r_self)->_word_length = cpy_r_r4;
    cpy_r_r6 = ((main___GameObject *)cpy_r_self)->_time_limit;
    cpy_r_r7 = CPyTagged_Add(cpy_r_r6, 4);
    CPyTagged_DECREF(((main___GameObject *)cpy_r_self)->_time_limit);
    ((main___GameObject *)cpy_r_self)->_time_limit = cpy_r_r7;
    cpy_r_r9 = ((main___GameObject *)cpy_r_self)->_entry;
    CPy_INCREF(cpy_r_r9);
    cpy_r_r10 = CPyStatics[26]; /* 'end' */
    cpy_r_r11 = CPyStatics[27]; /* 'delete' */
    cpy_r_r12 = CPyStatics[72]; /* 0 */
    PyObject *cpy_r_r13[3] = {cpy_r_r9, cpy_r_r12, cpy_r_r10};
    cpy_r_r14 = (PyObject **)&cpy_r_r13;
    cpy_r_r15 = PyObject_VectorcallMethod(cpy_r_r11, cpy_r_r14, 9223372036854775811ULL, 0);
    if (unlikely(cpy_r_r15 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 118, CPyStatic_globals);
        goto CPyL12;
    } else
        goto CPyL13;
CPyL1: ;
    CPy_DECREF(cpy_r_r9);
    cpy_r_r16 = CPyStatic_globals;
    cpy_r_r17 = CPyStatics[11]; /* 'time' */
    cpy_r_r18 = CPyDict_GetItem(cpy_r_r16, cpy_r_r17);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 119, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r19 = _PyObject_Vectorcall(cpy_r_r18, 0, 0, 0);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 119, CPyStatic_globals);
        goto CPyL11;
    }
    cpy_r_r20 = PyFloat_AsDouble(cpy_r_r19);
    if (cpy_r_r20 == -1.0 && PyErr_Occurred()) {
        CPy_TypeError("float", cpy_r_r19); cpy_r_r20 = -113.0;
    }
    CPy_DECREF(cpy_r_r19);
    cpy_r_r21 = cpy_r_r20 == -113.0;
    if (unlikely(cpy_r_r21)) goto CPyL5;
CPyL4: ;
    ((main___GameObject *)cpy_r_self)->_start_time = cpy_r_r20;
    cpy_r_r23 = ((main___GameObject *)cpy_r_self)->_label;
    CPy_INCREF(cpy_r_r23);
    cpy_r_r24 = CPyStatics[28]; /* 'Enter a word of length ' */
    cpy_r_r25 = ((main___GameObject *)cpy_r_self)->_word_length;
    CPyTagged_INCREF(cpy_r_r25);
    cpy_r_r26 = CPyTagged_Str(cpy_r_r25);
    CPyTagged_DECREF(cpy_r_r25);
    if (unlikely(cpy_r_r26 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 121, CPyStatic_globals);
        goto CPyL14;
    } else
        goto CPyL6;
CPyL5: ;
    cpy_r_r27 = PyErr_Occurred();
    if (unlikely(cpy_r_r27 != NULL)) {
        CPy_AddTraceback("main.py", "level_up", 119, CPyStatic_globals);
        goto CPyL11;
    } else
        goto CPyL4;
CPyL6: ;
    cpy_r_r28 = CPyStatics[29]; /* ' in ' */
    cpy_r_r29 = ((main___GameObject *)cpy_r_self)->_time_limit;
    CPyTagged_INCREF(cpy_r_r29);
    cpy_r_r30 = CPyTagged_Str(cpy_r_r29);
    CPyTagged_DECREF(cpy_r_r29);
    if (unlikely(cpy_r_r30 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 121, CPyStatic_globals);
        goto CPyL15;
    }
    cpy_r_r31 = CPyStatics[30]; /* ' seconds. Score: ' */
    cpy_r_r32 = ((main___GameObject *)cpy_r_self)->_score;
    CPyTagged_INCREF(cpy_r_r32);
    cpy_r_r33 = CPyTagged_Str(cpy_r_r32);
    CPyTagged_DECREF(cpy_r_r32);
    if (unlikely(cpy_r_r33 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 121, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r34 = CPyStr_Build(6, cpy_r_r24, cpy_r_r26, cpy_r_r28, cpy_r_r30, cpy_r_r31, cpy_r_r33);
    CPy_DECREF(cpy_r_r26);
    CPy_DECREF(cpy_r_r30);
    CPy_DECREF(cpy_r_r33);
    if (unlikely(cpy_r_r34 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 121, CPyStatic_globals);
        goto CPyL14;
    }
    cpy_r_r35 = CPyStatics[20]; /* 'config' */
    PyObject *cpy_r_r36[2] = {cpy_r_r23, cpy_r_r34};
    cpy_r_r37 = (PyObject **)&cpy_r_r36;
    cpy_r_r38 = CPyStatics[73]; /* ('text',) */
    cpy_r_r39 = PyObject_VectorcallMethod(cpy_r_r35, cpy_r_r37, 9223372036854775809ULL, cpy_r_r38);
    if (unlikely(cpy_r_r39 == NULL)) {
        CPy_AddTraceback("main.py", "level_up", 120, CPyStatic_globals);
        goto CPyL17;
    } else
        goto CPyL18;
CPyL10: ;
    CPy_DECREF(cpy_r_r23);
    CPy_DECREF(cpy_r_r34);
    return 1;
CPyL11: ;
    cpy_r_r40 = 2;
    return cpy_r_r40;
CPyL12: ;
    CPy_DecRef(cpy_r_r9);
    goto CPyL11;
CPyL13: ;
    CPy_DECREF(cpy_r_r15);
    goto CPyL1;
CPyL14: ;
    CPy_DecRef(cpy_r_r23);
    goto CPyL11;
CPyL15: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r26);
    goto CPyL11;
CPyL16: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r26);
    CPy_DecRef(cpy_r_r30);
    goto CPyL11;
CPyL17: ;
    CPy_DecRef(cpy_r_r23);
    CPy_DecRef(cpy_r_r34);
    goto CPyL11;
CPyL18: ;
    CPy_DECREF(cpy_r_r39);
    goto CPyL10;
}

PyObject *CPyPy_Game___level_up(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":level_up", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Game___level_up(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "level_up", 108, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game___save_score(PyObject *cpy_r_self, PyObject *cpy_r_name, CPyTagged cpy_r_score) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    int32_t cpy_r_r2;
    char cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject **cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject **cpy_r_r18;
    PyObject *cpy_r_r19;
    char cpy_r_r20;
    PyObject *cpy_r_f;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject **cpy_r_r26;
    PyObject *cpy_r_r27;
    tuple_T3OOO cpy_r_r28;
    tuple_T3OOO cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject **cpy_r_r34;
    PyObject *cpy_r_r35;
    int32_t cpy_r_r36;
    char cpy_r_r37;
    char cpy_r_r38;
    char cpy_r_r39;
    tuple_T3OOO cpy_r_r40;
    tuple_T3OOO cpy_r_r41;
    tuple_T3OOO cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    char cpy_r_r47;
    char cpy_r_r48;
    cpy_r_r0 = ((main___GameObject *)cpy_r_self)->_scores;
    CPy_INCREF(cpy_r_r0);
    CPyTagged_INCREF(cpy_r_score);
    cpy_r_r1 = CPyTagged_StealAsObject(cpy_r_score);
    cpy_r_r2 = PyObject_SetItem(cpy_r_r0, cpy_r_name, cpy_r_r1);
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_r1);
    cpy_r_r3 = cpy_r_r2 >= 0;
    if (unlikely(!cpy_r_r3)) {
        CPy_AddTraceback("main.py", "save_score", 135, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r4 = CPyStatics[5]; /* 'scores.json' */
    cpy_r_r5 = CPyStatics[31]; /* 'w' */
    cpy_r_r6 = CPyModule_builtins;
    cpy_r_r7 = CPyStatics[8]; /* 'open' */
    cpy_r_r8 = CPyObject_GetAttr(cpy_r_r6, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL31;
    }
    PyObject *cpy_r_r9[2] = {cpy_r_r4, cpy_r_r5};
    cpy_r_r10 = (PyObject **)&cpy_r_r9;
    cpy_r_r11 = _PyObject_Vectorcall(cpy_r_r8, cpy_r_r10, 2, 0);
    CPy_DECREF(cpy_r_r8);
    if (unlikely(cpy_r_r11 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL31;
    }
    cpy_r_r12 = PyObject_Type(cpy_r_r11);
    cpy_r_r13 = CPyStatics[32]; /* '__exit__' */
    cpy_r_r14 = CPyObject_GetAttr(cpy_r_r12, cpy_r_r13);
    if (unlikely(cpy_r_r14 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL32;
    }
    cpy_r_r15 = CPyStatics[33]; /* '__enter__' */
    cpy_r_r16 = CPyObject_GetAttr(cpy_r_r12, cpy_r_r15);
    CPy_DECREF(cpy_r_r12);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL33;
    }
    PyObject *cpy_r_r17[1] = {cpy_r_r11};
    cpy_r_r18 = (PyObject **)&cpy_r_r17;
    cpy_r_r19 = _PyObject_Vectorcall(cpy_r_r16, cpy_r_r18, 1, 0);
    CPy_DECREF(cpy_r_r16);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL33;
    }
    cpy_r_r20 = 1;
    cpy_r_f = cpy_r_r19;
    cpy_r_r21 = ((main___GameObject *)cpy_r_self)->_scores;
    CPy_INCREF(cpy_r_r21);
    cpy_r_r22 = CPyStatic_globals;
    cpy_r_r23 = CPyStatics[34]; /* 'dump' */
    cpy_r_r24 = CPyDict_GetItem(cpy_r_r22, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 137, CPyStatic_globals);
        goto CPyL34;
    }
    PyObject *cpy_r_r25[2] = {cpy_r_r21, cpy_r_f};
    cpy_r_r26 = (PyObject **)&cpy_r_r25;
    cpy_r_r27 = _PyObject_Vectorcall(cpy_r_r24, cpy_r_r26, 2, 0);
    CPy_DECREF(cpy_r_r24);
    if (unlikely(cpy_r_r27 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 137, CPyStatic_globals);
        goto CPyL34;
    } else
        goto CPyL35;
CPyL9: ;
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_f);
    goto CPyL18;
CPyL10: ;
    cpy_r_r28 = CPy_CatchError();
    cpy_r_r20 = 0;
    cpy_r_r29 = CPy_GetExcInfo();
    cpy_r_r30 = cpy_r_r29.f0;
    CPy_INCREF(cpy_r_r30);
    cpy_r_r31 = cpy_r_r29.f1;
    CPy_INCREF(cpy_r_r31);
    cpy_r_r32 = cpy_r_r29.f2;
    CPy_INCREF(cpy_r_r32);
    CPy_DecRef(cpy_r_r29.f0);
    CPy_DecRef(cpy_r_r29.f1);
    CPy_DecRef(cpy_r_r29.f2);
    PyObject *cpy_r_r33[4] = {cpy_r_r11, cpy_r_r30, cpy_r_r31, cpy_r_r32};
    cpy_r_r34 = (PyObject **)&cpy_r_r33;
    cpy_r_r35 = _PyObject_Vectorcall(cpy_r_r14, cpy_r_r34, 4, 0);
    if (unlikely(cpy_r_r35 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL36;
    }
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    cpy_r_r36 = PyObject_IsTrue(cpy_r_r35);
    CPy_DecRef(cpy_r_r35);
    cpy_r_r37 = cpy_r_r36 >= 0;
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL16;
    }
    cpy_r_r38 = cpy_r_r36;
    if (cpy_r_r38) goto CPyL15;
    CPy_Reraise();
    if (!0) {
        goto CPyL16;
    } else
        goto CPyL37;
CPyL14: ;
    CPy_Unreachable();
CPyL15: ;
    CPy_RestoreExcInfo(cpy_r_r28);
    CPy_DecRef(cpy_r_r28.f0);
    CPy_DecRef(cpy_r_r28.f1);
    CPy_DecRef(cpy_r_r28.f2);
    goto CPyL18;
CPyL16: ;
    CPy_RestoreExcInfo(cpy_r_r28);
    CPy_DecRef(cpy_r_r28.f0);
    CPy_DecRef(cpy_r_r28.f1);
    CPy_DecRef(cpy_r_r28.f2);
    cpy_r_r39 = CPy_KeepPropagating();
    if (!cpy_r_r39) {
        goto CPyL19;
    } else
        goto CPyL38;
CPyL17: ;
    CPy_Unreachable();
CPyL18: ;
    tuple_T3OOO __tmp2 = { NULL, NULL, NULL };
    cpy_r_r40 = __tmp2;
    cpy_r_r41 = cpy_r_r40;
    goto CPyL20;
CPyL19: ;
    cpy_r_r42 = CPy_CatchError();
    cpy_r_r41 = cpy_r_r42;
CPyL20: ;
    if (!cpy_r_r20) goto CPyL39;
    cpy_r_r43 = (PyObject *)&_Py_NoneStruct;
    PyObject *cpy_r_r44[4] = {cpy_r_r11, cpy_r_r43, cpy_r_r43, cpy_r_r43};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = _PyObject_Vectorcall(cpy_r_r14, cpy_r_r45, 4, 0);
    CPy_DECREF(cpy_r_r14);
    if (unlikely(cpy_r_r46 == NULL)) {
        CPy_AddTraceback("main.py", "save_score", 136, CPyStatic_globals);
        goto CPyL40;
    } else
        goto CPyL41;
CPyL22: ;
    CPy_DECREF(cpy_r_r11);
CPyL23: ;
    if (cpy_r_r41.f0 == NULL) goto CPyL30;
    CPy_Reraise();
    if (!0) {
        goto CPyL26;
    } else
        goto CPyL42;
CPyL25: ;
    CPy_Unreachable();
CPyL26: ;
    if (cpy_r_r41.f0 == NULL) goto CPyL28;
    CPy_RestoreExcInfo(cpy_r_r41);
    CPy_XDECREF(cpy_r_r41.f0);
    CPy_XDECREF(cpy_r_r41.f1);
    CPy_XDECREF(cpy_r_r41.f2);
CPyL28: ;
    cpy_r_r47 = CPy_KeepPropagating();
    if (!cpy_r_r47) goto CPyL31;
    CPy_Unreachable();
CPyL30: ;
    return 1;
CPyL31: ;
    cpy_r_r48 = 2;
    return cpy_r_r48;
CPyL32: ;
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r12);
    goto CPyL31;
CPyL33: ;
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r14);
    goto CPyL31;
CPyL34: ;
    CPy_DecRef(cpy_r_f);
    CPy_DecRef(cpy_r_r21);
    goto CPyL10;
CPyL35: ;
    CPy_DECREF(cpy_r_r27);
    goto CPyL9;
CPyL36: ;
    CPy_DecRef(cpy_r_r30);
    CPy_DecRef(cpy_r_r31);
    CPy_DecRef(cpy_r_r32);
    goto CPyL16;
CPyL37: ;
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r14);
    CPy_DecRef(cpy_r_r28.f0);
    CPy_DecRef(cpy_r_r28.f1);
    CPy_DecRef(cpy_r_r28.f2);
    goto CPyL14;
CPyL38: ;
    CPy_DecRef(cpy_r_r11);
    CPy_DecRef(cpy_r_r14);
    goto CPyL17;
CPyL39: ;
    CPy_DECREF(cpy_r_r11);
    CPy_DECREF(cpy_r_r14);
    goto CPyL23;
CPyL40: ;
    CPy_DecRef(cpy_r_r11);
    goto CPyL26;
CPyL41: ;
    CPy_DECREF(cpy_r_r46);
    goto CPyL22;
CPyL42: ;
    CPy_XDECREF(cpy_r_r41.f0);
    CPy_XDECREF(cpy_r_r41.f1);
    CPy_XDECREF(cpy_r_r41.f2);
    goto CPyL25;
}

PyObject *CPyPy_Game___save_score(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {"name", "score", 0};
    static CPyArg_Parser parser = {"OO:save_score", kwlist, 0};
    PyObject *obj_name;
    PyObject *obj_score;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_name, &obj_score)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    PyObject *arg_name;
    if (PyUnicode_Check(obj_name))
        arg_name = obj_name;
    else {
        arg_name = NULL;
    }
    if (arg_name != NULL) goto __LL3;
    if (obj_name == Py_None)
        arg_name = obj_name;
    else {
        arg_name = NULL;
    }
    if (arg_name != NULL) goto __LL3;
    CPy_TypeError("str or None", obj_name); 
    goto fail;
__LL3: ;
    CPyTagged arg_score;
    if (likely(PyLong_Check(obj_score)))
        arg_score = CPyTagged_BorrowFromObject(obj_score);
    else {
        CPy_TypeError("int", obj_score); goto fail;
    }
    char retval = CPyDef_Game___save_score(arg_self, arg_name, arg_score);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "save_score", 124, CPyStatic_globals);
    return NULL;
}

PyObject *CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner) {
    PyObject *cpy_r_r0;
    char cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    cpy_r_r0 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r1 = cpy_r_instance == cpy_r_r0;
    if (!cpy_r_r1) goto CPyL2;
    CPy_INCREF(cpy_r___mypyc_self__);
    return cpy_r___mypyc_self__;
CPyL2: ;
    cpy_r_r2 = PyMethod_New(cpy_r___mypyc_self__, cpy_r_instance);
    if (cpy_r_r2 == NULL) goto CPyL4;
    return cpy_r_r2;
CPyL4: ;
    cpy_r_r3 = NULL;
    return cpy_r_r3;
}

PyObject *CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"instance", "owner", 0};
    static CPyArg_Parser parser = {"OO:__get__", kwlist, 0};
    PyObject *obj_instance;
    PyObject *obj_owner;
    if (!CPyArg_ParseStackAndKeywordsSimple(args, nargs, kwnames, &parser, &obj_instance, &obj_owner)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    PyObject *arg_instance = obj_instance;
    PyObject *arg_owner = obj_owner;
    PyObject *retval = CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(arg___mypyc_self__, arg_instance, arg_owner);
    return retval;
fail: ;
    CPy_AddTraceback("main.py", "__get__", -1, CPyStatic_globals);
    return NULL;
}

CPyTagged CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____call__(PyObject *cpy_r___mypyc_self__, tuple_T2OI cpy_r_x) {
    PyObject *cpy_r_r0;
    CPyTagged cpy_r_r1;
    CPyTagged cpy_r_r2;
    cpy_r_r0 = ((main_____mypyc_lambda__0_show_leaderboard_Game_objObject *)cpy_r___mypyc_self__)->___mypyc_env__;
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AttributeError("main.py", "<lambda>", "__mypyc_lambda__0_show_leaderboard_Game_obj", "__mypyc_env__", 150, CPyStatic_globals);
        goto CPyL2;
    }
    CPy_INCREF(cpy_r_r0);
    goto CPyL3;
CPyL1: ;
    cpy_r_r1 = cpy_r_x.f1;
    CPyTagged_INCREF(cpy_r_r1);
    return cpy_r_r1;
CPyL2: ;
    cpy_r_r2 = CPY_INT_TAG;
    return cpy_r_r2;
CPyL3: ;
    CPy_DECREF(cpy_r_r0);
    goto CPyL1;
}

PyObject *CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj___mypyc_self__ = self;
    static const char * const kwlist[] = {"x", 0};
    static CPyArg_Parser parser = {"O:__call__", kwlist, 0};
    PyObject *obj_x;
    if (!CPyArg_ParseStackAndKeywordsOneArg(args, PyVectorcall_NARGS(nargs), kwnames, &parser, &obj_x)) {
        return NULL;
    }
    PyObject *arg___mypyc_self__ = obj___mypyc_self__;
    tuple_T2OI arg_x;
    PyObject *__tmp4;
    if (unlikely(!(PyTuple_Check(obj_x) && PyTuple_GET_SIZE(obj_x) == 2))) {
        __tmp4 = NULL;
        goto __LL5;
    }
    if (PyUnicode_Check(PyTuple_GET_ITEM(obj_x, 0)))
        __tmp4 = PyTuple_GET_ITEM(obj_x, 0);
    else {
        __tmp4 = NULL;
    }
    if (__tmp4 != NULL) goto __LL6;
    if (PyTuple_GET_ITEM(obj_x, 0) == Py_None)
        __tmp4 = PyTuple_GET_ITEM(obj_x, 0);
    else {
        __tmp4 = NULL;
    }
    if (__tmp4 != NULL) goto __LL6;
    __tmp4 = NULL;
__LL6: ;
    if (__tmp4 == NULL) goto __LL5;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(obj_x, 1))))
        __tmp4 = PyTuple_GET_ITEM(obj_x, 1);
    else {
        __tmp4 = NULL;
    }
    if (__tmp4 == NULL) goto __LL5;
    __tmp4 = obj_x;
__LL5: ;
    if (unlikely(__tmp4 == NULL)) {
        CPy_TypeError("tuple[union[str, None], int]", obj_x); goto fail;
    } else {
        PyObject *__tmp7 = PyTuple_GET_ITEM(obj_x, 0);
        PyObject *__tmp8;
        if (PyUnicode_Check(__tmp7))
            __tmp8 = __tmp7;
        else {
            __tmp8 = NULL;
        }
        if (__tmp8 != NULL) goto __LL9;
        if (__tmp7 == Py_None)
            __tmp8 = __tmp7;
        else {
            __tmp8 = NULL;
        }
        if (__tmp8 != NULL) goto __LL9;
        CPy_TypeError("str or None", __tmp7); 
        __tmp8 = NULL;
__LL9: ;
        arg_x.f0 = __tmp8;
        PyObject *__tmp10 = PyTuple_GET_ITEM(obj_x, 1);
        CPyTagged __tmp11;
        if (likely(PyLong_Check(__tmp10)))
            __tmp11 = CPyTagged_BorrowFromObject(__tmp10);
        else {
            CPy_TypeError("int", __tmp10); goto fail;
        }
        arg_x.f1 = __tmp11;
    }
    CPyTagged retval = CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____call__(arg___mypyc_self__, arg_x);
    if (retval == CPY_INT_TAG) {
        return NULL;
    }
    PyObject *retbox = CPyTagged_StealAsObject(retval);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "<lambda>", 150, CPyStatic_globals);
    return NULL;
}

char CPyDef_Game___show_leaderboard(PyObject *cpy_r_self) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    PyObject *cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject **cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_leaderboard_window;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject **cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject **cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    char cpy_r_r23;
    PyObject *cpy_r_name;
    PyObject *cpy_r_r24;
    char cpy_r_r25;
    PyObject *cpy_r_score;
    PyObject *cpy_r_r26;
    char cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    int32_t cpy_r_r30;
    char cpy_r_r31;
    char cpy_r_r32;
    tuple_T2OO cpy_r_r33;
    PyObject *cpy_r_r34;
    int32_t cpy_r_r35;
    char cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    char cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject **cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_sorted_scores;
    CPyTagged cpy_r_r49;
    CPyTagged cpy_r_i;
    CPyTagged cpy_r_r50;
    CPyPtr cpy_r_r51;
    int64_t cpy_r_r52;
    CPyTagged cpy_r_r53;
    char cpy_r_r54;
    PyObject *cpy_r_r55;
    tuple_T2OI cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_name_2;
    CPyTagged cpy_r_r58;
    CPyTagged cpy_r_score_2;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    PyObject *cpy_r_r62;
    PyObject *cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject **cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject *cpy_r_r69;
    PyObject *cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject **cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    CPyTagged cpy_r_r76;
    CPyTagged cpy_r_r77;
    char cpy_r_r78;
    cpy_r_r0 = CPyDef_show_leaderboard_Game_env();
    if (unlikely(cpy_r_r0 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 139, CPyStatic_globals);
        goto CPyL40;
    }
    cpy_r_r1 = ((main___GameObject *)cpy_r_self)->_master;
    CPy_INCREF(cpy_r_r1);
    cpy_r_r2 = CPyStatic_globals;
    cpy_r_r3 = CPyStatics[35]; /* 'Toplevel' */
    cpy_r_r4 = CPyDict_GetItem(cpy_r_r2, cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 146, CPyStatic_globals);
        goto CPyL41;
    }
    PyObject *cpy_r_r5[1] = {cpy_r_r1};
    cpy_r_r6 = (PyObject **)&cpy_r_r5;
    cpy_r_r7 = _PyObject_Vectorcall(cpy_r_r4, cpy_r_r6, 1, 0);
    CPy_DECREF(cpy_r_r4);
    if (unlikely(cpy_r_r7 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 146, CPyStatic_globals);
        goto CPyL41;
    }
    CPy_DECREF(cpy_r_r1);
    cpy_r_leaderboard_window = cpy_r_r7;
    cpy_r_r8 = CPyStatics[36]; /* 'Leaderboard' */
    cpy_r_r9 = CPyStatics[37]; /* 'title' */
    PyObject *cpy_r_r10[2] = {cpy_r_leaderboard_window, cpy_r_r8};
    cpy_r_r11 = (PyObject **)&cpy_r_r10;
    cpy_r_r12 = PyObject_VectorcallMethod(cpy_r_r9, cpy_r_r11, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 147, CPyStatic_globals);
        goto CPyL42;
    } else
        goto CPyL43;
CPyL4: ;
    cpy_r_r13 = PyList_New(0);
    if (unlikely(cpy_r_r13 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL42;
    }
    cpy_r_r14 = ((main___GameObject *)cpy_r_self)->_scores;
    CPy_INCREF(cpy_r_r14);
    cpy_r_r15 = CPyStatics[38]; /* 'items' */
    PyObject *cpy_r_r16[1] = {cpy_r_r14};
    cpy_r_r17 = (PyObject **)&cpy_r_r16;
    cpy_r_r18 = PyObject_VectorcallMethod(cpy_r_r15, cpy_r_r17, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r18 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL44;
    }
    CPy_DECREF(cpy_r_r14);
    cpy_r_r19 = PyObject_GetIter(cpy_r_r18);
    CPy_DECREF(cpy_r_r18);
    if (unlikely(cpy_r_r19 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL45;
    }
CPyL7: ;
    cpy_r_r20 = PyIter_Next(cpy_r_r19);
    if (cpy_r_r20 == NULL) goto CPyL46;
    cpy_r_r21 = PyObject_GetIter(cpy_r_r20);
    CPy_DECREF(cpy_r_r20);
    if (unlikely(cpy_r_r21 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL47;
    }
    cpy_r_r22 = PyIter_Next(cpy_r_r21);
    if (cpy_r_r22 == NULL) {
        goto CPyL48;
    } else
        goto CPyL12;
CPyL10: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r23 = 0;
    if (unlikely(!cpy_r_r23)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL40;
    }
    CPy_Unreachable();
CPyL12: ;
    cpy_r_name = cpy_r_r22;
    cpy_r_r24 = PyIter_Next(cpy_r_r21);
    if (cpy_r_r24 == NULL) {
        goto CPyL49;
    } else
        goto CPyL15;
CPyL13: ;
    PyErr_SetString(PyExc_ValueError, "not enough values to unpack");
    cpy_r_r25 = 0;
    if (unlikely(!cpy_r_r25)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL40;
    }
    CPy_Unreachable();
CPyL15: ;
    cpy_r_score = cpy_r_r24;
    cpy_r_r26 = PyIter_Next(cpy_r_r21);
    CPy_DECREF(cpy_r_r21);
    if (cpy_r_r26 == NULL) {
        goto CPyL18;
    } else
        goto CPyL50;
CPyL16: ;
    PyErr_SetString(PyExc_ValueError, "too many values to unpack");
    cpy_r_r27 = 0;
    if (unlikely(!cpy_r_r27)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL40;
    }
    CPy_Unreachable();
CPyL18: ;
    cpy_r_r28 = CPyStatics[72]; /* 0 */
    cpy_r_r29 = PyObject_RichCompare(cpy_r_score, cpy_r_r28, 4);
    if (unlikely(cpy_r_r29 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r30 = PyObject_IsTrue(cpy_r_r29);
    CPy_DECREF(cpy_r_r29);
    cpy_r_r31 = cpy_r_r30 >= 0;
    if (unlikely(!cpy_r_r31)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL51;
    }
    cpy_r_r32 = cpy_r_r30;
    if (!cpy_r_r32) goto CPyL52;
    cpy_r_r33.f0 = cpy_r_name;
    cpy_r_r33.f1 = cpy_r_score;
    cpy_r_r34 = PyTuple_New(2);
    if (unlikely(cpy_r_r34 == NULL))
        CPyError_OutOfMemory();
    PyObject *__tmp12 = cpy_r_r33.f0;
    PyTuple_SET_ITEM(cpy_r_r34, 0, __tmp12);
    PyObject *__tmp13 = cpy_r_r33.f1;
    PyTuple_SET_ITEM(cpy_r_r34, 1, __tmp13);
    cpy_r_r35 = PyList_Append(cpy_r_r13, cpy_r_r34);
    CPy_DECREF(cpy_r_r34);
    cpy_r_r36 = cpy_r_r35 >= 0;
    if (unlikely(!cpy_r_r36)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL47;
    } else
        goto CPyL7;
CPyL22: ;
    cpy_r_r37 = CPy_NoErrOccured();
    if (unlikely(!cpy_r_r37)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 149, CPyStatic_globals);
        goto CPyL45;
    }
    cpy_r_r38 = CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj();
    if (unlikely(cpy_r_r38 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 150, CPyStatic_globals);
        goto CPyL45;
    }
    if (((main_____mypyc_lambda__0_show_leaderboard_Game_objObject *)cpy_r_r38)->___mypyc_env__ != NULL) {
        CPy_DECREF(((main_____mypyc_lambda__0_show_leaderboard_Game_objObject *)cpy_r_r38)->___mypyc_env__);
    }
    ((main_____mypyc_lambda__0_show_leaderboard_Game_objObject *)cpy_r_r38)->___mypyc_env__ = cpy_r_r0;
    cpy_r_r39 = 1;
    if (unlikely(!cpy_r_r39)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 150, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r40 = CPyModule_builtins;
    cpy_r_r41 = CPyStatics[39]; /* 'sorted' */
    cpy_r_r42 = CPyObject_GetAttr(cpy_r_r40, cpy_r_r41);
    if (unlikely(cpy_r_r42 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 148, CPyStatic_globals);
        goto CPyL53;
    }
    cpy_r_r43 = 1 ? Py_True : Py_False;
    PyObject *cpy_r_r44[3] = {cpy_r_r13, cpy_r_r38, cpy_r_r43};
    cpy_r_r45 = (PyObject **)&cpy_r_r44;
    cpy_r_r46 = CPyStatics[74]; /* ('key', 'reverse') */
    cpy_r_r47 = _PyObject_Vectorcall(cpy_r_r42, cpy_r_r45, 1, cpy_r_r46);
    CPy_DECREF(cpy_r_r42);
    if (unlikely(cpy_r_r47 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 148, CPyStatic_globals);
        goto CPyL53;
    }
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r38);
    if (likely(PyList_Check(cpy_r_r47)))
        cpy_r_r48 = cpy_r_r47;
    else {
        CPy_TypeErrorTraceback("main.py", "show_leaderboard", 148, CPyStatic_globals, "list", cpy_r_r47);
        goto CPyL54;
    }
    cpy_r_sorted_scores = cpy_r_r48;
    cpy_r_r49 = 0;
    cpy_r_i = 0;
    cpy_r_r50 = 0;
CPyL29: ;
    cpy_r_r51 = (CPyPtr)&((PyVarObject *)cpy_r_sorted_scores)->ob_size;
    cpy_r_r52 = *(int64_t *)cpy_r_r51;
    cpy_r_r53 = cpy_r_r52 << 1;
    cpy_r_r54 = (Py_ssize_t)cpy_r_r50 < (Py_ssize_t)cpy_r_r53;
    if (!cpy_r_r54) goto CPyL55;
    cpy_r_r55 = CPyList_GetItemUnsafe(cpy_r_sorted_scores, cpy_r_r50);
    PyObject *__tmp14;
    if (unlikely(!(PyTuple_Check(cpy_r_r55) && PyTuple_GET_SIZE(cpy_r_r55) == 2))) {
        __tmp14 = NULL;
        goto __LL15;
    }
    if (PyUnicode_Check(PyTuple_GET_ITEM(cpy_r_r55, 0)))
        __tmp14 = PyTuple_GET_ITEM(cpy_r_r55, 0);
    else {
        __tmp14 = NULL;
    }
    if (__tmp14 != NULL) goto __LL16;
    if (PyTuple_GET_ITEM(cpy_r_r55, 0) == Py_None)
        __tmp14 = PyTuple_GET_ITEM(cpy_r_r55, 0);
    else {
        __tmp14 = NULL;
    }
    if (__tmp14 != NULL) goto __LL16;
    __tmp14 = NULL;
__LL16: ;
    if (__tmp14 == NULL) goto __LL15;
    if (likely(PyLong_Check(PyTuple_GET_ITEM(cpy_r_r55, 1))))
        __tmp14 = PyTuple_GET_ITEM(cpy_r_r55, 1);
    else {
        __tmp14 = NULL;
    }
    if (__tmp14 == NULL) goto __LL15;
    __tmp14 = cpy_r_r55;
__LL15: ;
    if (unlikely(__tmp14 == NULL)) {
        CPy_TypeError("tuple[union[str, None], int]", cpy_r_r55); cpy_r_r56 = (tuple_T2OI) { NULL, CPY_INT_TAG };
    } else {
        PyObject *__tmp17 = PyTuple_GET_ITEM(cpy_r_r55, 0);
        CPy_INCREF(__tmp17);
        PyObject *__tmp18;
        if (PyUnicode_Check(__tmp17))
            __tmp18 = __tmp17;
        else {
            __tmp18 = NULL;
        }
        if (__tmp18 != NULL) goto __LL19;
        if (__tmp17 == Py_None)
            __tmp18 = __tmp17;
        else {
            __tmp18 = NULL;
        }
        if (__tmp18 != NULL) goto __LL19;
        CPy_TypeError("str or None", __tmp17); 
        __tmp18 = NULL;
__LL19: ;
        cpy_r_r56.f0 = __tmp18;
        PyObject *__tmp20 = PyTuple_GET_ITEM(cpy_r_r55, 1);
        CPyTagged __tmp21;
        if (likely(PyLong_Check(__tmp20)))
            __tmp21 = CPyTagged_FromObject(__tmp20);
        else {
            CPy_TypeError("int", __tmp20); __tmp21 = CPY_INT_TAG;
        }
        cpy_r_r56.f1 = __tmp21;
    }
    CPy_DECREF(cpy_r_r55);
    if (unlikely(cpy_r_r56.f0 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 153, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r57 = cpy_r_r56.f0;
    CPy_INCREF(cpy_r_r57);
    cpy_r_name_2 = cpy_r_r57;
    cpy_r_r58 = cpy_r_r56.f1;
    CPyTagged_INCREF(cpy_r_r58);
    CPy_DECREF(cpy_r_r56.f0);
    CPyTagged_DECREF(cpy_r_r56.f1);
    cpy_r_score_2 = cpy_r_r58;
    cpy_r_r59 = PyObject_Str(cpy_r_name_2);
    CPy_DECREF(cpy_r_name_2);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 154, CPyStatic_globals);
        goto CPyL57;
    }
    cpy_r_r60 = CPyStatics[42]; /* ': ' */
    cpy_r_r61 = CPyTagged_Str(cpy_r_score_2);
    CPyTagged_DECREF(cpy_r_score_2);
    if (unlikely(cpy_r_r61 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 154, CPyStatic_globals);
        goto CPyL58;
    }
    cpy_r_r62 = CPyStr_Build(3, cpy_r_r59, cpy_r_r60, cpy_r_r61);
    CPy_DECREF(cpy_r_r59);
    CPy_DECREF(cpy_r_r61);
    if (unlikely(cpy_r_r62 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 154, CPyStatic_globals);
        goto CPyL56;
    }
    cpy_r_r63 = CPyStatic_globals;
    cpy_r_r64 = CPyStatics[15]; /* 'Label' */
    cpy_r_r65 = CPyDict_GetItem(cpy_r_r63, cpy_r_r64);
    if (unlikely(cpy_r_r65 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 154, CPyStatic_globals);
        goto CPyL59;
    }
    PyObject *cpy_r_r66[2] = {cpy_r_leaderboard_window, cpy_r_r62};
    cpy_r_r67 = (PyObject **)&cpy_r_r66;
    cpy_r_r68 = CPyStatics[73]; /* ('text',) */
    cpy_r_r69 = _PyObject_Vectorcall(cpy_r_r65, cpy_r_r67, 1, cpy_r_r68);
    CPy_DECREF(cpy_r_r65);
    if (unlikely(cpy_r_r69 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 154, CPyStatic_globals);
        goto CPyL59;
    }
    CPy_DECREF(cpy_r_r62);
    cpy_r_r70 = CPyStatics[43]; /* 'grid' */
    cpy_r_r71 = CPyTagged_StealAsObject(cpy_r_i);
    PyObject *cpy_r_r72[2] = {cpy_r_r69, cpy_r_r71};
    cpy_r_r73 = (PyObject **)&cpy_r_r72;
    cpy_r_r74 = CPyStatics[75]; /* ('row',) */
    cpy_r_r75 = PyObject_VectorcallMethod(cpy_r_r70, cpy_r_r73, 9223372036854775809ULL, cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("main.py", "show_leaderboard", 154, CPyStatic_globals);
        goto CPyL60;
    } else
        goto CPyL61;
CPyL37: ;
    CPy_DECREF(cpy_r_r69);
    CPy_DECREF(cpy_r_r71);
    cpy_r_r76 = cpy_r_r49 + 2;
    cpy_r_r49 = cpy_r_r76;
    cpy_r_i = cpy_r_r76;
    cpy_r_r77 = cpy_r_r50 + 2;
    cpy_r_r50 = cpy_r_r77;
    goto CPyL29;
CPyL39: ;
    return 1;
CPyL40: ;
    cpy_r_r78 = 2;
    return cpy_r_r78;
CPyL41: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_r1);
    goto CPyL40;
CPyL42: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_leaderboard_window);
    goto CPyL40;
CPyL43: ;
    CPy_DECREF(cpy_r_r12);
    goto CPyL4;
CPyL44: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r14);
    goto CPyL40;
CPyL45: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_r13);
    goto CPyL40;
CPyL46: ;
    CPy_DECREF(cpy_r_r19);
    goto CPyL22;
CPyL47: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r19);
    goto CPyL40;
CPyL48: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_leaderboard_window);
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r21);
    goto CPyL10;
CPyL49: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_leaderboard_window);
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_r21);
    CPy_DECREF(cpy_r_name);
    goto CPyL13;
CPyL50: ;
    CPy_DECREF(cpy_r_r0);
    CPy_DECREF(cpy_r_leaderboard_window);
    CPy_DECREF(cpy_r_r13);
    CPy_DECREF(cpy_r_r19);
    CPy_DECREF(cpy_r_name);
    CPy_DECREF(cpy_r_score);
    CPy_DECREF(cpy_r_r26);
    goto CPyL16;
CPyL51: ;
    CPy_DecRef(cpy_r_r0);
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r19);
    CPy_DecRef(cpy_r_name);
    CPy_DecRef(cpy_r_score);
    goto CPyL40;
CPyL52: ;
    CPy_DECREF(cpy_r_name);
    CPy_DECREF(cpy_r_score);
    goto CPyL7;
CPyL53: ;
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_r13);
    CPy_DecRef(cpy_r_r38);
    goto CPyL40;
CPyL54: ;
    CPy_DecRef(cpy_r_leaderboard_window);
    goto CPyL40;
CPyL55: ;
    CPy_DECREF(cpy_r_leaderboard_window);
    CPy_DECREF(cpy_r_sorted_scores);
    CPyTagged_DECREF(cpy_r_i);
    goto CPyL39;
CPyL56: ;
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_sorted_scores);
    CPyTagged_DecRef(cpy_r_i);
    goto CPyL40;
CPyL57: ;
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_sorted_scores);
    CPyTagged_DecRef(cpy_r_i);
    CPyTagged_DecRef(cpy_r_score_2);
    goto CPyL40;
CPyL58: ;
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_sorted_scores);
    CPyTagged_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r59);
    goto CPyL40;
CPyL59: ;
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_sorted_scores);
    CPyTagged_DecRef(cpy_r_i);
    CPy_DecRef(cpy_r_r62);
    goto CPyL40;
CPyL60: ;
    CPy_DecRef(cpy_r_leaderboard_window);
    CPy_DecRef(cpy_r_sorted_scores);
    CPy_DecRef(cpy_r_r69);
    CPy_DecRef(cpy_r_r71);
    goto CPyL40;
CPyL61: ;
    CPy_DECREF(cpy_r_r75);
    goto CPyL37;
}

PyObject *CPyPy_Game___show_leaderboard(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames) {
    PyObject *obj_self = self;
    static const char * const kwlist[] = {0};
    static CPyArg_Parser parser = {":show_leaderboard", kwlist, 0};
    if (!CPyArg_ParseStackAndKeywordsNoArgs(args, nargs, kwnames, &parser)) {
        return NULL;
    }
    PyObject *arg_self;
    if (likely(Py_TYPE(obj_self) == CPyType_Game))
        arg_self = obj_self;
    else {
        CPy_TypeError("main.Game", obj_self); 
        goto fail;
    }
    char retval = CPyDef_Game___show_leaderboard(arg_self);
    if (retval == 2) {
        return NULL;
    }
    PyObject *retbox = Py_None;
    CPy_INCREF(retbox);
    return retbox;
fail: ;
    CPy_AddTraceback("main.py", "show_leaderboard", 139, CPyStatic_globals);
    return NULL;
}

char CPyDef___top_level__(void) {
    PyObject *cpy_r_r0;
    PyObject *cpy_r_r1;
    char cpy_r_r2;
    PyObject *cpy_r_r3;
    PyObject *cpy_r_r4;
    PyObject *cpy_r_r5;
    PyObject *cpy_r_r6;
    PyObject *cpy_r_r7;
    PyObject *cpy_r_r8;
    PyObject *cpy_r_r9;
    PyObject *cpy_r_r10;
    PyObject *cpy_r_r11;
    PyObject *cpy_r_r12;
    PyObject *cpy_r_r13;
    PyObject *cpy_r_r14;
    PyObject *cpy_r_r15;
    PyObject *cpy_r_r16;
    PyObject *cpy_r_r17;
    PyObject *cpy_r_r18;
    PyObject *cpy_r_r19;
    PyObject *cpy_r_r20;
    PyObject *cpy_r_r21;
    PyObject *cpy_r_r22;
    PyObject *cpy_r_r23;
    PyObject *cpy_r_r24;
    PyObject *cpy_r_r25;
    PyObject *cpy_r_r26;
    PyObject *cpy_r_r27;
    PyObject *cpy_r_r28;
    PyObject *cpy_r_r29;
    PyObject *cpy_r_r30;
    PyObject *cpy_r_r31;
    PyObject *cpy_r_r32;
    PyObject *cpy_r_r33;
    PyObject *cpy_r_r34;
    PyObject *cpy_r_r35;
    PyObject *cpy_r_r36;
    char cpy_r_r37;
    PyObject *cpy_r_r38;
    PyObject *cpy_r_r39;
    PyObject *cpy_r_r40;
    PyObject *cpy_r_r41;
    PyObject *cpy_r_r42;
    PyObject *cpy_r_r43;
    PyObject *cpy_r_r44;
    PyObject *cpy_r_r45;
    PyObject *cpy_r_r46;
    PyObject *cpy_r_r47;
    PyObject *cpy_r_r48;
    PyObject *cpy_r_r49;
    int32_t cpy_r_r50;
    char cpy_r_r51;
    PyObject *cpy_r_r52;
    PyObject *cpy_r_r53;
    int32_t cpy_r_r54;
    char cpy_r_r55;
    PyObject *cpy_r_r56;
    PyObject *cpy_r_r57;
    PyObject *cpy_r_r58;
    PyObject *cpy_r_r59;
    PyObject *cpy_r_r60;
    PyObject *cpy_r_r61;
    int32_t cpy_r_r62;
    char cpy_r_r63;
    PyObject *cpy_r_r64;
    PyObject *cpy_r_r65;
    PyObject *cpy_r_r66;
    PyObject *cpy_r_r67;
    PyObject *cpy_r_r68;
    PyObject **cpy_r_r70;
    PyObject *cpy_r_r71;
    PyObject *cpy_r_r72;
    PyObject *cpy_r_r73;
    PyObject *cpy_r_r74;
    PyObject *cpy_r_r75;
    PyObject *cpy_r_r76;
    PyObject *cpy_r_r77;
    int32_t cpy_r_r78;
    char cpy_r_r79;
    PyObject *cpy_r_r80;
    PyObject *cpy_r_r81;
    PyObject *cpy_r_r82;
    PyObject *cpy_r_r83;
    PyObject **cpy_r_r85;
    PyObject *cpy_r_r86;
    char cpy_r_r87;
    cpy_r_r0 = CPyModule_builtins;
    cpy_r_r1 = (PyObject *)&_Py_NoneStruct;
    cpy_r_r2 = cpy_r_r0 != cpy_r_r1;
    if (cpy_r_r2) goto CPyL3;
    cpy_r_r3 = CPyStatics[45]; /* 'builtins' */
    cpy_r_r4 = PyImport_Import(cpy_r_r3);
    if (unlikely(cpy_r_r4 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", -1, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_builtins = cpy_r_r4;
    CPy_INCREF(CPyModule_builtins);
    CPy_DECREF(cpy_r_r4);
CPyL3: ;
    cpy_r_r5 = CPyStatics[76]; /* ('defaultdict',) */
    cpy_r_r6 = CPyStatics[46]; /* 'collections' */
    cpy_r_r7 = CPyStatic_globals;
    cpy_r_r8 = CPyImport_ImportFromMany(cpy_r_r6, cpy_r_r5, cpy_r_r5, cpy_r_r7);
    if (unlikely(cpy_r_r8 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 1, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_collections = cpy_r_r8;
    CPy_INCREF(CPyModule_collections);
    CPy_DECREF(cpy_r_r8);
    cpy_r_r9 = CPyStatics[77]; /* ('Tk', 'Entry', 'Label', 'Toplevel') */
    cpy_r_r10 = CPyStatics[48]; /* 'tkinter' */
    cpy_r_r11 = CPyStatic_globals;
    cpy_r_r12 = CPyImport_ImportFromMany(cpy_r_r10, cpy_r_r9, cpy_r_r9, cpy_r_r11);
    if (unlikely(cpy_r_r12 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 2, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_tkinter = cpy_r_r12;
    CPy_INCREF(CPyModule_tkinter);
    CPy_DECREF(cpy_r_r12);
    cpy_r_r13 = CPyStatics[78]; /* ('askstring',) */
    cpy_r_r14 = CPyStatics[49]; /* 'tkinter.simpledialog' */
    cpy_r_r15 = CPyStatic_globals;
    cpy_r_r16 = CPyImport_ImportFromMany(cpy_r_r14, cpy_r_r13, cpy_r_r13, cpy_r_r15);
    if (unlikely(cpy_r_r16 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 3, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_tkinter___simpledialog = cpy_r_r16;
    CPy_INCREF(CPyModule_tkinter___simpledialog);
    CPy_DECREF(cpy_r_r16);
    cpy_r_r17 = CPyStatics[79]; /* ('isfile',) */
    cpy_r_r18 = CPyStatics[50]; /* 'os.path' */
    cpy_r_r19 = CPyStatic_globals;
    cpy_r_r20 = CPyImport_ImportFromMany(cpy_r_r18, cpy_r_r17, cpy_r_r17, cpy_r_r19);
    if (unlikely(cpy_r_r20 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 4, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_os___path = cpy_r_r20;
    CPy_INCREF(CPyModule_os___path);
    CPy_DECREF(cpy_r_r20);
    cpy_r_r21 = CPyStatics[80]; /* ('load', 'dump') */
    cpy_r_r22 = CPyStatics[51]; /* 'json' */
    cpy_r_r23 = CPyStatic_globals;
    cpy_r_r24 = CPyImport_ImportFromMany(cpy_r_r22, cpy_r_r21, cpy_r_r21, cpy_r_r23);
    if (unlikely(cpy_r_r24 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 5, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_json = cpy_r_r24;
    CPy_INCREF(CPyModule_json);
    CPy_DECREF(cpy_r_r24);
    cpy_r_r25 = CPyStatics[81]; /* ('time',) */
    cpy_r_r26 = CPyStatics[11]; /* 'time' */
    cpy_r_r27 = CPyStatic_globals;
    cpy_r_r28 = CPyImport_ImportFromMany(cpy_r_r26, cpy_r_r25, cpy_r_r25, cpy_r_r27);
    if (unlikely(cpy_r_r28 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 6, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_time = cpy_r_r28;
    CPy_INCREF(CPyModule_time);
    CPy_DECREF(cpy_r_r28);
    cpy_r_r29 = CPyStatics[82]; /* ('Dict',) */
    cpy_r_r30 = CPyStatics[52]; /* 'enchant' */
    cpy_r_r31 = CPyStatic_globals;
    cpy_r_r32 = CPyImport_ImportFromMany(cpy_r_r30, cpy_r_r29, cpy_r_r29, cpy_r_r31);
    if (unlikely(cpy_r_r32 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 7, CPyStatic_globals);
        goto CPyL26;
    }
    CPyModule_enchant = cpy_r_r32;
    CPy_INCREF(CPyModule_enchant);
    CPy_DECREF(cpy_r_r32);
    cpy_r_r33 = NULL;
    cpy_r_r34 = CPyStatics[53]; /* 'main' */
    cpy_r_r35 = (PyObject *)CPyType_Game_template;
    cpy_r_r36 = CPyType_FromTemplate(cpy_r_r35, cpy_r_r33, cpy_r_r34);
    if (unlikely(cpy_r_r36 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 10, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r37 = CPyDef_Game_trait_vtable_setup();
    if (unlikely(cpy_r_r37 == 2)) {
        CPy_AddTraceback("main.py", "<module>", -1, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r38 = CPyStatics[54]; /* '__mypyc_attrs__' */
    cpy_r_r39 = CPyStatics[55]; /* 'dictionary' */
    cpy_r_r40 = CPyStatics[56]; /* 'scores' */
    cpy_r_r41 = CPyStatics[57]; /* 'master' */
    cpy_r_r42 = CPyStatics[58]; /* 'word_length' */
    cpy_r_r43 = CPyStatics[59]; /* 'time_limit' */
    cpy_r_r44 = CPyStatics[60]; /* 'score' */
    cpy_r_r45 = CPyStatics[61]; /* 'start_time' */
    cpy_r_r46 = CPyStatics[62]; /* 'used_words' */
    cpy_r_r47 = CPyStatics[63]; /* 'entry' */
    cpy_r_r48 = CPyStatics[64]; /* 'label' */
    cpy_r_r49 = PyTuple_Pack(10, cpy_r_r39, cpy_r_r40, cpy_r_r41, cpy_r_r42, cpy_r_r43, cpy_r_r44, cpy_r_r45, cpy_r_r46, cpy_r_r47, cpy_r_r48);
    if (unlikely(cpy_r_r49 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 10, CPyStatic_globals);
        goto CPyL27;
    }
    cpy_r_r50 = PyObject_SetAttr(cpy_r_r36, cpy_r_r38, cpy_r_r49);
    CPy_DECREF(cpy_r_r49);
    cpy_r_r51 = cpy_r_r50 >= 0;
    if (unlikely(!cpy_r_r51)) {
        CPy_AddTraceback("main.py", "<module>", 10, CPyStatic_globals);
        goto CPyL27;
    }
    CPyType_Game = (PyTypeObject *)cpy_r_r36;
    CPy_INCREF(CPyType_Game);
    cpy_r_r52 = CPyStatic_globals;
    cpy_r_r53 = CPyStatics[65]; /* 'Game' */
    cpy_r_r54 = CPyDict_SetItem(cpy_r_r52, cpy_r_r53, cpy_r_r36);
    CPy_DECREF(cpy_r_r36);
    cpy_r_r55 = cpy_r_r54 >= 0;
    if (unlikely(!cpy_r_r55)) {
        CPy_AddTraceback("main.py", "<module>", 10, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r56 = CPyStatic_globals;
    cpy_r_r57 = CPyStatics[47]; /* 'Tk' */
    cpy_r_r58 = CPyDict_GetItem(cpy_r_r56, cpy_r_r57);
    if (unlikely(cpy_r_r58 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 157, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r59 = _PyObject_Vectorcall(cpy_r_r58, 0, 0, 0);
    CPy_DECREF(cpy_r_r58);
    if (unlikely(cpy_r_r59 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 157, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r60 = CPyStatic_globals;
    cpy_r_r61 = CPyStatics[66]; /* 'root' */
    cpy_r_r62 = CPyDict_SetItem(cpy_r_r60, cpy_r_r61, cpy_r_r59);
    CPy_DECREF(cpy_r_r59);
    cpy_r_r63 = cpy_r_r62 >= 0;
    if (unlikely(!cpy_r_r63)) {
        CPy_AddTraceback("main.py", "<module>", 157, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r64 = CPyStatic_globals;
    cpy_r_r65 = CPyStatics[66]; /* 'root' */
    cpy_r_r66 = CPyDict_GetItem(cpy_r_r64, cpy_r_r65);
    if (unlikely(cpy_r_r66 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 158, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r67 = CPyStatics[67]; /* '800x600' */
    cpy_r_r68 = CPyStatics[68]; /* 'geometry' */
    PyObject *cpy_r_r69[2] = {cpy_r_r66, cpy_r_r67};
    cpy_r_r70 = (PyObject **)&cpy_r_r69;
    cpy_r_r71 = PyObject_VectorcallMethod(cpy_r_r68, cpy_r_r70, 9223372036854775810ULL, 0);
    if (unlikely(cpy_r_r71 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 158, CPyStatic_globals);
        goto CPyL28;
    } else
        goto CPyL29;
CPyL20: ;
    CPy_DECREF(cpy_r_r66);
    cpy_r_r72 = CPyStatic_globals;
    cpy_r_r73 = CPyStatics[66]; /* 'root' */
    cpy_r_r74 = CPyDict_GetItem(cpy_r_r72, cpy_r_r73);
    if (unlikely(cpy_r_r74 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 159, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r75 = CPyDef_Game(cpy_r_r74);
    CPy_DECREF(cpy_r_r74);
    if (unlikely(cpy_r_r75 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 159, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r76 = CPyStatic_globals;
    cpy_r_r77 = CPyStatics[69]; /* 'game' */
    cpy_r_r78 = CPyDict_SetItem(cpy_r_r76, cpy_r_r77, cpy_r_r75);
    CPy_DECREF(cpy_r_r75);
    cpy_r_r79 = cpy_r_r78 >= 0;
    if (unlikely(!cpy_r_r79)) {
        CPy_AddTraceback("main.py", "<module>", 159, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r80 = CPyStatic_globals;
    cpy_r_r81 = CPyStatics[66]; /* 'root' */
    cpy_r_r82 = CPyDict_GetItem(cpy_r_r80, cpy_r_r81);
    if (unlikely(cpy_r_r82 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 160, CPyStatic_globals);
        goto CPyL26;
    }
    cpy_r_r83 = CPyStatics[70]; /* 'mainloop' */
    PyObject *cpy_r_r84[1] = {cpy_r_r82};
    cpy_r_r85 = (PyObject **)&cpy_r_r84;
    cpy_r_r86 = PyObject_VectorcallMethod(cpy_r_r83, cpy_r_r85, 9223372036854775809ULL, 0);
    if (unlikely(cpy_r_r86 == NULL)) {
        CPy_AddTraceback("main.py", "<module>", 160, CPyStatic_globals);
        goto CPyL30;
    } else
        goto CPyL31;
CPyL25: ;
    CPy_DECREF(cpy_r_r82);
    return 1;
CPyL26: ;
    cpy_r_r87 = 2;
    return cpy_r_r87;
CPyL27: ;
    CPy_DecRef(cpy_r_r36);
    goto CPyL26;
CPyL28: ;
    CPy_DecRef(cpy_r_r66);
    goto CPyL26;
CPyL29: ;
    CPy_DECREF(cpy_r_r71);
    goto CPyL20;
CPyL30: ;
    CPy_DecRef(cpy_r_r82);
    goto CPyL26;
CPyL31: ;
    CPy_DECREF(cpy_r_r86);
    goto CPyL25;
}

int CPyGlobalsInit(void)
{
    static int is_initialized = 0;
    if (is_initialized) return 0;
    
    CPy_Init();
    CPyModule_main = Py_None;
    CPyModule_builtins = Py_None;
    CPyModule_collections = Py_None;
    CPyModule_tkinter = Py_None;
    CPyModule_tkinter___simpledialog = Py_None;
    CPyModule_os___path = Py_None;
    CPyModule_json = Py_None;
    CPyModule_time = Py_None;
    CPyModule_enchant = Py_None;
    if (CPyStatics_Initialize(CPyStatics, CPyLit_Str, CPyLit_Bytes, CPyLit_Int, CPyLit_Float, CPyLit_Complex, CPyLit_Tuple, CPyLit_FrozenSet) < 0) {
        return -1;
    }
    is_initialized = 1;
    return 0;
}

PyObject *CPyStatics[83];
const char * const CPyLit_Str[] = {
    "\v\005en_US\004Dict\vscores.json\006isfile\001r\004open\004load\vdefaultdict\004time\005Entry\004pack",
    "\b\000\005Label\004text\006update\005after\025Time\'s up. Game Over.\006config\005Input",
    "\006\020Enter your name:\taskstring\003get\005check\003end\006delete",
    "\006\027Enter a word of length \004 in \021 seconds. Score: \001w\b__exit__\t__enter__",
    "\v\004dump\bToplevel\vLeaderboard\005title\005items\006sorted\003key\areverse\002: \004grid\003row",
    "\a\bbuiltins\vcollections\002Tk\atkinter\024tkinter.simpledialog\aos.path\004json",
    "\a\aenchant\004main\017__mypyc_attrs__\ndictionary\006scores\006master\vword_length",
    "\t\ntime_limit\005score\nstart_time\nused_words\005entry\005label\004Game\004root\a800x600",
    "\003\bgeometry\004game\bmainloop",
    "",
};
const char * const CPyLit_Bytes[] = {
    "",
};
const char * const CPyLit_Int[] = {
    "\0021000\0000",
    "",
};
const double CPyLit_Float[] = {0};
const double CPyLit_Complex[] = {0};
const int CPyLit_Tuple[] = {
    10, 1, 16, 2, 40, 41, 1, 44, 1, 10, 4, 47, 12, 15, 35, 1, 23, 1, 6,
    2, 9, 34, 1, 11, 1, 4
};
const int CPyLit_FrozenSet[] = {0};
CPyModule *CPyModule_main_internal = NULL;
CPyModule *CPyModule_main;
PyObject *CPyStatic_globals;
CPyModule *CPyModule_builtins;
CPyModule *CPyModule_collections;
CPyModule *CPyModule_tkinter;
CPyModule *CPyModule_tkinter___simpledialog;
CPyModule *CPyModule_os___path;
CPyModule *CPyModule_json;
CPyModule *CPyModule_time;
CPyModule *CPyModule_enchant;
PyTypeObject *CPyType_Game;
PyObject *CPyDef_Game(PyObject *cpy_r_master);
PyTypeObject *CPyType_show_leaderboard_Game_env;
PyObject *CPyDef_show_leaderboard_Game_env(void);
PyTypeObject *CPyType___mypyc_lambda__0_show_leaderboard_Game_obj;
PyObject *CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj(void);
char CPyDef_Game_____init__(PyObject *cpy_r_self, PyObject *cpy_r_master);
PyObject *CPyPy_Game_____init__(PyObject *self, PyObject *args, PyObject *kw);
char CPyDef_Game___update(PyObject *cpy_r_self);
PyObject *CPyPy_Game___update(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Game___is_time_up(PyObject *cpy_r_self);
PyObject *CPyPy_Game___is_time_up(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Game___end_game(PyObject *cpy_r_self);
PyObject *CPyPy_Game___end_game(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Game___check_and_update_word(PyObject *cpy_r_self);
PyObject *CPyPy_Game___check_and_update_word(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Game___level_up(PyObject *cpy_r_self);
PyObject *CPyPy_Game___level_up(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Game___save_score(PyObject *cpy_r_self, PyObject *cpy_r_name, CPyTagged cpy_r_score);
PyObject *CPyPy_Game___save_score(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
PyObject *CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
PyObject *CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
CPyTagged CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____call__(PyObject *cpy_r___mypyc_self__, tuple_T2OI cpy_r_x);
PyObject *CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef_Game___show_leaderboard(PyObject *cpy_r_self);
PyObject *CPyPy_Game___show_leaderboard(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
char CPyDef___top_level__(void);
