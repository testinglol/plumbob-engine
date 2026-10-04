
undefined4 __fastcall FUN_005e96b0(int param_1)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  iVar1 = *(int *)(param_1 + 0xd4);
  if (iVar1 != 0) {
    local_24 = *(int *)(iVar1 + 0x14);
    local_20 = *(undefined4 *)(iVar1 + 0x18);
    local_18 = *(undefined4 *)(iVar1 + 0x20);
    local_1c = *(int *)(iVar1 + 0x1c) / *(int *)(param_1 + 0xd8);
    local_14 = (local_1c - local_24) * *(int *)(param_1 + 0xe4);
    local_c = local_1c + local_14;
    local_14 = local_24 + local_14;
    local_10 = local_20;
    local_8 = local_18;
    FUN_004ba5ac(param_1 + 0x1c);
    if (*(int **)(param_1 + 0x5c) != (int *)0x0) {
      cVar2 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
      if (cVar2 != '\0') {
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x9c))
                  (*(undefined4 *)(param_1 + 0xd4),&local_14,&local_24,0);
        (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
      }
    }
    piVar3 = (int *)FUN_004b46a0();
    (**(code **)(*piVar3 + 0x170))(param_1 + 0xc);
  }
  return 1;
}

