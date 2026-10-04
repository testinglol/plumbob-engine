
void FUN_0062b9b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_005a9320(0x48);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[0xe] = param_1;
    puVar1[0x10] = param_2;
    puVar1[0xf] = param_2;
    puVar1[8] = param_3;
    puVar1[9] = param_4;
    puVar1[10] = param_5;
    puVar1[6] = 0;
    puVar1[4] = 0;
    *puVar1 = 0;
    puVar1[2] = 0;
    puVar1[0xb] = param_6;
    puVar1[0xc] = 0;
    puVar1[7] = 0;
    puVar1[5] = 0;
    puVar1[1] = 0;
    puVar1[3] = 0x3ff00000;
    puVar1[0xd] = 0;
    puVar1[0x11] = 0;
  }
  return;
}

