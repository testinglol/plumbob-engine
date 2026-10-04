
bool __thiscall FUN_005fad94(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  bool bVar4;
  
  cVar2 = (**(code **)(*DAT_006fed70 + 8))();
  if ((cVar2 == '\0') || (*(char *)(param_1 + 0x2c) == '\0')) {
    bVar4 = true;
  }
  else {
    piVar1 = *(int **)(param_1 + 4);
    if (piVar1 == (int *)0x0) {
      bVar4 = false;
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x50))(piVar1,param_2,param_3,param_4,1);
      bVar4 = iVar3 == 0;
    }
  }
  return bVar4;
}

