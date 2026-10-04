
undefined4 __thiscall FUN_005eb3f9(int *param_1,int param_2,char param_3)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 local_14;
  undefined4 local_10;
  int *local_c;
  undefined4 local_8;
  
  if (param_2 != -1) {
    if (param_2 < 0) {
      param_2 = 0;
    }
    else if (param_2 < (param_1[0x65] - param_1[100]) / 0x28) goto LAB_005eb451;
    if ((param_1[0x65] - param_1[100]) / 0x28 <= param_2) {
      param_2 = (param_1[0x65] - param_1[100]) / 0x28 + -1;
    }
  }
LAB_005eb451:
  if (param_2 != param_1[0x35]) {
    param_1[0x35] = param_2;
  }
  puVar2 = (undefined4 *)param_1[0x12];
  if ((puVar2 != (undefined4 *)0x0) && (cVar1 = FUN_005da398(puVar2), cVar1 != '\0')) {
    local_8 = 0;
    local_14 = 3;
    local_10 = 0xe;
    local_c = param_1;
    (**(code **)*puVar2)(&local_14);
  }
  if (param_3 == '\0') {
    (**(code **)(*param_1 + 0x168))();
    return 1;
  }
  puVar2 = (undefined4 *)param_1[0x12];
  if (puVar2 != (undefined4 *)0x0) {
    if (param_1[0x35] == -1) {
      if ((puVar2 == (undefined4 *)0x0) || (cVar1 = FUN_005da398(puVar2), cVar1 == '\0'))
      goto LAB_005eb509;
      puVar2 = (undefined4 *)*puVar2;
      local_10 = 0x10;
    }
    else {
      if ((puVar2 == (undefined4 *)0x0) || (cVar1 = FUN_005da398(puVar2), cVar1 == '\0'))
      goto LAB_005eb509;
      puVar2 = (undefined4 *)*puVar2;
      local_10 = 0xf;
    }
    local_8 = 0;
    local_14 = 3;
    local_c = param_1;
    (*(code *)*puVar2)(&local_14);
  }
LAB_005eb509:
  if (param_1[0x60] != 0) {
    (**(code **)(*param_1 + 0x26c))();
  }
  return 1;
}

