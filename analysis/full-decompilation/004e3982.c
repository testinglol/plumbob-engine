
void FUN_004e3982(void)

{
  undefined **ppuVar1;
  int iVar2;
  undefined **ppuVar3;
  undefined4 uVar4;
  int unaff_EBP;
  undefined *puVar5;
  undefined **local_240;
  
  FUN_00634c24();
  local_240 = (undefined **)0x4e39af;
  FUN_0046f824();
  *(undefined ***)(unaff_EBP + -0x124) = &PTR_FUN_00666524;
  FUN_005b8680();
  ppuVar1 = *(undefined ***)(unaff_EBP + 8);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_004ea53c();
  local_240 = (undefined **)0x4e39e8;
  FUN_0046f824();
  *(undefined ***)(unaff_EBP + -0x230) = &PTR_FUN_00666524;
  FUN_0046f847();
  FUN_0046f8e4();
  FUN_0046fa40();
  FUN_0046f847();
  FUN_004e3901();
  FUN_0046fa40();
  FUN_005d4bbf();
  FUN_004e9a99();
  local_240 = (undefined **)0x4e3a6a;
  _strlen(s_description_006c9af8);
  FUN_00412d8a();
  FUN_004e9b56();
  local_240 = (undefined **)0x4e3a8a;
  iVar2 = FUN_004e3901();
  local_240 = (undefined **)(uint)(iVar2 == 0);
  FUN_004eaa9b(ppuVar1);
  iVar2 = FUN_004e3901(2);
  FUN_004eabf6(ppuVar1,iVar2 == 0);
  iVar2 = FUN_004e3901(3);
  if (iVar2 == 0) {
    *(undefined ****)(unaff_EBP + 8) = &local_240;
    FUN_0040f49d();
    puVar5 = &DAT_006c1010;
  }
  else if (iVar2 == 1) {
    *(undefined ****)(unaff_EBP + 8) = &local_240;
    FUN_0040f49d();
    puVar5 = &DAT_006c100c;
  }
  else {
    if (iVar2 != 2) goto LAB_004e3b20;
    *(undefined ****)(unaff_EBP + 8) = &local_240;
    FUN_0040f49d();
    puVar5 = &DAT_006c1008;
  }
  local_240 = &PTR_FUN_00666634;
  FUN_0046f8cb(puVar5);
  FUN_004eac8c(ppuVar1);
LAB_004e3b20:
  iVar2 = FUN_004eacb7();
  ppuVar3 = (undefined **)FUN_004ead68();
  if ((iVar2 == 0) || (ppuVar3 == (undefined **)0x0)) {
    FUN_004e334f();
  }
  else {
    FUN_004e3901();
    local_240 = (undefined **)0x4e3b47;
    FUN_004eacf0();
    local_240 = ppuVar3;
    uVar4 = FUN_004e3901();
    FUN_004eada1(ppuVar1,uVar4);
  }
  local_240 = ppuVar1;
  FUN_004ea674();
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  FUN_005b8770();
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return;
}

