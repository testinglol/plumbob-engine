
uint FUN_00562b2e(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined1 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  uVar5 = FUN_00634c24();
  if (*(int **)(extraout_ECX + 0x5c) != (int *)0x0) {
    uVar5 = (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x20))(1);
    if ((char)uVar5 != '\0') {
      uVar4 = FUN_0042a8d9(unaff_EBP + -0x24,10);
      (*(code *)PTR_FUN_006d7008)(uVar4);
      uVar6 = FUN_005d4956(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -0x10) = uVar6;
      piVar1 = *(int **)(extraout_ECX + 0xe8);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar2 = *piVar1;
      uVar6 = FUN_005d49d6();
      uVar6 = FUN_004096c2(uVar6);
      (**(code **)(iVar2 + 0x50))(unaff_EBP + -0x4c,uVar6);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      iVar3 = *(int *)(extraout_ECX + 0xe4);
      iVar2 = (*(int *)(iVar3 + 0x1c) - *(int *)(iVar3 + 0x14)) / 2 + -1 + DAT_006f5a98;
      iVar3 = (*(int *)(iVar3 + 0x20) - *(int *)(iVar3 + 0x18)) / 2 + -1 + DAT_006f5a9c;
      FUN_005d4956(unaff_EBP + -0x24);
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *(int *)(unaff_EBP + -0x10) =
           iVar3 - (*(int *)(unaff_EBP + -0x40) - *(int *)(unaff_EBP + -0x48)) / 2;
      uVar6 = *(undefined4 *)(extraout_ECX + 0x5c);
      *(int *)(unaff_EBP + -0x14) =
           iVar2 - (*(int *)(unaff_EBP + -0x44) - *(int *)(unaff_EBP + -0x4c)) / 2;
      piVar1 = *(int **)(extraout_ECX + 0xe8);
      *(undefined4 *)(unaff_EBP + -0x18) = uVar6;
      iVar2 = *piVar1;
      uVar6 = FUN_005d49d6(0,0,0);
      uVar6 = FUN_004096c2(uVar6);
      (**(code **)(iVar2 + 0x78))
                (*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14),
                 *(undefined4 *)(unaff_EBP + -0x10),uVar6);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_005b8770();
      uVar5 = (**(code **)(**(int **)(extraout_ECX + 0x5c) + 0x24))(1);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar5 & 0xffffff00;
}

