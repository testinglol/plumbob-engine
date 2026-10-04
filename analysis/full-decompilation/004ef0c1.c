
void FUN_004ef0c1(void)

{
  undefined4 *puVar1;
  undefined2 extraout_var;
  int iVar2;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x14) = extraout_ECX;
  extraout_ECX[-2] = &PTR_LAB_00669884;
  extraout_ECX[-1] = &PTR_LAB_00669878;
  *extraout_ECX = &PTR_FUN_00669860;
  extraout_ECX[2] = &PTR_LAB_00669858;
  extraout_ECX[0x10] = &PTR_LAB_00669810;
  extraout_ECX[0x18] = &PTR_LAB_00669804;
  puVar1 = (undefined4 *)extraout_ECX[0x2a];
  *(undefined4 *)(unaff_EBP + -4) = 7;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
    extraout_ECX[0x2a] = 0;
  }
  FUN_0055c1b3();
  FUN_00562093();
  FUN_0042004f();
  if (extraout_ECX[0x3e] != 0) {
    *(uint *)(unaff_EBP + -0x10) = CONCAT22(extraout_var,*(undefined2 *)((int)extraout_ECX + 0xf6));
  }
  FUN_005a55ea();
  FUN_005a9410();
  FUN_004df937();
  FUN_004d6372();
  if ((int *)extraout_ECX[0x3a] != (int *)0x0) {
    (**(code **)(*(int *)extraout_ECX[0x3a] + 0x18))(1);
    extraout_ECX[0x3a] = 0;
  }
  if (DAT_006f2a0c != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_006f2a0c + 0x10))();
    if (iVar2 != 0) {
      (**(code **)(*DAT_006f2a0c + 8))();
    }
    if (DAT_006f2a0c != (int *)0x0) {
      (**(code **)(*DAT_006f2a0c + 0x14))(1);
    }
    DAT_006f2a0c = (int *)0x0;
  }
  CoUninitialize();
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 3;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 1;
  FUN_005b8770();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0040763c();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005edb43();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

