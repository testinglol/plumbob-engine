
undefined1 * FUN_0053f472(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 local_14;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  
  local_14 = 0;
  if (param_3 == 0) {
    local_14 = 0xff00;
    puVar1 = &local_14;
  }
  else if (param_3 == 2) {
    local_10 = 0xff;
    local_f = 0;
    local_e = 0;
    puVar1 = (undefined4 *)&local_10;
  }
  else if (param_3 == 4) {
    local_c = 0xff;
    local_b = 0xff;
    local_a = 0;
    puVar1 = (undefined4 *)&local_c;
  }
  else if (param_3 == 6) {
    local_7 = 0xff;
    local_8 = 0;
    local_6 = 0;
    puVar1 = (undefined4 *)&local_8;
  }
  else {
    if (param_3 != 7) {
      *param_1 = *param_2;
      param_1[1] = param_2[1];
      param_1[2] = param_2[2];
      return param_1;
    }
    param_3 = 0xff;
    puVar1 = &param_3;
  }
  FUN_0046185f(param_1,puVar1);
  return param_1;
}

