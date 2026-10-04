
void FUN_0053f59e(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  byte *pbVar7;
  int extraout_ECX;
  int iVar8;
  int unaff_EBP;
  undefined4 *puVar9;
  
  FUN_00634c24();
  iVar8 = *(int *)(extraout_ECX + 0x14);
  *(int *)(unaff_EBP + -0x38) = iVar8;
  if (iVar8 != 0) {
    FUN_0053daef(0);
  }
  *(undefined1 *)(unaff_EBP + -0x18) = *(undefined1 *)(extraout_ECX + 4);
  *(undefined1 *)(unaff_EBP + -0x17) = *(undefined1 *)(extraout_ECX + 5);
  *(undefined1 *)(unaff_EBP + -0x16) = *(undefined1 *)(extraout_ECX + 6);
  uVar2 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_0053f472(unaff_EBP + -0x10,unaff_EBP + -0x18,uVar2);
  uVar2 = *(undefined4 *)(extraout_ECX + 0x10);
  *(undefined1 *)(unaff_EBP + -4) = 1;
  uVar2 = FUN_0053c16a(uVar2);
  *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
  uVar2 = FUN_0053c135(uVar2);
  *(undefined4 *)(unaff_EBP + -0x28) = uVar2;
  *(undefined1 *)(unaff_EBP + -0x14) = *(undefined1 *)(unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -0x13) = *(undefined1 *)(unaff_EBP + -0xf);
  *(undefined1 *)(unaff_EBP + -0x12) = *(undefined1 *)(unaff_EBP + -0xe);
  *(undefined1 *)(unaff_EBP + -4) = 2;
  FUN_0053c0e0(*(undefined4 *)(unaff_EBP + -0x20),unaff_EBP + -0x14);
  puVar3 = (undefined1 *)FUN_0044f2cf(unaff_EBP + -0x34,unaff_EBP + -0x10);
  *(undefined1 *)(unaff_EBP + -0x14) = *puVar3;
  *(undefined1 *)(unaff_EBP + -0x13) = puVar3[1];
  *(undefined1 *)(unaff_EBP + -0x12) = puVar3[2];
  if (*(int *)(extraout_ECX + 0x10) == 5) {
    *(undefined4 *)(unaff_EBP + -0x24) = 1;
    *(undefined4 *)(unaff_EBP + -0x1c) = 3;
  }
  else if (*(int *)(extraout_ECX + 0x10) == 6) {
    *(undefined4 *)(unaff_EBP + -0x24) = 4;
    *(undefined4 *)(unaff_EBP + -0x1c) = 2;
  }
  else {
    *(undefined4 *)(unaff_EBP + -0x24) = 0;
    *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  }
  *(undefined1 *)(unaff_EBP + -0x3c) = 0;
  *(undefined4 *)(unaff_EBP + -0x30) = *(undefined4 *)(extraout_ECX + 0x30);
  puVar4 = (undefined4 *)(unaff_EBP + -0x6c);
  for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(unaff_EBP + -0x98);
  for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined1 *)(unaff_EBP + -4) = 5;
  do {
    if ((*(byte *)(unaff_EBP + -0x44) & 0x10) != 0) {
      puVar4 = (undefined4 *)(unaff_EBP + -0x6c);
      for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    if ((*(byte *)(unaff_EBP + -0x70) & 0x10) != 0) {
      puVar4 = (undefined4 *)(unaff_EBP + -0x98);
      for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
    }
    puVar4 = (undefined4 *)FUN_00479737(unaff_EBP + -0xc4,unaff_EBP + -0x10);
    puVar9 = (undefined4 *)(unaff_EBP + -0x6c);
    for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar9 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar9 = puVar9 + 1;
    }
    pcVar5 = (char *)FUN_0046185f(unaff_EBP + -0x34,unaff_EBP + -0x14);
    if (((*(char *)(unaff_EBP + -0x10) == *pcVar5) && (*(char *)(unaff_EBP + -0xf) == pcVar5[1])) &&
       (*(char *)(unaff_EBP + -0xe) == pcVar5[2])) {
      puVar4 = (undefined4 *)(unaff_EBP + -0x6c);
      puVar9 = (undefined4 *)(unaff_EBP + -0x98);
      for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar9 = puVar9 + 1;
      }
    }
    else {
      uVar2 = FUN_0046185f(unaff_EBP + -0x40,unaff_EBP + -0x14);
      *(undefined1 *)(unaff_EBP + -4) = 6;
      puVar4 = (undefined4 *)FUN_00479737(unaff_EBP + -0xf0,uVar2);
      puVar9 = (undefined4 *)(unaff_EBP + -0x98);
      for (iVar8 = 0xb; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar9 = puVar9 + 1;
      }
      *(undefined1 *)(unaff_EBP + -4) = 5;
    }
    iVar8 = *(int *)(unaff_EBP + -0x20);
    iVar6 = FUN_00435221(iVar8,0);
    puVar3 = *(undefined1 **)(unaff_EBP + -0x30);
    puVar3[1] = *(undefined1 *)(unaff_EBP + -100 + iVar6 * 2);
    iVar6 = *(int *)(unaff_EBP + -0x24);
    if (iVar8 == 0x10) {
      if (iVar6 == 0) {
        iVar6 = 4;
      }
    }
    else if ((iVar8 == 0x20) && (iVar6 == 0)) {
      iVar6 = 1;
    }
    iVar6 = FUN_00435221(iVar8,iVar6);
    iVar8 = *(int *)(unaff_EBP + -0x28);
    *(undefined2 *)(puVar3 + *(int *)(extraout_ECX + 0x18) * 2 + 2) =
         *(undefined2 *)(unaff_EBP + -0x58 + iVar6 * 2);
    iVar6 = *(int *)(unaff_EBP + -0x1c);
    if (iVar8 == 0x10) {
      if (iVar6 == 0) {
        iVar6 = 4;
      }
    }
    else if ((*(int *)(unaff_EBP + -0x28) == 0x20) && (iVar6 == 0)) {
      iVar6 = 1;
    }
    iVar8 = FUN_00435221(*(undefined4 *)(unaff_EBP + -0x28),iVar6);
    *(undefined2 *)(puVar3 + (uint)(*(int *)(extraout_ECX + 0x18) == 0) * 2 + 2) =
         *(undefined2 *)(unaff_EBP + -0x84 + iVar8 * 2);
    *puVar3 = 0;
    *(char *)(unaff_EBP + -0x10) = *(char *)(unaff_EBP + -0x10) + *(char *)(extraout_ECX + 10);
    *(char *)(unaff_EBP + -0xf) = *(char *)(unaff_EBP + -0xf) + *(char *)(extraout_ECX + 0xb);
    *(char *)(unaff_EBP + -0x18) = *(char *)(unaff_EBP + -0x18) + *(char *)(extraout_ECX + 10);
    *(char *)(unaff_EBP + -0x17) = *(char *)(unaff_EBP + -0x17) + *(char *)(extraout_ECX + 0xb);
    *(undefined1 **)(unaff_EBP + -0x30) = puVar3 + 6;
    pbVar7 = (byte *)FUN_0053f84a(unaff_EBP + -0x29,unaff_EBP + -0x18);
    bVar1 = *pbVar7;
    *(byte *)(unaff_EBP + -0x3c) = bVar1;
  } while (((bVar1 != 0) && ((&DAT_006f4b20)[bVar1] == '\0')) && ((&DAT_006f4a20)[bVar1] == '\0'));
  if (*(int *)(unaff_EBP + -0x38) != *(int *)(extraout_ECX + 0x14)) {
    FUN_0053daef(*(int *)(unaff_EBP + -0x38));
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

