
undefined4 __thiscall FUN_005d9884(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 local_14;
  undefined4 *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x24);
  cVar2 = FUN_005da398(puVar1);
  if (cVar2 != '\0') {
    local_c = 0;
    local_8 = 0;
    local_14 = 0x14;
    local_10 = param_2;
    (**(code **)*puVar1)(&local_14);
  }
  *(undefined4 **)(param_1 + 0x24) = param_2;
  if (param_2 != (undefined4 *)0x0) {
    cVar2 = FUN_005da398(param_2);
    if (cVar2 != '\0') {
      local_c = 0;
      local_8 = 0;
      local_14 = 0x15;
      local_10 = puVar1;
      (**(code **)*param_2)(&local_14);
    }
    (**(code **)(**(int **)(param_1 + 0x24) + 0x18))();
  }
  return *(undefined4 *)(param_1 + 0x24);
}

