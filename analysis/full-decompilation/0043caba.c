
undefined4 __thiscall FUN_0043caba(int param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  piVar2 = *(int **)(param_1 + 0x20);
  local_8 = param_1 + 0x20;
  while( true ) {
    if (piVar2 == *(int **)(param_1 + 0x24)) {
      return 0;
    }
    if (*piVar2 == param_2) break;
    piVar2 = piVar2 + 1;
  }
  uVar1 = FUN_0045741b();
  FUN_0040766a(0x104,uVar1);
  FUN_0040766a(0xe0,0);
  param_2 = FUN_0045741b();
  FUN_0043b923(*piVar2);
  FUN_00575b11(&local_10,&param_2);
  if (local_10 != 0) {
    local_18 = local_10;
    local_14 = local_c;
    FUN_0057644e(&local_18);
  }
  FUN_005db2f2(piVar2);
  return 1;
}

