
void FUN_005d7d77(void)

{
  undefined1 uVar1;
  void *_Dst;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *extraout_ECX;
  uint uVar6;
  uint uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  uint uVar10;
  int unaff_EBP;
  undefined4 *puVar11;
  
  FUN_00634c24();
  uVar7 = *(uint *)(unaff_EBP + 0xc);
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffe0;
  *(int **)(unaff_EBP + -0x1c) = extraout_ECX;
  if (uVar7 != 0) {
    iVar5 = extraout_ECX[1];
    if ((uint)(extraout_ECX[2] - iVar5) < uVar7 + 1) {
      uVar10 = iVar5 - *extraout_ECX;
      piVar3 = (int *)(unaff_EBP + 0xc);
      *(uint *)(unaff_EBP + -0x20) = uVar10;
      if (uVar7 <= uVar10) {
        piVar3 = (int *)(unaff_EBP + -0x20);
      }
      iVar5 = *piVar3 + 1 + uVar10;
      *(int *)(unaff_EBP + -0x14) = iVar5;
      if (iVar5 == 0) {
        *(undefined4 *)(unaff_EBP + 0xc) = 0;
      }
      else {
        uVar4 = FUN_00401742(iVar5);
        *(undefined4 *)(unaff_EBP + 0xc) = uVar4;
      }
      puVar8 = (undefined1 *)*extraout_ECX;
      puVar9 = *(undefined1 **)(unaff_EBP + 0xc);
      *(undefined4 *)(unaff_EBP + -4) = 2;
      for (iVar5 = *(int *)(unaff_EBP + 8) - (int)puVar8; 0 < iVar5; iVar5 = iVar5 + -1) {
        uVar1 = *puVar8;
        puVar8 = puVar8 + 1;
        *puVar9 = uVar1;
        puVar9 = puVar9 + 1;
      }
      for (; uVar7 != 0; uVar7 = uVar7 - 1) {
        *puVar9 = *(undefined1 *)(unaff_EBP + 0x10);
        puVar9 = puVar9 + 1;
      }
      puVar8 = *(undefined1 **)(unaff_EBP + 8);
      for (iVar5 = extraout_ECX[1] - (int)puVar8; 0 < iVar5; iVar5 = iVar5 + -1) {
        uVar1 = *puVar8;
        puVar8 = puVar8 + 1;
        *puVar9 = uVar1;
        puVar9 = puVar9 + 1;
      }
      FUN_00401651(puVar9);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      FUN_00401729();
      iVar5 = *(int *)(unaff_EBP + 0xc);
      iVar2 = *(int *)(unaff_EBP + -0x14);
      *extraout_ECX = iVar5;
      extraout_ECX[1] = (int)puVar9;
      extraout_ECX[2] = iVar5 + iVar2;
    }
    else {
      uVar10 = iVar5 - *(int *)(unaff_EBP + 8);
      iVar5 = extraout_ECX[1];
      *(int *)(unaff_EBP + -0x20) = iVar5;
      *(uint *)(unaff_EBP + -0x14) = uVar10;
      if (uVar10 < uVar7) {
        *(undefined4 **)(unaff_EBP + -0x18) = (undefined4 *)(iVar5 + 1);
        uVar6 = (uVar7 - uVar10) - 1;
        if (uVar6 != 0) {
          uVar1 = *(undefined1 *)(unaff_EBP + 0x10);
          uVar10 = *(uint *)(unaff_EBP + -0x14);
          puVar11 = (undefined4 *)(iVar5 + 1);
          for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *puVar11 = CONCAT22(CONCAT11(uVar1,uVar1),CONCAT11(uVar1,uVar1));
            puVar11 = puVar11 + 1;
          }
          for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
            *(undefined1 *)puVar11 = uVar1;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
          }
          uVar7 = *(uint *)(unaff_EBP + 0xc);
        }
        extraout_ECX[1] = extraout_ECX[1] + (uVar7 - uVar10);
        iVar5 = extraout_ECX[1];
        *(undefined4 *)(unaff_EBP + -4) = 0;
        FUN_004746d5(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + -0x18),iVar5,
                     *(undefined4 *)(unaff_EBP + 0x10),0);
        extraout_ECX[1] = extraout_ECX[1] + uVar10;
        _memset(*(void **)(unaff_EBP + 8),(int)*(char *)(unaff_EBP + 0x10),uVar10 + 1);
      }
      else {
        FUN_004746d5((iVar5 - uVar7) + 1,iVar5 + 1,iVar5 + 1,*(undefined4 *)(unaff_EBP + 0x10),0);
        extraout_ECX[1] = extraout_ECX[1] + uVar7;
        _Dst = *(void **)(unaff_EBP + 8);
        FUN_00635190((int)_Dst + uVar7,_Dst,(uVar10 - uVar7) + 1);
        _memset(_Dst,(int)*(char *)(unaff_EBP + 0x10),uVar7);
      }
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

