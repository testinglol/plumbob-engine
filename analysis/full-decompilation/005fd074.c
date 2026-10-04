
void FUN_005fd074(void)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  int extraout_ECX;
  int unaff_EBP;
  
  FUN_00634c24();
  uVar4 = *(int *)(extraout_ECX + 8) - *(int *)(extraout_ECX + 4) >> 2;
  *(undefined1 **)(unaff_EBP + -0x10) = &stack0xffffffd8;
  *(uint *)(unaff_EBP + -0x14) = uVar4;
  if (uVar4 < *(uint *)(unaff_EBP + 8)) {
    uVar4 = FUN_00402aa0(*(undefined4 *)(unaff_EBP + 8));
    *(uint *)(unaff_EBP + -0x1c) = uVar4;
    if (*(uint *)(unaff_EBP + -0x14) < uVar4) {
      *(undefined1 *)(unaff_EBP + 0xb) = *(undefined1 *)(unaff_EBP + 0xb);
      *(undefined4 *)(unaff_EBP + -0x18) = 0;
      FUN_0054821c(uVar4,unaff_EBP + 0xb);
      *(undefined4 *)(unaff_EBP + -4) = 0;
      uVar5 = FUN_005fd5b4(*(undefined4 *)(unaff_EBP + -0x28),uVar4,unaff_EBP + -0x18,
                           *(undefined4 *)(unaff_EBP + 8));
      *(undefined4 *)(unaff_EBP + -0x24) = uVar5;
      *(undefined4 *)(unaff_EBP + -4) = 1;
      *(undefined1 *)(unaff_EBP + -4) = 2;
      for (uVar4 = 0; uVar4 < *(uint *)(unaff_EBP + -0x14); uVar4 = uVar4 + 1) {
        while( true ) {
          puVar1 = *(undefined4 **)(*(int *)(extraout_ECX + 4) + uVar4 * 4);
          if (puVar1 == (undefined4 *)0x0) break;
          uVar2 = puVar1[1];
          uVar3 = *(uint *)(unaff_EBP + -0x1c);
          *(undefined4 *)(*(int *)(extraout_ECX + 4) + uVar4 * 4) = *puVar1;
          iVar6 = (uVar2 % uVar3) * 4;
          *puVar1 = *(undefined4 *)(iVar6 + *(int *)(unaff_EBP + -0x28));
          *(undefined4 **)(iVar6 + *(int *)(unaff_EBP + -0x28)) = puVar1;
        }
      }
      FUN_005bfaad(unaff_EBP + -0x28);
      *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
      for (iVar6 = *(int *)(unaff_EBP + -0x28); iVar6 != *(int *)(unaff_EBP + -0x24);
          iVar6 = iVar6 + 4) {
      }
      FUN_0048c4c9();
    }
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

