
void FUN_005b95c0(int param_1)

{
  char cVar1;
  
  if ((*(char *)(param_1 + 0x1c) == '\0') && (*(int **)(param_1 + 0xc) != (int *)0x0)) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0xc) + 0x10))();
    if (cVar1 != '\0') {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x14))();
    }
    if (*(int **)(param_1 + 0xc) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xc) + 0x80))(1);
    }
    *(undefined4 *)(param_1 + 0xc) = 0;
  }
  if (param_1 != 0) {
    thunk_FUN_005b8770();
    FUN_006321f0(param_1);
  }
  return;
}

