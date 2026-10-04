
void FUN_005d0d0e(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *extraout_ECX;
  undefined4 *puVar5;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = &PTR_FUN_0067354c;
  puVar5 = (undefined4 *)extraout_ECX[0x3b];
  puVar1 = (undefined4 *)extraout_ECX[0x3c];
  *(undefined4 *)(unaff_EBP + -4) = 6;
  if (puVar5 != puVar1) {
    do {
      FUN_005cfd7a(*puVar5);
      puVar5 = puVar5 + 1;
    } while (puVar5 != (undefined4 *)extraout_ECX[0x3c]);
  }
  FUN_0040812f(extraout_ECX[0x32],extraout_ECX[0x33]);
  iVar2 = extraout_ECX[0x36];
  iVar3 = extraout_ECX[0x35];
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  if ((iVar2 - iVar3) / 0xc != 0) {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    do {
      puVar5 = (undefined4 *)(*(int *)(unaff_EBP + -0x10) + extraout_ECX[0x35]);
      FUN_005bd82a(*puVar5,puVar5[1]);
      iVar2 = extraout_ECX[0x36];
      iVar3 = extraout_ECX[0x35];
      *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 0xc;
    } while (*(uint *)(unaff_EBP + -0x14) < (uint)((iVar2 - iVar3) / 0xc));
  }
  uVar4 = extraout_ECX[0x3b];
  *(undefined1 *)(unaff_EBP + -4) = 4;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
  FUN_0048c4c9();
  uVar4 = extraout_ECX[0x38];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
  FUN_00542b02();
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005d1537();
  uVar4 = extraout_ECX[0x32];
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
  FUN_00407c07();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c5720();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005d47fc();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

