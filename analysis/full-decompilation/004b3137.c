
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_004b3137(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char cVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  char cVar9;
  int *unaff_EBX;
  int unaff_EBP;
  int *unaff_ESI;
  bool bVar10;
  
  *(int **)(unaff_EBP + -4) = unaff_EBX;
  FUN_004b04af(*(undefined4 *)(unaff_EBP + 8),*(undefined4 *)(unaff_EBP + 0x38));
  cVar9 = (char)unaff_EBX;
  if (*(char *)((int)unaff_ESI + 0x51) != cVar9) {
    iVar6 = *(int *)(unaff_EBP + 8);
    iVar1 = *(int *)(iVar6 + 0x1c);
    iVar2 = *(int *)(iVar6 + 0x14);
    *(int *)(unaff_EBP + -0x44) = *(int *)(iVar6 + 0x20) - *(int *)(iVar6 + 0x18);
    uVar3 = *(undefined4 *)(unaff_ESI[0x1a] + 0x10);
    *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(unaff_ESI[0x1a] + 0x14);
    iVar4 = unaff_ESI[0x21];
    *(undefined4 *)(unaff_EBP + -0x34) = uVar3;
    *(int *)(unaff_EBP + 0x38) = iVar4;
    cVar5 = FUN_004b0db9(iVar6);
    if (cVar5 != '\0') {
      FUN_005cf06d(iVar1 - iVar2,*(undefined4 *)(unaff_EBP + -0x44));
      FUN_004a7d36();
      iVar6 = unaff_ESI[0x1a];
      bVar10 = DAT_006e4870 != cVar9;
      *(undefined1 *)(unaff_EBP + 0x2f) = *(undefined1 *)(iVar6 + 0x66);
      if (bVar10) {
        *(char *)(iVar6 + 0x66) = cVar9;
      }
      iVar6 = FUN_005ce621(1);
      if (-1 < iVar6) {
        iVar6 = 0;
        do {
          piVar7 = (int *)FUN_00479149(iVar6);
          if (piVar7 != unaff_EBX) {
            FUN_0056eb75(unaff_ESI[0x1a],iVar6 + 1,unaff_EBX,unaff_EBX);
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < 2);
        FUN_005ce67e();
      }
      uVar3 = *(undefined4 *)(unaff_EBP + 0x38);
      *(undefined1 *)(unaff_ESI[0x1a] + 0x66) = *(undefined1 *)(unaff_EBP + 0x2f);
      FUN_004b0db9(uVar3);
      FUN_005cf06d(*(undefined4 *)(unaff_EBP + -0x34),*(undefined4 *)(unaff_EBP + -0x30));
      FUN_004a7d36();
    }
  }
  _DAT_006f0bc0 = *(undefined4 *)(unaff_EBP + -0x50);
  _DAT_006f0bc4 = *(undefined4 *)(unaff_EBP + -0x4c);
  *(undefined1 *)((int)unaff_ESI + 0x51) = *(undefined1 *)(unaff_EBP + -0x1d);
  *(char *)(unaff_ESI + 0x14) = cVar9;
  FUN_004b3938(unaff_EBP + -0xa8);
  DAT_006f0139 = *(undefined1 *)(unaff_EBP + -0x11);
  uVar3 = *(undefined4 *)(unaff_EBP + -0x58);
  *(char *)(unaff_ESI + 0x5f) = cVar9;
  FUN_004c440c(uVar3);
  FUN_004bbabe(1);
  (**(code **)(*unaff_ESI + 0x48))();
  piVar7 = *(int **)(unaff_EBP + 8);
  if (*(ushort *)((int)unaff_ESI + 0x182) == DAT_006f2a64) {
    (**(code **)(*piVar7 + 0x68))((uint)*(ushort *)((int)unaff_ESI + 0x182));
  }
  piVar8 = (int *)FUN_004ba969(*(undefined4 *)(unaff_EBP + 0x20),piVar7);
  if (piVar8 != unaff_EBX) {
    (**(code **)(*piVar8 + 0x68))(piVar7[9]);
  }
  DAT_006e4a84 = *(undefined4 *)(unaff_EBP + -0x54);
  if (*(int **)(unaff_EBP + -0x3c) != unaff_EBX) {
    FUN_006321f0(*(undefined4 *)(unaff_EBP + -0x3c));
  }
  if ((*(int **)(unaff_EBP + 0x34) == unaff_EBX) && (*(int **)(unaff_EBP + 8) != unaff_EBX)) {
    (**(code **)**(int **)(unaff_EBP + 8))(1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return piVar8;
}

