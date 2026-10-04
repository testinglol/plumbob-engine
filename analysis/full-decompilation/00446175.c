
void __fastcall FUN_00446175(int param_1)

{
  int *piVar1;
  int *local_c;
  
  if (*(int *)(param_1 + 200) != 0) {
    FUN_0044387c(*(undefined4 *)(param_1 + 200));
    if (*(int **)(param_1 + 200) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 200) + 0x10))(1);
    }
    *(undefined4 *)(param_1 + 200) = 0;
  }
  if (*(int *)(param_1 + 0xcc) != 0) {
    FUN_0044387c(*(undefined4 *)(param_1 + 0xcc));
    if (*(int **)(param_1 + 0xcc) != (int *)0x0) {
      (**(code **)(**(int **)(param_1 + 0xcc) + 0x10))(1);
    }
    *(undefined4 *)(param_1 + 0xcc) = 0;
  }
  piVar1 = *(int **)(param_1 + 0xd4);
  for (local_c = *(int **)(param_1 + 0xd0); local_c != piVar1; local_c = local_c + 1) {
    FUN_0044387c(*local_c);
    if ((int *)*local_c != (int *)0x0) {
      (**(code **)(*(int *)*local_c + 0x10))(1);
    }
  }
  FUN_00448aa5(*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4));
  piVar1 = *(int **)(param_1 + 0xe0);
  for (local_c = *(int **)(param_1 + 0xdc); local_c != piVar1; local_c = local_c + 1) {
    FUN_0044387c(*local_c);
    if ((int *)*local_c != (int *)0x0) {
      (**(code **)(*(int *)*local_c + 0x10))(1);
    }
  }
  FUN_00448aa5(*(undefined4 *)(param_1 + 0xdc),*(undefined4 *)(param_1 + 0xe0));
  return;
}

