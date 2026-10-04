
void FUN_005cfaaf(uint param_1,undefined4 param_2)

{
  undefined4 uVar1;
  byte bVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  uVar1 = param_1;
  puVar3 = (undefined4 *)FUN_005caed9();
  uVar6 = *puVar3;
  uVar7 = puVar3[1];
  bVar2 = FUN_005caf08();
  param_1 = (uint)bVar2;
  uVar4 = FUN_00401f77();
  uVar8 = 0;
  uVar5 = FUN_005caf0c(param_2,param_1,uVar6,uVar7,uVar4,0);
  FUN_005cfafc(uVar1,uVar5,param_2,param_1,uVar6,uVar7,uVar4,uVar8);
  return;
}

