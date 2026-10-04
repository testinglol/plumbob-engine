
undefined4 __thiscall FUN_005eb101(int *param_1,int param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  if (param_2 == 0x1b) {
    puVar1 = (undefined4 *)param_1[0x12];
    param_1[0x35] = -1;
    if (puVar1 != (undefined4 *)0x0) {
      cVar2 = FUN_005da398(puVar1);
      if (cVar2 != '\0') {
        local_8 = 0;
        local_14 = 3;
        local_10 = 0x10;
        local_c = 0x1b;
        (**(code **)*puVar1)(&local_14);
      }
    }
    (**(code **)(*param_1 + 0x26c))();
    uVar3 = 1;
  }
  else {
    puVar1 = (undefined4 *)param_1[0x12];
    if (puVar1 != (undefined4 *)0x0) {
      cVar2 = FUN_005da398(puVar1);
      if (cVar2 != '\0') {
        local_8 = 0;
        local_14 = 3;
        local_10 = 0x12;
        local_c = param_2;
        (**(code **)*puVar1)(&local_14);
      }
    }
    uVar3 = 0;
  }
  return uVar3;
}

