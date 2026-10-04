
undefined4 __fastcall FUN_0054fbc7(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0xd4) != 0) {
    cVar1 = (**(code **)(**(int **)(param_1 + 0x5c) + 0x20))(0x10);
    if (cVar1 == '\0') {
      return 0;
    }
    local_24 = *(undefined4 *)(param_1 + 0x1c);
    local_20 = *(undefined4 *)(param_1 + 0x20);
    local_1c = *(undefined4 *)(param_1 + 0x24);
    local_18 = *(undefined4 *)(param_1 + 0x28);
    iVar3 = *(int *)(param_1 + 0xd4);
    local_14 = *(undefined4 *)(iVar3 + 0x14);
    local_10 = *(undefined4 *)(iVar3 + 0x18);
    local_c = *(undefined4 *)(iVar3 + 0x1c);
    local_8 = *(undefined4 *)(iVar3 + 0x20);
    FUN_00473496(DAT_006e5490);
    iVar2 = __ftol();
    iVar2 = iVar2 + -0x145;
    iVar3 = -0xff;
    if ((-0x100 < iVar2) && (iVar3 = 0xff, iVar2 < 0x100)) {
      iVar3 = iVar2;
    }
    FUN_004ba1dc(*(undefined4 *)(param_1 + 0x5c),&local_24,*(undefined4 *)(param_1 + 0xd4),
                 *(undefined4 *)(*(int *)(param_1 + 0xd8) + 0x60),&local_14,iVar3);
    (**(code **)(**(int **)(param_1 + 0x5c) + 0x24))(0x10);
  }
  return 1;
}

