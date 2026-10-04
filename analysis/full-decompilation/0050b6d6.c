
int FUN_0050b6d6(void)

{
  int *piVar1;
  size_t sVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int unaff_EBP;
  int iVar6;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x14) = extraout_ECX;
  FUN_005d48d9();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0047343b(0,0);
  iVar5 = *(int *)(unaff_EBP + 8);
  *(undefined4 *)(extraout_ECX + 0x44) = *(undefined4 *)(unaff_EBP + 0xc);
  *(undefined4 *)(extraout_ECX + 0x10) = 0;
  *(undefined4 *)(extraout_ECX + 0x14) = 0;
  *(undefined4 *)(extraout_ECX + 0x18) = 0;
  *(undefined4 *)(extraout_ECX + 0x1c) = 0;
  *(undefined4 *)(extraout_ECX + 0x20) = 0;
  *(undefined4 *)(extraout_ECX + 0x24) = *(undefined4 *)(extraout_ECX + 0x14);
  *(undefined4 *)(extraout_ECX + 0x28) = *(undefined4 *)(extraout_ECX + 0x18);
  uVar4 = *(undefined4 *)(extraout_ECX + 0x1c);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(extraout_ECX + 0x2c) = uVar4;
  if (iVar5 != 0) {
    sVar2 = _strlen(*(char **)(unaff_EBP + 8));
    if (sVar2 != 0) {
      FUN_005d4bbf(*(undefined4 *)(unaff_EBP + 8));
      piVar1 = DAT_006f35fc;
      iVar5 = *(int *)(extraout_ECX + 4);
      iVar6 = (*(int *)(extraout_ECX + 8) - iVar5) + iVar5;
      *(int *)(unaff_EBP + 8) = iVar5;
      iVar5 = 0;
      iVar3 = (**(code **)(*piVar1 + 100))
                        (*(undefined4 *)(unaff_EBP + 8),iVar6 - *(int *)(unaff_EBP + 8),32000);
      *(int *)(extraout_ECX + 0x40) = iVar3;
      if (0 < iVar3) {
        *(int *)(unaff_EBP + 0xc) = iVar3;
        do {
          iVar3 = (**(code **)(*DAT_006f35fc + 0x58))();
          *(int *)(extraout_ECX + 0x1c) = *(int *)(extraout_ECX + 0x1c) + iVar3;
          uVar4 = (**(code **)(*DAT_006f35fc + 0x60))
                            (*(undefined4 *)(unaff_EBP + 8),iVar6 - *(int *)(unaff_EBP + 8),32000);
          piVar1 = DAT_006f35fc;
          *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
          iVar3 = (**(code **)(*piVar1 + 0x68))(*(undefined4 *)(unaff_EBP + 8),uVar4);
          if (iVar5 < iVar3) {
            iVar5 = iVar3;
          }
          *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + -0x10);
          piVar1 = (int *)(unaff_EBP + 0xc);
          *piVar1 = *piVar1 + -1;
        } while (*piVar1 != 0);
      }
      *(int *)(extraout_ECX + 0x18) = iVar5;
      goto LAB_0050b7f7;
    }
  }
  FUN_005d4bbf(&DAT_006de560);
  *(undefined4 *)(extraout_ECX + 0x40) = 1;
LAB_0050b7f7:
  FUN_0050ad4b(0);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

