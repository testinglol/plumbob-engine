
int __fastcall FUN_005caa0d(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_70 [27];
  
  iVar2 = 0;
  piVar1 = *(int **)(param_1 + 0x7c);
  if ((((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x6c))(piVar1), iVar2 != 0)) &&
      (iVar2 != -0x7789fdb4)) && (*(char *)(param_1 + 0x4e0) != '\0')) {
    FUN_005caacc();
    iVar3 = FUN_005c85e2(param_1 + 0x48,1,0);
    iVar2 = 0;
    if (iVar3 != 0) {
      return iVar3;
    }
  }
  piVar1 = *(int **)(param_1 + 0x8c);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x6c))(piVar1);
  }
  piVar1 = *(int **)(param_1 + 0x120);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x6c))(piVar1);
  }
  if (*(char *)(param_1 + 0x4e0) != '\0') {
    _memset(local_70,0,0x6c);
    local_70[0] = 0x6c;
    iVar2 = (**(code **)(**(int **)(param_1 + 0x70) + 0x24))
                      (*(int **)(param_1 + 0x70),0x10,local_70,0,FUN_005caaab);
  }
  return iVar2;
}

