
undefined4 FUN_0059fee5(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar3 = FUN_005b870f(&DAT_006d044c);
  iVar7 = 0;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  uVar4 = FUN_00412ab1(unaff_EBP + -0x30,*(undefined4 *)(unaff_EBP + 8),
                       *(undefined4 *)(unaff_EBP + 0xc));
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar3 = FUN_00412ab1(unaff_EBP + -0x24,uVar4,uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_005b86bd(uVar3);
  *(undefined1 *)(unaff_EBP + -4) = 6;
  FUN_00401729();
  *(undefined1 *)(unaff_EBP + -4) = 5;
  FUN_00401729();
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005b8770();
  uVar3 = *(undefined4 *)(unaff_EBP + -0x18);
  uVar4 = uVar3;
  FUN_005b8e25(uVar3);
  cVar2 = FUN_005b960e(uVar4);
  uVar4 = 1;
  if (cVar2 != '\0') {
    FUN_005b8e25(uVar3);
    iVar5 = FUN_005b936f(uVar3,uVar4);
    if (iVar5 != 0) {
      piVar1 = *(int **)(unaff_EBP + 0x10);
      iVar6 = piVar1[1] - *piVar1 >> 2;
      *(int *)(unaff_EBP + 0xc) = iVar6;
      cVar2 = FUN_005b90ab(iVar6);
      if (cVar2 == '\0') {
LAB_005a0098:
        uVar3 = 1;
      }
      else {
        if (0 < *(int *)(unaff_EBP + 0xc)) {
          do {
            cVar2 = FUN_005b9169(*(undefined4 *)(*(int *)(*piVar1 + iVar7 * 4) + 4));
            if ((cVar2 == '\0') || (cVar2 = FUN_005b9169(0), cVar2 == '\0')) goto LAB_005a0098;
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(unaff_EBP + 0xc));
        }
        piVar1 = *(int **)(unaff_EBP + 0x14);
        iVar7 = piVar1[1] - *piVar1 >> 2;
        *(int *)(unaff_EBP + 0xc) = iVar7;
        FUN_005b90ab(iVar7);
        iVar7 = 0;
        if (0 < *(int *)(unaff_EBP + 0xc)) {
          do {
            cVar2 = FUN_005b9169(*(undefined4 *)(*(int *)(*piVar1 + iVar7 * 4) + 4));
            if ((cVar2 == '\0') || (cVar2 = FUN_005b9169(0), cVar2 == '\0')) goto LAB_005a0098;
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(unaff_EBP + 0xc));
        }
        piVar1 = *(int **)(unaff_EBP + 0x18);
        iVar7 = piVar1[1] - *piVar1 >> 2;
        *(int *)(unaff_EBP + 0xc) = iVar7;
        FUN_005b90ab(iVar7);
        iVar7 = 0;
        if (0 < *(int *)(unaff_EBP + 0xc)) {
          do {
            cVar2 = FUN_005b9169(*(undefined4 *)(*(int *)(*piVar1 + iVar7 * 4) + 4));
            if ((cVar2 == '\0') || (cVar2 = FUN_005b9169(0), cVar2 == '\0')) goto LAB_005a0098;
            iVar7 = iVar7 + 1;
          } while (iVar7 < *(int *)(unaff_EBP + 0xc));
        }
        uVar3 = 0;
      }
      FUN_005b8e25(iVar5);
      FUN_005b95c0(iVar5);
      goto LAB_005a0079;
    }
  }
  uVar3 = 1;
LAB_005a0079:
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar3;
}

