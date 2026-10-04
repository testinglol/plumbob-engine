
void FUN_00452674(undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined2 extraout_var;
  undefined **local_594 [3];
  undefined1 local_588 [260];
  undefined **local_484 [3];
  undefined1 local_478 [260];
  undefined **local_374;
  undefined4 local_370;
  undefined1 local_368 [256];
  undefined **local_268 [3];
  undefined1 local_25c [256];
  undefined **local_15c;
  undefined4 local_158;
  undefined1 local_150 [256];
  undefined **local_50 [3];
  undefined1 local_44 [64];
  
  FUN_0046f824(local_368,0,0x100);
  local_374 = &PTR_FUN_00666524;
  FUN_0046f824(local_25c,0,0x100);
  local_268[0] = &PTR_FUN_00666524;
  FUN_0046f847(s_Event___006c414c,0xffffffff);
  FUN_0046f8e4(local_268);
  iVar1 = DAT_006e5050;
  DAT_006e5050 = DAT_006e5050 + 1;
  FUN_0046fa40(iVar1);
  FUN_004d402a(local_370);
  FUN_0046f824(local_150,0,0x100);
  local_15c = &PTR_FUN_00666524;
  FUN_0046f824(local_478,0,0x104);
  local_484[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_588,0,0x104);
  local_594[0] = &PTR_FUN_006664e8;
  FUN_0046f824(local_44,0,0x40);
  local_50[0] = &PTR_FUN_0066651c;
  piVar2 = (int *)(**(code **)**(undefined4 **)(param_1 + 6))(CONCAT22(extraout_var,*param_1));
  FUN_0046f824(local_25c,0,0x100);
  local_268[0] = &PTR_FUN_00666524;
  FUN_0046f847(s_Tree__006c4144,0xffffffff);
  FUN_0046f8e4(local_268);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x24))(local_484);
    FUN_0041218d(local_484,local_594);
    FUN_0046f917(local_594,0xffffffff);
    FUN_0046f847(&DAT_006c0c28,0xffffffff);
  }
  FUN_004747c8(local_50);
  FUN_0046f917(local_50,0xffffffff);
  FUN_0046f847(&DAT_006c0c28,0xffffffff);
  FUN_0046fa40((int)(short)param_1[1]);
  FUN_004d402a(local_158);
  return;
}

