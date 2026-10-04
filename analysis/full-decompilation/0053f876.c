
void FUN_0053f876(void)

{
  undefined1 uVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  ushort uVar5;
  char cVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined4 *puVar9;
  char *pcVar10;
  int iVar11;
  int iVar12;
  byte *pbVar13;
  int extraout_ECX;
  int iVar14;
  int unaff_EBP;
  undefined4 *puVar15;
  bool bVar16;
  
  FUN_00634c24();
  puVar8 = *(undefined1 **)(unaff_EBP + 8);
  *(undefined1 **)(extraout_ECX + 0x20) = puVar8;
  *(undefined1 *)(extraout_ECX + 4) = *puVar8;
  *(undefined1 *)(extraout_ECX + 5) = puVar8[1];
  *(undefined1 *)(extraout_ECX + 6) = puVar8[2];
  iVar14 = *(int *)(unaff_EBP + 0xc);
  *(int *)(extraout_ECX + 0x10) = iVar14;
  FUN_00461b74(&DAT_006e481c + iVar14 * 3);
  uVar1 = *(undefined1 *)(unaff_EBP + 8);
  *(undefined1 *)(extraout_ECX + 0xc) = 0;
  *(undefined1 *)(extraout_ECX + 10) = uVar1;
  *(undefined1 *)(extraout_ECX + 0xb) = *(undefined1 *)(unaff_EBP + 9);
  *(undefined4 *)(extraout_ECX + 0x14) = 0;
  *(undefined1 *)(extraout_ECX + 0x1c) = 0;
  *(undefined1 *)(extraout_ECX + 0x1d) = 0;
  iVar14 = *(int *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -0x2c) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = 0;
  if (iVar14 == 1) {
    *(undefined4 *)(extraout_ECX + 0x18) = 1;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 4;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 1;
  }
  else if (iVar14 == 3) {
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 8;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 2;
  }
  else if (iVar14 == 5) {
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 0x40;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 0x10;
    *(undefined4 *)(unaff_EBP + -0x2c) = 1;
    *(undefined4 *)(unaff_EBP + -0x30) = 3;
  }
  else if (iVar14 == 6) {
    *(undefined4 *)(extraout_ECX + 0x18) = 0;
    *(byte *)(extraout_ECX + 0x1c) = *(byte *)(extraout_ECX + 0x1c) | 0x80;
    *(byte *)(extraout_ECX + 0x1d) = *(byte *)(extraout_ECX + 0x1d) | 0x20;
    *(undefined4 *)(unaff_EBP + -0x2c) = 4;
    *(undefined4 *)(unaff_EBP + -0x30) = 2;
  }
  *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(extraout_ECX + 5);
  *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(extraout_ECX + 6);
  uVar7 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0053f472(unaff_EBP + -0x10,unaff_EBP + -0x18,uVar7);
  uVar7 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar7 = FUN_0053c16a(uVar7);
  *(undefined4 *)(unaff_EBP + -0x1c) = uVar7;
  *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0xe);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0053c0e0(*(undefined4 *)(unaff_EBP + -0x1c),unaff_EBP + -0x14);
  uVar7 = FUN_0053c135(*(undefined4 *)(unaff_EBP + -0x1c));
  *(undefined4 *)(unaff_EBP + -0x34) = uVar7;
  puVar8 = (undefined1 *)FUN_0044f2cf(unaff_EBP + 8,unaff_EBP + -0x10);
  uVar1 = *puVar8;
  *(undefined1 *)(unaff_EBP + -0x40) = 0;
  *(undefined1 *)(unaff_EBP + -0x14) = uVar1;
  *(undefined1 *)(unaff_EBP + -0x13) = puVar8[1];
  *(undefined1 *)(unaff_EBP + -0x12) = puVar8[2];
  puVar9 = (undefined4 *)(unaff_EBP + -0x7c);
  for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  puVar9 = (undefined4 *)(unaff_EBP + -0xa8);
  for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
    *puVar9 = 0;
    puVar9 = puVar9 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 5;
  do {
    if ((*(byte *)(unaff_EBP + -0x54) & 0x10) != 0) {
      puVar9 = (undefined4 *)(unaff_EBP + -0x7c);
      for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
    }
    if ((*(byte *)(unaff_EBP + -0x80) & 0x10) != 0) {
      puVar9 = (undefined4 *)(unaff_EBP + -0xa8);
      for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
        *puVar9 = 0;
        puVar9 = puVar9 + 1;
      }
    }
    puVar9 = (undefined4 *)FUN_00479737(unaff_EBP + -0xd4,unaff_EBP + -0x10);
    puVar15 = (undefined4 *)(unaff_EBP + -0x7c);
    for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar15 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar15 = puVar15 + 1;
    }
    pcVar10 = (char *)FUN_0046185f(unaff_EBP + 0xc,unaff_EBP + -0x14);
    if (((*(char *)(unaff_EBP + -0x10) == *pcVar10) && (*(char *)(unaff_EBP + -0xf) == pcVar10[1]))
       && (*(char *)(unaff_EBP + -0xe) == pcVar10[2])) {
      puVar9 = (undefined4 *)(unaff_EBP + -0x7c);
    }
    else {
      uVar7 = FUN_0046185f(unaff_EBP + -0x44,unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      puVar9 = (undefined4 *)FUN_00479737(unaff_EBP + -0x100,uVar7);
    }
    puVar15 = (undefined4 *)(unaff_EBP + -0xa8);
    for (iVar14 = 0xb; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar15 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar15 = puVar15 + 1;
    }
    iVar14 = *(int *)(unaff_EBP + -0x1c);
    *(undefined1 *)(unaff_EBP + -4) = 7;
    iVar11 = FUN_00435221(iVar14,0);
    *(char *)(unaff_EBP + -0x3b) = (char)*(undefined2 *)(unaff_EBP + -0x74 + iVar11 * 2);
    iVar11 = *(int *)(unaff_EBP + -0x2c);
    if (iVar14 == 0x10) {
      if (iVar11 == 0) {
        iVar11 = 4;
      }
    }
    else if ((iVar14 == 0x20) && (iVar11 == 0)) {
      iVar11 = 1;
    }
    iVar12 = FUN_00435221(iVar14,iVar11);
    iVar11 = *(int *)(unaff_EBP + -0x34);
    *(undefined2 *)(unaff_EBP + -0x3a + *(int *)(extraout_ECX + 0x18) * 2) =
         *(undefined2 *)(unaff_EBP + -0x68 + iVar12 * 2);
    iVar12 = *(int *)(unaff_EBP + -0x30);
    if (iVar11 == 0x10) {
      if (iVar12 == 0) {
        iVar12 = 4;
      }
    }
    else if ((*(int *)(unaff_EBP + -0x34) == 0x20) && (iVar12 == 0)) {
      iVar12 = 1;
    }
    iVar11 = FUN_00435221(*(undefined4 *)(unaff_EBP + -0x34),iVar12);
    cVar6 = *(char *)(unaff_EBP + -0xf);
    *(undefined2 *)(unaff_EBP + -0x3a + (uint)(*(int *)(extraout_ECX + 0x18) == 0) * 2) =
         *(undefined2 *)(unaff_EBP + -0x94 + iVar11 * 2);
    iVar11 = DAT_006e54dc;
    *(undefined1 *)(unaff_EBP + -0x3c) = 0;
    uVar4 = *(ushort *)
             (*(int *)(*(int *)(*(int *)(iVar11 + 0x28 + *(char *)(unaff_EBP + -0xe) * 4) + 0xc) +
                      *(char *)(unaff_EBP + -0x10) * 4) + cVar6 * 2);
    pcVar10 = (char *)FUN_0046185f(unaff_EBP + -0x48,unaff_EBP + -0x14);
    uVar5 = *(ushort *)
             (*(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x28 + pcVar10[2] * 4) + 0xc) + *pcVar10 * 4
                      ) + pcVar10[1] * 2);
    if (uVar4 < 0xfffb) {
      uVar7 = FUN_004670a4(CONCAT22((short)((uint)iVar14 >> 0x10),uVar4));
      *(undefined4 *)(extraout_ECX + 0x28 + *(int *)(extraout_ECX + 0x18) * 4) = uVar7;
    }
    else {
      cVar6 = FUN_004672d0(unaff_EBP + -0x10,unaff_EBP + -0x28,unaff_EBP + -0x24,unaff_EBP + -0x20,
                           unaff_EBP + -0x4c);
      if (cVar6 != '\0') {
        if (*(int *)(unaff_EBP + -0x1c) == 0x10) {
          if (*(int *)(unaff_EBP + -0x20) == 2) goto LAB_0053fbd5;
          bVar16 = *(int *)(unaff_EBP + -0x20) == 3;
LAB_0053fbbc:
          if (bVar16) goto LAB_0053fbd5;
          *(undefined4 *)(extraout_ECX + 0x28 + *(int *)(extraout_ECX + 0x18) * 4) =
               *(undefined4 *)(unaff_EBP + -0x24);
          uVar7 = *(undefined4 *)(unaff_EBP + -0x28);
          iVar14 = *(int *)(extraout_ECX + 0x18);
        }
        else {
          if (*(int *)(unaff_EBP + -0x20) != 2) {
            bVar16 = *(int *)(unaff_EBP + -0x20) == 1;
            goto LAB_0053fbbc;
          }
LAB_0053fbd5:
          *(undefined4 *)(extraout_ECX + 0x28 + *(int *)(extraout_ECX + 0x18) * 4) =
               *(undefined4 *)(unaff_EBP + -0x28);
          uVar7 = *(undefined4 *)(unaff_EBP + -0x24);
          iVar14 = *(int *)(extraout_ECX + 0x18);
        }
        *(undefined4 *)(extraout_ECX + 0x28 + (uint)(iVar14 == 0) * 4) = uVar7;
      }
    }
    if (uVar5 < 0xfffb) {
      uVar7 = FUN_004670a4(CONCAT22((short)((uint)puVar15 >> 0x10),uVar5));
      *(undefined4 *)(extraout_ECX + 0x28 + (uint)(*(int *)(extraout_ECX + 0x18) == 0) * 4) = uVar7;
    }
    else {
      FUN_0046185f(unaff_EBP + -0x50,unaff_EBP + -0x14);
    }
    FUN_0053ffb2(unaff_EBP + -0x3c);
    *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + *(char *)(extraout_ECX + 10);
    *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + *(char *)(extraout_ECX + 0xb);
    *(char *)(unaff_EBP + -0x18) = *(char *)(unaff_EBP + -0x18) + *(char *)(extraout_ECX + 10);
    *(char *)(unaff_EBP + -0x17) = *(char *)(unaff_EBP + -0x17) + *(char *)(extraout_ECX + 0xb);
    pbVar13 = (byte *)FUN_0053f84a(unaff_EBP + 0xb,unaff_EBP + -0x18);
    bVar2 = *pbVar13;
    *(undefined1 *)(unaff_EBP + -4) = 5;
    *(byte *)(unaff_EBP + -0x40) = bVar2;
    if (((bVar2 == 0) || ((&DAT_006f4b20)[bVar2] != '\0')) || ((&DAT_006f4a20)[bVar2] != '\0')) {
      puVar8 = (undefined1 *)
               FUN_0053f506(unaff_EBP + 8,unaff_EBP + -0x10,*(undefined4 *)(extraout_ECX + 0x10));
      uVar1 = *puVar8;
      *(undefined1 *)(unaff_EBP + -0x10) = uVar1;
      uVar3 = puVar8[1];
      *(undefined1 *)(unaff_EBP + -0xf) = uVar3;
      *(undefined1 *)(unaff_EBP + -0xe) = puVar8[2];
      puVar8 = (undefined1 *)(extraout_ECX + 7);
      *puVar8 = uVar1;
      uVar1 = *(undefined1 *)(unaff_EBP + -0xe);
      *(undefined1 *)(extraout_ECX + 8) = uVar3;
      *(undefined1 *)(extraout_ECX + 9) = uVar1;
      FUN_00540a5b(puVar8);
      iVar14 = FUN_00540a64(puVar8);
      *(int *)(extraout_ECX + 0x24) = iVar14;
      if (iVar14 != 0) {
        *(int *)(iVar14 + 0x20) = *(int *)(iVar14 + 0x20) + 1;
        FUN_0053d231(extraout_ECX,*(undefined4 *)(extraout_ECX + 0x10));
      }
      ExceptionList = *(void **)(unaff_EBP + -0xc);
      return;
    }
  } while( true );
}

