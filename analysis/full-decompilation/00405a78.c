
void FUN_00405a78(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int *extraout_ECX;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe8;
  puVar5 = (undefined4 *)extraout_ECX[1];
  if (puVar5 == (undefined4 *)extraout_ECX[2]) {
    iVar8 = (int)puVar5 - *extraout_ECX >> 2;
    if (iVar8 == 0) {
      *(undefined4 *)(unaff_EBP + -0x14) = 1;
      iVar8 = *(int *)(unaff_EBP + -0x14);
    }
    else {
      iVar8 = iVar8 * 2;
      *(int *)(unaff_EBP + -0x14) = iVar8;
    }
    if (iVar8 == 0) {
      iVar8 = 0;
    }
    else {
      iVar8 = FUN_00401742(iVar8 << 2);
    }
    iVar4 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    *(int *)(unaff_EBP + -0x18) = iVar8;
    puVar5 = (undefined4 *)
             FUN_00406200(iVar4,*(undefined4 *)(unaff_EBP + 8),iVar8,*(undefined4 *)(unaff_EBP + 8),
                          0);
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = **(undefined4 **)(unaff_EBP + 0xc);
    }
    iVar6 = FUN_00406200(*(undefined4 *)(unaff_EBP + 8),extraout_ECX[1],puVar5 + 1,
                         *(undefined4 *)(unaff_EBP + 8),0);
    iVar4 = *extraout_ECX;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    iVar7 = extraout_ECX[2] - iVar4 >> 2;
    if (iVar7 != 0) {
      FUN_0040189d(iVar4,iVar7 << 2);
    }
    iVar4 = *(int *)(unaff_EBP + -0x14);
    *extraout_ECX = iVar8;
    extraout_ECX[1] = iVar6;
    extraout_ECX[2] = iVar8 + iVar4 * 4;
  }
  else {
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = puVar5[-1];
    }
    extraout_ECX[1] = extraout_ECX[1] + 4;
    iVar8 = extraout_ECX[1] + -8;
    puVar5 = (undefined4 *)(extraout_ECX[1] + -4);
    uVar2 = **(undefined4 **)(unaff_EBP + 0xc);
    puVar3 = *(undefined4 **)(unaff_EBP + 8);
    iVar4 = iVar8 - (int)puVar3 >> 2;
    if (0 < iVar4) {
      do {
        puVar1 = (undefined4 *)(iVar8 + -4);
        iVar8 = iVar8 + -4;
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

