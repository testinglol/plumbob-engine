
void __thiscall
FUN_004cfaaa(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  *(undefined4 *)(param_1 + 500) = 0;
  if (*(int *)(param_1 + 0x54) != 0) {
    FUN_0050a446();
  }
  *(undefined4 *)(param_1 + 500) = param_2;
  *(char *)(param_1 + 0x1f8) = (char)param_3;
  *(char *)(param_1 + 0x1f9) = (char)param_4;
  *(undefined4 *)(param_1 + 0x1fc) = param_5;
  FUN_0050a417(param_2,param_3,param_4,param_5);
  return;
}

