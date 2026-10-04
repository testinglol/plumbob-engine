
void __thiscall FUN_004b978e(int param_1,undefined4 param_2)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  int local_8;
  
  *(undefined4 *)(param_1 + 0x18) = param_2;
  __ftol();
  local_8 = 0;
  if (0 < *(int *)(param_1 + 0xc)) {
    puVar2 = (undefined2 *)(param_1 + 0xc20);
    do {
      uVar1 = FUN_00438f12();
      local_8 = local_8 + 1;
      *puVar2 = uVar1;
      puVar2 = puVar2 + 1;
    } while (local_8 < *(int *)(param_1 + 0xc));
  }
  return;
}

