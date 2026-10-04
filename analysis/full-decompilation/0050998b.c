
undefined4 __fastcall FUN_0050998b(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
  if (cVar2 != '\0') {
    iVar1 = *(int *)(param_1 + 0x130);
    if (iVar1 != 0) {
      local_14 = *(undefined4 *)(iVar1 + 0x14);
      local_10 = *(undefined4 *)(iVar1 + 0x18);
      local_c = *(int *)(iVar1 + 0x1c) / 3;
      local_8 = *(int *)(iVar1 + 0x20) / 3;
      (**(code **)(**(int **)(param_1 + 0x5c) + 0xc0))(iVar1,&local_14,param_1 + 0x1c,1);
    }
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

