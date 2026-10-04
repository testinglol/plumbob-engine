
undefined4 __thiscall FUN_0043fb5b(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *local_18;
  undefined4 *local_14;
  
  uVar1 = *(undefined4 *)(DAT_006e486c + 0x44);
  *(undefined1 *)(param_1 + 0x11) = 0;
  FUN_00445fc4();
  FUN_0043df8d(param_2);
  for (local_18 = *(int **)(param_1 + 0x30); local_18 != (int *)0x0;
      local_18 = (int *)local_18[0x38]) {
    (**(code **)(*local_18 + 0x48))();
  }
  uVar1 = FUN_00449c40(param_1,param_2,0x4f626a4d,1,uVar1);
  FUN_00445e8a();
  *(undefined1 *)(param_1 + 0x11) = 1;
  uVar2 = FUN_00445724();
  FUN_0044668c(uVar2);
  for (local_14 = *(undefined4 **)(param_1 + 0x84); local_14 != *(undefined4 **)(param_1 + 0x88);
      local_14 = local_14 + 1) {
    FUN_00446f29(*local_14);
  }
  return uVar1;
}

