
void FUN_00479954(void)

{
  char cVar1;
  undefined1 uVar2;
  char *pcVar3;
  byte bVar4;
  char cVar5;
  int *piVar6;
  int iVar7;
  undefined1 *puVar8;
  int extraout_ECX;
  int iVar9;
  int unaff_EBP;
  byte *pbVar10;
  int iVar11;
  byte *pbVar12;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x1c) = extraout_ECX;
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 0x30) != 0) {
    FUN_0053bdc6(4 - *(int *)(unaff_EBP + 0x30));
  }
  pcVar3 = *(char **)(unaff_EBP + 8);
  cVar5 = pcVar3[2];
  cVar1 = *pcVar3;
  iVar9 = (int)cVar1;
  *(int *)(unaff_EBP + -0x18) = (int)pcVar3[1];
  *(int *)(unaff_EBP + -0x20) = (int)cVar5;
  *(int *)(unaff_EBP + 8) = extraout_ECX + 0x40 + cVar5 * 4;
  piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x24,iVar9);
  iVar11 = *(int *)(unaff_EBP + -0x18) * 0xe;
  pbVar10 = (byte *)(iVar11 + *piVar6);
  if (((byte)*(undefined4 *)(unaff_EBP + 0xc) & 0x10) == 0x10) {
    *pbVar10 = 0x10;
    iVar7 = FUN_00435221(0x10,0);
    *(undefined2 *)(pbVar10 + 4) = *(undefined2 *)(unaff_EBP + 0x14 + iVar7 * 2);
    iVar7 = FUN_00435221(0x10,2);
    *(undefined2 *)(pbVar10 + 10) = *(undefined2 *)(unaff_EBP + 0x20 + iVar7 * 2);
    iVar7 = FUN_00435221(0x10,4);
    *(undefined2 *)(pbVar10 + 0xc) = *(undefined2 *)(unaff_EBP + 0x20 + iVar7 * 2);
    *(undefined2 *)(pbVar10 + 2) = *(undefined2 *)(unaff_EBP + 0x14);
    *(undefined2 *)(pbVar10 + 6) = *(undefined2 *)(unaff_EBP + 0x20);
  }
  else {
    *pbVar10 = *pbVar10 & 0xef;
  }
  if (((byte)*(undefined4 *)(unaff_EBP + 0xc) & 0x20) == 0x20) {
    *pbVar10 = 0x20;
    iVar7 = FUN_00435221(0x20,0);
    *(undefined2 *)(pbVar10 + 4) = *(undefined2 *)(unaff_EBP + 0x14 + iVar7 * 2);
    iVar7 = FUN_00435221(0x20,1);
    *(undefined2 *)(pbVar10 + 10) = *(undefined2 *)(unaff_EBP + 0x20 + iVar7 * 2);
    iVar7 = FUN_00435221(0x20,3);
    *(undefined2 *)(pbVar10 + 0xc) = *(undefined2 *)(unaff_EBP + 0x20 + iVar7 * 2);
    *(undefined2 *)(pbVar10 + 2) = *(undefined2 *)(unaff_EBP + 0x14);
    *(undefined2 *)(pbVar10 + 6) = *(undefined2 *)(unaff_EBP + 0x20);
  }
  else {
    *pbVar10 = *pbVar10 & 0xdf;
  }
  if (((byte)*(undefined4 *)(unaff_EBP + 0xc) & 1) == 1) {
    *pbVar10 = *pbVar10 | 1;
    iVar7 = FUN_00435221(1,0);
    *(undefined2 *)(pbVar10 + 2) = *(undefined2 *)(unaff_EBP + 0x14 + iVar7 * 2);
    iVar7 = FUN_00435221(1,0);
    *(undefined2 *)(pbVar10 + 6) = *(undefined2 *)(unaff_EBP + 0x20 + iVar7 * 2);
    bVar4 = FUN_0053bd4d(1);
    pbVar10[1] = pbVar10[1] | bVar4;
    if (0 < iVar9) {
      piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,iVar9 + -1);
      *(byte *)(iVar11 + *piVar6) = *(byte *)(iVar11 + *piVar6) | 4;
    }
  }
  else if (((*pbVar10 & 1) != 0) && (*pbVar10 = *pbVar10 & 0xfe, 0 < iVar9)) {
    piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,iVar9 + -1);
    pbVar12 = (byte *)(iVar11 + *piVar6);
    *pbVar12 = *pbVar12 & 0xfb;
    pbVar12[0xc] = 0;
    pbVar12[0xd] = 0;
  }
  if (((byte)*(undefined4 *)(unaff_EBP + 0xc) & 2) == 2) {
    *pbVar10 = *pbVar10 | 2;
    iVar7 = FUN_00435221(2,0);
    *(undefined2 *)(pbVar10 + 4) = *(undefined2 *)(unaff_EBP + 0x14 + iVar7 * 2);
    iVar7 = FUN_00435221(2,0);
    *(undefined2 *)(pbVar10 + 8) = *(undefined2 *)(unaff_EBP + 0x20 + iVar7 * 2);
    cVar5 = FUN_0053bd4d(2);
    pbVar10[1] = pbVar10[1] | cVar5 << 2;
    if (0 < *(int *)(unaff_EBP + -0x18)) {
      piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,iVar9);
      pbVar12 = (byte *)(iVar11 + -0xe + *piVar6);
      *pbVar12 = *pbVar12 | 8;
    }
  }
  else if (((*pbVar10 & 2) != 0) &&
          (iVar7 = *(int *)(unaff_EBP + -0x18), *pbVar10 = *pbVar10 & 0xfd, 0 < iVar7)) {
    piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,iVar9);
    iVar7 = *piVar6;
    pbVar12 = (byte *)(iVar11 + -0xe + iVar7);
    *pbVar12 = *pbVar12 & 0xf7;
    *(undefined2 *)(iVar11 + -4 + iVar7) = 0;
  }
  if (((byte)*(undefined4 *)(unaff_EBP + 0xc) & 4) == 4) {
    *pbVar10 = *pbVar10 | 4;
    iVar7 = FUN_00435221(4,0);
    *(undefined2 *)(pbVar10 + 0xc) = *(undefined2 *)(unaff_EBP + 0x20 + iVar7 * 2);
    if (iVar9 < *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x10) + -1) {
      piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,iVar9 + 1);
      pbVar12 = (byte *)(iVar11 + *piVar6);
      *pbVar12 = *pbVar12 | 1;
      iVar11 = FUN_00435221(4,0);
      *(undefined2 *)(pbVar12 + 2) = *(undefined2 *)(unaff_EBP + 0x14 + iVar11 * 2);
      bVar4 = FUN_0053bd4d(4);
      pbVar12[1] = pbVar12[1] | bVar4;
    }
  }
  else if (((*pbVar10 & 4) != 0) &&
          (*pbVar10 = *pbVar10 & 0xfb, iVar9 < *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x10) + -1)) {
    piVar6 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,iVar9 + 1);
    pbVar12 = (byte *)(iVar11 + *piVar6);
    *pbVar12 = *pbVar12 & 0xfe;
    pbVar12[6] = 0;
    pbVar12[7] = 0;
  }
  if (((byte)*(undefined4 *)(unaff_EBP + 0xc) & 8) == 8) {
    *pbVar10 = *pbVar10 | 8;
    iVar11 = FUN_00435221(8,0);
    *(undefined2 *)(pbVar10 + 10) = *(undefined2 *)(unaff_EBP + 0x20 + iVar11 * 2);
    if (*(int *)(unaff_EBP + -0x18) < *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x10) + -1) {
      piVar6 = (int *)FUN_0047c7b7(unaff_EBP + 8,iVar9);
      pbVar10 = (byte *)((*(int *)(unaff_EBP + -0x18) + 1) * 0xe + *piVar6);
      *pbVar10 = *pbVar10 | 2;
      iVar9 = FUN_00435221(8,0);
      *(undefined2 *)(pbVar10 + 4) = *(undefined2 *)(unaff_EBP + 0x14 + iVar9 * 2);
      cVar5 = FUN_0053bd4d(8);
      pbVar10[1] = pbVar10[1] | cVar5 << 2;
    }
  }
  else if (((*pbVar10 & 8) != 0) &&
          (*pbVar10 = *pbVar10 & 0xf7,
          *(int *)(unaff_EBP + -0x18) < *(int *)(*(int *)(unaff_EBP + -0x1c) + 0x10) + -1)) {
    piVar6 = (int *)FUN_0047c7b7(unaff_EBP + 8,iVar9);
    pbVar10 = (byte *)((*(int *)(unaff_EBP + -0x18) + 1) * 0xe + *piVar6);
    *pbVar10 = *pbVar10 & 0xfd;
    pbVar10[8] = 0;
    pbVar10[9] = 0;
  }
  *(char *)(unaff_EBP + -0x14) = cVar1;
  *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x20);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  puVar8 = (undefined1 *)FUN_00479dca(unaff_EBP + 0xb,unaff_EBP + -0x14);
  iVar9 = *(int *)(unaff_EBP + -0x1c);
  *(undefined1 *)
   (*(int *)(*(int *)(*(int *)(iVar9 + 0x48 + *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
            *(char *)(unaff_EBP + -0x14) * 4) + (int)*(char *)(unaff_EBP + -0x13)) = *puVar8;
  *(char *)(unaff_EBP + 0xb) = cVar1 + '\x01';
  *(char *)(unaff_EBP + -0x14) = cVar1 + '\x01';
  *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0x18);
  *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0x20);
  puVar8 = (undefined1 *)FUN_00479dca(unaff_EBP + -0xd,unaff_EBP + -0x14);
  *(undefined1 *)
   (*(int *)(*(int *)(*(int *)(iVar9 + 0x48 + *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
            *(char *)(unaff_EBP + -0x14) * 4) + (int)*(char *)(unaff_EBP + -0x13)) = *puVar8;
  cVar5 = *(char *)(unaff_EBP + -0x18) + '\x01';
  *(char *)(unaff_EBP + -0x14) = cVar1;
  uVar2 = *(undefined1 *)(unaff_EBP + -0x20);
  *(char *)(unaff_EBP + -0xd) = cVar5;
  *(char *)(unaff_EBP + -0x13) = cVar5;
  *(undefined1 *)(unaff_EBP + -0x12) = uVar2;
  puVar8 = (undefined1 *)FUN_00479dca(unaff_EBP + -0xe,unaff_EBP + -0x14);
  *(undefined1 *)
   (*(int *)(*(int *)(*(int *)(iVar9 + 0x48 + *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
            *(char *)(unaff_EBP + -0x14) * 4) + (int)*(char *)(unaff_EBP + -0x13)) = *puVar8;
  *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + 0xb);
  *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0xd);
  *(undefined1 *)(unaff_EBP + -0x12) = uVar2;
  puVar8 = (undefined1 *)FUN_00479dca(unaff_EBP + 0xb,unaff_EBP + -0x14);
  *(undefined1 *)
   (*(int *)(*(int *)(*(int *)(iVar9 + 0x48 + *(char *)(unaff_EBP + -0x12) * 4) + 0xc) +
            *(char *)(unaff_EBP + -0x14) * 4) + (int)*(char *)(unaff_EBP + -0x13)) = *puVar8;
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

