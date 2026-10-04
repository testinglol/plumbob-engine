
uint __thiscall FUN_005dd715(int param_1,undefined4 param_2)

{
  uint in_EAX;
  uint uVar1;
  
  if (*(int **)(param_1 + 0x40) == (int *)0x0) {
    uVar1 = in_EAX & 0xffffff00;
  }
  else {
    uVar1 = (**(code **)(**(int **)(param_1 + 0x40) + 0xd8))(param_2);
  }
  return uVar1;
}

