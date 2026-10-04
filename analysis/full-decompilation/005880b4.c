
void FUN_005880b4(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *extraout_ECX;
  int unaff_EBP;
  uint uVar7;
  
  FUN_00634c24();
  *(undefined4 **)(unaff_EBP + -0x18) = extraout_ECX;
  *extraout_ECX = &PTR_LAB_00671ee4;
  *(undefined4 *)(unaff_EBP + -4) = 4;
  FUN_00588232();
  iVar5 = FUN_005a5e72();
  if (iVar5 != 0) {
    puVar6 = (undefined4 *)FUN_00401f6f();
    if (puVar6 == extraout_ECX) {
      FUN_004621c0();
    }
  }
  if (DAT_006f6b5c == extraout_ECX[0x4e]) {
    FUN_00586fdc(0);
  }
  iVar5 = extraout_ECX[0x96];
  if (iVar5 != 0) {
    FUN_005836d2();
    FUN_006321f0(iVar5);
  }
  extraout_ECX[0x96] = 0;
  FUN_00588d45();
  piVar1 = extraout_ECX + 0x9a;
  uVar7 = 0;
  if (extraout_ECX[0x9b] - *piVar1 >> 2 != 0) {
    do {
      iVar5 = *(int *)(*piVar1 + uVar7 * 4);
      *(int *)(unaff_EBP + -0x10) = iVar5;
      if (iVar5 != 0) {
        FUN_005836d2();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x10));
      }
      *(undefined4 *)(*piVar1 + uVar7 * 4) = 0;
      uVar7 = uVar7 + 1;
    } while (uVar7 < (uint)(extraout_ECX[0x9b] - *piVar1 >> 2));
  }
  iVar5 = extraout_ECX[0x98];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  piVar2 = extraout_ECX + 0x97;
  if (iVar5 - extraout_ECX[0x97] >> 2 != 0) {
    do {
      iVar5 = *(int *)(*piVar2 + *(int *)(unaff_EBP + -0x10) * 4);
      *(int *)(unaff_EBP + -0x14) = iVar5;
      if (iVar5 != 0) {
        FUN_005836d2();
        FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x14));
      }
      *(undefined4 *)(*piVar2 + *(int *)(unaff_EBP + -0x10) * 4) = 0;
      iVar5 = extraout_ECX[0x98];
      iVar3 = *piVar2;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(uint *)(unaff_EBP + -0x10) < (uint)(iVar5 - iVar3 >> 2));
  }
  uVar4 = extraout_ECX[0x9d];
  *(undefined1 *)(unaff_EBP + -4) = 3;
  *(undefined4 *)(unaff_EBP + -0x14) = uVar4;
  FUN_0048c4c9();
  iVar5 = *piVar1;
  *(undefined1 *)(unaff_EBP + -4) = 2;
  *(int *)(unaff_EBP + -0x14) = iVar5;
  FUN_0048c4c9();
  iVar5 = *piVar2;
  *(undefined1 *)(unaff_EBP + -4) = 1;
  *(int *)(unaff_EBP + -0x14) = iVar5;
  FUN_0048c4c9();
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005c4890();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_00584a60();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

