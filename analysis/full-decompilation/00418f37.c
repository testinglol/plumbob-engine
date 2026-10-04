
int __thiscall FUN_00418f37(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00418c28(param_2,0);
  if (piVar1 == *(int **)(param_1 + 4)) {
    iVar2 = 0;
  }
  else {
    iVar2 = (piVar1[1] - *piVar1) / 0x5c;
  }
  return iVar2;
}

