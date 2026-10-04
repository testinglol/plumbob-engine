
void FUN_00465150(undefined4 param_1)

{
  undefined4 *local_8;
  
  local_8 = operator_new(0x10);
  if (local_8 == (undefined4 *)0x0) {
    local_8 = (undefined4 *)0x0;
  }
  else {
    *local_8 = 0;
    local_8[1] = 0;
    local_8[2] = 0;
    local_8[3] = param_1;
  }
  FUN_00465323(&local_8);
  return;
}

