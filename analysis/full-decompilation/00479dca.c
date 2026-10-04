
byte * FUN_00479dca(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  byte *pbVar4;
  char cVar5;
  char cVar6;
  byte bVar7;
  char cVar8;
  undefined4 extraout_ECX;
  char *pcVar9;
  int unaff_EBP;
  int iVar10;
  
  FUN_00634c24();
  pcVar9 = *(char **)(unaff_EBP + 0xc);
  *(int *)(unaff_EBP + -0x14) = (int)*pcVar9;
  cVar2 = pcVar9[2];
  *(int *)(unaff_EBP + 0xc) = (int)pcVar9[1];
  iVar10 = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  FUN_00635e55(unaff_EBP + -0x28,3,4,&LAB_00479f05,FUN_00416e17);
  cVar6 = (char)*(undefined4 *)(unaff_EBP + 0xc) + -1;
  *(char *)(unaff_EBP + -0x26) = cVar2;
  *(char *)(unaff_EBP + -0x27) = cVar6;
  *(char *)(unaff_EBP + -0x24) = cVar6;
  cVar5 = (char)*(undefined4 *)(unaff_EBP + -0x14);
  cVar8 = cVar5 + -1;
  *(undefined1 *)(unaff_EBP + -0x21) = *(undefined1 *)(unaff_EBP + 0xc);
  *(char *)(unaff_EBP + -0x1f) = *pcVar9;
  *(char *)(unaff_EBP + -0x1e) = pcVar9[1];
  cVar6 = pcVar9[2];
  *(char *)(unaff_EBP + -0x28) = cVar8;
  *(char *)(unaff_EBP + -0x22) = cVar8;
  *(char *)(unaff_EBP + -0x25) = cVar5;
  *(char *)(unaff_EBP + -0x23) = cVar2;
  *(char *)(unaff_EBP + -0x20) = cVar2;
  *(char *)(unaff_EBP + -0x1d) = cVar6;
  pcVar9 = (char *)(unaff_EBP + -0x28);
  do {
    if (*pcVar9 < '\x01') {
LAB_00479e85:
      *(undefined1 *)(unaff_EBP + 0xc + iVar10) = 0;
    }
    else {
      iVar1 = *(int *)(*(int *)(unaff_EBP + -0x10) + 0x10) + -1;
      if (iVar1 <= *pcVar9) goto LAB_00479e85;
      cVar6 = pcVar9[1];
      if ((cVar6 < '\x01') || (iVar1 <= cVar6)) goto LAB_00479e85;
      *(undefined1 *)(unaff_EBP + 0xc + iVar10) =
           *(undefined1 *)
            (*(int *)(*(int *)(*(int *)(*(int *)(unaff_EBP + -0x10) + 0x40 + cVar2 * 4) + 0xc) +
                     *pcVar9 * 4) + cVar6 * 0xe);
    }
    iVar10 = iVar10 + 1;
    pcVar9 = pcVar9 + 3;
    if (3 < iVar10) {
      uVar3 = *(uint *)(unaff_EBP + 0xc);
      bVar7 = 0;
      if ((uVar3 & 8) != 0) {
        bVar7 = 2;
      }
      if ((uVar3 & 0x20) != 0) {
        bVar7 = bVar7 | 0x10;
      }
      if ((uVar3 & 0x100) != 0) {
        bVar7 = bVar7 | 1;
      }
      if ((uVar3 & 0x1000) != 0) {
        bVar7 = bVar7 | 0x80;
      }
      if ((*(byte *)(unaff_EBP + 0xe) & 4) != 0) {
        bVar7 = bVar7 | 4;
      }
      if ((*(byte *)(unaff_EBP + 0xe) & 0x10) != 0) {
        bVar7 = bVar7 | 0x20;
      }
      if ((*(byte *)(unaff_EBP + 0xf) & 2) != 0) {
        bVar7 = bVar7 | 8;
      }
      if ((*(byte *)(unaff_EBP + 0xf) & 0x20) != 0) {
        bVar7 = bVar7 | 0x40;
      }
      pbVar4 = *(byte **)(unaff_EBP + 8);
      *(undefined4 *)(unaff_EBP + -0x18) = 1;
      *pbVar4 = bVar7;
      FUN_00635f6d(unaff_EBP + -0x28,3,4,FUN_00416e17);
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return pbVar4;
    }
  } while( true );
}

