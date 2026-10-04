
void FUN_004718e9(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  puVar4 = (undefined4 *)extraout_ECX[1];
  if (puVar4 == (undefined4 *)extraout_ECX[2]) {
    iVar7 = (int)puVar4 - *extraout_ECX >> 2;
    if (iVar7 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar7 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar7 = iVar7 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar7;
    }
    if (iVar7 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = FUN_00401742(iVar7 << 2);
    }
    iVar3 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    puVar4 = (undefined4 *)
             FUN_00520ae5(iVar3,*(undefined4 *)(unaff_EBP + 8),iVar7,*(undefined4 *)(unaff_EBP + 8))
    ;
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = 0;
    }
    iVar5 = FUN_00520ae5(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar4 + 1,
                         *(undefined4 *)(unaff_EBP + 8));
    iVar3 = extraout_ECX[1];
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    for (iVar6 = *extraout_ECX; iVar6 != iVar3; iVar6 = iVar6 + 4) {
    }
    iVar3 = extraout_ECX[2] - *extraout_ECX >> 2;
    if (iVar3 != 0) {
      FUN_0040189d(*extraout_ECX,iVar3 << 2);
    }
    iVar3 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar7;
    extraout_ECX[1] = iVar5;
    extraout_ECX[2] = iVar7 + iVar3 * 4;
  }
  else {
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = puVar4[-1];
    }
    extraout_ECX[1] = extraout_ECX[1] + 4;
    iVar7 = extraout_ECX[1] + -8;
    puVar4 = (undefined4 *)(extraout_ECX[1] + -4);
    puVar2 = *(undefined4 **)(unaff_EBP + 8);
    iVar3 = iVar7 - (int)puVar2 >> 2;
    if (0 < iVar3) {
      do {
        puVar1 = (undefined4 *)(iVar7 + -4);
        iVar7 = iVar7 + -4;
        puVar4 = puVar4 + -1;
        iVar3 = iVar3 + -1;
        *puVar4 = *puVar1;
      } while (iVar3 != 0);
    }
    *puVar2 = 0;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

