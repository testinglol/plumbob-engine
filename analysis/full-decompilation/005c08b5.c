
void FUN_005c08b5(void)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_EBP;
  uint uVar6;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -4) = 0;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffa8;
  uVar2 = FUN_005bddff();
  uVar3 = FUN_005bdf5b();
  *(undefined1 *)(unaff_EBP + -0x11) = 0;
  uVar6 = uVar2 & 0x7fff;
  *(undefined4 *)(unaff_EBP + -0x18) = uVar3;
  if (0xb < (ushort)uVar6) {
    uVar6 = 0xb;
  }
  _memset((void *)(unaff_EBP + -0x38),0,0x10);
  iVar4 = *(int *)(unaff_EBP + 0xc);
  if (iVar4 < 1) {
    iVar4 = *(int *)(&UNK_00673150 + uVar6 * 4);
  }
  else {
    if (0x96 < iVar4) {
      iVar4 = 0x96;
    }
    *(undefined1 *)(unaff_EBP + -0x11) = 1;
  }
  if (((*(byte *)(unaff_EBP + -0x18) & 0x10) == 0) || (*(char *)(unaff_EBP + -0x11) != '\0')) {
    if (((ushort)uVar6 < 3) && ((uVar2 >> 0xf & 1) == 0)) {
      puVar5 = (undefined4 *)(unaff_EBP + -0x38);
    }
    else {
      puVar5 = (undefined4 *)FUN_005c0b17(unaff_EBP + -0x58,iVar4 * 4000);
      *(undefined4 *)(unaff_EBP + -0x28) = *puVar5;
      *(undefined4 *)(unaff_EBP + -0x24) = puVar5[1];
      *(undefined4 *)(unaff_EBP + -0x20) = puVar5[2];
      *(undefined4 *)(unaff_EBP + -0x1c) = puVar5[3];
      puVar5 = (undefined4 *)(unaff_EBP + -0x28);
    }
  }
  else {
    puVar5 = (undefined4 *)FUN_005c09ad(unaff_EBP + -0x48);
    *(undefined4 *)(unaff_EBP + -0x28) = *puVar5;
    *(undefined4 *)(unaff_EBP + -0x24) = puVar5[1];
    *(undefined4 *)(unaff_EBP + -0x20) = puVar5[2];
    *(undefined4 *)(unaff_EBP + -0x1c) = puVar5[3];
    puVar5 = (undefined4 *)(unaff_EBP + -0x28);
  }
  puVar1 = *(undefined4 **)(unaff_EBP + 8);
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  *puVar1 = *puVar5;
  puVar1[1] = puVar5[1];
  puVar1[2] = puVar5[2];
  puVar1[3] = puVar5[3];
  return;
}

