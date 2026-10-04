
void FUN_004aa1b9(void)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  int iVar7;
  int iVar8;
  int unaff_EBP;
  
  FUN_00634c24();
  iVar6 = *(int *)(DAT_006e54dc + 0x10);
  sVar1 = *(short *)(extraout_ECX + 0x30);
  iVar7 = (iVar6 + -2) * *(int *)(extraout_ECX + 0x58);
  iVar8 = *(int *)(extraout_ECX + 0x60);
  *(undefined2 *)(unaff_EBP + -0x1c) = *(undefined2 *)(extraout_ECX + 0x34);
  iVar5 = (int)sVar1 - (int)*(short *)(extraout_ECX + 0x28);
  if (iVar5 < iVar7) {
    **(int **)(unaff_EBP + 8) =
         (iVar7 / -2 - *(int *)(extraout_ECX + 0x5c)) + (int)*(short *)(extraout_ECX + 0x30);
    iVar5 = iVar7 / 2 + *(int *)(extraout_ECX + 0x58);
  }
  else {
    iVar5 = iVar5 / 2;
    **(int **)(unaff_EBP + 8) = iVar5;
  }
  iVar7 = 0;
  **(int **)(unaff_EBP + 0xc) = iVar5;
  if (*(int *)(extraout_ECX + 0x1ec) == 0) {
    iVar7 = 0x40 << ((char)DAT_006f0088 + 1U & 0x1f);
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x12) = 0;
    *(undefined1 *)(unaff_EBP + -0x14) = 1;
    *(undefined1 *)(unaff_EBP + -0x13) = 1;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    FUN_004a8000(unaff_EBP + -0x14);
    iVar5 = *(int *)(DAT_006e54dc + 0x10);
    *(undefined4 *)(unaff_EBP + -0x18) = 1;
    if (1 < iVar5 + -1) {
      do {
        iVar5 = ((uint)*(byte *)((int)*(char *)(unaff_EBP + -0x13) +
                                 (int)*(char *)(unaff_EBP + -0x14) + *(int *)(extraout_ECX + 0x1ec))
                << ((char)DAT_006f0088 + 1U & 0x1f)) -
                *(int *)(extraout_ECX + 100) * *(int *)(unaff_EBP + -0x18);
        if (iVar7 < iVar5) {
          iVar7 = iVar5;
        }
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 1;
        FUN_00461b74(&DAT_006e482b);
        *(undefined1 *)(unaff_EBP + -0xe) = 0;
        *(char *)(unaff_EBP + -0x14) = *(char *)(unaff_EBP + -0x14) + *(char *)(unaff_EBP + -0x10);
        *(char *)(unaff_EBP + -0x13) = *(char *)(unaff_EBP + -0x13) + *(char *)(unaff_EBP + -0xf);
      } while (*(int *)(unaff_EBP + -0x18) < *(int *)(DAT_006e54dc + 0x10) + -1);
    }
  }
  iVar5 = 0;
  **(int **)(unaff_EBP + 0x14) = iVar7 + *(int *)(extraout_ECX + (0x4c - DAT_006f0088) * 4) * 2;
  piVar2 = *(int **)(unaff_EBP + 0x10);
  *piVar2 = ((int)*(short *)(unaff_EBP + -0x1c) + *(int *)(extraout_ECX + 0x60) * -2) -
            (iVar6 + -2) * iVar8;
  if (*(int *)(extraout_ECX + 0x1f0) != 0) {
    uVar3 = *(undefined4 *)(DAT_006e54dc + 0x10);
    *(undefined1 *)(unaff_EBP + 0x12) = 0;
    iVar5 = 0x7fffffff;
    cVar4 = (char)uVar3 + -2;
    *(char *)(unaff_EBP + 0x10) = cVar4;
    *(char *)(unaff_EBP + 0x11) = cVar4;
    FUN_004a8000(unaff_EBP + 0x10);
    iVar6 = *(int *)(DAT_006e54dc + 0x10);
    *(undefined4 *)(unaff_EBP + -0x14) = 1;
    if (1 < iVar6 + -1) {
      *(int *)(unaff_EBP + -0x10) = DAT_006f0088 + 1;
      *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(extraout_ECX + 100);
      do {
        iVar6 = *(int *)(unaff_EBP + -0x18) -
                ((uint)*(byte *)((int)*(char *)(unaff_EBP + 0x10) +
                                *(int *)(extraout_ECX + 0x1f0) + (int)*(char *)(unaff_EBP + 0x11))
                << ((byte)*(undefined4 *)(unaff_EBP + -0x10) & 0x1f));
        if (iVar6 < iVar5) {
          iVar5 = iVar6;
        }
        iVar6 = *(int *)(extraout_ECX + 100);
        *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 1;
        *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + iVar6;
        *(char *)(unaff_EBP + 0x10) = *(char *)(unaff_EBP + 0x10) + DAT_006e4828;
        *(char *)(unaff_EBP + 0x11) = *(char *)(unaff_EBP + 0x11) + DAT_006e4829;
      } while (*(int *)(unaff_EBP + -0x14) < *(int *)(DAT_006e54dc + 0x10) + -1);
    }
  }
  *piVar2 = *piVar2 - iVar5;
  *(int *)(extraout_ECX + 500) = iVar5;
  iVar8 = ((int)*(char *)(DAT_006e54d8 + 0x70) - (int)*(char *)(DAT_006e54d8 + 0x78)) *
          *(int *)(extraout_ECX + 0x5c);
  iVar6 = ((int)*(char *)(DAT_006e54d8 + 0x78) + (int)*(char *)(DAT_006e54d8 + 0x70)) *
          *(int *)(extraout_ECX + 100);
  **(int **)(unaff_EBP + 0xc) = **(int **)(unaff_EBP + 0xc) - iVar8;
  **(int **)(unaff_EBP + 8) = **(int **)(unaff_EBP + 8) - iVar8;
  **(int **)(unaff_EBP + 0x14) = **(int **)(unaff_EBP + 0x14) - iVar6;
  *piVar2 = *piVar2 - iVar6;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

