
/* WARNING (jumptable): Unable to track spacebase fully for stack */

void FUN_004949f0(void)

{
  char cVar1;
  char cVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  int iVar13;
  int unaff_EBP;
  bool bVar14;
  
  FUN_00634c24();
  pcVar4 = *(char **)(unaff_EBP + 0xc);
  pcVar5 = *(char **)(unaff_EBP + 8);
  FUN_0044f2cf(unaff_EBP + -0x58,pcVar5);
  cVar9 = pcVar5[2];
  uVar6 = *(undefined4 *)(unaff_EBP + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  pcVar4[2] = cVar9;
  switch(uVar6) {
  case 0:
  case 1:
    FUN_00461b74(&DAT_006e4822);
    *(undefined1 *)(unaff_EBP + -0x2e) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 1;
    pcVar12 = (char *)FUN_00494e66(unaff_EBP + -0x40,(int)*(char *)(unaff_EBP + -0x58),
                                   unaff_EBP + -0x30);
    *pcVar4 = *pcVar4 + *pcVar12;
    pcVar4[1] = pcVar4[1] + pcVar12[1];
    cVar1 = *(char *)(unaff_EBP + -0x57);
    if (cVar1 < '\x01') {
code_r0x00494a74:
      if ((-1 < cVar1) || (*(int *)(unaff_EBP + 0x10) != 1)) goto LAB_00494e09;
    }
    else if (*(int *)(unaff_EBP + 0x10) != 0) {
      cVar1 = *(char *)(unaff_EBP + -0x57);
      goto code_r0x00494a74;
    }
    pcVar4[1] = pcVar5[1];
    break;
  case 2:
  case 3:
    FUN_00461b74(&DAT_006e481c);
    *(undefined1 *)(unaff_EBP + -0x32) = 0;
    *(undefined1 *)(unaff_EBP + -4) = 2;
    pcVar12 = (char *)FUN_00494e66(unaff_EBP + -0x44,(int)*(char *)(unaff_EBP + -0x57),
                                   unaff_EBP + -0x34);
    *pcVar4 = *pcVar4 + *pcVar12;
    pcVar4[1] = pcVar4[1] + pcVar12[1];
    cVar1 = *(char *)(unaff_EBP + -0x58);
    bVar14 = cVar1 < '\0';
    if (bVar14) {
      if (*(int *)(unaff_EBP + 0x10) != 3) {
        cVar1 = *(char *)(unaff_EBP + -0x58);
        bVar14 = cVar1 < '\0';
        goto code_r0x00494ad3;
      }
    }
    else {
code_r0x00494ad3:
      if ((cVar1 == '\0' || bVar14) || (*(int *)(unaff_EBP + 0x10) != 2)) goto LAB_00494e09;
    }
    cVar1 = *pcVar5;
    pcVar4[1] = pcVar4[1];
    *pcVar4 = cVar1;
    break;
  case 4:
  case 5:
    cVar9 = pcVar4[1];
    cVar1 = *pcVar4;
    cVar2 = *pcVar5;
    cVar3 = pcVar5[1];
    *(char *)(unaff_EBP + 0xb) = cVar2;
    if (((~(cVar1 - cVar9) ^ cVar2 - cVar3) & 1U) == 0) {
      cVar1 = *pcVar5;
      iVar13 = (int)*pcVar4;
      iVar10 = (int)cVar9;
      *(int *)(unaff_EBP + 8) = (int)cVar1;
      *(int *)(unaff_EBP + 0xc) = (int)cVar3;
      if (iVar13 - iVar10 < (int)cVar1 - (int)cVar3) {
        iVar11 = *(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0xc);
        if (iVar11 < iVar10 + iVar13) {
          FUN_00461b74(&DAT_006e481f);
          *(undefined1 *)(unaff_EBP + -0x16) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + -0x18);
          cVar9 = *(char *)(unaff_EBP + -0x17);
        }
        else {
          if (iVar11 <= iVar10 + iVar13) goto code_r0x00494d46;
          FUN_00461b74(&DAT_006e4822);
          *(undefined1 *)(unaff_EBP + -0x1a) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + -0x1c);
          cVar9 = *(char *)(unaff_EBP + -0x1b);
        }
      }
      else {
        iVar11 = *(int *)(unaff_EBP + 8) + *(int *)(unaff_EBP + 0xc);
        if (iVar11 < iVar10 + iVar13) {
          FUN_00461b74(&DAT_006e4825);
          *(undefined1 *)(unaff_EBP + -0x1e) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + -0x20);
          cVar9 = *(char *)(unaff_EBP + -0x1f);
        }
        else {
          if (iVar11 <= iVar10 + iVar13) goto code_r0x00494d46;
          FUN_00461b74(&DAT_006e481c);
          *(undefined1 *)(unaff_EBP + -0x22) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + -0x24);
          cVar9 = *(char *)(unaff_EBP + -0x23);
        }
      }
      pcVar4[1] = pcVar4[1] + cVar9;
    }
