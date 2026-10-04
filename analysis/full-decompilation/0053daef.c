
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_0053daef(void)

{
  char *pcVar1;
  char *pcVar2;
  int *piVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  char cVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  char cVar11;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar8 = *(int *)(unaff_EBP + 8) - *(int *)(extraout_ECX + 0x14) & 3;
  *(uint *)(unaff_EBP + -0x1c) = uVar8;
  if (uVar8 != 0) {
    pcVar1 = (char *)(extraout_ECX + 4);
    FUN_00434ffd(uVar8);
    pcVar2 = (char *)(extraout_ECX + 7);
    FUN_00434ffd(*(undefined4 *)(unaff_EBP + -0x1c));
    cVar7 = '\0';
    cVar11 = '\0';
    *(undefined1 *)(unaff_EBP + -0x1e) = 0;
    *(undefined1 *)(unaff_EBP + -0x20) = 0;
    *(undefined1 *)(unaff_EBP + -0x1f) = 0;
    iVar6 = *(int *)(unaff_EBP + -0x1c);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    if (iVar6 == 1) {
      FUN_00461b74(&DAT_006e4825);
      cVar7 = *(char *)(unaff_EBP + -0x18);
      cVar11 = *(char *)(unaff_EBP + -0x17);
    }
    else if (iVar6 == 2) {
      FUN_00461b74(&DAT_006e482b);
      cVar7 = *(char *)(unaff_EBP + -0x14);
      cVar11 = *(char *)(unaff_EBP + -0x13);
    }
    else if (iVar6 == 3) {
      FUN_00461b74(&DAT_006e481f);
      cVar7 = *(char *)(unaff_EBP + -0x10);
      cVar11 = *(char *)(unaff_EBP + -0xf);
    }
    *pcVar1 = *pcVar1 + cVar7;
    *(char *)(extraout_ECX + 5) = *(char *)(extraout_ECX + 5) + cVar11;
    *pcVar2 = *pcVar2 + cVar7;
    iVar6 = *(int *)(unaff_EBP + -0x1c);
    *(char *)(extraout_ECX + 8) = *(char *)(extraout_ECX + 8) + cVar11;
    *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    if ((0 < iVar6) &&
       (*(undefined1 *)(extraout_ECX + 0x1c) =
             (&DAT_006f4b20)[(uint)*(byte *)(extraout_ECX + 0x1c) + iVar6 * 0x100], 0 < iVar6)) {
      *(undefined1 *)(extraout_ECX + 0x1d) =
           (&DAT_006f4b20)[(uint)*(byte *)(extraout_ECX + 0x1d) + iVar6 * 0x100];
    }
    cVar7 = FUN_0044058c(pcVar1);
    if (cVar7 != '\0') {
      cVar7 = *pcVar2;
      uVar4 = *(undefined1 *)(extraout_ECX + 8);
      uVar5 = *(undefined1 *)(extraout_ECX + 9);
      *(char *)(unaff_EBP + -0x1c) = cVar7;
      *(undefined1 *)(unaff_EBP + -0x1b) = uVar4;
      *(undefined1 *)(unaff_EBP + -0x1a) = uVar5;
      cVar11 = *pcVar1;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *pcVar2 = cVar11;
      *(undefined1 *)(extraout_ECX + 8) = *(undefined1 *)(extraout_ECX + 5);
      *(undefined1 *)(extraout_ECX + 9) = *(undefined1 *)(extraout_ECX + 6);
      *pcVar1 = cVar7;
      uVar5 = *(undefined1 *)(unaff_EBP + -0x1a);
      *(undefined1 *)(extraout_ECX + 5) = uVar4;
      *(undefined1 *)(extraout_ECX + 6) = uVar5;
      uVar10 = *(undefined4 *)(extraout_ECX + 0x24);
      *(undefined4 *)(extraout_ECX + 0x24) = *(undefined4 *)(extraout_ECX + 0x20);
      *(undefined4 *)(extraout_ECX + 0x20) = uVar10;
      FUN_0053d900();
      piVar3 = (int *)(*(int *)(extraout_ECX + 0x24) + 0x20);
      *piVar3 = *piVar3 + 1;
      uVar4 = *(undefined1 *)(extraout_ECX + 0x1c);
      *(undefined1 *)(extraout_ECX + 0x1c) = *(undefined1 *)(extraout_ECX + 0x1d);
      *(undefined1 *)(extraout_ECX + 0x1d) = uVar4;
      FUN_00540332(*(undefined4 *)(extraout_ECX + 0x30),*(undefined4 *)(extraout_ECX + 0x34));
      iVar9 = *(int *)(extraout_ECX + 0x30);
      iVar6 = *(int *)(extraout_ECX + 0x34);
      *(int *)(unaff_EBP + -0x14) = iVar9;
      if (iVar9 != iVar6) {
        iVar9 = iVar9 + 2;
        *(int *)(unaff_EBP + -0x18) = iVar9;
        while( true ) {
          FUN_0054031b(iVar9,iVar9 + 2);
          *(int *)(unaff_EBP + -0x14) = *(int *)(unaff_EBP + -0x14) + 6;
          *(int *)(unaff_EBP + -0x18) = *(int *)(unaff_EBP + -0x18) + 6;
          if (*(int *)(unaff_EBP + -0x14) == *(int *)(extraout_ECX + 0x34)) break;
          iVar9 = *(int *)(unaff_EBP + -0x18);
        }
      }
      FUN_00540359(extraout_ECX + 0x28,extraout_ECX + 0x2c);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
    }
    uVar10 = FUN_0053f390(pcVar1,pcVar2);
    *(undefined4 *)(extraout_ECX + 0x10) = uVar10;
    uVar10 = FUN_0053dcf6(uVar10,0);
    *(undefined4 *)(unaff_EBP + -4) = 2;
    FUN_00461b74(uVar10);
    switch(*(undefined4 *)(extraout_ECX + 0x10)) {
    case 0:
    case 3:
    case 4:
    case 5:
    case 6:
      *(undefined4 *)(extraout_ECX + 0x18) = 0;
      break;
    case 1:
    case 2:
    case 7:
      *(undefined4 *)(extraout_ECX + 0x18) = 1;
    }
    *(undefined4 *)(extraout_ECX + 0x14) = *(undefined4 *)(unaff_EBP + 8);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

