
undefined4 FUN_004e1ae3(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  
  iVar2 = FUN_00425db3(param_1);
  if (iVar2 != 0) {
    iVar3 = FUN_004102e1();
    while (0 < iVar3) {
      puVar4 = (undefined4 *)FUN_004102ab(0);
      uVar1 = *puVar4;
      uVar5 = FUN_004e988f(uVar1);
      iVar3 = FUN_0043acf5(uVar1);
      iVar6 = FUN_00425769(uVar1);
      if (iVar6 != 0) {
        FUN_00426068(iVar6);
      }
      if ((iVar3 != 0) && (((byte)*(undefined4 *)(iVar3 + 0xb4) & 0xc) == 4)) {
        FUN_004e1e40(uVar5);
      }
      iVar3 = FUN_004102e1();
    }
    FUN_004e1b96(iVar2);
    iVar2 = FUN_00425f45(iVar2);
    if (iVar2 == 0) {
      FUN_004e19a1();
      return 1;
    }
  }
  return 0;
}

