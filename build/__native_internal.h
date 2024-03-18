#ifndef MYPYC_NATIVE_INTERNAL_H
#define MYPYC_NATIVE_INTERNAL_H
#include <Python.h>
#include <CPy.h>
#include "__native.h"

int CPyGlobalsInit(void);

extern PyObject *CPyStatics[83];
extern const char * const CPyLit_Str[];
extern const char * const CPyLit_Bytes[];
extern const char * const CPyLit_Int[];
extern const double CPyLit_Float[];
extern const double CPyLit_Complex[];
extern const int CPyLit_Tuple[];
extern const int CPyLit_FrozenSet[];
extern CPyModule *CPyModule_main_internal;
extern CPyModule *CPyModule_main;
extern PyObject *CPyStatic_globals;
extern CPyModule *CPyModule_builtins;
extern CPyModule *CPyModule_collections;
extern CPyModule *CPyModule_tkinter;
extern CPyModule *CPyModule_tkinter___simpledialog;
extern CPyModule *CPyModule_os___path;
extern CPyModule *CPyModule_json;
extern CPyModule *CPyModule_time;
extern CPyModule *CPyModule_enchant;
extern PyTypeObject *CPyType_Game;
extern PyObject *CPyDef_Game(PyObject *cpy_r_master);
extern PyTypeObject *CPyType_show_leaderboard_Game_env;
extern PyObject *CPyDef_show_leaderboard_Game_env(void);
extern PyTypeObject *CPyType___mypyc_lambda__0_show_leaderboard_Game_obj;
extern PyObject *CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj(void);
extern char CPyDef_Game_____init__(PyObject *cpy_r_self, PyObject *cpy_r_master);
extern PyObject *CPyPy_Game_____init__(PyObject *self, PyObject *args, PyObject *kw);
extern char CPyDef_Game___update(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___update(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Game___is_time_up(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___is_time_up(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Game___end_game(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___end_game(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Game___check_and_update_word(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___check_and_update_word(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Game___level_up(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___level_up(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Game___save_score(PyObject *cpy_r_self, PyObject *cpy_r_name, CPyTagged cpy_r_score);
extern PyObject *CPyPy_Game___save_score(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern PyObject *CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(PyObject *cpy_r___mypyc_self__, PyObject *cpy_r_instance, PyObject *cpy_r_owner);
extern PyObject *CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____get__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern CPyTagged CPyDef___mypyc_lambda__0_show_leaderboard_Game_obj_____call__(PyObject *cpy_r___mypyc_self__, tuple_T2OI cpy_r_x);
extern PyObject *CPyPy___mypyc_lambda__0_show_leaderboard_Game_obj_____call__(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef_Game___show_leaderboard(PyObject *cpy_r_self);
extern PyObject *CPyPy_Game___show_leaderboard(PyObject *self, PyObject *const *args, size_t nargs, PyObject *kwnames);
extern char CPyDef___top_level__(void);
#endif
