
void FUN_0049122d(void)

{
  char cVar1;
  char cVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_ECX;
  byte bVar6;
  byte bVar7;
  int unaff_EBP;
  int iVar8;
  
  FUN_00634c24();
  cVar1 = **(char **)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -0x24) = extraout_ECX;
  cVar2 = **(char **)(unaff_EBP + 0xc);
  if (cVar1 < cVar2) {
    *(int *)(unaff_EBP + -0x14) = (int)cVar1;
    cVar1 = cVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x14) = (int)cVar2;
  }
  cVar2 = (*(char **)(unaff_EBP + 0xc))[1];
  *(int *)(unaff_EBP + -0x18) = (int)cVar1;
  cVar1 = (*(char **)(unaff_EBP + 8))[1];
  if (cVar1 < cVar2) {
    *(int *)(unaff_EBP + -0x1c) = (int)cVar1;
    cVar1 = cVar2;
  }
  else {
    *(int *)(unaff_EBP + -0x1c) = (int)cVar2;
  }
  *(int *)(unaff_EBP + -0x20) = (int)cVar1;
  bVar6 = (*(char *)(unaff_EBP + 0x10) == '\0') + 1;
  *(undefined4 *)(unaff_EBP + 0xc) = 0;
  *(byte *)(unaff_EBP + 0x13) = bVar6;
  do {
    *(undefined4 *)(unaff_EBP + -0x10) = 0;
    iVar8 = (int)*(char *)(unaff_EBP + 0xc);
    do {
      *(undefined1 *)(unaff_EBP + 10) = 1;
      *(undefined1 *)(unaff_EBP + 8) = *(undefined1 *)(unaff_EBP + 0xc);
      *(char *)(unaff_EBP + 9) = *(char *)(unaff_EBP + -0x10);
      iVar4 = DAT_006e57c0;
      *(undefined4 *)(unaff_EBP + -4) = 0;
      iVar5 = (int)*(char *)(unaff_EBP + -0x10);
      bVar3 = *(byte *)(*(int *)(*(int *)(iVar4 + 0xc) + iVar8 * 4) + iVar5);
      bVar7 = bVar3 & 0xfc;
      if ((((*(int *)(unaff_EBP + -0x14) <= iVar8) && (iVar8 <= *(int *)(unaff_EBP + -0x18))) &&
          (*(int *)(unaff_EBP + -0x1c) <= iVar5)) && (iVar5 <= *(int *)(unaff_EBP + -0x20))) {
        bVar7 = bVar7 | bVar6;
      }
      if (bVar7 != bVar3) {
        FUN_004916e1(unaff_EBP + 8);
        *(byte *)(*(int *)(*(int *)(DAT_006e57c0 + 0xc) + *(char *)(unaff_EBP + 8) * 4) +
                 (int)*(char *)(unaff_EBP + 9)) = bVar7;
        bVar6 = *(byte *)(unaff_EBP + 0x13);
      }
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(int *)(unaff_EBP + -0x10) = *(int *)(unaff_EBP + -0x10) + 1;
    } while (*(int *)(unaff_EBP + -0x10) < 0x40);
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc) + 1;
  } while (*(int *)(unaff_EBP + 0xc) < 0x40);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

