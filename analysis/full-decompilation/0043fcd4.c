
void __thiscall FUN_0043fcd4(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *local_c;
  undefined4 *local_8;
  
  for (local_c = *(int **)(param_1 + 0x30); local_c != (int *)0x0; local_c = (int *)local_c[0x38]) {
    (**(code **)(*local_c + 0x44))(param_2);
  }
  FUN_00445e8a();
  *(undefined1 *)(param_1 + 0x11) = 1;
  uVar1 = FUN_00445724();
  FUN_0044668c(uVar1);
  for (local_8 = *(undefined4 **)(param_1 + 0x84); local_8 != *(undefined4 **)(param_1 + 0x88);
      local_8 = local_8 + 1) {
    FUN_00446f29(*local_8);
  }
  return;
}

