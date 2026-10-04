
void FUN_005db43e(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int *extraout_ECX;
  int iVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe4;
  puVar5 = (undefined4 *)extraout_ECX[1];
  if (puVar5 == (undefined4 *)extraout_ECX[2]) {
    iVar7 = (int)puVar5 - *extraout_ECX >> 2;
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
    iVar4 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar7;
    *(int *)(unaff_EBP + -0x1c) = iVar7;
    puVar5 = (undefined4 *)
             FUN_00520ae5(iVar4,*(undefined4 *)(unaff_EBP + 8),iVar7,*(undefined4 *)(unaff_EBP + 8))
    ;
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = **(undefined4 **)(unaff_EBP + 0xc);
    }
    iVar6 = FUN_00520ae5(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar5 + 1,
                         *(undefined4 *)(unaff_EBP + 8));
    for (iVar4 = *extraout_ECX; iVar4 != extraout_ECX[1]; iVar4 = iVar4 + 4) {
    }
    iVar4 = extraout_ECX[2] - *extraout_ECX >> 2;
    if (iVar4 != 0) {
      FUN_0040189d(*extraout_ECX,iVar4 << 2);
    }
    iVar4 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar7;
    extraout_ECX[1] = iVar6;
    extraout_ECX[2] = iVar7 + iVar4 * 4;
  }
  else {
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = puVar5[-1];
    }
    extraout_ECX[1] = extraout_ECX[1] + 4;
    iVar7 = extraout_ECX[1] + -8;
    puVar5 = (undefined4 *)(extraout_ECX[1] + -4);
    uVar2 = **(undefined4 **)(unaff_EBP + 0xc);
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
    iVar4 = iVar7 - (int)puVar3 >> 2;
    if (0 < iVar4) {
      do {
        puVar1 = (undefined4 *)(iVar7 + -4);
        iVar7 = iVar7 + -4;
        puVar5 = puVar5 + -1;
        iVar4 = iVar4 + -1;
        *puVar5 = *puVar1;
      } while (iVar4 != 0);
    }
    *puVar3 = uVar2;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

