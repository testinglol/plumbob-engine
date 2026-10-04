
void __thiscall FUN_004728b5(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *local_c;
  int *piStack_8;
  
  puVar1 = (undefined4 *)*param_1;
  if ((param_1[1] - (int)puVar1) / 0x14 != 0) {
    local_c = param_1;
    piStack_8 = param_1;
    puVar2 = (undefined4 *)FUN_0047270c(&local_c,param_2);
    *puVar1 = *puVar2;
    puVar1[1] = puVar2[1];
  }
  return;
}

