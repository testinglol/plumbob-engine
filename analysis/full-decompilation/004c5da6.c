
uint __thiscall
FUN_004c5da6(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  char cVar5;
  
  cVar5 = '\0';
  iVar2 = *(int *)(param_1 + 0x10);
  while ((iVar2 != *(int *)(param_1 + 0x14) && (cVar5 == '\0'))) {
    iVar1 = *(int *)(iVar2 + 0x14);
    iVar2 = *(int *)(iVar2 + 0x10);
    *param_2 = iVar2;
    if ((iVar2 < 0xf8) || (0xff < iVar2)) {
      if (((iVar2 < 0x1f) || (0xf7 < iVar2)) && ((iVar2 < 0x100 || (0xfffe < iVar2)))) {
        iVar2 = iVar2 * 3;
        uVar4 = FUN_0046fbe5(0xffffffff);
        if ((int)uVar4 < iVar2) {
          return uVar4 & 0xffffff00;
        }
        uVar3 = FUN_004705f2(iVar2 + -1,0xffffffff);
        FUN_005d4bbf(uVar3);
        uVar3 = FUN_004705f2(iVar2,0xffffffff);
        FUN_005d4bbf(uVar3);
      }
      else {
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
      cVar5 = '\x01';
      *param_5 = *(undefined4 *)(iVar1 + 0x10);
    }
    FUN_0041674f();
    iVar2 = *(int *)(param_1 + 0x10);
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),cVar5);
}

