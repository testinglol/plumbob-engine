
void __thiscall FUN_00594713(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_c;
  int *local_8;
  
  local_c = param_1;
  local_8 = (int *)param_1;
  iVar1 = FUN_005946e8(param_2);
  piVar3 = (int *)(param_1 + 4);
  *param_3 = *param_3 + 1;
  if (iVar1 == *(int *)(param_1 + 8) - *piVar3 >> 3) {
    local_c = param_2;
    local_8 = param_3;
    FUN_0059aded(&local_c);
  }
  else {
    piVar2 = (int *)(*piVar3 + iVar1 * 8);
    if (*piVar2 == param_2) {
      if (piVar2[1] != 0) {
        FUN_005942ab();
      }
      *(int **)(*piVar3 + 4 + iVar1 * 8) = param_3;
    }
    else {
      local_c = param_2;
      local_8 = param_3;
      FUN_0059ae1c(piVar2,&local_c);
    }
  }
  return;
}

