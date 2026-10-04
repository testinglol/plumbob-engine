
void FUN_0060c9a0(void)

{
  int in_stack_00007d08;
  int in_stack_00007d0c;
  int in_stack_00007d10;
  int in_stack_00007d14;
  int in_stack_00007d18;
  int in_stack_00007d1c;
  int in_stack_00007d20;
  int in_stack_00007d24;
  
  FUN_00636080();
  if (0 < in_stack_00007d1c) {
    do {
      FUN_0060ca70(&stack0x00000004,in_stack_00007d10,in_stack_00007d10 + in_stack_00007d14,
                   in_stack_00007d20,in_stack_00007d20,in_stack_00007d18 * 2,
                   *(undefined4 *)(in_stack_00007d24 + 0x24),in_stack_00007d24 + 0x28);
      FUN_0060ca70(in_stack_00007d08,&stack0x00000004,&stack0x00000004 + in_stack_00007d20,
                   in_stack_00007d20,in_stack_00007d20 * 2,in_stack_00007d18,
                   *(undefined4 *)(in_stack_00007d24 + 0x24),in_stack_00007d24 + 0x28);
      in_stack_00007d10 = in_stack_00007d10 + in_stack_00007d14 * 2;
      in_stack_00007d08 = in_stack_00007d08 + in_stack_00007d0c;
      in_stack_00007d1c = in_stack_00007d1c + -1;
    } while (in_stack_00007d1c != 0);
  }
  return;
}

