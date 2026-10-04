
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056d698(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int extraout_ECX;
  int unaff_EBP;
  float10 fVar6;
  
  FUN_00634c24();
  if ((*(char *)(extraout_ECX + 0x221) == '\0') && (*(char *)(extraout_ECX + 0x220) == '\0')) {
    fVar6 = (float10)FUN_004735bd(DAT_006e5490);
    *(float *)(unaff_EBP + -0x10) = (float)((float10)DAT_00673438 * (float10)_DAT_00666a48 + fVar6);
    iVar3 = FUN_005c38c0(unaff_EBP + -0x78,1,unaff_EBP + -0x10);
    FUN_00462f2f(iVar3);
    *(undefined4 *)(extraout_ECX + 500) = *(undefined4 *)(iVar3 + 0x40);
    FUN_005c4890();
  }
  else {
    FUN_00462f2f(&DAT_006fe6d0);
    *(undefined4 *)(extraout_ECX + 500) = DAT_006fe710;
  }
  iVar3 = 0x14;
  if ((*(char *)(extraout_ECX + 0x220) == '\0') && (*(char *)(extraout_ECX + 0x221) == '\0')) {
LAB_0056d74f:
    if (*(char *)(extraout_ECX + 0x220) == '\0') {
      *(int *)(unaff_EBP + -0x10) =
           (*(int *)(extraout_ECX + 0x24) - *(int *)(extraout_ECX + 0x1c)) / 2 +
           *(int *)(extraout_ECX + 0x1c);
      iVar1 = *(int *)(unaff_EBP + -0x10);
      goto LAB_0056d781;
    }
  }
  else {
    iVar3 = 0x32;
    if (*(char *)(extraout_ECX + 0x221) == '\0') goto LAB_0056d74f;
  }
  *(int *)(unaff_EBP + -0x10) =
       (*(int *)(extraout_ECX + 0x24) - *(int *)(extraout_ECX + 0x1c)) / 2 + -0x14 +
       *(int *)(extraout_ECX + 0x1c);
  iVar1 = *(int *)(unaff_EBP + -0x10);
LAB_0056d781:
  iVar2 = *(int *)(extraout_ECX + 0x28);
  *(undefined4 *)(unaff_EBP + -0x14) = 0x46fffe00;
  *(float *)(unaff_EBP + -0x1c) = (float)iVar1;
  *(int *)(unaff_EBP + -0x10) = iVar2 - iVar3;
  *(float *)(unaff_EBP + -0x18) = (float)*(int *)(unaff_EBP + -0x10);
  iVar3 = FUN_00415707();
  puVar4 = (undefined4 *)FUN_005c3840(unaff_EBP + -0x34,unaff_EBP + -0x1c,iVar3 + 0xa8);
  *(undefined4 *)(unaff_EBP + -0x28) = *puVar4;
  *(undefined4 *)(unaff_EBP + -0x24) = puVar4[1];
  *(undefined4 *)(unaff_EBP + -0x20) = puVar4[2];
  uVar5 = FUN_00462eea(unaff_EBP + -0x78,extraout_ECX + 0x21c);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00462c01(uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  uVar5 = FUN_00462f96(unaff_EBP + -0xbc,unaff_EBP + -0x28);
  *(undefined4 *)(unaff_EBP + -4) = 1;
  FUN_00462c01(uVar5);
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005c4890();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

