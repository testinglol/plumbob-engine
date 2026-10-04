
undefined4 * __thiscall FUN_00445897(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *local_48;
  int local_18;
  int *local_14;
  undefined4 *local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = FUN_0045741b();
  FUN_004497ed(&local_18,&local_c);
  local_8 = local_18;
  if (local_18 == *(int *)(param_1 + 0x70)) {
    local_48 = operator_new(0xc);
    if (local_48 == (undefined4 *)0x0) {
      local_48 = (undefined4 *)0x0;
    }
    else {
      *local_48 = 0;
      local_48[1] = 0;
      local_48[2] = 0;
    }
    local_10 = local_48;
    for (local_14 = *(int **)(param_1 + 0x18); local_14 != *(int **)(param_1 + 0x1c);
        local_14 = local_14 + 1) {
      if ((*local_14 != 0) && (*(int *)(*local_14 + 0x11c) == param_2)) {
        FUN_0044845a(local_14);
      }
    }
    puVar1 = (undefined4 *)FUN_004485c2(&local_c);
    *puVar1 = local_10;
  }
  else {
    local_10 = *(undefined4 **)(local_18 + 0x14);
  }
  return local_10;
}

