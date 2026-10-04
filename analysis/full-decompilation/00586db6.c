
undefined4 FUN_00586db6(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  int unaff_EBP;
  undefined4 uVar6;
  
  FUN_00634c24();
  if (*(int *)(unaff_EBP + 0xc) != 0) {
    iVar2 = FUN_005972be();
    if (iVar2 != 0) {
      piVar1 = *(int **)(unaff_EBP + 8);
      *(int *)(unaff_EBP + 8) = *piVar1;
      (**(code **)(*extraout_ECX + 0x104))(piVar1);
      *(undefined4 *)(unaff_EBP + -0x10) = 0x3f800000;
      if (*(int *)(unaff_EBP + 0x10) == 0) {
        *(undefined4 *)(unaff_EBP + 8) = 0x3f800000;
      }
      else {
        *(undefined4 *)(unaff_EBP + 8) = 0xbf800000;
      }
      uVar4 = (**(code **)(*extraout_ECX + 0x34))();
      iVar2 = unaff_EBP + -0x10;
      iVar5 = unaff_EBP + 8;
      uVar6 = 1;
      uVar3 = *(undefined4 *)(unaff_EBP + 0xc);
      (**(code **)(*extraout_ECX + 0xac))(uVar3,1,iVar5,iVar2,uVar4);
      iVar2 = FUN_005a08e3(uVar3,uVar6,iVar5,iVar2,uVar4);
      uVar3 = DAT_006d043c;
      *piVar1 = iVar2;
      *(undefined4 *)(iVar2 + 0x5c) = uVar3;
      iVar5 = (**(code **)(*extraout_ECX + 0xac))();
      *(undefined4 *)(unaff_EBP + 8) = *(undefined4 *)(iVar5 + 4);
      FUN_005b870f(&DAT_006c45a4);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar3 = FUN_0059783a(unaff_EBP + -0x1c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 0xc) = uVar3;
      FUN_005b8770();
      iVar5 = FUN_00599121(0);
      *(int *)(unaff_EBP + 8) = iVar5;
      if (((piVar1 == extraout_ECX + 3) && (iVar5 != 0)) && (*(int *)(unaff_EBP + 0xc) != 0)) {
        uVar3 = FUN_00596b7c(0);
        FUN_0049b849(unaff_EBP + -0x28,uVar3,*(int *)(unaff_EBP + 8) + 0x30);
      }
      if (*(int *)(unaff_EBP + 0x10) != 0) {
        *(undefined4 *)(iVar2 + 0x28) = 0x3f800000;
      }
      *(undefined4 *)(iVar2 + 0x40) = 0;
      uVar3 = 1;
      goto LAB_00586ec9;
    }
  }
  uVar3 = 0;
LAB_00586ec9:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

