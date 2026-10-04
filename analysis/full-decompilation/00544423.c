
void __thiscall FUN_00544423(int *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  
  piVar4 = (int *)param_1[0x36];
  while( true ) {
    if (piVar4 == (int *)param_1[0x37]) {
      return;
    }
    if (*(int *)(*piVar4 + 0x1b4) == param_2) break;
    piVar4 = piVar4 + 1;
  }
  if (param_1[0x43] != -1) {
    FUN_005e46f0(0);
  }
  iVar3 = (int)piVar4 - param_1[0x36] >> 2;
  param_1[0x43] = iVar3;
  if (iVar3 < 6) {
    param_1[0x40] = 0;
  }
  else {
    param_1[0x40] = iVar3 - (int)(CONCAT44((int)piVar4 - param_1[0x36] >> 0x1f,iVar3) % 6);
  }
  FUN_005e46f0(1);
  if ((int *)param_1[0x39] != (int *)0x0) {
    iVar3 = *(int *)param_1[0x39];
    if ((uint)(param_1[0x37] - param_1[0x36] >> 2) < 7) {
      (**(code **)(iVar3 + 0x98))();
    }
    else {
      (**(code **)(iVar3 + 0x94))();
      (**(code **)(*(int *)param_1[0x39] + 0x1ac))(0);
      (**(code **)(*(int *)param_1[0x39] + 0x1b0))((param_1[0x37] - param_1[0x36] >> 2) + -6);
      (**(code **)(*(int *)param_1[0x39] + 0x1a8))(param_1[0x40]);
      (**(code **)(*(int *)param_1[0x39] + 0x1d4))(6);
    }
  }
  FUN_00544228();
  (**(code **)(*param_1 + 0x168))();
  local_c = param_1[0x43];
  local_14 = 3;
  local_10 = 0x15;
  puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x18))();
  if (puVar2 == (undefined4 *)0x0) {
    return;
  }
  cVar1 = FUN_005da398(puVar2);
  if (cVar1 == '\0') {
    return;
  }
  (**(code **)*puVar2)(&local_14);
  return;
}

