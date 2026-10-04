
void FUN_00596177(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int extraout_ECX;
  int unaff_EBP;
  int iVar4;
  
  FUN_00634c24();
  iVar4 = *(int *)(unaff_EBP + 0xc);
  *(float *)(unaff_EBP + 0xc) = -*(float *)(iVar4 + 0xc);
  FUN_005c4840(iVar4,iVar4 + 4,iVar4 + 8,unaff_EBP + 0xc);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar3 = (undefined4 *)FUN_00590a83(unaff_EBP + -0x28,unaff_EBP + -0x38);
  puVar1 = (undefined4 *)(extraout_ECX + 0x58);
  *puVar1 = *puVar3;
  *(undefined4 *)(extraout_ECX + 0x5c) = puVar3[1];
  uVar2 = puVar3[3];
  *(undefined4 *)(extraout_ECX + 0x60) = puVar3[2];
  *(undefined4 *)(extraout_ECX + 100) = uVar2;
  FUN_005c4890();
  *(float *)(extraout_ECX + 100) = -*(float *)(extraout_ECX + 100);
  puVar3 = (undefined4 *)FUN_005962a1(unaff_EBP + -0x24,extraout_ECX + 0x30,iVar4);
  *(undefined4 *)(unaff_EBP + -0x18) = *puVar3;
  *(undefined4 *)(unaff_EBP + -0x14) = puVar3[1];
  *(undefined4 *)(unaff_EBP + -0x10) = puVar3[2];
  puVar3 = (undefined4 *)
           FUN_0045ef64(unaff_EBP + -0x24,*(undefined4 *)(unaff_EBP + 8),unaff_EBP + -0x18);
  *(undefined4 *)(extraout_ECX + 0x4c) = *puVar3;
  uVar2 = puVar3[2];
  *(undefined4 *)(extraout_ECX + 0x50) = puVar3[1];
  *(undefined4 *)(extraout_ECX + 0x54) = uVar2;
  FUN_00596270(puVar1,extraout_ECX + 0xc4);
  *(int *)(extraout_ECX + 0x130) = *(int *)(extraout_ECX + 0x130) + 1;
  for (iVar4 = *(int *)(extraout_ECX + 0x28); iVar4 != 0; iVar4 = *(int *)(iVar4 + 0x20)) {
    FUN_00596177((undefined4 *)(extraout_ECX + 0x4c),puVar1);
  }
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

