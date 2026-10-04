
char * FUN_00589c5c(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return s__NULL_practice__006d05a0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 8) != *(int *)(iVar1 + 4)) {
      return *(char **)(iVar1 + 4);
    }
    return s__unnamed_skill__006d0590;
  }
  return s__NULL_skill__006d0580;
}

