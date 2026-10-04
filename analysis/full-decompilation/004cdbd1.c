
undefined4 FUN_004cdbd1(void)

{
  int *piVar1;
  int iVar2;
  undefined2 uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar5 = extraout_ECX;
  pvVar4 = operator_new(0x60);
  *(void **)(unaff_EBP + -0x10) = pvVar4;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (pvVar4 == (void *)0x0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
  }
  else {
    uVar5 = FUN_004cb8d2(uVar5);
    *(undefined4 *)(unaff_EBP + -0x10) = uVar5;
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x10) != 0) {
    piVar1 = *(int **)(unaff_EBP + 0x14);
    if (piVar1 != (int *)0x0) {
      FUN_005a5631(*(undefined4 *)(unaff_EBP + 8),piVar1,4);
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        *(undefined4 *)(unaff_EBP + 0x14) = *(undefined4 *)*piVar1;
        uVar3 = FUN_005dfe3b(0xff,0,0xff);
        (**(code **)(*(int *)(unaff_EBP + 0x14) + 0x68))(uVar3);
      }
    }
    iVar2 = *(int *)(unaff_EBP + 0x10) * 3;
    uVar5 = FUN_004705f2(iVar2 + -2,0xffffffff);
    uVar5 = FUN_00635f62(uVar5);
    **(undefined4 **)(unaff_EBP + 0x20) = uVar5;
    uVar5 = FUN_004705f2(iVar2 + -1,0xffffffff);
    FUN_005d4bbf(uVar5);
    uVar5 = FUN_004705f2(iVar2,0xffffffff);
    FUN_005d4bbf(uVar5);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return *(undefined4 *)(unaff_EBP + -0x10);
}

