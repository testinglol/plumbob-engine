
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_004213c0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *extraout_ECX;
  undefined4 *puVar4;
  int unaff_EBP;
  int iVar5;
  
  FUN_00634c24();
  *(int **)(unaff_EBP + -0x10) = extraout_ECX;
  FUN_004215b6();
  uVar3 = _DAT_00666a60;
  iVar1 = *(int *)(unaff_EBP + 8);
  iVar5 = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = _DAT_00666a60;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar3;
  uVar3 = _DAT_0066674c;
  extraout_ECX[0x2f] = iVar1;
  *(undefined4 *)(unaff_EBP + -0x20) = uVar3;
  iVar2 = extraout_ECX[1];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar3;
  extraout_ECX[0x30] = iVar1 + 0x78c;
  *(undefined4 *)(unaff_EBP + 8) = 0;
  if (0 < iVar2) {
    puVar4 = &DAT_006c23f4;
    do {
      *(undefined4 *)(iVar5 + 0x10 + *extraout_ECX) = *puVar4;
      FUN_0046146f(4);
      FUN_004614cd(unaff_EBP + -0x18);
      FUN_004614cd(unaff_EBP + -0x20);
      *(int *)(unaff_EBP + 8) = *(int *)(unaff_EBP + 8) + 1;
      puVar4 = puVar4 + 1;
      iVar5 = iVar5 + 0x14;
    } while (*(int *)(unaff_EBP + 8) < extraout_ECX[1]);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return extraout_ECX;
}

