
undefined4 FUN_004ea33f(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  undefined4 uVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar1 = *(int *)(unaff_EBP + 0x10);
  iVar6 = *(int *)(iVar1 + 0xc);
  if (iVar6 == 0) {
LAB_004ea3de:
    uVar8 = 0;
  }
  else {
    puVar2 = *(undefined4 **)(unaff_EBP + 0x18);
    if (*(short *)(*(int *)(iVar6 + 0x118) + 0x12) == 2) {
      iVar6 = FUN_0045741b();
      FUN_005c1719();
      piVar4 = DAT_006f264c;
      piVar3 = DAT_006f2648;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      for (piVar7 = piVar3; piVar7 != piVar4; piVar7 = piVar7 + 0x11) {
        if (*piVar7 == iVar6) {
          iVar6 = ((int)piVar7 - (int)piVar3) / 0x44;
          goto LAB_004ea3a6;
        }
      }
      iVar6 = -1;
LAB_004ea3a6:
      cVar5 = FUN_004e93e4(iVar6,unaff_EBP + 0x10);
      if (cVar5 != '\0') {
        FUN_005a5e1c(unaff_EBP + 0x10);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
LAB_004ea419:
      FUN_005a5e09();
    }
    else {
      iVar6 = FUN_004573f9();
      if (iVar6 == 0) goto LAB_004ea3de;
      if (*(int *)(iVar6 + 0x84) != 0) {
        FUN_005c1719();
        *(undefined4 *)(unaff_EBP + -4) = 1;
        FUN_004ccc2f(unaff_EBP + 0x18);
        FUN_005a5e1c(unaff_EBP + 0x18);
        *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
        goto LAB_004ea419;
      }
    }
    cVar5 = *(char *)(unaff_EBP + 0x14);
    *(char *)((int)puVar2 + 9) = cVar5;
    if (cVar5 == '\0') {
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    else {
      *(bool *)(puVar2 + 2) = *(short *)(*(int *)(unaff_EBP + 0xc) + 0x5da) == 0;
    }
    uVar8 = *(undefined4 *)(unaff_EBP + 8);
    puVar2[3] = iVar1;
    *puVar2 = uVar8;
    uVar8 = CONCAT31((int3)((uint)uVar8 >> 8),1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar8;
}

