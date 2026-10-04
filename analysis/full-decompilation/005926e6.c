
undefined4 FUN_005926e6(void)

{
  int iVar1;
  undefined4 uVar2;
  int *extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    iVar1 = FUN_005972be();
    if (iVar1 != 0) {
      iVar1 = *extraout_ECX;
      *(undefined4 *)(unaff_EBP + -0x18) = **(undefined4 **)(unaff_EBP + 8);
      (**(code **)(iVar1 + 0x104))(*(undefined4 **)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x14) = 0x3f800000;
      if (*(int *)(unaff_EBP + 0x10) == 0) {
        *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
      }
      else {
        *(undefined4 *)(unaff_EBP + -0x10) = 0xbf800000;
      }
      uVar2 = (**(code **)(*extraout_ECX + 0x34))();
      iVar1 = FUN_005a08e3(*(undefined4 *)(unaff_EBP + 0xc),1,unaff_EBP + -0x10,unaff_EBP + -0x14,
                           uVar2);
      **(int **)(unaff_EBP + 8) = iVar1;
      *(undefined4 *)(iVar1 + 0x5c) = DAT_006d043c;
      FUN_005b870f(&DAT_006c45a4);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar2 = FUN_0059783a(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar2;
      FUN_005b8770();
      uVar2 = FUN_00599121(0);
      *(undefined4 *)(unaff_EBP + 0xc) = uVar2;
      if (((*(int **)(unaff_EBP + 8) == extraout_ECX + 3) && (*(int *)(unaff_EBP + 0xc) != 0)) &&
         (*(int *)(unaff_EBP + -0x18) != 0)) {
        uVar2 = FUN_00596b7c(0);
        FUN_0049b849(unaff_EBP + -0x30,uVar2,*(int *)(unaff_EBP + 0xc) + 0x30);
      }
      if (*(int *)(unaff_EBP + 0x10) != 0) {
        *(undefined4 *)(iVar1 + 0x28) = 0x3f800000;
      }
      *(undefined4 *)(iVar1 + 0x40) = 0;
      if ((*(int **)(unaff_EBP + 8) == extraout_ECX + 3) && (extraout_ECX[0x68] != 0)) {
        extraout_ECX[0x68] = 0;
        FUN_00598687(*(int *)(iVar1 + 0x14) + 5);
        if (extraout_ECX[4] != 0) {
          FUN_005a0903(extraout_ECX[4]);
          extraout_ECX[4] = 0;
        }
        *(undefined4 *)(iVar1 + 0x78) = 0;
        *(undefined4 *)(iVar1 + 0x7c) = 0;
      }
      uVar2 = 1;
      goto LAB_00592829;
    }
  }
  uVar2 = 0;
LAB_00592829:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}

