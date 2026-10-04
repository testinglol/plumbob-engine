
uint __fastcall FUN_004d381d(int param_1)

{
  uint in_EAX;
  uint uVar1;
  
  uVar1 = in_EAX & 0xffffff00;
  if (*(int **)(param_1 + 0x19c) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x19c) + 0x8c))(1);
  }
  return uVar1;
}

