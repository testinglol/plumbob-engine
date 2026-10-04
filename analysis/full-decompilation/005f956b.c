
char __thiscall FUN_005f956b(int param_1,undefined4 param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  cVar2 = (**(code **)(*DAT_006fed70 + 8))();
  if (cVar2 == '\0') {
    cVar2 = '\x01';
  }
  else {
    piVar1 = *(int **)(param_1 + 0x80);
    if (piVar1 == (int *)0x0) {
      cVar2 = '\0';
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0x34))(piVar1,param_2);
      cVar2 = '\x01' - (iVar3 != 0);
    }
  }
  return cVar2;
}

