
void FUN_0061cf00(int param_1,int param_2)

{
  if (*(uint *)(param_1 + 0x21c) < (uint)(*(int *)(param_1 + 0x218) + param_2)) {
    FUN_00634c51("\n%5ld   %s\n",*(undefined4 *)(param_1 + 0x240),param_1 + 0x274);
    FUN_00619f40(param_1,"Secondary heap overflow - assembly terminated.\n");
  }
  return;
}

