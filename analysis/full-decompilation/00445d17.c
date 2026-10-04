
void __fastcall FUN_00445d17(int param_1)

{
  short sVar1;
  int local_8;
  
  FUN_00445e6e();
  for (local_8 = 0; local_8 != *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x18) >> 2;
      local_8 = local_8 + 1) {
    if (*(int *)(*(int *)(param_1 + 0x18) + local_8 * 4) != 0) {
      if (*(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x18) + local_8 * 4) + 0x118) + 0x12) == 2
         ) {
        FUN_0044127f(*(undefined2 *)(*(int *)(*(int *)(param_1 + 0x18) + local_8 * 4) + 0xf0));
      }
      else {
        sVar1 = *(short *)(*(int *)(*(int *)(*(int *)(param_1 + 0x18) + local_8 * 4) + 0x118) + 0xc4
                          );
        if (sVar1 == 1) {
          (**(code **)(**(int **)(*(int *)(param_1 + 0x18) + local_8 * 4) + 0x40))(0);
        }
        else if (sVar1 == 2) {
          FUN_00442db0(*(undefined2 *)(*(int *)(*(int *)(param_1 + 0x18) + local_8 * 4) + 0xf0),0);
        }
      }
    }
  }
  return;
}

