
void __thiscall FUN_00576c70(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  undefined4 *local_1c;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = (undefined4 *)*param_1;
  local_8 = (undefined4 *)*local_c;
  puVar1 = (undefined4 *)*param_2;
  param_2 = (undefined4 *)*puVar1;
  while( true ) {
    if (local_8 == local_c) {
      if (param_2 != puVar1) {
        puVar5 = local_8;
        local_1c = puVar1;
        FUN_00602c56(&param_2);
        uVar3 = extraout_ECX_00;
        FUN_00602c56(&local_c);
        FUN_00576c38(uVar3,puVar5);
      }
      return;
    }
    if (param_2 == puVar1) break;
    local_1c = local_8 + 2;
    cVar2 = FUN_00430155(param_2 + 2);
    puVar5 = param_2;
    if (cVar2 == '\0') {
      local_8 = (undefined4 *)*local_8;
      param_2 = puVar5;
    }
    else {
      local_1c = (undefined4 *)0x576cbc;
      local_1c = (undefined4 *)FUN_00576d28();
      local_1c = (undefined4 *)*local_1c;
      ppuVar4 = &local_1c;
      FUN_00602c56(&param_2);
      uVar3 = extraout_ECX;
      FUN_00602c56(&local_8);
      FUN_00576c38(uVar3,ppuVar4);
      param_2 = puVar5;
    }
  }
  return;
}

