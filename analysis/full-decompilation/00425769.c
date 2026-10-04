
int __thiscall FUN_00425769(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_8;
  
  if (param_2 == 0) {
    local_8 = 0;
  }
  else {
    local_8 = 0;
    piVar1 = *(int **)(param_1 + 0x14c);
    for (piVar4 = *(int **)(param_1 + 0x148); piVar4 != piVar1; piVar4 = piVar4 + 1) {
      iVar2 = *piVar4;
      if (((iVar2 != 0) && (iVar3 = FUN_00401f73(), iVar3 == param_2)) && (local_8 == 0)) {
        local_8 = iVar2;
      }
    }
  }
  return local_8;
}

