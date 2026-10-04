
void __fastcall FUN_00445fc4(int param_1)

{
  undefined2 uVar1;
  int *piVar2;
  int *local_c;
  
  if (*(int *)(param_1 + 200) != 0) {
    uVar1 = *(undefined2 *)(*(int *)(param_1 + 200) + 0xf0);
    (**(code **)(**(int **)(param_1 + 200) + 0x50))(1);
    FUN_00440f2b(uVar1,0);
    *(undefined4 *)(param_1 + 200) = 0;
  }
  if (*(int *)(param_1 + 0xcc) != 0) {
    uVar1 = *(undefined2 *)(*(int *)(param_1 + 0xcc) + 0xf0);
    (**(code **)(**(int **)(param_1 + 0xcc) + 0x50))(1);
    FUN_00440f2b(uVar1,0);
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  piVar2 = *(int **)(param_1 + 0xd4);
  for (local_c = *(int **)(param_1 + 0xd0); local_c != piVar2; local_c = local_c + 1) {
    uVar1 = *(undefined2 *)(*local_c + 0xf0);
    (**(code **)(*(int *)*local_c + 0x50))(1);
    FUN_00440f2b(uVar1,0);
  }
  FUN_00448aa5(*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4));
  piVar2 = *(int **)(param_1 + 0xe0);
  for (local_c = *(int **)(param_1 + 0xdc); local_c != piVar2; local_c = local_c + 1) {
    uVar1 = *(undefined2 *)(*local_c + 0xf0);
    (**(code **)(*(int *)*local_c + 0x50))(1);
    FUN_00440f2b(uVar1,0);
  }
  FUN_00448aa5(*(undefined4 *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xe0));
  return;
}

