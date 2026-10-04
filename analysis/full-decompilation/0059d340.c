
void FUN_0059d340(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int extraout_ECX;
  int unaff_EBP;
  undefined4 *unaff_FS_OFFSET;
  
  FUN_00634c24();
  piVar1 = (int *)(extraout_ECX + 4);
  uVar3 = *(int *)(extraout_ECX + 8) - *(int *)(extraout_ECX + 4) >> 2;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd0;
  *(int *)(unaff_EBP + -0x24) = extraout_ECX;
  *(uint *)(unaff_EBP + -0x1c) = uVar3;
  if (uVar3 < *(uint *)(unaff_EBP + 8)) {
    uVar4 = FUN_00402aa0(*(undefined4 *)(unaff_EBP + 8));
    *(uint *)(unaff_EBP + -0x20) = uVar4;
    if (uVar3 < uVar4) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      *(undefined1 *)(unaff_EBP + 0xb) = *(undefined1 *)(unaff_EBP + 0xb);
      FUN_0054821c(uVar4,unaff_EBP + 0xb);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar5 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x30),uVar4,unaff_EBP + -0x18,
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x2c) = uVar5;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      uVar3 = 0;
      while (*(uint *)(unaff_EBP + -0x14) = uVar3, uVar3 < *(uint *)(unaff_EBP + -0x1c)) {
        iVar7 = *piVar1;
        while (puVar2 = *(undefined4 **)(uVar3 * 4 + iVar7), puVar2 != (undefined4 *)0x0) {
          uVar6 = FUN_005b8dba(puVar2[1]);
          uVar4 = *(uint *)(unaff_EBP + -0x20);
          *(undefined4 *)(uVar3 * 4 + *piVar1) = *puVar2;
          iVar7 = (uVar6 % uVar4) * 4;
          *puVar2 = *(undefined4 *)(iVar7 + *(int *)(unaff_EBP + -0x30));
          *(undefined4 **)(iVar7 + *(int *)(unaff_EBP + -0x30)) = puVar2;
          iVar7 = *piVar1;
        }
        uVar3 = *(int *)(unaff_EBP + -0x14) + 1;
      }
      FUN_005bfaad(unaff_EBP + -0x30);
      FUN_0048c4c9();
    }
  }
  *unaff_FS_OFFSET = *(undefined4 *)(unaff_EBP + -0xc);
  return;
}

