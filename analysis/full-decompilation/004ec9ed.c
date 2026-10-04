
void FUN_004ec9ed(void)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *extraout_ECX;
  int unaff_EBP;
  int iVar4;
  int iVar5;
  
  FUN_00634c24();
  FUN_0055e4e2(unaff_EBP + -0xd);
  iVar4 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004ecee7(unaff_EBP + -0x28);
  piVar1 = extraout_ECX + 0x3c;
  do {
    if (*(int *)(iVar4 + *piVar1) != 0) {
      FUN_005da4c7(*(undefined4 *)(iVar4 + *piVar1));
    }
    iVar4 = iVar4 + 4;
  } while (iVar4 < 0x10);
  FUN_0052ea87(*piVar1,extraout_ECX[0x3d]);
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  iVar4 = *(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2;
  FUN_0054821c(iVar4,unaff_EBP + -0xe);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x34),iVar4,unaff_EBP + -0x18,
                       *(undefined4 *)(unaff_EBP + -0x18));
  *(undefined4 *)(unaff_EBP + -0x30) = uVar2;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_004ed07c(unaff_EBP + -0x34);
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_0048c4c9();
  iVar4 = *(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2;
  if (iVar4 == 0) {
    extraout_ECX[0x46] = 0x10f;
    extraout_ECX[0x45] = 0x4b;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x14) = 0;
    if (iVar4 != 0) {
      do {
        pvVar3 = operator_new(0x370);
        *(void **)(unaff_EBP + -0x1c) = pvVar3;
        *(undefined1 *)(unaff_EBP + -4) = 3;
        if (pvVar3 == (void *)0x0) {
          uVar2 = 0;
        }
        else {
          uVar2 = FUN_004ebbe0();
        }
        iVar4 = *piVar1;
        *(undefined1 *)(unaff_EBP + -4) = 0;
        iVar5 = *(int *)(unaff_EBP + -0x14) * 4;
        *(undefined4 *)(iVar5 + iVar4) = uVar2;
        if (*(int *)(iVar5 + *piVar1) != 0) {
          FUN_004ec013(*(undefined4 *)(iVar5 + *(int *)(unaff_EBP + -0x28)));
          (**(code **)(*extraout_ECX + 0x20))(*(undefined4 *)(iVar5 + *piVar1));
        }
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      } while (*(uint *)(unaff_EBP + -0x14) <
               (uint)(*(int *)(unaff_EBP + -0x24) - *(int *)(unaff_EBP + -0x28) >> 2));
    }
    FUN_004ecd80();
    iVar4 = *(int *)*piVar1;
    extraout_ECX[0x46] = *(int *)(iVar4 + 0x84) - *(int *)(iVar4 + 0x7c);
    iVar4 = *(int *)*piVar1;
    extraout_ECX[0x45] = *(int *)(iVar4 + 0x88) - *(int *)(iVar4 + 0x80);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_0048c4c9();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

