
void FUN_00533ee8(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *puVar5;
  
  FUN_00634c24();
  uVar4 = *(undefined4 *)(extraout_ECX + 0x100);
  *(undefined4 *)(unaff_EBP + -0x44) = *(undefined4 *)(extraout_ECX + 0x13c);
  iVar3 = FUN_00534a16(uVar4,*(undefined4 *)(extraout_ECX + 0x104),unaff_EBP + -0x44,0);
  if (iVar3 == *(int *)(extraout_ECX + 0x104)) {
    FUN_0053426c(*(undefined4 *)(extraout_ECX + 0x100),*(undefined4 *)(extraout_ECX + 0x104));
  }
  if (0 < *(int *)(unaff_EBP + 0xc)) {
    *(int *)(unaff_EBP + 0xc) = *(int *)(unaff_EBP + 0xc);
    puVar5 = (undefined4 *)(*(int *)(unaff_EBP + 8) + 0xc);
    do {
      uVar4 = puVar5[-2];
      *(undefined4 *)(unaff_EBP + -0x2c) = *(undefined4 *)(extraout_ECX + 0x13c);
      uVar2 = puVar5[-1];
      *(undefined4 *)(unaff_EBP + -0x24) = 0;
      *(undefined4 *)(unaff_EBP + -0x28) = uVar2;
      uVar2 = *puVar5;
      *(undefined4 *)(unaff_EBP + -0x18) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x20) = uVar2;
      uVar2 = puVar5[-3];
      *(undefined4 *)(unaff_EBP + -0x10) = uVar4;
      *(undefined4 *)(unaff_EBP + -0x1c) = uVar2;
      *(undefined4 *)(unaff_EBP + -0x14) = uVar2;
      FUN_005d48d9();
      *(undefined4 *)(unaff_EBP + -0x5c) = *(undefined4 *)(unaff_EBP + -0x14);
      *(undefined4 *)(unaff_EBP + -0x58) = *(undefined4 *)(unaff_EBP + -0x10);
      uVar4 = *(undefined4 *)(extraout_ECX + 0xf8);
      uVar2 = *(undefined4 *)(extraout_ECX + 0xf4);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar4 = FUN_00534a58(uVar2,uVar4,unaff_EBP + -0x6c,&LAB_00533e8e,0);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      *(undefined4 *)(unaff_EBP + 8) = uVar4;
      FUN_005b8770();
      if (*(int *)(unaff_EBP + 8) != *(int *)(extraout_ECX + 0xf8)) {
        uVar4 = FUN_004096c2();
        *(undefined4 *)(unaff_EBP + -0x24) = uVar4;
      }
      FUN_00534195(unaff_EBP + -0x2c);
      puVar5 = puVar5 + 4;
      piVar1 = (int *)(unaff_EBP + 0xc);
      *piVar1 = *piVar1 + -1;
    } while (*piVar1 != 0);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

