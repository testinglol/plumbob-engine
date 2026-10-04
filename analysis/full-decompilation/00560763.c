
undefined4 FUN_00560763(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **local_11c;
  int local_118;
  undefined1 local_110 [260];
  undefined1 local_c;
  undefined1 local_b;
  undefined4 local_a;
  undefined2 uStack_6;
  
  local_b = 0;
  local_c = 0x2f;
  local_a = 0;
  uStack_6 = 0;
  uVar1 = param_1[1];
  uVar2 = (**(code **)*param_1)();
  FUN_0046fb9b(local_110,0x104);
  local_11c = &PTR_LAB_00666cdc;
  FUN_0046f847(uVar1,uVar2);
  iVar3 = 0;
  while( true ) {
    iVar3 = FUN_0046fab1(&local_c,iVar3);
    if (iVar3 < 0) break;
    *(undefined1 *)(local_118 + iVar3) = 0x5c;
  }
  FUN_0046f8e4(&local_11c);
  return 1;
}

