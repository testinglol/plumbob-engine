
void FUN_00435051(void)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  char cVar4;
  undefined4 *puVar5;
  int extraout_ECX;
  int iVar6;
  ushort uVar7;
  int unaff_EBP;
  int iVar8;
  uint uVar9;
  undefined4 *puVar10;
  
  FUN_00634c24();
  *(int *)(unaff_EBP + -0x18) = extraout_ECX;
  cVar4 = FUN_004351c8();
  iVar6 = DAT_006e54dc;
  if (cVar4 != '\0') {
    cVar4 = *(char *)(extraout_ECX + 0xfc);
    cVar1 = *(char *)(extraout_ECX + 0xfd);
    uVar7 = *(ushort *)(extraout_ECX + 0x54);
    uVar2 = *(undefined1 *)(extraout_ECX + 0xfe);
    *(int *)(unaff_EBP + -0x14) = DAT_006e54dc;
    uVar7 = uVar7 & 0xffc0;
    *(char *)(unaff_EBP + -0x10) = cVar4;
    *(char *)(unaff_EBP + -0xf) = cVar1;
    *(undefined1 *)(unaff_EBP + -0xe) = uVar2;
    *(undefined4 *)(unaff_EBP + -4) = 0;
    iVar8 = extraout_ECX;
    if (((('\0' < cVar4) && (iVar6 = *(int *)(iVar6 + 0x10) + -1, cVar4 < iVar6)) && ('\0' < cVar1))
       && (cVar1 < iVar6)) {
      uVar9 = (int)*(short *)(extraout_ECX + 0x4c) / -2 & 3;
      *(uint *)(unaff_EBP + -0x1c) = uVar9;
      FUN_00479737(unaff_EBP + -0x48,unaff_EBP + -0x10);
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_0053bdc6(uVar9);
      cVar4 = FUN_004351e4(1);
      if (cVar4 != '\0') {
        uVar7 = uVar7 | 1;
      }
      cVar4 = FUN_004351e4(2);
      if (cVar4 != '\0') {
        uVar7 = uVar7 | 4;
      }
      cVar4 = FUN_004351e4(4);
      if (cVar4 != '\0') {
        uVar7 = uVar7 | 2;
      }
      cVar4 = FUN_004351e4(8);
      if (cVar4 != '\0') {
        uVar7 = uVar7 | 8;
      }
      if (*(char *)(unaff_EBP + -0xe) < '\x01') {
        *(char *)(unaff_EBP + -0xe) = *(char *)(unaff_EBP + -0xe) + '\x01';
        puVar5 = (undefined4 *)FUN_00479737(unaff_EBP + -0x74,unaff_EBP + -0x10);
        uVar3 = *(undefined4 *)(unaff_EBP + -0x1c);
        puVar10 = (undefined4 *)(unaff_EBP + -0x48);
        for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar10 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar10 = puVar10 + 1;
        }
        FUN_0053bdc6(uVar3);
        cVar4 = FUN_004351e4(1);
        if (cVar4 != '\0') {
          uVar7 = uVar7 | 0x10;
        }
        cVar4 = FUN_004351e4(4);
        if (cVar4 != '\0') {
          uVar7 = uVar7 | 0x20;
        }
        iVar8 = *(int *)(unaff_EBP + -0x18);
      }
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
    if (uVar7 != *(ushort *)(iVar8 + 0x54)) {
      *(ushort *)(iVar8 + 0x54) = uVar7;
      FUN_00422d79(6,0,0);
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

