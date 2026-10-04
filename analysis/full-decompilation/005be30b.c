
undefined4 * FUN_005be30b(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_EBP;
  uint uVar4;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  *(undefined4 *)(unaff_EBP + -0x1c) = 0;
  *(undefined4 *)(unaff_EBP + -0x18) = 0;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x10) = 0;
  FUN_005bfbfb(8);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_005bfb53();
  piVar1 = *(int **)(unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 2;
  iVar3 = (**(code **)(*piVar1 + 0x1c))();
  uVar4 = iVar3 * 2;
  if (uVar4 < 0x201) {
    *(undefined4 *)(unaff_EBP + 0xc) = 0x200;
    FUN_005c05a6(piVar1,unaff_EBP + -0x428,unaff_EBP + 0xc,0x10);
    FUN_005bfc36(unaff_EBP + -0x428,unaff_EBP + -0x428 + *(int *)(unaff_EBP + 0xc) * 2);
  }
  else {
    FUN_005bfad6(uVar4);
    *(undefined1 *)(unaff_EBP + -4) = 3;
    *(uint *)(unaff_EBP + 0xc) = uVar4;
    FUN_005c05a6(piVar1,*(undefined4 *)(unaff_EBP + -0x28),unaff_EBP + 0xc,0x10);
    FUN_005bfc36(*(int *)(unaff_EBP + -0x28),
                 *(int *)(unaff_EBP + -0x28) + *(int *)(unaff_EBP + 0xc) * 2);
    *(undefined1 *)(unaff_EBP + -4) = 2;
    FUN_004d4185();
  }
  puVar2 = *(undefined4 **)(unaff_EBP + 8);
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  *(undefined1 *)(unaff_EBP + -4) = 4;
  FUN_005bfb88(*(undefined4 *)(unaff_EBP + -0x18),*(undefined4 *)(unaff_EBP + -0x14));
  *(undefined4 *)(unaff_EBP + -0x1c) = 1;
  *(undefined1 *)(unaff_EBP + -4) = 0;
  FUN_005bdc4a();
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return puVar2;
}

