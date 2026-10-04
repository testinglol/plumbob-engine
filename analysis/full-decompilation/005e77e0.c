
void __thiscall FUN_005e77e0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined1 local_18 [8];
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  uVar1 = param_2;
  FUN_00601485(&local_8,&param_2);
  if (local_8 != *(int *)(param_1 + 0x1c)) {
    (**(code **)(**(int **)(param_1 + 8) + 0x14))(*(undefined4 *)(local_8 + 0x14));
  }
  local_c = param_3;
  local_10 = uVar1;
  FUN_004c662a(local_18,&local_10);
  return;
}

