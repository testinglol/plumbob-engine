
undefined4 FUN_004e2d6b(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int local_8;
  
  iVar1 = FUN_00428f4f(param_1,&param_1,&local_8);
  if (iVar1 == 0) {
    uVar5 = 0xffffffff;
    if (local_8 != 0) {
      uVar5 = *(undefined4 *)(local_8 + 0x10c);
    }
    iVar4 = 0;
    iVar1 = FUN_004102e1();
    if (0 < iVar1) {
      do {
        puVar2 = (undefined4 *)FUN_004102ab(iVar4);
        uVar3 = FUN_004e988f(*puVar2);
        FUN_004e8d99(uVar3,0x1f,1);
        iVar4 = iVar4 + 1;
        iVar1 = FUN_004102e1();
      } while (iVar4 < iVar1);
    }
    if (*(int *)(param_1 + 0x10c) != 4000) {
      FUN_004e19b2(*(int *)(param_1 + 0x10c),0);
      *param_2 = *(undefined4 *)(param_1 + 0x10c);
    }
    local_8 = FUN_00425db3(uVar5);
    if ((local_8 != 0) && (*(int *)(local_8 + 0x10c) != 0)) {
      FUN_004e19b2(*(int *)(local_8 + 0x10c),0);
    }
    return 1;
  }
  return 0;
}

