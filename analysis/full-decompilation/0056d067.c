
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056d067(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar4;
  
  FUN_00634c24();
  fVar4 = (float10)FUN_004735bd(DAT_006e5490);
  *(float *)(unaff_EBP + -0x10) = (float)((float10)DAT_00673438 * (float10)_DAT_00666a48 + fVar4);
  iVar1 = FUN_005c38c0(unaff_EBP + -0x78,1,unaff_EBP + -0x10);
  FUN_00462f2f(iVar1);
  *(undefined4 *)(extraout_ECX + 0x1d8) = *(undefined4 *)(iVar1 + 0x40);
  FUN_005c4890();
  iVar1 = *(int *)(extraout_ECX + 0x24);
  *(undefined4 *)(unaff_EBP + -0x20) = 0x46fffe00;
  *(int *)(unaff_EBP + -0x10) =
       (iVar1 - *(int *)(extraout_ECX + 0x1c)) / 2 + *(int *)(extraout_ECX + 0x1c);
  iVar1 = *(int *)(unaff_EBP + -0x10);
  *(int *)(unaff_EBP + -0x10) = *(int *)(extraout_ECX + 0x28) + -0x14;
  *(float *)(unaff_EBP + -0x28) = (float)iVar1;
  *(float *)(unaff_EBP + -0x24) = (float)*(int *)(unaff_EBP + -0x10);
  iVar1 = FUN_00415707();
  puVar2 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x34,unaff_EBP + -0x28,iVar1 + 0xa8);
  *(undefined4 *)(unaff_EBP + -0x1c) = *puVar2;
  *(undefined4 *)(unaff_EBP + -0x18) = puVar2[1];
  *(undefined4 *)(unaff_EBP + -0x14) = puVar2[2];
  uVar3 = FUN_00462eea(unaff_EBP + -0x78,extraout_ECX + 0x200);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00462c01(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  uVar3 = FUN_00462f96(unaff_EBP + -0xbc,unaff_EBP + -0x1c);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00462c01(uVar3);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

