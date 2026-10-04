
undefined4 __fastcall FUN_00502c7a(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar3 = 0;
  piVar2 = (int *)(param_1 + 0xdc);
  while (*(char *)(*piVar2 + 0xe4) == '\0') {
    iVar3 = iVar3 + 1;
    piVar2 = piVar2 + 1;
    if (0x13 < iVar3) {
      return 1;
    }
  }
  if (*(int **)(param_1 + 0x5c) == (int *)0x0) {
    return 1;
  }
  cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar1 == '\0') {
    return 1;
  }
  iVar3 = *(int *)(param_1 + 0xd4);
  local_14 = *(undefined4 *)(iVar3 + 0x14);
  local_10 = *(undefined4 *)(iVar3 + 0x18);
  local_c = *(int *)(iVar3 + 0x1c) / 3;
  local_8 = *(int *)(iVar3 + 0x20) / 3;
  (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar3,&local_14,param_1 + 0x1c,1);
  (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  return 1;
}

