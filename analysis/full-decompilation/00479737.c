
void FUN_00479737(void)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  int iVar4;
  int unaff_EBP;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  bool bVar8;
  
  FUN_00634c24();
  iVar4 = (int)**(char **)(unaff_EBP + 0xc);
  iVar6 = (int)(*(char **)(unaff_EBP + 0xc))[1];
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = extraout_ECX;
  *(int *)(unaff_EBP + 0xc) = iVar6;
  piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x24,iVar4);
  iVar6 = iVar6 * 0xe;
  *(int *)(unaff_EBP + -0x24) = *piVar3 + iVar6;
  if (iVar4 < 1) {
    bVar8 = false;
  }
  else {
    piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x20,iVar4 + -1);
    iVar2 = *piVar3;
    *(undefined4 *)(unaff_EBP + -0x10) = 1;
    bVar8 = (*(byte *)(iVar6 + iVar2) & 0x30) != 0;
  }
  *(bool *)(unaff_EBP + -0x20) = bVar8;
  if ((*(byte *)(unaff_EBP + -0x10) & 1) != 0) {
    *(uint *)(unaff_EBP + -0x10) = *(uint *)(unaff_EBP + -0x10) & 0xfffffffe;
  }
  if (*(int *)(unaff_EBP + 0xc) < 1) {
    bVar8 = false;
  }
  else {
    piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x1c,iVar4);
    bVar8 = (*(byte *)(iVar6 + -0xe + *piVar3) & 0x30) != 0;
  }
  *(bool *)(unaff_EBP + -0x1c) = bVar8;
  if (*(int *)(unaff_EBP + 0xc) < *(int *)(*(int *)(unaff_EBP + -0x14) + 0x10) + -1) {
    piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x18,iVar4);
    bVar8 = (*(byte *)((*(int *)(unaff_EBP + 0xc) + 1) * 0xe + *piVar3) & 0x30) != 0;
  }
  else {
    bVar8 = false;
  }
  *(bool *)(unaff_EBP + -0x18) = bVar8;
  if (iVar4 < *(int *)(*(int *)(unaff_EBP + -0x14) + 0x10) + -1) {
    piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x10,iVar4 + 1);
    bVar8 = (*(byte *)(iVar6 + *piVar3) & 0x30) != 0;
  }
  else {
    bVar8 = false;
  }
  *(bool *)(unaff_EBP + -0x10) = bVar8;
  FUN_0053bb23(*(undefined4 *)(unaff_EBP + -0x24),*(undefined4 *)(unaff_EBP + -0x20),
               *(undefined4 *)(unaff_EBP + -0x1c),*(undefined4 *)(unaff_EBP + -0x18),
               *(undefined4 *)(unaff_EBP + -0x10));
  *(undefined4 *)(unaff_EBP + -4) = 0;
  if (*(int *)(unaff_EBP + 0xc) < *(int *)(*(int *)(unaff_EBP + -0x14) + 0x10) + -1) {
    piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x24,iVar4);
    bVar1 = *(byte *)((*(int *)(unaff_EBP + 0xc) + 1) * 0xe + *piVar3);
    *(uint *)(unaff_EBP + 0xc) = bVar1 & 2;
    if ((bVar1 & 2) != 0) {
      piVar3 = (int *)FUN_0047c7b7(unaff_EBP + 0xc,iVar4);
      iVar2 = *piVar3;
      *(undefined1 *)(unaff_EBP + -4) = 1;
      FUN_004633e3(*(undefined2 *)(iVar2 + 0x12 + iVar6),8);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      piVar3 = (int *)FUN_0047c7b7(unaff_EBP + 0xc,iVar4);
      iVar2 = *piVar3;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      FUN_0053bd78((*(byte *)(iVar6 + 0xf + iVar2) & 0xc) >> 2,8);
      *(undefined1 *)(unaff_EBP + -4) = 0;
    }
  }
  if (iVar4 < *(int *)(*(int *)(unaff_EBP + -0x14) + 0x10) + -1) {
    iVar4 = iVar4 + 1;
    piVar3 = (int *)FUN_0047c7b7(unaff_EBP + 0xc,iVar4);
    bVar1 = *(byte *)(iVar6 + *piVar3);
    *(uint *)(unaff_EBP + 0xc) = bVar1 & 1;
    if ((bVar1 & 1) != 0) {
      piVar3 = (int *)FUN_0047c7b7(unaff_EBP + 0xc,iVar4);
      iVar2 = *piVar3;
      *(undefined1 *)(unaff_EBP + -4) = 3;
      FUN_004633e3(*(undefined2 *)(iVar2 + 2 + iVar6),4);
      *(undefined1 *)(unaff_EBP + -4) = 0;
      piVar3 = (int *)FUN_0047c7b7(unaff_EBP + -0x28,iVar4);
      iVar4 = *piVar3;
      *(undefined1 *)(unaff_EBP + -4) = 4;
      FUN_0053bd78(*(byte *)(iVar4 + 1 + iVar6) & 3,4);
    }
  }
  puVar5 = (undefined4 *)(unaff_EBP + -0x54);
  puVar7 = *(undefined4 **)(unaff_EBP + 8);
  for (iVar4 = 0xb; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

