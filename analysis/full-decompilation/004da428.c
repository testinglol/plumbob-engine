
undefined4 FUN_004da428(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined **local_118;
  int local_114;
  undefined1 local_10c [256];
  undefined1 local_c;
  undefined1 local_b;
  undefined4 local_a;
  undefined2 uStack_6;
  
  local_b = 0;
  local_c = 0x20;
  local_a = 0;
  uStack_6 = 0;
  uVar1 = param_1[1];
  uVar2 = (**(code **)*param_1)();
  FUN_0046fb9b(local_10c,0x100);
  local_118 = &PTR_LAB_0066655c;
  FUN_0046f847(uVar1,uVar2);
  iVar3 = 0;
  while( true ) {
    iVar3 = FUN_0046fab1(&local_c,iVar3);
    if (iVar3 < 0) break;
    *(undefined1 *)(local_114 + iVar3) = 0x5f;
  }
  FUN_0046f8e4(&local_118);
  return 1;
}

