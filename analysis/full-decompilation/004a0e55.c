
undefined4 __thiscall
FUN_004a0e55(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0x10);
  if (iVar2 == *(int *)(param_1 + 0x14)) {
LAB_004a0f54:
    uVar3 = 0;
  }
  else {
    iVar1 = *(int *)(iVar2 + 0x14);
    iVar2 = *(int *)(iVar2 + 0x10);
    *param_2 = iVar2;
    if (((iVar2 < 0x1e) || (0xfe < iVar2)) && ((iVar2 < 0x100 || (0xfffe < iVar2)))) {
      iVar2 = iVar2 * 3;
      iVar4 = FUN_0046fbe5(0xffffffff);
      if (iVar4 < iVar2) goto LAB_004a0f54;
      uVar3 = FUN_004705f2(iVar2 + -1,0xffffffff);
      FUN_005d4bbf(uVar3);
      uVar3 = FUN_004705f2(iVar2,0xffffffff);
      FUN_005d4bbf(uVar3);
    }
    else {
      iVar2 = FUN_0046fbe5(0xffffffff);
      if (iVar2 < 2) goto LAB_004a0f54;
      if (*(int *)(iVar1 + 0x14) == *(int *)(iVar1 + 0x18)) {
        uVar3 = FUN_004705f2(2,0xffffffff);
      }
      else {
        uVar3 = FUN_004096c2();
      }
      FUN_005d49b7(uVar3);
      if (*(int *)(iVar1 + 0x20) == *(int *)(iVar1 + 0x24)) {
        uVar3 = FUN_004705f2(3,0xffffffff);
      }
      else {
        uVar3 = FUN_004096c2();
      }
      FUN_005d49b7(uVar3);
    }
    *param_5 = *(undefined4 *)(iVar1 + 0x10);
    FUN_0041674f();
    uVar3 = 1;
  }
  return uVar3;
}

