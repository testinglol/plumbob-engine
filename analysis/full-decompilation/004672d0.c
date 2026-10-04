
uint FUN_004672d0(void)

{
  ushort uVar1;
  char *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  pcVar2 = *(char **)(unaff_EBP + 8);
  FUN_004692b6(unaff_EBP + 8,pcVar2);
  iVar3 = *(int *)(unaff_EBP + 8);
  if (iVar3 == *(int *)(extraout_ECX + 0x10)) {
    iVar3 = *(int *)(*(int *)(*(int *)(DAT_006e54dc + 0x28 + pcVar2[2] * 4) + 0xc) + *pcVar2 * 4);
    uVar5 = FUN_004670a4(CONCAT22((short)((uint)iVar3 >> 0x10),
                                  *(undefined2 *)(iVar3 + pcVar2[1] * 2)));
    **(undefined4 **)(unaff_EBP + 0xc) = uVar5;
    **(undefined4 **)(unaff_EBP + 0x10) = uVar5;
    **(undefined4 **)(unaff_EBP + 0x14) = 0;
    puVar8 = *(undefined4 **)(unaff_EBP + 0x18);
    *puVar8 = 0;
    uVar6 = (uint)puVar8 & 0xffffff00;
  }
  else {
    *(undefined1 *)(unaff_EBP + -0x20) = *(undefined1 *)(iVar3 + 0x10);
    *(undefined1 *)(unaff_EBP + -0x1f) = *(undefined1 *)(iVar3 + 0x11);
    *(undefined1 *)(unaff_EBP + -0x1e) = *(undefined1 *)(iVar3 + 0x12);
    *(undefined4 *)(unaff_EBP + -0x1c) = *(undefined4 *)(iVar3 + 0x14);
    *(undefined4 *)(unaff_EBP + -0x18) = *(undefined4 *)(iVar3 + 0x18);
    *(undefined4 *)(unaff_EBP + -0x14) = *(undefined4 *)(iVar3 + 0x1c);
    *(undefined4 *)(unaff_EBP + -0x10) = *(undefined4 *)(iVar3 + 0x20);
    *(undefined4 *)(unaff_EBP + -4) = 0;
    uVar7 = FUN_004670a4(*(undefined4 *)(unaff_EBP + -0x1c));
    puVar8 = *(undefined4 **)(unaff_EBP + 0xc);
    uVar5 = *(undefined4 *)(unaff_EBP + -0x18);
    uVar1 = *(ushort *)(unaff_EBP + -0x14);
    *puVar8 = uVar7;
    puVar4 = *(undefined4 **)(unaff_EBP + 0x14);
    *puVar4 = uVar5;
    if (uVar1 < 0xfffb) {
      uVar5 = FUN_004670a4(*(undefined4 *)(unaff_EBP + -0x14));
      **(undefined4 **)(unaff_EBP + 0x10) = uVar5;
      puVar8 = *(undefined4 **)(unaff_EBP + 0x18);
      *puVar8 = *(undefined4 *)(unaff_EBP + -0x10);
    }
    else {
      **(undefined4 **)(unaff_EBP + 0x10) = *puVar8;
      *puVar4 = 0;
      puVar8 = *(undefined4 **)(unaff_EBP + 0x18);
      *puVar8 = 0;
    }
    uVar6 = CONCAT31((int3)((uint)puVar8 >> 8),1);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar6;
}