code_r0x00494d46:
    iVar10 = FUN_00636bef((((int)*pcVar4 - (int)pcVar4[1]) - (int)*pcVar5) + (int)pcVar5[1]);
    uVar8 = DAT_006e4831;
    uVar7 = DAT_006e482e;
    if (iVar10 / 2 != 0) {
      if ((int)*pcVar4 - (int)pcVar4[1] < (int)*pcVar5 - (int)pcVar5[1]) {
        *(undefined1 *)(unaff_EBP + -0x26) = 0;
        *(undefined1 *)(unaff_EBP + -0x28) = uVar7;
        *(undefined1 *)(unaff_EBP + -0x27) = DAT_006e482f;
        iVar13 = unaff_EBP + -0x50;
        *(undefined1 *)(unaff_EBP + -4) = 5;
      }
      else {
        *(undefined1 *)(unaff_EBP + -0x2a) = 0;
        *(undefined1 *)(unaff_EBP + -0x2c) = uVar8;
        *(undefined1 *)(unaff_EBP + -0x2b) = DAT_006e4832;
        iVar13 = unaff_EBP + -0x54;
        *(undefined1 *)(unaff_EBP + -4) = 6;
      }
      pcVar12 = (char *)func_0x00494e3a(iVar13,iVar10 / 2);
      *pcVar4 = *pcVar4 + *pcVar12;
      pcVar4[1] = pcVar4[1] + pcVar12[1];
    }
    iVar10 = (int)*pcVar5 + (int)pcVar5[1];
    if (((iVar10 < (int)*pcVar4 + (int)pcVar4[1]) && (*(int *)(unaff_EBP + 0x10) == 4)) ||
       (((int)*pcVar4 + (int)pcVar4[1] < iVar10 && (*(int *)(unaff_EBP + 0x10) == 5)))) {
      *pcVar4 = *pcVar5;
      pcVar4[1] = pcVar5[1];
      pcVar4[2] = pcVar5[2];
    }
    goto LAB_00494e09;
  case 6:
  case 7:
    cVar9 = pcVar5[1];
    if (((~(pcVar4[1] + *pcVar4) ^ *pcVar5 + cVar9) & 1U) == 0) {
      cVar1 = *pcVar5;
      iVar13 = (int)*pcVar4;
      iVar10 = (int)pcVar4[1];
      *(int *)(unaff_EBP + 8) = (int)cVar1;
      *(int *)(unaff_EBP + 0xc) = (int)cVar9;
      if (iVar13 + iVar10 < (int)cVar1 + (int)cVar9) {
        iVar11 = *(int *)(unaff_EBP + 8) - *(int *)(unaff_EBP + 0xc);
        if (iVar11 < iVar13 - iVar10) {
          FUN_00461b74(&DAT_006e481c);
          *(undefined1 *)(unaff_EBP + 10) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + 8);
          cVar9 = *(char *)(unaff_EBP + 9);
        }
        else {
          if (iVar11 <= iVar13 - iVar10) goto code_r0x00494bb3;
          FUN_00461b74(&DAT_006e4822);
          *(undefined1 *)(unaff_EBP + 0xe) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + 0xc);
          cVar9 = *(char *)(unaff_EBP + 0xd);
        }
      }
      else {
        iVar11 = *(int *)(unaff_EBP + 8) - *(int *)(unaff_EBP + 0xc);
        if (iVar11 < iVar13 - iVar10) {
          FUN_00461b74(&DAT_006e4825);
          *(undefined1 *)(unaff_EBP + -0xe) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + -0x10);
          cVar9 = *(char *)(unaff_EBP + -0xf);
        }
        else {
          if (iVar11 <= iVar13 - iVar10) goto code_r0x00494bb3;
          FUN_00461b74(&DAT_006e481f);
          *(undefined1 *)(unaff_EBP + -0x12) = 0;
          *pcVar4 = *pcVar4 + *(char *)(unaff_EBP + -0x14);
          cVar9 = *(char *)(unaff_EBP + -0x13);
        }
      }
      pcVar4[1] = pcVar4[1] + cVar9;
    }
code_r0x00494bb3:
    iVar10 = FUN_00636bef((((int)pcVar4[1] - (int)*pcVar5) - (int)pcVar5[1]) + (int)*pcVar4);
    if (iVar10 / 2 != 0) {
      if ((int)pcVar4[1] + (int)*pcVar4 < (int)*pcVar5 + (int)pcVar5[1]) {
        FUN_00461b74(&DAT_006e482b);
        *(undefined1 *)(unaff_EBP + -0x36) = 0;
        iVar13 = unaff_EBP + -0x48;
        *(undefined1 *)(unaff_EBP + -4) = 3;
      }
      else {
        FUN_00461b74(&DAT_006e4828);
        *(undefined1 *)(unaff_EBP + -0x3a) = 0;
        iVar13 = unaff_EBP + -0x4c;
        *(undefined1 *)(unaff_EBP + -4) = 4;
      }
      pcVar12 = (char *)func_0x00494e3a(iVar13,iVar10 / 2);
      *pcVar4 = *pcVar4 + *pcVar12;
      pcVar4[1] = pcVar4[1] + pcVar12[1];
    }
    cVar9 = *pcVar5;
    *(int *)(unaff_EBP + 8) = (int)*pcVar4 - (int)pcVar4[1];
    cVar1 = pcVar5[1];
    iVar11 = (int)cVar9 - (int)cVar1;
    iVar10 = *(int *)(unaff_EBP + 8);
    iVar13 = iVar10 - iVar11;
    if (iVar10 < iVar11) {
      if (*(int *)(unaff_EBP + 0x10) != 6) {
        iVar10 = *(int *)(unaff_EBP + 8);
        iVar13 = iVar10 - iVar11;
        goto code_r0x00494c5f;
      }
    }
    else {
code_r0x00494c5f:
      if ((iVar10 == iVar11 || SBORROW4(iVar10,iVar11) != iVar13 < 0) ||
         (*(int *)(unaff_EBP + 0x10) != 7)) goto LAB_00494e09;
    }
    cVar2 = pcVar5[2];
    *pcVar4 = cVar9;
    pcVar4[1] = cVar1;
    pcVar4[2] = cVar2;
  default:
    goto LAB_00494e09;
  }
  pcVar4[2] = cVar9;
LAB_00494e09:
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

